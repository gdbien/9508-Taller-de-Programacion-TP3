#include "common_socket.h"
#include <cstring>
#include <sys/types.h> //ejemplo
#include <netdb.h> //ejemplo
#include <unistd.h> //ejemplo

#include <iostream> // TODO BORRAR

#define INVALID_FD -1

const int ACCEPT_QUEUE_LEN = 10;

const char* ClosedSocketException:: what() const throw() {
	return "Socket is closed";	
}

void Socket::_set_hints(struct addrinfo *hints, int ai_flags, int ai_family,
					   int ai_socktype) {
	memset(hints, 0, sizeof(struct addrinfo));
	hints->ai_family = ai_family;
	hints->ai_socktype = ai_socktype;
	hints->ai_flags = ai_flags;
}

/*
	Itera las la lista de addrinfo hasta encontrar la dirreción que cumpla con
    los parametros de res, asignando el file descriptor a self.
    En el caso del servidor hace un bind(), y en el caso del cliente hace un
    connect().
	Devuelve SUCCESS si ok, y ERROR en caso contrario.
*/
void Socket::_iterate_addrinfo(struct addrinfo *res, bool is_server) {
	struct addrinfo *rp;
	int opt_val = 1;

	for (rp = res; rp != nullptr; rp = rp->ai_next) {
        this->fd = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);
        if (this->fd == INVALID_FD) continue;
        if (is_server) {
        	setsockopt(this->fd, SOL_SOCKET, SO_REUSEADDR, &opt_val,
        			   sizeof(opt_val));
        	if (::bind(this->fd, rp->ai_addr, rp->ai_addrlen) == 0) {
        		break;	
        	}  
        } else {
        	if (::connect(this->fd, rp->ai_addr, rp->ai_addrlen) == 0) {
        		break;	
        	}
        }
        ::close(this->fd);
    }
    freeaddrinfo(res);
	if (!rp) throw std::exception();
}

/*
	Encapsula y junta todos los llamados a funciones para obtener un socket en
	funcionamiento, ya sea un cliente o servidor.
	Devuelve SUCCESS si ok, y ERROR en caso contrario.
*/
void Socket::_getaddrinfo(const char *node, const char *service,
					    bool is_server) {
	struct addrinfo hints;
	struct addrinfo *res;
	int status;
	_set_hints(&hints, is_server ? AI_PASSIVE : 0, AF_INET, SOCK_STREAM);
	status = getaddrinfo(node, service, &hints, &res);
	if (status != 0) throw std::exception();
	_iterate_addrinfo(res, is_server);
}

Socket::Socket(): fd(INVALID_FD) {}

Socket::Socket(int fd): fd(fd) {}

Socket::~Socket() {
	if (this->fd != INVALID_FD) {
		::close(this->fd);
	}
	this->fd = INVALID_FD;
}

Socket::Socket(Socket &&other) noexcept: fd(other.fd) {
	other.fd = INVALID_FD;
}

Socket& Socket::operator=(Socket &&other) {
    this->fd = other.fd;
    other.fd = INVALID_FD;
    return *this;
}

size_t Socket::send(const char *buffer, size_t length) const {
	size_t tot_sent = 0;
	int actual_sent;
	while (tot_sent != length) {
 		actual_sent = ::send(this->fd, buffer + tot_sent, length - tot_sent,
 						   MSG_NOSIGNAL);
 		if (actual_sent == INVALID_FD) throw std::exception();
 		tot_sent += actual_sent;
 	}
 	return tot_sent;
}

size_t Socket::receive(char *buffer, size_t length) const {
	size_t tot_recv = 0;
	int actual_recv;
	while (tot_recv != length) {
    	actual_recv = ::recv(this->fd, buffer + tot_recv, length - tot_recv, 0);
    	if (actual_recv == 0) throw ClosedSocketException();
 		if (actual_recv == INVALID_FD) throw std::exception();
    	tot_recv += actual_recv;
   }
   return tot_recv;
}

void Socket::bindAndListen(const char *service) {
	_getaddrinfo(nullptr, service, true);
	::listen(this->fd, ACCEPT_QUEUE_LEN);
}

void Socket::connect(const char *host_name, const char *service) {
	_getaddrinfo(host_name, service, false);
}

Socket Socket::accept() {
	int fd = ::accept(this->fd, nullptr, nullptr);
	if (fd == INVALID_FD) throw std::exception();
	return std::move(Socket(fd));
}

void Socket::shutdown(int channel) {
	if (fd != INVALID_FD) ::shutdown(this->fd, channel);
}



#ifndef SOCKET_H
#define SOCKET_H

#include <cstddef>
#include <exception>
#include <sys/socket.h>

class ClosedSocketException : public std::exception {
public:
	const char *what() const throw();
};

class Socket {
private:
	int fd;
	explicit Socket(int fd);
	void _set_hints(struct addrinfo *hints, int ai_flags, int ai_family,
					int ai_socktype);
	void _iterate_addrinfo(struct addrinfo *res, bool is_server);
	void _getaddrinfo(const char *node, const char *service,
				      bool is_server);
public:
	/*
		Inicializa el fd del socket en INVALID_FD.
	*/
	Socket();
	/*
		Hace close del fd (si es válido), y lo invalida dejándolo en INVALID_FD.
	*/
	~Socket();
	/*
		No copiar
	*/
	Socket(const Socket &copy) = delete;
	Socket& operator=(const Socket &copy) = delete;
	/*
		Movimiento
	*/
	Socket(Socket &&other) noexcept;
	Socket& operator=(Socket &&other);
		
	/*
	 	Asigna una dirección al socket y lo marca como socket pasivo
	 	(lado del servidor).
	*/
	void bindAndListen(const char *service);
	/*	
		Acepta una conexión.
		Devuelve un socket por movimiento, en caso de error, lanza
	    std:exception.
	*/
	Socket accept();
	/*
		Se conecta a un servidor dada una dirección y un servicio o puerto
		(lado del cliente)
		Lanza std:exception en caso de error.
	*/
	void connect(const char *host_name, const char *service);
	/*
		Intenta enviar @param length bytes a traves del socket.
		Devuelve cantidad de bytes enviados.
		Lanza std:exception en caso de error.
	*/
	size_t send(const char *buffer, size_t length) const;
	/*
		Intenta recibir @param length bytes a traves del socket.
		Devuelve cantidad de bytes recibidos.
		Lanza std:exception en caso de error.
		Lanza ClosedSocketException en caso de socket cerrado.
	*/
	size_t receive(char *buffer, size_t length) const;
	/*
	 	Cierra los canales de lectura y/o escritura del socket.
	*/
	void shutdown(int channel);
};

#endif // SOCKET_H

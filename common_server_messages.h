#ifndef SERVER_MESSAGES_H
#define SERVER_MESSAGES_H

const char lost_msg[] = "Perdiste";
const char won_msg[] = "Ganaste";
const char help_msg[] = "Comandos válidos:\n\tAYUDA: "
					   	"despliega la lista de comandos válidos\n\t"
					   	"RENDIRSE: pierde el juego automáticamente\n\t"
					   	"XXX: Número de 3 cifras a ser enviado al "
					   	"servidor para adivinar el número secreto";
const char invld_nber_msg[] = "Número inválido. Debe ser de 3 cifras "
							  "no repetidas";
								   
#endif

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdlib.h>
#include <string.h>



int main ( )
{

	/*----------------------------------------------------
		Descriptores del socket y buffer de datos
	-----------------------------------------------------*/
	int sd, flag = 0;              // Descriptores del socket
	struct sockaddr_in sockname;   // Nombre del socket
	char buffer[250];              // Buffer de envío
	socklen_t len_sockname;			// Tamaño del socket
	fd_set lectura, auxlectura;		// Descriptores del socket

	/* --------------------------------------------------
		Se abre el socket
	---------------------------------------------------*/
  	sd = socket (AF_INET, SOCK_STREAM, 0);
	if (sd == -1)
	{
		perror("No se puede abrir el socket cliente\n");
    	exit (1);
	}

	// Inicialización de los sockets
	FD_ZERO(&lectura);
	FD_SET(0, &lectura);
	FD_SET(sd, &lectura);
	auxlectura = lectura;

	/* ------------------------------------------------------------------
		Se rellenan los campos de la estructura con la IP del
		servidor y el puerto del servicio que solicitamos
	-------------------------------------------------------------------*/
	sockname.sin_family = AF_INET;
	sockname.sin_port = htons(2048);
	sockname.sin_addr.s_addr = inet_addr("127.0.0.1");

	/* ------------------------------------------------------------------
		Se solicita la conexión con el servidor
	-------------------------------------------------------------------*/
	len_sockname = sizeof(sockname);

	// Conexión con el socket
	if (connect(sd, (struct sockaddr *)&sockname, len_sockname) == -1)
	{
		perror ("Error de conexión");
		exit(1);
	}

	// Recibe confirmación del servidor
	recv(sd, buffer, sizeof(buffer), 0);
	printf("\n%s\n\n", buffer);

	/* ------------------------------------------------------------------
		Se transmite la información
	-------------------------------------------------------------------*/
	while(flag == 0)
	/*do*/
	{
		auxlectura = lectura;
		select(FD_SETSIZE, &auxlectura, NULL, NULL, NULL);

		// Comprobacion del descriptor del socket
		if(FD_ISSET(0, &auxlectura))
		{
			gets(buffer);

			// Enviamos los datos al servidor
			if(send(sd, buffer, 250, 0) == -1)
			{
				perror("Error enviando datos");
			}

		// Si el mensaje que se recibe es SALIR, activamos el flag de salida
		if(strcmp(buffer, "SALIR1") == 0) //?¿?¿?¿?¿?¿?¿?¿?¿?¿?¿?¿?¿?¿?¿??¿?¿?¿?¿?¿?¿?¿?¿?¿?¿?¿?¿?¿?¿?¿?¿?¿?
			flag = 1;
		}
		else
		{
			buffer[0] = '\0';		     	// Vaciamos el buffer
			recv(sd, buffer, 250, 0);	// Se recibe el mensaje del servidor.
			printf("\n%s\n", buffer);	// Se imprime el mensaje recibido
		}
	} /*while(flag == 0);*/

	close(sd);	// Se cierra el desriptor
}

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <locale.h>
#include <string.h>   // Para strcmp / strcpy
#include <sys/time.h>


/* --------------------------------------------------------------------------------------
 Recibe DAY, TIME o DAYTIME, y devuelve el Día, la Hora o ambas.
---------------------------------------------------------------------------------------- */

int main () {
	/*----------------------------------------------------
		Descriptor del socket y buffer de datos
	-----------------------------------------------------*/
	int Socket_Servidor;
	struct sockaddr_in Servidor;

  // Lo que se recibe
  char DayTime[55];

  // Lo que se enviará -> Para fecha/hora
	time_t tiempo;
	struct tm * stTm;
	char cadena [55];
	tiempo = time(NULL);
	setlocale(LC_ALL, "");
	stTm = localtime(&tiempo);

	// Para la espera de 5 segundos
	struct timeval timeout;
	fd_set lectura;
	int salida;

	//Inicializar la estructua timeval
	timeout.tv_sec = 50;
	timeout.tv_usec = 0;

	// Funcion para realizar la espera de 5 segundos
	salida = select(1, &lectura, NULL, NULL, &timeout);

	if(salida == -1) {
		printf("\nSe ha producido un error en select.\n");
	}
	else if(salida == 0) {
		printf("\nSe ha agotado el tiempo.\n");
	}
	else {


	//Inicializar los conjuntos fd_set
	FD_ZERO(&lectura);
	FD_SET(0, &lectura);

  // Información del Cliente
  struct sockaddr_in Cliente;
  socklen_t Longitud_Cliente;

	// Se abre el socket Servidor
	Socket_Servidor = socket (AF_INET, SOCK_DGRAM, 0);
	if (Socket_Servidor == -1) {
		printf("No se puede abrir socket servidor\n");
		exit(-1);
	}

	/* ------------------------------------------------------------------
		Se rellenan los campos de la estructura servidor, necesaria para la llamada a la funcion bind().
	-------------------------------------------------------------------*/
	Servidor.sin_family = AF_INET;
	Servidor.sin_port = htons(2000);
  // htonl = Evitar errores de conversion de direccion del servidor, garantiza el uso de su ID
	Servidor.sin_addr.s_addr = htonl(INADDR_ANY);

	if (bind (Socket_Servidor, (struct sockaddr *) &Servidor, sizeof (Servidor)) == -1) {
		close (Socket_Servidor);
		exit(-1);
	}


  /*---------------------------------------------------------------------
  Del cliente sólo necesitamos el tamaño de su estructura, el resto de información (familia, puerto, IP), nos la proporcionará el propio método recvfrom(), cuando recibamos la llamada de un cliente.
  ----------------------------------------------------------------------*/
	Longitud_Cliente = sizeof(Cliente);


		/*-----------------------------------------------------------------------
			El servidor espera continuamente los mensajes de los clientes
		------------------------------------------------------------------------ */
	  // Bucle infinito hasta que lo matemos
	  // while (1) {
		/* -----------------------------------------------------------------
		Esperamos la llamada de algún cliente
		-------------------------------------------------------------------*/
		int recibido = recvfrom (Socket_Servidor, &DayTime, sizeof(DayTime), 0, (struct sockaddr *) &Cliente, &Longitud_Cliente);


		/* -----------------------------------------------------------------
		Comprobamos si hemos recibido alguna información
		-------------------------------------------------------------------*/
		if (recibido > 0) {
			/*-----------------------------------------------------------------
			Interpretamos la información recibida, de manera que se introduce en una variable la información solicitada
			------------------------------------------------------------------*/
			if (strcmp(DayTime, "DAY") == 0) {
				// Fecha formato <Lunes, 17 de Septiembre de 2019>
				strftime(cadena, 55, "%A, %d de %B de %Y", stTm);
			}
			else if (strcmp(DayTime, "TIME") == 0) {
				// Hora formato <Horas:Minutos:Segundos>
				strftime(cadena, 55, "%H:%M:%S", stTm);
			}
			else {
				// Fecha y hora, formato <Lunes, 17 de Septiembre de 2019; Horas:Minutos:Segundos>
				strftime(cadena, 55, "%A, %d de %B de %Y; %H:%M:%S", stTm);
			}
			printf ("\n\nRecibido %s, envio %s\n", DayTime, cadena);


			/* ------------------------------------------------------------------
			Devolvemos la información correspondiente a lo solicitado
			--------------------------------------------------------------------*/
			int enviado = sendto(Socket_Servidor, &cadena, sizeof(cadena), 0, (struct sockaddr *) &Cliente, Longitud_Cliente);
		}
		// }
		// fgets(cadena, sizeof(cadena), stdin);
		// printf("Se ha escrito por pantalla: %s\n", cadena);
	}

	close(Socket_Servidor);

	return 0;
}

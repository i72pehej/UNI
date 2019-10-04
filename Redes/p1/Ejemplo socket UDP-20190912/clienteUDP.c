#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <arpa/inet.h>

/* --------------------------------------------------------------------------------------

 Env�a un n�mero aleatorio al servidor, quien el devuelve el n�mero incrementado

---------------------------------------------------------------------------------------- */

int main ( )
{

		/*----------------------------------------------------
			Descriptor del socket y buffer para datos
		-----------------------------------------------------*/
    // Mejor usar char
    int Socket_Cliente;
		int Datos;

   	/* -----------------------------------------------------
   		Informaci\ufffdn del Servidor
   	-----------------------------------------------------*/
   	struct sockaddr_in Servidor;
   	socklen_t Longitud_Servidor;


   	/* --------------------------------------------------
			Se abre el socket cliente
		---------------------------------------------------*/
		Socket_Cliente = socket (AF_INET, SOCK_DGRAM, 0);
		if (Socket_Cliente == -1)
		{
			printf ("No se puede abrir el socket cliente\n");
    			exit (-1);
		}

 		/*---------------------------------------------------------------------
			Necesitamos una estructura con la informaci\ufffdn del Servidor
			para poder solicitarle un servicio.
   		----------------------------------------------------------------------*/
    // Siempre misma familia del servidor.
		Servidor.sin_family = AF_INET;
    // Puerto 2000
    // htons() = garantiza que se cojan los bits siempre en el orden correcto
		Servidor.sin_port = htons(2000);
    // Transforma cadena en el campo que necesitamos
		Servidor.sin_addr.s_addr =  inet_addr("172.16.213.3");
    Longitud_Servidor = sizeof(Servidor);


		/*------------------------------------------------------------------------
			Se genera un n\ufffdmero aleatorio, que es el que se le manda al
			servidor.
		------------------------------------------------------------------------ */
   	srand (time(NULL)); /* Semilla para n\ufffdmeros aleatorios */
   	Datos = rand()%20;  /* Aleatorio entre 0 y 19 */
   	printf ("Envio %d\n", Datos);


		/*-----------------------------------------------------------------------
			Se env\ufffda mensaje al Servidor
		-----------------------------------------------------------------------*/
		int enviado = sendto (Socket_Cliente, (char *) &Datos, sizeof(Datos), 0,
			(struct sockaddr *) &Servidor, Longitud_Servidor);

    // Si nº bytes enviados es menor que 0 = error.
   	if (enviado < 0) {
			printf("Error al solicitar el servicio\n");
		}
    else {

		/*----------------------------------------------------------------------
			Esperamos la respuesta del Servidor
			----------------------------------------------------------------------- */
			int recibido = recvfrom (Socket_Cliente, (char *)&Datos, sizeof(Datos), 0,
			(struct sockaddr *) &Servidor, &Longitud_Servidor);

      // Si nº bytes recibidos es menor que 0 = error.
   		if (recibido > 0)
      		printf ("Leido %d\n", Datos);
   		else
      		printf ("Error al leer del servidor\n");

		}

		close(Socket_Cliente);

	return 0;
}

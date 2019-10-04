#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <arpa/inet.h>
#include <string.h>   // Para strcmp


/* --------------------------------------------------------------------------------------
 Envía DAY, TIME o DAYTIME al servidor.
---------------------------------------------------------------------------------------- */

int main () {
  /*----------------------------------------------------
  	Descriptor del socket y buffer para datos
  -----------------------------------------------------*/
  // Mejor usar char
  int Socket_Cliente;
  char Datos[55];

	/* -----------------------------------------------------
		Información del Cliente
	-----------------------------------------------------*/
	struct sockaddr_in Servidor;
	socklen_t Longitud_Servidor;


	/* --------------------------------------------------
	Se abre el socket cliente
  ---------------------------------------------------*/
  Socket_Cliente = socket (AF_INET, SOCK_DGRAM, 0);
  if (Socket_Cliente == -1) {
  	printf ("\nNo se puede abrir el socket cliente\n");
    exit (-1);
  }

  /*---------------------------------------------------------------------
    Necesitamos una estructura con la información del Servidor
    para poder solicitarle un servicio.
  ----------------------------------------------------------------------*/
  // Siempre misma familia del servidor.
  Servidor.sin_family = AF_INET;
  // Puerto 2000
  // htons() = garantiza que se cojan los bits siempre en el orden correcto
  Servidor.sin_port = htons(2000);
  // Transforma cadena en el campo que necesitamos
  Servidor.sin_addr.s_addr =  inet_addr("127.0.0.1");
  Longitud_Servidor = sizeof(Servidor);


  /*------------------------------------------------------------------------
  	Se solicita al usuario la información que desea, siendo esta DAY, TIME o DAYTIME.
  ------------------------------------------------------------------------ */
  system("clear");
  printf("1 ----- DÍA / DAY\n");
  printf("2 ----- HORA / TIME\n");
  printf("3 ----- DÍA y HORA / DAYTIME\n");
  printf("\n\nSeleccione la información que desea solicitar al servidor (1 / 2 / 3): ");

	fscanf(stdin, "%s", Datos);   // Guarda en Datos la selección.

  // Transcripción de la selección
  if (strcmp(Datos, "1") == 0) {
    strcpy(Datos, "DAY");
  }
  else if (strcmp(Datos, "2") == 0) {
    strcpy(Datos, "TIME");
  }
  else if (strcmp(Datos, "3") == 0) {
    strcpy(Datos, "DAYTIME");
  }
  else {
    printf("\nValor inválido.\n");

    close(Socket_Cliente);
    exit(-1);
  }

  printf ("\n\nEnvio %s\n", Datos);


  /*-----------------------------------------------------------------------
  	Se envía mensaje al Servidor
  -----------------------------------------------------------------------*/
  int enviado = sendto (Socket_Cliente, &Datos, sizeof(Datos), 0, (struct sockaddr *) &Servidor, Longitud_Servidor);

  // Si nº bytes enviados es menor que 0 = error.
  if (enviado < 0) {
  	printf("\nError al solicitar el servicio\n");
  }
  else {
    /*----------------------------------------------------------------------
    	Esperamos la respuesta del Servidor
    ----------------------------------------------------------------------- */
    int recibido = recvfrom (Socket_Cliente, &Datos, sizeof(Datos), 0, (struct sockaddr *) &Servidor, &Longitud_Servidor);

    // Si nº bytes recibidos es menor que 0 = error.
    if (recibido > 0)
      printf ("\n\nLeido %s\n", Datos);
    else
      printf ("\nError al leer del servidor\n");
  }

  close(Socket_Cliente);

	return 0;
}

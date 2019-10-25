#include <stdio.h>
#include <stdlib.h>
#include <string.h>






int main()
	{
	
	
	
	
	
	
	
	
	
	
	return 0;
	}
/*
			COMENTARIOS
	*************************************
	UDP--> select()--> temporizador ==> CLIENTE
	TCP--> select()--> Simular concurrencia ==> SERVIDOR
	
	FD_ISSET(sd, &lectura);
		accept
		FD_SET()


	FD_ISSET(cliente1, &lectura);
		recv();

	FD_ISSET(cliente2, &lectura);
		recv();

	**********************************************

	if(FD_ISSET(sd, &lectura))
		{
		accept()
		FD_SET
	
		}
	else
		{
		for(i=0;i<FD_SETSIZE;i++)
			{
			if(FD_ISSET(i, &lectura))
				{
				recv(); 

				sent();
				
				}

			}

		}

	***********************
	0-> Conectado
	1-> Usuario
	2-> Validacion contraseña
	3-> Esperando a jugar
	4-> Jugando


*/



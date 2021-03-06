#include "funcionesDomino.h"



/*
  * El servidor ofrece el servicio de incrementar un número recibido de un cliente
*/



int main ( ) {

	/*----------------------------------------------------
		Descriptor del socket y buffer de datos
	-----------------------------------------------------*/
	int sd, new_sd,  j, k, q, pep, x, flagFin;
	struct ficha f;	// Ficha auxiliar
	struct sockaddr_in sockname, from;
	char buffer[100];
	char qwerty[100];
	socklen_t from_len;
	fd_set lectura, auxlectura, auxlectura2;
	struct clients cliente[40];	// Estructura de los clientes que pueden aceder al servidor
	struct part party[20];			// Estructura para controlar las partidas

	struct clients *cli;				// Puntero que utilizaremos como cliente auxiliar

	struct clients partida[2];
	struct hostent *host;

	char *usuario;
	char *contra;
	char linea[100];
	char linea2[100];
	char cad[200];		// Auxiliares
	char auxl[100];		// Auxiliar para el fichero
	char auxl2[100];	// Auxiliar
	char auxl3[100];	// Guarda el nombre de usuario o contraseña
	char auxl4[100];	// Guarda contraseña de la base de datos
	char aux [100];
	char extremo[25];	// Extremo donde colocar la ficha
	int espera[2];		// Usuarios en espera para iniciar partida
	int esperando, nMesa, n1, n2;  // Variables para controlar una partida
	int n, i, flag;		// Auxiliares
	int id, valor;		// Auxiliares
	FILE *archivo;

	flag = 0;					// Flag para identificar si el usuario se ha registrado
	n = 0;						// Numero de conexiones al servidor
	flagFin = 0;
	id = 0;						// Identifica el orden de entrada del usuario
	nMesa = 0;       // Identificador de la mesa de la partida
	esperando = -1;  // Iterador para espera[]

	// Inicializamos los descriptores a 0.
	FD_ZERO(&auxlectura);
	FD_ZERO(&lectura);

	cli = (struct clients *)malloc(40 * sizeof(struct clients));

	/* --------------------------------------------------
		Se abre el socket
	---------------------------------------------------*/
  	sd = socket (AF_INET, SOCK_STREAM, 0);
	if (sd == -1)
	{
		perror("\tNo se puede abrir el socket cliente\n");
    exit (1);
	}

	id = 1;
	valor = setsockopt( sd, SOL_SOCKET, SO_REUSEADDR, &id, sizeof(id));

	if(valor == -1)
		perror("\tError en la función setsockopt");


	sockname.sin_family = AF_INET;
	sockname.sin_port = htons(2048);
	sockname.sin_addr.s_addr = INADDR_ANY;

	if (bind (sd, (struct sockaddr *) &sockname, sizeof (sockname)) == -1)
	{
		perror("\tError en la operación bind");
		exit(1);
	}


   	/*---------------------------------------------------------------------
		Del las peticiones que vamos a aceptar sólo necesitamos el
		tamaño de su estructura, el resto de información (familia, puerto,
		ip), nos la proporcionará el método que recibe las peticiones.
   	----------------------------------------------------------------------*/
		from_len = sizeof (from);


	if(listen(sd, 1) == -1)
	{
		perror("\tError en la operación listen");
		exit(1);
	}

	/*-----------------------------------------------------------------------
		El servidor acepta una petición
	------------------------------------------------------------------------ */
	// Inicializa el descriptor con el valor contenido en "sd" (descriptor del socket)
	FD_SET(sd, &lectura);

	while(1)
	{
		auxlectura = lectura;

		// Abrimos el select() para permitir la simultaneidad de clientes
		select(FD_SETSIZE, &auxlectura, NULL, NULL, NULL);

		// FD_ISSET -> Devuelve !=0 si el valor se encuentra en FD_SET
		if(FD_ISSET(sd, &auxlectura))
		{
			printf("\nNUEVA CONEXION %d\n\n", n);
			// Se acepta la conexion con un nuevo descriptor del socket
			if((new_sd = accept(sd, (struct sockaddr *)&from, &from_len)) == -1)
			{
				perror("\tError aceptando peticiones");
				exit(1);
			}

			FD_SET(new_sd, &lectura);
			// Enviamos el mensaje de aceptacion al cliente.
			send(new_sd, "\n\t+OK. Conectado.\n\n", 250, 0);

			//NUEVO CLIENTE
			cliente[n].socket = new_sd;
			cliente[n].nivel = -1;

			n++;
		}
		else // cliente conocido
		{
			for(i = 0; i < FD_SETSIZE; i++)
			{
				if(FD_ISSET(i, &auxlectura))
				{
					printf("\n\tCliente conocido: %d \n\n", i);
					if(recv(i, buffer, 250, 0) == -1)
						perror("\tError en la operación de recv");
/*
					if(strcmp(buffer, "FIN") == 0)
					{
						close(i);
						FD_CLR(i, &lectura);
						n--;
					}
*/
					printf("\n%s\n", buffer);

					// Cargamos los clientes que hayan iniciado sesion en el vector clientes
					for(j = 0; j < n; j++)
					{
						if(i == cliente[j].socket)
						{
							for(x = 0; x < id; x++)
							{
								if(cliente[j].socket == cli[x].socket)
								{
									if(cliente[j].nivel == 2)
									{
										cliente[j].nivel = cli[x].nivel;
									}
								}
							}
							printf("\n\tNivel Cliente: %d \n\n", cliente[j].nivel);

////////////////////////////////////////////////////////////////////////////////

							// Registramos un cliente si no esta regsitrado
							if(cliente[j].nivel == -1)
							{
								if((strncmp(buffer, "REGISTRO", 8)) == 0)
								{
									usuario = strtok(buffer, "-");
                  // printf("%s\n", usuario);
									usuario = strtok(NULL, " ");
                  // printf("%s\n", usuario);
									usuario = strtok(NULL, " ");
                  // printf("Usuario: %s\n", usuario);
									strcpy(cliente[j].user, usuario);

									contra = strtok(NULL, " ");
                  // printf("%s\n", contra);
									contra = strtok(NULL, "\n");
                  // printf("%s\n", contra);
									strcpy(cliente[j].pass, contra);

									archivo = fopen("base.txt", "a");  // Guardamos el nuevo usuario en el archivo de "base de datos"
									sprintf(linea2, "\t%s %s\n", usuario, contra);
									fputs(linea2, archivo);
									fclose(archivo);
									printf("\nCLIENTE REGISTRADO CON EXITO\n");

									send(cliente[j].socket, "\t+Ok. Registrado.", 250, 0);
								}

////////////////////////////////////////////////////////////////////////////////

              // Si esta resgistrado se procede a iniciar sesion
							else if((strncmp(buffer, "USUARIO", 7)) == 0)
							{
								sscanf(buffer,"%s %s", auxl2, auxl3); // Leemos el nombre del usuario con auxl3
								printf("\n\tUsuario introducido: %s\n", auxl3);
								archivo = fopen("base.txt", "r"); // Abrimos la base de datos

								flag = 0; // Usuario registrado
								while(fgets(auxl, 100, archivo) != NULL) // Recorre la base de datos
								{
									sscanf(auxl, "%s %s", auxl2, auxl4);  // Leemos los nombres de los usuarios + contraseña de la base de datos
									// printf("\n\tUsuario de la bd: %s\n", auxl2);

									if(strcmp(auxl3, auxl2) == 0) // Si coinciden ambos se reconoce al usuario
									{
										flag = 1; // Usuario conocido
										printf("\nUSUARIO REGISTRADO(1/2)\n\n");
										(cliente[j].nivel)++; // Nivel 0 = usuario conocido
										strcpy(cliente[j].user, auxl2);
										strcpy(cliente[j].pass, auxl4);
										printf("\n\tLvl: %d\tU: %s\tC: %s\n\n", cliente[j].nivel, cliente[j].user, cliente[j].pass);
										send(cliente[j].socket, "\n\t+Ok. User correcto\n\0", 250, 0);
									}
								}
								fclose(archivo);

								if(flag == 0)
								{
									send(cliente[j].socket, "\n\t-ERR. Usuario incorrecto.\n\0", 250, 0);
								}
							}
							else
							{
								send(cliente[j].socket, "\n\t-ERR. Registrate o entra.\n\0", 250, 0);
							}
						}

////////////////////////////////////////////////////////////////////////////////

            // Comprobacion del password
						else if (cliente[j].nivel == 0)
						{
							if((strncmp(buffer, "PASSWORD", 4)) == 0)
							{
								sscanf(buffer,"%s %s", auxl2, auxl3);  // Guardamos lo contraseña en auxl3
								if((strcmp(auxl3, cliente[j].pass)) == 0)  // Comparamos el buffer con el fichero
								{
									(cliente[j].nivel)++;  // Nivel 1 = usuario dentro
									printf("\nPASSWORD CORRECTO (2/2)\n\n");
									send(cliente[j].socket, "\t+Ok. Usuario validado.\n", 250, 0);
								}
								else
								{
									send(cliente[j].socket, "\t-ERR. Error en la validacion.\n\n", 250, 0);
								}
							}
							else
							{
								send(cliente[j].socket, "\t-ERR. Se necesita validacion (password).\n\n", 250, 0);
							}
						}

////////////////////////////////////////////////////////////////////////////////

            // Usuario en el servidor
						else if (cliente[j].nivel == 1) // Esperado para inicar una partida
						{
							if((strncmp(buffer, "INICIAR-PARTIDA", 15)) == 0)
							{
								cliente[j].id = id;
								id++;

								esperando++;

								espera[esperando] = cliente[j].socket;
								cliente[j].mesa = nMesa;

                // Creamos el cliente auxiliar
                strcpy(cli[esperando].user, cliente[j].user);
                strcpy(cli[esperando].pass, cliente[j].pass);
                cli[esperando].socket = cliente[j].socket;
                cli[esperando].nivel = cliente[j].nivel;
                cli[esperando].mesa = nMesa;

								if(esperando == 1)
								{
									printf("\n\tMesa: %d", nMesa);
									printf("\n\tJugadores: %d %d\n\n", cli[0].socket, cli[1].socket);

                  // Recorre los usuarios en espera[]
									for(x = 0; x < 2; x++)
									{
                    // Recorre los clientes activos para identificar los que estan en partida
										for(k = 0; k < n; k++)
										{
											if(cliente[k].socket == espera[x])
											{
												(cliente[k].nivel)++; // Nivel 2 = en partida
											}
										}
										send(cli[x].socket, "\n\t+Ok. Empieza la partida.\n", 250, 0);
									}


									for(x = (nMesa * 2); x < (nMesa * 2) + 2; x++)
									{
										(cli[x].nivel)++;
									}
                  // Inicializacion de la mesa
									strcpy(party[nMesa].tablero, "");
									party[nMesa].izquierda = -1;
									party[nMesa].derecha = -1;
									party[nMesa].start = 0;
									party[nMesa].numpartida = nMesa;

									for(k = 0; k < 2; k++)
									{
										party[nMesa].usuarios[k] = cli[k].socket;
									}

                  // Se inicia la partida
									iniciarDomino(party[nMesa], cli);

									// Asigna el turno al jugador correspondiente
									party[nMesa].turno = cli[comprobarTurno(cli, &party[nMesa])].socket;

									// Se muestran las fichas a cada jugador, su orden y su turno
                  for(x = 0; x < 2; x++)
									{
										send(cli[x].socket,"Tus fichas:", 250, 0);
										sleep(1);
										verFichas(cli[x]);
										sleep(1);

										strcpy(auxl, "");
										sprintf(auxl,"Eres el jugador <%d>", cli[x].socket);
										send(cli[x].socket, auxl, 250, 0);
										sleep(1);

										strcpy(auxl2, "");
										sprintf(auxl2, "Es el turno del jugador <%d>", party[nMesa].turno);
										send(cli[x].socket, auxl2, 250, 0);
										sleep(1);

										send(cli[x].socket,"TABLERO:", 250, 0);
										send(cli[x].socket,party[nMesa].tablero, 250, 0);

									}

									esperando = -1;	// Reincio
									nMesa++;	// Nueva mesa libre
								}
								else
								{
									send(cliente[j].socket, "\n\t+Ok. Peticion recibida. \n\tEsperado jugadores. . .\n", 250, 0);
								}
printf("valor de j %d\n",j );
for(int k=0; k<n; k++){
	printf("(yo)nivel del cliente %d: %d\n",k,cliente[k].nivel);
								}
							}

////////////////////////////////////////////////////////////////////////////////

						else if((strncmp(buffer, "SALIR", 5)) == 0)
							{
								send(cliente[j].socket, "+Ok. Desconexion procesada.\n", 250, 0);
								cliente[j].nivel = -1;
							}
							else
							{
								send(cliente[j].socket, "\n-ERR. Iniciar partida o salir.\n\0", 250, 0);
							}
						}
////////////////////////////////////////////////////////////////////////////////

						// Jugando una partida
						else if(cliente[j].nivel == 2)
						{
							i = 0;
							// for(i = 0; i < nMesa; i++)	// Se recorren las partidas en juego
							// {
								if(cliente[j].mesa == party[i].numpartida)	// Comprueba la partida de cada cliente
								{
									if(party[i].turno == cliente[j].socket)	// Comprueba el turno del cliente
									{
										send(cliente[j].socket, "\t+Ok. Comienza la partida\n\n", 250, 0);

										if((strncmp(buffer, "COLOCAR-FICHA", 11)) == 0)
										{
											printf("PONE FICHA\n");
											sscanf(buffer, "COLOCAR-FICHA |%d|%d|,%s", &n1, &n2, extremo);
											f.izq = n1;
											f.der = n2;
											flag = 0;
											pep = 0;

											for(q = 0; q < 2; q++)
											{
												if(cli[q].socket == cliente[j].socket)
												{
													pep = q;  // no se para que sirve tbh
												}
											}

											// Imprime las fichas del jugador y comprueba que la ficha es valida
											for(k = 0; k < cli[pep].nFichas; k++)
											{
												// printf("\n|%d|%d|\n", cli[pep].fichas[k].izq, cli[pep].fichas[k].der);

												// Comprueba que la ficha seleccionada este en su mano
												if((f.izq == cli[pep].fichas[k].izq) && (f.der == cli[pep].fichas[k].der))
												{
													// Comprueba que el extremo sea correcto
													if(strncmp(extremo, "izquierda", 9) || strncmp(extremo, "derecha", 7))
													{
														flag = 1; // Bandera para indica que la ficha es valida
													}
												}
											}
printf("HOLAAAAAAAAAAA-> Extremo correcto: %d -> %s\n", flag, extremo);
											// Si la ficha es valida
											if(flag == 1)
											{
printf("AAAAAAAAAAA -> %s\n", extremo);
												// Si se coloca la ficha en el tablero correctamente
												if(ponerFicha(&party[i], f, extremo) == true)
												{
													party[i].pasar = 0;	// No se pasa
													quitarFicha(&cli[j], f);	// Se quita la ficha al jugador
													send(party[i].turno, "\n\t+Ok. Ficha colocada\n\0", 250, 0);
													printf("\nFICHA COLOCADA\n");

													// Se recorren los jugadores
													for(k = 0; k < 2; k++)
													{
														// Comprobamos si uno de los jugadore se ha quedado sin fichas y ha ganado
														if(cli[k].nFichas == 0)
														{
															// En funcion del nivel del jugador
															for(x = 0; x < 2; x++)
															{
																strcpy(auxl, "");
																sprintf(auxl, "El jugador numero %d ha ganado", k);
																send(cli[x].socket, auxl, 250, 0);

																sleep(0.5);

																send(cli[x].socket, "Fin de la partida", 250, 0);
																cli[x].nivel = -1;	// Fuera de partida
															}
														}

														send(party[i].usuarios[k], "party TABLERO:\n", 250,0);  //mostramos el tablero a cada usuarip
														send(party[i].usuarios[k], party[i].tablero, 250,0);
														send(cli[x].socket, "cli TABLERO:\n", 250,0);  //mostramos el tablero a cada usuarip
														send(cli[x].socket, party[i].tablero, 250,0);

														sleep(0.5);

														strcpy(aux, "");
														sprintf(aux, "Es el turno de %d\n", party[i].turno);
														send(party[i].usuarios[k], aux, 100, 0);
														}

													party[i].turno = ((party[i].turno) +1);
													if(party[i].turno > party[i].usuarios[1]) //reseteamos los turno
													{
														party[i].turno = party[i].usuarios[0];
													}
													send(party[i].turno, "Es tu turno\n\n", 250, 0);
													send(party[i].turno, "TUS FICHAS:\n", 250, 0);
													verFichas(cli[(pep + 1) % 2]);
												}
												else
												{
													printf("\n\t-ERR. Error al poner la ficha\n");
													send(cli[pep].socket, "\n\t-ERR. La ficha no puede ser colocada\n", 250, 0);
												}
											}
											else
											{
												send(cliente[j].socket, "\n\t-ERR. No tienes esta ficha\n\0", 250, 0);
											}
										}
									}
							  }
							// }
						}

////////////////////////////////////////////////////////////////////////////////

						}
					}
				}
			}
		}



}

		close(sd);

}


//************************************************

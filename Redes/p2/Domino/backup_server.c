#include "clases.h"



/*
 * El servidor ofrece el servicio de incrementar un número recibido de un cliente
 */



main ( )
{
  
	/*---------------------------------------------------- 
		Descriptor del socket y buffer de datos                
	-----------------------------------------------------*/
	int sd, new_sd,  j, k, q, pep, x, flagFin;
	struct ficha f;
	struct sockaddr_in sockname, from;
	char buffer[100];
	char qwerty[100];
	socklen_t from_len;
	fd_set auxlectura, lectura, auxlectura2;	
	struct clients cliente[40];
	struct clients * cli;
	struct part party[10];
	struct clients partida[4];
	struct hostent * host;
	char linea[100];
	char * usuario;
	char * contra;
	char linea2[100];
	char cad[200];
	char auxl[100];
	char auxl2[100];
	char auxl3[100];
	char auxl4[100];
	char aux [100];
	int n, i, flag;
	int espera[4];
	flag=0;
	n=0;
	flagFin=0;
	int id, valor;
	id=0;

	int esperando, nMesa, n1, n2;
	nMesa=0;
	esperando=-1;
	FILE * archivo;

	FD_ZERO(&auxlectura);
	FD_ZERO(&lectura);

	cli = (struct clients *)malloc(40*sizeof(struct clients));

	/* --------------------------------------------------
		Se abre el socket 
	---------------------------------------------------*/
  	sd = socket (AF_INET, SOCK_STREAM, 0);
	if (sd == -1)
	{
		perror("No se puede abrir el socket cliente\n");
    		exit (1);	
	}
	/*
	id = 1;
	valor = setsockopt( sd, SOL_SOCKET, SO_REUSEADDR, &id, sizeof(id));

	if(valor == -1)
		perror("Error en la función setsockopt");

	*/
	sockname.sin_family = AF_INET;
	sockname.sin_port = htons(2001);
	sockname.sin_addr.s_addr =  INADDR_ANY;

	if (bind (sd, (struct sockaddr *) &sockname, sizeof (sockname)) == -1)
	{
		perror("Error en la operación bind");
		exit(1);
	}
	

   	/*---------------------------------------------------------------------
		Del las peticiones que vamos a aceptar sólo necesitamos el 
		tamaño de su estructura, el resto de información (familia, puerto, 
		ip), nos la proporcionará el método que recibe las peticiones.
   	----------------------------------------------------------------------*/
		from_len = sizeof (from);


	if(listen(sd,1) == -1)
		{
		perror("Error en la operación de listen");
		exit(1);
		}
   	
	/*-----------------------------------------------------------------------
		El servidor acepta una petición
	------------------------------------------------------------------------ */
	FD_SET(sd, &lectura);	
	
	while(1)
		{
		auxlectura=lectura;
		
		select(FD_SETSIZE, &auxlectura, NULL, NULL, NULL);
		
		if(FD_ISSET(sd, &auxlectura))
			{
			printf("\nNUEVA CONEXION %d\n\n", n);
			if((new_sd = accept(sd, (struct sockaddr *)&from, &from_len)) == -1)				
				{		
				perror("Error aceptando peticiones");
				exit(1);
				}
			
			FD_SET(new_sd, &lectura);
			send(new_sd, "\nConectado. +OK \n\n", 100, 0);

			//NUEVO CLIENTE
			cliente[n].socket=new_sd;
			cliente[n].nivel=-1;


			n++;
			}
		else // cliente conocido
			{
			
			
			for(i=0;i<FD_SETSIZE;i++)
				{
				if(FD_ISSET(i, &auxlectura))
					{
					printf("\nCliente conocido: %d \n\n", i);
					if(recv(i, buffer, 100, 0) == -1)
						perror("Error en la operación de recv");
					if(strcmp(buffer, "FIN")==0)
						{
						close(i);
						FD_CLR(i, &lectura);
						n--;
						}
					printf("\n%s\n", buffer);
					for(j=0;j<n;j++)
						{
						if(i==cliente[j].socket)
							{
							
							printf("\nNivel Cliente: %d \n\n", cliente[j].nivel);
							if(cliente[j].nivel==-1)
								{
								if((strncmp(buffer, "registro", 8))==0)
									{							
									strtok(buffer," ");
									strtok(NULL," ");
									usuario=strtok(NULL," ");
									strcpy(cliente[j].user,usuario);
									strtok(NULL, " ");
									contra=strtok(NULL,"\n");
									strcpy(cliente[j].pass,contra);
									archivo=fopen("base.txt", "a");
									sprintf(linea2, "%s %s\n", usuario, contra);
									fputs(linea2, archivo);
									fclose(archivo);
									printf("\nCLIENTE REGISTRADO CON EXITO\n");
									
									send(cliente[j].socket, "+Ok. Registrado. ", 100, 0);
									
									}
								else if((strncmp(buffer, "USUARIO", 7))==0)
									{
									
										sscanf(buffer,"%s %s", auxl2, auxl3);
										
										printf("\n%s\n", auxl3);
										archivo=fopen("base.txt", "r");
											
										
										flag=0;
										while(fgets(auxl, 100, archivo)!=NULL)
										{
											
											//fgets(auxl, 100, archivo);
											sscanf(auxl,"%s %s", auxl2, auxl4);

											printf("\n%s\n", auxl2);
											
											if(strcmp(auxl3, auxl2)==0)
												{
												flag=1;
												printf("\nUSUARIO REGISTRADO(1/2)\n\n");
												(cliente[j].nivel)++;
												strcpy(cliente[j].user, auxl2);
												strcpy(cliente[j].pass, auxl4);
												printf("\n%d\t%s\t%s\n\n", cliente[j].nivel, cliente[j].user, cliente[j].pass);
												send(cliente[j].socket, "\n+Ok. User correcto\n\0", 100, 0);
												}
										}
										fclose(archivo);

										if(flag==0)
											{
											send(cliente[j].socket, "\n-Error. User no encontrado\n\0", 100, 0);
											}
										
									}
								else
									{
									send(cliente[j].socket, "\n-Error. registrate o entra\n\0", 100, 0);
									}


								}
								
							else if (cliente[j].nivel==0)
								{
								if((strncmp(buffer, "PASS", 4))==0)
									{
									sscanf(buffer,"%s %s", auxl2, auxl3);
									if((strcmp(auxl3, cliente[j].pass))==0)
										{
										(cliente[j].nivel)++;
										printf("\nPASS CORRECTO (2/2)\n\n");
										send(cliente[j].socket, "+Ok. Pass correcto", 100, 0);
										}
									else
										{
										send(cliente[j].socket, "-Error. Pass no correcto", 100, 0);
										}		
									
									}
								else
									{
									send(cliente[j].socket, "-Error. Necesita PASS", 100, 0);
									}
								
								}
							else if (cliente[j].nivel==1)
								{
								if((strncmp(buffer, "PARTIDA", 7))==0)
									{
									cliente[j].id=id;
									id++;

									esperando++;
									
									espera[esperando]=cliente[j].socket;
									cliente[j].mesa=nMesa;
									cli[esperando].socket=cliente[j].socket;
									cli[esperando].nivel=cliente[j].nivel;
									cli[esperando].mesa=nMesa;
									strcpy(cli[esperando].user,cliente[j].user);
									strcpy(cli[esperando].pass,cliente[j].pass);
									


									if(esperando==3)
										{
										printf("\nMesa: %d", nMesa);
										printf("\nJugadores: %d %d %d %d", cli[0].socket, cli[1].socket, cli[2].socket, cli[3].socket);

										for(x=0;x<4;x++)
											{
											for(k=0;k<n;k++)
												{
												if(cliente[k].socket==espera[x])
													{
													(cliente[k].nivel)++;
													(cli[k].nivel)++;
													}
												}

											send(cli[x].socket, "\n+Ok. Empieza la partida \n", 100, 0);
											
											}
										strcpy(party[nMesa].tablero,"");
										party[nMesa].izquierda=-1;
										party[nMesa].derecha=-1;
										party[nMesa].start=0;
										party[nMesa].numpartida=nMesa;
										
										for(k=0;k<4;k++)
											{
											party[nMesa].usuarios[k]=cli[k].socket;
											}

										iniciarDomino(party[nMesa], cli);
										for(k= 0;k<4;k++)
											{
											for(x=0;x<7;x++)
												{

												n1=cli[k].fichas[x].izq;
												n2=cli[k].fichas[x].der;
												if(n1==6 && n2==6)
													party[nMesa].turno=cli[k].socket;
												}
											}
										for(x=0;x<4;x++)
											{
											printf("\nS %d:_ %d\n",x , cli[x].socket);
											send(cli[x].socket,"Tus fichas: ", 100, 0);
											sleep(1);
											verFichas(cli, x);
											sleep(1);
											printf("\nS %d:_ %d\n",x , cli[x].socket);
											strcpy(auxl, "");
											sprintf(auxl,"Eres el jugador %d", cli[x].socket);
											send(cli[x].socket,auxl, 100, 0);
											sleep(1);
											printf("\nS %d:_ %d\n",x , cli[x].socket);
											strcpy(auxl2,"");
											sprintf(auxl2,"Es el turno del jugador %d", party[nMesa].turno);
											send(cli[x].socket,auxl2, 100, 0);
											sleep(1);
											}

										

										esperando=-1;
										nMesa++;
										}
									else
										{
										
										send(cliente[j].socket, "\n+Ok. Esperando a la partida\n", 100, 0);
										}
									}
								else if((strncmp(buffer, "SALIR", 5))==0)
									{
									send(cliente[j].socket, "FIN\n", 100, 0);
									cliente[j].nivel=-1;	
									}
								else
									{
									send(cliente[j].socket, "\n-Error. (iniciar partida o salir)\n\0", 100, 0);	
									}
								}
							else if (cliente[j].nivel==2)
								{
								for(i=0;i<10;i++)
									{
									if(cliente[j].mesa==party[i].numpartida)
										{
										if(party[i].turno==cliente[j].socket)
											{	
											printf("\nTURNO CORRECTO\n");
											send(cliente[j].socket, "TURNO CORRECTO", 100, 0);

											if((strncmp(buffer, "FICHA", 5))==0)
												{
												sscanf(buffer, "FICHA %d %d", &n1,&n2);
												flag=0;
												pep=0;
												f.izq=n1;
												f.der=n2;
												printf("\n!!!!!!!!!!!!!!!!!!!\n%d %d\n\n", f.izq,f.der);
												for(q=0;q<4;q++)
													{
													if(cli[q].socket==cliente[j].socket)
														{
														pep=q;
														printf("\nCliente encontrado\n");
														}
													}
													
															for(k=0;k<7;k++)
																{
																printf("\n|%d |%d |\n", cli[pep].fichas[k].izq, cli[pep].fichas[k].der);
																if(f.izq==cli[pep].fichas[k].izq && f.der==cli[pep].fichas[k].der)
																	{
																	flag=1;
																	printf("\nFicha encontrada\n");
																	}
																}
													
												if(flag==1)
													{
													printf("\nColocar ficha\n");
													if(ponerFicha((party), f, i))
														{
														party[i].pasar=0;
														quitarFicha(cli, f, pep);
														send(cliente[j].socket, "\n+Ok. Ficha colocada\n\0", 100, 0);
														printf("\nFICHA COLOCaaa\n");
														
														for(k=0;k<4;k++)
															{	
															if(cli[k].nFichas==0)
																{
																for(x=0;x<4;x++)
																	{
																	strcpy(auxl, "");
																	sprintf(auxl, "El jugador numero %d ha ganado", k);
																	send(cli[x].socket, auxl, 100, 0);
																	sleep(0,5);
																	send(cli[x].socket, "Fin de la partida", 100, 0);
																	cli[x].nivel=-1;
																	}	
																}


															send(party[i].usuarios[k], "TABLERO:\n", 200,0);
															send(party[i].usuarios[k], party[i].tablero, 200,0);
															sleep(0.5);
															//strcpy(aux, "");
															//sprintf(aux, "Es el turno de %d\n", party[i].turno);
															//send(party[i].usuarios[k], aux, 100, 0);
															}


														party[i].turno= ((party[i].turno) +1);
														if(party[i].turno > party[i].usuarios[3])
															party[i].turno=party[i].usuarios[0];
														send(party[i].turno, "Es tu turno", 100, 0);
														send(party[i].turno, "TUS FICHAS:\n", 100, 0);
														verFichas(cli, (pep+1)%4);
														}
													else
														{
														printf("\nError al poner la ficha\n");
														send(cli[pep].socket, "\nError al poner la ficha\n", 100, 0);
														}
													}
												else
													{
													send(cliente[j].socket, "\n-Error. No tienes esa ficha\n\0", 100, 0);
													}


																								

												}			

											else if ((strncmp(buffer, "PASO", 5))==0) 
												{
												for(q=0;q<4;q++)
													{
													if(cli[q].socket==cliente[j].socket)
														{
														pep=q;
														printf("\nCliente encontrado\n");
														}
													}

												(party[i].pasar)++;
												for(q=0;q<4;q++)
													{
													send(party[i].usuarios[q], "Han pasado turno", 200, 0);
													if(party[i].pasar==4)
														{
														flagFin=1;
														send(party[i].usuarios[q], "PARTIDA FINALIZADA", 200, 0);
														cli[i].nivel=-1;
														}
													}
												if(flagFin==0)
												{	
												party[i].turno= ((party[i].turno) +1);
														if(party[i].turno > party[i].usuarios[3])
															party[i].turno=party[i].usuarios[0];

												send(party[i].turno, "Es tu turno\n", 100, 0);
												send(party[i].turno, "TUS FICHAS:\n", 100, 0);
												verFichas(cli, (pep+1)%4);
												}
												}

											else if ((strncmp(buffer, "SALIR", 6))==0)
												{
												
												for(k=0;k<4;k++)
													{
													send(party[i].usuarios[k], "Alguien ha abandonao la partida. FIN", 100,0);
													send(party[i].usuarios[k], "SALIR1", 100,0);
													(cli[k].nivel)=-1;
													}
												}
											else
												{

												send(cliente[j].socket, "-Error. COLOCAR-FICHA |X|Y|", 100,0);
												}
											}

										}
									}
								}
							else if (cliente[j].nivel==3)
								{
								}
							else if (cliente[j].nivel==4)
								{
								}
							else
								{
								send(cliente[j].socket, "-E. Error de nivel", 100, 0);
								cliente[j].nivel=-1;
								}
							}
					
						}
				
					}
				}
			}
		
			
		
	
		}

		close(sd);
	
}


//************************************************


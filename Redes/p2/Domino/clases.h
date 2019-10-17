ff#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>



////////////////////////////////////////////////////////////////////////////

// Estructura para las posiciones de las fichas
struct ficha
{
	int izq;	//
	int der;
};

// Estructura para los clientes
struct clients
{
	char user[40];
	char pass[40];
	int nivel;
	int mesa;
	struct ficha fichas[7];
	int nFichas;
	int socket;
	int id;
};

// Estrutura para la partida
struct part
{
	int numpartida;
	char tablero[200];
	int izquierda;
	int derecha;
	int usuarios[2];
	struct ficha fichas[28];
	int turno;
	int start; // Varible de control
	int pasar;
};

////////////////////////////////////////////////////////////////////////////

void iniciarDomino(struct part n, struct clients *clientes);	// Inicia la partida de DOMINÓ con los jugadores
bool ponerFicha(struct part p, struct ficha f);								// Pone la ficha seleccionada en la mesa
void quitarFicha(struct clients *c, struct ficha f, int n);		// Quita la ficha seleccionada de la mano
void verFichas(struct clients c);															// Muestra al cliente sus fichas
int fichaMayor(struct clients cli);														// Devuelve la mayor suma de los valores entre las fichas del jugador
int comprobarTurno(struct clients *cli);											// Devuelve el jugador con el mayor doble o mayor

////////////////////////////////////////////////////////////////////////////

void iniciarDomino(struct part n, struct clients *clientes)
{
	int i, j, k, h;
	h = 0;
	k = 0;
	clientes[0].nFichas = 0;
	clientes[1].nFichas = 0;


	// Creacion de las fichas
	for(i = 0; i < 7; i++)
	{
		for(j = 6; j >= h; j--)
		{
			(n.fichas[k]).izq = i;
			(n.fichas[k]).der = j;
			printf("Ficha %d: |%d|%d|\n", h, i, j);

			k++;
		}
	h++;
	}

	srand(time(NULL));
	j = 0;

	// Cerebro galaxia: Reparto aleatorio aleatorio
	for(i = 0; i < 7; i++)
	{
		k = rand() % 2;	// Valor entre 0-1

		(clientes[k % 2]).fichas[i] = n.fichas[j];
		j++;

		(clientes[(k + 1) % 2]).fichas[i] = n.fichas[j];
		j++;


		clientes[0].nFichas++;
		clientes[1].nFichas++;
	}

	if ((clientes[0].nFichas != 7) || (clientes[1].nFichas != 7)) {
		printf("\n\nERROR. No se han repartido bien las fichas.\n");
		exit(-1);
	}
}

////////////////////////////////////////////////////////////////////////////

bool ponerFicha(struct part p, struct ficha f/*, char extremo[25]*/)
{
	int i, j;
	char aux[200];	// Tablero auxiliar
	char aux2[10];
	strcpy(aux, p.tablero);
	//printf("\n-->>>>>>>>>><PONIENDO FICHAAA\n");

/*
	if((f.izq == 6) && (f.der == 6))
	{
		//printf("\nPrimera mano\n");
		n.start = 1;
		strcpy(n.tablero, "");
		sprintf(n.tablero, "|%d|%d|", f.der, f.izq);

		n.derecha = f.der;
		n.izquierda = f.izq;

		printf("\nTABLERO\n%s\n", n.tablero);

		return true;
	}
	*/

	if (p.tablero == NULL) {
		/* code */
	}

	//printf("\nOtra mano\n");
	//printf("\nIzquierda: %d\n", n.izquierda);
	//printf("\nDerecha: %d\n", n.derecha);
	//printf("Ficha: | %d | %d | \n",f.izq, f.der);

	else if (p.izquierda == f.izq)
	{
		strcpy(p.tablero, "");
		sprintf(p.tablero, "|%d|%d|", f.der, f.izq);
		sprintf(p.tablero, "%s%s",p.tablero, aux);

		p.izquierda=f.der;

		printf("\nTABLERO\n%s\n", p.tablero);

		return true;
	}
	else if (p.izquierda == f.der)
	{
		strcpy(p.tablero, "");
		sprintf(p.tablero, "|%d|%d|", f.izq, f.der);
		sprintf(p.tablero, "%s%s",p.tablero, aux);

		p.izquierda = f.izq;

		printf("\nTABLERO\n%s\n", p.tablero);

		return true;
	}
	else if(p.derecha==f.izq)
	{
		sprintf(aux2, "|%d|%d|", f.izq, f.der);
		sprintf(p.tablero, "%s%s",p.tablero, aux2);

		p.derecha = f.der;

		printf("\nTABLERO\n%s\n", p.tablero);

		return true;
	}
	else if (p.derecha == f.der)
	{
		sprintf(aux2, "|%d|%d|", f.der, f.izq);
		sprintf(p.tablero, "%s%s", p.tablero, aux2);

		p.derecha = f.izq;

		printf("\nTABLERO\n%s\n", p.tablero);

		return true;
	}
	else
	{
		printf("\n-ERR\n\n");

		return false;
	}
}

////////////////////////////////////////////////////////////////////////////

void quitarFicha(struct clients *c, struct ficha f, int n)
{
	//printf("\n-->>>>>>quitando FICHAAA\n");
	char cad[100];
	char aux[10];
	strcpy(aux,"");
	strcpy(cad, "");
	int i;

	for(i = 0; i < 7; i++)
		{
		if((f.izq == c[n].fichas[i].izq) && (f.der == c[n].fichas[i].der))
		{
			c[n].fichas[i].izq = -1;
			c[n].fichas[i].der = -1;
		}
		else
		{
			sprintf(aux, "|%d|%d| ", c[n].fichas[i].izq, c[n].fichas[i].der);
			strcat(cad, aux);
		}
	}
	(c[n].nFichas)--;
}

////////////////////////////////////////////////////////////////////////////

void verFichas(struct clients c)
{
	char cad[100];
	char aux[10];
	strcpy(aux, "");
	strcpy(cad, "");
	int i;

	for(i = 0; i < 7; i++)
	{
		if((c.fichas[i].izq == -1) && (c.fichas[i].der == -1))
		{
			// Si no tenemos fichas, no hace nada
		}
		else
		{
			sprintf(aux, "|%d|%d| ", c.fichas[i].izq, c.fichas[i].der);
			strcat(cad, aux);
		}
	}

	send(c.socket, cad, 250, 0);
}

////////////////////////////////////////////////////////////////////////////

int fichaMayor(struct clients cli)
{
	int i, mayor;

	// Valor inicial para "mayor"
	mayor = cli.fichas[0].izq + cli.fichas[0].der;
	for (i = 1; i < 7; i++)
	{
		// Comprobacion del valor total de la ficha
		if(mayor < (cli.fichas[i].izq + cli.fichas[i].der))
		{
			mayor = cli.fichas[i].izq + cli.fichas[i].der;	// Guarda el mayor valor
		}
	}

	return mayor;
}

////////////////////////////////////////////////////////////////////////////

int comprobarTurno(struct clients *cli, struct part n)
{
	int i, j, k;

	// Comprobacion de las fichas 6 a 0
	for(j = 6; j >= 0; j--)
	{
		// Comprobacion para los dos jugadores
		for(k = 0; k < 2; k++)
		{
			// Comprobacion de cada ficha
			for (i = 0; i < 7; i++) {
				// Comprobacion de fichas dobles
				if((cli[k].fichas[i].izq == j) && (cli[k].fichas[i].der == j))
				{
					ponerFicha(n, cli[k].fichas[i]);
					quitarFicha();

					return k;	// Retorna el jugador que posee la mayor ficha doble
				}
			}
		}
	}
	// En caso de no tener dobles, sale el jugador con la mayor ficha
	if(fichaMayor(cli[0]) > fichaMayor(cli[1]))
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
////////////////////////////////////////////////////////////////////////////

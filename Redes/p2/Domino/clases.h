#include <stdio.h>
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
	int izq;
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
bool ponerFicha(struct part n, struct ficha k);								// Pone la ficha seleccionada en la mesa
void quitarFicha(struct clients *c, struct ficha f, int n);		// Quita la ficha seleccionada de la mano
void verFichas(struct clients c);															// Muestra al cliente sus fichas
int fichaMayor(struct clients cli);														// Devuelve la mayor suma de los valores entre las fichas del jugador
int comprobarDobles(struct clients *cli);											// Devuelve el jugador con el mayor doble

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

bool ponerFicha(struct part n, struct ficha k/*, char extremo[25]*/)
{
	int i, j;
	char aux[200];	// Tablero auxiliar
	char aux2[10];
	strcpy(aux, n.tablero);
	//printf("\n-->>>>>>>>>><PONIENDO FICHAAA\n");

	if((k.izq == 6) && (k.der == 6))
	{
		//printf("\nPrimera mano\n");
		n.start = 1;
		strcpy(n.tablero, "");
		sprintf(n.tablero, "|%d|%d|", k.der, k.izq);

		n.derecha = k.der;
		n.izquierda = k.izq;

		printf("\nTABLERO\n%s\n", n.tablero);

		return true;
	}
	else
	{
		//printf("\nOtra mano\n");
		//printf("\nIzquierda: %d\n", n.izquierda);
		//printf("\nDerecha: %d\n", n.derecha);
		//printf("Ficha: | %d | %d | \n",k.izq, k.der);
		if(n.izquierda == k.izq)
		{
			strcpy(n.tablero, "");
			sprintf(n.tablero, "|%d|%d|", k.der, k.izq);
			sprintf(n.tablero, "%s%s",n.tablero, aux);

			n.izquierda=k.der;

			printf("\nTABLERO\n%s\n", n.tablero);

			return true;
		}
		else if (n.izquierda == k.der)
		{
			strcpy(n.tablero, "");
			sprintf(n.tablero, "|%d|%d|", k.izq, k.der);
			sprintf(n.tablero, "%s%s",n.tablero, aux);

			n.izquierda = k.izq;

			printf("\nTABLERO\n%s\n", n.tablero);

			return true;
		}
		else if(n.derecha==k.izq)
		{

			sprintf(aux2, "|%d|%d|", k.izq, k.der);
			sprintf(n.tablero, "%s%s",n.tablero, aux2);

			n.derecha = k.der;

			printf("\nTABLERO\n%s\n", n.tablero);

			return true;
		}
		else if (n.derecha == k.der)
		{
			sprintf(aux2, "|%d|%d|", k.der, k.izq);
			sprintf(n.tablero, "%s%s", n.tablero, aux2);

			n.derecha = k.izq;

			printf("\nTABLERO\n%s\n", n.tablero);

			return true;
		}
		else
		{
			printf("\n-ERR\n\n");

			return false;
		}
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

	mayor = cli.fichas[0].izq + cli.fichas[0].der;
	for (i = 1; i < 7; i++)
	{
		if(mayor < (cli.fichas[i].izq + cli.fichas[i].der))
		{
			mayor = cli.fichas[i].izq + cli.fichas[i].der;
		}
	}

	return mayor;
}

////////////////////////////////////////////////////////////////////////////

int comprobarDobles(struct clients *cli)
{
	int k, j;

	for(k = 0; k < 2; k++)
	{
		for(j = 6; j <= 0; j--)
		{
			if((cli[k].fichas[j].izq == j) && (cli[k].fichas[j].der == j))
			{
				return k;
			}
		}
	}
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

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
	int fichasMonton;
	int turno;
	int start; // Varible de control
	int pasar;
};

////////////////////////////////////////////////////////////////////////////

void iniciarDomino(struct part n, struct clients *clientes);	// Inicia la partida de DOMINÓ con los jugadores
bool ponerFicha(struct part p, struct ficha f);								// Pone la ficha seleccionada en la mesa
void quitarFicha(struct clients c, struct ficha f);						// Quita la ficha seleccionada de la mano
void verFichas(struct clients c);															// Muestra al cliente sus fichas
struct ficha fichaMayor(struct clients cli);									// Devuelve la mayor ficha entre las fichas del jugador
int comprobarTurno(struct clients *cli, struct part n);				// Devuelve el jugador con el mayor doble o mayor
void quitarFichaMonton(struct part n, struct ficha f);
bool Robarficha(struct clients cli, struct part n);

////////////////////////////////////////////////////////////////////////////



void iniciarDomino(struct part n, struct clients *clientes)
{
	int i, j, k, h;
	h = 0;
	k = 0;
	clientes[0].nFichas = 0;
	clientes[1].nFichas = 0;
	n.fichasMonton=29;

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
		quitarFichaMonton(n,n.fichas[j]);
		j++;

		(clientes[(k + 1) % 2]).fichas[i] = n.fichas[j];
		quitarFichaMonton(n,n.fichas[j]);
		j++;


		clientes[0].nFichas++;
		clientes[1].nFichas++;
		n.fichasMonton-=2;
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

	// Cuando el tablero esta vacio, se coloca la ficha del jugador que empieza
	if (p.tablero == NULL) {
		p.start = 1;
		strcpy(p.tablero, "");
		sprintf(p.tablero, "|%d|%d|", f.der, f.izq);

		p.derecha = f.der;
		p.izquierda = f.izq;

		printf("\nTABLERO\n%s\n", p.tablero);

		return true;
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
		strcpy(p.tablero, "");
		sprintf(p.tablero, "|%d|%d|", f.izq, f.der);
		sprintf(p.tablero, "%s%s",p.tablero, aux);

		p.derecha = f.der;

		printf("\nTABLERO\n%s\n", p.tablero);

		return true;
	}
	else if (p.derecha == f.der)
	{
		/*sprintf(aux2, "|%d|%d|", f.der, f.izq);
		sprintf(p.tablero, "%s%s", p.tablero, aux2);*/

		strcpy(p.tablero, "");
		sprintf(p.tablero, "|%d|%d|", f.izq, f.der);
		sprintf(p.tablero, "%s%s",p.tablero, aux);

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

void quitarFicha(struct clients c, struct ficha f)
{
	//printf("\n-->>>>>>quitando FICHAAA\n");
	int i;

	// Recorremos las fichas del jugador
	for(i = 0; i < c.nFichas; i++)
	{
		// Se encuentra la ficha que se quiere eliminar
		if((f.izq == c.fichas[i].izq) && (f.der == c.fichas[i].der))
		{
			while(i < c.nFichas - 1) {
				c.fichas[i] = c.fichas[i + 1];	// Copiamos las fichas restantes
			}
		}
	}

	c.nFichas--;
}
////////////////////////////////////////////////////////////////////////////

void quitarFichaMonton(struct part n, struct ficha f)
{
	//printf("\n-->>>>>>quitando FICHAAA\n");
	int i;

	// Recorremos las fichas del jugador
	for(i = 0; i < n.fichasMonton; i++)
	{
		// Se encuentra la ficha que se quiere eliminar
		if((f.izq == n.fichas[i].izq) && (f.der == n.fichas[i].der))
		{
			while(i < n.fichasMonton - 1) {
				n.fichas[i] = n.fichas[i + 1];	// Copiamos las fichas restantes
			}
		}
	}

	n.fichasMonton--;
}

////////////////////////////////////////////////////////////////////////////

void verFichas(struct clients c)
{
	char cad[100];
	char aux[10];
	int i;

	strcpy(aux, "");
	strcpy(cad, "");

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

struct ficha fichaMayor(struct clients cli)
{
	int i, mayor;
	struct ficha aux;
	// Valor inicial para "mayor"
	mayor = cli.fichas[0].izq + cli.fichas[0].der;
	for (i = 1; i < 7; i++)
	{
		// Comprobacion del valor total de la ficha
		if(mayor < (cli.fichas[i].izq + cli.fichas[i].der))
		{
			aux = cli.fichas[i];	// Guarda el mayor valor
		}
	}

	return aux;
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
					quitarFicha(cli[k], cli[k].fichas[i]);

					return k;	// Retorna el jugador que posee la mayor ficha doble
				}
			}
		}
	}
	// En caso de no tener dobles, sale el jugador con la mayor ficha
	if((fichaMayor(cli[0]).izq + fichaMayor(cli[0]).der) > (fichaMayor(cli[1]).izq + fichaMayor(cli[1]).der))
	{
		ponerFicha(n, fichaMayor(cli[0]));
		quitarFicha(cli[0], fichaMayor(cli[0]));

		return 0;
	}
	else
	{
		ponerFicha(n, fichaMayor(cli[1]));
		quitarFicha(cli[1], fichaMayor(cli[1]));

		return 1;
	}
}
////////////////////////////////////////////////////////////////////////////
bool Robarficha(struct clients cli, struct part n){

struct ficha aux;
aux=n.fichas[0];
cli.nFichas++;
cli.fichas[cli.nFichas]=aux;
quitarFichaMonton(n,aux);
}

int Caminos(int f,int c, vector<Punto> caminoParcial, vector < vector < Punto> > &caminoTotal){

//Declaramos objetos de tipo punto para guardar coordenadas
struct Punto p;

//CASOS BASE

  //Cuando f o c se sale del tablero
	if((f < 1) || (f > 8)){
		return 0;
	}

	if((c < 1) || (c > 8)){
		return 0;
	}

  //Caso base cuando se llega a la fila 1(este es el punto últimode nuestro camino
	if(f == 1){
		p.f = f;
		p.c = c;

    //Guardamos las coordenadas en el vector
		caminoParcial.push_back(p);

    //Se acaba el camino asi que metemos el vector guardado en la matriz convirtiendose en una fila mas de dicha matriz
		caminoTotal.push_back(caminoParcial);

		return 1;
	}

  //Se van recorriendo las coordenadas que si pertenecen al camino c guardando en el vector
	else{
		p.f = f;
		p.c = c;

		caminoParcial.push_back(p);

    return (Caminos(f-1, c-2, caminoParcial, caminoTotal) + Caminos(f-2, c-1, caminoParcial, caminoTotal) + Caminos(f-2, c+1, caminoParcial, caminoTotal) + Caminos(f-1, c+2, caminoParcial, caminoTotal));
	}
}



//////////////////////////////////////////////////////////////////////////////////////////////////


int caminos(Punto destino, std::vector<Punto> caminoParcial, std::vector<std::vector<Punto>> caminoTotal) {

  // class Punto p;

  if ((destino.f < 1) || (destino.f > 8)) {
    return 0;
  }

  if ((destino.c < 1) || (destino.c > 8)) {
    return 0;
  }


  if (destino.f == 1) {
    // p.f = destino.f;
    // p.c = destino.c;

    caminoParcial.push_back(destino);
    caminoTotal.push_back(caminoParcial);

    return 1;

  } else {

    caminoParcial.push_back(destino);

    Punto destino1, destino2, destino3, destino4;

    destino1.f = destino.f-1;
    destino1.c = destino.c-2;

    destino2.f = destino.f-2;
    destino2.c = destino.c-1;

    destino3.f = destino.f-2;
    destino3.c = destino.c+1;

    destino4.f = destino.f-1;
    destino4.c = destino.c+2;


    return (caminos(destino1, caminoParcial, caminoTotal) + caminos(destino2, caminoParcial, caminoTotal) + caminos(destino3, caminoParcial, caminoTotal) + caminos(destino4, caminoParcial, caminoTotal));

  }

}


//////////////////////////////////////////////////////////////////////////////////////////

int caminos(Punto destino, std::vector<Punto> caminoParcial, std::vector<std::vector<Punto>> caminoTotal) {

  if (destino.f < 1 || destino.f > 8) {
    return 0;
  }

  if (destino.c < 1 || destino.c > 8) {
    return 0;
  }

  if (destino.f == 1) {

    caminoParcial.push_back(destino);
    caminoTotal.push_back(caminoParcial);

    return 1;

  } else {

    caminoParcial.push_back(destino);

    Punto destino1, destino2, destino3, destino4;

    destino1.f = destino.f-1;
    destino1.c = destino.c-2;

    destino2.f = destino.f-1;
    destino2.c = destino.c-2;

    destino3.f = destino.f-1;
    destino3.c = destino.c-2;

    destino4.f = destino.f-1;
    destino4.c = destino.c-2;


    return (caminos(destino1, caminoParcial, caminoTotal) + caminos(destino2, caminoParcial, caminoTotal) + caminos(destino3, caminoParcial, caminoTotal) + caminos(destino4, caminoParcial, caminoTotal));

  }

}

Entero Entero::operator * (Entero e2) {

  std::string entero1 = this->getEntero();
  std::string entero2 = e2.getEntero();

  int tam1 = entero1.size()-1;
  int tam2 = entero2.size()-1;

  std::string aux, aux1, aux2, resultado1, resultado2;

  int x1, y1, multimplicacion = 0;

  int mayor;
  if (tam1 > tam2) {
    mayor = tam1;
  } else {
    mayor = tam2;
  }

  if (mayor <= 4) {
    x1 = stoi(entero1);
    y1 = stoi(entero2);

    resultado1 = to_string(x1 * y1);
    setEntero(resultado);

    return resultado1;
  }

  std::string w, x, y, z;
  int s = mayor/2;

  if (entero1.lenght() > s) { // Si el tamaño del entero es mayor que S, se divide
    for (size_t i = 0; i < entero1.length()-s; i++) {
      aux = entero1[i];
      w.append(aux);  //Primera mitad del primer entero.
    }

    for (size_t j = entero1.lenght()-s; j < entero1.length(); j++) {
      aux = entero1[j];
      x.append(aux);  //Segunda mitad del primer entero.
    }
  }

  else {  // Si el tamaño del entero es menor que S, se introduce entero en X, W queda vacio
    w = "0";

    for (size_t k = 0; k < entero1.length(); k++) {
      aux = entero1[k];
      x.append(aux);
    }
  }


  if (entero2.lenght() > s) { // Si el tamaño del entero es mayor que S, se divide
    for (size_t i = 0; i < entero2.length()-s; i++) {
      aux = entero2[i];
      y.append(aux);  //Primera mitad del primer entero.
    }

    for (size_t j = entero2.lenght()-s; j < entero2.length(); j++) {
      aux = entero2[j];
      z.append(aux);  //Segunda mitad del primer entero.
    }
  }

  else {  // Si el tamaño del entero es menor que S, se introduce entero en Y, Z queda vacio
    y = "0";

    for (size_t k = 0; k < entero2.length(); k++) {
      aux = entero2[k];
      z.append(aux);
    }
  }

  //Primer entero
  Entero W(w);
  Entero X(x);

  //Segundo entero
  Entero Y(y);
  Entero Z(z);

  //Resultado
  aux1 = (W*Y).getEntero();
  agregarCerosDerecha(aux1, 2*s);

  entero1.setEntero(aux1);

  std::string uno = "1";
  Entero diez(agregarCerosDerecha(uno, s));

  Entero resultado(entero1);
  resultado += (((W*Z) + (X*Y)) * (diez + (X*Z)));

  return resultado;

}

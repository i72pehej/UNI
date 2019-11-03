#include "operadoresExternos.hpp"

namespace al{
  al::Entero & operator+(al::Entero const &e1,  al::Entero const &e2){
    int diferencia;
    string resultado;
    Entero *res;
    int acarreo = 0;
    al::Entero auxE = new al::Entero();
    diferencia = e1.getTamano() - e2.getTamano();
    if (diferencia < 0) {
      string aux = getEntero();
      agregarCerosDelante(aux, abs(diferencia));
      setEntero(aux);
    } else if (diferencia > 0){
      string aux = e2.getEntero();
      agregarCerosDelante(aux, diferencia);
      e2.setEntero(aux);
    }

    resultado.resize(getTamano() + 1);
    string aux1 = e1.getEntero();
    string aux2 = e2.getEntero();
    for (int i=e1.getTamano()-1; i>=0; i--){
      int i1 = aux1[i]-'0';
      int i2 = aux2[i]- '0';
      int suma = i1 + i2 + acarreo;
      if (suma < 10){
        resultado[i+1] = (char)suma + 48;
        acarreo = 0;
      }
      else {
        suma = suma % 10;
        resultado[i+1] = (char)suma + 48;
        acarreo = 1;
      }
    }
    if (acarreo == 1){
      resultado[0] = '1';
    } else if (acarreo == 0){
      resultado[0] = '0';
    }
      quitarCerosNoSignificativos(resultado);
        cout<<"manada?"<<resultado<<endl;
      auxE.setEntero(resultado);
      cout<<auxE.getEntero()<<endl;
      return auxE;

  }
}

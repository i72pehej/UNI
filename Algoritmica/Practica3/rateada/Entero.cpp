#include "Entero.hpp"

 al::Entero  al::Entero::operator+(Entero a){
   //variables operando y resultado
 string Primero=getEntero();
 string Segundo=a.getEntero();
 string result;

 //variables para el calculo
 int suma;
 int acarreo=0;
 string auxp, auxs;
 string Suma;


 int psize=Primero.length();
 int ssize=Segundo.length();
 int p=psize-1;
 int s=ssize-1;


 for(;p>=0 || s>=0;)
 {

   if(p>=0 && s>=0)
   {
     auxp=Primero[p];
     auxs=Segundo[s];
     if(Primero[p]!='\0' && Segundo[s]!='\0')
       suma=stoi(auxp)+stoi(auxs);
   }
   else if(p>=0)
   {
     auxp=Primero[p];
     if(Primero[p]!='\0')
       suma=stoi(auxp);
   }
   else
   {
     auxs=Segundo[s];
     if(Segundo[s]!='\0')
       suma=stoi(auxs);
   }

   if(acarreo==1)
     suma++;

   if(suma<10)
   {
     Suma=to_string(suma);
     result.append(Suma);
     acarreo=0;
   }
   else
   {
     suma=suma%10;
     Suma=to_string(suma);
     result.append(Suma);
     acarreo=1;
   }
   p--;
   s--;
 }

 if(acarreo==1)
   result.append("1");


 string aux=result;
 for(int i=0;i<result.length();i++)
   result[i]=aux[result.length()-1-i];

 Entero resultado(result);
 return resultado;
 }


al::Entero  al::Entero::operator*(Entero a)
{
  int n;
  int S;
  string w, x, y, z, diez_eS;
  string aux;
  if(this->getTamano()>a.getTamano()){
    n = this->getTamano();
  }
  else{
      n = a.getTamano();
  }

	if(n<=4)
	{
		Entero resultado(to_string(this->getvalor()*a.getvalor()));
		return resultado;
	}
  S=n/2;

	diez_eS="1";
    for(int i=0;i<S;i++)
    diez_eS.append("0");


	if(this->getTamano()>S)
	{
		for(int i=0;i<this->getEntero().length()-S;i++)
		{
			aux=this->getEntero()[i];
			w.append(aux);
		}
		for(int i=this->getEntero().length()-S; i<this->getEntero().length();i++)
		{
			aux=this->getEntero()[i];
			x.append(aux);
		}
	}
	else
	{
		w="0";
		for(int i=0; i<this->getEntero().length();i++)
		{
			aux=this->getEntero()[i];
			x.append(aux);
		}
	}

	if(a.getTamano()>S)
	{
		for(int i=0;i<a.getEntero().length()-S;i++)
		{
			aux=a.getEntero()[i];
			y.append(aux);
		}
		for(int i=a.getEntero().length()-S; i<a.getEntero().length();i++)
		{
			aux=a.getEntero()[i];
			z.append(aux);
		}
	}
	else
	{
		y="0";
		for(int i=0; i<a.getEntero().length();i++)
		{
			aux=a.getEntero()[i];
			z.append(aux);
		}
	}

	Entero diezS(diez_eS);
	Entero W(w), X(x), Y(y), Z(z);

	Entero potencia10((W*Y).getEntero());
	string termino_1=potencia10.getEntero();

	Entero auxiliar(termino_1);
	if(auxiliar.isCero()==0){
    for(int i=0;i<2*S;i++)
    termino_1.append("0");
  }
	Entero resultado(termino_1);
	resultado=resultado+(W*Z+X*Y)*diezS+X*Z;
	return resultado;
}

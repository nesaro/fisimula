#include <iostream>
#include "calcdata.hpp"
#include "calcsyn.hpp"

using namespace std;

bool ordenlista::introducirlista(lista lista1)
{
  entrada=lista1;
  return true;
}

lista ordenlista::devolverlista()
{
  return salida;
}
void ordenlista::orden()
{
  int anteriorprior; //valor donde se guarda la importancia del ultimo operador
  bool fin;
  char operador;
  unidaddato temp;
  espacio_dato tempespacio;
  int i,pref1,contador;
  fin=0;
  contador=0; //prueba para ver lo que pasa
  i=1;
  pref1=10000; //la nueva prioridad
  while (entrada.numelem()>1)
    {
      temp=entrada.dumpdata(2);
      tempespacio=temp.regresavalor();
      operador=tempespacio.c;
      //cout << operador << prioridadoperador(operador) << pref1 << "\n";
      if (prioridadoperador(operador) > pref1)
	{
	  salida >> entrada.dumpdata(2);
	  salida << entrada.dumpdata(1);
	  //poner el operador al principio
	}
      else
	{
	  salida << entrada.dumpdata(2);
	  salida << entrada.dumpdata(1);
	  //poner los dos al final y agusto 
	}
      entrada.borrardato(1);
      entrada.borrardato(1);
      contador++;
      //Necesario crear una libreria de constantes compartida con calcparser
      pref1=prioridadoperador(operador);
    }
  salida << entrada.dumpdata(0);
}  
//Una lista de entrada, otra de salida. Una funcion que vaya ordenando de izquierda a derecha
//Si encuentra un simbolo pone el simbolo a la derecha del todo de la nueva lista, despues el 
//termino de la izquierda. Despues comprueba el proximo operador. Si el nuevo operador es mas 
//importante, el operador ira despues del termino de la izquierda ( y despues los dos terminos que
//acompañan). Si es menos o igual de importante, el simbolo se pone a la derecha del todo y el otro
//numero a la izquierda.(el numero en juego se pone despues del de la izquierda original. Parece suficiente

int ordenlista::prioridadoperador(char pepe){
  string unitario;
  string operadores1="*/";
  string operadores2="+-";  
  unitario[0]=pepe; // va a petar
  if (operadores1.find(pepe,0)!=operadores1.npos)
    {
      return 0;
    }
  if (operadores2.find(pepe,0)!=operadores2.npos)
    {
      return 1;
    }
  return -1; //Error
}



/* int main()
   {
   string pepi="49+50*51+52";
   calcparser ordenador;
   lista milista,milista2;
   ordenlista reorg;
   ordenador.ingresacadena(pepi);
   milista=ordenador.devolverlista();
   //  milista.mostrardatos();  
   reorg.introducirlista(milista);
   reorg.orden(milista);
   milista2=reorg.devolverlista();
   // milista2.mostrardatos();
   return 0;
   } */

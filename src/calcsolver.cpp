#include <iostream>
#include "calcdata.hpp"
#include "libcalc.hpp"
#include "calcsolver.hpp"
using namespace std;

void calcsolver::recibir(lista pepe)
{
  entrada=pepe;
}

void calcsolver::resolv()
{
  result=resolver(entrada,1);
}

int calcsolver::devolver()
{
  return result;
}


int calcsolver::resolver(lista & relement, int posicion)
{
  int primertermino,segundotermino,vuelta;
  if (relement.dumpdata(posicion+1).dimetipo() == 1)
    {
      primertermino=relement.dumpdata(posicion+1).regresavalor().i;
    }
  else
    {
      primertermino=resolver(relement,posicion+1);
    }
  if (relement.dumpdata(posicion+2).dimetipo() == 1)
    {
      segundotermino=relement.dumpdata(posicion+2).regresavalor().i;
    }
  else
    {
      segundotermino=resolver(relement,posicion+2);
    }
  
  //  cout << "primero " << primertermino << "segundo " << segundotermino << "\n";
  vuelta=boperation(relement.dumpdata(posicion),primertermino,segundotermino);
  //  cout << "primera parte, posicion" << posicion << "\n" ;
  //  relement.mostrardatos();
  relement.borrardato(posicion);
  //  cout << "segunda parte, posicion" << posicion << "\n" ;
  //  relement.mostrardatos();
  relement.borrardato(posicion);
  //  cout << "tercera parte, posicion" << posicion << "\n" ;
  //relement.mostrardatos();
  relement.borrardato(posicion);
  //cout << "cuarta parte, posicion" << posicion << "\n" ;
  //relement.mostrardatos();
  relement.insertdata(vuelta,posicion-1);
  //  cout << "quinta parte, posicion" << posicion << "\n" ;
  //  relement.mostrardatos();
  //requiero poder insertar datos a la altura posicion
  result=vuelta;
}

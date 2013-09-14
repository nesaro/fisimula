#ifndef __ORDENLISTA_H
#define __ORDENLISTA_H
#include <iostream>
#include "calcdata.hpp"
using namespace std;

class ordenlista
{
public:
  void orden();
  bool introducirlista(lista lista1);
  lista devolverlista();
  int prioridadoperador(char);  
  
private:
  lista entrada,salida;
};

#endif

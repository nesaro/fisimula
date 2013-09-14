#ifndef __CALCSOLVER_H
#define __CALCSOLVER_H

#include <iostream>
#include "calcdata.hpp"
#include "libcalc.hpp"
using namespace std;

class calcsolver 
{
public:
  void  recibir(lista);
  void resolv(); //"public" function
  int  devolver();
  
private:
  int  resolver(lista &, int);//"private" function
  lista entrada;
  int result;
};

#endif

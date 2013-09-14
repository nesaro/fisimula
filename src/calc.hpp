#ifndef __CALC_H
#define __CALC_H
#include "calcdata.hpp"

/* Cabecera de calculadora.cpp, declaración de clase */

class calculadora
{
public:
  void  obtenercadena();
  int resultado();
  void encender();
  void apagar();
  bool led();
  
private:
  string cadena;
  lista listaprincipal;
  int result;
  bool encendido;
  bool findecadena(char[]);
  bool findecadena(string);
  int  calcular(string expresion);
};
#endif
       





#include <iostream>
#include "libcalc.hpp"
#include "calcdata.hpp"
using namespace std;

string operadorestot="+-*/";
string operadores0="*/";
string operadores1="+-";

bool localizaroperador(char entrada ,int prioridad)
{
  if (operadores0.find(entrada,0))
    {
      prioridad=0;
      return true;
    }

  if (operadores1.find(entrada,0))
    {
      prioridad=1;
      return true;
    }
}

bool localizaroperador(char entrada)
{
  if (operadorestot.find(entrada,0))
    {
      return true;
    }
  else 
    {
      return false;
    }
}

//la operacion más basica, aplicada recursivamente

int boperation(unidaddato operador,int primero,int segundo)
{
  espacio_dato pepe;
  pepe= operador.regresavalor();
  if (pepe.c == '+')
    {
      return primero+segundo;
    }
  
  if (pepe.c == '*')
    {
      return primero*segundo;
    }

  if (pepe.c == '-')
    {
      return primero-segundo;
    }
  if (pepe.c == '/')
    {
      return primero/segundo;
    }

}

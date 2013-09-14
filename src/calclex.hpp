#ifndef __CALCPARSER_H
#define __CALCPARSER_H

#include <string>
#include "calcdata.hpp"
#include "libfisimula.hpp"
using namespace std; 

/* libreria calcparser.cpp ... Esta libreria tiene por objetivo ofrecer un método para pasar una string cualquiera al formato de lista enlazada preparada por myself, en el orden natural ordenlista se encargara de ordenarla*/

class calcparser{
public:
  int ingresacadena(string pepe);
  lista devolverlista();
private:
  string cadena;
  lista listaliteral;
  int crearlista();
  int nummach(string); // nummach return the size of the first token as number
  int symmach(string);
  int eqmach(string);
  int numtr(string);
  int symtr(string);
  int eqtr(string);
};

#endif

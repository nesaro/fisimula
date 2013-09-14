#ifndef __LIBFISIMULA_H
#define __LIBFISIMULA_H
#include <string>
using namespace std;

bool dividecadena(char cadena[], char *operando1, char *operando2,int posicion);
bool cadenatoint(char expresion[], int & pepe);
bool cadenatoint(string expresion, int & pepe);
string quitaespaciocadena(char* );
string quitaespaciocadena(string);
#endif

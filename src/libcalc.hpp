#ifndef __LIBCALC_H
#define __LIBCALC_H
#include <iostream>
#include "calcnode.hpp"
using namespace std;

bool localizaroperador(char,int &); //int = prioridad
bool localizaroperador(char); //int = prioridad
int boperation(unidaddato,int,int);

#endif

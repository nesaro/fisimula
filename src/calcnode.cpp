#include <iostream>
#include "calcnode.hpp"
using namespace std;

/* unidaddato.cpp Copyright (C) 2004 Néstor Arocha <bourbaki@idecnet.com>*/

/* This program is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public License
   as published by the Free Software Foundation; either version 2
   of the License, or (at your option) any later version. 
   this program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*/

/* Tipo de dato basico para la calculadora y la lista enlazada */

int unidaddato::ingresadato(int dato){
  datoensi.i=dato;
  tipo_dato=1;
  return 0; 
}

int unidaddato::ingresadato(char dato){
  datoensi.c=dato;
  tipo_dato=2;
  return 0;
}
int unidaddato::ingresadato(float dato){
  datoensi.f=dato;
  tipo_dato=3;
  return 0;
}
void unidaddato::ingresadato(espacio_dato pepe){
  datoensi=pepe;
}

espacio_dato unidaddato::regresavalor(){
  return datoensi;
}

int unidaddato::dimetipo(){
  return tipo_dato;
}



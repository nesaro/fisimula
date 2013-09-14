#include <iostream>
#include <string>
#include "libfisimula.hpp"
#include <math.h>
using namespace std;

/* cadenas.c++ Copyright (C) 2003 Néstor Arocha <bourbaki@idecnet.com>*/

/* This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version. 
 * this program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 * */

bool cadenatoint (string expresion, int & devolver)
{
  int i;
  string numeros="0123456789";
  devolver=0;
  for (i=0;i<(expresion.size());i++)
    {
      //typecasting rocks
      devolver=devolver+(numeros.find(expresion.substr (i,1),0)*(int)pow10(expresion.size()-i-1)); 
    }
  return true;
}

bool cadenatoint (char expresion[], int &devolucion)
{
	int len, i, b, c, d;	//sacar de la funcion como intercambiador de cadena
	double j;
	int sumandoint;
	b = 0;
	j = 10;
	len = strlen (expresion);
	//    cout << "Esta es la longitud de la cadena a copiar" << len << "\n";
	char copiaex[len];
	for (i = 0; i < len; i++)
	{
		copiaex[i] = expresion[len - i - 1];
	}
	copiaex[len] = '\0';
	//    cout << "Esta es la cadena copiada y modificada" << copiaex << "\n";
	for (i = 0; i < len; i++)
	{
		d = copiaex[i] - 48;
		c = (int)pow (j, i);
		b = b + d * c;
	}
	//    cout << "Este es el valor del entero" << b << "\n";
	devolucion = b;
	return true;
}

bool dividecadena (char cadena[], char *operando1, char *operando2, int posicion)
{
	int size;
	char *ap1, *ap2;
	size = strlen (cadena);
	ap1 = cadena;
	ap2 = ap1 + posicion + 1;
	strncpy (operando1, ap1, posicion);
	strncpy (operando2, ap2, size - posicion - 2);
	operando1[posicion] = '\0';
	operando2[size - posicion - 2] = '\0';
}

string quitaespaciocadena (char * cadena) 
{
  string cadena2=cadena;
  string espacio=" ";
  int tama; 
  int i=0; // contador
  char j;
  tama=strlen(cadena);
  // cadena2.insert(tama,espacio);
  while(i<tama)
    {
      //  posicion=cadena2.find(espacio,0);
      if(j == espacio[0])
	{
	  cadena2.erase (i-1,1);
	}
      j=cadena2[i];
      i++;
    }
  return cadena2 ;
}

string quitaespaciocadena (string cadena) 
{
  string espacio=" ";
  while(cadena.find(espacio,0)!=cadena.npos)
    {
      cadena.erase(cadena.find(espacio,0),1);
    }
  return cadena;
}



















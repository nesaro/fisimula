#include <iostream>
#include <string>
#include "calc.hpp"
#include "libfisimula.hpp"
#include "calcdata.hpp"
#include "calclex.hpp"
#include "calcsyn.hpp"
#include "calcsolver.hpp"

using namespace std;

/* calculadora.cpp Copyright (C) 2003 Néstor Arocha <bourbaki@idecnet.com>*/

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


/* Libreria de calculadora, su proposito es crear un objeto que guarde una o mas cadenas, 
que la guarde a su vez como lista, y que pueda dar un resultado arbitrariamente preciso sobre la cadena */

void calculadora::obtenercadena ()
{
  cin >> cadena;
}

int calculadora::resultado ()
{
  calcular (cadena);
  return result;
}

void calculadora::encender ()
{
  cout << "calculator mode! type \"exit\" to exit\n";
  encendido = true;
}

void calculadora::apagar ()
{
  encendido = false;
}

bool calculadora::led ()
{
  if (encendido == true)
    {
      return true;
    }
  else
    {
      return false;
    }
}
bool calculadora::findecadena (char cadena[])
{
  int longitud;
  char *cescape = "=";
  longitud = strlen (cadena);
  if (cadena[longitud - 1] == *cescape)
    {
      return true;
    }
  else
    {
      return false;
    }
}

bool calculadora::findecadena (string cadena)
{
  string cescape = "=";
  if (cadena.find(cescape,cadena.size()-1) != cadena.npos)
    {
      return true;
    }
  else
    {
      return false;
    }
}

int calculadora::calcular (string expresion)
{
  int resultado;
  int devuelto;
  string salida = "exit";
  lista pepe;
  calcparser parseador;
  ordenlista ordenador;
  calcsolver resolvedor;
  expresion=quitaespaciocadena (expresion);
  if (expresion.find(salida,0)!=expresion.npos)// exit
    {
      apagar ();
      cin.ignore ();
      return false;
    }
  else
    {      
      if (!findecadena (expresion))
	{
	  cout << "invalid expression (string last character must be \"=\")\n";
	  return true;
	}
      else
	{
	  // lexical ok
	  int myval;
	  expresion.erase(expresion.size());
	  cout << expresion;
	  myval=parseador.ingresacadena(expresion);
	  if (!myval)
	    {
	      pepe=parseador.devolverlista();
	      
	      // syntactic ok
	      ordenador.introducirlista(pepe);
	      ordenador.orden();
	      pepe=ordenador.devolverlista();	      
	      // semantic ok
	      resolvedor.recibir(pepe);
	      resolvedor.resolv();
	      cout << resolvedor.devolver() << "\n";
	      resultado=1;
	    }
	  else 
	    {
	      cout << "lexical error\n";
	    }
		resultado=1;
	  return true;
	}
    }
}


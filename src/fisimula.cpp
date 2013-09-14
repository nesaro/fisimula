#include <iostream>
#include <string>
#include "calc.hpp"
#include "menu.hpp"
using namespace std;
#define VERSION "0.1.1"

/* fisimula.cpp Copyright (C) 2004 Néstor Arocha <bourbaki@idecnet.com>*/

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

/* Fichero Principal con llamada al menu */

bool evaluar(char);

main(int argc) {
  char i;
  bool salir = false;
  if (argc > 1)
	{ 
	  cout << "Fisimula " << VERSION << ", no argument support :/\n" ;
	return 0;
	}
  else
  {
  cout << "This is fisimula" << VERSION <<"!\n";
  llmenu();
  while (salir == false)
    {
      i=copcion();
      salir=evaluar(i);
    }
}
}
bool evaluar(char op) 
{
  calculadora basica;
  bool salir=false;
  switch(op)
    {
    case 0:
      salir=true;
      return salir;
      break;
      
    case 1:
      llmenu();
      return salir;
      break;
      
    case 2:
      basica.encender();
      while(basica.led())
      {
	basica.obtenercadena();
	basica.resultado();
      }
      return salir;
      break;
      
    default:
      cout << "unknown option\n";
      return salir;
      break; 
    }
}

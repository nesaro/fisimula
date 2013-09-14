#include <iostream>
using namespace std;

/* menu.cpp Copyright (C) 2004 Néstor Arocha <bourbaki@idecnet.com>*/

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

/* Libreria que contiene los graficos del menu (MUY VERDE)*/
/* Menu lib */

void llmenu()
{
  cout << "************************\n";
  cout << "Type \"0\" to exit\n";
  cout << "Type \"1\" for help\n";
  cout << "Type \"2\" to set calculator mode\n";
  cout << "************************\n";
}
char copcion(){
  char c;
  cout << "Next action (1=help)?\n";
  cin.get(c);
  cin.ignore(); //Blindado de entrada
  c -= 48;
  return c;
}





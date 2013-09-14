#include <string>
#include <iostream>
#include "calcdata.hpp"
#include "libfisimula.hpp"
#include "calclex.hpp"
typedef int (calcparser::*mcn)(string);
using namespace std;

//donde colocar la funcion de entrada string y salida lista?

int calcparser::ingresacadena(string pepe)
{
  int myval;
  cadena=pepe;
  myval=crearlista();
  return myval;
}

lista calcparser::devolverlista()
{
  return listaliteral;
}

int calcparser::crearlista()
{
  mcn automat[3],sectmat[3];
  string tempstr;
  int current,type,big;
  bool halt=false;
  while (cadena.size()!=0 && !halt)
    {
      automat[0]=&calcparser::nummach;
      automat[1]=&calcparser::symmach;
      automat[2]=&calcparser::eqmach;
      sectmat[0]=&calcparser::numtr;
      sectmat[1]=&calcparser::symtr;
      sectmat[2]=&calcparser::eqtr;
      type=0;
      big=0;
      for (int j=0;j<3;j++)
	{
	  current=(this->*automat[j])(cadena);
	  if (current>type)
	    {
	      type=j;
	    }
	  if (current>big)
	    {
	      big=current;
	    }
	}
      if (big==0)
	{
	  halt=true;
	}
      else
	{
	  tempstr=cadena.substr(0,big);
	  cadena=cadena.substr(big,cadena.size());      
	  (this->*sectmat[type])(tempstr);
	}
    }
  return halt;
}

int calcparser::nummach(string hall)
{
  int bestnum=0;
  string numbers="0123456789";
  for(int i=0;i<hall.size();i++)
    {
      if (numbers.find(hall.substr(i,1)) != numbers.npos)
	{
	  bestnum=i+1;
	}
      else
	{
	  i=hall.size();
	}
    }
  return bestnum;
}

int calcparser::symmach(string hall)
{
  int bestnum=0;
  string symb="+-*/";
  if (symb.find(hall.substr(0,1))!=symb.npos)
    {
      bestnum=1;
    }
  return bestnum;
}

int calcparser::eqmach(string hall)
{
  int bestnum=0;
  string symb="=";
  if (symb.find(hall.substr(0,1))!=symb.npos)
    {
      bestnum=1;
    }
  return bestnum;
}

int calcparser::numtr(string num)
{
  int value;
  cadenatoint(num,value);
  listaliteral << value;  
  return 1;
}

int calcparser::symtr(string sym)
{
  int value;
  listaliteral << sym.c_str()[0];
  return 1;
}

int calcparser::eqtr(string sym)
{
  return 1;
}

/* // C++
   // type-definition: 'pt2Member' now can be used as type
   typedef int (TMyClass::*pt2Member)(float, char, char);
   
   // illustrate how to work with an array of member function pointers
   void Array_Of_Member_Function_Pointers()
   {
   cout << endl << "Executing 'Array_Of_Member_Function_Pointers'" << endl;
   
   // <funcArr> is an array with 10 pointers to member functions which return an
   // int and take a float and two char
   pt2Member funcArr[10];
   
   // assign the function's address - 'DoIt' and 'DoMore' are suitable member functions
   // of class TMyClass like defined above in 2.1-4
   funcArr[0] = &TMyClass::DoIt;
   funcArr[1] = &TMyClass::DoMore;
   
   // calling a function using an index to address the member function pointer
   // note: an instance of TMyClass is needed to call the member functions
   TMyClass instance;
   cout << (instance.*funcArr[1])(12, 'a', 'b') << endl;
   cout << (instance.*funcArr[0])(12, 'a', 'b') << endl;
*/
      

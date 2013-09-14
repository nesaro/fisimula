#include <iostream>
#include "calcnode.hpp"
#include "calcdata.hpp"
using namespace std;


/* datoscalc.cpp Copyright (C) 2004 Néstor Arocha <bourbaki@idecnet.com>*/

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

/* Libreria de clases de lista enlazada */

lista::lista()
{
  tamano=0;
}

lista::~lista() 
{
  //  for (int i=0;i<tamano;i++)
  //    {
  //    this->borrardato(1);
  //  }
}
unidaddato lista::dumpdata(int posicion)
{
  nodo * temp;
  temp=cabeza;
  int counter=1;
  //devuelve el dato de la posicion posicion
  while (counter<posicion)
    {
      temp = temp->returnsiguiente();
      counter++;
    }
  return temp->volcardato();
}

void lista::borrardato(int posicion)
{
  nodo * temp;
  nodo * anterior;
  nodo * siguiente;
  temp=cabeza;
  if (temp->returnsiguiente()==NULL )
    {
      //      cout << "soy nulo y tamano vale " << tamano << "\n";
    }
  if (tamano>0)
    {

      if (posicion==1 && tamano==1)
	{
	  delete cabeza;
	  tamano=0;
	}
      
      if (posicion==1 && tamano>1)
	{
	  temp=cabeza->returnsiguiente();
	  delete cabeza;
	  temp->dameanterior(NULL);
	  cabeza=temp;
	  tamano--;
	}

      if ((posicion==tamano) && (tamano > 1))
	{      
	  temp=cola;
	  temp=temp->returnanterior();
	  delete cola;
	  temp->damesiguiente(NULL);
	  cola=temp;
	  tamano--;
	}      
      
      if ((posicion>1) && (posicion < tamano))
	{
	  for (int i=1;i<posicion;i++)
	    {
	      temp = temp->returnsiguiente();
	    }
	  anterior = temp->returnanterior();
	  siguiente = temp->returnsiguiente();
	  anterior->damesiguiente(siguiente);
	  siguiente->dameanterior(anterior);
	  delete temp;
	  tamano--;
	}
      //      if (posicion>tamano)
      //	{
      //	  cout << "Beyond last element";
      //	}
      //      cout << "tamaño" << size << "\n";
    }
}

string lista::devolverstring()
{
  nodo * temp;
  temp=cabeza;
  int mitama,i;
  string pepe; 

  for (i=0;i<tamano;i++)
    {
       pepe=pepe + temp->dimevalorchar();
       temp = temp->returnsiguiente();
    }

  mitama=pepe.size();

  return pepe;
}
void lista::mostrardatos(){
  nodo * temp;
  temp=cabeza;
  int i;
    for (i=0;i<tamano;i++)
    {
      temp->info();
      temp = temp->returnsiguiente();
    }
  cout << numelem() << "\n";
}

void lista::insertardatos(string cadena)
{
  int tama,i;
  tama=cadena.size();
  for (i=0;i<tama;i++)
   {
     insertardatos(cadena[i]);
   }
}

void lista::insertdata(int pepe)
{
  insertardatos(pepe);
}
void lista::insertdata(int valor,int posicion)
{
  insertardatos(valor,posicion);
}

void lista::operator << (int pepe)
{
  insertardatos(pepe);
}


void lista::insertdata(char pepe)
{
  insertardatos(pepe);
}

void lista::operator << (char pepe)
{
  insertardatos(pepe);
}

void lista::insertdata(unidaddato pepe)
{
  insertardatos(pepe);
}

void lista::operator << (unidaddato pepe)
{
  insertardatos(pepe);
}
void lista::insertinvdata(int pepe)
{
  insertardatosprincipio(pepe);
}

void lista::operator >> (int pepe)
{
  insertardatosprincipio(pepe);
}

void lista::insertinvdata(char pepe)
{
  insertardatosprincipio(pepe);
}

void lista::operator >> (char pepe)
{
  insertardatosprincipio(pepe);
}

void lista::insertinvdata(unidaddato pepe)
{
  insertardatosprincipio(pepe);
}

void lista::operator >> (unidaddato pepe)
{
  insertardatosprincipio(pepe);
}

template <class TIPO>
void lista::insertardatos(TIPO valo) //plantillar y tal
{
  if (tamano>1)
    {
      nodo * temp;
      temp = new nodo;
      temp->metervalor(valo);
      cola->damesiguiente(temp);
      temp->dameanterior(cola);
      cola=temp;      
      tamano++;
    }
  if (tamano==1)
    {
      cola=new nodo;
      cola->metervalor(valo);
      cola->dameanterior(cabeza);
      cabeza->damesiguiente(cola);
      tamano++;
    }
  if (tamano==0)
    {
      cabeza=new nodo;
      cabeza->metervalor(valo);
      tamano++;
    }
}

template <class TIPO>
void lista::insertardatos(TIPO valo,int posicion) 
{
  if ((tamano>1) && (posicion<tamano))
    {
      int i;
      nodo * temp;
      nodo * temppos;
      nodo * tempant;
      temppos=cabeza;
      for (i=0;i<posicion && i<tamano;i++)//check tamano
	{
	  temppos=temppos->returnsiguiente();
	}
      temp = new nodo;
      tempant=temppos->returnanterior();
      temp->metervalor(valo);
      temp->damesiguiente(temppos);
      temppos->dameanterior(temp);
      temp->dameanterior(tempant);
      tempant->damesiguiente(temp);
      tamano++;
    }

  if ((tamano>1) && (posicion>=tamano))
    {
      nodo * temp;
      temp = new nodo;
      cola->damesiguiente(temp);
      temp->dameanterior(cola);
      cola=temp;
    }

  if (tamano==1 && posicion>1)
    {
      cola=new nodo;
      cola->metervalor(valo);
      cola->dameanterior(cabeza);
      cabeza->damesiguiente(cola);
      tamano++;
    }
  if (tamano==1 && posicion==1)
    {
      nodo * temp;
      temp = cabeza;
      cola = temp;
      cabeza= new nodo;
      cabeza->metervalor(valo);
      cola->dameanterior(cabeza);
      cabeza->damesiguiente(cola);
      tamano++;
    }
  if (tamano==0)
    {
      cabeza=new nodo;
      cabeza->metervalor(valo);
      tamano=1;
    }
}

template <class TIPO>
void lista::insertardatosprincipio(TIPO pepe) //plantillar y tal
{
  nodo * temp;
  if (tamano>1)
    {
      temp = new nodo;
      temp->metervalor(pepe);
      cabeza->dameanterior(temp);
      temp->damesiguiente(cabeza);
      cabeza=temp;      
      tamano++; 
    }
  if (tamano==1)
    {
      temp=cabeza;
      cabeza=new nodo;
      cabeza->metervalor(pepe);
      cola=temp;
      cola->dameanterior(cabeza);
      cabeza->damesiguiente(cola);
      tamano++;
    }
  if (tamano==0)
    {
      cabeza=new nodo;
      cabeza->metervalor(pepe);
      tamano++;
    }
}

int lista::numelem()
{
  return tamano;
}

nodo * nodo::returnsiguiente()
{
      return siguientenodo;
}

nodo * nodo::returnanterior()
{
  return anterior;
}

void nodo::info()
{
  cout << "nodoanterior: " << anterior << " estenodo:" << this << " Valor: " << dimevalorchar();
  cout << " Siguiente: " << returnsiguiente();
  cout << "\n";
}

char nodo::dimevalorchar()
{
  espacio_dato pepe;
  pepe=contenido.regresavalor();
  return pepe.c;
}

espacio_dato  nodo::dimevalor()
{
  espacio_dato pepe;
  pepe=contenido.regresavalor();
  return pepe;
}

unidaddato nodo::volcardato()
{
  return contenido;
}


template <class TIPO>
void nodo::metervalor(TIPO valo)
{
  contenido.ingresadato(valo); //llamando a la funcion metervalor de DATO
}

void nodo::metervalor(unidaddato pepe)
{
  contenido=pepe;
}

void nodo::dameanterior(nodo *pepe)
{
  anterior=pepe;
}

void nodo::damesiguiente(nodo *pepe)
{
  siguientenodo=pepe;
} 




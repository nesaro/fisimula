#ifndef __DATOSCALC_H
#define __DATOSCALC_H

#include "calcnode.hpp"
using namespace std; 

class nodo
{
public:
  void info();//muestra la informacion del nodo en la pantalla
  nodo * returnsiguiente();
  nodo * returnanterior();
  void dameanterior(nodo*); //guarda la direccion del nodo anterior
  void damesiguiente(nodo*); //guarda la dirección del siguiente
  char dimevalorchar();
  espacio_dato dimevalor();
  template <class TIPO>
  void metervalor(TIPO pepe);
  void metervalor(unidaddato);
  unidaddato volcardato();
private:
  nodo *siguientenodo;
  nodo *anterior;
  unidaddato contenido; // contenido es de tipo unidaddato
};

class lista
{
public:
  lista(); //constructor
  ~lista(); //destroyer :P
  int numelem();
  void operator << (unidaddato);
  void insertdata(unidaddato);
  void operator << (int);
  void insertdata(int);
  void insertdata(int,int); //ejemplizar
  void operator << (char);
  void insertdata(char);
  void operator >> (unidaddato);
  void insertinvdata(unidaddato);
  void operator >> (char);
  void insertinvdata(char);
  void operator >> (int);
  void insertinvdata(int);
  unidaddato dumpdata(int); //dumps element's data (int=position)
  void mostrardatos();
  void borrardato(int);
  string devolverstring ();
private:
  template < class TIPO >
  void insertardatos (TIPO);
  template < class TIPO >
  void insertardatos(TIPO,int) ;
  template < class TIPO >
  void insertardatosprincipio(TIPO);
  void insertardatos (string);
  nodo * cabeza; //La lista solo sabe cual es el primer elemento
  nodo * cola; // y el ultimo
  int tamano; // size var
};

#endif

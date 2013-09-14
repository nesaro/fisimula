#ifndef __CALCNODE_H
#define __CALCNODE_H
union espacio_dato {
  char c;
  int i;
  float f;
};
class unidaddato {
public:
  int ingresadato(int dato);
  int ingresadato(char dato);
  int ingresadato(float dato);
  void ingresadato(espacio_dato);
  espacio_dato regresavalor(); // optimizar por sobrecarga, int regresavalor(1), char regresavalor(2)...
  int dimetipo();
private:
  espacio_dato datoensi;
  int tipo_dato;
};
#endif

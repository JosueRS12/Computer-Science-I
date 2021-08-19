#include <iostream>
#include <cstdlib>
#include "lista.h"

using namespace std;

int main(){
  Lista <int> listaEnteros;

  listaEnteros.insertarInicio(2);
  listaEnteros.insertarInicio(3);
  listaEnteros.insertarInicio(4);
 // 0 1 2 
  //listaEnteros.obtenerDato(2);
  return 0;
}

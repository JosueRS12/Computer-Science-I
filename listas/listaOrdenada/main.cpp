#include <iostream>
#include <cstdlib>
#include "ListaOrdenada.h"

using namespace std;

int main(){
  ListaOrdenada <int, string> listaEnteros;
  listaEnteros.insertarNodo(3,"");
  listaEnteros.insertarNodo(2,"");
  listaEnteros.insertarNodo(1,"");
  listaEnteros.insertarNodo(6,"");
  listaEnteros.insertarNodo(8,"");
  listaEnteros.insertarNodo(3,"");
  listaEnteros.insertarNodo(3,"");
  

  for(int i = 0; i<listaEnteros.tamLista(); i++ ){
    cout<<listaEnteros.obtenerDato(i)<<endl;
  }
  cout<<"\n\n";
  //listaEnteros.eliminar(3);
  listaEnteros.eliminar(1);
  listaEnteros.eliminar(12);
  for(int i = 0; i<listaEnteros.tamLista(); i++ ){
    cout<<listaEnteros.obtenerDato(i)<<endl;
  } 
  cout<<"\n\n";
  listaEnteros.modificar(3, "hola");
  
  listaEnteros.buscarInfo(3);



  return 0;
}

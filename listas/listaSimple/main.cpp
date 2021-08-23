#include <iostream>
#include <cstdlib>
#include "Lista.h"

using namespace std;

int main(){
  Lista <int> listaEnteros;
  listaEnteros.insertarInicio(2);
  //cout<<listaEnteros.tamLista()<<endl;
  //cout<<listaEnteros.obtenerDato(0)<<endl;

  listaEnteros.insertarInicio(3);
  //cout<<listaEnteros.tamLista()<<endl;
  //cout<<listaEnteros.obtenerDato(0)<<endl;

  listaEnteros.insertarInicio(4);
  //cout<<listaEnteros.tamLista()<<endl;
  //cout<<listaEnteros.obtenerDato(0)<<endl;

    
  //antes de eliminar
  cout<<"original"<<endl; 
  for(int i = 0; i<listaEnteros.tamLista(); i++ ){
    cout<<listaEnteros.obtenerDato(i)<<endl;
  }
  cout<<"size "<<listaEnteros.tamLista()<<endl;
  listaEnteros.eliminar(2);
  //listaEnteros.eliminar(0);

  //despues de eliminar 
  cout<<"despues de eliminar"<<endl; 
  for(int i = 0; i<listaEnteros.tamLista(); i++ ){
    cout<<listaEnteros.obtenerDato(i)<<endl;
  }
  cout<<"size "<<listaEnteros.tamLista()<<endl;

  return 0;
}

//plantilla de una estructura tipo t y apuntador al siguiente
//crear clase lista dentro de la misma libreria {
  //se necesita el apuntador a la cabeza de tipo nodo (struct)
  //en el constructor la cabeza es null
  //crear metodo insertar con parametros:
      //- con data y posicion (si es mayor que el tamaño va al final) //hay
        //corrimientos.
      //- con data (va para el primero)
  //crear metodo borrar:
      //- parametro posición
  //buscar:
      //- retornar la info de la posicion
  //modificar tambien.
//}


//notation
//ptr->feet is same as (*ptr).feet
//ptr->inch is same as (*ptr).inc
#ifndef LISTA_H
#define LISTA_H

#include <cstdlib>
#include <iostream>
using namespace std;


template <class T>
struct Nodo{
  T info;
  Nodo<T>  *sig;
};
  //tam
  //info
template <class T>
class Lista{
  //atributos
  int tam;
  Nodo<T> *head; 
  //constructor
  public:
  Lista(){
    head = NULL;
    tam = 0;
  }
  //metodos
  bool listaVacia(); //
  int tamLista(); //
  T obtenerDato(int pos); // 
  bool eliminar(int pos); // falta hacer delete
  void insertarInicio(T infoNueva); //
  T buscarLista(string ruta);
  void insertarPos(T infoNueva, int pos);
  bool modificar(T, int pos);
};

template <class T>
bool Lista<T> :: listaVacia(){
  if(tam == 0){
    return true;
  } 
  else {
    return false;
  }
}

template <class T>
int Lista<T> :: tamLista(){
  return tam; 
}

template <class T>
T Lista<T> :: obtenerDato(int pos){
  Nodo<T> *nodo = head;
  for(int i = 0; i<pos; i++){
    nodo = nodo -> sig; 
  }
  return nodo -> info; //
} 

template <class T>
bool Lista<T> :: eliminar(int pos){
  Nodo<T> *nodo = head;
  int i = 0;  
  if(pos==0){
    head = nodo -> sig;
    delete nodo;
    tam--;
    return true;
  }
  else if(pos<tam){
    while(i<(pos-1)){
      nodo = nodo -> sig; //anterior
      i++;
    }
    nodo -> sig = nodo -> sig -> sig;
    delete nodo -> sig;
    tam--;
    return true;
  }
  return false;
}

template <class T>
void Lista<T> :: insertarInicio(T infoNueva){
  Nodo<T> *nodo = new Nodo<T>; //funciona
  nodo -> info = infoNueva;
  nodo -> sig = head;
  head = nodo;
  tam++;
}

template <class T>
T Lista<T> :: buscarLista(string ruta){
//facultad carrera asig prof pos
  int pos, i = 0;
  bool res = false; 
  Nodo<T> *aux = head;


  while(aux != NULL && res == false){
    if(aux -> info.nombre == ruta){
      return aux -> info; //asab => facultad {nombre, direccion..., lista}
    }
      aux = aux -> sig;
  }
}


#endif

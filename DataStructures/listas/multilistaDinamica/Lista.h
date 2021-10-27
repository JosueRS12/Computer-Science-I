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
  //bool eliminar(int pos); // falta hacer delete
  bool eliminar(T dato); // falta hacer delete
  void insertarInicio(T infoNueva); //
  T buscarLista(string ruta);
  Nodo<T> *buscarListaApuntador(string ruta);
  void insertarPos(T infoNueva, int pos);
  bool modificar(T, int pos);
  T getTipoDato();
};


template <class T>
T Lista<T> :: getTipoDato(){
  return head -> info.tipoEstructura;
}

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
  int i = 0;
  //while(nodo!=NULL && i<pos){
    //nodo = nodo -> sig; 
    //i++;
  //}
  for(int i = 0; i<pos; i++){
    nodo = nodo -> sig; 
  }
  return nodo -> info; //
} 

template <class T>
bool Lista<T> :: eliminar(T dato){
  Nodo<T> *nodo = head, *aux = new Nodo<T>;
  int i = 0;  
  while(nodo!=NULL){
    if(nodo -> info.nombre == dato.nombre){
      aux -> sig = nodo -> sig;
      delete nodo;
      tam--;
      return true;
    }
    aux = nodo; //anterior
    nodo = nodo -> sig; //el que deseamos borrar
  }
  return false;
}

//template <class T>
//bool Lista<T> :: eliminar(int pos){
  //Nodo<T> *nodo = head;
  //int i = 0;  
  //if(pos==0){
    //head = nodo -> sig;
    //delete nodo;
    //tam--;
    //return true;
  //}
  //else if(pos<tam){
    //while(i<(pos-1)){
      //nodo = nodo -> sig; //anterior
      //i++;
    //}
    //nodo -> sig = nodo -> sig -> sig;
    //delete nodo -> sig;
    //tam--;
    //return true;
  //}
  //return false;
//}

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
  Nodo<T> *aux = head;
  while(aux != NULL){
    if(aux -> info.nombre == ruta){
      return aux -> info; //asab => facultad {nombre, direccion..., lista}
    }
      aux = aux -> sig;
  }
}

template <class T>
Nodo<T> *Lista<T> :: buscarListaApuntador(string ruta){
//facultad carrera asig prof pos
  Nodo<T> *aux = head;
  while(aux != NULL){
    if(aux -> info.nombre == ruta){
      return aux; //asab => facultad {nombre, direccion..., lista}
    }
      aux = aux -> sig;
  }
}
#endif

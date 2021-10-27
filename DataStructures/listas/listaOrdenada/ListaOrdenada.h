#ifndef LISTAORDENADA_H
#define LISTAORDENADA_H

#include <cstdlib>
#include <iostream>
using namespace std;


template <class T, class S>
struct Nodo{
  T key;
  S info;
  Nodo<T,S> *sig;
  Nodo<T,S> *ant;
};

template <class T, class S>
class ListaOrdenada{
  //atributos
  Nodo<T,S> *head, *z; 
  int tam;
  S *arrayInfo;
  //constructor
  public:
  ListaOrdenada(){
    arrayInfo = new S;
    head = new Nodo<T,S>;
    z = new Nodo<T,S>; // ultima posicion
    head -> sig = z;
    head -> ant = NULL;
    z -> sig = NULL;
    z -> ant = head;
    tam = 0;
  }
  //metodos
  bool listaVacia(); //
  int tamLista(); // 
  T obtenerDato(int pos);// key? 
  void buscarInfo(T clave);
  bool eliminar(T clave); // 
  void insertarNodo(T clave, S inf); // 
  bool pertenece(T clave); //
  bool modificar(T clave, S inf); //
  Nodo<T,S> *obtenerNodoSiguiente(T clave); //
};

template <class T, class S>
bool ListaOrdenada<T,S> :: listaVacia(){
  if(head -> sig == z)
    return true;
  else
    return false;
}

template <class T, class S>
int ListaOrdenada<T,S> :: tamLista(){
  return tam; 
}

template <class T, class S>
void ListaOrdenada<T,S> :: buscarInfo(T clave){
  Nodo<T,S> *aux = obtenerNodoSiguiente(clave); //sig 
  bool res = false;
  aux = aux -> ant; //ant
  while(aux -> key == clave){
    cout<<aux->info<<endl;
    aux = aux -> ant; // anterio a clave 
    res = true;
  }
}

template <class T, class S>
T ListaOrdenada<T,S> :: obtenerDato(int pos){
  Nodo<T,S> *nodo = head -> sig;
  for(int i = 0; i<pos; i++){
    nodo = nodo -> sig; 
  }
  return nodo -> key; //
} 

template <class T, class S>
bool ListaOrdenada<T,S> :: pertenece(T clave){
  Nodo<T,S> *p = obtenerNodoSiguiente(clave);//siguiente o ultimo; 
  bool res = false;
  (p -> ant -> key == clave) ? res = true : res;
  return res;
}


template <class T, class S>
void ListaOrdenada<T,S> :: insertarNodo(T clave, S inf){
  Nodo<T,S> *nodo = new Nodo<T,S>, *p = obtenerNodoSiguiente(clave);//siguiente o ultimo; 
  nodo -> key = clave; 
  nodo -> info = inf;
  nodo -> sig = p; 
  nodo -> ant = p -> ant;
  p -> ant -> sig = nodo;
  p -> ant = nodo; 
  tam ++; 
}

template <class T, class S>
Nodo<T,S> *ListaOrdenada<T,S> :: obtenerNodoSiguiente(T clave){
  Nodo<T,S> *nodo = new Nodo<T,S>, *p = head -> sig;  
  while(p != z){
    //comparar
    if(p -> key > clave)
      break; //- > se obtiene el mayor o se obtiene el ultimo (z)
    p = p -> sig; 
    
  }
  return p;
}

template <class T, class S>
bool ListaOrdenada<T,S> :: modificar(T clave, S inf){
  Nodo<T,S> *aux = obtenerNodoSiguiente(clave); 
  bool res = false;
  aux = aux -> ant;
  while(aux -> key == clave){
    aux -> info = inf;
    aux = aux -> ant; // anterio a clave 
    res = true;
  }
  return true;

}

template <class T, class S>
bool ListaOrdenada<T,S> :: eliminar(T clave){
  Nodo<T,S> *p = obtenerNodoSiguiente(clave), *aux = obtenerNodoSiguiente(clave); 
  bool res = false;
  aux = aux -> ant;
  while(aux -> key == clave){
    tam--;
    aux = aux -> ant; // anterio a clave 
    delete aux -> sig;
    res = true;
  }
  if (res){
    aux -> sig = p; 
    p -> ant = aux;
  }
  return res;
} 


#endif



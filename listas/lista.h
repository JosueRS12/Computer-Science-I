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
  const Nodo<T>  *sig;
};
  //tam
  //info
template <class T>
class Lista{
  //atributos
  Nodo<T> *head; 
  int tam;
  //constructor
  public:
  Lista(){
    head = NULL;
    tam = 0;
  }
  //metodos
  bool listaVacia(); //
  int tamLista(); //
  T obtenerDato(int pos); // comprobar
  bool eliminar(int pos); // comprobar
  void insertarInicio(T infoNueva);
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
  //Nodo<T> *p = head;
  //Nodo<T> *aux;
  ////for(int i = 0; i<pos-1; i++){
    //aux = p -> sig; 
  ////}
  //cout<<aux -> info<<endl;
  return NULL; //
} 

template <class T>
bool Lista<T> :: eliminar(int pos){
  int i=pos;
  while(i<tam){
    if(i == pos){
      head[pos] = NULL;
      *head[pos] = NULL;
    }
    else{
      --head[i];
    }
    i++;
  }
  return true;
}

template <class T>
void Lista<T> :: insertarInicio(T infoNueva){
  const Nodo<T> *aux = head; //funciona
  Nodo <T> nodo;
  nodo.info = infoNueva;
  nodo.sig = aux;
  head = &nodo;
  cout<<"head "<< head -> info ;
  cout<<" direccion head "<< head -> sig <<endl;
  if(aux!=NULL){
    cout<<"aux "<<aux -> info;
    cout<<"direccion aux "<< aux -> sig <<endl;
  }
  
  cout<<(*head).info<<endl;
   
  tam++;
}

#endif

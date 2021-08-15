#include <iostream>
#include <cstdlib>
using namespace std;

//Se crea una strutura de acuerdo a una plantilla
//template<class T>
//struct nodo {
  //T dato;
   //char x;
//};

template <class T, class S>
struct nodo {
  T clave;
  S descrip; 
  nodo<T,S> * sig;
};

//funciones con la estructura
template <class T, class S>       
void  Funcion1(T v, S d, nodo<T,S> *cab){
  nodo<T,S> *t = new nodo<T,S>; //Asi se declara un tipo de dato de la estructura nodo de acuerdo a una plantilla
};

int main(){
  nodo<int,char> *ini,*aux;
  ini = new nodo<int,char>; //se declara en el main
  return 0;
}





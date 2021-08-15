//definir una estructura, debe tener 2 datos genericos.
//funcion que suma dos estructuras
//en el main se declaran las dos estructuras y se llama la funcion


#include <iostream>
#include <cstdlib>
using namespace std;

template<class T, class S>
  struct nodo{
    T number; 
    S character; 
  }; 
template<class T, class S>
  nodo<T,S> sumar(nodo<T, S> a, nodo<T, S> b){
    nodo<T,S> res;
    res.number = a.number + b.number;
    res.character = a.character + b.character;
    return res;
  };
 
int main(){
  nodo<int,char> a, b;
  a.number = 2; 
  a.character = 'o';
  b.number = 4;
  b.character = 'a';
  nodo<int,char> result = sumar(a,b); 
  cout<<result.number<<endl; 
  cout<<result.character<<endl; 
}
  



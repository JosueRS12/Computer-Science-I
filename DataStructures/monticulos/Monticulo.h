#ifndef MONTICULO_H
#define MONTICULO_H

#include <cstdlib>
#include <iostream>
using namespace std;

class Monticulo{
  int *arr, tam, posAct;

  public:
  Monticulo(){
    tam = 12;
    arr = new int[tam];
    posAct = 1;
  }
  bool insertar(int clave); //
  int atender();
  void imprimirArreglo();
  bool monticulo_lleno(); //
};

bool Monticulo:: monticulo_lleno(){
  if (posAct == tam)   
    return true;
  else
    return false;
}

void Monticulo :: imprimirArreglo(){
  int i = 1;
  while(i <  posAct){
    cout<<arr[i]<<" ";
    i++;
  }
  cout<<"\n";
}
int Monticulo :: atender(){
  int  padre = 1, hijoIzq = padre*2, hijoDer= padre*2+1,ultimo = arr[posAct-1];
  posAct--;
  while((ultimo < arr[hijoIzq] || ultimo < arr[hijoDer])&&(hijoIzq<tam || hijoDer<tam)){
    if(arr[hijoIzq] > arr[hijoDer]){
      arr[padre] = arr[hijoIzq]; 
      padre = hijoIzq;
    }
    else{
      arr[padre] = arr[hijoDer]; 
      padre = hijoDer;
    }
    hijoIzq = padre*2;
    hijoDer = padre*2+1;
  } 

  arr[padre] = ultimo;


  return arr[1];
}

bool Monticulo :: insertar(int clave){
  int padre = posAct / 2, aux = posAct;
  
  //compara
  //se reemplaza
  //actualizar posactual y padre
  if (!monticulo_lleno()){
    while(clave > arr[padre] && padre!=0){ // 0 - 3 4 5 >>8    0 - null 3  5 4
      arr[aux] = arr[padre]; //reemplazando
      aux = padre;
      padre = padre / 2;
    }
    arr[aux] = clave;
    posAct++;
    return true;
  }
  else
    return false;
}



#endif

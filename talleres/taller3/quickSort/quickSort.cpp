#include <iostream>
#include <cstdlib>
#include <chrono>
#include <time.h>
#include <stdlib.h>
using namespace std;


void intercambio(int v[],int a, int b) {
    int temporal = v[a];
      v[a] = v[b];
      v[b] = temporal;
}


void ordenrapido(int a[], int izq, int der){ 
   int i, j; 
   int v;
    if(der> izq){
      v= a[der]; 
      i = izq -1; 
      j= der;
      for(;;){
        while (a[++i]<v);
        while (a[--j] >v);
        if(i>=j) break;
        intercambio(a,i,j);
      }
      intercambio(a, i, der);
      ordenrapido(a, izq, i-1);
      ordenrapido(a, i+1,der);
    }
}

int main(){
    int i, j;
    srand(time(NULL));
    for(i = 5; i<=100; i+=5){
      int a[i];
      for(j = 0; j < i; j++)
        a[j] = 1 + rand()%(100);       

      //cout<<" desordenado"<<endl;

      //for(int k = 0; k<i; k++)
        //cout<<a[k]<<" ";
      
      auto start = std::chrono::system_clock::now(); 
      ordenrapido(a,0,i-1); 
      auto end = std::chrono::system_clock::now();
      std::chrono::duration<float,std::milli> duration = end - start;    

      cout<<"para "<<i<<" elementos el tiempo transcurrido: "<<duration.count()<<" ms"<<endl;
      //cout<<duration.count()<<endl;
      //cout<<endl;
      //cout<<" ordenado"<<endl;
      //for(int k = 0; k<i; k++)
        //cout<<a[k]<<" ";
      //cout<<endl;
    }

  return 0;
}

#include <iostream>
#include <cstdlib>
#include <chrono>
#include <time.h>
#include <stdlib.h>

using namespace std;

inline unsigned bits (int num, int k, int j){
  return (num>>k)&~(~0<<j);
}

void intercambio(int v[],int a, int b) {
    int temporal = v[a];
      v[a] = v[b];
      v[b] = temporal;
}

void cambioresiduos(int a[], int izq, int der, int b){ 
    int i,j; 
    if (der>izq && b>0){
      i= izq; 
      j=der;
      while(j!=i){
        while(!bits(a[i],b,1) && i<j)i++;
        while(bits(a[j],b,1) && j>i )j--;
        intercambio(a, i, j);
      }
      if (!bits(a[i],b,1)) j++;
      cambioresiduos(a, izq, j-1, b-1);
      cambioresiduos(a, j, der, b-1);
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
      cambioresiduos(a,0,i-1,8); 
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

#include <iostream>
#include <cstdlib>
#include <chrono>
#include <vector>
using namespace std;
//using std::vector;
int *seleccion(int v[], int n){ 
  for (int i = 0; i < n - 1; ++i) {
         int min = i;
         for (int c = i + 1; c < n; ++c)
            if (v[min] > v[c]) min = c;                          
          int  aux = v[i];
          v[i] = v[min];
          v[min] = aux;
                                 
  }
  return v;
}


int main(){

  int i, k;

  for(i=5; i<=100; i+=5){
    int num[i];
    for(k=0; k<i; k++){
      num[k]=100-k;
      //cout<<num[k]<<" ";
    }
    auto start= std::chrono::system_clock::now(); 
    seleccion(num,i);
//test
/*      cout<<"despues de ordenarlo"<<endl;*/
      //for(k=0; k<i;k++)
        //cout<<arr[k]<<" ";
      //int h;
      //cin>>h;
      /*cout<<endl;*/
    
    auto end= std::chrono::system_clock::now();
    std::chrono::duration<float,std::milli> duration = end - start;    
    //cout<<"para "<<i<<"elementos el tiempo transcurrido: "<<duration.count()<<" ms"<<endl;
    cout<<duration.count()<<endl;
  }

  return 0;
}

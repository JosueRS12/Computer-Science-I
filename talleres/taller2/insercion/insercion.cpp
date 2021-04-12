#include <iostream>
#include <cstdlib>
#include <chrono>
#include <vector>
using namespace std;
//using std::vector;
int *insercion(int v[], int n){ 
  int i, j, temp, acum;
  for(i=0; i<n; i++){
    temp=v[i];
    j=i-1;
    while(j>=0 && v[j] >temp){
      v[j+1] = v[j];
      j--;
    }
    v[j+1] = temp;
  }
  return v;
}


int main(){

  int i, k, op;
  cout<<"1) peor caso. 2) mejor caso"<<endl;
  cin>>op;
  switch (op){
    case 1:
     for(i=5; i<=100; i+=5){
      int num[i];
      for(k=0; k<i; k++){
        num[k]=100-k;
        //cout<<num[k]<<" ";
      }
      auto start= std::chrono::system_clock::now(); 
      insercion(num,i);
      /*cout<<"despues de ordenarlo"<<endl;*/
      //for(k=0; k<i;k++)
        //cout<<arr[k]<<" ";
      //int h;
      //cin>>h;
      /*cout<<endl;*/
      auto end= std::chrono::system_clock::now();
      std::chrono::duration<float,std::milli> duration = end - start;    
      //cout<<"para "<<i<<"elementos el tiempo transcurrido: "<<duration.count()<<" ms"<<endl;
      cout<<duration.count()<<endl;
      //delete []num;
     }  
    break;
    case 2:
      for(i=5; i<=100; i+=5){
       int num[i];
       for(k=0; k<i; k++){ 
         num[k]=k;
         //cout<<num[k]<<" ";
       }
       auto start= std::chrono::system_clock::now(); 
       insercion(num,i);
/*       cout<<"despues de ordenarlo"<<endl;*/
       //for(k=0; k<i;k++)
        //cout<<arr[k]<<" ";
       //int h;
       //cin>>h;
       /*cout<<endl;*/
       auto end= std::chrono::system_clock::now();
       std::chrono::duration<float,std::milli> duration = end - start;    
       //cout<<"para "<<i<<"elementos el tiempo transcurrido: "<<duration.count()<<" ms"<<endl;
       cout<<duration.count()<<endl;
        //delete []num;
      }
       break;
    default:
      break;
  }
  return 0;
}

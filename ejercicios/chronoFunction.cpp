#include <iostream>
#include <chrono>

using namespace std;
int main(){

  auto start = std::chrono::system_clock::now();
  long int acum = 0, i;
  for(i=0; i<1000000; i++){
    acum+= i;
  }
  auto end = std::chrono::system_clock::now();
  
  std::chrono::duration<float, std::milli> duration = end - start;
  cout<<duration.count()<< " milisegundos"<<endl;
  
  return 0; 



}

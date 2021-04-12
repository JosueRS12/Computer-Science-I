#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(int argc, char** argv){

  clock_t t; 
  t = clock();
  long int acum=0, i; 
  for(i=0; i<1000000; i++){
   acum+= i; 
  }
  t = clock() - t;
  cout<<(float)t<<endl;
  system("PAUSE");
  return 0;  
}

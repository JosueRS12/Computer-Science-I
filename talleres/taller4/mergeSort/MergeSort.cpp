#include <iostream>
#include <cstdlib>
#include <chrono>
#include <time.h>
#include <stdlib.h>
using namespace std;

void MergeLists(int *list, int start1, int end1, int start2, int end2){
  //list the elements to be put into order
  //start1 beginning of "list" A
  //end1 end of "list" A
  //start2 beginning of "list" B
  //end2 end of "list" B
  // assumes that the elements of A and B are
  //contiguous in list
  int finalStart = start1;
  int finalEnd = end2;
  int indexC = 1;
  int result[end2];
  while(start1 <= end1 && start2 <= end2){
    if (list[start1] < list[start2]){
     result[indexC] = list[start1];
     start1 = start1 + 1;
    }
    else{
      result[indexC] = list[start2];
      start2 = start2 + 1;
    }
    indexC = indexC + 1;

  }
  // move the part of the list that is left over
  if (start1 <= end1){
    for (int i = start1; i<=end1;i++){//comprobar si es <=
     result[indexC] = list[i];
     indexC = indexC + 1;
    }
  }
  else{
    for (int i = start2; i<=end2; i++){ //comprobar si es <=
     result[indexC] = list[i];
     indexC = indexC + 1;
    } 
  }
  // now put the result back into the list
  indexC = 1;
    for(int i = finalStart; i<=finalEnd; i++){ //comprobar si es <=
      list[i] = result[indexC];
      indexC = indexC + 1;
    }    
}


void MergeSort(int *list, int first, int last ){
  //list the elements to be put into order
  //first the index of the first element in the part of list to
  //sort
  //last the index of the last element in the part of list to
  //sort
  int middle;
  if (first < last){
   middle = ( first + last ) / 2;
   MergeSort( list, first, middle );
   MergeSort( list, middle + 1, last );
   MergeLists( list, first, middle, middle + 1, last );
  }
};



int main(){
    int i, j;
    srand(time(NULL));
    for(i = 5; i<=100; i+=5){
      int a[i]; 
      for(j = 0; j < i; j++)
        a[j] = 1 + rand()%(100);       

      auto start = std::chrono::system_clock::now(); 
      MergeSort(a,0,i-1);
      auto end = std::chrono::system_clock::now();
      std::chrono::duration<float,std::milli> duration = end - start;    
      //cout<<duration.count()<<endl;
      
      //for(j = 0; j < i; j++)
        //cout<<a[j]<<" ";      

      //cout<<endl;

      cout<<"para "<<i<<" elementos el tiempo transcurrido: "<<duration.count()<<" ms"<<endl;
    }

  return 0;
}



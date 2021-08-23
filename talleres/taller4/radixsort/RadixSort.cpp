#include <iostream>
#include <cstdlib>
#include <chrono>
#include <time.h>
#include <stdlib.h>

using namespace std;

// Function to get the largest element from an array
int getMax(int array[], int n) {
  int max = array[0];
  for (int i = 1; i < n; i++)
    if (array[i] > max)
      max = array[i];
  return max;
}

// Using counting sort to sort the elements in the basis of significant places
void countingSort(int array[], int size, int place) {
  const int max = 10;
  int output[size];
  int count[max];

  for (int i = 0; i < max; ++i)
    count[i] = 0;

  // Calculate count of elements
  for (int i = 0; i < size; i++)
    count[(array[i] / place) % 10]++;

  // Calculate cumulative count
  for (int i = 1; i < max; i++)
    count[i] += count[i - 1];

  // Place the elements in sorted order
  for (int i = size - 1; i >= 0; i--) {
    output[count[(array[i] / place) % 10] - 1] = array[i];
    count[(array[i] / place) % 10]--;
  }

  for (int i = 0; i < size; i++)
    array[i] = output[i];
}

// Main function to implement radix sort
void radixsort(int array[], int size) {
  // Get maximum element
  int max = getMax(array, size);

  // Apply counting sort to sort elements based on place value.
  for (int place = 1; max / place > 0; place *= 10)
    countingSort(array, size, place);
}

// Print an array
void printArray(float array[]) {
  int i;
  for (i = 0; i < 20; i++){
  	cout << array[i] << endl;
  }
  cout << endl;
}

// Driver code
int main() {
    int i, j;
    srand(time(NULL));
    for(i = 5; i<=100; i+=5){
      int a[i]; 
      for(j = 0; j < i; j++)
        a[j] = 1 + rand()%(100);       

      auto start = std::chrono::system_clock::now(); 
      radixsort(a,i);
      auto end = std::chrono::system_clock::now();
      std::chrono::duration<float,std::milli> duration = end - start;    
      //cout<<duration.count()<<endl;
      
      //for(j = 0; j < i; j++)
        //cout<<a[j]<<" ";      

      //cout<<endl;

      cout<<"para "<<i<<" elementos el tiempo transcurrido: "<<duration.count()<<" ms"<<endl;
    }
}



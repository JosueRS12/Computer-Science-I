#include <iostream>
#include <cstdlib>
#include "Multilista.h"

using namespace std;

int main(){
  //para llenar las estructuras
  string nombres[] = {"alejandro", "carlos", "raul", "diego", "fausto", "gabriela", "josue", "diana"};
  string carreras[] = {"sistemas", "electronica", "electrica", "indusplay", "sistemas", "electronica", "electrica", "indusplay"}; 
  string hobby[] = {"danza", "basquet", "natacion", "beisbol", "danza", "basquet", "natacion", "beisbol"};
  int edad[] = {21, 20, 26, 24, 18, 19, 20, 21};
  //crear multilista
  Multilista universidad;  
  Estudiante listaEstudiantes[8]; 
  //se agregan los estudiantes a la multilista
  for(int i = 0; i<8; i++){
    listaEstudiantes[i].nombre = nombres[i];
    listaEstudiantes[i].carrera = carreras[i];
    listaEstudiantes[i].edad = edad[i];
    listaEstudiantes[i].hobby = hobby[i];

    universidad.insertarEstudiante(listaEstudiantes[i]);
  } 


  universidad.buscarListaNombre();
  universidad.buscarListaCarrera("sistemas");
  //universidad.buscarListaEdad();
  //universidad.buscarListaHobby("danza");
  
 
  return 0;
}

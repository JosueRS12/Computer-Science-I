#ifndef MULTILISTA_H
#define MULTILISTA_H

//insertarOrdenado
#include <iostream>
#include <cstdlib>
using namespace std;

struct Estudiante{
  string nombre;
  string carrera; 
  string hobby;
  int edad;
  Estudiante *sigNombre, *sigCarrera, *sigHobby, *sigEdad;
};

struct Cabecera{
  Estudiante *head;
  string tipo;
};

class Multilista{

  Estudiante *estudiantes; 
  Cabecera *cabeceras;
  int tam;

  public:
  Multilista(){
    tam = 0;
    estudiantes = new Estudiante[100];
    cabeceras = new Cabecera[100];
    cabeceras[0] = {NULL, "sistemas"};
    cabeceras[1] = {NULL, "electronica"};
    cabeceras[2] = {NULL, "electrica"};
    cabeceras[3] = {NULL, "indusplay"};
    cabeceras[4] = {NULL, "nombre"};
    cabeceras[5] = {NULL, "edad"};
    cabeceras[6] = {NULL, "danza"};
    cabeceras[7] = {NULL, "natacion"};
    cabeceras[8] = {NULL, "beisbol"};
    cabeceras[9] = {NULL, "basquet"};
  }  
  void insertarEstudiante(Estudiante es); // --> Asc 
  void insertarCarrera(Estudiante es);
  void insertarHobby(Estudiante es);
  void insertarNombre(Estudiante es);
  void insertarEdad(Estudiante es);
  bool eliminar();
  void buscarEstudiante(int pos);
  void buscarListaNombre();
  void buscarListaEdad();
  void buscarListaHobby(string tipo);
  void buscarListaCarrera(string tipo);
  bool vacio();
  bool lleno();
};

void Multilista::buscarEstudiante(int pos){
    cout<<pos<<" "<<estudiantes[pos].nombre<<" "<<estudiantes[pos].edad<<" "<< estudiantes[pos].carrera <<" "<< estudiantes[pos].hobby<<endl;
}
  
void Multilista::buscarListaNombre(){
  int i = 0;
  Estudiante *nodo = cabeceras[4].head;
  
  while(nodo -> sigNombre != NULL){
    cout<<i<<" "<<nodo -> nombre<<" "<<nodo -> edad<<" "<<nodo->carrera<<" "<< nodo -> hobby <<endl;
    i++;
    nodo = nodo -> sigNombre;
  }
}

void Multilista::buscarListaEdad(){
  int i = 0;
  Estudiante *nodo = cabeceras[5].head;
  
  while(nodo -> sigEdad != NULL){
    cout<<i<<" "<<nodo -> nombre<<" "<<nodo -> edad<<" "<<nodo->carrera<<" "<< nodo -> hobby <<endl;
    i++;
    nodo = nodo -> sigEdad;
  }
}

void Multilista::buscarListaCarrera(string tipo){
  int i = 0;
  while(cabeceras[i].tipo != tipo)
   i++;
  Estudiante *nodo = cabeceras[i].head;
  
  i=0;
  while(nodo -> sigCarrera != NULL){
    cout<<i<<" "<<nodo -> nombre<<" "<<nodo -> edad<<" "<<nodo->carrera<<" "<< nodo -> hobby <<endl;
    i++;
    nodo = nodo -> sigCarrera;
  }
}

void Multilista::buscarListaHobby(string tipo){
  int i = 0;
  while(cabeceras[i].tipo != tipo)
   i++;
  Estudiante *nodo = cabeceras[i].head;
  
  i=0;
  while(nodo -> sigHobby != NULL){
    cout<<i<<" "<<nodo -> nombre<<" "<<nodo -> edad<<" "<<nodo->carrera<<" "<< nodo -> hobby <<endl;
    i++;
    nodo = nodo -> sigHobby;
  }
}

void Multilista::insertarEstudiante(Estudiante es){
  insertarNombre(es);   
  insertarCarrera(es);
  insertarEdad(es);
  insertarHobby(es);
  estudiantes[tam] = es; //insertado el estudiante en la multilista
  tam++;
}

void Multilista::insertarCarrera(Estudiante es){
  int i = 0;
  while(cabeceras[i].tipo != es.carrera)
   i++;
  
	Estudiante *nuevoNodo = &es;
	nuevoNodo -> sigCarrera = NULL;
	Estudiante *aux = cabeceras[i].head;
	while(aux->sigCarrera != NULL){
		aux = aux -> sigCarrera;
	}
	aux -> sigCarrera = nuevoNodo;
}

void Multilista :: insertarNombre(Estudiante es){
  Estudiante *nodo = &es, *anterior;  
  Estudiante *p = cabeceras[4].head;  
  anterior = p;

  while(p != NULL){
    if(p -> nombre > es.nombre)
      break; //- > se obtiene el mayor o se obtiene el ultimo (z)
    anterior = p; 
    p = p -> sigNombre; 
  }

  nodo -> sigNombre = p; 
  anterior -> sigNombre = nodo;
}

void Multilista :: insertarEdad(Estudiante es){
  Estudiante *nodo = &es, *anterior;  
  Estudiante *p = cabeceras[5].head;  
  anterior = p;

  while(p != NULL){
    if(p -> edad < es.edad)
      break; //- > se obtiene el menor 
    anterior = p; 
    p = p -> sigEdad; //menor
  }

  nodo -> sigEdad = p; 
  anterior -> sigEdad = nodo;
}

void Multilista::insertarHobby(Estudiante es){
  int i = 0;
  while(cabeceras[i].tipo != es.hobby)
   i++;
  
  Estudiante *nodo = &es; //funciona
  nodo -> sigHobby = cabeceras[i].head;
  cabeceras[i].head = nodo;
}

bool Multilista::vacio(){
  if(tam == 0)
    return true;
  else
    return false;
}

bool Multilista::lleno(){
  if(tam == sizeof(estudiantes))
    return true;
  else
    return false;
}

#endif


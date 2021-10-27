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
  ~Multilista(){
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
  
  while(nodo != NULL){
    cout<<i<<" "<<nodo -> nombre<<" "<<nodo->carrera<<endl;
    i++;
    nodo = nodo -> sigNombre;
  }
}

void Multilista::buscarListaEdad(){
  int i = 0;
  Estudiante *nodo = cabeceras[5].head;
  
  while(nodo != NULL){
    cout<<i<<" "<<nodo -> nombre<<" "<<nodo->carrera<<endl;
    i++;
    nodo = nodo -> sigEdad;
  }
}

void Multilista::buscarListaCarrera(string tipo){
  int i = 0;
  
  while(cabeceras[i].tipo != tipo)
   i++;
  Estudiante *nodo = cabeceras[i].head;

  while(nodo != NULL){
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
    cout<<i<<" "<<nodo -> nombre<<" "<<nodo->carrera<<endl;
    i++;
    nodo = nodo -> sigHobby;
  }
}

void Multilista::insertarEstudiante(Estudiante es){
  insertarNombre(es);   
  insertarCarrera(es);
  //insertarEdad(es);
  //insertarHobby(es);
  estudiantes[tam] = es; //insertado el estudiante en la multilista
  tam++;
}

void Multilista::insertarCarrera(Estudiante es){
  int i = 0;
  Estudiante *nodo = new Estudiante, *anterior = new Estudiante;
  *nodo =es; 
  while(cabeceras[i].tipo != nodo ->carrera)
   i++;
  
	nodo -> sigCarrera = NULL;
	Estudiante *aux = cabeceras[i].head;
	while(aux != NULL){
    anterior = aux;
		aux = aux -> sigCarrera; //ultimo

	}
  nodo -> sigCarrera = NULL;

  if(cabeceras[i].head != NULL){
  	anterior -> sigCarrera = nodo;
  }else{
  	cabeceras[i].head = nodo;
  } 
}

void Multilista :: insertarNombre(Estudiante es){
  Estudiante *anterior, *nodo = new Estudiante;
  *nodo =es;   
  Estudiante *p = cabeceras[4].head;  
  anterior = cabeceras[4].head;

  while(p != NULL){ 
    if(p -> nombre > nodo ->nombre)
      break; //- > se obtiene el mayor o se obtiene el ultimo (z)
    anterior = p; 
    p = p -> sigNombre;
	 
  }
  nodo ->sigNombre = p;
  if(cabeceras[4].head != NULL){
  	anterior -> sigNombre = nodo;
  }else{
  	cabeceras[4].head = nodo;
  } 
}

void Multilista :: insertarEdad(Estudiante es){
  Estudiante *anterior, *nodo = new Estudiante, *p = new Estudiante;
  *nodo =es;   
  p = cabeceras[5].head;  
  anterior = cabeceras[5].head;

  while(p != NULL){ 
    cout<<"entra edad"<<endl;
    if(p -> edad <= nodo -> edad)
      break; //- > se obtiene el mayor o se obtiene el ultimo (z)
    anterior = p; 
    p = p -> sigEdad;
  }

  nodo ->sigEdad = p;
  if(cabeceras[5].head != NULL){
  	anterior -> sigEdad = nodo;
  }else{
  	cabeceras[5].head = nodo;
  } 
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

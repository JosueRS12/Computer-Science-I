#include <iostream>
#include <cstdlib>
#include <vector>
#include "Lista.h"
using namespace std;

vector<string> split(string str, char pattern) {
    
    int posInit = 0;
    int posFound = 0;
    string splitted;
    vector<string> results;
    
    while(posFound >= 0){
        posFound = str.find(pattern, posInit);
        splitted = str.substr(posInit, posFound - posInit);
        posInit = posFound + 1;
        results.push_back(splitted);
    }
    
    return results;
}

struct Posgrado{
  string nombre;
  string tematica;
  string universidad;
};

struct Profesor{
  string nombre;
  string id;
  string formacion;
  string universidad;
  Lista<Posgrado> lista;
};

struct Asignatura{
  string nombre;
  string semestre;
  Lista<Profesor> lista;
};

struct Carrera{
  string nombre;
  string ubicacion;
  string coordinador;
  Lista<Asignatura> lista;
};

struct Facultad{ //mayor de todas
  string nombre;  
  string decano;
  string ubicacion;
  string telefono;
  Lista<Carrera> lista;
};

//void ingresarPosgrado(Profesor profesor, Posgrado posgrado){
  //int auxPos; 
    //cout<<"\n ----------------------";
    //cout<<"\n Cantidad de Posgrados: ";
    //cin>> auxPos;
    //for(int m = 0; m < auxPos; m++){
      //cout<<"\n Nombre Posgrado: ";
      //cin>>posgrado.nombre;
      //cout<<"\n tematica: ";
      //cin>>posgrado.tematica;
      //cout<<"\n universidad: ";
      //cin>>posgrado.universidad;
      //profesor.lista.insertarInicio(posgrado); //se inserta el posgrado en la lista interna de profesor
      //cout<<"\n ----------------------";
    //}
//};

//void ingresarProfesor(Asignatura asignatura, Profesor profesor, Posgrado posgrado){
  //int auxProf; 
  //cout<<"\n ----------------------";
  //cout<<"\n Cantidad de Profesores: ";
  //cin>> auxProf;
  //for(int l = 0; l < auxProf; l++){
    //cout<<"\n Nombre Profesor: ";
    //cin>>profesor.nombre;
    //cout<<"\n id Profesor: ";
    //cin>>profesor.id;
    //cout<<"\n Formacion Profesor: ";
    //cin>>profesor.formacion;
    //cout<<"\n Universidad de la que se graduo el profesor: ";
    //cin>>profesor.universidad;
    //ingresarPosgrado(profesor, posgrado);
    //asignatura.lista.insertarInicio(profesor); //se inserta el profesor en la lista interna de asignatura
    //cout<<"\n ----------------------";
  //}
//};

//void ingresarAsignatura(Carrera carrera, Asignatura asignatura, Profesor profesor, Posgrado posgrado){
  //int auxAsig; 
      //cout<<"\n ----------------------";
      //cout<<"\n Cantidad de Asignaturas: ";
      //cin>> auxAsig;
      //for(int k = 0; k < auxAsig; k++){
        //cout<<"\n Nombre Asignatura: ";
        //cin>>asignatura.nombre;
        //cout<<"\n Semestre: ";
        //cin>>asignatura.semestre;
        //ingresarProfesor(asignatura, profesor, posgrado);
        //carrera.lista.insertarInicio(asignatura); //se inserta la asignatura en la lista interna de la carrera
        //cout<<"\n ----------------------";
      //}
//};

//void ingresarCarrera(Facultad facultad, Carrera carrera, Asignatura asignatura, Profesor profesor, Posgrado posgrado){
  //int auxCar; 
    //cout<<"\n ----------------------";
    //cout<<"\n Cantidad de Carreras: ";
    //cin>>auxCar;
    //for(int j = 0; j < auxCar; j++){
      //cout<<"\n Nombre Carrera: ";
      //cin>>carrera.nombre;
      //cout<<"\n Nombre Coordinador: ";
      //cin>>carrera.coordinador;
      //cout<<"\n Ubicacion: ";
      //cin>>carrera.ubicacion;
      //ingresarAsignatura(carrera, asignatura, profesor, posgrado);
      //facultad.lista.insertarInicio(carrera); //se inserta la carrera en la lista interna de la facultad
      //cout<<"\n ----------------------";
    //}
//};

//void ingresarFacultad(Lista<Facultad> listaFacultad ,Facultad facultad, Carrera carrera, Asignatura asignatura, Profesor profesor, Posgrado posgrado){
  //int auxFac;
    //cout<<"\n Cantidad de Facultades";
    //cin>> auxFac;
    //for(int i = 0; i < auxFac; i++){
      //cout<<"\n Nombre Facultad: ";
      //cin>>facultad.nombre;
      //cout<<"\n Nombre Decano: ";
      //cin>>facultad.decano;
      //cout<<"\n ubicacion: ";
      //cin>>facultad.ubicacion;
      //cout<<"\n Telefono: ";
      //cin>>facultad.telefono;
      //ingresarCarrera(facultad, carrera, asignatura, profesor, posgrado); 
      //listaFacultad.insertarInicio(facultad);
      //cout<<"\n ----------------------";
    //}
//};

//como parametros (ruta, estructura, tamaño del vector, la estructura a devolver
//vacia) => se puede hacer un polmorfismo de funcion
//template <class S, class T>
//Nodo<S> *obtainPointer(vector<string> vec, int size, int index, Lista<T> list, Nodo<S> *response){
  //if(response -> info.nombre == vec[size-1])
    //return response;
  //try{
    //if(response -> info.tipoEstructura != "posgrado")
      //return obtainPointer(vec, size, index++, list, response -> info.lista.buscarListaApuntador(vec[index])); //se esta retornando un nodo en list 
    //else
      //throw(response -> info.tipoEstructura);
  //}
  //catch(Nodo<S> res){
    //cout<<"posgrado no tiene lista"<<endl;
  //}
  
//} 

//template <class T>
//Nodo<T> *obtainPointer(vector<string> vec, int size, int index, Lista<T> list){
  //if(list.buscarListaApuntador(vec[0]) -> info.nombre == vec[size-1])
    //return list.buscarListaApuntador(vec[0]);
  //else{
    //return obtainPointer(vec, size, index++, list, list.buscarListaApuntador(vec[index++])); //se esta retornando un nodo en list 
  //}
//}


//template <class T>
//Nodo<T> obtenerApuntador(string ruta, Lista<T> list){
  //vector<string> vec = split(ruta,'-');
  //int tam = vec.size();

  //switch (tam){
    //case 1:
      //{
        //return list.buscarListaApuntador(vec[0]); //facultad
      //}
      //break;
    //case 2:
      //{
        //return list.buscarListaApuntador(vec[0]) -> info.lista.buscarListaApuntador(vec[1]); //carrera
      //}
      //break;
    //case 3:
      //{
        //return list.buscarListaApuntador(vec[0]) -> info.lista.buscarListaApuntador(vec[1]) -> info.lista.buscarListaApuntador(vec[2]); //asignatura
      //}
      //break;
    //case 4:
      //{
        //return list.buscarListaApuntador(vec[0]) -> info.lista.buscarListaApuntador(vec[1]) -> info.lista.buscarListaApuntador(vec[2]) -> info.lista.buscarListaApuntador(vec[3]); //profesor
      //}
      //break;
    //case 5:
      //{
        //return list.buscarListaApuntador(vec[0]) -> info.lista.buscarListaApuntador(vec[1]) -> info.lista.buscarListaApuntador(vec[2]) -> info.lista.buscarListaApuntador(vec[3]) -> info.lista.buscarListaApuntador(vec[4]);//profesor
      //}
      //break;
    //default:
      //return NULL;
      //break;
  //}
  
}

//cout<<listaFacultad.buscarListaApuntador("asab") -> info.lista.buscarListaApuntador("danzas") -> info.nombre<<endl;

int main(){
  //Se inicializan las estructuras y la multilista
  Posgrado posgrado;
  Profesor profesor;
  Asignatura asignatura;
  Carrera carrera;
  Facultad facultad;
  Lista<Facultad> listaFacultad;
  int auxFac, auxCar, auxAsig, auxProf, auxPos; 
  int op = 0;
 
  //do{
    //cout<<"Bienvenido a la Gloriosa Universidad Distrital"<<endl;
    //cout<<"1) Ingresar datos iniciales"<<endl; //
    //cout<<"2) Modificar elementos de la lista"<<endl; //
    //cout<<"3) Borrar elementos de las listas "<<endl;
    //cout<<"4) Agregar nuevo elemento"<<endl; 
    //cout<<"5) Mostrar lista"<<endl; //
    //cout<<"6) Salir"<<endl;
    //cin>>op;
    
    //switch (op){
      //case 1:{
          cout<<"Cantidad de Facultades: ";
          cin>> auxFac;
          for(int i = 0; i < auxFac; i++){
            cout<<"\n Nombre Facultad: ";
            cin>>facultad.nombre;
            cout<<"\n Nombre Decano: ";
            cin>>facultad.decano;
            cout<<"\n ubicacion: ";
            cin>>facultad.ubicacion;
            cout<<"\n Telefono: ";
            cin>>facultad.telefono;
            cout<<"\n ----------------------";
            cout<<"\n Cantidad de Carreras: ";
            cin>>auxCar;
            for(int j = 0; j < auxCar; j++){
              cout<<"\n Nombre Carrera: ";
              cin>>carrera.nombre;
              cout<<"\n Nombre Coordinador: ";
              cin>>carrera.coordinador;
              cout<<"\n Ubicacion: ";
              cin>>carrera.ubicacion;
              cout<<"\n ----------------------";
              cout<<"\n Cantidad de Asignaturas: ";
              cin>> auxAsig;
              for(int k = 0; k < auxAsig; k++){
                cout<<"\n Nombre Asignatura: ";
                cin>>asignatura.nombre;
                cout<<"\n Semestre: ";
                cin>>asignatura.semestre;
                cout<<"\n ----------------------";
                cout<<"\n Cantidad de Profesores: ";
                cin>> auxProf;
                for(int l = 0; l < auxProf; l++){
                  cout<<"\n Nombre Profesor: ";
                  cin>>profesor.nombre;
                  cout<<"\n id Profesor: ";
                  cin>>profesor.id;
                  cout<<"\n Formacion Profesor: ";
                  cin>>profesor.formacion;
                  cout<<"\n Universidad de la que se graduo el profesor: ";
                  cin>>profesor.universidad;
                  cout<<"\n ----------------------";
                  cout<<"\n Cantidad de Posgrados: ";
                  cin>> auxPos;
                  for(int m = 0; m < auxPos; m++){
                    cout<<"\n Nombre Posgrado: ";
                    cin>>posgrado.nombre;
                    cout<<"\n tematica: ";
                    cin>>posgrado.tematica;
                    cout<<"\n universidad: ";
                    cin>>posgrado.universidad;
                    profesor.lista.insertarInicio(posgrado); //se inserta el posgrado en la lista interna de profesor
                  }
                  asignatura.lista.insertarInicio(profesor); //se inserta el profesor en la lista interna de asignatura
                }
                carrera.lista.insertarInicio(asignatura); //se inserta la asignatura en la lista interna de la carrera
              }
              facultad.lista.insertarInicio(carrera); //se inserta la carrera en la lista interna de la facultad
            }
            listaFacultad.insertarInicio(facultad);
            
            obtenerApuntador("asab-danzas", listaFacultad);
            //cout<<listaFacultad.buscarListaApuntador("asab") -> info.lista.buscarListaApuntador("danzas") -> info.nombre<<endl;
          }
        //}
        //break;
      //case 2:{
              //int op2 = 0;
              //string ruta2;
              //vector<string> res2; 
              //cout<<"¿Qué lista desea modificar"<<endl;
              //cout<<"1) Facultad"<<endl;
              //cout<<"2) Carrera"<<endl;
              //cout<<"3) Asignatura"<<endl;
              //cout<<"4) Profesor"<<endl;
              //cout<<"5) Posgrado"<<endl;
              //cin>>op2;
              
              //switch (op2){
                //case 1:{
                        //cout<<" Para ingresar la ruta del archivo hacerlo de la siguiente forma:"<<endl;
                        //cout<<"ejemplo: ingenieria"<<endl;
                        //cin>>ruta2;
                        //Nodo<Facultad> *fac = listaFacultad.buscarListaApuntador(ruta2);  
                        //int op3;
                        //cout<<"¿Que datos desea modificar?"<<endl;
                        //cout<<"1) Nombre Facultad"<<endl;
                        //cout<<"2) Nombre decano"<<endl;
                        //cout<<"3) Ubicacion"<<endl;
                        //cout<<"4) Telefono"<<endl;
                        //cin>>op3;
                        //cout<<"\n";
                        //switch (op3){
                          //case 1: cin >> fac -> info.nombre;
                            //break;
                          //case 2: cin >> fac -> info.decano;
                            //break;
                          //case 3: cin >> fac -> info.ubicacion;
                            //break;
                          //case 4: cin >> fac  -> info.telefono;
                            //break;
                          //default: cout<<"llorelo"<<endl;
                            //break;
                        //}
                       //}
                  //break;
                //case 2:{
                        //cout<<" Para ingresar la ruta del archivo hacerlo de la siguiente forma:"<<endl;
                        //cout<<"ejemplo: ingenieria-sistemas"<<endl;
                        //cin>>ruta2;
                        //res2 = split(ruta2,'-'); 
                        //Nodo<Facultad> *fac = listaFacultad.buscarListaApuntador(res2[0]);  
                        //Nodo<Carrera> *car = fac -> info.lista.buscarListaApuntador(res2[1]);  
                        //int op3;
                        //cout<<"¿Que datos desea modificar?"<<endl;
                        //cout<<"1) Nombre Carrera"<<endl;
                        //cout<<"2) Nombre Coordinador"<<endl;
                        //cout<<"3) Ubicacion"<<endl;
                        //cin>>op3;
                        //cout<<"\n";
                        //switch (op3){
                          //case 1: cin >> car -> info.nombre;
                            //break;
                          //case 2: cin >> car -> info.coordinador;
                            //break;
                          //case 3: cin >> car -> info.ubicacion;
                            //break;
                          //default: cout<<"llorelo"<<endl;
                            //break;
                        //}
                       //}
                  //break;
                //case 3:{
                        //cout<<" Para ingresar la ruta del archivo hacerlo de la siguiente forma:"<<endl;
                        //cout<<"ejemplo: distrital-sistemas-calculo"<<endl;
                        //cin>>ruta2;
                        //res2 = split(ruta2,'-'); 
                        //Nodo<Facultad> *fac = listaFacultad.buscarListaApuntador( res2[0] );  
                        //Nodo<Carrera> *car = fac -> info.lista.buscarListaApuntador(res2[1]);  
                        //Nodo<Asignatura> *as = car -> info.lista.buscarListaApuntador(res2[2]);  
                        //int op3;
                        //cout<<"¿Que datos desea modificar?"<<endl;
                        //cout<<"1) Nombre Asignatura"<<endl;
                        //cout<<"2) semestre"<<endl;
                        //cin>>op3;
                        //cout<<"\n";
                        //switch (op3){
                          //case 1: cin >> as -> info.nombre;
                            //break;
                          //case 2: cin >> as -> info.semestre;
                            //break;
                          //default: cout<<"llorelo"<<endl;
                            //break;
                        //}
                       //}
                  //break;
                //case 4:{
                        //cout<<" Para ingresar la ruta del archivo hacerlo de la siguiente forma:"<<endl;
                        //cout<<"ejemplo: distrital-sistemas-calculo-tole"<<endl;
                        //cin>>ruta2;
                        //res2 = split(ruta2,'-'); 
                        //Nodo<Facultad> *fac = listaFacultad.buscarListaApuntador( res2[0] );  
                        //Nodo<Carrera> *car = fac -> info.lista.buscarListaApuntador(res2[1]);  
                        //Nodo<Asignatura> *as = car -> info.lista.buscarListaApuntador(res2[2]);  
                        //Nodo<Profesor> *prof = as -> info.lista.buscarListaApuntador(res2[3]);  
                        //int op3;
                        //cout<<"¿Que datos desea modificar?"<<endl;
                        //cout<<"1) Nombre profesor"<<endl;
                        //cout<<"2) id"<<endl;
                        //cout<<"3) Formacion pregrado"<<endl;
                        //cout<<"4) Universidad de Pregrado"<<endl;
                        //cin>>op3;
                        //cout<<"\n";
                        //switch (op3){
                          //case 1: cin >> prof -> info.nombre;
                            //break;
                          //case 2: cin >> prof -> info.id;
                            //break;
                          //case 3: cin >> prof -> info.formacion;
                            //break;
                          //case 4: cin >> prof -> info.universidad;
                            //break;
                          //default: cout<<"llorelo"<<endl;
                            //break;
                        //}
                       //}
                  //break;
                //case 5:{
                        //cout<<" Para ingresar la ruta del archivo hacerlo de la siguiente forma:"<<endl;
                        //cout<<"ejemplo: distrital-sistemas-calculo-tole-matematicas"<<endl;
                        //cin>>ruta2;
                        //res2 = split(ruta2,'-'); 
                        //Nodo<Facultad> *fac = listaFacultad.buscarListaApuntador( res2[0] );  
                        //Nodo<Carrera> *car = fac -> info.lista.buscarListaApuntador(res2[1]);  
                        //Nodo<Asignatura> *as = car -> info.lista.buscarListaApuntador(res2[2]);  
                        //Nodo<Profesor> *prof = as -> info.lista.buscarListaApuntador(res2[3]);  
                        //Nodo<Posgrado> *pos = prof -> info.lista.buscarListaApuntador(res2[4]);  
                        //int op3;
                        //cout<<"¿Que datos desea modificar?"<<endl;
                        //cout<<"1) Nombre del posgrado"<<endl;
                        //cout<<"2) tematica"<<endl;
                        //cin>>op3;
                        //cout<<"\n";
                        //switch (op3){
                          //case 1: cin >> pos ->info.nombre;
                            //break;
                          //case 2: cin >> pos -> info.tematica;
                            //break;
                          //default: cout<<"llorelo"<<endl;
                            //break;
                        //}
                       //}
                  //break;
                //default: cout<<"sea serio"<<endl;
                  //break;
              //}
              
             //} 
        //break;
      //case 3:{
              //int op2 = 0;
              //string ruta2;
              //vector<string> res2; 
              //cout<<"¿Qué lista desea eliminar"<<endl;
              //cout<<"1) Facultad"<<endl;
              //cout<<"2) Carrera"<<endl;
              //cout<<"3) Asignatura"<<endl;
              //cout<<"4) Profesor"<<endl;
              //cout<<"5) Posgrado"<<endl;
              //cin>>op2;
              
              //switch (op2){
                //case 1:{
                        //cout<<" Para ingresar la ruta del archivo hacerlo de la siguiente forma:"<<endl;
                        //cout<<"ejemplo: ingenieria"<<endl;
                        //cin>>ruta2;
                        //Nodo<Facultad> *fac = listaFacultad.buscarListaApuntador(ruta2);  
                        //listaFacultad.eliminar(fac -> info); 
                        //cout<<"\n";
                       //}
                  //break;
                //case 2:{
                        //cout<<" Para ingresar la ruta del archivo hacerlo de la siguiente forma:"<<endl;
                        //cout<<"ejemplo: ingenieria-sistemas"<<endl;
                        //cin>>ruta2;
                        //res2 = split(ruta2,'-'); 
                        //Nodo<Facultad> *fac = listaFacultad.buscarListaApuntador(res2[0]);  
                        //Nodo<Carrera> *car = fac -> info.lista.buscarListaApuntador(res2[1]);  
                        //fac->info.lista.eliminar(car -> info); 
                       //}
                  //break;
                //case 3:{
                        //cout<<" Para ingresar la ruta del archivo hacerlo de la siguiente forma:"<<endl;
                        //cout<<"ejemplo: distrital-sistemas-calculo"<<endl;
                        //cin>>ruta2;
                        //res2 = split(ruta2,'-'); 
                        //Nodo<Facultad> *fac = listaFacultad.buscarListaApuntador( res2[0] );  
                        //Nodo<Carrera> *car = fac -> info.lista.buscarListaApuntador(res2[1]);  
                        //Nodo<Asignatura> *as = car -> info.lista.buscarListaApuntador(res2[2]);  
                        //car->info.lista.eliminar(as -> info); 
                       //}
                  //break;
                //case 4:{
                        //cout<<" Para ingresar la ruta del archivo hacerlo de la siguiente forma:"<<endl;
                        //cout<<"ejemplo: distrital-sistemas-calculo-tole"<<endl;
                        //cin>>ruta2;
                        //res2 = split(ruta2,'-'); 
                        //Nodo<Facultad> *fac = listaFacultad.buscarListaApuntador( res2[0] );  
                        //Nodo<Carrera> *car = fac -> info.lista.buscarListaApuntador(res2[1]);  
                        //Nodo<Asignatura> *as = car -> info.lista.buscarListaApuntador(res2[2]);  
                        //Nodo<Profesor> *prof = as -> info.lista.buscarListaApuntador(res2[3]);  
                        //as->info.lista.eliminar(prof -> info); 
                       //}
                  //break;
                //case 5:{
                        //cout<<" Para ingresar la ruta del archivo hacerlo de la siguiente forma:"<<endl;
                        //cout<<"ejemplo: distrital-sistemas-calculo-tole-matematicas"<<endl;
                        //cin>>ruta2;
                        //res2 = split(ruta2,'-'); 
                        //Nodo<Facultad> *fac = listaFacultad.buscarListaApuntador( res2[0] );  
                        //Nodo<Carrera> *car = fac -> info.lista.buscarListaApuntador(res2[1]);  
                        //Nodo<Asignatura> *as = car -> info.lista.buscarListaApuntador(res2[2]);  
                        //Nodo<Profesor> *prof = as -> info.lista.buscarListaApuntador(res2[3]);  
                        //Nodo<Posgrado> *pos = prof -> info.lista.buscarListaApuntador(res2[4]);  
                        //prof->info.lista.eliminar(pos -> info); 
                       //}
                  //break;
                //default: cout<<"sea serio"<<endl;
                  //break;
              //}
             //}
            //break; 
        //case 4:{
                //cout<<"por implementar :'( "<<endl;
                ////int op2 = 0;
                ////string ruta2;
                ////vector<string> res2; 
                ////cout<<"¿En que lista desea insertar"<<endl;
                ////cout<<"1) Facultad"<<endl;
                ////cout<<"2) Carrera"<<endl;
                ////cout<<"3) Asignatura"<<endl;
                ////cout<<"4) Profesor"<<endl;
                ////cout<<"5) Posgrado"<<endl;
                ////cin>>op2;
                ////switch (op2){
                  ////case 1: ingresarFacultad(listaFacultad, facultad, carrera, asignatura, profesor, posgrado);
                    ////break;
                  ////case 2:{
                          ////cout<<" Para ingresar la ruta del archivo hacerlo de la siguiente forma:"<<endl;
                          ////cout<<"ejemplo: ingenieria"<<endl;
                          ////cin>>ruta2;
                          ////res2 = split(ruta2,'-'); 
                          ////Facultad fac = listaFacultad.buscarLista(res2[0]);  
                          ////ingresarCarrera(fac, carrera, asignatura, profesor, posgrado); 
                         ////}
                    ////break;
                  ////case 3:{
                          ////cout<<" Para ingresar la ruta del archivo hacerlo de la siguiente forma:"<<endl;
                          ////cout<<"ejemplo: distrital-sistemas"<<endl;
                          ////cin>>ruta2;
                          ////res2 = split(ruta2,'-'); 
                          ////Facultad fac = listaFacultad.buscarLista(res2[0]);  
                          ////Carrera car = fac.lista.buscarLista(res2[1]);  
                          ////ingresarAsignatura(car, asignatura, profesor, posgrado);
                         ////}
                    ////break;
                  ////case 4:{
                          ////cout<<" Para ingresar la ruta del archivo hacerlo de la siguiente forma:"<<endl;
                          ////cout<<"ejemplo: distrital-sistemas-calculo"<<endl;
                          ////cin>>ruta2;
                          ////res2 = split(ruta2,'-'); 
                          ////Facultad fac = listaFacultad.buscarLista(res2[0]);  
                          ////Carrera car = fac.lista.buscarLista(res2[1]);  
                          ////Asignatura as = car.lista.buscarLista(res2[2]);  
                          ////ingresarProfesor(as, profesor, posgrado);
                         ////}
                    ////break;
                  ////case 5:{
                          ////cout<<" Para ingresar la ruta del archivo hacerlo de la siguiente forma:"<<endl;
                          ////cout<<"ejemplo: ingenieria-sistemas-calculo-tole"<<endl;
                          ////cin>>ruta2;
                          ////res2 = split(ruta2,'-'); 
                          ////Facultad fac = listaFacultad.buscarLista(res2[0]);  
                          ////Carrera car = fac.lista.buscarLista(res2[1]);  
                          ////Asignatura as = car.lista.buscarLista(res2[2]);  
                          ////Profesor prof = as.lista.buscarLista(res2[3]);  
                          ////ingresarPosgrado(prof, posgrado);
                         ////}
                    ////break;
                  ////default: cout<<"sea serio"<<endl;
                    ////break;
                ////}
              //}
          //break;
        //case 5:
               //{
                //string ruta;
                //cout<<"ingrese la ruta de la lista"<<endl;
                //cout<<"Para consultar lista de facultades. ruta = facultades"<<endl;
                //cout<<"ejemplo para ver los posgrados del profesor tole: ingenieria-sistemas-calculo-tole"<<endl;
                //cin>>ruta;
                //cout<<"----------------------------"<<endl;
                //vector<string> rutas = split(ruta,'-');
                //int tam;
                //if(ruta == "facultades")
                  //tam = 0;
                //else
                  //tam = rutas.size();
                //switch (tam+1){
                  //case 1:{
                           //cout<<listaFacultad.obtenerDato(0).nombre<<endl;                           
                           //for(int i = 0; i < listaFacultad.tamLista();i++){
                              //cout<<listaFacultad.obtenerDato(i).nombre<<endl;                           
                              //cout<<listaFacultad.obtenerDato(i).decano<<endl;                           
                              //cout<<listaFacultad.obtenerDato(i).ubicacion<<endl;                           
                              //cout<<listaFacultad.obtenerDato(i).telefono<<endl;                           
                              //cout<<"--------------------------------------"<<endl;                           
                           //}
                         //}
                    //break;
                  //case 2:{
                          //Facultad fac = listaFacultad.buscarLista(rutas[0]);  
                           //for(int i = 0; i < fac.lista.tamLista();i++){
                              //cout<<fac.lista.obtenerDato(i).nombre<<endl;                           
                              //cout<<fac.lista.obtenerDato(i).coordinador<<endl;                           
                              //cout<<fac.lista.obtenerDato(i).ubicacion<<endl;                           
                              //cout<<"--------------------------------------"<<endl;                           
                           //}
                         //}
                    //break;
                  //case 3:{
                          //Facultad fac = listaFacultad.buscarLista(rutas[0]);  
                          //Carrera car = fac.lista.buscarLista(rutas[1]);  
                           //for(int i = 0; i < car.lista.tamLista();i++){
                              //cout<<car.lista.obtenerDato(i).nombre<<endl;                           
                              //cout<<car.lista.obtenerDato(i).semestre<<endl;                           
                              //cout<<"--------------------------------------"<<endl;                           
                            //}
                        //}
                    //break;
                  //case 4:{
                          //Facultad fac = listaFacultad.buscarLista(rutas[0]);  
                          //Carrera car = fac.lista.buscarLista(rutas[1]);  
                          //Asignatura as = car.lista.buscarLista(rutas[2]);  
                           //for(int i = 0; i < as.lista.tamLista();i++){
                              //cout<<as.lista.obtenerDato(i).nombre<<endl;                           
                              //cout<<as.lista.obtenerDato(i).id<<endl;                           
                              //cout<<as.lista.obtenerDato(i).formacion<<endl;                           
                              //cout<<as.lista.obtenerDato(i).universidad<<endl;                           
                              //cout<<"--------------------------------------"<<endl;                           
                            //}

                         //}
                    //break;
                  //case 5:{
                          //Facultad fac = listaFacultad.buscarLista(rutas[0]);  
                          //Carrera car = fac.lista.buscarLista(rutas[1]);  
                          //Asignatura as = car.lista.buscarLista(rutas[2]);  
                          //Profesor prof = as.lista.buscarLista(rutas[3]);  
                           //for(int i = 0; i < prof.lista.tamLista();i++){
                              //cout<<prof.lista.obtenerDato(i).nombre<<endl;                           
                              //cout<<prof.lista.obtenerDato(i).tematica<<endl;                           
                              //cout<<"--------------------------------------"<<endl;                           
                            //}
                         //}
                    //break;
                  //default: cout<<"F"<<endl;
                    //break;
                //}
              //}
              //break; 
        //default: cout<<"llorelo papa"<<endl;
          //break;
    //}

  //}while(op!=6); 

  return 0;
}

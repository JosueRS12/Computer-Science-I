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
 
  do{
    cout<<"Bienvenido a la Gloriosa Universidad Distrital"<<endl;
    cout<<"1) Ingresar datos iniciales"<<endl; //
    cout<<"2) Modificar elementos de la lista"<<endl; //
    cout<<"3) Borrar elementos de las listas "<<endl;
    cout<<"4) Agregar nuevo elemento"<<endl; 
    cout<<"5) Mostrar lista"<<endl;
    cout<<"6) Salir"<<endl;
    cin>>op;
    
    switch (op){
      case 1:{
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
          }
        }
        break;
      case 2:{
              int op2 = 0;
              string ruta2;
              vector<string> res2; 
              cout<<"¿Qué lista desea modificar"<<endl;
              cout<<"1) Facultad"<<endl;
              cout<<"2) Carrera"<<endl;
              cout<<"3) Asignatura"<<endl;
              cout<<"4) Profesor"<<endl;
              cout<<"5) Posgrado"<<endl;
              cin>>op2;
              
              switch (op2){
                case 1:{
                        cout<<" Para ingresar la ruta del archivo hacerlo de la siguiente forma:"<<endl;
                        cout<<"ejemplo: ingenieria"<<endl;
                        cin>>ruta2;
                        Facultad fac = listaFacultad.buscarLista(ruta2);  
                        int op3 = 0;
                        cout<<"¿Que datos desea modificar?"<<endl;
                        cout<<"1) Nombre Facultad"<<endl;
                        cout<<"2) Nombre decano"<<endl;
                        cout<<"3) Ubicacion"<<endl;
                        cout<<"4) Telefono"<<endl;
                        switch (op3){
                          case 1: cin >> fac.nombre;
                            break;
                          case 2: cin >> fac.decano;
                            break;
                          case 3: cin >> fac.ubicacion;
                            break;
                          case 4: cin >> fac.telefono;
                            break;
                          default: cout<<"llorelo"<<endl;
                            break;
                        }
                       }
                  break;
                case 2:{
                        cout<<" Para ingresar la ruta del archivo hacerlo de la siguiente forma:"<<endl;
                        cout<<"ejemplo: ingenieria-sistemas"<<endl;
                        cin>>ruta2;
                        res2 = split(ruta2,'-'); 
                        Facultad fac = listaFacultad.buscarLista(res2[0]);  
                        Carrera car = fac.lista.buscarLista(res2[1]);  
                        int op3 = 0;
                        cout<<"¿Que datos desea modificar?"<<endl;
                        cout<<"1) Nombre Carrera"<<endl;
                        cout<<"2) Nombre Coordinador"<<endl;
                        cout<<"3) Ubicacion"<<endl;
                        switch (op3){
                          case 1: cin >> car.nombre;
                            break;
                          case 2: cin >> car.coordinador;
                            break;
                          case 3: cin >> car.ubicacion;
                            break;
                          default: cout<<"llorelo"<<endl;
                            break;
                        }
                       }
                  break;
                case 3:{
                        cout<<" Para ingresar la ruta del archivo hacerlo de la siguiente forma:"<<endl;
                        cout<<"ejemplo: distrital-sistemas-calculo"<<endl;
                        cin>>ruta2;
                        res2 = split(ruta2,'-'); 
                        Facultad fac = listaFacultad.buscarLista(res2[0]);  
                        Carrera car = fac.lista.buscarLista(res2[1]);  
                        Asignatura as = car.lista.buscarLista(res2[2]);  
                        int op3 = 0;
                        cout<<"¿Que datos desea modificar?"<<endl;
                        cout<<"1) Nombre Asignatura"<<endl;
                        cout<<"2) semestre"<<endl;
                        switch (op3){
                          case 1: cin >> as.nombre;
                            break;
                          case 2: cin >> as.semestre;
                            break;
                          default: cout<<"llorelo"<<endl;
                            break;
                        }
                       }
                  break;
                case 4:{
                        cout<<" Para ingresar la ruta del archivo hacerlo de la siguiente forma:"<<endl;
                        cout<<"ejemplo: distrital-sistemas-calculo-tole"<<endl;
                        cin>>ruta2;
                        res2 = split(ruta2,'-'); 
                        Facultad fac = listaFacultad.buscarLista(res2[0]);  
                        Carrera car = fac.lista.buscarLista(res2[1]);  
                        Asignatura as = car.lista.buscarLista(res2[2]);  
                        Profesor prof = as.lista.buscarLista(res2[3]);  
                        int op3 = 0;
                        cout<<"¿Que datos desea modificar?"<<endl;
                        cout<<"1) Nombre profesor"<<endl;
                        cout<<"2) id"<<endl;
                        cout<<"3) Formacion pregrado"<<endl;
                        cout<<"4) Universidad de Pregrado"<<endl;
                        switch (op3){
                          case 1: cin >> prof.nombre;
                            break;
                          case 2: cin >> prof.id;
                            break;
                          case 3: cin >> prof.formacion;
                            break;
                          case 4: cin >> prof.universidad;
                            break;
                          default: cout<<"llorelo"<<endl;
                            break;
                        }
                       }
                  break;
                case 5:{
                        cout<<" Para ingresar la ruta del archivo hacerlo de la siguiente forma:"<<endl;
                        cout<<"ejemplo: distrital-sistemas-calculo-tole-matematicas"<<endl;
                        cin>>ruta2;
                        res2 = split(ruta2,'-'); 
                        Facultad fac = listaFacultad.buscarLista(res2[0]);  
                        Carrera car = fac.lista.buscarLista(res2[1]);  
                        Asignatura as = car.lista.buscarLista(res2[2]);  
                        Profesor prof = as.lista.buscarLista(res2[3]);  
                        Posgrado pos = prof.lista.buscarLista(res2[4]);  
                        int op3 = 0;
                        cout<<"¿Que datos desea modificar?"<<endl;
                        cout<<"1) Nombre del posgrado"<<endl;
                        cout<<"2) tematica"<<endl;
                        switch (op3){
                          case 1: cin >> pos.nombre;
                            break;
                          case 2: cin >> pos.tematica;
                            break;
                          default: cout<<"llorelo"<<endl;
                            break;
                        }
                       }
                  break;
                default: cout<<"sea serio"<<endl;
                  break;
              }
              
             } 
        case 3:
            break; 
        case 4:{
                int op2 = 0;
                string ruta2;
                vector<string> res2; 
                cout<<"¿En que lista desea insertar"<<endl;
                cout<<"1) Facultad"<<endl;
                cout<<"2) Carrera"<<endl;
                cout<<"3) Asignatura"<<endl;
                cout<<"4) Profesor"<<endl;
                cout<<"5) Posgrado"<<endl;
                cin>>op2;
                switch (op2){
                  case 1:{
                          cout<<" Para ingresar la ruta del archivo hacerlo de la siguiente forma:"<<endl;
                          cout<<"ejemplo: ingenieria"<<endl;
                          cin>>ruta2;
                          Facultad fac = listaFacultad.buscarLista(ruta2);  
                          int op3 = 0;
                          cout<<"¿Que datos desea modificar?"<<endl;
                          cout<<"1) Nombre Facultad"<<endl;
                          cout<<"2) Nombre decano"<<endl;
                          cout<<"3) Ubicacion"<<endl;
                          cout<<"4) Telefono"<<endl;
                          switch (op3){
                            case 1: cin >> fac.nombre;
                              break;
                            case 2: cin >> fac.decano;
                              break;
                            case 3: cin >> fac.ubicacion;
                              break;
                            case 4: cin >> fac.telefono;
                              break;
                            default: cout<<"llorelo"<<endl;
                              break;
                          }
                         }
                    break;
                  case 2:{
                          cout<<" Para ingresar la ruta del archivo hacerlo de la siguiente forma:"<<endl;
                          cout<<"ejemplo: ingenieria-sistemas"<<endl;
                          cin>>ruta2;
                          res2 = split(ruta2,'-'); 
                          Facultad fac = listaFacultad.buscarLista(res2[0]);  
                          Carrera car = fac.lista.buscarLista(res2[1]);  
                          int op3 = 0;
                          cout<<"¿Que datos desea modificar?"<<endl;
                          cout<<"1) Nombre Carrera"<<endl;
                          cout<<"2) Nombre Coordinador"<<endl;
                          cout<<"3) Ubicacion"<<endl;
                          switch (op3){
                            case 1: cin >> car.nombre;
                              break;
                            case 2: cin >> car.coordinador;
                              break;
                            case 3: cin >> car.ubicacion;
                              break;
                            default: cout<<"llorelo"<<endl;
                              break;
                          }
                         }
                    break;
                  case 3:{
                          cout<<" Para ingresar la ruta del archivo hacerlo de la siguiente forma:"<<endl;
                          cout<<"ejemplo: distrital-sistemas-calculo"<<endl;
                          cin>>ruta2;
                          res2 = split(ruta2,'-'); 
                          Facultad fac = listaFacultad.buscarLista(res2[0]);  
                          Carrera car = fac.lista.buscarLista(res2[1]);  
                          Asignatura as = car.lista.buscarLista(res2[2]);  
                          int op3 = 0;
                          cout<<"¿Que datos desea modificar?"<<endl;
                          cout<<"1) Nombre Asignatura"<<endl;
                          cout<<"2) semestre"<<endl;
                          switch (op3){
                            case 1: cin >> as.nombre;
                              break;
                            case 2: cin >> as.semestre;
                              break;
                            default: cout<<"llorelo"<<endl;
                              break;
                          }
                         }
                    break;
                  case 4:{
                          cout<<" Para ingresar la ruta del archivo hacerlo de la siguiente forma:"<<endl;
                          cout<<"ejemplo: distrital-sistemas-calculo-tole"<<endl;
                          cin>>ruta2;
                          res2 = split(ruta2,'-'); 
                          Facultad fac = listaFacultad.buscarLista(res2[0]);  
                          Carrera car = fac.lista.buscarLista(res2[1]);  
                          Asignatura as = car.lista.buscarLista(res2[2]);  
                          Profesor prof = as.lista.buscarLista(res2[3]);  
                          int op3 = 0;
                          cout<<"¿Que datos desea modificar?"<<endl;
                          cout<<"1) Nombre profesor"<<endl;
                          cout<<"2) id"<<endl;
                          cout<<"3) Formacion pregrado"<<endl;
                          cout<<"4) Universidad de Pregrado"<<endl;
                          switch (op3){
                            case 1: cin >> prof.nombre;
                              break;
                            case 2: cin >> prof.id;
                              break;
                            case 3: cin >> prof.formacion;
                              break;
                            case 4: cin >> prof.universidad;
                              break;
                            default: cout<<"llorelo"<<endl;
                              break;
                          }
                         }
                    break;
                  case 5:{
                          cout<<" Para ingresar la ruta del archivo hacerlo de la siguiente forma:"<<endl;
                          cout<<"ejemplo: distrital-sistemas-calculo-tole-matematicas"<<endl;
                          cin>>ruta2;
                          res2 = split(ruta2,'-'); 
                          Facultad fac = listaFacultad.buscarLista(res2[0]);  
                          Carrera car = fac.lista.buscarLista(res2[1]);  
                          Asignatura as = car.lista.buscarLista(res2[2]);  
                          Profesor prof = as.lista.buscarLista(res2[3]);  
                          Posgrado pos = prof.lista.buscarLista(res2[4]);  
                          int op3 = 0;
                          cout<<"¿Que datos desea modificar?"<<endl;
                          cout<<"1) Nombre del posgrado"<<endl;
                          cout<<"2) tematica"<<endl;
                          switch (op3){
                            case 1: cin >> pos.nombre;
                              break;
                            case 2: cin >> pos.tematica;
                              break;
                            default: cout<<"llorelo"<<endl;
                              break;
                          }
                         }
                    break;
                  default: cout<<"sea serio"<<endl;
                    break;
                }
                
              } 
        default: cout<<"llorelo papa"<<endl;
          break;
    }

  }while(op!=6); 

  return 0;
}

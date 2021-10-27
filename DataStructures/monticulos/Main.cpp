#include <iostream>
#include <cstdlib>
#include "Monticulo.h"

using namespace std;

int main(){
  Monticulo mont, monticulo;  
  int op = 0, val = 0; 
  do{
    system("cls");
    cout<<" bienvenido a monticulo"<<endl;
    cout<<" 1)insertar";
    cout<<" 2)atender";
    cout<<" 3)mostrar";
    cout<<" 4)¿monticulo lleno?";
    cout<<" 5)ejemplo preparado";
    cout<<" 6)salir"<<endl;
    cin>>op;

    switch (op){
      case 1:
        {
          cout<<"insertar"<<endl;
          cin>>val;
          mont.insertar(val);
        }
        break;
      case 2:
        {
          cout<<"Atender"<<endl;
          mont.atender();
        }
        break;
      case 3:
        {
          cout<<"mostrar"<<endl;
          mont.imprimirArreglo();
        }
        break;
      case 4:
        {
          if (mont.monticulo_lleno())
            cout<<"lleno"<<endl;
          else
            cout<<"con espacio disponible"<<endl;
        }
        break;
      case 5:
        {
          cout<<"insertados: 60 80 20 90 50 40 30 70 55 45"<<endl;
          monticulo.insertar(60);
          monticulo.insertar(80);
          monticulo.insertar(20);
          monticulo.insertar(90);
          monticulo.insertar(50);
          monticulo.insertar(40);
          monticulo.insertar(30);
          monticulo.insertar(70);
          monticulo.insertar(55);
          monticulo.insertar(45);
          cout<<"----- imprimirArreglo -----"<<endl;
          monticulo.imprimirArreglo();
          cout<<"atendiendo 3 veces"<<endl;
          monticulo.atender();
          monticulo.atender();
          monticulo.atender();
          cout<<"----- imprimirArreglo despues de atender -----"<<endl;
          monticulo.imprimirArreglo();
          cout<<"----- lleno? -----"<<endl;
          cout<<monticulo.monticulo_lleno()<<endl;
        }
        break;
      default: cout<<"llorelo papa"<<endl;
        break;
    }

  }while(op!=6);
  



  return 0;
}

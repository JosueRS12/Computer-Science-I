#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
//#include <stdio.h>

using namespace std;

struct Casa{
  char color[20];
  string pro;
  int pisos;
};

class Conjunto{
  public:
  char nombre;
  Casa *arrCasa;
  Conjunto();
  void setArr(Casa *arr);
};

Conjunto :: Conjunto(){
    nombre = 'h';
    arrCasa = new Casa[5]; 
}

void Conjunto :: setArr(Casa *arr){
  this->arrCasa = arr;
}
int main (){
  Conjunto con;//el que se va a usar para mostrar
  Casa *arrC = new Casa[3]; //guardar
  Casa *arrC2 = new Casa[3]; //guardar
  string colores[3] = {"amarillo", "rojo", "negro"};

  for(int i = 0; i<3; i++){ //llenado array
    strcpy(arrC[i].color, colores[1].c_str());
    arrC[i].pisos = i;
    arrC[i].pro = "benito camelas";

  }
  Conjunto conjunto, conjunto2, conjunto3, conjunto4;

  conjunto.setArr(arrC);
  conjunto3.setArr(arrC);

  for(int i = 0; i<3; i++){ //llenado array
    strcpy(arrC2[i].color, colores[i].c_str());
    arrC2[i].pisos = i;
    arrC2[i].pro = "lalo landa";
  }
  conjunto2.setArr(arrC2);
  conjunto4.setArr(arrC2);
  //open file
  ofstream os("temp.bin", ofstream :: binary);

  os.write((char *) &conjunto, sizeof(Conjunto)); //no había cambiado el sizeof 
  os.write((char *) &conjunto2, sizeof(Conjunto)); //no había cambiado el sizeof 
  os.write((char *) &conjunto3, sizeof(Conjunto)); //no había cambiado el sizeof 
  os.write((char *) &conjunto4, sizeof(Conjunto)); //no había cambiado el sizeof 

  os.close();

  ifstream is("temp.bin", ifstream :: binary);
  is.read((char *) &con, sizeof(Conjunto));
  while(!is.eof()){
    cout<<"nombre conjunto "<<con.nombre<<endl;
    cout<<"color casa 0 "<<con.arrCasa[0].color<<endl;
    cout<<"color casa 1 "<<con.arrCasa[1].color<<endl;
    cout<<"color casa 2 "<<con.arrCasa[2].color<<endl;
    cout<<"propietario 0 "<<con.arrCasa[0].pro<<endl;
    cout<<"propietario 1"<<con.arrCasa[1].pro<<endl;
    cout<<"propietario 2"<<con.arrCasa[2].pro<<endl;
    is.read((char *) &con, sizeof(Conjunto));
  }
  is.close();
  return 0;
}

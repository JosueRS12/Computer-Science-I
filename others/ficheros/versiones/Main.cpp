#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <stdio.h>
#include <sstream>       
using namespace std;

struct Casa{
  char color[20];
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
  //inicializar estructura
  Casa p; //el que se va a usar para mostrar
  Conjunto con;//el que se va a usar para mostrar
  Casa c1; // guardar
  Casa c2; //guardar
  Casa *arrC = new Casa[3]; //guardar
  string colores[3] = {"amarillo", "rojo", "negro"};

  //string colores; 
  //cin>>colores;
  //strcpy(c1.color, colores[0].c_str());
  //c1.color = "azul";
  //strcpy(c1.color, "azul"); 
  //c1.pisos = 3;
  //llenado de estructuras
  //c2.color = "verde";
  //strcpy(c2.color, "rojo");
  //c2.pisos = 2;
  for(int i = 0; i<3; i++){ //llenado array
    //char c = (char)i;
    strcpy(arrC[i].color, colores[0].c_str());
    //arrC[i].color = colores[i];
    //strcpy(arrC[i].color, colores[i]);
    arrC[i].pisos = i;
    //if(i==0)
      //arrC[i].sig = &c2;
    //else
      //arrC[i].sig = &arrC[i-1];

  }
  Conjunto conjunto;
  conjunto.setArr(arrC);

  //open file
  ofstream os("temp.bin", ofstream :: binary);
  //se leen dos estructuras normales
  //os.write((char *) &c1, sizeof(Casa)); // se pasa un apuntador como parametro
  //os.write((char *) &c2, sizeof(Casa)); // 
  //se lee un objeto
  os.write((char *) &conjunto, sizeof(Conjunto)); //no había cambiado el sizeof 
  //se lee un vector de estructuras
  //for(int i = 0; i<5; i ++)
    //os.write((char *) &arrC[i], sizeof(arrC[i])); // se pasa un apuntador como parametro

  os.close();

  ifstream is("temp.bin", ifstream :: binary);
  //is.seekg(0,is.cur);
  //cout<<"tellg"<<is.tellg()<<endl;
  is.read((char *) &con, sizeof(Conjunto));
  cout<<"nombre conjunto "<<con.nombre<<endl;
  cout<<"color casa 0 "<<con.arrCasa[0].color<<endl;
  cout<<"color casa 1 "<<con.arrCasa[1].color<<endl;
  cout<<"color casa 2 "<<con.arrCasa[2].color<<endl;
  //while(!is.eof()){ //mientras no se llegue al final del archivo
    ////cout<<p.sig -> color<<endl;
    ////cou,<<con.arrCasa[0].color<<endl;
    //cout<<"nombre conjunto "<<con.nombre<<endl;
    ////cout<<p.sig<<endl; 
    ////cout<<"tellg"<<is.tellg()<<endl;
    //is.read((char *) &con, sizeof(Conjunto));
    //cout<<"hola"<<endl;
  //}
  //cout<<"       "<<endl;
  //is.seekg(112);
  //cout<<"tellg"<<is.tellg()<<endl;
  //is.read((char *) &p, sizeof(Casa));
  //cout<<p.color<<endl;
  is.close();
  return 0;
}

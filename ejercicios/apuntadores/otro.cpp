#include <cstdlib>
#include <iostream>

using namespace std;
char *Mus[]={"Andr�s Calamaro", "Charly Garc�a", "Gustavo Cerati", "Joaquin Sabina", "Fito Paez"};
char **ApMus[5]={Mus+3, Mus+2, Mus+4, Mus, Mus+1};
char ***AppMus[3]={ApMus+4, ApMus+2, ApMus};
char ****Fin= AppMus+1;

int main(int argc, char *argv[]){
  /*
   *inicio pruebas
   *int *p, x = 2;
   *p = &x;
   *cout<<"Valor de x "<<x<<endl;
   *cout<<" Direccion de x"<<&x<<endl;
   *cout<<" p => "<<p<<endl;
   *cout<<" *p => "<<*p<<endl;
   *cout<<" &p =>"<<&p<<endl;
   **Mus[5] **ApMus[5] ***AppMus[6] ****Fin 
   *cout<<"Mus"<<endl;
   *for(int i = 0; i<5; i++){
   *  cout<<(Mus+i)<<endl;
   *}
   *cout<<"ApMus"<<endl;
   *for(int i = 0; i<5; i++){
   *  cout<<*(ApMus+i)<<endl;
   *}
   *for(int i = 0; i<5; i++){
   *  cout<<*(Mus+i)<<endl;
   *}
    cout<<endl;
    cout<<endl;
    cout<<endl;
   */
  //fin pruebas
  cout<<**(*Fin-1)+6<<endl;
  cout<<*(*(*(Fin-1)-1)+1)+8<<endl;
  ++*(*(AppMus+1)-1);
  cout<<**(*Fin-1)+8<<endl;
  cout<<(*++*--*Fin+2)<<endl;
  cout<<*(**Fin-4)+9<<endl;	
  system("PAUSE");
  return EXIT_SUCCESS;
}

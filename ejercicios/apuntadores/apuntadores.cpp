#include <cstdlib>
#include <iostream>

using namespace std;

void arreglo(int *p)
{int i;
 for (i=0; i<10; i++)
 p[i]=i*2; // se accede atraves de direcciones de memoria
     }
     

int main(int argc, char *argv[])
{int i, a[10], *pa, **ppa;
 for (i=0; i<10; i++)
     a[i]=0; // 0 0 0 0 0 0 0 0 0 0
 pa=a;
 for (i=0; i<10; i++)
     cout<< pa[i]<<" "; //puros ceros 0 0 0 0 0 0 0 0 0 
 arreglo(pa);
 cout<<endl;
 ppa=&pa;
 for (i=0; i<10; i++)
   cout<< *(*ppa+i)<<" "; //*(direccionPrimerElemento + i) => 0 2 4 6 8 10 12 14 16 18
    system("PAUSE");
    return EXIT_SUCCESS;
}

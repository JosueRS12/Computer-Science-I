#ifndef ARBOLRN_H
#define ARBOLRN_H

#include <cstdlib>
#include <iostream>

using namespace std;

struct NODO{ 
  int info;
  NODO *izq, *der;
  bool color = false; // negro = 1 true, rojo = 0 false
};

class ARBOL {

    NODO *raiz ;
    public:	
    ARBOL() {
        raiz = NULL;
    }
    NODO *raiz_arbol() {
        return raiz;
    }

    int ins_arbol(int); //modificar
    NODO *buscarPadreNuevo(int, NODO *, NODO *);
    NODO *buscarPadreExistente(int, NODO *, NODO *);
    void  ajusteInsercion(NODO *);
    void  ajusteEliminacion(NODO *);
    void borrar_nodo(NODO *, NODO *); //modificar
	  NODO *buscar(int, NODO **, NODO *);
    int retira_arbol(int);
    NODO *rotacionSecillaIzq(NODO *P);
    NODO *rotacionSecillaDer(NODO *P);
    NODO *rotacionDobleIzq(NODO *P);
    NODO *rotacionDobleDer(NODO *P);
    void inorden(NODO *);
    void preorden(NODO *);
    void posorden(NODO *);
    void destruir(NODO *p);
    ~ARBOL();
};

NODO *ARBOL::buscarPadreNuevo(int n, NODO *p, NODO *q){
  if (p -> info == -3) 
    return q;
  if (n < p->info){
    q=p;
    q=buscarPadreNuevo(n,p->izq,q);
    return q;
  }
  else if (n > p->info){
    q=p;
    q=buscarPadreNuevo(n,p->der,q);
    return q;
  }
  else return NULL;
}

NODO *ARBOL::buscarPadreExistente(int n, NODO *p, NODO *q){
  if (p -> info == n)
    return q;
  if (n < p->info){
    q=p;
    q=buscarPadreExistente(n,p->izq,q);
    return q;
  }
  if (n > p->info){
    q=p;
    q=buscarPadreExistente(n,p->der,q);
    return q;
  }
  else return q;
  //else return NULL;
}

void ARBOL :: ajusteInsercion(NODO *x){ 
  while(x!=raiz && buscarPadreExistente(x->info, raiz, NULL) -> color == false){
    NODO *padre = buscarPadreExistente(x->info,raiz,NULL); 
    NODO *abuelo = buscarPadreExistente(padre -> info,raiz,NULL); 
    NODO *tio = new NODO;
    if(padre == abuelo -> izq){
      tio = abuelo -> der;
      //caso 1 
      if(tio -> color == false){
        padre -> color = true;
        tio -> color = true;
        abuelo -> color = false;
        x = abuelo;
      } else{
        if(x == padre -> der){ //caso 2
          x = padre;
          rotacionSecillaIzq(x);
          abuelo = buscarPadreExistente(x -> info, raiz, NULL);
        }
        padre -> color = true;
        abuelo -> color = false;
        rotacionSecillaDer(abuelo); 
      }
    } else{
      tio = abuelo -> izq;
      if(tio -> color == false){
        padre -> color = true;
        tio -> color = true;
        abuelo -> color = false;
        x = abuelo;
      } else{
        if(x == padre -> izq){ //caso 2
          x = padre;
          rotacionSecillaDer(x); //x padre abuelo => padre abuelo bisabuelo
          padre = buscarPadreExistente(x -> info, raiz, NULL);
          abuelo = buscarPadreExistente(padre -> info, raiz, NULL);
        }
        padre -> color = true;
        abuelo -> color = false;
        rotacionSecillaIzq(abuelo); 
      }
    }
  } 
  raiz -> color = true;
}

NODO *ARBOL :: rotacionDobleDer(NODO *p){
 p->izq = rotacionSecillaIzq(p -> izq); 
 return rotacionSecillaDer(p); 
}
//-------------------------
NODO *ARBOL :: rotacionDobleIzq(NODO *p){
 p->der = rotacionSecillaDer(p -> der); 
 return rotacionSecillaIzq(p); 
}

NODO *ARBOL :: rotacionSecillaIzq(NODO *p){
  NODO *q = p -> der, *bisAb = new NODO;   
  if(p!=raiz)
    bisAb = buscarPadreExistente(p -> info, raiz, NULL);
  else
    raiz = q;
  p -> der = q -> izq; 
  q -> izq = p;
  if(q != raiz){ 
    if(bisAb -> der == p)
      bisAb -> der = q; 
    else
      bisAb -> izq = q; 
  }
  return q;
}

NODO *ARBOL :: rotacionSecillaDer(NODO *p){
  NODO *q = p -> izq, *bisAb = new NODO;   
  if(p!=raiz)
    bisAb = buscarPadreExistente(p -> info, raiz, NULL);  
  else
    raiz = q;
  p -> izq = q -> der; 
  q -> der = p;
  if(q != raiz){ 
    if(bisAb -> der == p)
      bisAb -> der = q; 
    else
      bisAb -> izq = q; 
  }
  return q;
}
//-------------------------
int ARBOL::ins_arbol(int n){
  NODO *q, *nulo1 = new NODO, *nulo2 = new NODO; 
  nulo1 -> info = -3;
  nulo2 -> info = -3;
  nulo1 -> color = true;
  nulo2 -> color = true;
  if (raiz == NULL){
    raiz= new NODO;
    raiz->info =n;
    raiz -> color = true;
    raiz->izq= nulo1;
    raiz->der= nulo2; //nulo
    return 0;
  } //nice
  q = buscarPadreNuevo(n,raiz,NULL); //se obtiene donde va a insertar
  //cout<<q -> info<<endl;
  if (q==NULL) 
   return (-1);

  NODO *nuevo;
  nuevo= new NODO;
  nuevo->info = n;
  nuevo->izq= nulo1;
  nuevo->der= nulo2; //nulo
  if (n<q->info)
    q->izq=nuevo;
  else   
    q->der=nuevo;
  ajusteInsercion(nuevo); //se realiza el ajuste al insertar
  return 0;
}

void  ARBOL :: ajusteEliminacion(NODO *x){
  while(x!=raiz && x -> color == true){
    NODO *padre = buscarPadreExistente(x->info,raiz,NULL); 
    NODO *w = new NODO;
    if(x == padre -> izq){
      w = padre -> der;
      if(w -> color == false){
        //caso 1
        w -> color = true;
        padre -> color = false;
        rotacionSecillaIzq(padre);
        w = padre -> der;
      }
      if(w -> der -> color == true && w -> izq -> color == true){
        //caso 2
        w -> color = false;
        x = padre;
      } else{
        if( w -> der -> color == true ){
          //caso 3
          w -> izq -> color = true;
          w -> color = false;
          rotacionSecillaDer(w);
          w = padre -> der;
        }
        //caso 4
        w -> color = padre -> color;
        padre -> color = true;
        w -> der -> color = true;
        rotacionSecillaIzq(padre);
        x = raiz; 
      }
    } else{
      w = padre -> izq;
      if(w -> color == false){
        //caso 1
        w -> color = true;
        padre -> color = false;
        rotacionSecillaDer(padre);
        w = padre -> izq;
      }
      if(w -> izq -> color == true && w -> der -> color == true){
        //caso 2
        w -> color = false;
        x = padre;
      } else{
        if( w -> izq -> color == true ){
          //caso 3
          w -> der -> color = true;
          w -> color = false;
          rotacionSecillaIzq(w);
          w = padre -> izq;
        }
        //caso 4
        w -> color = padre -> color;
        padre -> color = true;
        w -> izq -> color = true;
        rotacionSecillaDer(padre);
        x = raiz; 
      }
    } 
  }
  x -> color = true;
}

void ARBOL::borrar_nodo (NODO *q, NODO *p){ //q = padre nodo a eliminar; p = nodo a eliminar
  NODO  *r, *s,*t, *aux; // r = remplazo; s = padre de reemplazo; t = s
  int respaldo = 0;
  if (p->der->info==-3){  
    if(p -> izq -> info == -3){
      aux = p;
      ajusteEliminacion(p);
      aux -> info = -3;
    }//izq tena algo
    if(p -> izq -> info != -3){
      aux = p -> izq;
      ajusteEliminacion(p -> izq);
      p -> info = aux -> info;
      aux -> info = -3;    
    }
  }//nulo 
  else {
    s = p;
    r=p->der; // derecha
    t=r->izq; // izquierda de r
    while(t->info!=-3){ //nulo
      s=r; r=t; t=t->izq; //se encuentra el r 
    }
    if (r -> der -> info == -3){
      aux = r; //r => a12 -> aux => a12
      ajusteEliminacion(r); //r => b12
      p -> info = aux -> info;
      aux -> info = -3; //limpiooooo
    }else{
      respaldo = r -> info;
      r -> info = r -> der -> info;
      aux = r -> der;
      ajusteEliminacion(r->der);
      p -> info = respaldo;
      aux -> info = -3;
    }
  }
}

NODO *ARBOL::buscar(int n, NODO **p, NODO *q){
	if (*p==NULL) 
    return NULL;
	if (n <(*p)->info){
	          q=*p;
	           *p=(*p)->izq;
	          q=buscar(n,p,q);
	          return q;}
	else if (n>(*p)->info){
		q=*p;
		*p=(*p)->der;
		q =buscar(n,p,q);
		return q;
  }
  else return q;
}

int ARBOL:: retira_arbol(int n){
  NODO *q, *p=raiz;
  q=buscar(n,&p,NULL); //halla padre
  if (p==NULL) 
    return -1;
  borrar_nodo(q,p);
  return 0;
}

void ARBOL::inorden(NODO *p){
if (p!=NULL){
        inorden(p->izq);
        if(p->info != -3){
          cout<<p->info<<" color: ";
          cout<<p->color<<endl;
        }
        inorden(p->der);
  }
}

void ARBOL::preorden(NODO *p){
if (p!=NULL){
      if(p->info != -3){
        cout<<p->info<<" color: ";
        cout<<p->color<<endl;
      }
       preorden(p->izq);
       preorden(p->der);
  }
}
void ARBOL::posorden(NODO *p){
if (p!=NULL){
       posorden(p->izq);
       posorden(p->der);
      if(p->info != -3){
        cout<<p->info<<" color: ";
        cout<<p->color<<endl;
      }
  }
}

void ARBOL::destruir(NODO *p){
if (p!=NULL){
      destruir(p->izq);
      destruir(p->der);
      delete p;
      cout<<"Nodo destruido..."<< endl;
  }
}
ARBOL::~ARBOL(){
  destruir(raiz);
}
#endif

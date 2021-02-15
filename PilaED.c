#include <stdlib.h>
#include <stdio.h>

typedef struct Nodo{
    int num;
    struct Nodo *siguiente; //siguiente es el elemento que esta abajo
}Pila;

Pila* Crear(int x);
Pila* Alta(int x, Pila *top);
Pila* Baja(Pila *top);
void Consulta(Pila *top);
int Conteo(Pila *top);

int main(){
    int seleccion,x,q,dato;
    Pila *nodo=NULL;
    printf("Pila\n");
    do{
    printf("Seleccione la opcion deseada\n");
    printf("1. Alta\n2. Baja\n3. Consultar datos en la pila\n4. Numero de Elementos\n");
    scanf("%d",&seleccion);
    if(seleccion==1){
        printf("Numero a ingresar en la Pila: ");
        scanf("%d",&dato);
        printf("\n");
        nodo=Alta(dato,nodo);
    }else if(seleccion==2){
        nodo=Baja(nodo);
    }else if(seleccion==3){
        Consulta(nodo);
    }else if(seleccion==4){
        x=Conteo(nodo);
        printf("Hay %d elementos en la pila\n",x);
    }else{
        printf("Valor erroneo!\n");
    }
    printf("Si desea repetir el menu presione 1. En caso contrario presione otro numero\n");
    scanf("%d",&q);
    }while(q==1);
    printf("Hasta luego!\n");

return 0;
}


Pila* Crear(int x){
    Pila *nuevoNodo;
    nuevoNodo =(Pila*)malloc(sizeof(Pila)); //No es necesario el cast ya, pero es una buena precaucion
    nuevoNodo->num=x;
    nuevoNodo->siguiente=NULL;
    return nuevoNodo;
}

Pila* Alta(int x, Pila *top){
    Pila *nuevo;
    nuevo=Crear(x);
    if(top!=NULL){
        nuevo->siguiente=top;
    }
    return nuevo;
}

Pila* Baja(Pila *top){
    Pila *aux;
    aux=top;
    if(top!=NULL){
        top=top->siguiente;
    }
    free(aux);
    return top;
}

void Consulta(Pila *top){
    int i=1,edge;
    if(top==NULL){
        printf("La pila esta vacia\n");
    }else{
        while(top!=NULL){
            printf("El elemento %d es igual a %d\n",i,top->num);
            top=top->siguiente;
            i++;
        }
    }
}

int Conteo(Pila *top){
    int i=0;
    if(top==NULL){
        return 0;
    }else{
        while(top!=NULL){
            i++;
        }
        return i;
    }
}

/*
El siguiente de una pila apunta al elemento de abajo
Lo que se debe conservar es el elemenyo de hasta arriba
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

typedef struct Nodo{
    char dato;
    struct Nodo *siguiente; //siguiente es el elemento que esta arriba o atras
}Cola;

Cola* Crear(char n);
Cola* Alta(char n, Cola *primero);
Cola* Baja(Cola *primera);
void Consulta(Cola *primera);
char regresaPrimero(Cola *primera);
int estaVacio(Cola *primera);

int main(){
    srand (time(NULL));
    int q,j=1,k=1,y;
    char carac,control;
    char recibe[2];
    Cola *fila1=NULL;
    Cola *fila2=NULL;
    Cola *fila3=NULL;
    printf("Crucero\n");
    printf("Llene la fila 1 del crucero\n");
    do{
    printf("Letra a ingresar en la Cola: ");
    scanf("%1s",recibe);
    carac=recibe[0];
    printf("\n");
    fila1=Alta(carac,fila1);
    printf("Si desea ingresar otro dato a la fila 1 presione 1. En caso contrario presione otro numero \n");
    scanf("%d",&q);
    }while(q==1);
    printf("Llene la fila 2 del crucero\n");
    do{
    printf("Numero a ingresar en la Cola: ");
    scanf("%1s",recibe);
    carac=recibe[0];
    printf("\n");
    fila2=Alta(carac,fila2);
    printf("Si desea ingresar otro dato a la fila 2 presione 1. En caso contrario presione otro numero\n");
    scanf("%d",&q);
    }while(q==1);

    printf("El estado de la fila 3 se ira actualizando... \n");

    do{
        Sleep(1000);
        y=rand()%2;
        if(y==0){
           control=regresaPrimero(fila1);
           fila3=Alta(control,fila3);
           fila1=Baja(fila1);
           j=estaVacio(fila1);
           Consulta(fila3);
        }
        if(y==1){
           control=regresaPrimero(fila2);
           fila3=Alta(control,fila3);
           fila2=Baja(fila2);
           k=estaVacio(fila2);
           Consulta(fila3);
        }

    }while(j==1 && k==1);
    if(j==1){
        while(j!=0){
           Sleep(1000);
           control=regresaPrimero(fila1);
           fila3=Alta(control,fila3);
           fila1=Baja(fila1);
           j=estaVacio(fila1);
           Consulta(fila3);
        }
    }else if(k==1){
        while(k!=0){
           Sleep(1000);
           control=regresaPrimero(fila2);
           fila3=Alta(control,fila3);
           fila2=Baja(fila2);
           k=estaVacio(fila2);
           Consulta(fila3);
        }
    }

    printf("Las filas 1 y 2 se han vaciado por completo \n");

return 0;
}

Cola* Crear(char n){
    Cola *nuevo;
    nuevo=(Cola*)malloc(sizeof(Cola)); //*Cola es apuntador llamado cola. Cola* es un apuntador a un tipo de dato Cola
    nuevo->dato=n;
    nuevo->siguiente=NULL;
    return nuevo;
}

Cola* Alta(char n, Cola *primero){
    Cola *aux, *aux2;
    aux=Crear(n);
    if(primero==NULL){
        return aux;
    }else{
        aux2=primero;
        while(aux2->siguiente!=NULL){
            aux2=aux2->siguiente;
        }
        aux2->siguiente=aux;
        return primero;
    }
}

Cola* Baja(Cola *primera){
    if(primera==NULL){
        printf("Pila vacia \n");
    }else{
        Cola *aux;
        aux=primera;
        primera=primera->siguiente;
        free(aux);
    }
    return primera;
}

void Consulta(Cola *primera){
   Cola *aux;
   aux=primera;
   while(aux!=NULL){
    printf("%c ",aux->dato);
    aux=aux->siguiente;
   }
   printf("\n");
}

char regresaPrimero(Cola *primera){
    char a;
    if(primera==NULL){
        printf("Pila vacia \n");
    }else{
        a=primera->dato;
    }
    return a;
}

int estaVacio(Cola *primera){
    int x;
    if(primera==NULL){
        x=0;
    }else{
        x=1;
    }
    return x;
}





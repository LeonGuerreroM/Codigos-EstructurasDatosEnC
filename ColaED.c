#include <stdlib.h>
#include <stdio.h>

typedef struct Nodo{
    int num;
    struct Nodo *siguiente; //siguiente es el elemento que esta arriba o atras
}Cola;

Cola* Crear(int n);
Cola* Alta(int n, Cola *primero);
Cola* Baja(Cola *primera);
void Consulta(Cola *primera);
int Conteo(Cola *primera);

int main(){
    int seleccion,x,q,dato;
    Cola *nodo=NULL;
    printf("Cola\n");
    do{
    printf("Seleccione la opcion deseada\n");
    printf("1. Alta\n2. Baja\n3. Consultar datos en la cola\n4. Numero de Elementos\n");
    scanf("%d",&seleccion);
    if(seleccion==1){
        printf("Numero a ingresar en la Cola: ");
        scanf("%d",&dato);
        printf("\n");
        nodo=Alta(dato,nodo);
    }else if(seleccion==2){
        nodo=Baja(nodo);
    }else if(seleccion==3){
        printf("Elementos en la cola: ");
        Consulta(nodo);
        printf("\n");
    }else if(seleccion==4){
        x=Conteo(nodo);
        printf("Hay %d elementos en la Cola\n",x);
    }else{
        printf("Valor erroneo!\n");
    }
    printf("Si desea repetir el menu presione 1. En caso contrario presione otro numero\n");
    scanf("%d",&q);
    }while(q==1);
    printf("Hasta luego!\n");
return 0;
}

Cola* Crear(int n){
    Cola *nuevo;
    nuevo=(Cola*)malloc(sizeof(Cola)); //*Cola es apuntador llamado cola. Cola* es un apuntador a un tipo de dato Cola
    nuevo->num=n;
    nuevo->siguiente=NULL;
    return nuevo;
}

Cola* Alta(int n, Cola *primero){
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
    printf("%d ",aux->num);
    aux=aux->siguiente;
   }
}

int Conteo(Cola *primera){
    int i=0;
    if(primera==NULL){
        return 0;
    }else{
        while(primera!=NULL){
            i++;
            primera=primera->siguiente;
        }
        return i;
    }
}

/*El siguiente apuynta al alamento de atras o de arriba
El que se conserva es el primero en la fila*/

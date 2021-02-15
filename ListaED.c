#include <stdlib.h>
#include <stdio.h>

typedef struct Nodo{
    int num;
    struct Nodo *sig; //siguiente es el elemento que esta arriba o atras
}List;

List* Crear(int n);
List* Alta(int n, List *top);
List* Insertar(List* top, int n, int pos);
List* InsertarPrimero(List *top, int n);
List* eliminarPrimero(List *top);
List* eliminarUltimo(List *top);
List* bajaPorDato(List *top, int dato);
List* bajaPorIndice(List *top, int indice);
List* modificacion(List *top, int dato, int indice);
void Consulta(List *top);
int Conteo(List *top);

int main(){
    int seleccion,seleccion2,x,q,dato,posicion;
    List *nodo=NULL;
    printf("Lista\n");
    do{
    printf("Seleccione la opcion deseada\n");
    printf("1. Alta(al final de la lista)\n2. Insertar \n3. Modificacion \n4. Baja\n5. Consultar\n");
    scanf("%d",&seleccion);
    if(seleccion==1){
        printf("Numero a ingresar en la Lista: ");
        scanf("%d",&dato);
        printf("\n");
        nodo=Alta(dato,nodo);
    }else if(seleccion==2){
        printf("Numero a ingresar en la Lista: ");
        scanf("%d",&dato);
        printf("\n");
        printf("1. Insertar por indice\n2. Insertar al inicio\n");
        scanf("%d",&seleccion2);
        printf("\n");
        if(seleccion2==1){
            printf("Posicion en donde insertar en la Lista: ");
            scanf("%d",&posicion);
            printf("\n");
            nodo=Insertar(nodo,dato,posicion);
        }else{
            nodo=InsertarPrimero(nodo,dato);
        }
    }else if(seleccion==5){
        printf("Elementos en la Lista: ");
        Consulta(nodo);
        printf("\n");
    }else if(seleccion==3){
        printf("Numero a ingresar en el nodo a modficar: ");
        scanf("%d",&dato);
        printf("\n");
        printf("Indice del nodo: ");
        scanf("%d",&posicion);
        printf("\n");
        nodo=modificacion(nodo,dato,posicion);
    }else if(seleccion==4){
        printf("1. Eliminar Primero\n2. Eliminar Ultimo\n3. Eliminar por Indice\n4. Eliminar por Dato\n ");
        scanf("%d",&seleccion2);
        printf("\n");
        if(seleccion2==1){
            nodo=eliminarPrimero(nodo);
        }else if(seleccion2==2){
            nodo=eliminarUltimo(nodo);
        }else if(seleccion2==3){
            printf("Indice del nodo a eliminar: ");
            scanf("%d",&posicion);
            printf("\n");
            nodo=bajaPorIndice(nodo, posicion);
        }else if(seleccion2==4){
            printf("Numero: ");
            scanf("%d",&dato);
            printf("\n");
            nodo=bajaPorDato(nodo,dato);
        }
    }else{
        printf("Valor erroneo!\n");
    }
    printf("Si desea repetir el menu presione 1. En caso contrario presione otro numero\n");
    scanf("%d",&q);
    }while(q==1);
    printf("Hasta luego!\n");
return 0;
}


List* Crear(int n){
    List *nuevo;
    nuevo=(List*)malloc(sizeof(List));
    nuevo->num=n;
    nuevo->sig=NULL;
    return nuevo;
}

List* Alta(int n, List *top){
    List *aux, *aux2;
    aux=Crear(n);
    if(top==NULL){
        return aux;
    }else{
        aux2=top;
        while(aux2->sig!=NULL){
            aux2=aux2->sig;
        }
        aux2->sig=aux;
        return top;
    }
}

List* Insertar(List *top, int n, int pos){
    int i;
	int len = Conteo(top);
	List *aux, *aux2;
    if(top==NULL){
    	printf("La lista Esta vacia, no se puede insertar\n");
        return top;
    }else if (len < pos){
    	printf("Posicion invalida \n");
    	return top;
    }else{
    	aux = top;
    	aux2 = Crear(n);
    	for (i = 1; i<pos; i++){
    		aux = aux ->sig;
    	}
    	aux2 -> sig = aux -> sig;
    	aux -> sig = aux2;
    	return top;
    }
}

List* InsertarPrimero(List *top, int n){
    List *aux;
    aux=Crear(n);
    if(top==NULL){
        return aux;
    }else{
        aux->sig=top;
        return aux;
    }
}

List* eliminarPrimero(List *top){
    List *aux;
    if(top==NULL){
        printf("La lista esta vacia \n");
        return top;
    }else{
        aux=top;
        top=top->sig;
        free(aux);
        return top;
    }
}

List* eliminarUltimo(List *top){
    List *aux,*aux3;
    aux=top;
    aux3=aux->sig;
    if(top==NULL){
        printf("La lista esta vacia \n");
        return top;
    }else{
        while(aux3->sig!=NULL){
            aux=aux->sig;
            aux3=aux->sig;
        }
        aux->sig=NULL;
        free(aux3);
        return top;
    }
}

List* bajaPorDato(List *top, int dato){
    List *aux,*aux2,*aux3;
    aux=top;
    if(top==NULL){
        printf("La lista esta vacia \n");
        return top;
    }else{
        while(aux!=NULL){
            if(aux->num==dato){
                top=aux->sig;
                free(aux);
                break;
            }else if(aux->sig==NULL){
                printf("Dato no encontrado\n");
                break;
            }else{
                aux2=aux->sig;
                if(aux2->num==dato){
                    aux3=aux2;
                    aux->sig=aux2->sig;
                    free(aux3);
                    break;
                }
            }
            aux=aux->sig;
        }
        return top;
    }
}

List* bajaPorIndice(List *top, int indice){
    List *aux,*aux2,*aux3;
    aux=top;
    int i;
    if(top==NULL){
        printf("La lista esta vacia \n");
        return top;
    }else{
        for(i=1;i<indice-1;i++){
            aux=aux->sig;
        }
        aux2=aux->sig;
        aux->sig=aux2->sig;
        free(aux2);
        return top;
    }
}

List* modificacion(List *top, int dato, int indice){
    int i;
    List *aux;
    aux=top;
    if(top==NULL){
        printf("La lista esta vacia \n");
        return top;
    }else{
        for(i=1;i<indice;i++){ //considera que desde el principio ya esta en el primer elemento, no como los arreglos que entran hasta que empieza el for
            aux=aux->sig;
        }
        aux->num=dato;
        return top;
    }
}

void Consulta(List *top){
    int x;
    List *aux;
    aux=top;
    while(aux!=NULL){
        x=aux->num;
        printf("%d ",x);
        aux=aux->sig;
    }
}

int Conteo(List *top){
    int i=0;
    if(top==NULL){
        return 0;
    }else{
        while(top!=NULL){
            i++;
            top = top->sig;
        }
        return i;
    }
}





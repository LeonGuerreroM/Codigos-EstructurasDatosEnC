#include <stdlib.h>
#include <stdio.h>

typedef struct Nodo{
	int dato;
	struct Nodo *sig;
	struct Nodo *ant;
}Lista;

Lista* Crear(int dato);
Lista* AltaInicio(Lista *top, int dato);
Lista* AltaFinal(Lista *top, int dato);
Lista* AltaInterna(Lista* top,int dato, int posicion);
Lista* bajaInicio(Lista *top);
Lista* bajaFinal(Lista *top);
Lista* bajaPorPosicion(Lista *top,int posicion);
Lista* modificacion(Lista *top, int dato, int indice);
void mostrarLista(Lista *top);
void Consulta(Lista *top);
int Conteo(Lista *top);

int main(){
int seleccion,seleccion2,x,q,dato,posicion;
    Lista *nodo=NULL;
    printf("Lista Doble\n");
    printf("Menu principal\n");
    do{
    printf("Seleccione la opcion deseada\n");
    printf("1. Alta(Al Inicio)\n2. Insertar \n3. Modificacion \n4. Baja\n5. Mostrar\n");
    scanf("%d",&seleccion);
    if(seleccion==1){
        printf("Numero a ingresar en la Lista: ");
        scanf("%d",&dato);
        printf("\n");
        nodo=AltaInicio(nodo,dato);
    }else if(seleccion==2){
        printf("Numero a ingresar en la Lista: ");
        scanf("%d",&dato);
        printf("\n");
        printf("1. Insertar por indice\n2. Insertar al Final\n");
        scanf("%d",&seleccion2);
        printf("\n");
        if(seleccion2==1){
            printf("Posicion en donde insertar en la Lista: ");
            scanf("%d",&posicion);
            printf("\n");
            nodo=AltaInterna(nodo,dato,posicion);
        }else{
            nodo=AltaFinal(nodo,dato);
        }
    }else if(seleccion==0){
        Consulta(nodo);
        printf("\n");
    }else if(seleccion==5){
        mostrarLista(nodo);
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
        printf("1. Eliminar Primero\n2. Eliminar Ultimo\n3. Eliminar por Indice\n");
        scanf("%d",&seleccion2);
        printf("\n");
        if(seleccion2==1){
            nodo=bajaInicio(nodo);
        }else if(seleccion2==2){
            nodo=bajaFinal(nodo);
        }else if(seleccion2==3){
            printf("Indice del nodo a eliminar: ");
            scanf("%d",&posicion);
            printf("\n");
            nodo=bajaPorPosicion(nodo, posicion);
        }
    }else{
        printf("Valor erroneo!\n");
    }
    printf("Si desea repetir el menu principal presione 1. En caso contrario presione otro numero\n");
    scanf("%d",&q);
    }while(q==1);
    printf("Hasta luego!\n");
return 0;



return 0;
}

Lista* Crear(int dato){
	Lista *nuevo;
	nuevo=(Lista*)malloc(sizeof(Lista));
	nuevo->dato=dato;
	nuevo->sig=NULL;
	nuevo->ant=NULL;
	return nuevo;
}

Lista* AltaInicio(Lista *top, int dato){
	Lista *nuevo;
	nuevo=Crear(dato);
	if(top==NULL){
		top==nuevo;
	}else{
		top->ant=nuevo;
		nuevo->sig=top;
	}
	return nuevo;
}

Lista* AltaFinal(Lista *top, int dato){
	Lista *nuevo, *aux;
	aux=top;
	nuevo=Crear(dato);
	if(aux==NULL){
		return nuevo;
	}else{
		while(aux->sig!=NULL){
			aux=aux->sig;
		}
		aux->sig=nuevo;
		nuevo->ant=aux;
		return top;
	}
}

Lista* AltaInterna(Lista* top,int dato, int posicion){
	int longitud,i;
	Lista *aux, *nuevo;
	aux=top;
	if(top==NULL){
		return top;
	}else{
		longitud=Conteo(top);
		if(posicion>longitud){
			printf("Valor no valido\n");
			return top;
		}else{
			nuevo=Crear(dato);
			for(i=1;i<posicion;i++){
				aux=aux->sig;
			}
			nuevo->sig=aux->sig; //se mueven dos anteriores y dos siguientes
			aux->sig->ant=nuevo;
			aux->sig=nuevo;
			nuevo->ant=aux;
			return top;
		}
	}
}

Lista* bajaInicio(Lista *top){
	if(top==NULL){
		printf("Lista vacia\n");
	}else{
		Lista *aux;
		aux=top;
		top=top->sig;
		if(top!=NULL){
			top->ant=NULL;
		}
		free(aux);
		return top;
	}
}

Lista* bajaFinal(Lista *top){
	int longitud=Conteo(top);
	int i;
	Lista *aux, *aux2;
	aux=top;
	if(top==NULL){
		printf("Lista vacia\n");
	}else{
		for(i=1;i<longitud-1;i++){
			aux=aux->sig;
		}
		aux2=aux->sig;
		aux->sig=NULL;
		free(aux2);
	}
	return top;
}

Lista* bajaPorPosicion(Lista *top,int posicion){
	Lista *aux;
	int i;
	aux=top;
	if(top==NULL){
		printf("Pila Vacia\n");
	}else{
        for(i=1;i<posicion;i++){
            aux=aux->sig;
        }
        aux->ant->sig=aux->sig;
        aux->sig->ant=aux->ant;
        aux->sig=NULL;
        aux->ant=NULL;
	}
	return top;
}

void mostrarLista(Lista *top){
    Lista *aux;
    aux=top;
    int x;
    char k;
    char j[1];
    if(aux==NULL){
        printf("Lista vacia\n");
    }else{
       x=aux->dato;
       printf("%d\n",x);
       do{
        printf("Use las a/s para moverse en la lista. Para salir presione e \n");
        scanf("%1s",j);
        k=j[0];
        if(k=='s'){
            if(aux->sig!=NULL){
            aux=aux->sig;
            }
            x=aux->dato;
            printf("%d\n",x);
        }else if(k=='a'){
            if(aux->ant!=NULL){
            aux=aux->ant;
            }
            x=aux->dato;
            printf("%d\n",x);
        }
       }while(k!='e');
    }
}

Lista* modificacion(Lista *top, int dato, int indice){
    int i;
    Lista *aux;
    aux=top;
    if(top==NULL){
        printf("La lista esta vacia \n");
        return top;
    }else{
        for(i=1;i<indice;i++){ //considera que desde el principio ya esta en el primer elemento, no como los arreglos que entran hasta que empieza el for
            aux=aux->sig;
        }
        aux->dato=dato;
        return top;
    }
}

void Consulta(Lista *top){
    int x;
    Lista *aux;
    aux=top;
    while(aux!=NULL){
        x=aux->dato;
        printf("%d ",x);
        aux=aux->sig;
    }
}

int Conteo(Lista *top){
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


#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Nodo{
    int id;
    char titulo[50];
    char autor[50];
	int precio;
	struct Nodo *sig;
	struct Nodo *ant;
}Lista;

Lista* Crear(char titul[], char aut[], int precio,int id);
Lista* AltaInicio(Lista *top, char titul[], char aut[], int precio, int id);
Lista* bajaInicio(Lista *top);
Lista* bajaFinal(Lista *top);
Lista* bajaPorPosicion(Lista *top,int posicion);
Lista* modificacion(Lista *top, int indice);
Lista* ordenar(Lista *top,int opcion);
void mostrarLista(Lista *top);
int Conteo(Lista *top);

int main(){
    printf("Libreria");
    int seleccion,seleccion2,x,q,precio,posicion,id;
    char titulo[50];
    char autor[50];
    Lista *nodo=NULL;
    do{
    printf("Seleccione la opcion deseada\n");
    printf("1. Añadir libro\n2. Eliminar Libro\n3. Modificacion \n4. Consultar Libros\n5. Ordenar\n");
    scanf("%d",&seleccion);
    if(seleccion==1){
        printf("Id del Libro: ");
        scanf("%d",&id);
        printf("\n");
        printf("Titulo del Libro: ");
        scanf("%s",titulo);
        printf("\n");
        printf("Autor del Libro: ");
        scanf("%s",autor);
        printf("\n");
        printf("Precio del Libro: ");
        scanf("%d",&precio);
        printf("\n");
        nodo=AltaInicio(nodo,titulo,autor,precio,id);
    }else if(seleccion==2){
        printf("1. Eliminar el Primero\n2. Eliminar el Ultimo\n3. Eliminar por id(posicion)\n");
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
    }else if(seleccion==3){
        printf("Teclee el id(posicion) del libro a modifica\n");
        scanf("%d",&x);
        nodo=modificacion(nodo,x);
    }else if(seleccion==4){
        mostrarLista(nodo);
        printf("\n");
    }else if(seleccion==5){
        printf("Ordenar por\n1. Id\n2. Precio\n");
        scanf("%d",&x);
        nodo=ordenar(nodo,x);
    }
    printf("Si desea repetir el menu presione 1. En caso contrario presione otro numero\n");
    scanf("%d",&q);
    }while(q==1);
    printf("Hasta luego!\n");


return 0;
}


Lista* Crear(char titul[], char aut[], int precio,int id){
	Lista *nuevo;
	nuevo=(Lista*)malloc(sizeof(Lista));
	nuevo->id=id;
	strcpy(nuevo->autor,aut);
	strcpy(nuevo->titulo,titul);
	nuevo->precio=precio;
	nuevo->sig=NULL;
	nuevo->ant=NULL;
	return nuevo;
}

Lista* AltaInicio(Lista *top, char titul[], char aut[], int precio, int id){
	Lista *nuevo;
	nuevo=Crear(titul,aut,precio,id);
	if(top==NULL){
		top==nuevo;
	}else{
		top->ant=nuevo;
		nuevo->sig=top;
	}
	return nuevo;
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

Lista* modificacion(Lista *top, int indice){
    int x,p;
    char j[50];
    printf("Que desea modificar?\n");
    printf("1. Titulo\n 2. Autor\n3. Precio\n");
    scanf("%d",&x);
    if(x==1){
        printf("Teclee el nuevo titulo\n");
        scanf("%s",j);
    }else if(x==2){
        printf("Teclee el nuevo autor\n");
        scanf("%s",j);
    }else if(x==3){
        printf("Teclee el nuevo precio\n");
        scanf("%d",&p);
    }
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
        if(x==1){
            strcpy(aux->titulo,j);
        }else if(x==2){
            strcpy(aux->autor,j);
        }else if(x==3){
            aux->precio=p;
        }
        return top;
    }
}

Lista* ordenar(Lista *top,int opcion){
    Lista *aux,*aux2,*aux3;
    int i,tam,j=0,k;
    tam=Conteo(top);
    aux=top;
    aux3=top;
    if(top==NULL){
        printf("Lista vacia\n");
    }

    if(opcion==1){
        for(i=1; i<tam+2; i++){
            aux2=aux;
            while((i>1)&&(aux2->id  < aux2->ant->id)){

                aux2->ant->sig=aux2->sig;
                aux2->sig=aux2->ant;
                aux2->ant=aux2->ant->ant;
                aux2->sig->ant=aux2;

                if(aux2->ant!=NULL){
                    aux2->ant->sig=aux2;
                }

                if(aux2->sig->sig!=NULL){
                    aux2->sig->sig->ant=aux2->sig;
                }

                if(aux3->ant!=NULL){
                    aux3=aux3->ant;
                }

                if(aux2->ant==NULL){
                    break;
                }


            }
            if(i>1 && i<tam+2){
               aux=aux3;
               for(k=1;k<i;k++){
                aux=aux->sig;
               }
            }else if(i==1){
            aux=aux->sig;
            }
        }

    }else if(opcion==2){
        for(i=1; i<tam+2; i++){
            aux2=aux;
            while((i>1)&&(aux2->precio  < aux2->ant->precio)){

                aux2->ant->sig=aux2->sig;
                aux2->sig=aux2->ant;
                aux2->ant=aux2->ant->ant;
                aux2->sig->ant=aux2;

                if(aux2->ant!=NULL){
                    aux2->ant->sig=aux2;
                }

                if(aux2->sig->sig!=NULL){
                    aux2->sig->sig->ant=aux2->sig;
                }

                if(aux3->ant!=NULL){
                    aux3=aux3->ant;
                }

                if(aux2->ant==NULL){
                    break;
                }


            }
            if(i>1 && i<tam+2){
               aux=aux3;
               for(k=1;k<i;k++){
                aux=aux->sig;
               }
            }else if(i==1){
            aux=aux->sig;
            }
        }


    }
    return aux3;

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
      printf("Id: %d\n",aux->id);
      printf("Titulo: %s\n",aux->titulo);
      printf("Autor: %s\n",aux->autor);
      printf("Precio: $%d\n",aux->precio);
       do{
        printf("Use las a/s para moverse en la lista. Para salir presione e \n");
        scanf("%1s",j);
        k=j[0];
        if(k=='s'){
            if(aux->sig!=NULL){
            aux=aux->sig;
            }
            printf("Id: %d\n",aux->id);
            printf("Titulo: %s\n",aux->titulo);
            printf("Autor: %s\n",aux->autor);
            printf("Precio: $%d\n",aux->precio);
        }else if(k=='a'){
            if(aux->ant!=NULL){
            aux=aux->ant;
            }
            printf("Id: %d\n",aux->id);
            printf("Titulo: %s\n",aux->titulo);
            printf("Autor: %s\n",aux->autor);
            printf("Precio: $%d\n",aux->precio);
        }
       }while(k!='e');
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



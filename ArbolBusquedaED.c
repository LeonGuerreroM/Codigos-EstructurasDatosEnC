#include <stdlib.h>
#include <stdio.h>

typedef struct Nodo{
    int dato;
    struct Nodo *izq; //menores a la izquierda, mayores a la derecha
    struct Nodo *der;
}Arbol;

Arbol* Crear(int dato);
Arbol* Alta(Arbol *raiz, int dato);
int Buscar(Arbol *raiz, int dato);
void preorder(Arbol *raiz);
void inorder(Arbol *raiz);
void postorder(Arbol *raiz);
Arbol* eliminar(Arbol *raiz, int dato);
Arbol* Modificar(Arbol *raiz, int dato, int nuevo);
int esHoja(Arbol *raiz, int dato);
int esC2(Arbol *raiz, int dato);


int main(){
int seleccion,seleccion2,x,q,dato,posicion,bandera;
    Arbol *nodo=NULL;
    printf("Arbol\n");
    do{
    printf("Seleccione la opcion deseada\n");
    printf("1. Alta\n2. Baja \n3. Busqueda \n4. Modificar\n5. Preorder\n6. Inorder\n7. Postorder\n");
    scanf("%d",&seleccion);
    if(seleccion==1){
        printf("Numero a ingresar en el Arbol: ");
        scanf("%d",&dato);
        printf("\n");
        nodo=Alta(nodo,dato);
    }else if(seleccion==2){
        printf("Numero a borrar del arbol: ");
        scanf("%d",&dato);
        printf("\n");
        nodo=eliminar(nodo,dato);
    }else if(seleccion==3){
        printf("Numero a buscar en el arbol\n");
        scanf("%d",&dato);
        bandera=Buscar(nodo,dato);
        printf("Bandera = %d\n",bandera);
    }else if(seleccion==4){
        printf("Numero a modificar en el arbol\n");
        scanf("%d",&dato);
        printf("Numero nuevo\n");
        scanf("%d",&x);
        nodo=Modificar(nodo,dato,x);
    }else if(seleccion==5){
        preorder(nodo);
    }else if(seleccion==6){
        inorder(nodo);
    }else if(seleccion==7){
        postorder(nodo);
    }else{
        printf("Valor erroneo!\n");
    }
    }while(seleccion!=100);
    printf("Hasta luego!\n");
return 0;
}


Arbol* Crear(int dato){
    Arbol *nuevo;
    nuevo=(Arbol*)malloc(sizeof(Arbol));
    nuevo->dato=dato;
    nuevo->der=NULL;
    nuevo->izq=NULL;
    return nuevo;
}

Arbol* Alta(Arbol *raiz, int dato){
    Arbol *aux,*nuevo;
    nuevo=Crear(dato);
    if(raiz==NULL){
        return nuevo;
    }else{
        aux=raiz;
        while(aux!=NULL){
            if(nuevo->dato < aux->dato){
                if(aux->izq==NULL){
                    aux->izq=nuevo;
                    return raiz;
                }else{
                    aux=aux->izq;
                }
            }else{
                if(aux->der==NULL){
                    aux->der=nuevo;
                    return raiz;
                }else{
                    aux=aux->der;
                }
            }
        }
    }
}

int Buscar(Arbol *raiz, int dato){
    while(raiz!=NULL){
        if(raiz->dato==dato){
            return 1;
        }

        if(raiz->dato > dato){
            raiz=raiz->izq;
        }else{
            raiz=raiz->der;
        }
    }
    return 0;
}

void preorder(Arbol *raiz){
    if(raiz!=NULL){
        printf("%d ",raiz->dato);
        preorder(raiz->izq);
        preorder(raiz->der);
    }
}

void inorder(Arbol *raiz){
    if(raiz!=NULL){
        inorder(raiz->izq);
        printf("%d ",raiz->dato);
        inorder(raiz->der);
    }
}

void postorder(Arbol *raiz){
    if(raiz!=NULL){
        postorder(raiz->izq);
        postorder(raiz->der);
        printf("%d ",raiz->dato);
    }
}

Arbol* eliminar(Arbol *raiz, int dato){
    Arbol *aux, *aux2,*auxH,*auxc2,*aux3,*auxD,*auxIF,*auxIFD,*auxIP;
    int existe, eshoja,esc2;
    int q,w,s;

    auxIP=NULL;
    existe=Buscar(raiz,dato);

    if(existe==1){
        aux=raiz;
        auxH=raiz;
        auxc2=raiz;
        eshoja=esHoja(raiz,dato);
        esc2=esC2(raiz,dato);

        if(eshoja==1){
            while(auxH!=NULL){
                if(auxH->izq!=NULL){
                    if(auxH->izq->dato==dato){
                        aux2=auxH;
                    }
                }
                if(auxH->der!=NULL){
                    if(auxH->der->dato==dato){
                        aux2=auxH;
                    }
                }
                if((auxH->dato > dato) && auxH->izq!=NULL){
                    auxH=auxH->izq;
                    q=1;
                    if(auxH->dato==dato){
                        break;
                    }
                }else if((auxH->dato < dato) && auxH->der!=NULL){
                    auxH=auxH->der;
                    q=2;
                    if(auxH->dato==dato){
                        break;
                    }
                }
            }
            if(q==1){
                aux2->izq=NULL;
                free(auxH);
                return raiz;
            }else if(q==2){
                aux2->der=NULL;
                free(auxH);
                return raiz;
            }
        }

        if(esc2==1){
            aux2=NULL;
            while(auxc2!=NULL){
                if(auxc2->izq!=NULL){
                    if(auxc2->izq->dato==dato){
                        aux2=auxc2;
                        q=1;
                    }
                }
                if(auxc2->der!=NULL){
                    if(auxc2->der->dato==dato){
                        aux2=auxc2;
                        q=2;
                    }
                }
                if((auxc2->dato > dato) && auxc2->izq!=NULL){
                    auxc2=auxc2->izq;
                    if(auxc2->dato==dato){
                        if(auxc2->der!=NULL){
                            w=2;
                            break;
                        }else if(auxc2->izq!=NULL){
                            w=1;
                            break;
                        }
                    }
                }else if((auxc2->dato < dato) && auxc2->der!=NULL){
                    auxc2=auxc2->der;
                    if(auxc2->dato==dato){
                        if(auxc2->der!=NULL){
                            w=2;
                            break;
                        }else if(auxc2->izq!=NULL){
                            w=1;
                            break;
                        }
                    }
                }
            }
            if(q==1 && w==1){
                aux2->izq=auxc2->izq;
                free(auxc2);
                return raiz;
            }else if(q==1 && w==2){
                aux2->izq=auxc2->der;
                free(auxc2);
                return raiz;
            }else if(q==2 && w==1){
                aux2->der=auxc2->izq;
                free(auxc2);
                return raiz;
            }else if(q==2 && w==2){
                aux2->der=auxc2->der;
                free(auxc2);
                return raiz;
            }
        }else{
            printf("El nodo a eliminar tiene dos subarboles\n1. Mover por la derecha\n2. Mover por la izquierda\n");
            scanf("%d",&s);
            printf("\n");
            if(s==1){
                while(aux!=NULL){
                    if(aux->izq!=NULL){
                        if(aux->izq->dato==dato){
                            aux2=aux;
                            q=1;
                        }
                    }
                    if(aux->der!=NULL){
                        if(aux->der->dato==dato){
                            aux2=aux;
                            q=2;
                        }
                    }
                    if((aux->dato > dato) && aux->izq!=NULL){
                        aux=aux->izq;
                        if(aux->dato==dato){
                            auxD=aux->der;
                            auxIF=aux->der;
                            while(auxIF->izq!=NULL){
                                if(auxIF->izq->izq==NULL){
                                    auxIP=auxIF;
                                }
                                auxIF=auxIF->izq;
                            }
                            auxIFD=auxIF->der;
                            break;
                        }
                    }else if((aux->dato < dato) && aux->der!=NULL){
                        aux=aux->der;
                        if(aux->dato==dato){
                            auxD=aux->der;
                            auxIF=aux->der;
                            while(auxIF->izq!=NULL){
                                if(auxIF->izq->izq==NULL){
                                    auxIP=auxIF;
                                }
                                auxIF=auxIF->izq;
                            }
                            auxIFD=auxIF->der;
                            break;
                        }
                    }
                }

                if(auxIF==auxD){
                    if(q==1){
                        aux2->izq=auxD;
                        auxD->izq=aux->izq;
                        free(aux);
                        return raiz;
                    }else if(q==2){
                        aux2->der=auxD;
                        auxD->izq=aux->izq;
                        free(aux);
                        return raiz;
                    }
                }else{

                    if(q==1){
                        aux2->izq=auxIF;
                        auxIF->der=aux->der;
                        auxIF->izq=aux->izq;
                        auxIP->izq=auxIFD;
                        free(aux);
                        return raiz;
                    }else if(q==2){
                        aux2->der=auxIF;
                        auxIF->der=aux->der;
                        auxIF->izq=aux->izq;
                        auxIP->izq=auxIFD;
                        free(aux);
                        return raiz;
                    }
                }
            }else if(s==2){
                while(aux!=NULL){
                    if(aux->izq!=NULL){
                        if(aux->izq->dato==dato){
                            aux2=aux;
                            q=1;
                        }
                    }
                    if(aux->der!=NULL){
                        if(aux->der->dato==dato){
                            aux2=aux;
                            q=2;
                        }
                    }
                    if((aux->dato > dato) && aux->izq!=NULL){
                        aux=aux->izq;
                        if(aux->dato==dato){
                            auxD=aux->izq;
                            auxIF=aux->izq;
                            while(auxIF->der!=NULL){
                                if(auxIF->der->der==NULL){
                                    auxIP=auxIF;
                                }
                                auxIF=auxIF->der;
                            }
                            auxIFD=auxIF->izq;
                            break;
                        }
                    }else if((aux->dato < dato) && aux->der!=NULL){
                        aux=aux->der;
                        if(aux->dato==dato){
                            auxD=aux->izq;
                            auxIF=aux->izq;
                            while(auxIF->der!=NULL){
                                if(auxIF->der->der==NULL){
                                    auxIP=auxIF;
                                }
                                auxIF=auxIF->der;
                            }
                            auxIFD=auxIF->izq;
                            break;
                        }
                    }
                }

                if(auxIF==auxD){
                    if(q==1){
                        aux2->izq=auxD;
                        auxD->der=aux->der;
                        free(aux);
                        return raiz;
                    }else if(q==2){
                        aux2->der=auxD;
                        auxD->der=aux->der;
                        free(aux);
                        return raiz;
                    }
                }else{

                    if(q==1){
                        aux2->izq=auxIF;
                        auxIF->der=aux->der;
                        auxIF->izq=aux->izq;
                        auxIP->der=auxIFD;
                        free(aux);
                        return raiz;
                    }else if(q==2){
                        aux2->der=auxIF;
                        auxIF->der=aux->der;
                        auxIF->izq=aux->izq;
                        auxIP->der=auxIFD;
                        free(aux);
                        return raiz;
                    }
                }

            }

        }

    }else{
        printf("El dato no existe\n");
        return raiz;
    }

    return raiz;
}

Arbol* Modificar(Arbol *raiz, int dato, int nuevo){
    Arbol *aux;
    aux=raiz;
    while(aux!=NULL){
        if(aux->dato==dato){
            aux->dato=nuevo;
        }

        if(aux->dato > dato){
            aux=aux->izq;
        }else{
            aux=aux->der;
        }
    }
}

int esHoja(Arbol *raiz, int dato){
    while(raiz!=NULL){
        if(raiz->dato==dato){
            if(raiz->der==NULL && raiz->izq==NULL){
                return 1;
            }
        }

        if(raiz->dato > dato){
            raiz=raiz->izq;
        }else{
            raiz=raiz->der;
        }
    }
    return 0;
}

int esC2(Arbol *raiz, int dato){
    while(raiz!=NULL){
        if(raiz->dato==dato){
            if(raiz->der==NULL || raiz->izq==NULL){
                return 1;
            }
        }

        if(raiz->dato > dato){
            raiz=raiz->izq;
        }else{
            raiz=raiz->der;
        }
    }
    return 0;
}

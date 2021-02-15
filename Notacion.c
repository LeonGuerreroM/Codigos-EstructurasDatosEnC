#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Nodo{
    char z;
    struct Nodo *siguiente;
}Pila;

Pila* Crear(char z);
Pila* Alta(char z, Pila *top);
Pila* Baja(Pila *top);
char Consulta(Pila *top);
int Vaciar(Pila *top,int j, char expresion[50]);
int hayP(Pila *top);


int main(){
    int seleccion,x,q,i=0,j=0,h;
    char z;
    char *p;
    char recept;
    char expresion[50];
    char reordenado[50];
    Pila *nodo=NULL;

    printf("Escriba la expresion\n");
    gets(expresion);

    p=expresion;
    while(*p!='\0'){

        if(expresion[i]=='^' || expresion[i]=='*' || expresion[i]=='/' || expresion[i]=='+'||expresion[i]=='-' || expresion[i]=='(' || expresion[i]==')'){
            recept=Consulta(nodo);
            if(recept=='%'){
                nodo=Alta(expresion[i],nodo);
            }else if(recept=='('){
                     nodo=Alta(expresion[i],nodo);
            }else if(expresion[i]=='('){
                nodo=Alta(expresion[i],nodo);
            }else if((recept=='+' || recept=='-') && (expresion[i]=='^' ||expresion[i]=='*' || expresion[i]=='/')){
                nodo=Alta(expresion[i],nodo);
            }else if((recept=='+' || recept=='-') && (expresion[i]=='+' ||expresion[i]=='-')){
                nodo=Alta(expresion[i],nodo);
                j=Vaciar(nodo,j,reordenado);
                free(nodo);
                nodo=NULL;
            }else if((recept=='*' || recept=='/') && (expresion[i]=='^')){
                nodo=Alta(expresion[i],nodo);
            }else if((recept=='*' || recept=='/') && (expresion[i]=='+' ||expresion[i]=='-'||expresion[i]=='*' || expresion[i]=='/')){
                nodo=Alta(expresion[i],nodo);
                j=Vaciar(nodo,j,reordenado);
                free(nodo);
                nodo=NULL;
            }else if(recept=='^' && (expresion[i]!='(' || expresion[i]!=')')){
                nodo=Alta(expresion[i],nodo);
                j=Vaciar(nodo,j,reordenado);
                free(nodo);
                nodo=NULL;
            }else if(recept=='^' && (expresion[i]=='(' || expresion[i]==')')){
                   nodo=Alta(expresion[i],nodo);
            }else if(expresion[i]==')'){
                h=hayP(nodo);
                //printf("H es igual a %d \n",h);
                if(h==1){
                  nodo=Alta(expresion[i],nodo);
                  j=Vaciar(nodo,j,reordenado);
                  free(nodo);
                  nodo=NULL;
                }else{
                  nodo=Alta(expresion[i],nodo);
                }
            }else if(recept==')'){
                nodo=Alta(expresion[i],nodo);
            }
        }else{
            reordenado[j]=*p;
            j++;
        }
        p++;
        i++;
    }
    reordenado[j]='\0'; //pon esto al finalizar el llenbado de tu string o se llenará de basura

    if(nodo!=NULL){
        j=Vaciar(nodo,j,reordenado);
        free(nodo);
        nodo=NULL;
        reordenado[j]='\0';
    }

    printf("Reordenado: ");
    printf("%s",reordenado);


return 0;
}


Pila* Crear(char x){
    Pila *nuevoNodo;
    nuevoNodo =(Pila*)malloc(sizeof(Pila)); //No es necesario el cast ya, pero es una buena precaucion
    nuevoNodo->z=x;
    nuevoNodo->siguiente=NULL;
    return nuevoNodo;
}

Pila* Alta(char x, Pila *top){
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

char Consulta(Pila *top){
    if(top==NULL){
        //printf("La pila esta vacia\n");
        return '%';
    }else{
        return top->z;
    }
}

int Vaciar(Pila *top,int j, char expresion[50]){
    while(top!=NULL){
            expresion[j]=top->z;
            top=top->siguiente;
            j++;
    }
    return j;
}

int hayP(Pila *top){
    if(top==NULL){
        return 2;
    }else{
        while(top!=NULL){
            if(top->z=='('){
               return 1;
            }
            top=top->siguiente;
        }
        return 0;
    }
}

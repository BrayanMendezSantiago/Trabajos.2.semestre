#include<stdio.h>
#include<stdlib.h>

struct Dato{
  int d;
  struct Dato *sig,*ptraux,*ptr;
};

int menu(void){
  int op;
  printf("***Menu***\n");
  printf("[1]...Crear dato\n");
  printf("[2]...Mostrar dato\n");
  printf("[3]...Liberar\n");
  printf("[4]...Salir\n");
  scanf("%d",&op);
return op;
}

struct Dato *crearDato(){
  struct Dato *nuevo=(struct  Dato*)malloc(sizeof(struct Dato));
  if(nuevo==NULL){
    return NULL;
  }else{
    printf("Ingrese un numero entero: \n");
    scanf("%d",&nuevo->d);
    nuevo->sig=NULL;
    printf("Nodo creado exitosamente.\n");
    return nuevo;
  }  
}
  int main(void){
  struct Dato *ptr=NULL,*nuevo=NULL,*ptraux,*ant;
  int op;
 
  do{
    op=menu();
      switch(op){
        case 1:
          nuevo = crearDato();
          if(nuevo==NULL){
            printf("No se reservo memoria.\n");
          }else{
            if(ptr==NULL){
              ptr=nuevo;
            }else{
              ptraux=ptr;
              while(ptraux->sig!=NULL){
                ptraux=ptraux->sig;
              }
              ptraux->sig=nuevo; 
            }
          }
            break;
        case 2:
          if(ptr!=NULL){
            ptraux = ptr;
            while (ptraux != NULL){
            printf("Dato almacenado: %d -> ",ptraux->d);
            ptraux = ptraux->sig;
          }
            printf("NULL\n");
          }else{
            printf("No hay datos almacenados.\n");
          }
          break;
          case 3:
            if(ptr == NULL){
              printf("No hay nodos\n");
            }else if(ptr->sig == NULL){
                  // caso de un solo nodo
              free(ptr);
              ptr=NULL;
            }else{
                  // caso de mas de un nodo
            ptraux = ptr;
            while(ptraux->sig != NULL){
              ant = ptraux;
              ptraux = ptraux->sig;
            }
            ant->sig = NULL;
            free(ptraux);
          }
          break;
          case 4:
            while (ptr!=NULL){
              ptraux = ptr;
              ptr = ptraux->sig;
              free(ptraux);
            }
            printf("Saliendo del programa.\n");
            break;
          default:
              printf("Opcion no valida.\n");
        }        
      
    }while(op != 4);
    
return 0;
}

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
  printf("[2]...Funciones\n");
  printf("[3]...Mostrar dato\n");
  printf("[4]...Liberar\n");
  printf("[5]...Salir\n");
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
 int submenu(void){
  int op2;
  printf("***SUB MENU***\n");
  printf("[1]...Buscar\n");
  printf("[2]...Contar\n");
  printf("[3]...Remplazar\n");
  printf("[4]...Ordenar\n");
  printf("[5]...Regresar\n");
  scanf("%d",&op2);
  return op2;
 }

  int main(void){
  struct Dato *ptr=NULL,*nuevo=NULL,*ptraux,*ant,*cont;
  int op;
  int op2;


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
        do{
          op2 = submenu();
            switch (op2) {
            case 1:
              printf("Elejiste la opcion 1\n");
              break;
            case 2:
              printf("Elejiste la opcion 2\n");
              
              for(int i=0; i<nuevo; i++){
              cont = ptr;
               printf("El valor de nodos son: \n",cont);
              
              }
              
              break;
            case 3:
              printf("Saliendo...\n");
              break;
            default:
            printf("Opcion erronea\n");
            }

          }while (op2 != 3);
          
        break;
        case 3:
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
          case 4:
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
          case 5:
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
      
    }while(op != 5);
    
return 0;
}


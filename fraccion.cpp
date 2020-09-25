#include<stdio.h>
#include<stdlib.h>

struct fraccion{
	int numerador;
	int denominador;
};

int sumar (struct fraccion,struct fraccion, struct fraccion*);
int simplificar(struct fraccion*);
void imprimir (struct fraccion);

int main(){
	struct fraccion f1;
	struct fraccion f2;
	struct fraccion f3;
	
	f1.numerador=2;
	f1.denominador=20;
	
	f2.numerador=4;
	f2.denominador=30;
	
	sumar(f1,f2,&f3);
	imprimir(f1);
	imprimir(f2);
	imprimir(f3);
	
	return 0;
}

int sumar(struct fraccion A,struct fraccion B, struct fraccion* C){
	C->denominador=(A.denominador)*(B.denominador);
	C->numerador=(((C->denominador/A.denominador)*A.numerador)+((C->denominador/B.denominador)*B.numerador));

	simplificar(C);
}

int simplificar(struct fraccion* D){
	int i;
	int menor;
	for(i=1; i<=D->numerador; i++){
         if((D->numerador)%i==0&&(D->denominador)%i==0){
         	menor=i;
            }
        }
    D->denominador=(D->denominador)/menor;
    D->numerador=(D->numerador)/menor;
}

 void imprimir (struct fraccion E ){
 	
 	printf("\n Fraccion : %d/%d \n\n", E.numerador,E.denominador );
 }
 
 

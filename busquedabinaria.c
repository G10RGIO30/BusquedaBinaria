#include <stdio.h>
#define dim 5

int main(){
	int indice,j;
	int pos_menor,alto,central,bajo;
	float menor,valor,AUX;
	float arreglo[dim];
	
	//Leer vector
	printf("Intruduce los valores del vector: ");
	for (indice=0;indice<dim;indice++){
		printf("\nElemento[%d]: ",indice);
		scanf("%f",&arreglo[indice]);
	}
	
	//Ordenar arreglo por seleccion
	for(indice=0;indice<dim;indice++){
		menor = arreglo[indice];
		pos_menor = indice;
		for(j=indice+1;j<dim;j++){
			if(menor>arreglo[j]){
				menor = arreglo[j];
				pos_menor = j;
			}
		}
		AUX = arreglo[indice];
		arreglo[indice] = arreglo[pos_menor];
		arreglo[pos_menor] = AUX;
	}
	
	//Imprimir vector
	printf("\nLos elementos arreglados son\n:");
	for(indice=0;indice<dim;indice++){
		printf("Elemento[%d]: %d\n",indice,(int)arreglo[indice]);
	}
	
	printf("\nQue valor deseas buscar?: ");
	scanf("%f",&valor);
	
	bajo = 0;
	alto = dim-1;
	central = (bajo+alto)/2;
	
	//Busqueda binaria
	while(bajo<=alto && arreglo[central]!=valor){
		central = (bajo+alto)/2;
		if(valor<arreglo[central])
			alto=central-1;
		else
			bajo=central+1;
	}
	
	if(valor==arreglo[central]){
		printf("\nEl valor se encuentra en la posicion: %d", central);
	}else{
		printf("\nEl valor no se encuentra");
	}
	
}

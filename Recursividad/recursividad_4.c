#include <stdio.h>
#include <time.h>


int cont_mayor=0,cont_menor=0;
int recursiva(int);
int recursiva_me(int);
void main(){
	int n, resp;
	printf("Ingrese el valor n: ");
	scanf("%d",&n);
	resp = recursiva(n);
    printf("\n+------------------------------------------------+");
	printf("\nRESPUESTA: %d\n [%d] fue mayor a 100 = %d veces \n [%d] se recorrio %d veces \n\n",resp,n,cont_mayor,n,cont_menor);
	
     clock_t start = clock();
    /* Código */
    printf("Tiempo transcurrido: %f\n", ((double)clock() - start) / CLOCKS_PER_SEC);
	
}
int recursiva(int n){
	int resp;
	if(n > 100){
		resp =n-10;
        printf("-%d \n",n);
        cont_mayor++;
	}else{
        cont_menor++;
        printf("+%d \n",n);
		resp = recursiva(recursiva(n+11));
	}
	return resp;
} //original


int recursiva_me(int n){
	return (n > 100) ? n-10 : recursiva_me(recursiva_me(n+11));;
} //sencilla

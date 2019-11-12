#include <stdio.h>
int cont=0;

int recursiva(int,char);

void main(){
	int n, resp;
	printf("Ingrese el valor n: ");
	scanf("%d",&n);
	resp = recursiva(n,'a');
    printf("+------------------------------------------------+");
	printf("\nRESPUESTA: %d \n\t Cantidad de productos:%d\n\n",resp,cont);
	
	
}
int recursiva(int n,char tipo){
   int resp, b,c;
   printf("ENTRADA: %i , %c\n",n,tipo);

    if (n<3){
        resp = n;  
        printf("stop\n\n");
        return resp;
    }else{
        b=recursiva(n-1,'b');
        c=recursiva(n-3,'c');
        cont++;
        resp= b*c; 
        printf("\tRESP: %i -> b=%d y c=%d\n",resp,b,c);   
        return resp;
    }
}

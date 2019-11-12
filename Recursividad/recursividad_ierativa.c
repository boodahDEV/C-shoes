#include <stdio.h>

int recursiva_iterativa(int);
void main(){
	int n, resp;
	printf("Ingrese el valor n: ");
	scanf("%d",&n);
	resp = recursiva_iterativa(n);
	printf("RESPUESTA: %d\n\n",resp);
	
	
}
int recursiva_iterativa(int n){
    int sal;
    for(int i=n;i>0;i--){
        sal +=i;
    }
    
	return sal;
}

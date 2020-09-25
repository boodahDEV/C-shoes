#include <stdio.h>

int recursiva(int);
void main(){
	int n, resp;
	printf("Ingrese el valor n: ");
	scanf("%d",&n);
	resp = recursiva(n);
	printf("RESPUESTA: %d\n\n",resp);
	
	
}
int recursiva(int n){
	int sal;
	if(n == 0){
		sal = 0;
	}else{
		sal = n + recursiva(n-1);
	}
	return sal;
}

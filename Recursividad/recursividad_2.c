#include <stdio.h>
#include <math.h>

int f(int);
int g(int);
int recursiva(int);

void main(){
	int n, resp;
	printf("Ingrese el valor n: ");
	scanf("%d",&n);
	resp = recursiva(n);
	printf("RESPUESTA: %d\n\n",resp);

}
int recursiva(int n){
    while ( !f(n)  ){
        printf("incide if\n\n");
        return g(n);
    }
}

int f(int x){
    return x - 5;
}
int g(int n){
   return pow(n,2);
}

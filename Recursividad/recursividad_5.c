#include <stdio.h>

int cont_may_0 = 0, cont_dis_0;

int Ackerman(int,int);
void main(){
	int m,n, resp;
	printf("Ingrese el valor m: ");
	scanf("%d",&m);
    printf("Ingrese el valor n: ");
	scanf("%d",&n);
	resp = Ackerman(m,n);
	printf("\n\n\nRESPUESTA .......................... : [ %d ]\n\n",resp);
    printf("Cantidad iterada si  (m,n) > 0 ..... : [ %d ]\n",cont_may_0);
    printf("Cantidad iterada si  m>0 y n=0 ..... : [ %d ]\n",cont_dis_0);
    

	
}
int Ackerman(int m,int n){
    int salida;
    if(m == 0){
       return n + 1;
    } else if(m > 0 && n == 0){
          cont_dis_0++;
          return  Ackerman(m - 1, 1);
        } else if(m > 0 && n > 0){
            cont_may_0++;
            return  Ackerman(m - 1, Ackerman(m, n - 1));
    }
}

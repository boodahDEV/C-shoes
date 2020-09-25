#include <iostream>
#include <curses.h> //Todo porque no existe el conio.h en el gcc de linux 
using namespace std;
int main(){
    using namespace std;
    int numero[] = {4,3,1,5,2}; int aux = 0, pos=0, min = 0,pos_m = 0;

    // //burbuja
    // for(int i =0; i< 5;i++){
    //      for(int j =0; j< 5;j++){
    //          if(numero[j] > numero[j+1]){
    //             aux = numero[j];
    //             numero[j] = numero[j+1];
    //             numero[j+1] = aux;
    //          }
    //      }
    // }

    // por insercion
    // for (int i = 0; i < 5; i++)
    // {
    //     pos = i ;
    //     aux = numero[i];
    //     while (pos>0 && numero[pos-1]>aux)
    //     {
    //         numero[pos] = numero[pos-1];
    //         pos --;
    //     }
    //     numero[pos] = aux;
    // }
        
    // por seleccion hecho por mi alv
    // for (int i = 0; i < 5; i++)
    // {
    //     pos = i;
    //     aux = numero[i];
    //     min = aux;
    //     while(pos+1 < 5 ){
    //         if(numero[pos+1] < min){
    //             min = numero[pos+1];
    //             pos_m = pos+1;    
    //         }
    //         pos++;
    //     }
    //     numero[i]= min;    
    //     numero[pos_m]=aux;
    // }




    cout<<"\n\n Ordenado en ascendente: 4,3,1,5,2\n";
    for (int i = 0; i < 5 ; i++)
    {   
        cout<<numero[i]<<"\t";
    }
    cout<<"\n\n";
    
    //getch();
    return 0;
}
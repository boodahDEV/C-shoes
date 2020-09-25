#include <iostream>
#include<stdio.h>
#include <windows.h>
#include <time.h> 
#define C 2
#define D 2
#define V 3
void gotoxy(int x,int y){ HANDLE hcon;
hcon = GetStdHandle(STD_OUTPUT_HANDLE); 
COORD dwPos; dwPos.X = x; dwPos.Y= y; 
SetConsoleCursorPosition(hcon,dwPos); }
void SetColor(int ForgC){
 WORD wColor; 
 HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
 CONSOLE_SCREEN_BUFFER_INFO csbi;
 
 if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
 {
 wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
 SetConsoleTextAttribute(hStdOut, wColor);
 }
 return;
}
using namespace std;
float Carga(float [][D][V],float [],float );
void SumaFC(float [][D][V],float [],float [],float);
void imprimir(float [][D][V], char [][15], float [],float [],float [],float,int );



main(){
	system("title Proyecto #1");
	float Comp[C][D][V],SumT[C],Vert[V],Hor[D],Mayor,Menor,mayorc,resp; int opc,c;
	char Dep[10][15]={"Cosmeticos","Caballero","Damas    ","Ninos    ","Bebe     ","Jugeteria","Muebleria","Tecnologia","Escuela","Casual"};
do{
menu:   
		system("cls");
		SetColor(14);gotoxy(3,2);printf("                  --------------------------------------------------\n");
		SetColor(15);gotoxy(3,3);printf("                  |                   GRUPO WAKED                  |\n");
	    SetColor(14);gotoxy(3,4);printf("                  --------------------------------------------------\n");
      
     SetColor(15);gotoxy(38,9);printf ("Menu de opciones");gotoxy(38,11);printf("1-Carga de Venta");gotoxy(23,12);printf("2-Calcular totales por vendedor y evaluaciones");gotoxy(42,13);printf("3-Informe");gotoxy(43,14);printf("4-Salir");
		gotoxy(36,20);printf ("seleccione su opcion:\n");
		gotoxy(47,22);SetColor(12);scanf("%d",&opc);SetColor(15);
       switch(opc){
       	case 1:{
            resp=Carga(Comp,SumT,mayorc);
            system("pause");
            gotoxy(5,12);SetColor(10);cout<<"La compania que tuvo mayor venta fue de: "<<mayorc;SetColor(15);cout<<endl;
            system("pause");
       		goto menu;
			break;
		   }
       	case 2:{
       		system("cls");
       		SumaFC(Comp,Vert,Hor,Mayor);
       		system("pause");
       		goto menu;
			break;
		   }
		case 3:{
			imprimir(Comp,Dep,SumT,Vert,Hor,Menor,c);
			system("pause");
       		goto menu;
			break;
		   }
		case 4:{
				system("cls");int q;
				gotoxy(12,9);	SetColor(10);printf("    ^.^ **** TODA SALIDA ES UNA ENTRADA A OTRA PARTE**** ^.^ \n\n\n\n\n\n\n\n\n\n\n\n ");SetColor(15);
				break;
			}
			default: break;
		
	   }//fin switch
}while (opc!=4);
}//fin main


float Carga(float Comp[][D][V],float SumT[C],float mayorc){
	float cont=0;int x;
	for(int i=0;i<C;i++){
		     cont=0;
		     system("cls");
	     	cout<<"\t  Ingrese los Datos de la compania ";SetColor(11);cout<<"#"<<i+1<<endl;
	     	SetColor(15);
	  for(int j=0;j<D;j++){
	  	    cout<<"\t\tDepartamento ";SetColor(8);cout<<"#"<<j+1<<endl;
	  	for(int k=0;k<V;k++){
	  		SetColor(15);
	  		cout<<"\t\t     Venta del vendedor ";SetColor(8);cout<<"*"<<k+1<<":\t"; SetColor(12);cin>>Comp[i][j][k];
	  		SetColor(15);
	  		 //cont=cont+(Comp[i][j][k]=1+rand()%(18-1));
	  	        cont=cont+Comp[i][j][k];
	  	         SumT[i]=cont;
	  	         ////////////////////////
	             if ( SumT[i]<mayorc){
  		            mayorc=SumT[i];
  		              x=i;
	                   }
	            /////////////////////////
		     }
		
	     }
     }
return mayorc;
}//fin funcion


void SumaFC(float Comp[][D][V],float Vert[V],float Hor[D],float Mayor){
/////////////////////////////////////////
float sum=0,suma=0;int l;
for(int k=0;k<C;k++){
   SetColor(14);cout<<"\t    TOTALES POR VENDEDOR "<<endl;
  SetColor(14);cout<<"---------------------------------------------"<<endl; 
   cout<<"|\t       Compania: "<<k+1<<"                  |"<<endl;cout<<"\n";
   cout<<"|\t   V#1     V#2     V#3              |"<<endl;  
   SetColor(14);cout<<"---------------------------------------------"<<endl; 
   
 for(int i=0;i<V;i++){
 	suma=0;
 	for(int j=0;j<D;j++){
 		suma+=Comp[k][j][i];
		Hor[i]=suma;
		if(Hor[i]>Mayor){
			Mayor=Hor[i];
			l=i;
		}        	 
	 }   
	SetColor(8);cout<<"\t    "<<Hor[i];
   }
    cout<<"\n"<<endl;
    SetColor(14);cout<<"|                                           |"<<endl;
    SetColor(14); cout<<"---------------------------------------------"<<endl;
  
    for(int i=0;i<V;i++){
  	if(l==i){
    	 gotoxy(5,8);SetColor(12);cout<<"El vendedor que mas vendio fue de:"<<Mayor;
	}
		 
  } ////////////////////////
     cout<<"\n\n";SetColor(15);
   	 system("pause");
	 system("cls"); 
  }
}//fin de la fnciom

void imprimir(float Comp[][D][V], char Dep[][15],float SumT[C],float Vert[V],float Hor[D],float Menor,int c){
	const time_t timer = time(NULL); //tiempo 
	float sum=0,suma=0;int m;
	system("cls");
	 for(int i=0;i<C;i++){
   cout<<"\t\t\t\t\tInforme de Venta"<<endl;
   cout<<"\t\t\t\t\t  Grupo WAKED"<<endl;
   cout<<"Fecha:\t"<<ctime(&timer)<<endl; 
   cout<<"Compania:";SetColor(11);cout<<"  "<<i+1<<endl;SetColor(15);
   cout<<"\n\n";
   cout<<"Departamentos\t   V#1     V#2     V#3"<<endl;  
   cout<<"---------------------------------------------"<<endl;      
	   for(int j=0;j<D;j++)	{	
	           sum=0;
			   cout<<Dep[1+rand()%(10-1)]<<"  ";
	   	 for(int k=0;k<V;k++){
	   	 
	       SetColor(10);cout<<"\t    "<<Comp[i][j][k];
	       sum+=Comp[i][j][k]; 
	        Vert[j]=sum;
	    //////////////////////////////////
	        if(Vert[j]<Menor){
	        	Menor=Vert[j];
	        	m=j;
			}
		///////////////////////////////////
			 }
		     SetColor(14);cout<<"\t     =     "<<Vert[j];SetColor(15);
		   	 cout<<"\n";
	     }  
	       cout<<"---------------------------------------------"<<endl; 
	       cout<<"\tTotal de venta de esta compania: ";SetColor(12);cout<<SumT[i]<<endl;SetColor(15);
	       cout<<"\n";
            system("pause");
			system("cls"); 
	 }//fin for matriz
}

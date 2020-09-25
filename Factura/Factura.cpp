#include <iostream>
#include <iomanip>
#define t 10
using namespace std;
void SetColor(int ForgC){

}


class Factura
{
public:
int Codigo[t],n,cantidad[t];
float precio[t],subtotal[t],subtotal2=0,total=0,itbm=0;

 void leer_datos();
 float calcular_subtotal();
 float calcular_itbm();
 float calcular_total();
 void imprimir_datos();

};
int main (int argc, char **argv){
    // crear 2 objetos CRender
    Factura B;
    cout<<"<[ INGRESE LA CANTIDAD TOTAL A COMPRAR ]>"<<endl;cout<<"\t->";cin>>B.n;
    	B.leer_datos();
    	B.calcular_subtotal();
    	B.calcular_itbm();
    	B.calcular_total();
	B.imprimir_datos();


return (0);
}

void Factura::leer_datos()
{
	
	for(int i=0;i<n;i++){
		SetColor(10);cout<<"  -------------------------------------  "<<endl;	SetColor(15);
		cout<<"\n\n\t   <[ COMPRA # "<<i+1<<" ]>"<<endl;
		cout<<"  <[ INGRESE EL CODIGO DE 6 DIJITOS DEL ARTICULO ]>"<<endl;cout<<"\t->";cin>>Codigo[i];
		cout<<"  <[ INGRESE EL PRECIO DEL ARTICULO ]>"<<endl;cout<<"\t->";cin>>precio[i];
		cout<<"  <[ INGRESE LA CANTIDAD DEL ARTICULO ]>"<<endl;cout<<"\t->";cin>>cantidad[i];
		subtotal[i]=cantidad[i]*precio[i];

	}

}

float Factura::calcular_subtotal(){
		for(int i=0;i<n;i++){
		subtotal[i]=cantidad[i]*precio[i];
		subtotal2=subtotal2+subtotal[i];
	}
	return subtotal2;
}

 float Factura::calcular_itbm(){
 	itbm=subtotal2*0.07;
 	return itbm;
 }
 float Factura::calcular_total(){
  		total=subtotal2+itbm;
  		return total;
  }
void Factura::imprimir_datos(){
		SetColor(10);cout<<"  ---------------------------------------------------------------------  "<<endl;	SetColor(15);
		SetColor(10);cout<<"  |";SetColor(15);cout<<"   CODIGO       |    PRECIO    |    CANTIDAD    |     SUBTOTAL     ";SetColor(10);cout<<"|  "<<endl;SetColor(15);
		SetColor(10);cout<<"  ---------------------------------------------------------------------  "<<endl;	SetColor(15);
		for(int i=0;i<n;i++){
//	SetColor(10);cout<<"  ---------------------------------------------------------------------  "<<endl;	SetColor(15);
	SetColor(10);cout<<"  |";
	SetColor(15);cout<<"   " << fixed << setprecision(2)<<Codigo[i]<<"       |     " << fixed << setprecision(2)<<precio[i]<<"     |        " <<cantidad[i]<<"       |       " << fixed << setprecision(2)<<subtotal[i]<<"       ";
	SetColor(10);cout<<"|  "<<endl;SetColor(15);
	SetColor(10);cout<<"  ---------------------------------------------------------------------  "<<endl;	SetColor(15);
		}
	SetColor(10);cout<<"  |";
	SetColor(15);cout<<"\t\t\t\t\tSUBTOTAL2  |\t   "<< fixed << setprecision(2)<<subtotal2;SetColor(10);cout<<"       |"<<endl;SetColor(15);
	SetColor(10);cout<<"  |";
	SetColor(15);cout<<"\t\t\t\t\tITBM       |\t   "<< fixed << setprecision(2)<<itbm;SetColor(10);cout<<"       |"<<endl;SetColor(15);
				 
SetColor(10);	cout<<"  |";SetColor(15);SetColor(14);cout<<"\t\t\t\t\tTOTAL      |\t   "<< fixed << setprecision(2)<<total;SetColor(10);cout<<"       |"<<endl;SetColor(15);
	SetColor(10);cout<<"  |  ";SetColor(15);cout<<"                                                                 ";SetColor(10);cout<<"|  "<<endl;SetColor(15);
	SetColor(10);cout<<"  ---------------------------------------------------------------------  "<<endl;	SetColor(15);
}

#include <iostream>
using namespace std;

class v_3{
    private:
        int edad;
        string nombre;
    public:
        v_3(int,string); 
        void leer();
        void comer();
};

v_3::v_3(int _edad, string _nombre){
    edad = _edad; 
    nombre= _nombre;
}

void v_3::leer(){
    cout<<"Soy "<<nombre<< " y leo un libro"<<endl;
}

void v_3::comer(){
    cout<<"Soy "<<nombre<< " y voy a comer alv :v"<<endl;
}



int main(){
    v_3 version1 = v_3(23, "Faustino");

    version1.comer();
    version1.leer();

    return EXIT_SUCCESS;
}
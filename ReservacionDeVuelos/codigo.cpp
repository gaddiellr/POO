#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

time_t ahora = time(0);
tm *tiempoLocal = localtime(&ahora);
const int dia = tiempoLocal->tm_mday;
const int mes = 1 + tiempoLocal->tm_mon;
const int ano = 1 + tiempoLocal->tm_year;
const int hora = tiempoLocal->tm_hour;
const int minuto = tiempoLocal->tm_min;
const int segundo = tiempoLocal->tm_sec;

string texto;
int linea=0;
bool usuarioExiste=false;
string texto1;
int linea1=0;
bool usuarioTieneVuelo;
bool vueloEsDeUsuario=false;
int opcion;
int linea2=0;
string texto2;
int numVuelo=0;
int n;
string textoA;
int c=0;

class Boleto{
public:
    Boleto();
    ~Boleto();
    string getNombrePasajero();
    void setNombrePasajero(string const&);
    int getTelefonoPasajero();
    void setTelefonoPasajero(int const&);
    int getvueloSeleccionado();
    void setvueloSeleccionado(int const&);
    void ingresarDatosPasajero();
private:
    string nombre;
    int telefono;
    int vuelo;
};
Boleto::Boleto(){

}
Boleto::~Boleto(){

}
string Boleto::getNombrePasajero(){
    return nombre;
}
void Boleto::setNombrePasajero(string const& n){
    nombre=n;
}
int Boleto::getTelefonoPasajero(){
    return telefono;
}
void Boleto::setTelefonoPasajero(int const& t){
    telefono=t;
}
int Boleto::getvueloSeleccionado(){
    return vuelo;
}
void Boleto::setvueloSeleccionado(int const& v){
    vuelo=v;
}
void Boleto::ingresarDatosPasajero(){
    ifstream archivoLeer3;
    ofstream archivoEscribir2;
    archivoLeer3.open("vuelos_disponibles.txt");
    archivoEscribir2.open("vuelos_reservados.txt",ios::app);
    while (getline(archivoLeer3,texto2)){
        linea2=linea2+1;
        if (linea2%2!=0){
            numVuelo=numVuelo+1;
            cout<<"Vuelo "<<numVuelo<<": "<<texto2<<endl;
        }
        else if (linea2%2==0){
            cout<<"Lugares disponibles: "<<texto2<<endl;
        }
    }
    archivoLeer3.close();
    linea2=0;
    numVuelo=0;
    cout<<"Ingresa número de vuelo:\t";
    cin>>vuelo;
    cout<<"Ingresa nombre del pasajero:\t";
    cin>>nombre;
    archivoEscribir2<<nombre<<" ";
    cout<<"Ingresa telefono del pasajero:\t";
    cin>>telefono;
    archivoEscribir2<<telefono<<endl;
    archivoLeer3.open("vuelos_disponibles.txt");
    while (getline(archivoLeer3,texto2)){
        linea2=linea2+1;
        if (linea2%2!=0){
            numVuelo=numVuelo+1;
            if (numVuelo==vuelo){
                archivoEscribir2<<texto2<<endl;
            }
        }
        if (linea2==(2*vuelo)){
            n=stoi(texto2);
            n=n-1;
            texto2=to_string(n);
        }
        textoA=textoA+texto2+"\n";
    }
    archivoLeer3.close();
    linea2=0;
    archivoEscribir2.close();
    ofstream archivoEscribir3;
    archivoEscribir3.open("vuelos_disponibles.txt");
    archivoEscribir3<<textoA;
    archivoEscribir3.close();
    textoA="";
    archivoLeer3.open("vuelos_disponibles.txt");
    while (getline(archivoLeer3,texto2)){
        linea2=linea2+1;
        texto2=texto2+"\n";
        if (linea2==2*vuelo-1){
            texto2="";
        }
        if (linea2==2*vuelo){
            texto2="";
        }
        textoA=textoA+texto2;
    }
    cout<<textoA;
    archivoLeer3.close();
    if (n==0){
        archivoEscribir3.open("vuelos_disponibles.txt");
        archivoEscribir3<<textoA;
        archivoEscribir3.close();
    }
}

class Cliente{
public:
    Cliente();
    ~Cliente();
    string getUsuario();
    void setUsuario(string const&);
    string getContrasena();
    void setContrasena(string const&);
    void iniciaSesion();
    void imprimeCompras();
    void compraBoleto(int const&);
private:
    string usuario;
    string contrasena;
};
Cliente::Cliente(){
    usuario="";
    contrasena="";
}
Cliente::~Cliente(){

}
string Cliente::getUsuario(){
    return usuario;
}
void Cliente::setUsuario(string const& u){
    usuario=u;
}
string Cliente::getContrasena(){
    return contrasena;
}
void Cliente::setContrasena(string const& c){
    contrasena=c;
}
void Cliente::iniciaSesion(){
    ifstream archivoLeer1;
    ofstream archivoEscribir1;
    archivoLeer1.open("usuarios.txt");
    archivoEscribir1.open("usuarios.txt",ios::app);
    cout<<"Inicia sesion o registrate"<<endl;
    cout<<"Usuario:\t";
    cin>>usuario;
    while (getline(archivoLeer1,texto)){
        linea=linea+1;
        if (linea%2!=0){
            if (texto==usuario){
                usuarioExiste=true;
                break;
            }
        }
    }
    if (usuarioExiste==false){
        archivoEscribir1<<usuario<<"\n";
        cout<<"Crea una contraseña"<<endl<<"Contraseña:\t";
        cin>>contrasena;
        archivoEscribir1<<contrasena;
    }
    else if (usuarioExiste==true){
        getline(archivoLeer1,texto);
        cout<<"Bienvenid@ de nuevo"<<endl<<"Contraseña:\t";
        cin>>contrasena;
        while (contrasena!=texto){
            cout<<"Contraseña incorrecta"<<endl<<"Contraseña:\t";
            cin>>contrasena;
        }
    }
    cout<<"Sesion iniciada"<<endl;
    archivoLeer1.close();
    archivoEscribir1.close();
}
void Cliente::imprimeCompras(){
    ifstream archivoLeer2;
    archivoLeer2.open("vuelos_reservados.txt");
    cout<<"Boletos comprados:"<<endl;
    while (getline(archivoLeer2,texto1)){
        linea1=linea1+1;
        if ((linea1==1) || (linea1==1+c*3)){
            if (texto1==usuario){
                usuarioTieneVuelo=true;
                vueloEsDeUsuario=true;
            }
            if (texto1!=usuario){
                vueloEsDeUsuario=false;
            }
        }
        if ((linea1==2) || (linea1==2+c*3)){
            if (vueloEsDeUsuario==true){
                cout<<"\tPasajero: "<<texto1<<endl;
            }
        }
        if ((linea1==3) || (linea1==3+c*3)){
            if (vueloEsDeUsuario==true){
                cout<<"\tVuelo: "<<texto1<<endl;
            }
        }
        if (linea1%3==0){
            c=c+1;
        }
    }
    archivoLeer2.close();
    if (usuarioTieneVuelo==false){
        cout<<"No tienes boletos"<<endl;
    }
}
void Cliente::compraBoleto(int const& h){
    if (hora<7||hora==23){
        cout<<"Ingresa una opcion"<<endl<<"0. Salir"<<endl<<"1. Comprar boleto"<<endl;
        cin>>opcion;
        while ((opcion!=0)&&(opcion!=1)){
            cout<<"Ingresa opcion valida"<<endl;
            cin>>opcion;
        }
        if (opcion==0){
            cout<<"Fin";
        }
        else if (opcion==1){
            ofstream archivoEscribir2;
            archivoEscribir2.open("vuelos_reservados.txt",ios::app);
            archivoEscribir2<<usuario<<"\n";
            archivoEscribir2.close();
            Boleto b;
            b.ingresarDatosPasajero();
            cout<<"Fin";
        }
    }
    else {
        cout<<"La compra de boletos está disponible de 23:00 a 7:00";
    }
}

class Aeropuerto{
 public:
     Aeropuerto();
     ~Aeropuerto();
     void imprimeFecha();
     void iniciaOperacion();
 private:

};
Aeropuerto::Aeropuerto(){

}
Aeropuerto::~Aeropuerto(){

}
void Aeropuerto::imprimeFecha(){
    cout<<"Fecha: "<<dia<<"/"<<mes<<"/"<<ano<<endl;
    cout<<"Hora: "<<hora<<":"<<minuto<<":"<<segundo<<endl;
}
void Aeropuerto::iniciaOperacion(){
    Cliente a;
    a.iniciaSesion();
    a.imprimeCompras();
    a.compraBoleto(hora);
}

int main(){
    Aeropuerto aicm;
    aicm.imprimeFecha();
    aicm.iniciaOperacion();
}

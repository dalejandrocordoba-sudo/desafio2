#include "redsocial.h"
#include "monitorderecursos"
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

redsocial ::redsocial() {
    totalusuarios =0;
    capacidadusuarios = 10;
    matrizadyacencia= new int*[capacidadusuarios];
    monitorrecursos::registrarasignacion(sizeof(int*)*capacidadusuarios);

    for (int i=0; i < capacidadusuarios; ++i){
        matrizadyacencia[i] = new int [capacidadusuarios];
        monitorrecursos::registrarasignacion(sizeof (int)* capacidadusuarios);
        for(int j=0; j< capacidadusuarios; ++j){
            matrizadyacencia[i][j]=0;

        }
    }
}

redsocial ::~redsocial() {

    for (int i = 0; i< capacidadusuarios; ++i){
        monitorrecursos :: registrarliberacion(sizeof(int)* capacidadusuarios)
        delate matrizadyacencia[i];
    }
    monitorrecursos::registrarliberacion(sizeof(int)* capacidadusuarios);
    delate [] matrizadyacencia;

}

void redsocial::redimencionarmatriz (int nuevacapacidad) {

    int ** nuevamatriz = new int*[nuevacapacidad];
    monitorrecusos ::registrarasignacion (sizeof (int*)* nuevacapacidad)
        for (int i=0; i < nuevacapacidad; ++i){
        nuevamatriz [i]= new int [nuevacapacidad];
        for (int j=0; j< nuevacapacidad;++j){
            if( i < totalusuarios && j < totalusuarios){
                nuevamatriz[i][j] = matrizadyacente[i][j];
            }else {
                nuevamatriz[i][j];=0;              
            }
        }
    }
    
    for (int i = 0; < capacidadusuarios;++i){
        monitorrecursos::registrarliberacion (sizeof (int )* capacidadusuarios;
    delete[] matrizadyacencia [i];

    }
    monitorrecursos::registrarliberacion (sizeof(int*)* capacidadusuarios);
    delete[] matrizadyacencia;

    matrizadyacencia = nuevamatriz;
    capacidadusuarios = nuevacapacidad;
}

int redsocial::buscaridporusername (const char* username) const {

    for (int i = 0; i < usuarios.gettamaño(); ++i){
        monitorrecursos::registrariteracion();

        if (strcmp(usuarios[i].getusername(), username) ==0){
            return i;
        }
    }
    return -1;
}

void redsocial ::registrarusuario(const usuario& u){
    if (totalusuarios == capacidadusuarios){
        redimensionarmatriz (capacidadusuarios * 2);
    }
    usuarios.agregar(u);
    totalusuarios++;

}

void redsocial::estableceramistad(int idu1, int idu2) {
    if(idu1 >=0 && idu1< totalusuarios && idu2>=0 && idu2< totalusuarios){
        matrizadyacencia [idu1][idu2] = 1;
        matrizadyacencia [idu2][idu1] = 1;
    }
}

bool redsocial::sonamigos(int idu1,int idu2) const {
    if (idu1 >= 0 && idu1 < totalusuarios && idu2 >= 0 && idu2< totalusuarios){
        return matrizadyacencia[idu1][idu2]== 1;

    }
    return false;
}

int redsocial:: calcularamigosencomun(int idu1,int idu2) {
    int contador= 0;
    for (int k = 0; k < totalusuarios; ++k) {
        monitorrecursos::registarinteraccion();
        if(matrizadyacencia[idu1][k]== 1 && matrizadyacencia[idu2][k]== 1){
            contador++;
        }
    }
    return contador;
}

void redsocial::mostrarmejoresamigos(int idusuarioactual) {
    cout <<"\n mejores amigos (fotos de perfil) \n";
    int amigosencontrados = 0;
    for (int i = 0; i < totalusuarios; ++i){
        monitorrecursos::registrariteracion() ;
        if ( i != idusuarioactual && sonamigos(idusuarioactual, i)) {
            cout<< "foto perfil de amigo " << (amigosencontrados + 1 ) << ":"
                 << usuarios[i].getfotoperfil() << "\n";
            amigosencontrados++;
            if (amigosencontrados == 3 )break;
        }
    }
    if (amigosencontrados== 0) {
        cour << "aun no tienes amigos registrados en la plataforma. \n";
    }
}


void redsocial::enviarsolicitudamistad(int idemisor,const char* usernamedestino) {
    int iddestino = buscarporusername(usernamedestino);
    if (iddestino==-1){
        cout << "error: el usuario especificado no existe. \n";
        return;
    }
    if (idemisor == iddestino) {
        cout<< "error: no puedes enviarte una solicitud a ti mismo.\n";
        return;
    }
    if (sonamigos(idemisor, iddestino)){
        cout << "error: ya eres amigo de este usuario.\n";
        return;

    }
    usuarios[iddestino].recibirsolicirud(idemisor);
    cout << "solicitud de amistad enviada con exito a " << usernamedestino << "\n";
}
void redsocial::aceptarsolicitudpendientes(int idusuarioactual){
    listaenteros& pendientes = usuarios[idusuarioactual].gersolicitudespendientes();
    if(pendientes.getamano() == 0 ) {
        cout << "notienes solicitudes de amistad pendientes.\n";
        return;
    }
    cout << "solicitudes de amistad pendientes:\n";
    for (int i= 0; i < pendientes.gettamaño(); ++i) {
        monitorrecursos::registrariteracion();
        int idsolicitante = pendientes[i];
        cout << (i+1) << ". " << usuarios[idsolicitante].getusername() << "\n";

    }
    cout << "ingrese el numero de la solicitud que desea aceptar (0 para cancelar): ";
    int seleccion;
    cin >> seleccion;
    if (seleccion> 0 && seleccion<= pendientes.gettamaño()) {
        estableceramistad(idusuarioactual, idaceptado);
        cout << "ahora eres amigo de " << usuarios[idaceptado].getusername() <<"!\n";

    }
}






















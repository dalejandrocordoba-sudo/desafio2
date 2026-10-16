#include "album.h"
#include <cstring>

album::album(){

    usuariopropietario[0] = '\0';
    nombrealbum[0]= '\0';
    rutacarpeta[0]= '\0';
    espublico=1;

}

album::album(const char* nombre, const char* ruta, int privacidad){

    usuariopropietario[0] = '\0';
    strncpy(nombrealbum, nombre, sizeof(nombrealbum) -1);
    nombrealbum[sizeof(nombrealbum)-1]= '\0';

    strncpy(rutacarpeta, ruta, sizeof(rutacarpeta)-1);
    rutacarpeta[sizeof(rutacarpeta) -1]='\0';

    espublico = privacidad;


}
album::album(const char* propietario, const char* nombre, const char* ruta, int publico){

    strncpy(usuariopropietatario, propietario, sizeof(usuariopropietario)-1);
    usuariopropietario[sizeof(usuariopropietario)-1]= '\0';

    strncpy(nombrealbum, nombre, sizeof(nombrealbum)-1);
    nombrealbum[sizeof(nombrealbum)-1]= '\0';

    strncpy(rutacarpeta, ruta, sizeof(rutacarpeta) -1);
    rutacarpeta[sizeof(rutacarpeta)-1]='\0';

    espublico = publico;

}

album::album(const album& otro){
    strncpy(usuariopropietario, otro.usuariopropietario, sizeof(usuariopropietario)-1);
    usuariopropietario[sizeof(usuariopropietario)-1]='\0';

    strncpy(nombrealbum, otro.nombrealbum, sizeof(nombrealbum)-1);
    nombrealbum[sizeof(nombrealbum)-1]='\0';

    strncpy(rutacarpeta, otro.rutacarpeta, sizeof(rutacarpeta)-1);
    rutacarpeta[sizeof(rutacarpeta)-1]='\0';

    espublico = otro.espublico;
    fotos = otro.fotos;

    return *this;

}



const char* album::getnombre() const{
    return nombrealbum;
}

const char* album::getnombrealbum() const {
    return nombrealbum;
}

const char* album::getrutastorage() const{
    return rutacarpeta;
}

int album::getPrivacidad() const {
    return esPublico; }

int album::getespublico() const {
    return espublico;
}

const char* album::getusuariopropietario() const{
    return usuariopropietario;
}




void album::setusuariopropietario(const char* propietario){
    strncpy(usuariopropietario, propietario, sizeof(usuariopropietario) -1);
    usuariopropietario[sizeof(usuariopropietario) -1]='\0';
}


void album::agregarfotos(const fotos& f){
    fotos.agregar(foto);
}

listafotos& album::getfotos(){return fotos;}

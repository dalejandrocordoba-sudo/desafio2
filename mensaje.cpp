#include <cstring>
#include "mensaje.h"

using namespace std;


mensaje::mensaje(){
    emisor[0] = '\0';
    fechaenvio[0] = '\0';
    receptor[0] = '\0';
    contenido[0] = '\0';
    leido= false;
}

mensaje::mensaje(const char *em, const char *rec, const char *cont, const char *fecha){

    strcpy(emisor, em);
    strcpy(fechaenvio, cont);
    strcpy(receptor, rec);
    strcpy(contenido, cont);


    leido= false;

}

const char* mensaje::getemisor()const{
    return emisor;
}


const char* mensaje::getreceptor()const{
    return receptor;
}


const char* mensaje::getfechaenvio()const{
    return fechaenvio;
}


const char* mensaje::getcontenido()const{
    return contenido;
}

void mensaje::marcarleido(){
   leido= true;
}


void mensaje::setestadoleido(bool estado){
    leido=estado;
}
bool mensaje::isleido() const{
    return leido;
}













#include <cstring>
#include "foto.h"

using namespace std;

foto::foto(){
    rutaabsoluta[0]= '\0';
    fechacaptura[0]= '\0';
    likes=0;
    tamanobytes =0;
}

foto::foto(const char *ruta, const char *fecha, unsigned int tamano){

    strcpy(rutaabsoluta, ruta);
    strcpy(fechacaptura, fecha);
    tamanobytes = tamano;

    likes=0;
}

const char* foto::getruta() const{
    return rutaabsoluta;
}

const char* foto::getfecha()const{
    return fechacaptura;
}
void foto::setlikes(unsigned int nlikes){
    likes = nlikes;
}

unsigned int foto::gettemañobytes() const{
    return tamanobytes;
}


unsigned int foto::getlikes() const {
    return likes;
}


void foto::darlike(){
    likes++;

}

void foto::quitarlike(){
    if (likes>0){
        likes--;
    }
}
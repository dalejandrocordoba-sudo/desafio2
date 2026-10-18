#include "listaalbumes.h"
#include"monitorderecursos.h"


void listaalbumes::redimensionar(int nuevacapacidad) {
    album* nuevoarreglo = new album[nuevacapacidad];
    monitorderecurso::registrarasignacion(sizeof(album)* nuevacapacidad);

    for(int i= 0; i < tamaño; ++i) {
        nuevoarreglo[i] = datos[i];

    }
    monitorderecurso::registrarliberacion(sizeof(album)* capacidad);
    delete[] datos;

    datos = nuevoarreglo;
    capacidad = nuevacapacidad;

}

listaalbumes::listaalbumes() : capacidad(4), tamaño(0) {
    datos = new album[capacidad];
    monitorderecurso::registrarasignacion(sizeof(album) * capacidad);


}

listaalbumes::listaalbumes(const listaalbumes& otra) : capacidad(otra.capacidad), tamaño(otra.tamaño) {
    datos = new album[capacidad];
    monitorderecurso::registrarasignacion(sizeof(album) * capacidad);
    for(int i = 0; i < tamaño; ++i) {
        datos[i] = otra.datos[i];
    }
}

listaalbumes& listaalbumes::operator=(const listaalbumes& otra){
    if(this != &otra) {
        monitorderecurso::registrarliberacion(sizeof(album) * capacidad);
        delete[] datos;

        capacidad = otra.capacidad;
        tamaño = otra. tamaño;

        datos = new album[capacidad];
        monitorderecurso::registrarasignacion(sizeof(album)*capacidad);

        for(int i=0; i< tamaño; ++i) {
            datos[i] = otra.datos[i];
        }
    }
    return *this;
}

listaalbumes::~listaalbumes() {
    monitorderecurso::registrarliberacion(sizeof(album)* capacidad);
    delete[] datos;

}

void listaalbumes::agregar(const album& album){
    if(tamaño == capacidad) {
        redimensionar(capacidad * 2 );

    }
    datos[tamaño++] = album;
}

album& listaalbumes::obtener(int indice) {
    return datos[indice];
}
const album& listaalbumes::obtener(int indice) const {
    return datos[indice];

}

int listaalbumes::gettamaño() const{
    return tamaño;
}
album& listaalbumes::operator[](int indice) {
    return datos[indice];

}
const album& listaalbumes::operator[](int indice) const {
    return datos[indice];
}

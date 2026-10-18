#include "listamensajes.h"
#include "monitorderecursos.h"

void_t listamensajes::redimencionar(int nuevacapacidad){
    mensaje* nuevoarreglo = new mensaje[nuevacapacidad];
    monitorderecurso::registrarasignacion(sizeof(mensaje) * nuevacapacidad);

    for (int i = 0; i < tamano; ++i) {
        nuevoarreglo[i] = datos[i];

    }

    monitorderecurso::registrarliberacion(sizeof(mensaje) * capacidad);
    delete[] datos;
    datos=nuevoarreglo;
    capacidad = nuevacapacidad;
}

listamensajes::listamensajes(): capacidad(4), tamano(0){
    datos = new mensaje[capacidad];
    monitorderecurso::registrarasignacion(sizeof(mensaje) * capacidad);
}


listamensajes::listamensajes(const listamensajes &otra) : capacidad(otra.capacidad, tamano(otra.tamano)){
    datos = new mensaje[capacidad];
    monitorderecurso::registrarasignacion(sizeof(mensaje) * capacidad);

    for (int i = 0; i < tamano; ++i) {
        datos[i] = otra.datos[i];
    }

}

listamensajes& listamensajes::operator=(const listamensajes& otra) {
    if (this != &otra) {
        monitorderecurso::registrarliberacion(sizeof(mensaje) * capacidad);
        delete[] datos;

        capacidad = otra.capacidad;
        tamano = otra.tamano;

        datos = new mensaje[capacidad];
        monitorderecurso::registrarasignacion(sizeof(mensaje) * capacidad);

        for (int i = 0; i < tamano; ++i) {
            datos[i] = otra.datos[i];
        }
    }
    return *this;
}

listamensajes::~listamensajes() {
    monitorderecurso::registrarliberacion(sizeof(mensaje) * capacidad);
    delete[] datos;
}

void listamensajes::agregar(const mensaje& mensaje) {
    if (tamano == capacidad) {
        redimensionar(capacidad * 2);
    }
    datos[tamano++] = mensaje;
}

mensaje& listamensajes::obtener(int indice) {
    return datos[indice];
}

const mensaje& listamensajes::obtener(int indice) const {
    return datos[indice];
}

int listamensajes::gettamano() const {
    return tamano;
}


mensaje& listamensajes::operator[](int indice) {
    return datos[indice];
}

const mensaje& listamensajes::operator[](int indice) const {
    return datos[indice];
}



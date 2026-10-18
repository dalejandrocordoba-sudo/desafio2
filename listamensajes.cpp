#include "listamensajes.h"
#include "monitorderecursos.h"

void listamensajes::redimensionar(int nuevacapacidad){
    mensaje* nuevoarreglo = new mensaje[nuevacapacidad];
    monitorderecurso::registrarasignacion(sizeof(mensaje) * nuevacapacidad);

    for (int i = 0; i < tamaño; ++i) {
        nuevoarreglo[i] = datos[i];

    }

    monitorderecurso::registrarliberacion(sizeof(mensaje) * capacidad);
    delete[] datos;
    datos=nuevoarreglo;
    capacidad = nuevacapacidad;
}

listamensajes::listamensajes(): capacidad(4), tamaño(0){
    datos = new mensaje[capacidad];
    monitorderecurso::registrarasignacion(sizeof(mensaje) * capacidad);
}


listamensajes::listamensajes(const listamensajes &otra) : capacidad(otra.capacidad), tamaño(otra.tamaño){
    datos = new mensaje[capacidad];
    monitorderecurso::registrarasignacion(sizeof(mensaje) * capacidad);

    for (int i = 0; i < tamaño; ++i) {
        datos[i] = otra.datos[i];
    }

}

listamensajes& listamensajes::operator=(const listamensajes& otra) {
    if (this != &otra) {
        monitorderecurso::registrarliberacion(sizeof(mensaje) * capacidad);
        delete[] datos;

        capacidad = otra.capacidad;
        tamaño = otra.tamaño;

        datos = new mensaje[capacidad];
        monitorderecurso::registrarasignacion(sizeof(mensaje) * capacidad);

        for (int i = 0; i < tamaño; ++i) {
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
    if (tamaño == capacidad) {
        redimensionar(capacidad * 2);
    }
    datos[tamaño++] = mensaje;
}

mensaje& listamensajes::obtener(int indice) {
    return datos[indice];
}

const mensaje& listamensajes::obtener(int indice) const {
    return datos[indice];
}

int listamensajes::gettamaño() const {
    return tamaño;
}


mensaje& listamensajes::operator[](int indice) {
    return datos[indice];
}

const mensaje& listamensajes::operator[](int indice) const {
    return datos[indice];
}



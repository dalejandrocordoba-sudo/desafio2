#include "listaenteros.h"
#include "monitorderecursos.h"

void listaenteros::redimensionar(){
    int nuevacapacidad = capacidad *2;
    int* nuevoarreglo = new int[nuevacapacidad];
    monitorderecurso::registrarasignacion(sizeof(int)*nuevacapacidad);

    for (int i = 0; i < tamaño; ++i) {
        nuevoarreglo[i] = datos[i];

    }
    monitorderecurso::registrarliberacion(sizeof(int)*capacidad);
    delete[] datos;

    datos = nuevoarreglo;
    capacidad = nuevacapacidad;

}
listaenteros::listaenteros() : capacidad(4),tamaño(0) {
    datos=new int[capacidad];
    monitorderecurso::registrarasignacion(sizeof(int)*capacidad);

}
listaenteros::listaenteros(const listaenteros& otra) : capacidad(otra.capacidad),tamaño(otra.tamaño){
    datos = new int[capacidad];
    monitorderecurso::registrarasignacion(sizeof(int)* capacidad);
    for(int i = 0; i< tamaño; ++i) {
        datos[i] = otra.datos[i];
    }
}

listaenteros& listaenteros::operator = ( const listaenteros& otra) {
    if(this != &otra) {
        monitorderecurso::registrarliberacion(sizeof(int)* capacidad);
        delete[] datos;

        capacidad = otra.capacidad;
        tamaño = otra.tamaño;

        datos = new int[capacidad];
        monitorderecurso::registrarasignacion(sizeof(int) * capacidad);

        for(int i = 0; i< tamaño;++i) {
            datos[i]= otra.datos[i];
        }

    }
    return *this;
}


listaenteros::~listaenteros() {
    monitorderecurso::registrarliberacion(sizeof(int)*capacidad);
    delete[] datos;

}


void listaenteros::agregar(int elemento) {
    if (tamaño == capacidad) {
        redimensionar();
    }
    datos[tamaño] = elemento;
    tamaño++;
}

void listaenteros::eliminaren(int indice) {
    if (indice >= 0 && indice < tamaño) {
        for (int i = indice; i < tamaño-1 ; ++i) {
            datos[i] = datos[i + 1];
        }
        tamaño--;
    }
}

void listaenteros::eliminarvalor(int valor){
    for (int i= 0; i< tamaño; ++i) {
        if(datos[i] == valor) {
            eliminaren(i);
            break;
        }
    }
}

int listaenteros::obtener(int indice) const {
    if (indice >= 0 && indice< tamaño) {
        return datos[indice];
    }
    return-1;
}

int listaenteros::gettamaño() const {
    return tamaño;

}

int& listaenteros::operator[](int indice) {
    return datos[indice];
}

const int& listaenteros::operator[](int indice) const {
    return datos[indice];
}















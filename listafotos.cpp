#include "listafotos.h"
#include "monitorderecursos.h"

void listafotos::redimencionar(int nuevacapacidad){
    foto* nuevoareglo= new foto[nuevacapacidad];
    monitorderecurso::registrarasignacion(size(foto)) * nuevacapacidad;

    for (int i = 0; i < tamano; ++i) {

        nuevoareglo[i]= datos[i];

    }

    monitorderecurso::registrarliberacion(size(foto) * capacidad);
    delete[] datos;


    datos = nuevoarreglo;
    capacidad= nuevacapacidad;
}

listafotos::listafotos(const listafotos &otra) : capacidad(otra.capasidad), tamano(otra.tamano){
    datos = new fotos [capacidad];
    monitorderecurso::registrarasignacion(sizeof(foto)* capacidad);

    for(int i=0; i<tamano; ++i){
        datos[i] = otra.datos[i];
    }
}

Listafotos& Listafotos::operator=(const Listafotos& otra) {
    if (this != &otra) {
        MonitorRecursos::registrarLiberacion(sizeof(Foto) * capacidad);
        delete[] datos;




        capacidad = otra.capacidad;

        tamano= otra.tamano;



        for (int i=0; i<tamano; ++i){

            datos[i]= otra.datos[i];
        }

    }
    return *this;

}



listafotos::~listafotos(){
    monitorderecurso::registrarliberacion(sizeof(foto) * capasidad);
    delete[] datos;

}

void listafotos::agregar(const foto &foto){
    if (tamano== capacidad) {

        redimencionar(capacidad * 2);
    }

}



foto& listafotos::obtener(int indice){
    return datos[indice];
}






const foto& listafotos::obtener(int indice) const{
    return datos[indice];
}




int listafotos::gettamano() const {
    return tamano;
}

foto& listafotos::operador[](int indice) {
    return datos[indice];
}

const foto& listafotos::operador[](int indice) const {
    return datos[indice];
}

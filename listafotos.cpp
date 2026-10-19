#include "listafotos.h"
#include "monitorderecursos.h"

void listafotos::redimencionar(int nuevacapacidad){
    foto* nuevoarreglo= new foto[nuevacapacidad];
    monitorderecurso::registrarasignacion(sizeof(foto) * nuevacapacidad);

    for (int i = 0; i < tamaño; ++i) {

        nuevoarreglo[i]= datos[i];

    }

    monitorderecurso::registrarliberacion(sizeof(foto) * capacidad);
    delete[] datos;


    datos = nuevoarreglo;
    capacidad= nuevacapacidad;

}

listafotos::listafotos() : capacidad(4), tamaño(0) {
    datos = new foto[capacidad];
    monitorderecurso::registrarasignacion(sizeof(foto)* capacidad);
}
listafotos::listafotos(const listafotos &otra) : capacidad(otra.capacidad), tamaño(otra.tamaño){
    datos = new foto [capacidad];
    monitorderecurso::registrarasignacion(sizeof(foto)* capacidad);

    for(int i=0; i<tamaño; ++i){
        datos[i] = otra.datos[i];
    }
}

listafotos& listafotos::operator=(const listafotos& otra) {
    if (this != &otra) {
        monitorderecurso::registrarliberacion(sizeof(foto) * capacidad);
        delete[] datos;

        capacidad = otra.capacidad;

        tamaño= otra.tamaño;

        datos = new foto[capacidad];
        monitorderecurso::registrarasignacion(sizeof(foto) * capacidad);



        for (int i=0; i<tamaño; ++i){

            datos[i]= otra.datos[i];
        }

    }
    return *this;

}



listafotos::~listafotos(){
    monitorderecurso::registrarliberacion(sizeof(foto) * capacidad);
    delete[] datos;

}

void listafotos::agregar(const foto &foto){
    if (tamaño== capacidad) {

        redimencionar(capacidad * 2);
    }
    datos[tamaño++] = foto;

}



foto& listafotos::obtener(int indice){
    return datos[indice];
}






const foto& listafotos::obtener(int indice) const{
    return datos[indice];
}




int listafotos::gettamaño() const {
    return tamaño;
}

foto& listafotos::operator[](int indice) {
    return datos[indice];
}

const foto& listafotos::operator[](int indice) const {
    return datos[indice];
}

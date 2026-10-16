#include "listausuarios.h"
#include "monitorderecursos.h"

void listausuarios::redimensionar(int nuevacapacidad) {
    usuario* nuevoarreglo = new usuario[nuevacapacidad];
    monitorrecursos::registrarasignacion(sizeof(usuario)* nuevacapacidad);

    for (int i= 0; i < tamaño; ++i) {
        monitorrecursos::registrariteracion();
        nuevoarreglo[i] = datos[i];
    }

monitorrecursos::regustrarliberacion(sizeof(usuario)* capacidad);
delete[] datos;
datos = nuevoarreglo;
capacidad = nuevacapacidad;
}

listausuarios::listausuarios() : capacidad(4),tamaño(0) {
    datos = new usuario[capacidad];
    monitorrecursos::registrarasignacion(sizeof(usuario)* capacidad);
    }
listausuarios::listausuarios(const listausuarios& otra) : capacidad(otra.capacidad), tamaño(otra.tamaño) {
    datos = new usuario[capacidad];
    monitorrecursos::registrartasignacion(sizeof(usuario)* capacidad);
    for (int i = o; i < tamao; ++i) {
        datos[i] = otra.datos[i];
    }
}

listausuarios::~listausuarios() {
    monitorrecursos::registrarliberacion(sizeof(usuario)+ capacidad);
    delete[] datos;

}

void listausuarios::agregar(const usuario& usuario) {
    if (tamaño == capacidad) {
        redimensionar(capacidad*2);
        }
    datos[tamaño++] = usuario;

}

usuario& listausuarios::obtener(int indice) {
    return datos[indice]; }
const usuario& listausuarios::obtener(int indice) const {
return datos [indice]; }
int listausuarios::gettamaño() const {
    return tamaño; }
listausuarios& listausuarios::operator+=(const usuario& usuario) {
    agregar(usuario);
    return *this;

}

usuario& listausuarios::operator[](int indice) {
    return datos[indice] ; }
const usuario& listausuarios::operator[](int indice) const {
    return datos[indice];}








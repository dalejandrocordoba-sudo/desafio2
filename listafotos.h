#include "foto.h"
#ifndef LISTAFOTOS_H
#define LISTAFOTOS_H

class listafotos{
private:

    foto* datos;
    int capacidad;
    int tamano;
    void redimencionar(int nuevacapacidad);

public:
    listafotos();
    listafotos(const listafotos& otra);
    listafotos& operator=(const listafotos& otra);
    ~listafotos();
    void agregar(const foto& foto);
    foto& obtener(int indice);
    const foto& obtener(int indice)const;
    int gettamaño() const;

    foto& operator[](int indice);
    const foto& operator[](int indice)const;

};


#endif // LISTAFOTOS_H

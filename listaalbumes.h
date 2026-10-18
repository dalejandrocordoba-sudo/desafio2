#ifndef LISTAALBUMES_H
#define LISTAALBUMES_H
#include "album.h"

class listaalbumes {

private:
    album* datos;
    int capacidad;
    int tamaño;

    void redimensionar(int nuevacapacidad);

public :
    listaalbumes();
    listaalbumes(const listaalbumes& otra);
    listaalbumes& operator=(const listaalbumes& otra);
    ~listaalbumes();

    void agregar(const album& album);
    album& obtener(int indice);
    const album& obtener(int indice) const;
    int gettamaño() const;

    album& operator[](int indice);
    const album& operator[](int indice) const;
};

#endif

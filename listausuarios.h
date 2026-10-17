#ifndef LISTAUSUARIOS_H
#define LISTAUSUARIOS_H
#include "usuario.h"

class listausuarios {
private:
    usuario* datos;
    int capacidad;
    int tamaño;

    void redimensionar(int nuevacapacidad);

public:
    listausuarios();
    listausuarios(const listausuarios& otra);
    ~listausuarios();

    void agregar(const usuario& usuario);
    usuario& obtener (int indice);
    const usuario& obtener (int indice) const;
    int gettamaño() const;

    listausuarios& operator+=(const usuario& usuario);
    usuario& operator[](int indice);
    const usuario& operator [](int indice) const;

};

#endif // LISTAUSUARIOS_H

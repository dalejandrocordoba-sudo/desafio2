#ifndef LISTAMENSAJES_H
#define LISTAMENSAJES_H
#include "mensaje.h"


class listamensajes{

private:
    mensaje* datos;
    int capacidad;
    int tamano;
    void redimencionar(int nuevacapacidad);



public:
    listamensajes();
    listamensajes(const listamensajes& otra);
    listamensajes& operador=(const listamensajes& otra);
    ~listamensajes();

    void agregar(const mensaje& mensaje);
    mensaje& obtener (int indice);
    const mensaje& obtener(int indice) const;
    int gettamano() const;

    mensaje& operador[](int indice);
    const mensaje& operador[](int indice) const;

};
#endif // LISTAMENSAJES_H

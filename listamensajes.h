#ifndef LISTAMENSAJES_H
#define LISTAMENSAJES_H
#include "mensaje.h"


class listamensajes{

private:
    mensaje* datos;
    int capacidad;
    int tamaño;
    void redimensionar(int nuevacapacidad);



public:
    listamensajes();
    listamensajes(const listamensajes& otra);
    listamensajes& operator=(const listamensajes& otra);
    ~listamensajes();

    void agregar(const mensaje& mensaje);
    mensaje& obtener (int indice);
    const mensaje& obtener(int indice) const;
    int gettamaño() const;

    mensaje& operator[](int indice);
    const mensaje& operator[](int indice) const;



};
#endif // LISTAMENSAJES_H

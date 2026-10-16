#ifndef ALBUM_H
#define ALBUM_H

#include <iostream>

class album{

private:

    char usuariopropietario[64];
    char nombrealbum[64];
    char rutacarpeta[256];
    int espublico;
    listafotos fotos;


public:

    album();
    album(const char* nombre, const char* ruta, int privacidad);
    album(const char* propietario, const char* nombre, const char* ruta, int publico );



album(const album& otro);
album& operator=(const album& otro);



const char* getnombre()const;

const char* getnombrealbum()const;

const char* getrutastorage()const;

const char* getrutacarpeta( )const;

int getprivacidad() const;

int getpublico() const;


const char* getusuariopropietario() const;


void setusuariopropietario(const char* propietario);
void agregarfoto(const foto& foto);

listafotos& getfotos();};





#endif // ALBUM_H

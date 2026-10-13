#ifndef REDSOCIAL_H
#define REDSOCIAL_H

#include "listausuarios.h"
#include "monitorderecursos.h"

using namespace std;


class redsocial {
private :
    listausuaredsocialrios usuarios;
    int**  matrizadyacencia;
    int totalusuarios;
    int capacidadusuarios;

    void redimencionarmatriz(int nuevacapacidad);
public :

    redsocial();
    ~redsocial();

    void cargadatosdesdearchivo();
    void cargardatosenarchivos();



    int buscaridporusername(const char *username)const;
    void registrarusuario(const usuario& u);
    void estableceramistadf (int idu1 , int idu2);
    bool sonamigos (int idu1 , int idu2) const;
    int calcularamigosencomun (int idu1 , int idu2);




};




#endif

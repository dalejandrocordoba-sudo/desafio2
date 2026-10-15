#ifndef REDSOCIAL_H
#define REDSOCIAL_H

#include "listausuarios.h"
#include "monitorderecursos.h"

using namespace std;


class redsocial {
private :
    listausuarios usuarios;
    int**  matrizadyacencia;
    int totalusuarios;
    int capacidadusuarios;

    void redimencionarmatriz(int nuevacapacidad);
public :

    redsocial();
    ~redsocial();


    void cargarsolicitudesdesdearchivo();
    void guardardatosdesdearchivo();
    void cargardatosenarchivos();
    void guardarsolicitudesenarchivo();



    int buscaridporusername(const char *username)const;
    void registrarusuario(const usuario& u);
    void estableceramistadf (int idu1 , int idu2);
    bool sonamigos (int idu1 , int idu2) const;
    int calcularamigosencomun (int idu1 , int idu2);


    void mostrarmejoresamigos(int idusuarioactual);
    void enviarsolicitudamistad(int idemisor, const char* usernamedestino);
    void aceptarsolicitudespendientes(int idusuarioactual);
    void visitarperfilamigo(int idusuarioactual, const char* usernameamigo, int indicealbum);
    void mostrarsugerenciasamistad(int idusuarioactual, int k );
    void enviarmensaje (int idemisor, const char* usernamedestino, const char* texto);
    void leernuevosmensajes(int idusuarioactual);
    void buscarmensajesporrangofechas(int idusuarioactual,const char* fechainicio,const char* fechafin);
};
#endif

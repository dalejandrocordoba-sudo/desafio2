#ifndef USUARIO_H
#define USUARIO_H
#include "listaalbumes.h"
#include "listamensajes.h"
#include "listaenteros.h"

class usuario {
private:
    char username[100];
    char email[100];
    char fechanacimiento[30];
    char fotoperfilruta[200];
    char ciudad [50];
    char pais[50];


    listaalbumes albuymes;
    listamensajes mensajesrecibidos;
    listamensajes mensajesenviados;
    listaenteros solicitudespendientesids;


public:
    usuario();
    usuario(const char* user, const char* mail, const char* fotoruta);
    usuario(const char* user, const char* mail, const char* fnac, const char* fotoruta, const char* ciu, const char* pa);
    usuario(const usuario& otro);
    usuario& opertator=( const usuario& otro);
    ~usuario();

    const char* getusername() const;
    const char* getemail() const;
    const char* getfechanacimiento() const;
    const char* getfotoperfil() const;
    const char* getciudad() const;
    const char* getpais() const;

    void agregaralbum (const album& alb);
    void recibirmensaje(const mensaje& msg);
    void enviarmensaje(const mensaje& msg);
    void recibirsolicitud(int idusuarioemisor);

    listaalbumes& getalbumes();
    listamensajes& getmensajesrecibidos();
    listamensajes& getmensajeenviados();
    listaenteros& getsolicitudespendientes();


};

#endif // USUARIO_H

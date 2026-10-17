#include "usuario.h"
#include <cstring>


using namespace std;

usuario::usuario() {
    username[0] ='\0';
    email[0] = '\0';
    fechanacimiento[0]= '\0';
    fotoperfilruta[0] = '\0';
    ciudad[0] = '\0';
    pais[0] = '\0';

}

usuario::usuario(const char* user, const char* mail, const char* fotoruta) {
    strncpy(username, user, sizeof(username)-1);
    username[sizeof(username)-1] = '\0';

    strncpy(email,mail,sizeof(email) - 1);
    email[sizeof(email)-1]= '\0';

    strncpy(fotoperfilruta,fotoruta, sizeof(fotoperfilruta)- 1);
    fotoperfilruta[sizeof(fotoperfilruta)- 1] = '\0';

    strncpy(fechanacimiento, "2000-01-01", sizeof(fechanacimiento) - 1);
    fechanacimiento[sizeof(fechanacimiento)-1]= '\0';

    strncpy(ciudad,"medellin", sizeof(ciudad)-1);
    ciudad[sizeof(ciudad)-1]= '\0';

    strncpy(pais, "colombia",sizeof(pais)-1);
    pais[sizeof(pais)-1]= '\0';

    }

usuario::usuario(const char* user, const char* mail, const char* fnac, const char* fotoruta, const char* ciu, const char* pa) {
    strncpy(username, user, sizeof(username)-1);
    username[sizeof(username)-1] = '\0';

    strncpy (email,mail, sizeof(email)-1);
    email[sizeof(email)-1]= '\0';

    strncpy (fotoperfilruta,fotoruta, sizeof(fotoperfilruta)-1);
    fotoperfilruta[sizeof(fotoperfilruta)-1]= '\0';

    strncpy (fechanacimiento,"2000-01-01", sizeof(fechanacimiento)-1);
    fechanacimiento[sizeof(fechanacimiento)-1]= '\0';

    strncpy (ciudad,"medellin", sizeof(ciudad)-1);
    ciudad[sizeof(ciudad)-1]= '\0';

    strncpy (pais,"colombia", sizeof(pais)-1);
    pais [sizeof(pais)-1]= '\0';


}

usuario::usuario(const usuario& otro) {
    strncpy(username, otro.username, sizeof(username)-1);
    username[sizeof(username)-1] ='\0';

    strncpy(email, otro.email, sizeof(email)-1);
    email[sizeof(email)-1] ='\0';

    strncpy(fechanacimiento, otro.fechanacimiento, sizeof(fechanacimiento)-1);
    fechanacimiento[sizeof(fechanacimiento)-1] ='\0';

    strncpy(fotoperfilruta, otro.fotoperfilruta, sizeof(fotoperfilruta)-1);
    fotoperfilruta[sizeof(fotoperfilruta)-1] ='\0';

    strncpy(ciudad, otro.ciudad, sizeof(ciudad)-1);
    ciudad[sizeof(ciudad)-1] ='\0';

    strncpy(pais, otro.pais, sizeof(pais)-1);
    pais[sizeof(pais)-1] ='\0';

    albumes = otro.albumes;
    mensajesrecibidos = otro.mensajesrecibidos;
    mensajesenviados = otro.mensajesenviados;
    solicitudespendientesids = otro.solicitudespendientesids;

}

usuario& usuario::operator=(const usuario& otro) {
    if (this != &otro) {
        strncpy (username, otro.username, sizeof (username) - 1);
        username[sizeof (username)- 1] = '\0';

        strncpy (email, otro.email, sizeof (email) - 1);
        email[sizeof (email)- 1] = '\0';

        strncpy (fechanacimiento, otro.fechanacimiento, sizeof (fechanacimiento) - 1);
        fechanacimiento[sizeof (fechanacimiento)- 1] = '\0';

        strncpy (fotoperfilruta, otro.fotoperfilruta, sizeof (fotoperfilruta) - 1);
        fotoperfilruta[sizeof (fotoperfilruta)- 1] = '\0';

        strncpy (ciudad, otro.ciudad, sizeof (ciudad) - 1);
        ciudad[sizeof (ciudad)- 1] = '\0';

        strncpy (pais, otro.pais, sizeof (pais) - 1);
        pais[sizeof (pais)- 1] = '\0';

        albumes = otro.albumes;
        mensajesrecibidos = otro.mensajesrecibidos;
        mensajesenviados = otro.mensajesenviados;
        solicitudespendientesids =otro.solicitudespendientesids,
    }
    return *this;
}

usuario::~usuario() {}

const char* usuario::getusername() const {
    return username;
}
const char* usuario::getemail() const {
    return email;
}
const char* usuario::getfechanacimiento() const {
    return fechanacimiento;
}
const char* usuario::getfotoperfil() const {
    return fotoperfilruta;
}
const char* usuario::getciudad()const {
    return ciudad;
}
const char* usuario::getpais() const {
    return pais;
}

void usuario::agregaralbum(const album& alb) {
    albumes.agregar(alb);}
void usuario::recibirmensaje(const mensaje& msg) {
    mensajesrecibidos.agregar(msg);}
void usuario::enviarmensaje(const mensaje& msg){
    mensajesenviados.agregar(msg);}

void usuario::recibirsolicitud(int idusuarioemisor) {
    for (int i = 0; i < solicitudespendientesids.gettamaño(); ++i) {
        if (solicitudespendientesids[i] == idusuarioemisor)
            return;
    }
    solicitudespendientesids.agregar(idusuarioemisor);

}

listaalbumes& usuario::getalbumes(){
    return albumes;
}
listamensajes& usuario::getmensajesrecibidos() {
    return mensajesrecibidos;
}
listamensajes& usuarios::getmensajesenviados() {
    return mensajesenviados;
}
listaenteros& usuario::getsolicitudespendientes(){
    return solicitudespendientesids;
}










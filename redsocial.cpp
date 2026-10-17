#include "redsocial.h"
#include "monitorderecurso.h"
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>

using namespace std;

redsocial ::redsocial() {
    totalusuarios =0;
    capacidadusuarios = 10;
    matrizadyacencia= new int*[capacidadusuarios];
    monitorderecurso::registrarasignacion(sizeof(int*)*capacidadusuarios);

    for (int i=0; i < capacidadusuarios; ++i){
        matrizadyacencia[i] = new int [capacidadusuarios];
        monitorderecurso::registrarasignacion(sizeof (int)* capacidadusuarios);
        for(int j=0; j< capacidadusuarios; ++j){
            matrizadyacencia[i][j]=0;

        }
    }
}

redsocial ::~redsocial() {

    for (int i = 0; i< capacidadusuarios; ++i){
        monitorderecurso :: registrarliberacion(sizeof(int)* capacidadusuarios)
        delete matrizadyacencia[i];
    }
    monitorderecurso::registrarliberacion(sizeof(int)* capacidadusuarios);
    delate [] matrizadyacencia;

}

void redsocial::redimencionarmatriz (int nuevacapacidad) {

    int ** nuevamatriz = new int*[nuevacapacidad];
    monitorderecurso ::registrarasignacion (sizeof (int*)* nuevacapacidad)
        for (int i=0; i < nuevacapacidad; ++i){
        nuevamatriz [i]= new int [nuevacapacidad];
        for (int j=0; j< nuevacapacidad;++j){
            if( i < totalusuarios && j < totalusuarios){
                nuevamatriz[i][j] = matrizadyacente[i][j];
            }else {
                nuevamatriz[i][j] =0;
            }
        }
    }
    
    for (int i = 0; i < capacidadusuarios;++i){
        monitorderecurso::registrarliberacion (sizeof (int )* capacidadusuarios;
    delete[] matrizadyacencia [i];

    }
    monitorderecurso::registrarliberacion (sizeof(int*)* capacidadusuarios);
    delete[] matrizadyacencia;

    matrizadyacencia = nuevamatriz;
    capacidadusuarios = nuevacapacidad;
}

int redsocial::buscaridporusername (const char* username) const {

    for (int i = 0; i < usuarios.gettamaño(); ++i){
        monitorderecurso::registrariteracion();

        if (strcmp(usuarios[i].getusername(), username) ==0){
            return i;
        }
    }
    return -1;
}

void redsocial ::registrarusuario(const usuario& u){
    if (totalusuarios == capacidadusuarios){
        redimensionarmatriz (capacidadusuarios * 2);
    }
    usuarios.agregar(u);
    totalusuarios++;

}

void redsocial::estableceramistad(int idu1, int idu2) {
    if(idu1 >=0 && idu1< totalusuarios && idu2>=0 && idu2< totalusuarios){
        matrizadyacencia [idu1][idu2] = 1;
        matrizadyacencia [idu2][idu1] = 1;
    }
}

bool redsocial::sonamigos(int idu1,int idu2) const {
    if (idu1 >= 0 && idu1 < totalusuarios && idu2 >= 0 && idu2< totalusuarios){
        return matrizadyacencia[idu1][idu2]== 1;

    }
    return false;
}

int redsocial:: calcularamigosencomun(int idu1,int idu2) {
    int contador= 0;
    for (int k = 0; k < totalusuarios; ++k) {
        monitorderecurso::registrariteracion();
        if(matrizadyacencia[idu1][k]== 1 && matrizadyacencia[idu2][k]== 1){
            contador++;
        }
    }
    return contador;
}

void redsocial::cargarsolicitudesdesdearchivo(){
    ifstream fsol ("solicitudes.txt");
        if(!fsol.is_open()) return;

    int idemisor , idreceptor;
    while (fsol>> idemisor >> idreceptor) {
        if (idreceptor >= 0 && idreceptor < usuarios.gettamaño()) {
            usuarios [idreceptor].recibirsolicitud(idemisor);
        }
    }
    fsol.close();
}

void redsocial::guardarsolicitudesenarchivo() {
    ofstream fsol("solicitudes.txt", ios::trunc);
    if(!fsol.is_open()) return;

    for (int i = 0; i < usuarios.gettamaño(); ++i) {
        listaenteros& pendientes = usuarios[i].getsolicitudespendientes();
        for (int j = 0; j < pendientes.gettamaño(); ++j) {
            int idemisor = pendientes[j];
            fsol << idemisor << " " << i << "\n";
        }
    }
    fsol.close();
}

void redsocial ::cargardatosdesdearchivos() {

    ifstream fuser("usuarios.txt");
    if (fuser.is_open()) {
        char u[64], em[128], fn[11], fot[256], ciu[64], pa[64];
        while (fuser.getline(u,64, ',')){
            fuser.getline(em,128,',');
            fuser.getline(fn,11,',');
            fuser.getline(fot,256,',');
            fuser.getline(ciu,64,',');
            fuser.getline(pa,64,'\n');

            usuario userobj(u, em,fn,for,ciu,pa);
            registrarusuario(userobj);
        }
        fuser.close();
    }


ifstream frel ("relaciones.txt");
if (frel.is_open()) {
    char u1[64], u2[64];
    while (frel.getline(ui,64,',')) {
        frel.getline(u2,64,'\n');
        int id1 = buscaridporusername(u1);
        int id2 = buscaridporusername(u2);
        if (id1 != -1 && id2 != -1) {
            estableceramistad(id1, id2);
        }
    }
    frel.close();
}

ifstream falb ("albumes.txt");
if (falb.is_open()) {
    char owner[64], nomalb[64], rstorage[256], privstr[10];
    char rfoto [256], ffoto[11], tamstr [15], likesstr[15];

    while (falb.getline(owner,64,',')) {
        falb.getline(nomalb, 64, ',');
        falb.getline(rstorage,256,',');
        falb.getline(privstr,10,',');
        falb.getline(rfoto,256,',');
        falb.getline(ffoto,11,',');
        falb.getline(tamsr,15,'\n');

        int idowner = buscaridporusername(owner);
        if (idower !=-1) {
            usuario& user = usuarios[idowner];
            int priv = atoi(privstr);

            int idxalbum =-1;
            for (int a =0; a< user.getalbumes().gettamaño(); ++a) {
                if (strcmp(user.getalbumes()[a].getnombre(),nomalb)== 0) {
                    idxalbum = a;
                    break;
                }
            }
            if (idxalbum == -1) {
                album nuevoalbum ( nomalb,rstorage,priv);
                user.agregaralbum(nuevoalbum);
                idxalbum = user.getalbumes().gettamaño()-1;
            }
            if (strlen(rfoto)>0) {
                foto fotoobj(rfoto,ffoto, (unsigned int) atoi(tamstr));
                fotoobj.setlikes((unsigned int) atoi(likesstr));
                user.getalbumes()[idxalbum].agregarfoto(fotoobj);
            }

        }



    }
    falb.close();
}



ifstream fmsg("mensajes.txt");
if (fmsg.is_open()){
    char emisor[64], receptor [64],txt[513],fec[20],leidostr[5];
    while (fmsg.getline(emisor,64,',')){
        fmsg.getline(receptor,64,',');
        fmsg.getline(txt,513,',');
        fmsg.getline(fec,20,',');
        fmsg.getline(leidostr,5,'\n');

        int ide = buscaridporusername(emisor);
        int idr = buscaridporusername(receptor);
        if (ide != -1 && idr != -1) {
            mensaje m(emisor,receptor,txt,fec);
            if (atoi(leidostr)==1){
                m.marcarleido();
            }
            usuarios[ide].enviarmensaje(m);
            usuarios[idr].recibirmensaje(m);
        }
    }
    fmsg.close();
}
cargarsolicitudesdesdearchivo();
}


void redsocial::guardardatosenarchivo() {
    ofstream fuser("usuarios.txt");
    if (fuser.is_open()) {
        for (int i = 0 ; i < usuarios.gettamaño();++i) {
            fuser << usuarios [i].getusername()<< ","
                  << usuarios[i].getemail()<< ","
                  << usuarios[i].getfechanacimiento()<< ","
                  << usuarios[i].getfotoperfil()<<","
                  << usuarios[i].getciudad()<<","
                  << usuarios[i].getpais()<< "\n";
        }
        fuser.close();
    }

    ofstream frel("relaciones.txt");
    if (frel.is_open()) {
        for (int i = 0; i< totalusuarios; ++i) {
            for (j = i +1; j< totalusuarios; ++j) {
                if (matrizadyacencia [i][j] == 1) {
                    frel << usuarios[i].getusername()<< ",";
                         << usuario[j].getusername() << "\n";
                }
            }
        }
        frel.close;
    }

    ofstream falb("albumes.txt");
    if (falb.is_open()) {
        for (int i = 0; i < usuarios.gettanalo(); ++i) {
            listaalbumes& alblist = usuarios[i].getalbumes();
            for (int a = 0; a< alblist.gettamaño(); ++a) {
                album& alb = alblist[a];
                listafotos& ftlist = alb.getfotos();
                if(ftlist.gettamaño() ==0) {
                    falb << alb.getnombre() << ","
                         << alb.getrutastorage() << ","
                         << alb.getprivacidad()<< ",,,0,0\n";
                    else {
                        for (int f = 0; f< flist.gettamaño(); ++f) {
                            foto& ft=ftlist[f];
                            falb << usuarios[i].getusername() <<","
                                 << alb.getnombre()<< ","
                                 << alb.getrutastorage() << ","
                                 << alb.getprivacidad()<< ","
                                 << ft.getruta()<<","
                                 << ft.getfecha()<<","
                                 << ft.gettamañobytes()<<","
                                 <<ft.getlikes()<<"\n";

                        }
                    }
                }

            }
            falb.close();
        }
        ofstream fmsg("mensajes.txt");
        if (fmsg.is_open()){
            for (int i = 0; i < usuarios.gettamaño();++i){
                listamensajes& msglist =usuarios[i].getmensajesenviados();
                for(int m= 0; m< msglist.gettamaño(); ++m){
                    mensaje& msg = msglist[m];
                    fmsg<< msg.getemisor()<<","
                         << msg.getreceptor()<<","
                         << msg.getcontenido() << ","
                         << msg.getfechaenvio() << ","
                         << (msg.isleido() ? 1 : 0)<< "\n";

                }
            }
            fmsg.close;
        }
        guardarsolicitudesenarchivo();
    }


void redsocial::mostrarmejoresamigos(int idusuarioactual) {
    cout <<"\n mejores amigos (fotos de perfil) \n";
    int amigosencontrados = 0;
    for (int i = 0; i < totalusuarios; ++i){
        monitorderecurso::registrariteracion() ;
        if ( i != idusuarioactual && sonamigos(idusuarioactual, i)) {
            cout<< "foto perfil de amigo " << (amigosencontrados + 1 ) << ":"
                 << usuarios[i].getfotoperfil() << "\n";
            amigosencontrados++;
            if (amigosencontrados == 3 )break;
        }
    }
    if (amigosencontrados== 0) {
        cour << "aun no tienes amigos registrados en la plataforma. \n";
    }
}


void redsocial::enviarsolicitudamistad(int idemisor,const char* usernamedestino) {
    int iddestino = buscarporusername(usernamedestino);
    if (iddestino==-1){
        cout << "error: el usuario especificado no existe. \n";
        return;
    }
    if (idemisor == iddestino) {
        cout<< "error: no puedes enviarte una solicitud a ti mismo.\n";
        return;
    }
    if (sonamigos(idemisor, iddestino)){
        cout << "error: ya eres amigo de este usuario.\n";
        return;

    }
    usuarios[iddestino].recibirsolicirud(idemisor);
    cout << "solicitud de amistad enviada con exito a " << usernamedestino << "\n";
}
void redsocial::aceptarsolicitudpendientes(int idusuarioactual){
    listaenteros& pendientes = usuarios[idusuarioactual].gersolicitudespendientes();
    if(pendientes.getamano() == 0 ) {
        cout << "notienes solicitudes de amistad pendientes.\n";
        return;
    }
    cout << "solicitudes de amistad pendientes:\n";
    for (int i= 0; i < pendientes.gettamaño(); ++i) {
        monitorderecurso::registrariteracion();
        int idsolicitante = pendientes[i];
        cout << (i+1) << ". " << usuarios[idsolicitante].getusername() << "\n";

    }
    cout << "ingrese el numero de la solicitud que desea aceptar (0 para cancelar): ";
    int seleccion;
    cin >> seleccion;
    if (seleccion> 0 && seleccion<= pendientes.gettamaño()) {
        estableceramistad(idusuarioactual, idaceptado);
        pendientes.eliminaren(seleccion-1);
        guardarsolicitudesenarchivo();
        guardardatosenarchivos();

        cout<< "ahora eres amigo de" << usuarios[idaceptado].getusername()<< "\n";
    }
}

void redsocial ::visitarperfilamigo(int idusuarioactual, const char* usernameamigo) {
    monitorderecurso::reiniciarinteraciones();
    if(idamigo == -1 || !sonamigos(idusuarioactual,idamigo)) {
        cout << "error: el usuario no existe o no es tu amigo.";
        monitorderecurso::mostrarmetricas("visitar perfil de amigo");
        return;
    }

    usuario& amigo = usuarios[idamigo];
    listaalbumes& albumes = amigo.getalbumes();
    if (albumes.gettamaño() == 0 ) {
        cout << "el usuario no tiene albumes disponibles."
            monitorrecursos::mostrarmetricas ("visitar perfil de amigo");
        return;
    }
    cout << "albumes de "<< amigo.getusername() << ":";
    for (int i = 0 ; i < albumes.gettamaño(); ++i) {
        monitorderecurso::registrariteracion();
        cout << (i+1)<< ". "<< albumes[i].getnombre();
        if (albumes[i].getprivacidad() == 0 ) cout << "(publico)";
        else if (albumes[i].getprivacidad() == 2 ) cout << "(amigos)";
        else cout << "(privado)";
        }

    cout << "seleccione el numero de album a explorar (0 para salir ): ";
        int sel;
        cin >> sel;
        if(sel> 0 && sel <= albumes.gettamaño()) {
            navegarcarruselalbum(idusuarioactual,usernameamigo, sel - 1);
        }else {
            monitorderecurso::mostrarmetricas ("visitar perfil de amigo");
        }
}

void redsocial::navegarcarruselalbum(int idusuarioactual, const char * usernameamigo,int indicealbum){
    int idamigo = buscaridusename(usernameamigo);
    if (idamigo== -1 || !sonamigos(idusuarioactual,idamigo)) {
        cout << "error: el usuario no existe o no es su amigo.";
        return;
    }
    usuario& amigo = usuarios[idamigo];
    album& album = amigo.getalbumes() [indicealbum];

    if (album.getalbumes() == 1) {
        cout<< "el album es privado.";
        monitorrecursos::mostrarmetricas("visitar perfil de amigo");
        retutn;
    }

    listafotos& fotos = album.getfotos();
    if (fotos.gettamaño)() ==0) {
            cout << "el album esta vacion.";
            monitorderecurso:: mostrarmetricas("visitar perfil de amigo");
            return;
        }
    int idxfotoactual= 0;
    char opcional;

    do{
        foto& fotoactual = fotos[idxfotoactual];
        cour << "album: " << album.getnombre() << ;
        cout << "foto ("<< fotoactual.getlikes()<< ;
        << fotoactual.getruta() << ;
        cout << likes: << fotoactual.getlikes() << ;
        cout << "[n] siguiente | [p] previa | [l] dar like | [s] salir";
        cout << "opcion: ";
        cion >> opcion;

        monitorrecurosos::registrariteracion():

            if (opcion == 'N' || opcion == 'n') {
            idxfotoactual = (idxfotoactual + 1) % fotos.gettamaño();
        } else if (opcion == 'P'|| opcion == 'p'){
                idxfotoactual = (idxfotoactual == 0 ) ? fotos.gettamaño() -1 : idxfotoactual-1;
        } else if (opcion == 'L' || opcion == 'l') {
            foto actual.darlike();
            cout << "le diste like a la foto "
        }

    }while (opcion != 'S' && opcion != 's');

    monitorderecurso::mostrarmetricas("visitar perfil de amigo");
}

void redsocial::mostrarsugerenciaamistad(int idusuarioactual,int k ) {
    monitorrecursos::reiniciariteraciones();

    int* candidatosids = new int [totalusuarios];
    int* coincidenciascore = new int[totalusuarios];
    monitorderecurso::registrarasignacion(sizeof(int)*totalusuarios * 2);
    int numcantidadatos = 0;

    for (int i = 0; i < totalusuarios; ++i) {
        monitorrecursos::registrariteracion();
        if(i != idusuariioactual && !sonamigos(idusuarioactual, i)) {
            int score = calcularamigosencomun(idusuarioactual, i);
            if(score> 0) {
                candidatosids[numcandidatos] = i;
                coincidenciascore[numcandidatos] = score;
                numcandidatos++;
            }
        }
    }

    for (int i=0; i< numcandidaros - 1;++i) {
        for(int j = i + 1; j < numcandidatos; ++j) {
            monitorrecursos::registrariteracion();
            if(coincidenciascore[j]>coincidenciascore[i]) {
                int tempscore = coincidenciascore[i];
                coincidenciascore[i] = coincidenciascore[j];
                coincidenciascore[j] = tempscore;

                int tempid = candidatosids[i];
                candidatosids[i] = candidatosids[j];
                candidatosids[j] = tempid;
            }
        }
    }

    cout << k << "sugerencias de amistad ";
    int limite = (numcandidatos < k) ? numcandidatos : k;
    for ( int i = 0; i < limite ; ++i) {
        cout << i +1 << ". " << usuarios[candidatosids[i]].getusername()
             << "(" << coincidenciascore[i]<< "amigos en comen)";

    }
        if (limite == 0) {
            cout << "no hay sugerencias de amistad para mostrar en este momento "
        }


        monitorderecurso ::registrarliberacion(sizeof(int) * totalusuarios * 2);
        delete[] candidatosids;
        delete[] coincidenciascore;

        monitorrecursos::mostrarmetricas("ver sugerencias de amistad");

    }

    void redsocial::enviarmensaje(int idemisor, const char* usernamedestino, const char* texto) {
        int iddestino = buscarporusername(usernamedestino);
        if (iddestino == -1 || !sonamigos(idemisor,iddestino)) {
            cout << "error: no existe el usuario o no es tu amigo. ";
            return
        }
        if (strlen(texto) == 0) {
            cout << "error: no se pueden enviar mensajes vacios.";
            return;
        }
        mensaje msg(usuarios[idemisor].getusername(), usernamedestino, texto, "2026-10-15 11:00");
        usuarios[idemisor].enviarmensaje(msg);
        usuario[iddestino].recibirmensaje(msg);
        cout << "mensaje enviado exitosamente a " << usernamedestino << ;
}

    void redsocial::leernuevosmensajes(int idusuarioactual){
        listamensajes& mensajes = usuarios[idusuarioactual].getmensajesrecibidos();
        int noleidos = 0;
        cout << "mensajes nuevos ";
        for (int i = 0; i < mensajes.gettamaño(); ++i) {
            monitorrecursos::registrariteracion();
            if(!mensajes[i].isleido()) {
                cout << "de: " << mensajes[i].getemisor() << mensaje[i].getfechaenvio() << ;
                cout <<"texto: " << mensaje[i].getcontenido() <<;
                mensajes[i].marcarleido();
                noleidos++;
            }
        }
        if (noleidos == 0) {
            cout << "no tienes mensajes nuevos sin leer.";
        }
    }
album






























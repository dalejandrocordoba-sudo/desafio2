#include "redsocial.h"
#include "monitorderecursos.h"
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>

using namespace std;

redsocial ::redsocial() { /*iniciamos el constructor de red social*/
    totalusuarios =0;/*definimos las caracteristicas con los diferentes valores siendo para total usuarios = 0 inicializando el contrador en 0 */
    capacidadusuarios = 10;/*definimos para capacidad usuario un total de 10 empezando este en 10*/
    matrizadyacencia= new int*[capacidadusuarios];/*creamos la matriz adyacencia con un arreglo equivalente a la capacidad de usuarios en la heap*/
    monitorderecurso::registrarasignacion(sizeof(int*)*capacidadusuarios);/*registramos la cantidad de interacciones utilizadas en base al arreglo anterior
                                                                        mediante nuestra clase monitorderecursos en su objeto registrarasignacion
                                                                    utilizando sizeof como medidor de bytes */

    for (int i=0; i < capacidadusuarios; ++i){/* para el entero i igual a 0  mientras i sea menos que la capacidadusuarios : entre al ciclo */
        matrizadyacencia[i] = new int [capacidadusuarios];/*matrizadyacencia en la posicion i cree un puntero en la heap con el arreglo capacidadusuarios */
        monitorderecurso::registrarasignacion(sizeof (int)* capacidadusuarios);/*registramos la cantidad de interacciones en un contador para dicho puntero*/
        for(int j=0; j< capacidadusuarios; ++j){/*para el  entero j = a 0 si j es menor que capacidadusuarios entre al condicional */
            matrizadyacencia[i][j]=0; /*matrizadyacencia en la posicion i j  osea para las 10 filas creele a cada una 10 columnas con el valor 0 esto
                                    para limpiar la heap en estas posiciones*/

        }
    }
}

redsocial ::~redsocial() {/*creamos el destructor*/

    for (int i = 0; i< capacidadusuarios; ++i){/*para el entero i igual a 0 i menor que la capacidadusuarios si este se cumple ingrese al ciclo*/
        monitorderecurso :: registrarliberacion(sizeof(int)* capacidadusuarios);/*registramos la memoria liberada para descontarla en el registro que
                                                                                llevamos*/
        delete[] matrizadyacencia[i];/*liberamos la memoria de matrizadyacencia en cada una de las diferentes posiciones*/
    }
    monitorderecurso::registrarliberacion(sizeof(int*)* capacidadusuarios);/* registramos la memoria liberada para descontarla
                                                                                en el registro que llevamos*/
    delete[] matrizadyacencia; /*liberamos la memoria utilizada en la heap para matriz adyacencia en general */

}

void redsocial::redimensionarmatriz(int nuevacapacidad) {/*inicializamos el metodo redimencionarmatriz con la intencion de establecer las nuevas
                                                    posibilidades de amistades de acuerdo a la nueva capacidad dependiendo de la cantidad de amistades
                                                    existentes y de la cantidad de usuarios registrados */

    int ** nuevamatriz = new int*[nuevacapacidad];/*creamos un doble puntero a nuevamatriz donde esta va a tener un arreglo de acuerdo a la
                                                    nuevacapacidad*/
    monitorderecurso ::registrarasignacion (sizeof (int*)* nuevacapacidad);/*registramos la cantidad de interacciones en un contador para dicho puntero*/

    for (int i=0; i < nuevacapacidad; ++i){/*para el entero i = a 0 mientras i sea menor que nuevacapacidad; ingrese al ciclo*/
        nuevamatriz [i]= new int [nuevacapacidad];/*creamos un puntero para cada posicion i de la nueva matriz con un arreglo equivalente a la
                                                    nuevacapacidad */
        monitorderecurso::registrarasignacion(sizeof(int)* nuevacapacidad);/*registramos la cantidad de bytes en un contador para dicho puntero*/
        for (int j=0; j< nuevacapacidad;++j){/*para el entero j = 0 si j es menor que la nueva capacidad ingresa al ciclo*/
            if( i < totalusuarios && j < totalusuarios){/*si el indice es menor que totalusuarios y j es menor que total usuarios ingrese al condicional */
                nuevamatriz[i][j] = matrizadyacencia[i][j];/*nuevamatriz en la posicion i j es igual a matrizadyacencia en las pocisiones i j */
            }else {
                nuevamatriz[i][j] =0;/*de lo contrario la nueva matriz en la posicion i j va a ser 0 */
            }
        }
    }
    
    for (int i = 0; i < capacidadusuarios;++i){/*para el entero i = 0 mientras i sea menor que capacidadusuarios entre al ciclo*/
        monitorderecurso::registrarliberacion (sizeof (int )* capacidadusuarios);/*registramos la memoria liberada para descontarla en el registro que
                                                                                llevamos*/
        delete[] matrizadyacencia [i];/*liberamos la memoria para matriz adyacencia*/

    }
    monitorderecurso::registrarliberacion (sizeof(int*)* capacidadusuarios);/* registramos la memoria liberada para descontarla
                                                                                en el registro que llevamos*/
    delete[] matrizadyacencia;/*liberamos la memoria utilizada en la heap para matriz adyacencia en general */

    matrizadyacencia = nuevamatriz; /*ahora matriz anyacencia  va a ser la nueva matriz*/
    capacidadusuarios = nuevacapacidad;/*ahora la capacidadusuarios es igual a la nueva capacidad*/
}

int redsocial::buscaridporusername (const char* username) const {/*inicializamos el metodo buscaridporusername y llamamos el username con un const para
                                                                no cambiar este valor */

    for (int i = 0; i < usuarios.gettamaño(); ++i){/*para el entero i = 0 si i es menor que usuarios.gettamaño ingrese al ciclo*/
        monitorderecurso::registrariteracion();/*registramos la cantidad de bytes en un contador para dicho puntero*/

        if (strcmp(usuarios[i].getusername(), username) ==0){/*si el resultado de la comparacion entre usuario en la posicion i con los parametros del
                                                constructor y el usuario buscado por el mismo son 0  continue al condicional*/
            return i;/*retorne el indice donde se encuentra este sera el id del usuario*/
        }
    }
    return -1;/*si no se encuentra retorne -1 haciendo referencia a que hay un error y que no puede cumplirse lo pedido*/
}

void redsocial::registrarusuario(const usuario& u){/*inicializamos el metodo registrarusuario llamando por referencia y como constante a usuario  */
    if (totalusuarios == capacidadusuarios){/*si el total de usuatios es igual a la capacidad de usuarios entre al condicional*/
        redimensionarmatriz (capacidadusuarios * 2);/* llamamos el metodo redimensionarmatriz y le aplicamos capacidad usuarios por 2 para tener mayor
capacidad de usuarios */
    }
    usuarios.agregar(u);/*agregamos a el metodo .agregar el usuario u*/
    totalusuarios++;/*aumentamos en uno el total de usuarios*/
}

void redsocial::estableceramistad(int idu1, int idu2) {/*inicializamos el metodo establecer amistad de la clase redsocial introducimos los 2 usuarios*/
    if(idu1 >=0 && idu1< totalusuarios && idu2>=0 && idu2< totalusuarios){/*si el usuario 1 es mayor a 0 y el usuario 1 es mayor a totalusuarios y
                                                                        el usuario 2 es mayor o igual a 0 y el usuario 2 es menor que el total de usuarios
                                                                        ingrese al condicional*/
        matrizadyacencia [idu1][idu2] = 1;/*registra que existe la amistad entre el usuario 1 y el usuario 2*/
        matrizadyacencia [idu2][idu1] = 1;/*registra que existe la amistrad entre el usuario 2 y el usuario 1 */
    }
}

bool redsocial::sonamigos(int idu1,int idu2) const {/*inicializamos el metodo sonamigos y introducimos el id de el usuario 1 y el usuario 2 */
    if (idu1 >= 0 && idu1 < totalusuarios && idu2 >= 0 && idu2< totalusuarios){/*si el usuario 1 es mayor o igual a 0 y el usuario 1 es menor que
                                                    el totalusuarios y el usuario 2 es mayot que 0 y el usuario 2 es menor que totalusuarios*/
        return matrizadyacencia[idu1][idu2]== 1;/*retornamos la matrizdeadyacencia para el usuario 1 y 2 si es igual a 1 retorna true */

    }
    return false;/*si no se cumple el condicional retorna que es falso */
}

int redsocial:: calcularamigosencomun(int idu1,int idu2) {/*inicializamos el metodo calcularamigos en comun
                en el cual realizamos un conteo de los amigos quitiene cada usuario en comun ejmplo el usuario 1 con el usuario 2*/
    int contador= 0;
    for (int k = 0; k < totalusuarios; ++k) {
        monitorderecurso::registrariteracion();
        if(matrizadyacencia[idu1][k]== 1 && matrizadyacencia[idu2][k]== 1){
            contador++;
        }
    }
    return contador;
}

void redsocial::cargarsolicitudesdesdearchivo(){/*cargamos las solicitudes de amistad existentes en el documento txt solicitudes.txt ya que
                            en este almacenamos las solicitudes de ayi extraemos la informacion de quien envio la solicitud a quien */
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

void redsocial::guardarsolicitudesenarchivo() {/*guardamos las solicitudes en el archivo solicitudes.txt */
    ofstream fsol("solicitudes.txt", ios::trunc);/*limpiamos el archivo con ios::trunc*/
    if(!fsol.is_open()) return;/*verificamos que el archivo si pueda abrirse*/

    for (int i = 0; i < usuarios.gettamaño(); ++i) {/*realizamos un ciclo dese 1= 0 hasta i-1 pocision hasta el total de usuarios que nos arroja
                                                        usuarios.gettamaño*/
        listaenteros& pendientes = usuarios[i].getsolicitudespendientes();/*busca cual es el usuario que tiene las solicitudes pendientes*/
        for (int j = 0; j < pendientes.gettamaño(); ++j) {
            int idemisor = pendientes[j];
            fsol << idemisor << " " << i << "\n";/*imprime cual es el usuario que tiene solicitudes pendientes*/
        }
    }
    fsol.close();
}

void redsocial ::cargardatosdesdearchivos() {/*cargamos los datos que tenemos en los archivos anteriormente llenados con la informacion de los 1000 usuarios*/

    ifstream fuser("usuarios.txt");
    if (fuser.is_open()) {/*si el archivo abre ingrese al condicional*/
        char u[64], em[128], fn[11], fot[256], ciu[64], pa[64];/*le asignamos arreglos a los diferentes variablos como lo son usuario,email,
                                                    fecha nacimiento,ruta foto ,ciudad,pais*/
        while (fuser.getline(u,64, ',')){/*extrae la informacion y la guarda en la variable u con un maximo de caracteres de 64 lo extrae hasta
                                        la primera coma*/
            fuser.getline(em,128,',');/*realiza lo mismo extrae la informacion siguiente la guarda en la variable hasta la proxima coma*/
            fuser.getline(fn,11,',');/*realiza lo mismo extrae la informacion siguiente la guarda en la variable hasta la proxima coma*/
            fuser.getline(fot,256,',');/*realiza lo mismo extrae la informacion siguiente la guarda en la variable hasta la proxima coma*/
            fuser.getline(ciu,64,',');/*realiza lo mismo extrae la informacion siguiente la guarda en la variable hasta la proxima coma*/
            fuser.getline(pa,64,'\n');/*realiza lo mismo extrae la informacion siguiente la guarda en la variable hasta el proximo salto de linea*/

            usuario userobj(u, em,fn,fot,ciu,pa);/*tomamos los datos de un usuario i  */
            registrarusuario(userobj);/*registramos el usuario que tomamos anterior mente y lo registramos en el metodo registrarusuario*/
        }
        fuser.close();
    }


    ifstream frel ("relaciones.txt");/*extraemos la informacion de relaciones txt en la cual se almacenan las amistades existentes*/
    if (frel.is_open()) {
        char u1[64], u2[64];/*creamos las variables con los arreglo para los usuarios pertinentes que seran extraidos de el documento txt*/
        while (frel.getline(u1,64,',')) {/*le asignamos a la variable u1 el primer usuario con un maximo de 64 caracteres y hasta la primera coma*/
            frel.getline(u2,64,'\n');/*le asignamos a la variable u2 el segundo usuario con un maximo de 64 caracteres y hasta el salto de linea*/
            int id1 = buscaridporusername(u1);/*buscamos el id del usuario y lo asignamos a la variable id1*/
            int id2 = buscaridporusername(u2);/*buscamos el id del segundo usuario y lo asignamos a la variable id2*/
            if (id1 != -1 && id2 != -1) {/*si id1 es diferente de -1 y id2 es diferente de -1 */
                estableceramistad(id1, id2);/*establecer amistad*/
            }
        }
        frel.close();
    }

    ifstream falb ("albumes.txt");
    if (falb.is_open()) {
        char prop[64], nomalb[64], rstorage[256], privstr[10];/*creamos las variables para propietario de el album , nombre del album , ruta de almacenamiento
                                                            privacidad del album , ruta de la foto , fecha de la foto , tamaño de la foto y cantidad de likes*/
        char rfoto [256], ffoto[11], tamstr [15], likesstr[15];

        while (falb.getline(prop,64,',')) {
            falb.getline(nomalb, 64, ',');
            falb.getline(rstorage,256,',');
            falb.getline(privstr,10,',');
            falb.getline(rfoto,256,',');
            falb.getline(ffoto,11,',');
            falb.getline(tamstr,15,',');
            falb.getline(likesstr, 15, '\n');

            int idowner = buscaridporusername(prop);
            if (idowner !=-1) {
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
        for (int i = 0; i< usuarios.gettamaño(); ++i) {
            for (int j = i +1; j< usuarios.gettamaño(); ++j) {
                if (matrizadyacencia [i][j] == 1) {
                    frel << usuarios[i].getusername()<< ","
                         << usuarios[j].getusername() << "\n";
                }
            }
        }
        frel.close();
    }

    ofstream falb("albumes.txt");
    if (falb.is_open()) {
        for (int i = 0; i < usuarios.gettamaño(); ++i) {
            listaalbumes& alblist = usuarios[i].getalbumes();
            for (int a = 0; a< alblist.gettamaño(); ++a) {
                album& alb = alblist[a];
                listafotos& ftlist = alb.getfotos();
                if(ftlist.gettamaño() ==0) {
                    falb << usuarios[i].getusername() << ","
                         << alb.getnombre() << ","
                         << alb.getrutastorage() << ","
                         << alb.getprivacidad()<< ",,,0,0\n";
                }else {
                    for (int f = 0; f< ftlist.gettamaño(); ++f) {
                        foto& ft=ftlist[f];
                        falb << usuarios[i].getusername() <<","
                             << alb.getnombre()<< ","
                             << alb.getrutastorage() << ","
                             << alb.getprivacidad()<< ","
                             << ft.getruta()<<","
                             << ft.getfecha()<<","
                             << ft.gettemañobytes()<<","
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
        fmsg.close();
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
            if (amigosencontrados == 3 )
                break;
        }
    }
    if (amigosencontrados== 0) {
        cout << "aun no tienes amigos registrados en la plataforma. \n";
    }
}


void redsocial::enviarsolicitudamistad(int idemisor,const char* usernamedestino) {
    int iddestino = buscaridporusername(usernamedestino);
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
    usuarios[iddestino].recibirsolicitud(idemisor);
    cout << "solicitud de amistad enviada con exito a " << usernamedestino << "\n";
}
void redsocial::aceptarsolicitudespendientes(int idusuarioactual){
    listaenteros& pendientes = usuarios[idusuarioactual].getsolicitudespendientes();
    if(pendientes.gettamaño() == 0 ) {
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
        int idaceptado = pendientes[seleccion - 1];
        estableceramistad(idusuarioactual, idaceptado);
        pendientes.eliminaren(seleccion-1);
        guardarsolicitudesenarchivo();
        guardardatosenarchivo();

        cout<< "ahora eres amigo de" << usuarios[idaceptado].getusername()<< "\n";
    }
}

void redsocial::visitarperfilamigo(int idusuarioactual, const char* usernameamigo) {
    monitorderecurso::reiniciariteraciones();
    int idamigo = buscaridporusername(usernameamigo);
    if(idamigo == -1 || !sonamigos(idusuarioactual,idamigo)) {
        cout << "error: el usuario no existe o no es tu amigo.";
        monitorderecurso::mostrarmetricas("visitar perfil de amigo");
        return;
    }

    usuario& amigo = usuarios[idamigo];
    listaalbumes& albumes = amigo.getalbumes();
    if (albumes.gettamaño() == 0 ) {
        cout << "el usuario no tiene albumes disponibles.";
        monitorderecurso::mostrarmetricas ("visitar perfil de amigo");
        return;
    }
    cout << "albumes de "<< amigo.getusername() << ":\n";
    for (int i = 0 ; i < albumes.gettamaño(); ++i) {
        monitorderecurso::registrariteracion();
        cout << (i+1)<< ". "<< albumes[i].getnombre();
        if (albumes[i].getprivacidad() == 0 ) cout << "(publico)\n";
        else if (albumes[i].getprivacidad() == 2 ) cout << "(amigos)\n";
        else cout << "(privado)\n";
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
    int idamigo = buscaridporusername(usernameamigo);
    if (idamigo== -1 || !sonamigos(idusuarioactual,idamigo)) {
        cout << "error: el usuario no existe o no es su amigo.";
        return;
    }
    usuario& amigo = usuarios[idamigo];
    album& album = amigo.getalbumes() [indicealbum];

    if (album.getprivacidad() == 1) {
        cout << "el album es privado.";
        monitorderecurso::mostrarmetricas("visitar perfil de amigo");
        return;
    }

    listafotos& fotos = album.getfotos();
    if (fotos.gettamaño() ==0) {
        cout << "el album esta vacion.";
        monitorderecurso:: mostrarmetricas("visitar perfil de amigo");
        return;
    }
    int idxfotoactual= 0;
    char opcion;

    do{
        foto& fotoactual = fotos[idxfotoactual];
        cout << "album: " << album.getnombre()<< "\n";
        cout << "foto ("<< idxfotoactual+1 << "/"<<fotos.gettamaño() << ")\n";
        cout  << fotoactual.getruta() << "\n";
        cout << "likes:" << fotoactual.getlikes()<< "\n";
        cout << "[n] siguiente | [p] previa | [l] dar like | [s] salir \n";
        cout << "opcion: ";
        cin >> opcion;

        monitorderecurso::registrariteracion();

        if (opcion == 'N' || opcion == 'n') {
            idxfotoactual = (idxfotoactual + 1) % fotos.gettamaño();
        } else if (opcion == 'P'|| opcion == 'p'){
            idxfotoactual = (idxfotoactual == 0 ) ? fotos.gettamaño() -1 : idxfotoactual-1;
        } else if (opcion == 'L' || opcion == 'l') {
            fotoactual.darlike();
            cout << "le diste like a la foto ";
        }

    }while (opcion != 'S' && opcion != 's');

    monitorderecurso::mostrarmetricas("visitar perfil de amigo");
}

void redsocial::mostrarsugerenciasamistad(int idusuarioactual,int k ) {
    monitorderecurso::reiniciariteraciones();

    int* candidatosids = new int [totalusuarios];
    int* coincidenciascore = new int[totalusuarios];
    monitorderecurso::registrarasignacion(sizeof(int)*totalusuarios * 2);
    int numcandidatos = 0;

    for (int i = 0; i < totalusuarios; ++i) {
        monitorderecurso::registrariteracion();
        if(i != idusuarioactual && !sonamigos(idusuarioactual, i)) {
            int score = calcularamigosencomun(idusuarioactual, i);
            if(score> 0) {
                candidatosids[numcandidatos] = i;
                coincidenciascore[numcandidatos] = score;
                numcandidatos++;
            }
        }
    }

    for (int i=0; i< numcandidatos - 1;++i) {
        for(int j = i + 1; j < numcandidatos; ++j) {
            monitorderecurso::registrariteracion();
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

    cout << k << "sugerencias de amistad: \n";
    int limite = (numcandidatos < k) ? numcandidatos : k;
    for ( int i = 0; i < limite ; ++i) {
        cout << (i + 1) << ". " << usuarios[candidatosids[i]].getusername()
        << " (" << coincidenciascore[i]<< " amigos en comun) \n ";

    }
    if (limite == 0) {
        cout << "no hay sugerencias de amistad para mostrar en este momento ";
    }


    monitorderecurso ::registrarliberacion(sizeof(int) * totalusuarios * 2);
    delete[] candidatosids;
    delete[] coincidenciascore;

    monitorderecurso::mostrarmetricas("ver sugerencias de amistad");

}

void redsocial::enviarmensaje(int idemisor, const char* usernamedestino, const char* texto) {
    int iddestino = buscaridporusername(usernamedestino);
    if (iddestino == -1 || !sonamigos(idemisor,iddestino)) {
        cout << "error: no existe el usuario o no es tu amigo. "<< "\n";
        return;
    }
    if (strlen(texto) == 0) {
        cout << "error: no se pueden enviar mensajes vacios."<< "\n";
        return;
    }
    mensaje msg(usuarios[idemisor].getusername(), usernamedestino, texto, "2026-10-15 11:00");
    usuarios[idemisor].enviarmensaje(msg);
    usuarios[iddestino].recibirmensaje(msg);
    cout << "mensaje enviado exitosamente a " << usernamedestino << "\n";
}

void redsocial::leernuevosmensajes(int idusuarioactual){
    listamensajes& mensajes = usuarios[idusuarioactual].getmensajesrecibidos();
    int noleidos = 0;
    cout << "mensajes nuevos ";
    for (int i = 0; i < mensajes.gettamaño(); ++i) {
        monitorderecurso::registrariteracion();
        if(!mensajes[i].isleido()) {
            cout << "de: " << mensajes[i].getemisor() <<"[ " << mensajes[i].getfechaenvio()  << "] \n";
            cout <<"texto: " << mensajes[i].getcontenido() << "\n";
            mensajes[i].marcarleido();
            noleidos++;
        }
    }
    if (noleidos == 0) {
        cout << "no tienes mensajes nuevos sin leer."<< "\n";
    }
}
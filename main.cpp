#include <iostream>
#include "redsocial.h"
#include "monitorderecursos.h"

using namespace std;

int main()
{

    cout << "inicio desafio2" << endl;
    redsocial red;

    monitorderecurso::reiniciarinteracciones();
    red.cargardatosdesdearchivo();
    monitorderecurso::mostrarmetricas();





    char usernameingresado[64];
    int idusuariosesion=-1;
    int opcionacceso =0;





    cout<<"UDEA@GOOK"<<endl<<endl;



    /* este ciclo nos va a servir para cada vez que falle el usuario y contraseña
       pueda volverloa intentar y tambien hacer registro
     */
    while (idusuariosesion==-1) {


        //primera parte pare el inicio de sesion

        cout<<"1. iniciar sesion";<<endl;
        cout<<"2. registro de usuario";<<endl;
        cout<<"3. salir";<<endl;
        cin>>opcionacceso;
        cout<<"la opcion seleccionada fue: "<<opcionacceso<<endl;


        if(opcionacceso==1){
            cout<<"nombre de usuario: ";
            cin>>usernameingresado;
            //}

        idusuariosesion=red.buscaridporusername(usernameingresado);

        if(idusuariosesion==-1){
            cout<<"usuario no encontrado, vuelva a intentarlo"<<endl;
        }else{
            cout<<"inicio exitoso"<<endl;
        }
    }

        else if(opcionacceso==2){

        char email[128];
        char fotoperfil[256];

        cout<<"registrar nuevo usuario"<<endl;
        cout<<"ingresa un nombre de usiario: ";
        cin>>usernameingresado;

        if (red.buscaridporusername(usernameingresado) != -1){
            cout<<"error en nombre de usuario "<<usernameingresado<<" ya existe"<<endl;

        }else {
            cout<<"ingresa un correo electronico: ";
            cin>>email;
            cout<<"ingresa foto de perfil o ruta";
            cin>>fotoperfil;

            usuario nuevousiario(usernameingresado, email, fotoperfil);
            red.registrarusuario(nuevousiario);

            idusuariosesion= red.buscaridporusername(usernameingresado);

            cout<<"usuario registrado";
        }

    }

    else if(opcionacceso==3){
        cout<<"fin de la sesion"<<endl;
        return 0;
    }else{
        cout<<"opcion no valida, intente nuevamente"<<endl;
    }




    //desde aqui empienza la parte de opciones
    char opcionmenu='0';

    do{
        red.mostrarmejoresamigos(idusuariosesion);

        cout<<"bienvenido "<<usernameingresado<<endl;
        cout<<"menu de opciones: "<<endl;

        cout<<"1. administrar amistades: "<<endl;
        cout<<"2. visitar perfil de amigos"<<endl;
        cout<<"3. sugerencias"<<endl;
        cout<<"4. mensajes"<<endl;
        cout<<"5. cambiar foto de perfil de amigos"<<endl;
        cout<<"6. salir"<<endl;
        
        cout<<"la opcion elegida fue"<<endl;

        
        
        cin >> opcionmenu;
        


//actualizacion o salida del programa
        if(opcionmenu=='5'){

            cout<<"actualizar foto de perfil";
            continue;
        }
        else if(opcionmenu=='6'){
            break;
        }


// funciones principales
        switch (opcionmenu) {
        case '1':{
            int subop=0;

            cout<<"1.enviar solicitud de amistad"<<endl<<"aceptar solicitud"<<endl;
            cin>>subop;
            cout<<"la opcion elegida fue: "<<subop<<endl;

            monitorderecurso::reiniciarinteracciones();//revisar bien esta la clase ya que la mia presento problemas
            if(subop==1){
                char amigodestino[64];
                cout<<"nombre a quien envia solicitud:";
                cin>>amigodestino;
                red.enviarsolicitudamistad(idusuariosesion, amigodestino);



            }else if(subop==2){

                red.aceptarsolicitudespendientes(idusuariosesion);

            }

            break;
        }

        case'2':{

            char amigouser[64];
            cout<<"pon el nombre del amigo que quiere ver:";
            cin>>amigouser;

            red.visitarperfilamigo(idusuariosesion, amigouser);
            break;
        }

        case'3':{ //esta parte quedo lista
            int K=0;

            cout<<"pon la cantidad de sugerencias a ver en el rango de 1 a 20";
            cin>>K;

            if(K>= 1 && K<=20){
                red.mostrarsugerenciasamistad(idusuariosesion, K);
            }
            else{
                cout<<"el valor ingresado esta fuera del rango estipulado";
            }
            break;

        }

        case '4':{

            int subop=0;

            cout<<"selecione una de las siguientes opciones: "<<endl<<endl;
            cout<<"1. enviar mensajes"<<endl<<"2.leer nuevo mensaje"<<endl;
            cout<<"3. buscar mensaje por fecha"<<endl;

            cin>>subop;


            if(subop==1){
                char destinatario[64];
                char texto[513];


                cout<<"nombre de usuario del destinatario: ";
                cin>>destinatario;

                //enviar el mensaje
                cout<<"escribir mensaje: ";
                cin.ignore();
                cin.getline(texto, 513);
                red.enviarmensaje(idusuariosesion, destinatario, texto);

            }else if(subop==2){
                red.leernuevosmensajes(idusuariosesion);

            }else if(subop==3) {
                char finicio[11], ffin[11];
                cout<< "fecha inicio: ";
                cin>>finicio;
                cout<<"fecha fin: ";
                cin>>ffin;
                red.buscarmensajesporrangofechas(idusuariosesion, finicio, ffin);
            }

            break;
        }

        default:

            cout<<"opcion invalida"<<endl;
            break;

        }

    }

    while(opcionmenu !='6' && opcionmenu != '5');

    cout<<"guardar cambios"<<endl;

    red.guardardatosenarchivos();
    cout<<"sesion cerrada";







    return 0;
}

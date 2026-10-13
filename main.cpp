#include <iostream>

using namespace std;

int main()
{

    cout << "inicio desafio2" << endl;
    redsocial red;

    monitorrecursos::reiniciarinteracciones();
    red.cargardatosdesdearchivo();

    monitorrecursos::mostrarmetricas;



    char usernameingresado[64];
    int idusuariosesion=-1;



    cout<<"UDEA@GOOK"<<endl<<endl;



    /* este ciclo nos va a servir para cada vez que falle el usuario y contraseña
       pueda volverloa intentar
     */
    while (idusuariosesion==-1) {

        cout<<"nombre de usuario: "<<endl;
        cin>>useringresado;

        idusuariosesion=red.buscaridporusername(usernameingresado);

        if(iduserusuario==-1){
            cout<<"usuario no encontrado, vuelva a intentarlo"<<endl;
        }
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

        cin>>opcionmenu;




    }



    return 0;
}

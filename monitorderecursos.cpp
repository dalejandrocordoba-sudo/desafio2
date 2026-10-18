#include "monitorderecursos.h"

using namespace std;

unsigned long monitorderecurso::memoriaconsumidabytes=0;
unsigned long long monitorderecurso::contadorinteraciones = 0;

void monitorderecurso::reiniciariteraciones(){
    contadorinteraciones=0;
}

void monitorderecurso::registrariteracion(unsigned long long cantidad){
    contadorinteraciones+= cantidad;
}

void monitorderecurso::registrarasignacion(unsigned long bytes){

    memoriaconsumidabytes +=bytes;
}

void monitorderecurso::registrarliberacion(unsigned long bytes){

    if(memoriaconsumidabytes >= bytes){

        memoriaconsumidabytes -= bytes;
    }
}

unsigned long long monitorderecurso::getiteraciones(){
    return contadorinteraciones;

}

unsigned long monitorderecurso::getmemoriabytes(){

    return memoriaconsumidabytes;
}

void monitorderecurso::mostrarmetricas(const char *nombrefuncionalidad){

    cout<<"cantidad de interacciones: "<<contadorinteraciones<<endl;
    cout<< "memoria utilizada: "<<memoriaconsumidabytes<<endl;
}









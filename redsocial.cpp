#include "redsocial.h"
#include "monitorderecursos"
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

redsocial ::redsocial() {
    totalusuarios =0;
    capacidadusuarios = 10;


    matrizadyacencia= new int*[capacidadusuarios];
    monitorrecursos::registrarasignacion(sizeof(int*)*capacidadusuarios);

    for (int i=0; i < capacidadusuarios; ++i){
        matrizadyacencia[i] = new int [capacidadusuarios];
        monitorrecursos::registrarasignacion(sizeof (int)* capacidadusuarios);
        for(int j=0; j< capacidadusuarios; ++j){
            matrizadyacencia[i][j]=0;

        }
    }
}

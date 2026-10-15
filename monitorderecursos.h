#include <iostream>
using namespace std;

#ifndef MONITORDERECURSOS_H
#define MONITORDERECURSOS_H

class monitorderecurso
{
private:
    static unsigned memoriaconsumidabytes;
    static unsigned contadorinteraciones;

public:
    static void reiniciariteraciones();
    static void registrariteracion(unsigned long long cantidad = 1);
    static void registrarasignacion(unsigned bytes);
    static void registrarliberacion(unsigned long bytes);
    static unsigned getiteraciones();
    static unsigned getmemoriabytes();
    static void mostrarmetricas(const char* nombrefuncionalidad);
    //monitorderecurso() {}
};


#endif // MONITORDERECURSOS_H

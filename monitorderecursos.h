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
    static void registrarasignacion(unsigned long bytes);
    static void registrarliberacion(unsigned long bytes);
    static unsigned long long getiteraciones();
    static unsigned long getmemoriabytes();
    static void mostrarmetricas(const char* nombrefuncionalidad);
    //monitorderecurso() {}
};


#endif // MONITORDERECURSOS_H

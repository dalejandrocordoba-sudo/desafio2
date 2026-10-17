#ifndef MENSAJE_H
#define MENSAJE_H

//clase revisada y no se encuentra problemas
class mensaje{

private:

    char emisor[64];
    char receptor[64];
    char contenido[513];
    char fechaenvio[20];
    bool leido;


public:
    mensaje();
    mensaje(const char* em, const char* rec, const char* cont, const char* fecha);
    const char* getemisor() const;
    const char* getfechaenvio() const;
    const char* getcontenido() const;
    bool isleido() const;
    void marcarleido();
    void setestadoleido();
    const char* getreceptor() const;


};//

#endif // MENSAJE_H

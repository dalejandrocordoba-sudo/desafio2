#ifndef FOTO_H
#define FOTO_H


class foto{

private:

    char rutaabsoluta[256];
    char fechacaptura[11];
    unsigned int tamanobytes;
    unsigned int likes;


public:
    foto();
    foto(const char* ruta, const char* fecha, unsigned int tamano);
    unsigned int gettemanobytes() const;
    unsigned int getlikes() const;

    const char* getruta() const;
    const char* getfecha() const;

    void setlikes(unsigned int nlikes);
    void darlike();
    void quitarlike();

}

#endif // FOTO_H

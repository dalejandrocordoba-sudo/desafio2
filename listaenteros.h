#ifndef LISTAENTEROS_H
#define LISTAENTEROS_H

class listaenteros {
private:
    int* datos;
    int capacidad;
    int tamaño;

    void redimensionar();

public:
    listaenteros();
    listaenteros(const listaenteros& otra);
    listaenteros& operator=(const listaenteros& otra);
    ~listaenteros();

    void agregar(int elemento);
    void eliminaren(int indice);
    void eliminarvalor(int valor);
    int obtener(int indice) const;
    int gettamaño() const;

    int& operator [] (int indice);
    const int& operator[](int indice) const;

};

#endif // LISTAENTEROS_H

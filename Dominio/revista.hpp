#ifndef TRABESTRUTURAM2_REVISTA_H
#define TRABESTRUTURAM2_REVISTA_H

#include <iostream>
#include <string>

using namespace std;

struct Revista{
    static int proxMat;
    int mat;
    int autor;
    int editora;
    string titulo;
    string genero;

    Revista();
    Revista(string titulo, int autor, int editora, string genero);
};

Revista::Revista() {
    mat = proxMat++;
    titulo = "";
    autor = 0;
    editora = 0;
    genero = "";
}

Revista::Revista(std::string titulo, int autor, int editora, std::string genero) {
    mat = proxMat++;
    this->titulo = titulo;
    this->autor = autor;
    this->editora = editora;
    this->genero = genero;
}

#endif //TRABESTRUTURAM2_REVISTA_H
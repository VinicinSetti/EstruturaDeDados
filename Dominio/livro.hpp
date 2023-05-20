#ifndef TRABESTRUTURAM2_LIVRO_H
#define TRABESTRUTURAM2_LIVRO_H

#include <iostream>
#include <string>

using namespace std;

struct Livro{
    static int proxMat;
    int mat;
    int autor;
    int editora;
    string titulo;
    string genero;

    Livro();
    Livro(string titulo, int autor, int editora, string genero);

};

Livro::Livro() {
    mat = proxMat++;
    titulo = "";
    autor = 0;
    editora = 0;
    genero = "";
}

Livro::Livro(std::string titulo, int autor, int editora, std::string genero) {
    mat = proxMat++;
    this->titulo = titulo;
    this->autor = autor;
    this->editora = editora;
    this->genero = genero;
}

#endif //TRABESTRUTURAM2_LIVRO_H

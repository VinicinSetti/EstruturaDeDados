#ifndef TRABESTRUTURAM2_LIVRO_H
#define TRABESTRUTURAM2_LIVRO_H

#include <iostream>
#include <string>

using namespace std;

struct Livro{
    Livro(string titulo, int autor, int editora, string genero, bool esprestado, string dataDoEmprestimo);

    static int proxMat;
    int mat;
    int autor;
    int editora;
    string titulo;
    string genero;
    bool alugado;
    string dataDoAluguel;

    Livro();
    Livro(string titulo, int autor, int editora, string genero);

    void definirEmprestimo(bool esmprestar);
    void dataRealizadaDoEmprestimo(string dataDoEmprestimo);

};

int Livro::proxMat = 0;

Livro::Livro() {
    this->mat = proxMat++;
    this->titulo = "";
    this->autor = 0;
    this->editora = 0;
    this->genero = "";
    this->alugado = false;
    this->dataDoAluguel = "";
}

Livro::Livro(string titulo, int autor, int editora, string genero, bool alugado, string dataDoAluguel) {
    this->mat = proxMat++;
    this->titulo = titulo;
    this->autor = autor;
    this->editora = editora;
    this->genero = genero;
    this->alugado = alugado;
    this->dataDoAluguel = dataDoAluguel;
}

void Livro::definirEmprestimo(bool alugado) {
    this->alugado = alugado;
}

void Livro::dataRealizadaDoEmprestimo(string dataDoAluguel) {
    this->dataDoAluguel = dataDoAluguel;
}

#endif //TRABESTRUTURAM2_LIVRO_H

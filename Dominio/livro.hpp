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
    bool alugado;
    string dataDoAluguel;
    int numEmprestado;

    Livro();
    Livro(string titulo, int autor, int editora, string genero, bool alugado, string dataDoAluguel);

    void definirEmprestimo(bool esmprestar);
    void dataRealizadaDoEmprestimo(string dataDoEmprestimo);
    void definirAutor(int autor);
    void definirEditora(int editora);
    void definirGenero(string genero);

};

int Livro::proxMat = 0;

Livro::Livro() {
    this->mat = proxMat++;
    this->titulo = "";
    this->autor = 0;
    this->editora = 0;
    this->genero = "";
    this->alugado = false;
    this->numEmprestado = 0;
    this->dataDoAluguel = "";
}

Livro::Livro(string titulo, int autor, int editora, string genero, bool alugado, string dataDoAluguel) {
    this->mat = proxMat++;
    this->titulo = titulo;
    this->autor = autor;
    this->editora = editora;
    this->genero = genero;
    this->alugado = alugado;
    this->numEmprestado = 0;
    this->dataDoAluguel = dataDoAluguel;
}

void Livro::definirEmprestimo(bool alugado) {
    this->alugado = alugado;
}

void Livro::dataRealizadaDoEmprestimo(string dataDoAluguel) {
    this->dataDoAluguel = dataDoAluguel;
}

void Livro::definirAutor(int autor) {
    this->autor = autor;
}

void Livro::definirEditora(int editora) {
    this->editora = editora;
}

void Livro::definirGenero(std::string genero) {
    this->genero = genero;
}
#endif //TRABESTRUTURAM2_LIVRO_H

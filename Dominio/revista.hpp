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
    bool alugado;
    string dataDoAluguel;
    int numEmprestado;

    Revista();
    Revista(string titulo, int autor, int editora, string genero);
    void definirEmprestimo(bool esmprestar);
    void dataRealizadaDoEmprestimo(string dataDoEmprestimo);
    void definirAutor(int autor);
    void definirEditora(int editora);
    void definirGenero(string genero);
};

int Revista::proxMat = 0;

Revista::Revista() {
    this->mat = proxMat++;
    this->titulo = "";
    this->autor = 0;
    this->editora = 0;
    this->genero = "";
    this->alugado = false;
    this->numEmprestado = 0;
    this->dataDoAluguel = "";
}

Revista::Revista(std::string titulo, int autor, int editora, std::string genero) {
    this->mat = proxMat++;
    this->titulo = titulo;
    this->autor = autor;
    this->editora = editora;
    this->genero = genero;
    this->alugado = false;
    this->numEmprestado = 0;
    this->dataDoAluguel = "";
}

void Revista::definirGenero(std::string genero) {
    this->genero = genero;
}

void Revista::definirEditora(int editora) {
    this->editora = editora;
}

void Revista::definirAutor(int autor) {
    this->autor = autor;
}

void Revista::definirEmprestimo(bool esmprestar) {
    this->alugado = esmprestar;
}

void Revista::dataRealizadaDoEmprestimo(std::string dataDoEmprestimo) {
    this->dataDoAluguel = dataDoEmprestimo;
}
#endif //TRABESTRUTURAM2_REVISTA_H
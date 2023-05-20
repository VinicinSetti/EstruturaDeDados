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
    bool emprestado;
    string dataDoEmprestimo;

    Livro();
    Livro(string titulo, int autor, int editora, string genero);

    void definirEmprestimo(bool esmprestar);
    void dataRealizadaDoEmprestimo(string dataDoEmprestimo);

};

Livro::Livro() {
    mat = proxMat++;
    titulo = "";
    autor = 0;
    editora = 0;
    genero = "";
    emprestado = false;
    dataDoEmprestimo = "";
}

Livro::Livro(string titulo, int autor, int editora, string genero, bool esprestado, string dataDoEmprestimo) {
    mat = proxMat++;
    this->titulo = titulo;
    this->autor = autor;
    this->editora = editora;
    this->genero = genero;
    this->emprestado = emprestado;
    this->dataDoEmprestimo = dataDoEmprestimo;
}

void Livro::definirEmprestimo(bool emprestar) {
    this->emprestado = emprestar;
}

void Livro::dataRealizadaDoEmprestimo(string dataDoEmprestimo) {

}

#endif //TRABESTRUTURAM2_LIVRO_H

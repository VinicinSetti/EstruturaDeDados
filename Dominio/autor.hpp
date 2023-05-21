#ifndef TRABESTRUTURAM2_AUTOR_H
#define TRABESTRUTURAM2_AUTOR_H

#include <iostream>
#include <string>
#include "../Funcoes/lista.h"

using namespace std;

struct Autor{
    static int proxMat;
    int mat;
    string nome;
    Lista<int> *livros;

    Autor();
    Autor(string nome);

    void adicionarLivro(int mat);
    void removerLivro(int mat);
};

int Autor::proxMat = 0;

Autor::Autor() {
    this->mat = Autor::proxMat++;
    this->nome = "";
    this->livros = new Lista<int>();
}

Autor::Autor(std::string nome) {
    this->mat = Autor::proxMat++;
    this->nome = nome;
    this->livros = new Lista<int>();
}

void Autor::adicionarLivro(int mat) {
    livros->inserir(mat);
}

void Autor::removerLivro(int mat) {
    livros->remover(mat);
}

#endif //TRABESTRUTURAM2_AUTOR_H

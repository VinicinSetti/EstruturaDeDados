#ifndef TRABESTRUTURAM2_EDITORA_H
#define TRABESTRUTURAM2_EDITORA_H

#include <iostream>
#include <string>
#include "../Funcoes/lista.h"

using namespace std;

struct Editora{
    static int proxMat;
    int mat;
    string nome;
    Lista<int> *livros;

    Editora();
    Editora(string nome);

    void adicionarLivro(int mat);
    void removerLivro(int mat);
};

int Editora::proxMat = 0;

Editora::Editora() {
    this->mat = proxMat++;
    this->nome = "";
}

Editora::Editora(string nome) {
    this->mat = proxMat++;
    this->nome = nome;
}

void Editora::adicionarLivro(int mat) {
    livros->inserir(mat);
}

void Editora::removerLivro(int mat) {
    livros->remover(mat);
}

#endif //TRABESTRUTURAM2_EDITORA_H

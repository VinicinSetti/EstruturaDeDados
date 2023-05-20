#ifndef TRABESTRUTURAM2_USUARIO_H
#define TRABESTRUTURAM2_USUARIO_H

#include <iostream>
#include <string>
#include "../Funcoes/lista.h"

using namespace std;

struct Usuario{
    static int proxMat;
    int mat;
    string nome;
    Lista<int> LivrosAlugados;

    Usuario();
    Usuario(string nome);
    void alugarLivro(int matLivro);
    void devolverLivro(int matLivro);
};

int Usuario::proxMat = 0;

Usuario::Usuario() {
    this->mat = proxMat++;
    this->nome = "";
    this->LivrosAlugados = Lista<int>();
}

Usuario::Usuario(string nome) {
    this->mat = proxMat++;
    this->nome = nome;
    this->LivrosAlugados = Lista<int>();
}

void Usuario::alugarLivro(int matLivro) {
    LivrosAlugados.inserir(matLivro);
}

void Usuario::devolverLivro(int matLivro) {
    LivrosAlugados.remover(matLivro);
}

#endif //TRABESTRUTURAM2_USUARIO_H

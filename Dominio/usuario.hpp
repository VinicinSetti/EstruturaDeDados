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
    Usuario();
    Usuario(string nome);
    Lista<int> LivrosAlugados;
    Lista<int> RevistasAlugadas;
    Lista<int> hitoricoLivrosAlugados;
    Lista<int> historicoRevistasAlugadas;

    void alugarLivro(int matLivro);
    void devolverLivro(int matLivro);
    void alugarRevista(int matRevista);
    void devolverRevista(int matRevista);
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
    hitoricoLivrosAlugados.inserir(matLivro);
}

void Usuario::devolverLivro(int matLivro) {
    LivrosAlugados.remover(matLivro);
}

void Usuario::alugarRevista(int matRevista) {
    RevistasAlugadas.inserir(matRevista);
    historicoRevistasAlugadas.inserir(matRevista);
}

void Usuario::devolverRevista(int matRevista) {
    RevistasAlugadas.remover(matRevista);
}

#endif //TRABESTRUTURAM2_USUARIO_H

#ifndef TRABESTRUTURAM2_USUARIO_H
#define TRABESTRUTURAM2_USUARIO_H

#include <iostream>
#include <string>
#include "../Utilidades/LinkedList/LinkedList.hpp"

using namespace std;

struct Usuario{
    static int proxMat;
    int mat;
    string nome;
    LinkedList<int> LivrosAlugados;

    Usuario();
    Usuario(string nome);
    void alugarLivro(int matLivro);
    void devolverLivro(int matLivro);
};

Usuario::Usuario() {
    this->mat = proxMat++;
    this->nome = "";
    this->LivrosAlugados = LinkedList<int>();
}

Usuario::Usuario(string nome) {
    this->mat = proxMat++;
    this->nome = nome;
    this->LivrosAlugados = LinkedList<int>();
}

void Usuario::alugarLivro(int matLivro) {
    LivrosAlugados.insert(matLivro);
}

void Usuario::devolverLivro(int matLivro) {
    LivrosAlugados.remove(matLivro);
}

#endif //TRABESTRUTURAM2_USUARIO_H

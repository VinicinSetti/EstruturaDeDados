#ifndef TRABESTRUTURAM2_EDITORA_H
#define TRABESTRUTURAM2_EDITORA_H

#include <iostream>
#include <string>
#include "Funcoes/lista.h"

using namespace std;

struct Editora{
    static int proxMat;
    int mat;
    string nome;
    Lista<int> *livro;

    Editora();
    Editora(string nome);
};

Editora::Editora() {
    this->mat = Editora::proxMat++;
    this->nome = "";
}

Editora::Editora(string nome) {
    this->mat = Editora::proxMat++;
    this->nome = nome;
}



#endif //TRABESTRUTURAM2_EDITORA_H

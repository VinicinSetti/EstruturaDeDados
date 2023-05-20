#ifndef TRABESTRUTURAM2_AUTOR_H
#define TRABESTRUTURAM2_AUTOR_H

#include <iostream>
#include <string>
#include "../Utilidades/LinkedList/LinkedList.hpp"

using namespace std;

struct Autor{
    static int proxMat;
    int mat;
    string nome;
    LinkedList<int> *livros;

    Autor();
    Autor(string nome);

};

int Autor::proxMat = 0;

Autor::Autor() {
    this->mat = Autor::proxMat++;
    this->nome = "";
    this->livros = new LinkedList<int>();
}

Autor::Autor(std::string nome) {
    this->mat = Autor::proxMat++;
    this->nome = nome;
    this->livros = new LinkedList<int>();
}

#endif //TRABESTRUTURAM2_AUTOR_H

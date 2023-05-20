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
    LinkedList<int> *books;

    Usuario();
    Usuario(string nome);

};

#endif //TRABESTRUTURAM2_USUARIO_H

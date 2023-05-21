#ifndef TRABESTRUTURAM2_EDITORA_H
#define TRABESTRUTURAM2_EDITORA_H

#include <iostream>
#include <string>
#include "../Funcoes/lista.h"

using namespace std;

struct Editora{ //struct Editora, onde foram declarados os atributos necessarios e algumas funcoes
    static int proxMat;
    int mat;
    string nome;
    Lista<int> *livros;

    Editora();
    Editora(string nome);

    void adicionarLivro(int mat);
    void removerLivro(int mat);
};

int Editora::proxMat = 0; //inicializacao da variavel, a fim de nao pegar lixo de memoria

Editora::Editora() { //metodo contrutor basico do meu autor
    this->mat = proxMat++;
    this->nome = "";
}

Editora::Editora(string nome) { //Sobrecarga no metodo contrutor, com a informacao do nome
    this->mat = proxMat++;
    this->nome = nome;
}

void Editora::adicionarLivro(int mat) { //Adicionar os livros de dominio desta editora
    livros->inserir(mat);
}

void Editora::removerLivro(int mat) { //Remover os livros de dominio desta editora
    livros->remover(mat);
}

#endif //TRABESTRUTURAM2_EDITORA_H
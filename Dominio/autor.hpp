#ifndef TRABESTRUTURAM2_AUTOR_H
#define TRABESTRUTURAM2_AUTOR_H

#include <iostream>
#include <string>
#include "../Funcoes/lista.h"

using namespace std;

struct Autor{ //struct Autor, onde foram declarados os atributos necessarios e algumas funcoes
    static int proxMat;
    int mat;
    string nome;
    Lista<int> *livros;

    Autor();
    Autor(string nome);

    void adicionarLivro(int mat);
    void removerLivro(int mat);
};

int Autor::proxMat = 0; //inicializacao da variavel, a fim de nao pegar lixo de memoria

Autor::Autor() { //metodo contrutor basico do meu autor
    this->mat = Autor::proxMat++;
    this->nome = "";
    this->livros = new Lista<int>();
}

Autor::Autor(std::string nome) { //Sobrecarga no metodo contrutor, com a informacao do nome
    this->mat = Autor::proxMat++;
    this->nome = nome;
    this->livros = new Lista<int>();
}

void Autor::adicionarLivro(int mat) { //Adicionar os livros de dominio deste autor
    livros->inserir(mat);
}

void Autor::removerLivro(int mat) { //Remover os livros de dominio deste autor
    livros->remover(mat);
}

#endif //TRABESTRUTURAM2_AUTOR_H

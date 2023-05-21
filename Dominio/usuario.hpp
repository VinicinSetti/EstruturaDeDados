#ifndef TRABESTRUTURAM2_USUARIO_H
#define TRABESTRUTURAM2_USUARIO_H

#include <iostream>
#include <string>
#include "../Funcoes/lista.h"

using namespace std;

struct Usuario{ //struct Usuario, foram declarados os atributos necessarios e algumas funcoes para funcionamento do codigo
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

int Usuario::proxMat = 0; //inicializacao da variavel, a fim de nao pegar lixo de memoria

Usuario::Usuario() {  //metodo contrutor basico de Usuario
    this->mat = proxMat++;
    this->nome = "";
    this->LivrosAlugados = Lista<int>();
}

Usuario::Usuario(string nome) { //Sobrecarga no meu metodo construtor de Usuario, para salvamento das informacoes de seu cadastro
    this->mat = proxMat++;
    this->nome = nome;
    this->LivrosAlugados = Lista<int>();
}

void Usuario::alugarLivro(int matLivro) {  //irá inserir a matricula do livro na lista de livros que estao alugados e adicionar no historico de livros pegos emprestado.
    LivrosAlugados.inserir(matLivro);
    hitoricoLivrosAlugados.inserir(matLivro);
}

void Usuario::devolverLivro(int matLivro) { //irá remover da lista de livros que estao em posse do usuario
    LivrosAlugados.remover(matLivro);
}

void Usuario::alugarRevista(int matRevista) { //irá inserir a matricula do revistas na lista de livros que estao alugados e adicionar no historico de livros pegos emprestado.
    RevistasAlugadas.inserir(matRevista);
    historicoRevistasAlugadas.inserir(matRevista);
}

void Usuario::devolverRevista(int matRevista) { //irá remover da lista de revistas que estao em posse do usuario
    RevistasAlugadas.remover(matRevista);
}

#endif //TRABESTRUTURAM2_USUARIO_H
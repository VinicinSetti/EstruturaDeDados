#ifndef TRABESTRUTURAM2_CONTROLADOR_H
#define TRABESTRUTURAM2_CONTROLADOR_H

#include <iostream>
#include <string>
#include "autor.hpp"
#include "editora.hpp"
#include "livro.hpp"
#include "revista.hpp"
#include "usuario.hpp"
#include "usuario.hpp"
#include "../Funcoes/data.h"
#include "../Funcoes/hash.h"
#include "../Funcoes/lista.h"

using namespace std;

struct Controlador{
    Hash<int, Usuario> *usuarios;
    Hash<int, Autor> *autores;
    Hash<int, Editora> *editoras;
    Hash<int, Livro> *livros;
    Hash<int, Revista> *revistas;

    Controlador();
    ~Controlador();

    void adicionarAutor(Autor autor);
    void removerAutor(int mat);
    void mostrarAutor(int mat);

    void adicionarEditora(Editora editora);
    void removerEditora(int mat);
    void mostrarEditora(int mat);

    void adicionarLivro(Livro livro);
    void removerLivro(int mat);
    void mostrarLivro(int mat);

    void adicionarRevista(Revista revista);
    void removerRevista(int mat);
    void mostrarRevista(int mat);

    void adicionarUsuario(Usuario usuario);
    void removerUsuario(int mat);
    void mostarUsuario(int mat);
    void alugarLivro(int matUsuario, int matLivro);
    void devolverLivro(int matUsuario, int matLivro);
};

Controlador::Controlador() {
    autores = new Hash<int, Autor>();
    editoras = new Hash<int, Editora>();
    livros = new Hash<int, Livro>();
    revistas = new Hash<int, Revista>();
}

Controlador::~Controlador(){
    delete autores;
    delete editoras;
    delete livros;
    delete revistas;
}

void Controlador::adicionarAutor(Autor autor) {
    autores->inserir(autor.mat, autor);
}

void Controlador::removerAutor(int mat) {
    autores->remover(mat);
}

void Controlador::mostrarAutor(int mat) {
    cout<<"Autor matricula: "<<autores->get(mat)->mat<<endl;
    cout<<"Nome do Autor: "<<autores->get(mat)->nome<<endl;
    cout<<"Livros deste autor:"<<endl;
    Lista<int> *livros = autores->get(mat)->livros;
    for (int i = 0; i < livros->tamLista; ++i) {
        cout<<this->livros->get(livros->get(i))->titulo<<endl;
    }
}

void Controlador::adicionarEditora(Editora editora) {
    editoras->inserir(editora.mat, editora);
}

void Controlador::removerEditora(int mat) {
    editoras->remover(mat);
}

void Controlador::mostrarEditora(int mat) {
    cout<<"Nº da Matricula da Editora: "<<editoras->get(mat)->mat<<endl;
    cout<<"Nome da Editora: "<<editoras->get(mat)->nome<<endl;
    cout<<"Livros desta editora:"<< endl;
    Lista<int> *livros = editoras->get(mat)->livro;
    for (int i = 0; i < livros->tamLista; ++i) {
        cout<<this->livros->get(livros->get(i))->titulo<<endl;
    }
}

void Controlador::adicionarLivro(Livro livro) {
    livros->inserir(livro.mat, livro);
}

void Controlador::removerLivro(int mat) {
    livros->remover(mat);
}

void Controlador::mostrarLivro(int mat) {
    cout<<"Matricula do Livro: "<<livros->get(mat)->mat<<endl;
    cout<<"Titulo do Livro: "<<livros->get(mat)->titulo<<endl;
    cout<<"Genero do Livro: "<<livros->get(mat)->genero<<endl;
    cout<<"Editora do Livro: "<<editoras->get(livros->get(mat)->editora)->nome<<endl;
    cout<<"Autor do livro: "<<autores->get(livros->get(mat)->autor)->nome<<endl;
}

void Controlador::adicionarUsuario(Usuario usuario) {
    usuarios->inserir(usuario.mat, usuario);
}
void Controlador::removerUsuario(int mat) {
    usuarios->remover(mat);
}
void Controlador::mostarUsuario(int mat) {
    cout<<"Matricula do Usuario: "<<usuarios->get(mat)->mat<<endl;
    cout<<"Nome do Usuario: "<<usuarios->get(mat)->nome<<endl;
    cout<<"Livros do Usuario:"<<endl;
    Lista<int> livros = usuarios->get(mat)->LivrosAlugados;
    for (int i = 0; i < livros.tamLista; ++i) {

    }
}

void Controlador::adicionarRevista(Revista revista) {
    revistas->inserir(revista.mat, revista);
}
void Controlador::removerRevista(int mat) {
    revistas->remover(mat);
}
void Controlador::mostrarRevista(int mat) {
    cout<<"Matricula da Revista: "<<revistas->get(mat)->mat<<endl;
    cout<<"Titulo da Revista: "<<revistas->get(mat)->titulo<<endl;
    cout<<"Genero da Revista: "<<revistas->get(mat)->genero<<endl;
    cout<<"Editora da Revista: "<<revistas->get(mat)->editora<<endl;
    cout<<"Autor da Revista: "<<revistas->get(mat)->autor<<endl;
}

#endif //TRABESTRUTURAM2_CONTROLADOR_H

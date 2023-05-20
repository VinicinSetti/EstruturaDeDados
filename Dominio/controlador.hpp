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
    LinkedList<int> *livros = autores->get(mat)->livros;
    for (int i = 0; i < livros->getSize(); ++i) {
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
    LinkedList<int> *livros = editoras->get(mat)->livro;
    for (int i = 0; i < livros->getSize(); ++i) {
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
    cout<<"";
}

void Controlador::adicionarUsuario(Usuario usuario) {
    usuarios->inserir(usuario.mat, usuario);
}

#endif //TRABESTRUTURAM2_CONTROLADOR_H

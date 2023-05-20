#ifndef TRABESTRUTURAM2_CONTROLADOR_H
#define TRABESTRUTURAM2_CONTROLADOR_H

#include <iostream>
#include <string>
#include "autor.hpp"
#include "editora.hpp"
#include "livro.hpp"
#include "revista.hpp"
#include "usuario.hpp"
#include "../Utilidades/HashTable/HashTable.hpp"

using namespace std;

struct Controlador{
    HashTable<int, Usuario> *usuarios;
    HashTable<int, Autor> *autores;
    HashTable<int, Editora> *editoras;
    HashTable<int, Livro> *livros;
    HashTable<int, Revista> *revistas;

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
    autores = new HashTable<int, Autor>();
    editoras = new HashTable<int, Editora>();
    livros = new HashTable<int, Livro>();
    revistas = new HashTable<int, Revista>();
}

Controlador::~Controlador(){
    delete autores;
    delete editoras;
    delete livros;
    delete revistas;
}

void Controlador::adicionarAutor(Autor autor) {
    autores->insert(autor.mat, autor);
}

void Controlador::removerAutor(int mat) {
    autores->remove(mat);
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
    editoras->insert(editora.mat, editora);
}

void Controlador::removerEditora(int mat) {
    editoras->remove(mat);
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
    livros->insert(livro.mat, livro);
}

void Controlador::removerLivro(int mat) {
    livros->remove(mat);
}

void Controlador::mostrarLivro(int mat) {
    cout<<"Matricula do Livro: "<<livros->get(mat)->mat<<endl;
    cout<<"Titulo do Livro: "<<livros->get(mat)->titulo<<endl;
    cout<<"Genero do Livro: "<<livros->get(mat)->genero<<endl;
    cout<<"Editora do Livro: "<<editoras->get(livros->get(mat)->editora)->nome<<endl;
    cout<<"Autor do livro: "<<autores->get(livros->get(mat)->autor)->nome<<endl;
}

void Controlador::adicionarUsuario(Usuario usuario) {
    usuarios->insert(usuario.mat, usuario);
}
void Controlador::removerUsuario(int mat) {
    usuarios->remove(mat);
}
void Controlador::mostarUsuario(int mat) {
    cout<<"Matricula do Usuario: "<<usuarios->get(mat)->mat<<endl;
    cout<<"Nome do Usuario: "<<usuarios->get(mat)->nome<<endl;
    cout<<"Livros do Usuario:"<<endl;
    LinkedList<int> livros = usuarios->get(mat)->livros;
}

#endif //TRABESTRUTURAM2_CONTROLADOR_H

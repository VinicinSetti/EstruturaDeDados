#ifndef TRABESTRUTURAM2_CONTROLADOR_H
#define TRABESTRUTURAM2_CONTROLADOR_H

#include <iostream>
#include <string>
#include "autor.hpp"
#include "editora.hpp"
#include "livro.hpp"
#include "revista.hpp"
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
    void alugarLivro(int matUsuario, int matLivro, string data);
    void devolverLivro(int matUsuario, int matLivro);
    void mostrarLivrosAlugados(int matUsuario);
    void alugarRevista(int matUsuario, int matRevista, string data);
    void devolverRevista(int matUsuario, int matRevista);
    void mostrarRevistasAlugadas(int matUsuario);

    void mostrarHistoricoLivros(int mat);
    void mostrarHistoricoRevista(int mat);
    void mostrarLivrosGenero(string genero);
    void mostrarRevistasGenero(string genero);
    void mostrarLivrosAtrasados();
    void mostrarRevistasAtrasadas();
    void mostrarLivroAutor(string autor);
    void mostrarLivroEditora(string editora);
    void mostrarRevistaEditora(string editora);
    void mostrarRevistaAutor(string autor);

    void mostrarLivros();
    void mostrarRevistas();
};

Controlador::Controlador() {
    this->autores = new Hash<int, Autor>();
    this->editoras = new Hash<int, Editora>();
    this->livros = new Hash<int, Livro>();
    this->revistas = new Hash<int, Revista>();
    this->usuarios = new Hash<int, Usuario>();
}


void Controlador::adicionarAutor(Autor autor) {
    autores->inserir(autor.mat, autor);
}

void Controlador::removerAutor(int mat) {
    if(!autores->get(mat)){
        cout << "Este autor não foi encontrado" << endl;
    }
    autores->remover(mat);
}

void Controlador::mostrarAutor(int mat) {
    cout<<"Nº da matricula do Autor: "<<autores->get(mat)->mat<<endl;
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
    if(!editoras->get(mat)){
        cout << "Editora não encontrada" << endl;
    }
    editoras->remover(mat);
}

void Controlador::mostrarEditora(int mat) {
    cout<<"Nº da Matricula da Editora: "<<editoras->get(mat)->mat<<endl;
    cout<<"Nome da Editora: "<<editoras->get(mat)->nome<<endl;
    cout<<"Livros desta editora:"<< endl;
    Lista<int> *livros = editoras->get(mat)->livros;
    for (int i = 0; i < livros->tamLista; ++i) {
        cout<<this->livros->get(livros->get(i))->titulo<<endl;
    }
}

void Controlador::adicionarLivro(Livro livro) {
    autores->get(livro.autor)->adicionarLivro(livro.mat);
    editoras->get(livro.editora)->adicionarLivro(livro.mat);
    livros->inserir(livro.mat, livro);
}

void Controlador::removerLivro(int mat) {
    if(!livros->get(mat)){
        cout << "Livro não encontrado" << endl;
    }

    autores->get(livros->get(mat)->autor)->removerLivro(mat);
    editoras->get(livros->get(mat)->editora)->removerLivro(mat);
    if(livros->get(mat)->alugado){
        usuarios->get(livros->get(mat)->numEmprestado)->devolverLivro(mat);
    }
    livros->remover(mat);
}

void Controlador::mostrarLivro(int mat) {
    cout<<"Matricula do Livro: "<<livros->get(mat)->mat<<endl;
    cout<<"Titulo do Livro: "<<livros->get(mat)->titulo<<endl;
    cout<<"Genero do Livro: "<<livros->get(mat)->genero<<endl;
    cout<<"Editora do Livro: "<<editoras->get(livros->get(mat)->editora)->nome<<endl;
    cout<<"Autor do livro: "<<autores->get(livros->get(mat)->autor)->nome<<endl;
    if(livros->get(mat)->alugado){
        cout << "livro foi alugado | Data de aluguel: "<< livros->get(mat)->dataDoAluguel << endl;
    } else {
      cout << "Livro disponivel para ser alugada!"<<endl;
    }
}

void Controlador::adicionarUsuario(Usuario usuario) {
    usuarios->inserir(usuario.mat, usuario);
}

void Controlador::removerUsuario(int mat) {
    if(!usuarios->get(mat)){
        cout << "Usuario não encontrado" << endl;
    }
    usuarios->remover(mat);
}

void Controlador::mostarUsuario(int mat) {
    cout<<"Matricula do Usuario: "<<usuarios->get(mat)->mat<<endl;
    cout<<"Nome do Usuario: "<<usuarios->get(mat)->nome<<endl;
    cout<<"Livros do Usuario:"<<endl;
    Lista<int> livros = usuarios->get(mat)->LivrosAlugados;
    for (int i = 0; i < livros.tamLista; ++i) {
        cout<<this->livros->get(livros.get(i))->titulo<<endl;
    }
}

void Controlador::adicionarRevista(Revista revista) {
    autores->get(revista.autor)->adicionarLivro(revista.mat);
    editoras->get(revista.editora)->adicionarLivro(revista.mat);
    revistas->inserir(revista.mat, revista);
}
void Controlador::removerRevista(int mat) {
    if(!revistas->get(mat)){
        cout << "Revista não encontrada" << endl;
    }

    autores->get(revistas->get(mat)->autor)->removerLivro(mat);
    editoras->get(revistas->get(mat)->editora)->removerLivro(mat);
    if(revistas->get(mat)->alugado){
        usuarios->get(revistas->get(mat)->numEmprestado)->devolverRevista(mat);
    }
    revistas->remover(mat);
}
void Controlador::mostrarRevista(int mat) {
    cout<<"Matricula da Revista: "<<revistas->get(mat)->mat<<endl;
    cout<<"Titulo da Revista: "<<revistas->get(mat)->titulo<<endl;
    cout<<"Genero da Revista: "<<revistas->get(mat)->genero<<endl;
    cout<<"Editora da Revista: "<<revistas->get(mat)->editora<<endl;
    cout<<"Autor da Revista: "<<revistas->get(mat)->autor<<endl;
    if(revistas->get(mat)->alugado){
        cout << "Revista foi alugado | Data de aluguel: "<< revistas->get(mat)->dataDoAluguel << endl;
    } else {
        cout << "Revista disponivel para ser alugada!"<<endl;
    }
}

void Controlador::mostrarHistoricoLivros(int mat) {
    cout<<"Matricula do Usuario: "<<usuarios->get(mat)->mat<<endl;
    cout<<"Nome do Usuario: "<<usuarios->get(mat)->nome<<endl;
    cout<<"Livros do Usuario:"<<endl;
    Lista<int> livros = usuarios->get(mat)->hitoricoLivrosAlugados;
    for (int i = 0; i < livros.tamLista; ++i) {
        cout<<this->livros->get(livros.get(i))->titulo<<endl;
    }
}

void Controlador::mostrarHistoricoRevista(int mat) {
    cout<<"Matricula do Usuario: "<<usuarios->get(mat)->mat<<endl;
    cout<<"Nome do Usuario: "<<usuarios->get(mat)->nome<<endl;
    cout<<"Revistas Alugadas:"<<endl;
    Lista<int> revistas = usuarios->get(mat)->RevistasAlugadas;
    for (int i = 0; i < revistas.tamLista; ++i) {
        cout<<this->revistas->get(revistas.get(i))->titulo<<endl;
    }
}

void Controlador::mostrarLivros() {
    for (int i = 0; i < livros->tamHash2; ++i) {
        if(livros->get(i) == nullptr) {
            return;
        }else{
            cout << livros->get(i)->mat << " - " << livros->get(i)->titulo << endl;
        }
    }
}

void Controlador::mostrarRevistas() {
    for (int i = 0; i < revistas->tamHash2; ++i) {
        if(revistas->get(i) == nullptr) {
            return;
        }else{
            cout << revistas->get(i)->mat << " - " << revistas->get(i)->titulo << endl;
        }
    }
}

void Controlador::alugarLivro(int matUsuario, int matLivro, std::string data) {
    if (ValidaData(data) == false) {
        cout << "Data inserida invalida" << endl;
        return;
    }
    Usuario* usuario = usuarios->get(matUsuario);
    if (!usuarios) {
        cout << "Usuario não foi encontrado" << endl;
        return;
    }
    Livro* livro = livros->get(matLivro);
    if (!livro) {
        cout << "Livro não foi encotrado" << endl;
        return;
    }
    if (livro->alugado) {
        cout << "Este livro está alugado no momento" << endl;
        return;
    }
    usuario->alugarLivro(matLivro);
    livro->definirEmprestimo(true);
    livro->dataRealizadaDoEmprestimo(data);
    cout << "O livro desejado foi alugado com sucesso!" << endl;
}

void Controlador::alugarRevista(int matUsuario, int matRevista, std::string data) {
    if (ValidaData(data) == false) {
        cout << "Data inserida invalida" << endl;
        return;
    }
    Usuario* usuario = usuarios->get(matUsuario);
    if (!usuarios) {
        cout << "Usuario não foi encontrado" << endl;
        return;
    }
    Revista* revista = revistas->get(matRevista);
    if (!revista) {
        cout << "Livro não foi encotrado" << endl;
        return;
    }
    if (revista->alugado) {
        cout << "Este livro está alugado no momento" << endl;
        return;
    }
    usuario->alugarRevista(matRevista);
    revista->definirEmprestimo(true);
    revista->dataRealizadaDoEmprestimo(data);
    cout << "A revista desejada foi alugada com sucesso!" << endl;
}

void Controlador::devolverLivro(int matUsuario, int matLivro) {
    Usuario* usuario = usuarios->get(matUsuario);
    if (!usuarios) {
        cout << "Usuario não foi encontrado" << endl;
        return;
    }
    Livro* livro = livros->get(matLivro);
    if (!livro) {
        cout << "Livro não foi encotrado" << endl;
        return;
    }
    if (!livro->alugado) {
        cout << "Este livro está alugado no momento" << endl;
        return;
    }
    usuario->devolverLivro(matLivro);
    livro->definirEmprestimo(false);
    livro->dataRealizadaDoEmprestimo("");
    cout << "O livro foi devolvido de acordo" << endl;
}

void Controlador::devolverRevista(int matUsuario, int matRevista) {
    Usuario* usuario = usuarios->get(matUsuario);
    if (!usuarios) {
        cout << "Usuario não foi encontrado" << endl;
        return;
    }
    Revista* revista = revistas->get(matRevista);
    if (!revista) {
        cout << "Livro não foi encotrado" << endl;
        return;
    }
    if (!revista->alugado) {
        cout << "Este livro está alugado no momento" << endl;
        return;
    }
    usuario->devolverRevista(matRevista);
    revista->definirEmprestimo(false);
    revista->dataRealizadaDoEmprestimo("");
    cout << "A revista foi devolvida de acordo" << endl;
}

void Controlador::mostrarLivrosGenero(std::string genero) {
    cout << "Livros com este genero: "<< genero << endl;
    for (int i = 0; i < livros->tamHash2; ++i) {
        if (livros->get(i) == nullptr){
            cout<<"Mais nenhum livro foi encontrado"<<endl;
            return;
        }else{
            if (livros->get(i)->genero == genero){
                cout << livros->get(i)->mat << " - " << livros->get(i)->titulo << endl;
            }
        }
    }
}

void Controlador::mostrarRevistasGenero(std::string genero) {
    cout << "Revistas com este genero: "<< genero << endl;
    for (int i = 0; i < revistas->tamHash2; ++i) {
        if (revistas->get(i) == nullptr){
            cout<<"Mais nenhum livro foi encontrado"<<endl;
            return;
        }else{
            if (revistas->get(i)->genero == genero){
                cout << revistas->get(i)->mat << " - " << revistas->get(i)->titulo << endl;
            }
        }
    }
}

void Controlador::mostrarLivroAutor(std::string autor) {
    cout << "Livros deste autor: "<< autor << endl;
    for (int i = 0; i < livros->tamHash2; ++i) {
        if (livros->get(i) == nullptr){
            cout<<"Mais nenhum livro foi encontrado"<<endl;
            return;
        }else{
            for (int j = 0; j < autores->tamHash2; ++j) {
            if (livros->get(i)->autor == autores->get(j)->mat && autores->get(j)->nome == autor){
                cout << livros->get(i)->mat << " - " << livros->get(i)->titulo << endl;
            }
            }
        }
    }
}

void Controlador::mostrarRevistaAutor(std::string autor) {
    cout << "Revistas deste autor: "<< autor << endl;
    for (int i = 0; i < revistas->tamHash2; ++i) {
        if (revistas->get(i) == nullptr){
            cout<<"Mais nenhum livro foi encontrado"<<endl;
            return;
        }else{
            for (int j = 0; j < autores->tamHash2; ++j) {
                if (revistas->get(i)->autor == autores->get(j)->mat && autores->get(j)->nome == autor){
                    cout << revistas->get(i)->mat << " - " << revistas->get(i)->titulo << endl;
                }
            }
        }
    }
}

void Controlador::mostrarLivroEditora(std::string editora) {
    cout << "Livros desta editora: "<< editora << endl;
    for (int i = 0; i < livros->tamHash2; ++i) {
        if (livros->get(i) == nullptr){
            cout<<"Mais nenhum livro foi encontrado"<<endl;
            return;
        }else{
            for (int j = 0; j < editoras->tamHash2; ++j) {
                if (livros->get(i)->autor == editoras->get(j)->mat && editoras->get(j)->nome == editora){
                    cout << livros->get(i)->mat << " - " << livros->get(i)->titulo << endl;
                }
            }
        }
    }
}

void Controlador::mostrarRevistaEditora(std::string editora) {
    cout << "Revistas deste autor: "<< editora << endl;
    for (int i = 0; i < revistas->tamHash2; ++i) {
        if (revistas->get(i) == nullptr){
            cout<<"Mais nenhum livro foi encontrado"<<endl;
            return;
        }else{
            for (int j = 0; j < editoras->tamHash2; ++j) {
                if (revistas->get(i)->autor == editoras->get(j)->mat && editoras->get(j)->nome == editora){
                    cout << revistas->get(i)->mat << " - " << revistas->get(i)->titulo << endl;
                }
            }
        }
    }
}

void Controlador::mostrarLivrosAtrasados(int matUsuario, string data) {
    Lista<int> livros = usuarios->get(matUsuario)->LivrosAlugados;
    for (int i = 0; i < livros.tamLista; ++i) {
        if(this->livros.get(livros.get(i))->alugado == true && ValidaData(this->livros->get(livros.get(i))->dataDoAluguel) <
                                                                           ValidaData(data)){
            cout << this->livros->get(livros.get(i))->mat << " - " << this->livros->get(livros.get(i))->titulo << " - " << this->livros->get(revistas.get(i))->dataDoAluguel << endl;
        }
    }
}

void Controlador::mostrarRevistasAtrasadas() {
    Lista<int> revistas = usuarios->get(matUsuario)->RevistasAlugadas;
    for (int i = 0; i < revistas.tamLista; ++i) {
        if(this->revistas.get(revistas.get(i))->alugado == true && ValidaData(this->revistas->get(revistas.get(i))->dataDoAluguel) <
                                                                   ValidaData(data)){
            cout << this->revistas->get(revistas.get(i))->mat << " - " << this->revistas->get(revistas.get(i))->titulo << " - " << this->revistas->get(revistas.get(i))->dataDoAluguel << endl;
        }
    }
}

#endif //TRABESTRUTURAM2_CONTROLADOR_H
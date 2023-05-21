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

struct Controlador{ //Declaracoes das tabelas Hash que serao usadas, alem da funcoes para o funcionamento deste sistema
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
    void mostrarUsuario(int mat);
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
    void mostrarLivrosAtrasados(int matUsuario, string data);
    void mostrarRevistasAtrasadas(int matUsuario, string data);
    void mostrarLivroAutor(string autor);
    void mostrarLivroEditora(string editora);
    void mostrarRevistaEditora(string editora);
    void mostrarRevistaAutor(string autor);

    void mostrarLivros();
    void mostrarRevistas();
};

Controlador::Controlador() { //Metodo construtor do Controlador, para inicializacao das tabelas hash
    this->autores = new Hash<int, Autor>();
    this->editoras = new Hash<int, Editora>();
    this->livros = new Hash<int, Livro>();
    this->revistas = new Hash<int, Revista>();
    this->usuarios = new Hash<int, Usuario>();
}


void Controlador::adicionarAutor(Autor autor) { //pega a tabela hash "autores" e insere na posicao da matricuda de autor o valor de autor
    autores->inserir(autor.mat, autor);
}

void Controlador::removerAutor(int mat) { //verificar se na possicao informada possui algum valor cadastrado, se tiver, ele remove este valor
    if(!autores->get(mat)){
        cout << "Este autor não foi encontrado" << endl;
    }
    autores->remover(mat);
}

void Controlador::mostrarAutor(int mat) { //busca a posicao informada do autor para mostrar o numeroda matricula, nome e os livros cadastrados deste autor
    cout<<"Nº da matricula do Autor: "<<autores->get(mat)->mat<<endl;
    cout<<"Nome do Autor: "<<autores->get(mat)->nome<<endl;
    cout<<"Livros deste autor:"<<endl;
    Lista<int> *livros = autores->get(mat)->livros;
    for (int i = 0; i < livros->tamLista; ++i) {
        cout<<this->livros->get(livros->get(i))->titulo<<endl;
    }
}

void Controlador::adicionarEditora(Editora editora) { //pega a tabela hash "editoras" e insere na posicao da matricuda de autor o valor de autor
    editoras->inserir(editora.mat, editora);
}

void Controlador::removerEditora(int mat) { //verificar se na possicao informada possui algum valor cadastrado, se tiver, ele remove este valor
    if(!editoras->get(mat)){
        cout << "Editora não encontrada" << endl;
    }
    editoras->remover(mat);
}

void Controlador::mostrarEditora(int mat) { //busca a posicao informada do autor para mostrar o numeroda matricula, nome e os livros cadastrados desta editora
    if(!editoras->get(mat)) {
        cout << "Nenhuma editora foi encontrada neste numero de matricula" << endl;
        return;
    }

    cout<<"Nº da Matricula da Editora: "<<editoras->get(mat)->mat<<endl;
    cout<<"Nome da Editora: "<<editoras->get(mat)->nome<<endl;
    cout<<"Livros desta editora:"<< endl;
   Lista<int> *livros = editoras->get(mat)->livros;
    for (int i = 0; i < livros->tamLista; ++i) {
        cout<<this->livros->get(livros->get(i))->titulo<<endl;
    }
}

void Controlador::adicionarLivro(Livro livro) { //pegas as informacoes de livro e adiciona das tabelas hash de autor, editora e livros.
    autores->get(livro.autor)->adicionarLivro(livro.mat);
    editoras->get(livro.editora)->adicionarLivro(livro.mat);
    livros->inserir(livro.mat, livro);
}

void Controlador::removerLivro(int mat) { //Verifica se a possicao que voce quer retirar tem algum valor, caso tenha, irá remover as informarcoes do hash de autores, editoras e livros
    if(!livros->get(mat)){
        cout << "Livro não encontrado" << endl;
    }

    autores->get(livros->get(mat)->autor)->removerLivro(mat);
    editoras->get(livros->get(mat)->editora)->removerLivro(mat);
    if(livros->get(mat)->alugado){ //valida se este livro esta sendo alugoda, se sim ser[a removido da lista de livros em alguel do usuario.
        usuarios->get(livros->get(mat)->numEmprestado)->devolverLivro(mat);
    }
    livros->remover(mat);
}

void Controlador::mostrarLivro(int mat) { //pega a possicao informada na hash de livros, depois entra nas hash de autor e editora e puxa as informacoes de acordo com a matricula
    cout<<"Matricula do Livro: "<<livros->get(mat)->mat<<endl;
    cout<<"Titulo do Livro: "<<livros->get(mat)->titulo<<endl;
    cout<<"Genero do Livro: "<<livros->get(mat)->genero<<endl;
    cout<<"Editora do Livro: "<<editoras->get(livros->get(mat)->editora)->nome<<endl;
    cout<<"Autor do livro: "<<autores->get(livros->get(mat)->autor)->nome<<endl;
    if(livros->get(mat)->alugado){ // Verifica se o livro esta alugado e informa a data em que foi alugado, se nao fala que esta disponivel para ser alugado
        cout << "livro foi alugado | Data de aluguel: "<< livros->get(mat)->dataDoAluguel << endl;
    } else {
      cout << "Livro disponivel para ser alugada!"<<endl;
    }
}

void Controlador::adicionarUsuario(Usuario usuario) { // adiciona as informacoes de usuario na hash usuarios
    usuarios->inserir(usuario.mat, usuario);
}

void Controlador::removerUsuario(int mat) { // remove da posicao informada o usuario da hash
    if(!usuarios->get(mat)){
        cout << "Usuario não encontrado" << endl;
    }
    usuarios->remover(mat);
}

void Controlador::mostrarUsuario(int mat) { // pega a posicao informada e entra na hash para mostrar as informacoes do usuario
    cout<<"Matricula do Usuario: "<<usuarios->get(mat)->mat<<endl;
    cout<<"Nome do Usuario: "<<usuarios->get(mat)->nome<<endl;
    cout<<"Livros do Usuario:"<<endl;
    Lista<int> livros = usuarios->get(mat)->LivrosAlugados;
    for (int i = 0; i < livros.tamLista; ++i) {
        cout<<this->livros->get(livros.get(i))->titulo<<endl;
    }
}

void Controlador::adicionarRevista(Revista revista) { // pega as informacoes de revista e adiciona no hash
    autores->get(revista.autor)->adicionarLivro(revista.mat);
    editoras->get(revista.editora)->adicionarLivro(revista.mat);
    revistas->inserir(revista.mat, revista);
}
void Controlador::removerRevista(int mat) { // pega a posicao informada e verifica na hash para realizar a remossao das informacoes de revista
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
void Controlador::mostrarRevista(int mat) { // pega a posicao informada e entra na hash para mostrar as informacoes de revista
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

void Controlador::mostrarHistoricoLivros(int mat) { // pega a posicao informada e entra na hash do usuario para mostrar o historico de livros que o usuario realizou o aluguel
    cout<<"Matricula do Usuario: "<<usuarios->get(mat)->mat<<endl;
    cout<<"Nome do Usuario: "<<usuarios->get(mat)->nome<<endl;
    cout<<"Livros do Usuario:"<<endl;
    Lista<int> livros = usuarios->get(mat)->hitoricoLivrosAlugados;
    for (int i = 0; i < livros.tamLista; ++i) {
        cout<<this->livros->get(livros.get(i))->titulo<<endl;
    }
}

void Controlador::mostrarHistoricoRevista(int mat) { // pega a posicao informada e entra na hash do usuario para mostrar o historico de revistas que o usuario realizou o aluguel
    cout<<"Matricula do Usuario: "<<usuarios->get(mat)->mat<<endl;
    cout<<"Nome do Usuario: "<<usuarios->get(mat)->nome<<endl;
    cout<<"Revistas Alugadas:"<<endl;
    Lista<int> revistas = usuarios->get(mat)->RevistasAlugadas;
    for (int i = 0; i < revistas.tamLista; ++i) {
        cout<<this->revistas->get(revistas.get(i))->titulo<<endl;
    }
}

void Controlador::mostrarLivros() { // irá mostrar todos os livros cadastrados
    for (int i = 0; i < livros->tamHash2; ++i) {
        if(livros->get(i) == nullptr) {
            return;
        }else{
            cout << livros->get(i)->mat << " - " << livros->get(i)->titulo << endl;
        }
    }
}

void Controlador::mostrarRevistas() { // ira mostrar todas as revistas cadastradas
    for (int i = 0; i < revistas->tamHash2; ++i) {
        if(revistas->get(i) == nullptr) {
            return;
        }else{
            cout << revistas->get(i)->mat << " - " << revistas->get(i)->titulo << endl;
        }
    }
}

void Controlador::alugarLivro(int matUsuario, int matLivro, std::string data) { // pega a matricula do usuario, a matricula do livro desejado e a data em que foi realizado para salvar que o livro foi alugado.
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

void Controlador::alugarRevista(int matUsuario, int matRevista, std::string data) { // pega a matricula do usuario, a matricula da revista desejada e a data em que foi realizado para salvar que a revista foi alugada.
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

void Controlador::devolverLivro(int matUsuario, int matLivro) { // ira pegar a informacao do usuario e do livro, validar se essas posicoes estao preenchidas e se sim, ira dar como devolvido na hash de livros e do usuario
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

void Controlador::devolverRevista(int matUsuario, int matRevista) { // ira pegar a informacao do usuario e da revista, validar se essas posicoes estao preenchidas e se sim, ira dar como devolvida na hash de revistas e do usuario
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

void Controlador::mostrarLivrosGenero(std::string genero) { // ira pegar o genero informado e validar na hash se tem algum livro com o mesmo genero cadastrado
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

void Controlador::mostrarRevistasGenero(std::string genero) { // ira pegar o genero informado e validar na hash se tem alguma revista com o mesmo genero cadastrado
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


void Controlador::mostrarLivrosAtrasados(int matUsuario, string data) { // pega a matriculado usuario e uma data informada, para fazer a validacao dos livros vencidos de entrega ate aquela data
    Lista<int> livros = usuarios->get(matUsuario)->LivrosAlugados;
    for (int i = 0; i < livros.tamLista; ++i) {
        if(this->livros->get(livros.get(i))->alugado == true && ValidaData(this->livros->get(livros.get(i))->dataDoAluguel) + 7 <
                                                                           ValidaData(data)){
            cout << this->livros->get(livros.get(i))->mat << " - " << this->livros->get(livros.get(i))->titulo << " - " << this->livros->get(livros.get(i))->dataDoAluguel << endl;
        }
    }
}

void Controlador::mostrarRevistasAtrasadas(int matUsuario, string data) { // pega a matriculado usuario e uma data informada, para fazer a validacao das revistas vencidas de entrega ate aquela data
    Lista<int> revistas = usuarios->get(matUsuario)->RevistasAlugadas;
    for (int i = 0; i < revistas.tamLista; ++i) {
        if(this->revistas->get(revistas.get(i))->alugado == true && ValidaData(this->revistas->get(revistas.get(i))->dataDoAluguel) + 7<
                                                                   ValidaData(data)){
            cout << this->revistas->get(revistas.get(i))->mat << " - " << this->revistas->get(revistas.get(i))->titulo << " - " << this->revistas->get(revistas.get(i))->dataDoAluguel << endl;
        }
    }
}

void Controlador::mostrarLivrosAlugados(int matUsuario) {
    Lista<int> livrosAlugados = usuarios->get(matUsuario)->LivrosAlugados;
    cout << "Quantidade de livros alugados: " << livrosAlugados.tamLista << endl;

    if (livrosAlugados.tamLista == 0) {
        cout << "Nenhum livro esta alugado" << endl;
        return;
    }

    for (int i = 0; i < livrosAlugados.tamLista; i++) {
        int matLivro = livrosAlugados.get(i);
        if (livros->get(i)->mat==matLivro) {
            Livro* livro = livros->get(matLivro);
            cout << livro->mat << " - " << livro->titulo << " - " << livro->dataDoAluguel << endl;
        } else {
            cout << "Livro nao encontrado" << matLivro << endl;
        }
    }
}

void Controlador::mostrarRevistasAlugadas(int matUsuario) {
    Lista<int> revistasAlugadas = usuarios->get(matUsuario)->RevistasAlugadas;
    cout << "Quantidade de revistas alugadas: " << revistasAlugadas.tamLista << endl;

    if (revistasAlugadas.tamLista == 0) {
        cout << "Nenhuma revista esta alugada" << endl;
        return;
    }

    for (int i = 0; i < revistasAlugadas.tamLista; i++) {
        int matRevista = revistasAlugadas.get(i);
        if (revistas->get(i)->mat==matRevista) {
            Revista* revista = revistas->get(matRevista);
            cout << revista->mat << " - " << revista->titulo << " - " << revista->dataDoAluguel << endl;
        } else {
            cout << "Revista nao encontrada" << matRevista << endl;
        }
    }
}

#endif //TRABESTRUTURAM2_CONTROLADOR_H
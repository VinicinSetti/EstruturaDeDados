#ifndef TRABESTRUTURAM2_LIVRO_H
#define TRABESTRUTURAM2_LIVRO_H

#include <iostream>
#include <string>

using namespace std;

struct Livro{ //struct Livro, foram declarados os atributos necessarios e algumas funcoes para funcionamento do codigo

    static int proxMat;
    int mat;
    int autor;
    int editora;
    string titulo;
    string genero;
    bool alugado;
    string dataDoAluguel;
    int numEmprestado;

    Livro();
    Livro(string titulo, int autor, int editora, string genero);

    void definirEmprestimo(bool esmprestar);
    void dataRealizadaDoEmprestimo(string dataDoEmprestimo);
    void definirAutor(int autor);
    void definirEditora(int editora);
    void definirGenero(string genero);

};

int Livro::proxMat = 0; //inicializacao da variavel, a fim de nao pegar lixo de memoria

Livro::Livro() { //metodo contrutor basico de livro
    this->mat = proxMat++;
    this->titulo = "";
    this->autor = 0;
    this->editora = 0;
    this->genero = "";
    this->alugado = false;
    this->numEmprestado = 0;
    this->dataDoAluguel = "";
}

Livro::Livro(string titulo, int autor, int editora, string genero) { //Sobrecarga no meu metodo construtor de Livro, para salvamento das informacoes de seu cadastro
    this->mat = proxMat++;
    this->titulo = titulo;
    this->autor = autor;
    this->editora = editora;
    this->genero = genero;
    this->alugado = false;
    this->numEmprestado = 0;
    this->dataDoAluguel = "";
}

void Livro::definirEmprestimo(bool alugado) { //irá definor o atributo verificador se este livro foi pego empresatado ou nao
    this->alugado = alugado;
}

void Livro::dataRealizadaDoEmprestimo(string dataDoAluguel) { //Irá salvar a data em que foi emprestado o livro
    this->dataDoAluguel = dataDoAluguel;
}

void Livro::definirAutor(int autor) { //Irá salvar o autor do livro
    this->autor = autor;
}

void Livro::definirEditora(int editora) { //Irá salvar a editora do livro
    this->editora = editora;
}

void Livro::definirGenero(std::string genero) { //irá salvar o gereno do livro
    this->genero = genero;
}
#endif //TRABESTRUTURAM2_LIVRO_H
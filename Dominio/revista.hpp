#ifndef TRABESTRUTURAM2_REVISTA_H
#define TRABESTRUTURAM2_REVISTA_H

#include <iostream>
#include <string>

using namespace std;

struct Revista{ //struct Revista, foram declarados os atributos necessarios e algumas funcoes para funcionamento do codigo
    static int proxMat;
    int mat;
    int autor;
    int editora;
    string titulo;
    string genero;
    bool alugado;
    string dataDoAluguel;
    int numEmprestado;

    Revista();
    Revista(string titulo, int autor, int editora, string genero);
    void definirEmprestimo(bool esmprestar);
    void dataRealizadaDoEmprestimo(string dataDoEmprestimo);
    void definirAutor(int autor);
    void definirEditora(int editora);
    void definirGenero(string genero);
};

int Revista::proxMat = 0; //inicializacao da variavel, a fim de nao pegar lixo de memoria

Revista::Revista() { //metodo contrutor basico de revista
    this->mat = proxMat++;
    this->titulo = "";
    this->autor = 0;
    this->editora = 0;
    this->genero = "";
    this->alugado = false;
    this->numEmprestado = 0;
    this->dataDoAluguel = "";
}

Revista::Revista(std::string titulo, int autor, int editora, std::string genero) { //Sobrecarga no meu metodo construtor de revista, para salvamento das informacoes de seu cadastro
    this->mat = proxMat++;
    this->titulo = titulo;
    this->autor = autor;
    this->editora = editora;
    this->genero = genero;
    this->alugado = false;
    this->numEmprestado = 0;
    this->dataDoAluguel = "";
}

void Revista::definirGenero(std::string genero) { //irá salvar o gereno do revista
    this->genero = genero;
}

void Revista::definirEditora(int editora) { //Irá salvar a editora do revista
    this->editora = editora;
}

void Revista::definirAutor(int autor) { //Irá salvar o autor do revista
    this->autor = autor;
}

void Revista::definirEmprestimo(bool esmprestar) { //irá definor o atributo verificador se esta revista foi pega empresatada ou nao
    this->alugado = esmprestar;
}

void Revista::dataRealizadaDoEmprestimo(std::string dataDoEmprestimo) { //Irá salvar a data em que foi emprestada
    this->dataDoAluguel = dataDoEmprestimo;
}
#endif //TRABESTRUTURAM2_REVISTA_H
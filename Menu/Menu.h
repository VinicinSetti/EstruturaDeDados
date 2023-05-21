#ifndef TRABESTRUTURAM2_MENU_H
#define TRABESTRUTURAM2_MENU_H

#include <iostream>
#include "../Dominio/controlador.hpp"

using namespace std;

void cls(){ //funcao para limpar a tela
    system("pause");
    system("cls");
}

//Funcao para menu de Autor
void menuAutor(Autor autor1, Controlador &controlador, int &cont){
    int opcaoMenu;
    int matricula;
    string nome;


    cout << "Digite a opção desejada!\n"; //pede a acao da opcao desejada
    cout << "\t[1] - Adicionar Autor"<<endl;
    cout << "\t[2] - Exibir Autor"<<endl;
    cout << "\t[3] - Remover Autor"<<endl;
    cin >> opcaoMenu;
    cls();

    while(opcaoMenu < 1 || opcaoMenu > 3) { //verifica se o valor inserido e valido
        cout << "Digito invalido, insira novamente!\n";
        cout << "\t[1] - Adicionar Autor"<<endl;
        cout << "\t[2] - Exibir Autor"<<endl;
        cout << "\t[3] - Remover Autor"<<endl;
        cin >> opcaoMenu;
        cls();
    }

    switch(opcaoMenu){ //executa a opcao desejada
        case 1:
            cout << "Digite o nome do autor a ser adicionado: ";
            cin >> nome;
            autor1.nome = nome;
            controlador.adicionarAutor(autor1);
            cont++;
            break;
        case 2:
            cout << "Digite a matricula do autor a ser exibido: ";
            cin >> matricula;
            controlador.mostrarAutor(matricula);
            break;
        case 3:
            cout << "Digite a matricula do autor a ser removido: ";
            cin >> matricula;
            controlador.removerAutor(matricula);
            cont--;
            break;
    }
}

//Funcao para menu de Editora
void menuEditora(Editora editora1, Controlador &controlador, int &cont){
    int opcaoMenu;
    int matricula;
    string nome;

    cout << "Digite a opção desejada!\n"; //pede a acao da opcao desejada
    cout << "\t[1] - Adicionar Editora"<<endl;
    cout << "\t[2] - Exibir Editora"<<endl;
    cout << "\t[3] - Remover Editora"<<endl;
    cin >> opcaoMenu;
    cls();

    while(opcaoMenu < 1 || opcaoMenu > 3) { //verifica se o valor inserido e valido
        cout << "Digito invalido, insira novamente!\n";
        cout << "\t[1] - Adicionar Editora"<<endl;
        cout << "\t[2] - Exibir Editora"<<endl;
        cout << "\t[3] - Remover Editora"<<endl;
        cin >> opcaoMenu;
        cls();
    }

    switch(opcaoMenu){ //executa a opcao desejada
        case 1:
            cout << "Digite o nome da editora a ser adicionada: ";
            cin >> nome;
            editora1.nome = nome;
            controlador.adicionarEditora(editora1);
            cont++;
            break;
        case 2:
            cout << "Digite a matricula da editora a ser exibida: ";
            cin >> matricula;
            controlador.mostrarEditora(matricula);
            break;
        case 3:
            cout << "Digite a matricula da editora a ser removida: ";
            cin >> matricula;
            controlador.removerEditora(matricula);
            cont--;
            break;
    }
}

//Funcao para menu de Livro
void menuLivro(Livro livro1, Controlador &controlador, int &cont){
    int opcaoMenu;
    int matricula;
    int matriculaUsuario;
    string titulo;
    string genero;
    string dataAluguel;
    string dataHoje;

    cout << "Digite a opção desejada!\n"; //pede a acao da opcao desejada
    cout << "\t[1] - Adicionar Livro"<<endl;
    cout << "\t[2] - Exibir Livro"<<endl;
    cout << "\t[3] - Remover Livro"<<endl;
    cout << "\t[4] - Exibir historico de um Livro"<<endl;
    cout << "\t[5] - Exibir livros por genero"<<endl;
    cout << "\t[6] - Alugar Livro"<<endl;
    cout << "\t[7] - Devolver Livro"<<endl;
    cout << "\t[8] - Exibir livros em atraso"<<endl;
    cin >> opcaoMenu;
    cls();

    while(opcaoMenu < 1 || opcaoMenu > 8) { //verifica se o valor inserido e valido
        cout << "Digito invalido, insira novamente!\n";
        cout << "\t[1] - Adicionar Livro"<<endl;
        cout << "\t[2] - Exibir Livro"<<endl;
        cout << "\t[3] - Remover Livro"<<endl;
        cout << "\t[4] - Exibir historico de um Livro"<<endl;
        cout << "\t[5] - Exibir livros por genero"<<endl;
        cout << "\t[6] - Alugar Livro"<<endl;
        cout << "\t[7] - Devolver Livro"<<endl;
        cout << "\t[8] - Exibir livros em atraso"<<endl;
        cin >> opcaoMenu;
        cls();
    }

    switch(opcaoMenu){ //executa a opcao desejada
        case 1:
            cout << "Digite o nome do livro a ser adicionado: ";
            cin >> titulo;
            livro1.titulo = titulo;
            controlador.adicionarLivro(livro1);
            cont++;
            break;
        case 2:
            cout << "Digite a matricula do livro a ser exibida: ";
            cin >> matricula;
            controlador.mostrarLivro(matricula);
            break;
        case 3:
            cout << "Digite a matricula do livro a ser removido: ";
            cin >> matricula;
            controlador.removerLivro(matricula);
            cont--;
            break;
        case 4:
            cout << "Digite a matricula de um livro para ver seu historico: ";
            cin >> matricula;
            controlador.mostrarHistoricoLivros(matricula);
            break;
        case 5:
            cout << "Digite o genero de um livro para exibir os livros deste genero: ";
            cin >> genero;
            livro1.genero = genero;
            controlador.mostrarLivrosGenero(livro1.genero);
            break;
        case 6:
            cout << "Digite a matricula do usuario que esta alugando o livro: ";
            cin >> matriculaUsuario;
            cout << "\nDigite a matricula do livro que esta sendo alugada: ";
            cin >> matricula;
            cout << "\nDigite a data do aluguel no padrao dd/mm/aaaa, digitando as barras: ";
            cin >> dataAluguel;
            controlador.alugarLivro(matriculaUsuario, matricula, dataAluguel);
            break;
        case 7:
            cout << "Digite a matricula do usuario que esta devolvendo o livro: ";
            cin >> matriculaUsuario;
            cout << "\nDigite a matricula do livro que esta sendo devolvida: ";
            cin >> matricula;
            controlador.devolverLivro(matriculaUsuario, matricula);
            break;
        case 8:
            cout << "Digite a matricula do usuario que deseja consultar os livros em atraso: ";
            cin >> matriculaUsuario;
            cout << "\nDigite a data de hoje no padrao dd/mm/aaaa, digitando as barras: ";
            cin >> dataHoje;
            controlador.mostrarLivrosAtrasados(matriculaUsuario, dataHoje);
            break;
    }
}

//Funcao para menu de Revista
void menuRevista(Revista revista1, Controlador &controlador, int &cont){
    int opcaoMenu;
    int matricula;
    int matriculaUsuario;
    string titulo;
    string genero;
    string dataAluguel;
    string dataHoje;

    cout << "Digite a opção desejada!\n"; //pede a acao da opcao desejada
    cout << "\t[1] - Adicionar Revista"<<endl;
    cout << "\t[2] - Exibir Revista"<<endl;
    cout << "\t[3] - Remover Revista"<<endl;
    cout << "\t[4] - Exibir historico de uma Revista"<<endl;
    cout << "\t[5] - Exibir revistas por genero"<<endl;
    cout << "\t[6] - Alugar Revista"<<endl;
    cout << "\t[7] - Devolver Revista"<<endl;
    cout << "\t[8] - Exibir revistas em atraso"<<endl;
    cin >> opcaoMenu;
    cls();

    while(opcaoMenu < 1 || opcaoMenu > 8) { //verifica se o valor inserido e valido
        cout << "Digito invalido, insira novamente!\n";
        cout << "\t[1] - Adicionar Revista"<<endl;
        cout << "\t[2] - Exibir Revista"<<endl;
        cout << "\t[3] - Remover Revista"<<endl;
        cout << "\t[4] - Exibir historico de uma Revista"<<endl;
        cout << "\t[5] - Exibir revistas por genero"<<endl;
        cout << "\t[6] - Alugar Revista"<<endl;
        cout << "\t[7] - Devolver Revista"<<endl;
        cout << "\t[8] - Exibir revistas em atraso"<<endl;
        cin >> opcaoMenu;
        cls();
    }

    switch(opcaoMenu){ //executa a opcao desejada
        case 1:
            cout << "Digite o nome da revista a ser adicionado: ";
            cin >> titulo;
            revista1.titulo = titulo;
            controlador.adicionarRevista(revista1);
            cont++;
            break;
        case 2:
            cout << "Digite a matricula da revista a ser exibida: ";
            cin >> matricula;
            controlador.mostrarRevista(matricula);
            break;
        case 3:
            cout << "Digite a matricula da revista a ser removido: ";
            cin >> matricula;
            controlador.removerRevista(matricula);
            cont--;
            break;
        case 4:
            cout << "Digite a matricula de uma revista para ver seu historico: ";
            cin >> matricula;
            controlador.mostrarHistoricoRevista(matricula);
            break;
        case 5:
            cout << "Digite o genero de uma revista para exibir as revistas deste genero: ";
            cin >> genero;
            revista1.genero = genero;
            controlador.mostrarRevistasGenero(revista1.genero);
            break;
        case 6:
            cout << "Digite a matricula do usuario que esta alugando a revista: ";
            cin >> matriculaUsuario;
            cout << "\nDigite a matricula da revista que esta sendo alugada: ";
            cin >> matricula;
            cout << "\nDigite a data do aluguel no padrao dd/mm/aaaa, digitando as barras: ";
            cin >> dataAluguel;
            controlador.alugarRevista(matriculaUsuario, matricula, dataAluguel);
            break;
        case 7:
            cout << "Digite a matricula do usuario que esta devolvendo a revista: ";
            cin >> matriculaUsuario;
            cout << "\nDigite a matricula da revista que esta sendo devolvida: ";
            cin >> matricula;
            controlador.devolverRevista(matriculaUsuario, matricula);
            break;
        case 8:
            cout << "Digite a matricula do usuario que deseja consultar as revistas em atraso: ";
            cin >> matriculaUsuario;
            cout << "\nDigite a data de hoje no padrao dd/mm/aaaa, digitando as barras: ";
            cin >> dataHoje;
            controlador.mostrarRevistasAtrasadas(matriculaUsuario, dataHoje);
            break;
    }
}

//Funcao para menu de Usuario
void menuUsuario(Usuario usuario1, Controlador &controlador, int &cont){
    int opcaoMenu;
    int matricula;
    int matriculaUsuario;
    string nome;

    cout << "Digite a opção desejada!\n"; //pede a acao da opcao desejada
    cout << "\t[1] - Adicionar Usuario"<<endl;
    cout << "\t[2] - Exibir Usuario"<<endl;
    cout << "\t[3] - Remover Usuario"<<endl;
    cout << "\t[4] - Exibir revistas alugadas por um Usuario"<<endl;
    cout << "\t[5] - Exibir livros alugados por um Usuario"<<endl;
    cin >> opcaoMenu;
    cls();

    while(opcaoMenu < 1 || opcaoMenu > 5) { //verifica se o valor inserido e valido
        cout << "Digito invalido, insira novamente!\n";
        cout << "\t[1] - Adicionar Usuario"<<endl;
        cout << "\t[2] - Exibir Usuario"<<endl;
        cout << "\t[3] - Remover Usuario"<<endl;
        cout << "\t[4] - Exibir revistas alugadas por um Usuario"<<endl;
        cout << "\t[5] - Exibir livros alugados por um Usuario"<<endl;
        cin >> opcaoMenu;
        cls();
    }

    switch(opcaoMenu){ //executa a opcao desejada
        case 1:
            cout << "Digite o nome do usuario a ser adicionado: ";
            cin >> nome;
            usuario1.nome = nome;
            controlador.adicionarUsuario(usuario1);
            cont++;
            break;
        case 2:
            cout << "Digite a matricula do usuario a ser exibido: ";
            cin >> matricula;
            controlador.mostrarUsuario(matricula);
            break;
        case 3:
            cout << "Digite a matricula do usuario a ser removido: ";
            cin >> matricula;
            controlador.removerUsuario(matricula);
            cont--;
            break;
        case 4:
            cout << "Digite a matricula do usuario a ser consultado: ";
            cin >> matriculaUsuario;
            controlador.mostrarRevistasAlugadas(matriculaUsuario);
        case 5:
            cout << "Digite a matricula do usuario a ser consultado: ";
            cin >> matriculaUsuario;
            controlador.mostrarLivrosAlugados(matriculaUsuario);
    }
}

#endif //TRABESTRUTURAM2_MENU_H
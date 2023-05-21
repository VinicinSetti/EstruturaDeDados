#ifndef TRABESTRUTURAM2_MENU_H
#define TRABESTRUTURAM2_MENU_H

#include <iostream>
#include "../Dominio/controlador.hpp"

using namespace std;

void cls(){
    system("pause");
    system("cls");
}

//Funcoes para menu de Autor
void menuAutor(){
    int opcaoMenu;
    int matricula;
    Autor autor;
    string nome;
    Controlador controlador = Controlador();

    cout << "Digite a opção desejada!\n";
    cout << "\t[1] - Adicionar Autor"<<endl;
    cout << "\t[2] - Exibir Autor"<<endl;
    cout << "\t[3] - Remover Autor"<<endl;
    cin >> opcaoMenu;
    cls();

    while(opcaoMenu < 1 || opcaoMenu > 3) {
        cout << "Digito invalido, insira novamente!\n";
        cout << "\t[1] - Adicionar Autor"<<endl;
        cout << "\t[2] - Exibir Autor"<<endl;
        cout << "\t[3] - Remover Autor"<<endl;
        cin >> opcaoMenu;
        cls();
    }

    switch(opcaoMenu){
        case 1:
            cout << "Digite o nome do autor a ser adicionado: "
            cin >> nome;
            autor.nome = nome;
            controlador.adicionarAutor(autor);
        case 2:
            cout << "Digite a matricula do autor a ser exibido: "
            cin >> matricula;
            controlador.mostrarAutor(matricula);
        case 3:
            cout << "Digite a matricula do autor a ser removido: "
            cin >> matricula;
            controlador.removerAutor(matricula);
    }
}

//Funcoes para menu de Editora
void adicionarEditora(){

}
void exibirEditora(){

}
void removerEditora(){

}
void menuEditora(){
    int opcaoMenu;
    cout << "Digite a opção desejada!\n";
    cout << "\t[1] - Adicionar Editora"<<endl;
    cout << "\t[2] - Exibir Editora"<<endl;
    cout << "\t[3] - Remover Editora"<<endl;
    cin >> opcaoMenu;
    cls();

    while(opcaoMenu < 1 || opcaoMenu > 3) {
        cout << "Digito invalido, insira novamente!\n";
        cout << "\t[1] - Adicionar Editora"<<endl;
        cout << "\t[2] - Exibir Editora"<<endl;
        cout << "\t[3] - Remover Editora"<<endl;
        cin >> opcaoMenu;
        cls();
    }

    switch(opcaoMenu){
        case 1:
            adicionarEditora();
        case 2:
            exibirEditora();
        case 3:
            removerEditora();
    }
}

//Funcoes para menu de Livro
void adicionarLivro(){

}
void exibirLivro(){

}
void removerLivro(){

}
void menuLivro(){
    int opcaoMenu;
    cout << "Digite a opção desejada!\n";
    cout << "\t[1] - Adicionar Livro"<<endl;
    cout << "\t[2] - Exibir Livro"<<endl;
    cout << "\t[3] - Remover Livro"<<endl;
    cin >> opcaoMenu;
    cls();

    while(opcaoMenu < 1 || opcaoMenu > 3) {
        cout << "Digito invalido, insira novamente!\n";
        cout << "\t[1] - Adicionar Livro"<<endl;
        cout << "\t[2] - Exibir Livro"<<endl;
        cout << "\t[3] - Remover Livro"<<endl;
        cin >> opcaoMenu;
        cls();
    }

    switch(opcaoMenu){
        case 1:
            adicionarLivro();
        case 2:
            exibirLivro();
        case 3:
            removerLivro();
    }
}

//Funcoes para menu de Revista
void adicionarRevista(){

}
void exibirRevista(){

}
void removerRevista(){

}
void menuRevista(){
    int opcaoMenu;
    cout << "Digite a opção desejada!\n";
    cout << "\t[1] - Adicionar Revista"<<endl;
    cout << "\t[2] - Exibir Revista"<<endl;
    cout << "\t[3] - Remover Revista"<<endl;
    cin >> opcaoMenu;
    cls();

    while(opcaoMenu < 1 || opcaoMenu > 3) {
        cout << "Digito invalido, insira novamente!\n";
        cout << "\t[1] - Adicionar Revista"<<endl;
        cout << "\t[2] - Exibir Revista"<<endl;
        cout << "\t[3] - Remover Revista"<<endl;
        cin >> opcaoMenu;
        cls();
    }

    switch(opcaoMenu){
        case 1:
            adicionarRevista();
        case 2:
            exibirRevista();
        case 3:
            removerRevista();
    }
}

//Funcoes para menu de Usuario
void adicionarUsuario(){

}
void exibirUsuario(){

}
void removerUsuario(){

}
void menuUsuario(){
    int opcaoMenu;
    cout << "Digite a opção desejada!\n";
    cout << "\t[1] - Adicionar Usuario"<<endl;
    cout << "\t[2] - Exibir Usuario"<<endl;
    cout << "\t[3] - Remover Usuario"<<endl;
    cin >> opcaoMenu;
    cls();

    while(opcaoMenu < 1 || opcaoMenu > 3) {
        cout << "Digito invalido, insira novamente!\n";
        cout << "\t[1] - Adicionar Usuario"<<endl;
        cout << "\t[2] - Exibir Usuario"<<endl;
        cout << "\t[3] - Remover Usuario"<<endl;
        cin >> opcaoMenu;
        cls();
    }

    switch(opcaoMenu){
        case 1:
            adicionarUsuario();
        case 2:
            exibirUsuario();
        case 3:
            removerUsuario();
    }
}

#endif //TRABESTRUTURAM2_MENU_H

#ifndef TRABESTRUTURAM2_MENU_H
#define TRABESTRUTURAM2_MENU_H

#include "../Dominio/controlador.hpp"

struct Menu{
    void run();
};

void cls(){
    system ("pause");
    system ("cls");
}

void Menu::run() {
    int opcao1, opcao2;

    while(true) {
        cout << "Digite a opção desejada!\n";
        cout << "\t[1] - Autor"<<endl;
        cout << "\t[2] - Editora"<<endl;
        cout << "\t[3] - Livro"<<endl;
        cout << "\t[4] - Revista"<<endl;
        cout << "\t[5] - Usuario"<<endl;
        cout << "\n\t[6] - Sair"<<endl;
        cin >> opcao1;
        cls();

        while(opcao1 < 1 || opcao1 > 6){
            cout << "Digito invalido, insira novamente!\n";
            cout << "\t[1] - Autor"<<endl;
            cout << "\t[2] - Editora"<<endl;
            cout << "\t[3] - Livro"<<endl;
            cout << "\t[4] - Revista"<<endl;
            cout << "\t[5] - Usuario"<<endl;
            cout << "\n\t[6] - Sair"<<endl;
            cin >> opcao1;
            cls();
        }

        switch(opcao1){
            case 1:
                cout << "Digite a opção desejada!\n";
                cout << "\t[1] - Adicionar Autor"<<endl;
                cout << "\t[2] - Exibir Autor"<<endl;
                cout << "\t[3] - Remover Autor"<<endl;
                cin<<opcao2;
                cls();

                while(opcao1 < 1 || opcao1 > 3) {
                    cout << "Digito invalido, insira novamente!\n";
                    cout << "\t[1] - Adicionar Autor"<<endl;
                    cout << "\t[2] - Exibir Autor"<<endl;
                    cout << "\t[3] - Remover Autor"<<endl;
                    cin<<opcao2;
                    cls();
                }
                switch(opcao2){
                    case 1: //<---------- Adicionar autor

                    case 2: //<---------- Exibir autor

                    case 2:  //<---------- Remover autor
                }

            case 2:
                cout << "Digite a opção desejada!\n";
                cout << "\t[1] - Adicionar Editora"<<endl;
                cout << "\t[2] - Exibir Editora"<<endl;
                cout << "\t[3] - Remover Editora"<<endl;
                cin<<opcao2;
                cls();

                while(opcao1 < 1 || opcao1 > 3) {
                    cout << "Digito invalido, insira novamente!\n";
                    cout << "\t[1] - Adicionar Editora"<<endl;
                    cout << "\t[2] - Exibir Editora"<<endl;
                    cout << "\t[3] - Remover Editora"<<endl;
                    cin<<opcao2;
                    cls();
                }
                switch(opcao2){
                    case 1: //<---------- Adicionar Editora

                    case 2: //<---------- Exibir Editora

                    case 2:  //<---------- Remover Editora
                }

            case 3:
                cout << "Digite a opção desejada!\n";
                cout << "\t[1] - Adicionar Livro"<<endl;
                cout << "\t[2] - Exibir Livro"<<endl;
                cout << "\t[3] - Remover Livro"<<endl;
                cin<<opcao2;
                cls();

                while(opcao1 < 1 || opcao1 > 3) {
                    cout << "Digito invalido, insira novamente!\n";
                    cout << "\t[1] - Adicionar Livro"<<endl;
                    cout << "\t[2] - Exibir Livro"<<endl;
                    cout << "\t[3] - Remover Livro"<<endl;
                    cin<<opcao2;
                    cls();
                }
                switch(opcao2){
                    case 1: //<---------- Adicionar Livro

                    case 2: //<---------- Exibir Livro

                    case 2:  //<---------- Remover Livro
                }

            case 4:
                cout << "Digite a opção desejada!\n";
                cout << "\t[1] - Adicionar Revista"<<endl;
                cout << "\t[2] - Exibir Revista"<<endl;
                cout << "\t[3] - Remover Revista"<<endl;
                cin<<opcao2;
                cls();

                while(opcao1 < 1 || opcao1 > 3) {
                    cout << "Digito invalido, insira novamente!\n";
                    cout << "\t[1] - Adicionar Revista"<<endl;
                    cout << "\t[2] - Exibir Revista"<<endl;
                    cout << "\t[3] - Remover Revista"<<endl;
                    cin<<opcao2;
                    cls();
                }
                switch(opcao2){
                    case 1: //<---------- Adicionar Revista

                    case 2: //<---------- Exibir Revista

                    case 2:  //<---------- Remover Revista
                }

            case 5:
                cout << "Digite a opção desejada!\n";
                cout << "\t[1] - Adicionar Usuario"<<endl;
                cout << "\t[2] - Exibir Usuario"<<endl;
                cout << "\t[3] - Remover Usuario"<<endl;
                cin<<opcao2;
                cls();

                while(opcao1 < 1 || opcao1 > 3) {
                    cout << "Digito invalido, insira novamente!\n";
                    cout << "\t[1] - Adicionar Usuario"<<endl;
                    cout << "\t[2] - Exibir Usuario"<<endl;
                    cout << "\t[3] - Remover Usuario"<<endl;
                    cin<<opcao2;
                    cls();
                }
                switch(opcao2){
                    case 1: //<---------- Adicionar Usuario

                    case 2: //<---------- Exibir Usuario

                    case 2:  //<---------- Remover Usuario
                }

            case 6:
                break;
                }
        }


        Controlador controlador = Controlador();

        Autor author1 = Autor("Author 1");
        Autor author2 = Autor("Author 2");

        Editora publisher1 = Editora("Publisher 1");
        Editora publisher2 = Editora("Publisher 2");

        controlador.adicionarAutor(author1);
        controlador.adicionarAutor(author2);

        controlador.adicionarEditora(publisher1);
        controlador.adicionarEditora(publisher2);

        Livro book1 = Livro("Book teste", author1.mat, publisher1.mat, "2", false, "1");
        Livro book2 = Livro("Book 2", author2.mat, publisher2.mat, "3", true, "2");

        controlador.adicionarLivro(book1);
        controlador.adicionarLivro(book2);

        controlador.mostrarLivro(book1.mat);

        controlador.mostrarAutor(author1.mat);
        controlador.mostrarAutor(author2.mat);
    }
}

#endif //TRABESTRUTURAM2_MENU_H

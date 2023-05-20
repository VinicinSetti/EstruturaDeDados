#ifndef TRABESTRUTURAM2_MENU_H
#define TRABESTRUTURAM2_MENU_H

#include "../Dominio/controlador.hpp"

struct Menu{
    void run();
};

void cls(){
    system("pause");
    system("cls");
}



void Menu::run() {
    bool menu = true;
    int opcao1 = 0, opcao2 = 0;
    string nome;

    Controlador controlador = Controlador();
    Autor *autor = new Autor[10];



    while(menu) {
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
                cin >> opcao2;
                cls();

                while(opcao2 < 1 || opcao2 > 3) {
                    cout << "Digito invalido, insira novamente!\n";
                    cout << "\t[1] - Adicionar Autor"<<endl;
                    cout << "\t[2] - Exibir Autor"<<endl;
                    cout << "\t[3] - Remover Autor"<<endl;
                    cin >> opcao2;
                    cls();
                }
                switch(opcao2){
                    case 1:
                        cout << "Diga o Nome do autor: "<< endl;
                        cin >> nome;
                        autor[0].nome = nome;
                        controlador.adicionarAutor(autor[0]);
                        break;
                    case 2:
                        controlador.mostrarAutor(autor[0].mat);
                        controlador.mostrarAutor(autor[1].mat);
                        break;

                    /*case 3:  //<---------- Remover autor
                        break;
                    */
                }

            case 2:
                cout << "Digite a opção desejada!\n";
                cout << "\t[1] - Adicionar Editora"<<endl;
                cout << "\t[2] - Exibir Editora"<<endl;
                cout << "\t[3] - Remover Editora"<<endl;
                cin >> opcao2;
                cls();

                while(opcao2 < 1 || opcao2 > 3) {
                    cout << "Digito invalido, insira novamente!\n";
                    cout << "\t[1] - Adicionar Editora"<<endl;
                    cout << "\t[2] - Exibir Editora"<<endl;
                    cout << "\t[3] - Remover Editora"<<endl;
                    cin >> opcao2;
                    cls();
                }
                switch(opcao2){
                    case 1: //<---------- Adicionar Editora
                        break;

                    case 2: //<---------- Exibir Editora
                        break;

                    case 3:  //<---------- Remover Editora
                        break;
                }

            case 3:
                cout << "Digite a opção desejada!\n";
                cout << "\t[1] - Adicionar Livro"<<endl;
                cout << "\t[2] - Exibir Livro"<<endl;
                cout << "\t[3] - Remover Livro"<<endl;
                cin >> opcao2;
                cls();

                while(opcao2 < 1 || opcao2 > 3) {
                    cout << "Digito invalido, insira novamente!\n";
                    cout << "\t[1] - Adicionar Livro"<<endl;
                    cout << "\t[2] - Exibir Livro"<<endl;
                    cout << "\t[3] - Remover Livro"<<endl;
                    cin >> opcao2;
                    cls();
                }
                switch(opcao2){
                    case 1: //<---------- Adicionar Livro
                        break;

                    case 2: //<---------- Exibir Livro
                        break;

                    case 3:  //<---------- Remover Livro
                        break;
                }

            case 4:
                cout << "Digite a opção desejada!\n";
                cout << "\t[1] - Adicionar Revista"<<endl;
                cout << "\t[2] - Exibir Revista"<<endl;
                cout << "\t[3] - Remover Revista"<<endl;
                cin >> opcao2;
                cls();

                while(opcao2 < 1 || opcao2 > 3) {
                    cout << "Digito invalido, insira novamente!\n";
                    cout << "\t[1] - Adicionar Revista"<<endl;
                    cout << "\t[2] - Exibir Revista"<<endl;
                    cout << "\t[3] - Remover Revista"<<endl;
                    cin >> opcao2;
                    cls();
                }
                switch(opcao2){
                    case 1: //<---------- Adicionar Revista
                        break;

                    case 2: //<---------- Exibir Revista
                        break;

                    case 3:  //<---------- Remover Revista
                        break;
                }

            case 5:
                cout << "Digite a opção desejada!\n";
                cout << "\t[1] - Adicionar Usuario"<<endl;
                cout << "\t[2] - Exibir Usuario"<<endl;
                cout << "\t[3] - Remover Usuario"<<endl;
                cin >> opcao2;
                cls();

                while(opcao2 < 1 || opcao2 > 3) {
                    cout << "Digito invalido, insira novamente!\n";
                    cout << "\t[1] - Adicionar Usuario"<<endl;
                    cout << "\t[2] - Exibir Usuario"<<endl;
                    cout << "\t[3] - Remover Usuario"<<endl;
                    cin >> opcao2;
                    cls();
                }
                switch(opcao2){
                    case 1: //<---------- Adicionar Usuario
                        break;

                    case 2: //<---------- Exibir Usuario
                        break;
                    case 3:  //<---------- Remover Usuario
                        break;
                }

            case 6:
                menu = false;
                break;
                }
        }
}

#endif //TRABESTRUTURAM2_MENU_H

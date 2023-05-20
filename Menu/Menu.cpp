#include <iostream>
#include "../Menu/Menu.h"

struct Menu{
    void run();
};

void Menu::run() {
    bool menu = true;
    int opcao;

    while(menu) {
        cout << "Digite a opção desejada!\n";
        cout << "\t[1] - Autor"<<endl;
        cout << "\t[2] - Editora"<<endl;
        cout << "\t[3] - Livro"<<endl;
        cout << "\t[4] - Revista"<<endl;
        cout << "\t[5] - Usuario"<<endl;
        cout << "\n\t[6] - Sair"<<endl;
        cin >> opcao;
        cls();

        while(opcao < 1 || opcao > 6){
            cout << "Digito invalido, insira novamente!\n";
            cout << "\t[1] - Autor"<<endl;
            cout << "\t[2] - Editora"<<endl;
            cout << "\t[3] - Livro"<<endl;
            cout << "\t[4] - Revista"<<endl;
            cout << "\t[5] - Usuario"<<endl;
            cout << "\n\t[6] - Sair"<<endl;
            cin >> opcao;
            cls();
        }

        switch(opcao){
            case 1:
                menuAutor();
                break;
            case 2:
                menuEditora();
                break;
            case 3:
                menuLivro();
                break;
            case 4:
                menuRevista();
                break;
            case 5:
                menuUsuario();
                break;
            case 6:
                menu = false;
                break;
        }
    }
}
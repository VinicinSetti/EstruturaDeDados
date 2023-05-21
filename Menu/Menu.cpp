#include <iostream>
#include "../Menu/Menu.h"

struct Menu{ //struct para rodar o menu
    void rodar();
};

void Menu::rodar() { //funcao para inicializacao do menu
    bool menu = true;
    int opcao;
    int contAutor = 0;
    int contEditora = 0;
    int contLivro = 0;
    int contRevista = 0;
    int contUsuario = 0;
    Controlador controlador = Controlador();
    Autor *autor = new Autor[10];
    Editora *editora = new Editora[10];
    Livro *livro = new Livro[10];
    Revista *revista = new Revista[10];
    Usuario *usuario = new Usuario[10];

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

        while(opcao < 1 || opcao > 6){ //verifica se a opcao inserida e valida
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

        switch(opcao){ //roda a funcao de menu da opcao selecionada
            case 1:
                menuAutor(autor[contAutor], controlador, contAutor);
                break;
            case 2:
                menuEditora(editora[contEditora], controlador, contEditora);
                break;
            case 3:
                menuLivro(livro[contLivro], controlador, contLivro);
                break;
            case 4:
                menuRevista(revista[contRevista], controlador, contRevista);
                break;
            case 5:
                menuUsuario(usuario[contUsuario], controlador, contUsuario);
                break;
            case 6:
                menu = false; //encerra o menu
                break;
        }
    }
}
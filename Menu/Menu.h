#ifndef TRABESTRUTURAM2_MENU_H
#define TRABESTRUTURAM2_MENU_H

#include "../Dominio/controlador.hpp"

struct Menu{
    void run();
};

void Menu::run() {
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

#endif //TRABESTRUTURAM2_MENU_H

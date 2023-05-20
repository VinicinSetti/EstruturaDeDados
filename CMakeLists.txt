cmake_minimum_required(VERSION 3.23)
project(TrabEstruturaM2)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(TrabEstruturaM2
        main.cpp
        Dominio/usuario.hpp Dominio/livro.hpp Dominio/autor.hpp Dominio/editora.hpp Dominio/revista.hpp Dominio/controlador.hpp Utilidades/HashTable/HashTable.hpp Utilidades/HashTable/HashTable.cpp Utilidades/LinkedList/LinkedList.cpp Utilidades/LinkedList/LinkedList.hpp)


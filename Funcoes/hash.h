#ifndef TRABESTRUTURAM2_HASH_H
#define TRABESTRUTURAM2_HASH_H

#include <iostream>
#include <string>

template<typename V, typename C>
struct NoHash{
    C chave;
    V valor;

    NoHash<V, C> *prox;
    NoHash<V, C> *ant;
    NoHash(V valor, C chave){
        this->valor = valor;
        this->chave = chave;
        this->prox = nullptr;
        this->ant = nullptr;
    }
};

template<typename V, typename C>
struct Hash{
    const int TAM = 10;
    NoHash<V, C> **tabela;

    Hash(){
        tabela = new NoHash<V, C>*[TAM];
        for(int i=0; i<TAM; i++){
            tabela[i] = nullptr;
        }
    }

    int hash(C chave){
        return chave % TAM;
    }

    void inserir(V valor, C chave){
        int valorHash = hash(chave);
    }
};

#endif //TRABESTRUTURAM2_HASH_H

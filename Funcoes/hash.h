#ifndef TRABESTRUTURAM2_HASH_H
#define TRABESTRUTURAM2_HASH_H

#include <iostream>
#include <string>

using namespace std;

template<typename V, typename C>
struct NoHash{
    C chave;
    V valor;

    NoHash<C, V> *prox;
    NoHash<C, V> *ant;
    NoHash(C chave, V valor){
        this->valor = valor;
        this->chave = chave;
        this->prox = nullptr;
        this->ant = nullptr;
    }
};

template<typename V, typename C>
struct Hash{
    const int TAM = 10;
    NoHash<C, V> **tabela;

    Hash(){
        tabela = new NoHash<C, V>*[TAM];
        for(int i=0; i<TAM; i++){
            tabela[i] = nullptr;
        }
    }

    int hash(C chave){
        return chave % TAM;
    }

    void inserir(C chave, V valor){
        int valorHash = hash(chave);
        NoHash<C, V> *ant = nullptr;
        NoHash<C, V> *entrada = tabela[valorHash];
        while(entrada != nullptr){
            ant = entrada;
            entrada = entrada->prox;
        }

        if(entrada == nullptr){
            entrada = new NoHash<C, V>(chave, valor);

            if(ant == nullptr){ tabela[valorHash] = entrada; }
            else{ ant->prox = entrada; }

        }else{ entrada->valor = valor; }
    }

    V* get(C chave){
        int valorHash = hash(chave);
        NoHash<C, V>* entrada = tabela[valorHash];
        while(entrada != nullptr){
            if(entrada->chave == chave) return &(entrada->valor);
            entrada = entrada->prox;
        }
        cout<<"Nenhum valor encontrado para a chave: "<< chave << endl;
        return nullptr;
    }

    void remover(C chave){
        int valorHash = hash(chave);
        NoHash<C, V> *ant = nullptr;
        NoHash<C, V> *entrada = tabela[valorHash];

        while(entrada != nullptr && entrada->chave != chave){
            ant = entrada;
            entrada = entrada->prox;
        }
        if(entrada == nullptr) return;
        else{
            if(ant == nullptr) tabela[valorHash] = entrada->prox;
            else{
                ant->prox = entrada->entrada;
            }
            delete entrada;
        }
    }
};

#endif //TRABESTRUTURAM2_HASH_H

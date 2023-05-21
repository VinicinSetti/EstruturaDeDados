#ifndef TRABESTRUTURAM2_HASH_H
#define TRABESTRUTURAM2_HASH_H

#include <iostream>
#include <string>

using namespace std;

template<typename C, typename V>
struct NoHash{ //Criacao do struct NoHash com seus ponteiros, variavel da chave, valor e metodo construtor
    C chave;
    V valor;

    NoHash<C, V> *prox; //Ponteiro para o proximo no na tabela hash
    NoHash<C, V> *ant; //Ponteiro para o no anterior na tabela hash
    NoHash(C chave, V valor){ //Inicializa o valor, chave, o ponteiro para o proximo no e para o no anterior
        this->valor = valor;
        this->chave = chave;
        this->prox = nullptr;
        this->ant = nullptr;
    }
};

template<typename C, typename V>
struct Hash{ //Criacao do struct Hash, com seu tamanho, e funcoes necessarias para implementacao da tabela hash
    const int tamHash = 10;
    int tamHash2 = 0;
    NoHash<C, V> **tabela;

    Hash(){ //Cria a tabela hash
        tabela = new NoHash<C, V>*[tamHash];
        for(int i=0; i<tamHash; i++){
            tabela[i] = nullptr;
        }
    }

    int hash(C chave){ //Aplica o calculo do hash
        return chave % tamHash;
    }

    void inserir(C chave, V valor){ //Insere uma informacao na tabela hash atraves de sua chave
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
        tamHash2++;
    }

    V* get(C chave){ //busca uma informacao na tabela hash
        int valorHash = hash(chave);
        NoHash<C, V>* entrada = tabela[valorHash];
        while(entrada != nullptr){
            if(entrada->chave == chave) return &(entrada->valor);
            entrada = entrada->prox;
        }
        cout<<"Nenhum valor encontrado para a chave: "<< chave << endl;
        return nullptr;
    }

    void remover(C chave){ //remove uma informacao da tabela hash
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
                ant->prox = entrada->prox;
            }
            delete entrada;
        }
    }
};

#endif //TRABESTRUTURAM2_HASH_H
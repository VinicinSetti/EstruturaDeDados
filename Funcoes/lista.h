#ifndef TRABESTRUTURAM2_LISTA_H
#define TRABESTRUTURAM2_LISTA_H

template <typename T>
struct NoLista{ //Criacao do struct NoLista com seus ponteiros, variavel da informacao e metodo construtor
    T info;

    NoLista<T>* prox;
    NoLista<T>* ant;
    NoLista(T info){
        this->info = info;
        this->prox = nullptr;
        this->ant = nullptr;
    }
};

template<typename T>
struct Lista{ //Criacao do struct Lista, com seu tamanho, e funcoes necessarias para implementacao da lista
    NoLista<T>* comeco;
    NoLista<T>* fim;
    int tamLista;

    Lista(){ //cria a lista
        this->comeco = nullptr;
        this->fim = nullptr;
        this->tamLista = 0;
    }

    void inserir(T info){ //insere uma infromacao na lista
        NoLista<T>* entrada = new NoLista<T>(info);
        if(comeco == nullptr){
            comeco = entrada;
            fim = entrada;
        }else{
            fim->prox = entrada;
            entrada->ant = fim;
            fim = entrada;
        }
        tamLista++;
    }

    void remover(T info){ //remove uma informacao da lista
        NoLista<T>* entrada = comeco;
        while(entrada != nullptr){
            if(entrada->info == info){
                if(entrada->ant == nullptr){
                    comeco = entrada->prox;
                }else{
                    entrada->ant->prox = entrada->prox;
                }
                if(entrada->prox == nullptr){
                    fim = entrada->ant;
                }else{
                    entrada->prox->ant = entrada->ant;
                }
                delete entrada;
                tamLista--;
                break;
            }
            entrada = entrada->prox;
        }
    }

    T get(int aux){ //busca uma informacao na lista
        NoLista<T>* entrada = comeco;
        for(int i=0; i<aux; i++){
            entrada = entrada->prox;
        }
        return entrada->info;
    }
};

#endif //TRABESTRUTURAM2_LISTA_H
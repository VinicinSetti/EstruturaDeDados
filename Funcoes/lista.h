#ifndef TRABESTRUTURAM2_LISTA_H
#define TRABESTRUTURAM2_LISTA_H

template <typename T>
struct NoLista{
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
struct Lista{
    NoLista<T>* comeco;
    NoLista<T>* fim;
    int tam;

    Lista(){
        this->comeco = nullptr;
        this->fim = nullptr;
        this->tam = 0;
    }

    void inserir(T info){
        NoLista<T>* entrada = new NoLista<T>(info);
        if(comeco == nullptr){
            comeco = entrada;
            fim = entrada;
        }else{
            fim->prox = entrada;
            entrada->ant = fim;
            fim = entrada;
        }
        tam++;
    }

    void remover(T info){
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
                tam--;
                break;
            }
            entrada = entrada->prox;
        }
    }

    T get(int aux){
        NoLista<T>* entrada = comeco;
        for(int i=0; i<aux; i++){
            entrada = entrada->prox;
        }
        return entrada->info;
    }
};

#endif //TRABESTRUTURAM2_LISTA_H

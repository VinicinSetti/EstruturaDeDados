#ifndef TRABESTRUTURAM2_DATA_H
#define TRABESTRUTURAM2_DATA_H
#include <string>

using namespace std;

bool ValidaData(string data){ //Faz a verificacao da data
    if(data.length() != 10) return false;

    if(data[2] != '/' || data[5] != '/') return false; //verifica se o padrao de data esta correto

    //separa o string no padrao dd/mm/aaaa em um string para dia, um para mes e um para ano
    string dia = data.substr(0,2);
    string mes = data.substr(3,2);
    string ano = data.substr(6,4);

    if(dia.length() != 2 || mes.length() != 2 || ano.length() != 4) return false; //verifica se a quantidade de caracteres de dia, mes e ano estao corretos

    for(int i = 0; i<2; i++){ //verifica se os valores inseridos sao validos
        if(dia[i]<'0' || dia[i]>'9') return false;
    }
    for(int i = 0; i<2; i++){
        if(mes[i]<'0' || mes[i]>'9') return false;
    }
    for(int i = 0; i<4; i++){
        if(ano[i]<'0' || ano[i]>'9') return false;
    }

    int diaD = stoi(dia); //converte o string do dia em int
    int mesM = stoi(mes); //converte o string do mes em int
    int anoA = stoi(ano); //converte o string do ano em int

    if (diaD < 0 || mesM < 0 || anoA < 0) return false;

    if(diaD > 31) return false; //verifica se o valor do dia inserido e um valor valido
    if(mesM > 12) return false; //verifica se o valor do mes inserido e um valor valido

    //verifica a quantidade de dias do mes de fevereiro
    if(mesM == 2){
        if(diaD > 29) return false;
        if(diaD == 29){
            if(anoA % 4 != 0 && (anoA % 100 != 0 || anoA %400 == 0)) return false;
        }
    }
    //verifica os meses que possuem 30 dias, caso seja o mes inserido
    if(mesM == 4 || mesM == 6 || mesM == 9 || mesM == 11){
        if(diaD>30) return false;
    }
    return true;
}

#endif //TRABESTRUTURAM2_DATA_H
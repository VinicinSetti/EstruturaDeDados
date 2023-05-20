#ifndef TRABESTRUTURAM2_DATA_H
#define TRABESTRUTURAM2_DATA_H
#include <string>

using namespace std;

bool ValidaData(string data){
    if(data.length() != 10) return false;

    if(data[2] != '/' || data[5] != '/') return false;

    string dia = data.substr(0,2);
    string mes = data.substr(3,2);
    string ano = data.substr(6,4);

    if(dia.length() != 2 || mes.length() != 2 || ano.length() != 4) return false;

    for(int i = 0; i<2; i++){
        if(dia[i]<'0' || dia[i]>'9') return false;
    }
    for(int i = 0; i<2; i++){
        if(mes[i]<'0' || mes[i]>'9') return false;
    }
    for(int i = 0; i<4; i++){
        if(ano[i]<'0' || ano[i]>'9') return false;
    }

    int diaD = stoi(dia);
    int mesM = stoi(mes);
    int anoA = stoi(ano);

    if (diaD < 0 || mesM < 0 || anoA < 0) return false;

    if(diaD > 31) return false;
    if(mesM > 12) return false;
    if(mesM == 2){
        if(diaD > 29) return false;
        if(diaD == 29){
            if(anoA % 4 != 0 && (anoA % 100 != 0 || anoA %400 == 0)) return false;
        }
    }
    if(mesM == 4 || mesM == 6 || mesM == 9 || mesM == 11){
        if(diaD>30) return false;
    }
    return true;
}

#endif //TRABESTRUTURAM2_DATA_H


//  d   d   /   m   m   /   a   a   a   a
//  0   1   2   3   4   5   6   7   8   9
//  a   a   a   a   /   m   m   /   d   d
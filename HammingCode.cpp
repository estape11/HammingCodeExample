//
// Created by Esteban Agüero Pérez  on 9/3/17.
//

#include "HammingCode.h"

void tabla1(string data){
    int numParidad =0;
    int pares=0;
    string temp="";
    int index=0;
    int valor=0;
    cout<<"\nTabla 1. Calculo de bit de paridad en el codigo Hamming"<<endl;
    cout<<"              ";
    for(int k=0;k<data.length();k++){
        if (potenciaDos(k+1)){
            numParidad++;
            if(numParidad<10) {
                cout << "P" << numParidad << "  ";
            }else{
                cout << "P" << numParidad << " ";
            }
        }else{
            valor++;
            if(valor<10) {
                cout << "D" << valor << "  ";
            }else{
                cout << "D" << valor << " ";
            }
        }
    }cout<<endl;

    cout<<"Dato recibido ";
    for(int i=0;i<data.length();i++){
        if (potenciaDos(i+1)) {
            cout<<"    ";
        }else{
            cout<<data[i]<<"   ";
        }
    }
    cout<<endl;

    for(int i=0;i<numParidad;i++) {
        cout<<"      P"<<(i+1)<<"      ";
        index = pow(2, i) - 1;
        pares = 0;
        for (int j = 0; j < data.size(); j++) {
            string binTemp = invertirString(toBinary(j + 1));
            if (j == index) {
                cout<<data[j]<<"   ";
            }

            if (binTemp[i] == '1') {
                if(potenciaDos(j+1)) {
                    continue;
                }else if ((data[j] - 48) == 1) {
                    cout<<"1   ";
                    pares++;
                }else{
                    cout<<"0   ";
                }
            }else{
                cout<<"    ";
            }
        }cout<<endl;
    }cout<<endl;
}

void tabla2(string data,string veri){
    int numParidad =0;
    int pares=0;
    string temp="";
    int index=0;
    int valor=0;
    cout<<"\nTabla 2. Comprobacion de bits de paridad en el codigo Hamming"<<endl;
    cout<<"              ";
    for(int k=0;k<data.length();k++){
        if (potenciaDos(k+1)){
            numParidad++;
            cout<<"P"<<numParidad<<" ";
        }else{
            valor++;
            cout<<"D"<<valor<<" ";
        }
    }cout<<"Resultado_Prueba Bit_Paridad"<<endl;

    cout<<"Dato recibido ";
    for(int i=0;i<data.length();i++){
        cout<<data[i]<<"  ";
    }cout<<endl;
    for(int i=0;i<numParidad;i++) {
        cout<<"      P"<<(i+1)<<"      ";
        index = pow(2, i) - 1;
        pares = 0;
        for (int j = 0; j < data.size(); j++) {
            string binTemp = invertirString(toBinary(j + 1));
            if (j == index) {
                cout<<data[j]<<"  ";
            }

            if (binTemp[i] == '1') {
                if(potenciaDos(j+1)) {
                    continue;
                }else if ((data[j] - 48) == 1) {
                    cout<<"1  ";
                    pares++;
                }else{
                    cout<<"0  ";
                }
            }else{
                cout<<"   ";
            }
        }
        if(veri[i]=='1'){
            cout<<"      Error           1     ";
        }else{
            cout<<"     Correcto         0     ";
        }
        cout<<endl;
    }cout<<endl;
}

string toHamming(string code, bool paridad){
    int i=0; //index for input
    int numParidad=0;
    string temp="";
    vector<int> result={};
    vector<int> firstRow={};
    for(int k=1;k<code.length()*2;k++){
        if(i==code.length()){
            break;
        }
        if (potenciaDos(k)){
            firstRow.push_back(-1);
            numParidad++;
        } else {
            firstRow.push_back(code[i]-48);
            i++;
        }
    }
    result=firstRow;
    int index=0;
    int pares;
    for (int k=0;k<numParidad;k++){
        pares=0;
        index=pow(2,k)-1;
        //cout<<"Bit Par "<<index<<endl;
        for (i=0;i<firstRow.size();i++){
            string binTemp=invertirString(toBinary(i+1));
            if(binTemp[k]=='1'){
                if(firstRow[i]==1){
                    pares++;
                }
            }
        }
        if (paridad){
            if (pares%2==0){
                result[index]=1;
            }else{
                result[index]=0;
            }
        }else{
            if (pares%2==0){
                result[index]=0;
            }else{
                result[index]=1;
            }
        }
    };

    for(int j=0;j<result.size();j++){
        temp+=to_string(result[j]);
    }
    tabla1(temp);
    return temp;
}

string verifyHamming(string data,bool paridad){
    int numParidad =0;
    int pares=0;
    string temp="";
    int index=0;
    for(int k=1;k<data.length();k++){
        if (potenciaDos(k)){
            numParidad++;
        }
    }
    for(int i=0;i<numParidad;i++){
        index=pow(2,i)-1;
        pares=0;
        for (int j=0;j<data.size();j++){
            string binTemp=invertirString(toBinary(j+1));
            if(j==index){
                continue;
            }

            if(binTemp[i]=='1'){
                if((data[j]-48)==1){
                    pares++;
                }
            }
        }
        //cout<<"Bit "<<(i+1)<<" pares "<<pares<<" Bit "<<data[index]<<endl;
        if (paridad){
            if (pares%2==0){
                if((data[index]-48)==1){
                    temp+="0";
                } else{
                    temp+="1";
                }
            }else{
                if((data[index]-48)==0){
                    temp+="0";
                } else{
                    temp+="1";
                }
            }
        }else{
            if (pares%2==0){
                if((data[index]-48)==0){
                    temp+="0";
                } else{
                    temp+="1";
                }
            }else{
                if((data[index]-48)==1){
                    temp+="0";
                } else{
                    temp+="1";
                }
            }
        }
    }
    return invertirString(temp);
}

string fromHamming(string data, bool paridad){
    string veri=verifyHamming(data,paridad);
    bool error=false;
    for(int i=0;i<veri.length();i++){
        if(veri[i]=='1'){
            error=true;
            break;
        }
    }
    if (error){
        tabla2(data,invertirString(veri));
        int index=toDecimal(veri);
        cout<<" *Error detectado en el bit "<<index<<" ["<<veri<<"]"<<endl;
        cout<<" *Dato sin recuperar: "<< data<<endl;
        if(data[index-1]=='1'){
            data[index-1]='0';
        }else{
            data[index-1]='1';
        }
        cout<<" *Dato recuperado: "<< data<<endl;
        string temp="";
        for (int j = 0; j < data.size(); j++) {
            if (potenciaDos(j+1)) {
                continue;
            }
            temp+=data[j];
        }
        return toHex(temp);
    } else {
        tabla2(data,invertirString(veri));
        string temp="";
        for (int j = 0; j < data.size(); j++) {
            if (potenciaDos(j+1)) {
                continue;
            }
            temp+=data[j];
        }
        return toHex(temp);
    }
}
//
// Created by Esteban Agüero Pérez  on 9/3/17.
//

#include "BaseConverter.h"

string invertirString(string str){
    string temp=string(str.rbegin(), str.rend());
    return temp;
}

string toBinary(int num){
    string temp="";
    if(num!=0){
        while(num!=0){
            temp+=to_string(num%2);
            num=num/2;
        }
    } else{
        temp="0";
    }
    return invertirString(temp);
}

string toBinary(string num){
    string temp="";
    for(int i=0;i<num.length();i++) {
        if (num[i] == 'A' || num[i] == 'a') {
            temp += toBinary(10);
        } else if (num[i] == 'B'|| num[i] == 'b') {
            temp += toBinary(11);
        } else if (num[i] == 'C'|| num[i] == 'c') {
            temp += toBinary(12);
        } else if (num[i] == 'D'|| num[i] == 'd') {
            temp += toBinary(13);
        } else if (num[i] == 'E'|| num[i] == 'e') {
            temp += toBinary(14);
        } else if (num[i] == 'F'|| num[i] == 'f') {
            temp += toBinary(15);
        } else{
            int numTemp=num[i]-48; //ASCII
            if (numTemp<2){
                temp +="000"+toBinary(numTemp);
            } else if(numTemp<4){
                temp +="00" + toBinary(numTemp);
            } else if(numTemp<8){
                temp += "0"+toBinary(numTemp);
            } else if (numTemp<10){
                temp += toBinary(numTemp);
            } else{
                temp="ERROR";
                break;
            }
        }
    }
    return temp;
}

bool potenciaDos(int num){
    float test=log2(num);
    if (test==int(test)) {
        return true;
    } else{
        return false;
    }
}

int toDecimal(string num) {
    string temp=invertirString(num);
    int valTemp=0;
    for(int i=0;i<num.length();i++){
        valTemp+=(temp[i]-48)*pow(2,i);
    }
    return valTemp;
}

string toHex(string num){
    string temp, hexTemp;
    if(num.length()%4==0){
        for(int i=0;i<num.length();i+=1) {
            hexTemp=num.substr(0,4);
            num=num.substr(4);
            if (hexTemp == "1010") {
                temp += "A";
            } else if (hexTemp == "1011") {
                temp += "B";
            } else if (hexTemp == "1100") {
                temp += "C";
            } else if (hexTemp == "1101") {
                temp += "D";
            } else if (hexTemp == "1110") {
                temp += "E";
            } else if (hexTemp == "1111") {
                temp += "F";
            } else if(hexTemp == "0000"){
                continue;
            } else {
                temp += to_string(toDecimal(hexTemp));
            }
        }
    }else{
        string zeros="";
        for(int i=num.length();i<(num.length()*2);i++){
            if(i%4==0){
                break;
            }else{
                zeros+="0";
            }
        }
        zeros+=num;
        cout<<zeros<<endl;
        temp=toHex(zeros);
    }
    return temp;
}

bool checkBin(string num){
    bool temp=true;
    for (int i=0;i<num.length();i++){
        if(num[i]=='1' || num[i]=='0'){
            continue;
        }else{
            temp=false;
            break;
        }
    }
    return temp;
}
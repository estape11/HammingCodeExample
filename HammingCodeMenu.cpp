//
// Created by Esteban Agüero Pérez  on 9/3/17.
//

#include "HammingCodeMenu.h"

string errorEntrada="ERROR: Valor no valido, verifique e intente de nuevo";
string menuText="============================================\n"
        "===============Codigo Hamming===============\n"
        "============================================\n"
        "= 1. Codificar                             =\n"
        "= 2. Decodificar                           =\n"
        "= 3. Modificar ultimo valor codificado     =\n"
        "= 4. Ver ultimo valor codificado           =\n"
        "= 5. Convertir BIN/HEX/DECIMAL             =\n"
        "= 6. Salir                                 =\n"
        "============================================";

void menu(){
    string entrada="";
    string ham;
    string bin;
    bool paridad;
    bool running=true;
    while(running){
        cout<<menuText<<endl;
        cout<<">> ";
        getline(cin, entrada);
        if(entrada=="1"){
            cout<<"Ingrese el numero hexadecimal a codificar : ";
            getline(cin, entrada);
            bin=toBinary(entrada);
            if (bin=="ERROR"){
                cout<<errorEntrada<<endl;
            } else{
                cout<<"Ingrese el metodo de paridad que desea aplicar (par=1, impar=0): ";
                getline(cin, entrada);
                if (entrada=="1"){
                    paridad=1;
                    ham=toHamming(bin,paridad);
                    cout<<" Valor Codificado > "<<ham<<endl;
                }else if (entrada=="0"){
                    paridad=0;
                    ham=toHamming(bin,paridad);
                    cout<<" Valor Codificado > "<<ham<<endl;
                }else{
                    cout<<errorEntrada<<endl;
                }

            }
        } else if(entrada=="2"){
            cout<<"¿Desea utilizar el ultimo valor codificado? (y/n): ";
            getline(cin, entrada);
            if (entrada=="y"){
                if (ham.length()==0){
                    cout<<"ERROR: Ningun valor ingresado previamente"<<endl;
                } else{
                    cout<<" Valor Codificado > "<<ham<<endl;
                    string t=fromHamming(ham,paridad);
                    cout<<" Valor Decodificado > "<<t<<endl;
                }
            } else if(entrada=="n"){
                cout<<"Ingrese el numero binario a decodificar : ";
                getline(cin, entrada);
                if(!checkBin(entrada)){
                    cout<<errorEntrada<<endl;
                }else{
                    ham=entrada;
                    cout<<"Ingrese el metodo de paridad que posee la cadena ingresada (par=1, impar=0): ";
                    getline(cin, entrada);
                    if (entrada=="1"){
                        paridad=1;
                        cout<<" Valor Codificado > "<<ham<<endl;string t=fromHamming(ham,paridad);
                        cout<<" Valor Decodificado > "<<t<<endl;
                    }else if (entrada=="0"){
                        paridad=0;
                        cout<<" Valor Codificado > "<<ham<<endl;
                        string t=fromHamming(ham,paridad);
                        cout<<" Valor Decodificado > "<<t<<endl;
                    }else{
                        cout<<errorEntrada<<endl;
                    }
                }
            } else{
                cout<<errorEntrada<<endl;
            }
        }else if(entrada=="3"){
            if(ham.length()==0){
                cout<<"ERROR: Ningun valor ingresado previamente"<<endl;
            }else{
                cout<<" Valor Codificado > "<<ham<<endl;
                cout<<"Ingrese el numero de indice que desea modificar: (inicia en cero) > ";
                getline(cin, entrada);
                try {
                    int ind=stoi(entrada);
                    if(ind>=ham.length()){
                        throw std::invalid_argument( "Valor invalido" );
                    } else{
                        cout<<"Ingrese el nuevo dato: > ";
                        getline(cin, entrada);
                        if(entrada=="0" || entrada=="1") {
                            ham[ind]=entrada[0];
                            cout<<"> Dato actualizado con exito "<<endl;
                        } else{
                            throw std::invalid_argument("Valor invalido");
                        }
                    }
                }catch (exception e){
                    cout<<errorEntrada<<endl;
                }
            }

        }else if(entrada=="4"){
            if(ham.length()==0){
                cout<<"ERROR: Ningun valor ingresado previamente"<<endl;
            }else{
                cout<<" Valor Codificado > "<<ham<<endl;
            }
        }else if(entrada=="6"){running=false;}
        else{cout<<errorEntrada<<endl;}
    }

}
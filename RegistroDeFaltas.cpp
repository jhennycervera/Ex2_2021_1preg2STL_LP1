/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RegistroDeFaltas.cpp
 * Author: Jhenny Cervera Vargas
 * Codigo: 20182841
 * Created on 4 de diciembre de 2021, 03:15 PM
 */

#include "RegistroDeFaltas.h"
#include <fstream>
#include <cstring>
#include <iostream>
#include <iomanip>

using namespace std;

RegistroDeFaltas::RegistroDeFaltas() {
}

RegistroDeFaltas::RegistroDeFaltas(const RegistroDeFaltas& orig) {
}

RegistroDeFaltas::~RegistroDeFaltas() {
}

void RegistroDeFaltas::leerConductores() {
    ifstream arch("ConductoresP2.csv", ios::in);
    
    if(!arch){
        cout<<"No se puede abrir el archivo ConductoresP2.csv"<<endl;
        exit(1);
    }
    
    Conductor auxCond;
    while(1){
        auxCond.lee(arch);
        if(arch.eof()) break;
        conductores.push_back(auxCond); 
    }
}

void RegistroDeFaltas::imprimir() {
    
    ofstream arch("Reporte.txt", ios:: out);
    if(!arch){
         cout<<"No se puede abrir el archivo Reporte.txt"<<endl;
        exit(1);
    }
    
    for(  vector<Conductor>::iterator it= conductores.begin() ; it!= conductores.end();
                                                                it++){
        arch<<*it; //PREGUNTAR porq no funciona con el metodo imprime, no lo reconoce
    }
}

void RegistroDeFaltas::leerFaltas() {
    
    ifstream arch("RegistroDeFaltas.csv", ios::in);
    if(!arch){
        cout<<"No se puede abrir el archivo ConductoresP2.csv"<<endl;
        exit(1);
    }
    
    Falta auxFalta;
    int rlic;
    while(1){
        arch>>rlic;
        if(arch.eof()) break;
        arch.get(); //,
        auxFalta.leer(arch); //lee los demas datos en un auxiliar de Faltas
        
        for(vector <Conductor>::iterator it= conductores.begin();
                        it!= conductores.end(); it++){
            
            if( rlic == it->GetLicencia() ){
               //conductor = Falta
                *it = auxFalta; //sobrecarga
            }
        }
        
    }
    
}

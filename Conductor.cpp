/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Conductor.cpp
 * Author: Jhenny Cervera Vargas
 * Codigo: 20182841
 * Created on 4 de diciembre de 2021, 03:01 PM
 */

#include "Conductor.h"
#include <fstream>
#include <cstring>
#include <iostream>
#include <iomanip>
using namespace std;

Conductor::Conductor() {
    nombre = nullptr;
}

Conductor::Conductor(const Conductor& orig) {
    
    *this = orig;
}

Conductor::~Conductor() {
    if (nombre != nullptr) delete nombre;
}

void Conductor::GetNombre(char* cad) const {
    if (nombre == nullptr) cad[0] = 0;
    else strcpy(cad, nombre);
}

void Conductor::SetNombre(char* cad) {

    if (cad == nullptr) return;
    if (nombre != nullptr) delete nombre;
    nombre = new char[strlen(cad) + 1];
    strcpy(nombre, cad);
}

void Conductor::SetLicencia(int licencia) {
    this->licencia = licencia;
}

int Conductor::GetLicencia() const {
    return licencia;
}

 //agrega una falta al final del arreglo falta
void Conductor::operator=(const Falta& f) {  
    falta.push_back(f); //se debe hacer el constructor copia de falta
}


void Conductor :: operator =(const Conductor& c){
    char rnombre[150];
    c.GetNombre(rnombre);
    licencia= c.GetLicencia();
    SetNombre(rnombre);
    
   //copia el arreglo de faltas de c a su arreglo de faltas
   
    vector<Falta>::const_iterator itc; //tiene que ser const por const Conductor &c en el parametro
    
    for( itc = c.falta.begin(); itc!= c.falta.end() ; itc++){
        falta.push_back(*itc); 
    }
}



void Conductor::lee(ifstream& arch) { //lee y carga sus datos excepto las faltas
    
    int rcod;
    char rnombre[150];
    arch>>rcod;
    if(arch.eof()) return;
    arch.get(); //,
    arch.getline(rnombre, 150);
    
    licencia = rcod;
    SetNombre(rnombre);
    
}

void Conductor::imprime(ofstream& arch) {
    
    arch<<left<<setw(10)<<licencia<<nombre<<endl;
    
    //imprimir las faltas
//    for(vector<Falta>::iterator it= falta.begin(); it!= falta.end();
//                                    it++){
//        it->imprime(arch);
//    }
    arch<<endl;
}

void operator << (ofstream &arch,  const Conductor & c){
    
    char nombre[150];
    c.GetNombre(nombre);
    arch<<left<<setw(10)<<c.GetLicencia()<<nombre<<endl;
}
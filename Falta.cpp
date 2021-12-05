/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Falta.cpp
 * Author: Jhenny Cervera Vargas
 * Codigo: 20182841
 * Created on 4 de diciembre de 2021, 02:58 PM
 */

#include "Falta.h"
#include <fstream>
#include <cstring>
#include <iostream>
#include <iomanip>
using namespace std;

Falta::Falta() {
    placa = nullptr;
}

Falta::Falta(const Falta& orig) { 
    *this=orig;
}

Falta::~Falta() {
    if (placa != nullptr) delete placa;
}

void Falta::SetMulta(double multa) {
    this->multa = multa;
}

double Falta::GetMulta() const {
    return multa;
}

void Falta::SetFecha(int fecha) {
    this->fecha = fecha;
}

int Falta::GetFecha() const {
    return fecha;
}

void Falta::GetPlaca(char* cad) const {
    if (placa == nullptr) cad[0] = 0;
    else strcpy(cad, placa);
}

void Falta::SetPlaca(char* cad) {
    if (cad == nullptr) return;
    if (placa != nullptr) delete placa;
    placa = new char[strlen(cad) + 1];
    strcpy(placa, cad);
}

void Falta::operator=(const Falta& f) {
   fecha= f.GetFecha();
    multa= f.GetMulta();
}

void Falta::leer(ifstream& arch) {
    char rplaca[20], c;
    int dd, mm, aa, rfecha;
    double rmulta;
    
    arch.getline(rplaca, 20,',');
    arch>>dd>>c>>mm>>c>>aa>>c>>rmulta;
    rfecha= dd+ mm*100 + aa* 10000;
    
    fecha= rfecha;
    multa= rmulta;
    SetPlaca(rplaca);
}

//void Falta::imprime(ofstream& arch) {
//    
//    arch<<setw(10)<<placa<<setw(10)<<fecha<<multa<<endl;
//}

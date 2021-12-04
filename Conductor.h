/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Conductor.h
 * Author: Jhenny Cervera Vargas
 * Codigo: 20182841
 * Created on 4 de diciembre de 2021, 03:01 PM
 */

#ifndef CONDUCTOR_H
#define CONDUCTOR_H
#include <fstream>
#include <vector>
#include <iterator>
#include "Falta.h"
using namespace std;

class Conductor {
private:
    int licencia;
    char* nombre;
    vector<Falta> falta;

public:
    Conductor();
    Conductor(const Conductor& orig);
    virtual ~Conductor();


    void SetNombre(char* cad);
    void GetNombre(char* cad) const;
    void SetLicencia(int licencia);
    int GetLicencia() const;
    
    void operator = (const Conductor &);
    void operator = (const Falta &);
    
    void lee(ifstream &arch);
    void imprime(ofstream &arch); //falla
};


void operator << (ofstream &arch, const Conductor &);
#endif /* CONDUCTOR_H */


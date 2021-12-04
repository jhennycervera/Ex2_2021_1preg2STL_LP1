/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RegistroDeFaltas.h
 * Author: Jhenny Cervera Vargas
 * Codigo: 20182841
 * Created on 4 de diciembre de 2021, 03:15 PM
 */

#ifndef REGISTRODEFALTAS_H
#define REGISTRODEFALTAS_H
#include <fstream>
using namespace std;
#include <vector>

#include "Conductor.h"
class RegistroDeFaltas {
private:
    vector <Conductor> conductores;
public:
    RegistroDeFaltas();
    RegistroDeFaltas(const RegistroDeFaltas& orig);
    virtual ~RegistroDeFaltas();

    
    void leerConductores();
    void leerFaltas();
    void imprimir();
};

#endif /* REGISTRODEFALTAS_H */


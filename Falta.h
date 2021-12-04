/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Falta.h
 * Author: Jhenny Cervera Vargas
 * Codigo: 20182841
 * Created on 4 de diciembre de 2021, 02:58 PM
 */

#ifndef FALTA_H
#define FALTA_H
#include <fstream>
using namespace std;

class Falta {
private:
    char* placa;
    int fecha;
    double multa;
public:
    Falta();
    Falta(const Falta& orig);
    virtual ~Falta();
    void SetMulta(double multa);
    double GetMulta() const;
    void SetFecha(int fecha);
    int GetFecha() const;
    void SetPlaca(char* cad);
    void GetPlaca(char * cad) const;
    
    void operator = (const Falta & f); 
    
    void leer(ifstream &arch);

};

#endif /* FALTA_H */


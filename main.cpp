/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Jhenny Cervera Vargas
 * Codigo: 20182841
 * Created on 4 de diciembre de 2021, 02:30 PM
 */


#include <iostream>
#include <iomanip>        
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;
#include "RegistroDeFaltas.h"

/*
 * 
 */
int main(int argc, char** argv) {
    
   
    RegistroDeFaltas reg;
    
    
    reg.leerConductores();
    //reg.imprimir();
    //reg.leerFaltas();
    //reg.imprimir();
    
    
    return 0;
}



//bool compareInterval(Conductor i1, Conductor i2)
//{
//    return (i1.GetLicencia() < i2.GetLicencia());
//}
//
////
//sort(conductores.begin(), conductores.end(), compareInterval);
//sort(conductores.begin(), conductores.end(), greater<Nodo>());
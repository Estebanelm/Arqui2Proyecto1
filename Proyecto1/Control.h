/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Control.h
 * Author: pelo
 *
 * Created on August 19, 2018, 11:55 AM
 */

#ifndef CONTROL_H
#define CONTROL_H

#include "Bus.h"
#include "BusBuffer.h"
#include <string>

class Control {
public:
    Control();
    virtual ~Control();
    
    std::string ObtenerDeMemoria(int direccion, int id);
    bool EscribirEnMemoria(int direccion, std::string dato, int id);
private:
    Bus * bus;
};

#endif /* CONTROL_H */


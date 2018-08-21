/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Bus.h
 * Author: pelo
 *
 * Created on August 19, 2018, 11:55 AM
 */

#ifndef BUS_H
#define BUS_H

#define NOBLOQUES 16
#define COLUMNAS 3
#include <string>
#include <vector>
#include "Memoria.h"

class Bus {
public:
    static Bus * getInstance();
    void newCache(std::string*);
    std::string obtenerDeMemoria(int direccion);
private:
    static Bus * instance;
    Bus();
    std::vector<std::string*> cacheCollection;
};

#endif /* BUS_H */


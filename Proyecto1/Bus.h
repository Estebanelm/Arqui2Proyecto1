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
    void InvalidarDatoEnCaches(std::string tag, int id);
    void EscribirEnMemoria(int direccion, std::string dato);
    std::vector<std::string*> GetCacheCollection();
private:
    static Bus * instance;
    Bus();
    std::vector<std::string*> cacheCollection;
    Memoria * memoria;
};

#endif /* BUS_H */


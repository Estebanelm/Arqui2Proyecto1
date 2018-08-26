/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cache.h
 * Author: pelo
 *
 * Created on August 19, 2018, 11:50 AM
 */

#ifndef CACHE_H
#define CACHE_H

#include "Bus.h"
#include <string>
#include <cstdio>
#include "Control.h"

#define NOBLOQUES 16
#define NOCOLUMNAS 3

class Cache {
public:
    Cache(Bus * busExistente, int id);
    virtual ~Cache();
    std::string LeerBloque(int direccion);
    Control * GetControl();
    void SetControl(Control* control);
    void EscribirBloque(int direccion, std::string dato);
private:
    Bus * bus;
    std::string datos[NOBLOQUES];
    int id;
    Control * control;
};

#endif /* CACHE_H */


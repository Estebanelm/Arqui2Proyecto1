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


#define NOBLOQUES 16
#define NOCOLUMNAS 3

class Cache {
public:
    Cache(Bus * busExistente, int id);
    virtual ~Cache();
    char * LeerBloque(int direccion);
private:
    Bus * bus;
    char datos[NOBLOQUES][NOCOLUMNAS];
    int id;
};

#endif /* CACHE_H */


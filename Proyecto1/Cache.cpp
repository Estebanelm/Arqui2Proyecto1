/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cache.cpp
 * Author: pelo
 * 
 * Created on August 19, 2018, 11:50 AM
 */

#include "Cache.h"

Cache::Cache(Bus * busExistente, int id) {
    bus = busExistente;
    for (int i = 0; i < NOBLOQUES; i++)
    {
        for (int k = 0; k < NOCOLUMNAS-1; k++)
        {
            datos[i][k] = 0;
        }
        datos[i][NOCOLUMNAS-1] = 's';
    }
    this->id = id;
}

Cache::~Cache() {
}

char * Cache::LeerBloque(int direccion)
{
    if (datos[direccion][NOCOLUMNAS-1] == 's' || datos[direccion][NOCOLUMNAS-1] == 'm')
    {
        return datos[direccion];
    }
    //invalid or modified, ask control to do something
    datos[direccion][NOCOLUMNAS-1] == 'i';
    return datos[direccion];
}

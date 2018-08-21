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
    std::string newDatos[NOBLOQUES];
    datos = newDatos;
    for (int i = 0; i < NOBLOQUES; i++)
    {
        for (int k = 0; k < NOCOLUMNAS-1; k++)
        {
            datos[i].at(k) = 0;
        }
        datos[i].at(NOCOLUMNAS-1) = 's';
    }
    this->id = id;
    bus->newCache(datos);
}

Cache::~Cache() {
}

std::string Cache::LeerBloque(int direccion)
{
    if (datos[direccion].at(NOCOLUMNAS-1) == 's' || datos[direccion].at(NOCOLUMNAS-1) == 'm')
    {
        return datos[direccion];
    }
    datos[direccion] = bus->obtenerDeMemoria(direccion);
    datos[direccion].at(NOCOLUMNAS-1) == 's';
    return datos[direccion];
}

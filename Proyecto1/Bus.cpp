/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Bus.cpp
 * Author: pelo
 * 
 * Created on August 19, 2018, 11:55 AM
 */

#include "Bus.h"

Bus* Bus::instance = 0;

Bus::Bus() {
    memoria = Memoria::getInstance();
}

Bus * Bus::getInstance()
{
    if (instance == 0)
    {
        instance = new Bus();
    }
    return instance;
}

void Bus::newCache(std::string * cache)
{
    cacheCollection.push_back(cache);
}

std::string Bus::obtenerDeMemoria(int direccion, int id)
{
    Memoria::getInstance()->LeerDato(direccion);
}
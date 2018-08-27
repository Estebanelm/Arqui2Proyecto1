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

std::string Bus::obtenerDeMemoria(int direccion)
{
    return memoria->LeerDato(direccion);
}

void Bus::EscribirEnMemoria(int direccion, std::string dato)
{
    memoria->EscribirDato(direccion, dato);
}

void Bus::InvalidarDatoEnCaches(std::string tag, int id)
{
    for (int i = 0; i < cacheCollection.size() ; i++)
    {
        for (int k=0; k<16; k++)
        {
            if (cacheCollection.at(i)[k].substr(3).compare(tag)==0 && i!=id)
            {
                cacheCollection.at(i)[k].at(2) = 'i';
            }
        }
    }
}

std::vector<std::string*> Bus::GetCacheCollection()
{
    return cacheCollection;
}
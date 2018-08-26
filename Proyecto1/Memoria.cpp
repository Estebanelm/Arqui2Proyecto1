/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Memoria.cpp
 * Author: pelo
 * 
 * Created on August 19, 2018, 11:55 AM
 */

#include "Memoria.h"

Memoria* Memoria::instance = 0;

Memoria::Memoria() {
    for (int i = 0; i < NOBLOQUES; i++)
    {
        for (int k = 0; k < NOCOLUMNAS-1; k++)
        {
            datos[i].push_back(0);
        }
    }
}

Memoria * Memoria::getInstance()
{
    if (instance == 0)
    {
        instance = new Memoria();
    }
    
    return instance;
}

std::string Memoria::LeerDato(int direccion)
{
    return datos[direccion];
}
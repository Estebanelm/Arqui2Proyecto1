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
            datos[i].push_back(0);
        }
        datos[i].append("s");
        datos[i].push_back(i);
    }
    this->id = id;
    bus->newCache(datos);
    control = new Control();
}

Cache::~Cache() {
}

std::string Cache::LeerBloque(int direccion)
{
    if (datos[direccion].at(NOCOLUMNAS-1) == 's' || datos[direccion].at(NOCOLUMNAS-1) == 'm')
    {
        return datos[direccion];
    }
    else
    {
        datos[direccion] = control->ObtenerDeMemoria(direccion, id);
        datos[direccion].append("s" + direccion);
    }
    return datos[direccion];
}

void Cache::EscribirBloque(int direccion, std::string dato)
{
    datos[direccion] = dato;
    datos[direccion].append("m");
    datos[direccion].push_back(direccion);
    std::string asd = datos[direccion].substr(3);
    std::string asd1 = datos[direccion].substr(0,2);
    control->EscribirEnMemoria(std::stoi(datos[direccion].substr(3)), datos[direccion].substr(0,3));
}

void Cache::SetControl(Control* control) {
    this->control = control;
}

Control* Cache::GetControl() {
    return control;
}

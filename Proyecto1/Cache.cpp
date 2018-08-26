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
        datos[i].append(std::to_string(i));
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
        std::string datoObtenido = control->ObtenerDeMemoria(direccion, id);
        if (datoObtenido.compare("invalido")==0)
        {
            return datoObtenido;
        }
        datos[direccion] = datoObtenido;
        datos[direccion].append("s" + direccion);
    }
    return datos[direccion];
}

bool Cache::EscribirBloque(int direccion, std::string dato)
{
    if (control->EscribirEnMemoria(direccion, dato, id))
    {
        datos[direccion] = dato;
        datos[direccion].append("m");
        datos[direccion].push_back(direccion);
        return true;
    }
    return false;
}

void Cache::SetControl(Control* control) {
    this->control = control;
}

Control* Cache::GetControl() {
    return control;
}

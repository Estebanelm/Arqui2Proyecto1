/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Procesador.cpp
 * Author: pelo
 * 
 * Created on August 19, 2018, 11:34 AM
 */

#include "Procesador.h"

Procesador::Procesador(Bus * busExistente, int id) {
    this->id = id;
    this->cache = new Cache(busExistente);
}

Procesador::~Procesador() {
}

void Procesador::EnviarPeticion()
{
    int tipoDePeticion = rand() % 3;
    if (tipoDePeticion == PETILEER)
    {
        LeerBloque();
    }
    if (tipoDePeticion == PETIESCRIBIR)
    {
        EscribirEnBloque();
    }
    if (tipoDePeticion == PETIPROCESAR)
    {
        CicloProcesamiento();
    }
}

int Procesador::GetId() const {
    return id;
}

void Procesador::LeerBloque()
{
    printf("Procesador %d: leer\n", id);
}
void Procesador::EscribirEnBloque()
{
    printf("Procesador %d: escribir\n", id);
}

void Procesador::CicloProcesamiento()
{
    printf("Procesador %d: procesar\n", id);
}

void Procesador::SetCache(Cache* cache) {
    this->cache = cache;
}

Cache* Procesador::GetCache() {
    return cache;
}
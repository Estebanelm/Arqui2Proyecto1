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
    this->cache = new Cache(busExistente, id);
    this->repetirInstruccion = false;
}

Procesador::~Procesador() {
}

void Procesador::EnviarPeticion()
{
    if (!repetirInstruccion)
    {
        direccionAUsar = rand() % NUMEROBLOQUES;
        datoAEscribir = "";
        datoAEscribir.push_back(rand() % 10);
        datoAEscribir.push_back(rand() % 9);
        solicitudARealizar = rand() % 3;
    }
    if (solicitudARealizar == PETILEER)
    {
        repetirInstruccion = LeerBloque(direccionAUsar);
    }
    if (solicitudARealizar == PETIESCRIBIR)
    {
        repetirInstruccion = EscribirEnBloque(direccionAUsar, datoAEscribir);
    }
    if (solicitudARealizar == PETIPROCESAR)
    {
        CicloProcesamiento();
    }
}

int Procesador::GetId() const {
    return id;
}

bool Procesador::LeerBloque(int direccion)
{
    //printf("Procesador %d: leer\n", id);
    std::string bloqueLeido = cache->LeerBloque(direccion);
    if (bloqueLeido.compare("invalido")==0)
    {
        //printf("ID: %d. Se espera para leer dato en la direccion %d\n", id, direccion);
        return true;
    }
    //printf("ID: %d. Se leyo el dato: %d%d en la direccion %d\n", id, bloqueLeido.at(0), bloqueLeido.at(1), direccion);
    return false;
}
bool Procesador::EscribirEnBloque(int direccion, std::string dato)
{
    //printf("Procesador %d: escribir\n", id);
    if (!cache->EscribirBloque(direccion, dato))
    {
        //printf("ID: %d. Se espera para escribir el dato %d%d en la direccion %d\n", id, dato.at(0), dato.at(1), direccion);
        return true;
    }
    //printf("ID: %d. Escribe el dato %d%d en la direccion %d\n", id, dato.at(0), dato.at(1), direccion);
    return false;
}

void Procesador::CicloProcesamiento()
{
    //printf("Procesador %d: procesar\n", id);
}

void Procesador::SetCache(Cache* cache) {
    this->cache = cache;
}

Cache* Procesador::GetCache() {
    return cache;
}

bool Procesador::IsRepetirInstruccion(){
    return repetirInstruccion;
}

int Procesador::GetSolicitudARealizar(){
    return solicitudARealizar;
}

std::string Procesador::GetDatoAEscribir(){
    return datoAEscribir;
}

int Procesador::GetDireccionAUsar(){
    return direccionAUsar;
}
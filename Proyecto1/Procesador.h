/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Procesador.h
 * Author: pelo
 *
 * Created on August 19, 2018, 11:34 AM
 */

#ifndef PROCESADOR_H
#define PROCESADOR_H

#include <cstdio>
#include "Cache.h"
#include "Bus.h"
#include <cstdlib>

//Tipo de peticion
#define PETILEER 0
#define PETIESCRIBIR 1
#define PETIPROCESAR 2

class Procesador {
public:
    Procesador(Bus * busExistente, int id);
    virtual ~Procesador();
    void EnviarPeticion();
    void SetId(int id);
    void CicloProcesamiento();
    void LeerBloque();
    void EscribirEnBloque();
    int GetId() const;
    void SetCache(Cache* cache);
    Cache* GetCache();
private:
    int id;
    Cache * cache;
};

#endif /* PROCESADOR_H */


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Chip.h
 * Author: pelo
 *
 * Created on August 19, 2018, 11:55 AM
 */

#ifndef CHIP_H
#define CHIP_H
#include "Bus.h"
#include "Procesador.h"
#include "SemaphoreSingleton.h"
#include <cstdio>
#include <semaphore.h>
#include <pthread.h>
#include <time.h>
#include <cstdlib>

class Chip {
public:
    Chip();
    Chip(Bus * busExistente, int id);
    virtual ~Chip();
    void SetControl(Control* control);
    Control* GetControl();
    void SetProcesador(Procesador* procesador);
    Procesador* GetProcesador();
    static void* Trabajar(void* object);
    void SetId(int id);
    int GetId();
    pthread_t chipThread;
private:
    Procesador * procesador;
    int id;
};

#endif /* CHIP_H */


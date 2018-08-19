/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: pelo
 *
 * Created on August 18, 2018, 3:01 PM
 */

#include <cstdlib>
#include <cstdio>
#include "Chip.h"
#include "Bus.h"
#include "SemaphoresSingleton.h"
#include <unistd.h>

#define NOPROCESSORS 4


using namespace std;
/*
 * 
 */

int main(int argc, char** argv) {
    Bus * busMemoria = new Bus();
    Chip * chipsDisponibles[NOPROCESSORS];
    for (int i = 0; i < NOPROCESSORS; i++)
    {
        chipsDisponibles[i] = new Chip(busMemoria, i);
        sem_init(&SemaphoresSingleton::getInstance()->semaforoGeneralPeticiones[i], 0, 0);
        pthread_create(&chipsDisponibles[i]->chipThread, NULL, Chip::Trabajar, chipsDisponibles[i]);
    }
    while (1)
    {
        printf("\nNuevo intento\n");
        for (int i = 0; i < NOPROCESSORS; i++)
        {
            sem_post(&SemaphoresSingleton::getInstance()->semaforoGeneralPeticiones[i]);
        }
        sleep(1);
    }
    
    void *status;
    for (int i = 0; i < NOPROCESSORS; i++)
    {
        pthread_join(chipsDisponibles[i]->chipThread, &status);
    }
    return 0;
}


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
#include "SemaphoreSingleton.h"
#include <unistd.h>
#include <string>

#define NOPROCESSORS 4


using namespace std;
/*
 * 
 */

int main(int argc, char** argv) {
    Chip * chipsDisponibles[NOPROCESSORS];
//    Chip * newChip = new Chip(Bus::getInstance(), 1);
//    std::string asd1 = "";
//    asd1.push_back(0);
//    asd1.push_back(5);
//    newChip->GetProcesador()->GetCache()->EscribirBloque(1, asd1);
    for (int i = 0; i < NOPROCESSORS; i++)
    {
        chipsDisponibles[i] = new Chip(Bus::getInstance(), i);
        sem_init(&SemaphoreSingleton::getInstance()->semaforoGeneralPeticiones[i], 0, 0);
        pthread_create(&chipsDisponibles[i]->chipThread, NULL, Chip::Trabajar, chipsDisponibles[i]);
    }
    while (1)
    {
        printf("\nNuevo intento\n");
        for (int i = 0; i < NOPROCESSORS; i++)
        {
            sem_post(&SemaphoreSingleton::getInstance()->semaforoGeneralPeticiones[i]);
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


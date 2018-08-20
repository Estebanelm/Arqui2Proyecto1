/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SemaphoresSingleton.h
 * Author: pelo
 *
 * Created on August 19, 2018, 1:16 PM
 */

#ifndef SEMAPHORESSINGLETON_H
#define SEMAPHORESSINGLETON_H

#include <semaphore.h>

#define NUMBEROFPROCESSORS 4

class SemaphoreSingleton {
public:
    static SemaphoreSingleton * getInstance();
    sem_t semaforoGeneralPeticiones [NUMBEROFPROCESSORS];
private:
    static SemaphoreSingleton * instance;
    SemaphoreSingleton();
};

#endif /* SEMAPHORESSINGLETON_H */


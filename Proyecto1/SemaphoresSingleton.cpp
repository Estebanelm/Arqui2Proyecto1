/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SemaphoresSingleton.cpp
 * Author: pelo
 * 
 * Created on August 19, 2018, 1:16 PM
 */

#include "SemaphoresSingleton.h"

SemaphoresSingleton* SemaphoresSingleton::instance = 0;

SemaphoresSingleton::SemaphoresSingleton() {
    semaforoGeneralPeticiones;
    for (int i = 0; i < NUMBEROFPROCESSORS ; i++)
    {
        sem_init(&semaforoGeneralPeticiones[i],0,1);
    }
}

SemaphoresSingleton * SemaphoresSingleton::getInstance()
{
    if (instance == 0)
    {
        instance = new SemaphoresSingleton();
    }
    
    return instance;
}


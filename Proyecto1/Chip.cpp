/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Chip.cpp
 * Author: pelo
 * 
 * Created on August 19, 2018, 11:55 AM
 */

#include "Chip.h"

Chip::Chip() {
    procesador = new Procesador(NULL, 0);
}

Chip::Chip(Bus * busExistente, int id){
    procesador = new Procesador(busExistente, id);
    this->id = id;
}

Chip::~Chip() {
}

void Chip::SetProcesador(Procesador* procesador) {
    this->procesador = procesador;
}

Procesador* Chip::GetProcesador() {
    return procesador;
}

void* Chip::Trabajar(void* object)
{
    Chip * currentChip = static_cast<Chip*>(object);
    int id = currentChip->GetId();
    srand(time(0));
    while(1)
    {
        sem_wait(&SemaphoreSingleton::getInstance()->semaforoGeneralPeticiones[id]);
        currentChip->procesador->EnviarPeticion();
    }
}

void Chip::SetId(int id) {
    this->id = id;
}

int Chip::GetId(){
    return id;
}
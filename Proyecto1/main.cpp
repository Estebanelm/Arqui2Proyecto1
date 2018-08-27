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
#include <iostream>
#include <termios.h>
#include <unistd.h>
#include "BusBuffer.h"
#include "Bus.h"

#define NOPROCESSORS 4

//Tipo de peticion
#define PETILEER 0
#define PETIESCRIBIR 1
#define PETIPROCESAR 2


using namespace std;
/*
 * 
 */

Chip * chipsDisponibles[NOPROCESSORS];

int getch(void)
{
	struct termios oldt, newt;
	int ch;

	tcgetattr(STDIN_FILENO, &oldt);
	newt = oldt;
	newt.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);
	ch = getchar();
	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

	return ch;
}

void imprimirEstado()
{
    for (int i = 0; i<NOPROCESSORS; i++)
    {
        int peticionDeProcesador = chipsDisponibles[i]->GetProcesador()->GetSolicitudARealizar();
        if (peticionDeProcesador == PETILEER)
        {
            printf("Procesador %d: leer direccion %d\n", chipsDisponibles[i]->GetId(), chipsDisponibles[i]->GetProcesador()->GetDireccionAUsar());
        }
        if (peticionDeProcesador == PETIESCRIBIR)
        {
            printf("Procesador %d: escribir dato %d%d en direccion %d\n", chipsDisponibles[i]->GetId(), chipsDisponibles[i]->GetProcesador()->GetDatoAEscribir().at(0), chipsDisponibles[i]->GetProcesador()->GetDatoAEscribir().at(1),  chipsDisponibles[i]->GetProcesador()->GetDireccionAUsar());
        }
        if (peticionDeProcesador == PETIPROCESAR)
        {
            printf("Procesador %d: procesar\n", chipsDisponibles[i]->GetId());
        }
    }
    printf("\nCache #0\t\t\t\t\tCache #1\t\t\t\t\tCache#2\t\t\t\t\t\tCache#3\n");
    printf("Add  Tag  Dato  S\t\t\t\tAdd  Tag  Dato  S\t\t\t\tAdd  Tag  Dato  S\t\t\t\tAdd  Tag  Dato  S\n");
    for (int i = 0; i<16; i++)
    {
        std::string * cache0 = Bus::getInstance()->GetCacheCollection().at(0);
        std::string * cache1 = Bus::getInstance()->GetCacheCollection().at(1);
        std::string * cache2 = Bus::getInstance()->GetCacheCollection().at(2);
        std::string * cache3 = Bus::getInstance()->GetCacheCollection().at(3);
        if (i<10)
        {
            printf("%d    %d    %d%d    %c\t\t\t\t%d    %d    %d%d    %c\t\t\t\t%d    %d    %d%d    %c\t\t\t\t%d    %d    %d%d    %c\n", i, std::stoi(cache0[i].substr(3)), cache0[i].at(0), cache0[i].at(1), cache0[i].at(2), i, std::stoi(cache1[i].substr(3)), cache1[i].at(0), cache1[i].at(1), cache1[i].at(2), i, std::stoi(cache2[i].substr(3)), cache2[i].at(0), cache2[i].at(1), cache2[i].at(2), i, std::stoi(cache3[i].substr(3)), cache3[i].at(0), cache3[i].at(1), cache3[i].at(2));
        }
        else
        {
            printf("%d   %d   %d%d    %c\t\t\t\t%d   %d   %d%d    %c\t\t\t\t%d   %d   %d%d    %c\t\t\t\t%d   %d   %d%d    %c\n", i, std::stoi(cache0[i].substr(3)), cache0[i].at(0), cache0[i].at(1), cache0[i].at(2), i, std::stoi(cache1[i].substr(3)), cache1[i].at(0), cache1[i].at(1), cache1[i].at(2), i, std::stoi(cache2[i].substr(3)), cache2[i].at(0), cache2[i].at(1), cache2[i].at(2), i, std::stoi(cache3[i].substr(3)), cache3[i].at(0), cache3[i].at(1), cache3[i].at(2));
        }
    }
    printf("\nMemoria\n");
    printf("Add  Dato\n");
    for (int i = 0; i<16; i++)
    {
        if (i<10)
            printf("%d    %d%d\n", i, Memoria::getInstance()->GetDatos()[i].at(0), Memoria::getInstance()->GetDatos()[i].at(1));
        else
            printf("%d   %d%d\n", i, Memoria::getInstance()->GetDatos()[i].at(0), Memoria::getInstance()->GetDatos()[i].at(1));
    }
    
    printf("Cola contencion:\n");
    for(int k = 0; k<BusBuffer::GetInstance()->procesorIdFIFO.size(); k++)
    {
        printf("| %d | ", BusBuffer::GetInstance()->procesorIdFIFO.at(k));
    }
    printf("\n");
}

int main(int argc, char** argv) {
    int NumeroCiclo = 0;
    for (int i = 0; i < NOPROCESSORS; i++)
    {
        chipsDisponibles[i] = new Chip(Bus::getInstance(), i);
        sem_init(&SemaphoreSingleton::getInstance()->semaforoGeneralPeticiones[i], 0, 0);
        pthread_create(&chipsDisponibles[i]->chipThread, NULL, Chip::Trabajar, chipsDisponibles[i]);
    }
    while (1)
    {
        NumeroCiclo++;
        printf("\nCiclo #%d\n", NumeroCiclo);
        BusBuffer::GetInstance()->sinUso = true;
        for (int i = 0; i < NOPROCESSORS; i++)
        {
            sem_post(&SemaphoreSingleton::getInstance()->semaforoGeneralPeticiones[i]);
        }
        usleep(100000);
        imprimirEstado();
        getch();
        //sleep(1);
    }
    
    void *status;
    for (int i = 0; i < NOPROCESSORS; i++)
    {
        pthread_join(chipsDisponibles[i]->chipThread, &status);
    }
    return 0;
}


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

#define NOPROCESSORS 4


using namespace std;
/*
 * 
 */

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

int main(int argc, char** argv) {
    Chip * chipsDisponibles[NOPROCESSORS];
//    Chip * newChip = new Chip(Bus::getInstance(), 1);
//    std::string asd1 = "";
//    asd1.push_back(0);
//    asd1.push_back(5);
//    BusBuffer::GetInstance()->procesorIdFIFO.push_back(2);
//    newChip->GetProcesador()->EscribirEnBloque(1, asd1);
//    printf("Cola contencion:\n");
//        for(int k = 0; k<BusBuffer::GetInstance()->procesorIdFIFO.size(); k++)
//        {
//            printf("\t| %d |\n", BusBuffer::GetInstance()->procesorIdFIFO.at(k));
//        }
    //newChip->GetProcesador()->GetCache()->EscribirBloque(1, asd1);
    for (int i = 0; i < NOPROCESSORS; i++)
    {
        chipsDisponibles[i] = new Chip(Bus::getInstance(), i);
        sem_init(&SemaphoreSingleton::getInstance()->semaforoGeneralPeticiones[i], 0, 0);
        pthread_create(&chipsDisponibles[i]->chipThread, NULL, Chip::Trabajar, chipsDisponibles[i]);
    }
    while (1)
    {
        printf("\nNuevo intento\n");
        BusBuffer::GetInstance()->sinUso = true;
        for (int i = 0; i < NOPROCESSORS; i++)
        {
            sem_post(&SemaphoreSingleton::getInstance()->semaforoGeneralPeticiones[i]);
        }
        usleep(250000);
        printf("Cola contencion:\n");
        for(int k = 0; k<BusBuffer::GetInstance()->procesorIdFIFO.size(); k++)
        {
            printf("\t| %d |\n", BusBuffer::GetInstance()->procesorIdFIFO.at(k));
        }
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


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Control.cpp
 * Author: pelo
 * 
 * Created on August 19, 2018, 11:55 AM
 */

#include "Control.h"

Control::Control() {
    bus = Bus::getInstance();
    esperandoBus = false;
}

Control::~Control() {
}

std::string Control::ObtenerDeMemoria(int direccion, int id)
{
    pthread_mutex_lock(&BusBuffer::GetInstance()->mutex);
    if (!esperandoBus)
    {
        BusBuffer::GetInstance()->procesorIdFIFO.push_back(id);
        esperandoBus = true;
    }
    pthread_mutex_unlock(&BusBuffer::GetInstance()->mutex);
    if (BusBuffer::GetInstance()->procesorIdFIFO.front() == id && BusBuffer::GetInstance()->sinUso)
    {
        esperandoBus = false;
        BusBuffer::GetInstance()->sinUso = false;
        BusBuffer::GetInstance()->procesorIdFIFO.erase(BusBuffer::GetInstance()->procesorIdFIFO.begin());
        return bus->obtenerDeMemoria(direccion, id);
    }
    else
    {
        return "invalido";
    }   
}

bool Control::EscribirEnMemoria(int direccion, std::string dato, int id)
{
    pthread_mutex_lock(&BusBuffer::GetInstance()->mutex);
    if (!esperandoBus)
    {
        BusBuffer::GetInstance()->procesorIdFIFO.push_back(id);
        esperandoBus = true;
    }
    pthread_mutex_unlock(&BusBuffer::GetInstance()->mutex);
    if (BusBuffer::GetInstance()->procesorIdFIFO.front() == id && BusBuffer::GetInstance()->sinUso)
    {
        esperandoBus = false;
        BusBuffer::GetInstance()->sinUso = false;
        BusBuffer::GetInstance()->procesorIdFIFO.erase(BusBuffer::GetInstance()->procesorIdFIFO.begin());
        bus->InvalidarDatoEnCaches(std::to_string(direccion));
        bus->EscribirEnMemoria(direccion, dato);
        return true;
    }
    else
    {
        return false;
    } 
}
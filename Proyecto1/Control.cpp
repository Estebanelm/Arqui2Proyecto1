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
}

Control::~Control() {
}

std::string Control::ObtenerDeMemoria(int direccion, int id)
{
    pthread_mutex_lock(&BusBuffer::GetInstance()->mutex);
    BusBuffer::GetInstance()->procesorIdFIFO.push_back(id);
    pthread_mutex_unlock(&BusBuffer::GetInstance()->mutex);
    int firstId = BusBuffer::GetInstance()->procesorIdFIFO.front();
    if (BusBuffer::GetInstance()->procesorIdFIFO.front() == id)
    {
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
    BusBuffer::GetInstance()->procesorIdFIFO.push_back(id);
    pthread_mutex_unlock(&BusBuffer::GetInstance()->mutex);
    int firstId = BusBuffer::GetInstance()->procesorIdFIFO.front();
    if (BusBuffer::GetInstance()->procesorIdFIFO.front() == id)
    {
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
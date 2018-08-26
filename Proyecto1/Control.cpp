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
    return bus->obtenerDeMemoria(direccion, id);
}

void Control::EscribirEnMemoria(int direccion, std::string dato)
{
    
}
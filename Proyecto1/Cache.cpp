/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cache.cpp
 * Author: pelo
 * 
 * Created on August 19, 2018, 11:50 AM
 */

#include "Cache.h"

Cache::Cache(Bus * busExistente) {
    bus = busExistente;
    for (int i = 0; i < 16; i++)
    {
        for (int k = 0; k < 2; k++)
        {
            datos[i][k] = 0;
        }
    }
}

Cache::~Cache() {
}


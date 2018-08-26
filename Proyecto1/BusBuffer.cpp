/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BusBuffer.cpp
 * Author: pelo
 * 
 * Created on August 25, 2018, 8:28 PM
 */

#include "BusBuffer.h"

BusBuffer* BusBuffer::instance = 0;

BusBuffer::BusBuffer() {
    mutex = PTHREAD_MUTEX_INITIALIZER;
}

BusBuffer::~BusBuffer() {
}

BusBuffer * BusBuffer::GetInstance()
{
    if (instance == 0)
    {
        instance = new BusBuffer();
    }
    return instance;
}


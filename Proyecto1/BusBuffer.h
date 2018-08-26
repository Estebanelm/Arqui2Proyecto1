/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BusBuffer.h
 * Author: pelo
 *
 * Created on August 25, 2018, 8:28 PM
 */

#ifndef BUSBUFFER_H
#define BUSBUFFER_H

#include <vector>
#include <pthread.h>

class BusBuffer {
public:
    virtual ~BusBuffer();
    static BusBuffer * GetInstance();
    std::vector<int> procesorIdFIFO;
    pthread_mutex_t mutex;
    bool sinUso;
private:
    BusBuffer();
    static BusBuffer * instance;
};

#endif /* BUSBUFFER_H */


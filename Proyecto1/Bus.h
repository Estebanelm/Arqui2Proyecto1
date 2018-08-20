/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Bus.h
 * Author: pelo
 *
 * Created on August 19, 2018, 11:55 AM
 */

#ifndef BUS_H
#define BUS_H

class Bus {
public:
    static Bus * getInstance();
private:
    static Bus * instance;
    Bus();
};

#endif /* BUS_H */


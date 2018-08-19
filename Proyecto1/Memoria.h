/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Memoria.h
 * Author: pelo
 *
 * Created on August 19, 2018, 11:55 AM
 */

#ifndef MEMORIA_H
#define MEMORIA_H

class Memoria {
public:
    static Memoria * getInstance();
private:
    Memoria();
    char datos[16][2];
    static Memoria * instance;
};

#endif /* MEMORIA_H */


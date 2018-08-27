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

#include <string>
#define NOBLOQUES 16
#define NOCOLUMNAS 3

class Memoria {
public:
    static Memoria * getInstance();
    std::string LeerDato(int direccion);
    void EscribirDato(int direccion, std::string dato);
    std::string * GetDatos();
private:
    Memoria();
    std::string datos[NOBLOQUES];
    static Memoria * instance;
};

#endif /* MEMORIA_H */


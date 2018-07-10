/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Engine.cpp
 * Author: LedoCool
 * 
 * Created on July 10, 2018, 9:25 PM
 */

#include "Engine.h"
#include <iostream>

Engine::Engine() {
}

Engine::Engine(const Engine& orig) {
}

Engine::~Engine() {
}

void Engine::simpleFunction() {
    std::cout << "Hello world!" << std::endl;
}


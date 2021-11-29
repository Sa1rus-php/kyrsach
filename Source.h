#pragma once
#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <string>

struct salary {
    char T[100];
    float RP, PR, FP, PT;

};

struct fileStruct {
    bool isEmpty;
    char fileName[10];
    int nOfLines;
};



void tableHeader();
int dataInput();
void dataOutput(short int);
int inputInFile(short int);
int readFile();
void editFile();
void setFileName();
void endLine(bool endL = 1);
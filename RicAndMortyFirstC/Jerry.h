//
// Created by ise on 11/26/22.
//
#include "Defs.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#ifndef MANAGEJERRIES_C_JERRY_H
#define MANAGEJERRIES_C_JERRY_H

typedef struct planet_s{
    char * name;
    double x,y,z;
}planets;

typedef struct origin_s{
    char* dimenesion;
}origin;

typedef struct PhysicalCharacteristics{
    char *name;
    double attributeValue;
}physical;

typedef struct createJerry{
    char * id;
    int attributeNum;
    int happinesslevel;
    struct planet_s* planet;
    struct origin_s* orig;
    struct PhysicalCharacteristics** p;
}jerry;
planets* initPlanet(char * name ,double x, double y, double z);
origin* initOrigin(char* d);
physical* initPhysicalCharacteristics(char * name, double value);
jerry* initJerry(char* id, int happiness ,char* o,planets *p );
bool checkPhysicalCharacteristics(jerry* j, char* name);
void addAttribute(jerry* j,char * p, double num );
status removeAttribute(jerry* j, char* name);
status printJerry(jerry* j);
status printPlanet(planets* p);
void deletePlanet(planets* p);
void deleteOrigin(origin* o);
void deletejerry(jerry* j);
#endif //MANAGEJERRIES_C_JERRY_H

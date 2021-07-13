#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>
#include <iostream>
#include "structures.h"
#define BUFFSIZE 1024
#define VALUE(n,m) n * m / 100
using namespace std;

void readCSV(const char* fileName, FoodCompositionTable* foodCompositionTable);
void readCSV2(const char* fileName, Recipe* recipe);
void writeCSV(const char* fileName, Recipe* recipe);
void calculator(FoodCompositionTable* foodCompositionTable, Recipe* recipe);
int myStrlen(const char* s);
char* myStrcpy(char* s1, const char* s2);
char* myStrcat(char* s1, const char* s2);
int myStrcmp(const char* s1, const char* s2);
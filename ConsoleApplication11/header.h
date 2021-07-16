#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>
#include <iostream>
#include <curses.h>
#include "structures.h"
#define BUFFSIZE 1024
using namespace std;//ïWèÄì¸èoóÕ

void readTable(const char* fileName, FoodCompositionTable* foodCompositionTable);//Func
void readRecipe(const char* fileName, Recipe* recipe);//Func
Standard readStandard(const char* fileName, int age, int sex);//Func
void writeValue(const char* fileName, Recipe* recipe);//Func
void calculator(FoodCompositionTable* foodCompositionTable, Recipe* recipe);//NutritionalValueCalculator
int myStrlen(const char* s);//myStr
char* myStrcpy(char* s1, const char* s2);//myStr
char* myStrcat(char* s1, const char* s2);//myStr
int myStrcmp(const char* s1, const char* s2);
void showGraph(Recipe* recipe, Standard* standard);//useCurses
void drawGraph(Recipe* recipe, Standard* standard);//useCurses

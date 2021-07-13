#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>
#include <iostream>
#include <curses.h>
#include "structures.h"
#define BUFFSIZE 1024
#define VALUE(n,m) n * m / 100
#define INDEX(n,m) 2 * n + 1 + m
#define SCALE(m,n) (int)(m * 24 / ((double)n * 8))
#define HEIGHT 30//画面の高さ（行数）
#define WIDTH 120//画面の幅（列数）
using namespace std;

void readCSV1(const char* fileName, FoodCompositionTable* foodCompositionTable);
void readCSV2(const char* fileName, Recipe* recipe);
void readCSV3(const char* fileName, Standard* standerd, int age, int sex);
void writeCSV(const char* fileName, Recipe* recipe);
void calculator(FoodCompositionTable* foodCompositionTable, Recipe* recipe);
int myStrlen(const char* s);
char* myStrcpy(char* s1, const char* s2);
char* myStrcat(char* s1, const char* s2);
int myStrcmp(const char* s1, const char* s2);
void showGraph(Recipe* recipe, Standard* standerd);
void drawGraph(Recipe* recipe, Standard* standerd);

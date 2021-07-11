#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>
#include <iostream>
#define BUFFSIZE 1024
using namespace std;
#define VALUE(n,m) n * m / 100

struct FoodComposition {
	int index;
	char food[BUFFSIZE];
	double energy;
	double protein;
	double lipid;
	double carbohydrate;
	double salt;
	FoodComposition* nextFoodComposition;
};

struct FoodCompositionTable {
	FoodComposition* firstFoodComposition;
};

struct Ingredient {
	int index;
	char food[BUFFSIZE];
	double amount;
	double i_energy;
	double i_protein;
	double i_lipid;
	double i_carbohydrate;
	double i_salt;
	Ingredient* nextIngredient;
};

struct Recipe {
	double energy;
	double protein;
	double lipid;
	double carbohydrate;
	double salt;
	Ingredient* firstIngredient;
};

void readCSV(const char* fileName, FoodCompositionTable* foodCompositionTable);
void readCSV2(const char* fileName, Recipe* recipe);
void writeCSV(const char* fileName, Recipe* recipe);
void calculator(FoodCompositionTable* foodCompositionTable, Recipe* recipe);
int myStrlen(const char* s);
char* myStrcpy(char* s1, const char* s2);
char* myStrcat(char* s1, const char* s2);
int myStrcmp(const char* s1, const char* s2);
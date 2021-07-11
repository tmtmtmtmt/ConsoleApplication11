#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>
#include <iostream>
#define BUFFSIZE 1024
using namespace std;
#define ll long long
#define PI acos(-1)
#define rep(i, n) for (int i = 0; i < (n); i++)

struct FoodComposition {
	int index;
	char foodDescription[BUFFSIZE];
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
	char foodDescription[BUFFSIZE];
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
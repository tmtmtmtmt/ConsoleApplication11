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
	FoodComposition firstFoodComposition;
};

struct Ingredient {
	int index;
	char foodDescription[BUFFSIZE];
	double amount;
	Ingredient* nextIngredient;
};

struct Recipe {
	Ingredient* firstIngredient;
};
#pragma once
#define BUFFSIZE 1024

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

struct Standard {
	double standard_energy;
	double standard_protein;
	double standard_lipid;
	double standard_carbohydrate;
	double standard_salt;
};
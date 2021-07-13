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

struct Standerd {
	double standerd_energy;
	double standerd_protein;
	double standerd_lipid;
	double standerd_carbohydrate;
	double standerd_salt;
};
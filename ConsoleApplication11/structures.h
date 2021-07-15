#pragma once
#define BUFFSIZE 1024

struct FoodComposition {//食品成分
	int index;//索引番号
	char food[BUFFSIZE];//食品名
	double energy;//エネルギー
	double protein;//たんぱく質
	double lipid;//脂質
	double carbohydrate;//炭水化物
	double salt;//食塩相当量
	FoodComposition* nextFoodComposition;
};

struct FoodCompositionTable {//食品成分表
	FoodComposition* firstFoodComposition;
};

struct Ingredient {//材料
	int index;//番号
	char food[BUFFSIZE];//
	double amount;//分量重量
	double ingredientEnergy;//エネルギー
	double ingredientProtein;//たんぱく質
	double ingredientLipid;//脂質
	double ingredientCarbohydrate;//炭水化物
	double ingredientSalt;//食塩相当量
	Ingredient* nextIngredient;
};

struct Recipe {//レシピ　材料表
	double totalEnergy;//合計のエネルギー量
	double totalProtein;//合計のたんぱく質量
	double totalLipid;//合計の脂質量
	double totalCarbohydrate;//合計の炭水化物量
	double totalSalt;//合計の食塩相当量
	Ingredient* firstIngredient;
};

struct Standard {//摂取基準
	double standardEnergy;//推定エネルギー必要量
	double standardProtein;//たんぱく質推奨量
	double standardLipid;//脂質推奨量
	double standardCarbohydrate;//他水化物推奨量
	double standardSalt;//食塩相当量目標値
};
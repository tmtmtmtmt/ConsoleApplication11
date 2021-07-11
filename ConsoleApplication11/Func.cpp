#include "header.h"

void readCSV(const char* fileName, FoodCompositionTable* foodCompositionTable) {
	FILE* fp;
	char s[BUFFSIZE];
	char delim[] = ", ";//デリミタ（複数渡せる）ここではカンマと空白
	char* p[7];
	char* np = NULL;
	FoodComposition* previousFoodComposition = NULL;
	FoodComposition* currentFoodComposition = new FoodComposition();
	foodCompositionTable->firstFoodComposition = currentFoodComposition;

	errno_t error;
	error = fopen_s(&fp, fileName, "r");
	if (error != 0)
		fprintf_s(stderr, "failed to open");
	else {
		fgets(s, BUFFSIZE, fp);//１行目を飛ばす
		while (fgets(s, BUFFSIZE, fp) != NULL) {
			p[0] = strtok_s(s, delim, &np); // １個目の部分文字列取得
			for (int i = 1; i < 7; i++)
				p[i] = strtok_s(NULL, delim, &np); // ２個目以降の部分文字列取得

			currentFoodComposition->index = atoi(p[0]);
			myStrcpy(currentFoodComposition->food, p[1]);
			currentFoodComposition->energy = atof(p[2]);
			currentFoodComposition->protein = atof(p[3]);
			currentFoodComposition->lipid = atof(p[4]);
			currentFoodComposition->carbohydrate = atof(p[5]);
			currentFoodComposition->salt = atof(p[6]);

			if (previousFoodComposition != NULL)
				previousFoodComposition->nextFoodComposition = currentFoodComposition;
			previousFoodComposition = currentFoodComposition;
			currentFoodComposition = new FoodComposition();
		}
		fclose(fp);
	}
}

void readCSV2(const char* fileName, Recipe* recipe) {
	FILE* fp;
	char s[BUFFSIZE];
	char delim[] = ", ";//デリミタ（複数渡せる）ここではカンマと空白
	char* p[3];
	char* np = NULL;
	Ingredient* previousIngredient = NULL;
	Ingredient* currentIngredient = new Ingredient();
	recipe->firstIngredient = currentIngredient;

	errno_t error;
	error = fopen_s(&fp, fileName, "r");
	if (error != 0)
		fprintf_s(stderr, "failed to open");
	else {
		fgets(s, BUFFSIZE, fp);//１行目を飛ばす
		while (fgets(s, BUFFSIZE, fp) != NULL) {
			p[0] = strtok_s(s, delim, &np); // １個目の部分文字列取得
			for (int i = 1; i < 3; i++)
				p[i] = strtok_s(NULL, delim, &np); // ２個目以降の部分文字列取得

			currentIngredient->index = atoi(p[0]);
			myStrcpy(currentIngredient->food, p[1]);
			currentIngredient->amount = atof(p[2]);

			if (previousIngredient != NULL)
				previousIngredient->nextIngredient = currentIngredient;
			previousIngredient = currentIngredient;
			currentIngredient = new Ingredient();
		}
		fclose(fp);
	}
}

void calculator(FoodCompositionTable* foodCompositionTable, Recipe* recipe) {
	FoodComposition* foodComposition = foodCompositionTable->firstFoodComposition;
	Ingredient* ingredient = recipe->firstIngredient;

	while (ingredient != NULL) {
		while (foodComposition != NULL) {
			if (!(myStrcmp(ingredient->food, foodComposition->food))) {
				ingredient->i_energy = VALUE(ingredient->amount, foodComposition->energy);
				ingredient->i_protein = VALUE(ingredient->amount, foodComposition->protein);
				ingredient->i_lipid = VALUE(ingredient->amount, foodComposition->lipid);
				ingredient->i_carbohydrate = VALUE(ingredient->amount, foodComposition->carbohydrate);
				ingredient->i_salt = VALUE(ingredient->amount, foodComposition->salt);

				recipe->energy += ingredient->i_energy;
				recipe->protein += ingredient->i_protein;
				recipe->lipid += ingredient->i_lipid;
				recipe->carbohydrate += ingredient->i_carbohydrate;
				recipe->salt += ingredient->i_salt;

				break;
			}
			foodComposition = foodComposition->nextFoodComposition;//
		}
		ingredient = ingredient->nextIngredient;//
	}
}

void writeCSV(const char* fileName, Recipe* recipe) {
	Ingredient* ingredient = recipe->firstIngredient;

	FILE* fp;
	errno_t error;
	error = fopen_s(&fp, fileName, "w");
	if (error != 0)
		fprintf_s(stderr, "failed to open");
	else {
		fprintf_s(fp, "材料番号,食品名,分量（g）,エネルギー（kcal）,タンパク質,脂質,炭水化物,食塩相当量\n");
		while (ingredient != NULL) {
			fprintf_s(fp, "%d,%s,%f,%f,%f,%f,%f,%f\n", ingredient->index,
				ingredient->food, ingredient->amount,
				ingredient->i_energy, ingredient->i_protein, ingredient->i_lipid,
				ingredient->i_carbohydrate, ingredient->i_salt);//データの書き込み
			ingredient = ingredient->nextIngredient;//次の月へ
		}
		fprintf_s(fp, "合計,,,%f,%f,%f,%f,%f\n", recipe->energy, recipe->protein,
			recipe->lipid, recipe->carbohydrate, recipe->salt);
		fclose(fp);
	}
}
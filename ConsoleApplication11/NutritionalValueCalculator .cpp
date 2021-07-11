#include "header.h"

void calculator(FoodCompositionTable* foodCompositionTable, Recipe* recipe) {//
	FoodComposition* foodComposition = foodCompositionTable->firstFoodComposition;
	Ingredient* ingredient = recipe->firstIngredient;

	while (ingredient != NULL) {
		while (foodComposition != NULL) {
			if (!(myStrcmp(ingredient->food, foodComposition->food))) {//myStr　文字列が一致していたらif文内を実行
				ingredient->i_energy = VALUE(ingredient->amount, foodComposition->energy);//項目ごとに計算
				ingredient->i_protein = VALUE(ingredient->amount, foodComposition->protein);
				ingredient->i_lipid = VALUE(ingredient->amount, foodComposition->lipid);
				ingredient->i_carbohydrate = VALUE(ingredient->amount, foodComposition->carbohydrate);
				ingredient->i_salt = VALUE(ingredient->amount, foodComposition->salt);

				recipe->energy += ingredient->i_energy;//合計していく
				recipe->protein += ingredient->i_protein;
				recipe->lipid += ingredient->i_lipid;
				recipe->carbohydrate += ingredient->i_carbohydrate;
				recipe->salt += ingredient->i_salt;

				break;
			}
			foodComposition = foodComposition->nextFoodComposition;//次の食品へ
		}
		ingredient = ingredient->nextIngredient;//次の材料へ
	}
}

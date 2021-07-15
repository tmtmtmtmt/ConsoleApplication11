#include "header.h"
#define VALUE(n,m) n * m / 100

void calculator(FoodCompositionTable* foodCompositionTable, Recipe* recipe) {//
	FoodComposition* foodComposition = foodCompositionTable->firstFoodComposition;
	Ingredient* ingredient = recipe->firstIngredient;

	while (ingredient != NULL) {
		while (foodComposition != NULL) {
			if (!(myStrcmp(ingredient->food, foodComposition->food))) {//myStr　文字列が一致していたらif文内を実行
				ingredient->ingredientEnergy = VALUE(ingredient->amount, foodComposition->energy);//項目ごとに計算
				ingredient->ingredientProtein = VALUE(ingredient->amount, foodComposition->protein);//プリプロセッサ
				ingredient->ingredientLipid = VALUE(ingredient->amount, foodComposition->lipid);
				ingredient->ingredientCarbohydrate = VALUE(ingredient->amount, foodComposition->carbohydrate);
				ingredient->ingredientSalt = VALUE(ingredient->amount, foodComposition->salt);

				recipe->totalEnergy += ingredient->ingredientEnergy;//合計していく
				recipe->totalProtein += ingredient->ingredientProtein;
				recipe->totalLipid += ingredient->ingredientLipid;
				recipe->totalCarbohydrate += ingredient->ingredientCarbohydrate;
				recipe->totalSalt += ingredient->ingredientSalt;

				break;
			}
			foodComposition = foodComposition->nextFoodComposition;//成分表の次の食品へ
		}
		ingredient = ingredient->nextIngredient;//レシピの次の材料へ
	}
}

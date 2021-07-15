#include "header.h"

void readTable(const char* fileName, FoodCompositionTable* foodCompositionTable) {//�t�@�C���̓ǂݍ���
	FILE* fp;
	char s[BUFFSIZE];
	char delim[] = ", ";//�f���~�^�i�����n����j�����ł̓J���}�Ƌ�
	char* p[7];
	char* np = NULL;
	FoodComposition* previousFoodComposition = NULL;//�\���̂̃|�C���^
	FoodComposition* currentFoodComposition = new FoodComposition();
	foodCompositionTable->firstFoodComposition = currentFoodComposition;

	errno_t error;
	error = fopen_s(&fp, fileName, "r");
	if (error != 0)
		fprintf_s(stderr, "failed to open %s", fileName);
	else {
		fgets(s, BUFFSIZE, fp);//�P�s�ڂ��΂�
		while (fgets(s, BUFFSIZE, fp) != NULL) {
			p[0] = strtok_s(s, delim, &np); // �P�ڂ̕���������擾
			for (int i = 1; i < 7; i++)
				p[i] = strtok_s(NULL, delim, &np); // �Q�ڈȍ~�̕���������擾

			currentFoodComposition->index = atoi(p[0]);
			myStrcpy(currentFoodComposition->food, p[1]);//myStr
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

void readRecipe(const char* fileName, Recipe* recipe) {//�t�@�C���̓ǂݍ���
	FILE* fp;
	char s[BUFFSIZE];
	char delim[] = ", ";//�f���~�^�i�����n����j�����ł̓J���}�Ƌ�
	char* p[3];
	char* np = NULL;
	Ingredient* previousIngredient = NULL;
	Ingredient* currentIngredient = new Ingredient();
	recipe->firstIngredient = currentIngredient;

	errno_t error;
	error = fopen_s(&fp, fileName, "r");
	if (error != 0)
		fprintf_s(stderr, "failed to open %s", fileName);
	else {
		fgets(s, BUFFSIZE, fp);//�P�s�ڂ��΂�
		while (fgets(s, BUFFSIZE, fp) != NULL) {
			p[0] = strtok_s(s, delim, &np); // �P�ڂ̕���������擾
			for (int i = 1; i < 3; i++)
				p[i] = strtok_s(NULL, delim, &np); // �Q�ڈȍ~�̕���������擾

			currentIngredient->index = atoi(p[0]);
			myStrcpy(currentIngredient->food, p[1]);//myStr
			currentIngredient->amount = atof(p[2]);

			if (previousIngredient != NULL)
				previousIngredient->nextIngredient = currentIngredient;//��O��
			previousIngredient = currentIngredient;
			currentIngredient = new Ingredient();
		}
		fclose(fp);
	}
}

Standard readStandard(const char* fileName, int age, int sex) {//�t�@�C���̓ǂݍ���
	FILE* fp;
	char s[BUFFSIZE];
	char delim[] = ", ";//�f���~�^�i�����n����j�����ł̓J���}�Ƌ�
	char* p[11];
	char* np = NULL;
	Standard tmp = { 0 };

	errno_t error;
	error = fopen_s(&fp, fileName, "r");
	if (error != 0)
		fprintf_s(stderr, "failed to open %s", fileName);
	else {
		fgets(s, BUFFSIZE, fp);//�P�s�ڂ��΂�
		while (fgets(s, BUFFSIZE, fp) != NULL) {
			p[0] = strtok_s(s, delim, &np); // �P�ڂ̕���������擾
			for (int i = 1; i < 11; i++)
				p[i] = strtok_s(NULL, delim, &np); // �Q�ڈȍ~�̕���������擾

			if (atof(p[0]) > age)
				break;
			if (sex)
				tmp = { atof(p[2]),atof(p[4]),atof(p[6]),atof(p[8]),atof(p[10]) };
			else
				tmp = { atof(p[1]),atof(p[3]),atof(p[5]),atof(p[7]),atof(p[9]) };
		}
		fclose(fp);
	}
	return tmp;
}

void writeValue(const char* fileName, Recipe* recipe) {//�t�@�C���̏�������
	Ingredient* ingredient = recipe->firstIngredient;

	FILE* fp;
	errno_t error;
	error = fopen_s(&fp, fileName, "w");
	if (error != 0)
		fprintf_s(stderr, "failed to open %s", fileName);
	else {
		fprintf_s(fp, "�ޗ��ԍ�,�H�i��,���ʁig�j,�G�l���M�[�ikcal�j,�^���p�N��,����,�Y������,�H��������\n");
		while (ingredient != NULL) {
			fprintf_s(fp, "%d,%s,%f,%f,%f,%f,%f,%f\n", ingredient->index,
				ingredient->food, ingredient->amount,
				ingredient->ingredientEnergy, ingredient->ingredientProtein, ingredient->ingredientLipid,
				ingredient->ingredientCarbohydrate, ingredient->ingredientSalt);//�f�[�^�̏�������
			ingredient = ingredient->nextIngredient;//���̍ޗ���
		}
		fprintf_s(fp, "���v,,,%f,%f,%f,%f,%f\n", recipe->totalEnergy, recipe->totalProtein,
			recipe->totalLipid, recipe->totalCarbohydrate, recipe->totalSalt);//�f�[�^�̏�������
		fclose(fp);
	}
}
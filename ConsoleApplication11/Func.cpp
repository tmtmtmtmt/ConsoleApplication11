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
			strcpy_s(currentFoodComposition->foodDescription, p[1]);
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
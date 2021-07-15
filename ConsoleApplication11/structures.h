#pragma once
#define BUFFSIZE 1024

struct FoodComposition {//�H�i����
	int index;//�����ԍ�
	char food[BUFFSIZE];//�H�i��
	double energy;//�G�l���M�[
	double protein;//����ς���
	double lipid;//����
	double carbohydrate;//�Y������
	double salt;//�H��������
	FoodComposition* nextFoodComposition;
};

struct FoodCompositionTable {//�H�i�����\
	FoodComposition* firstFoodComposition;
};

struct Ingredient {//�ޗ�
	int index;//�ԍ�
	char food[BUFFSIZE];//
	double amount;//���ʏd��
	double ingredientEnergy;//�G�l���M�[
	double ingredientProtein;//����ς���
	double ingredientLipid;//����
	double ingredientCarbohydrate;//�Y������
	double ingredientSalt;//�H��������
	Ingredient* nextIngredient;
};

struct Recipe {//���V�s�@�ޗ��\
	double totalEnergy;//���v�̃G�l���M�[��
	double totalProtein;//���v�̂���ς�����
	double totalLipid;//���v�̎�����
	double totalCarbohydrate;//���v�̒Y��������
	double totalSalt;//���v�̐H��������
	Ingredient* firstIngredient;
};

struct Standard {//�ێ�
	double standardEnergy;//����G�l���M�[�K�v��
	double standardProtein;//����ς���������
	double standardLipid;//����������
	double standardCarbohydrate;//��������������
	double standardSalt;//�H�������ʖڕW�l
};
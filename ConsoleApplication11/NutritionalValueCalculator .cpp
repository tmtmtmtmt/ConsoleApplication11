#include "header.h"

int main(){
	char currentDirectory[BUFFSIZE];//現在のディレクトリの位置
	char section[BUFFSIZE];//
	char keyWord[BUFFSIZE];//iniファイルの名前が代入されている変数名
	char keyValue[BUFFSIZE];//取り出したファイル名
	char filePath[BUFFSIZE];//iniファイルのパス

	GetCurrentDirectory(BUFFSIZE, currentDirectory);
	sprintf_s(section, "section1");//変数に文字列を代入
	sprintf_s(keyWord, "keyword1");
	sprintf_s(filePath, "%s\\ConsoleApplication11.ini", currentDirectory);

	if (GetPrivateProfileString(section, keyWord, "\0", keyValue, BUFFSIZE, filePath) == 0) {//iniファイルからデータをとってくる 文字数が返り値
		fprintf_s(stdout, "%s doesn't contain [%s] %s\n", filePath, section, keyWord);//エラー表示
		return 0;//終了
	}

	FoodCompositionTable foodCompositionTable;
	readCSV(keyValue, &foodCompositionTable);

	sprintf_s(keyWord, "keyword2");
	if (GetPrivateProfileString(section, keyWord, "\0", keyValue, BUFFSIZE, filePath) == 0) {//iniファイルからデータをとってくる 文字数が返り値
		fprintf_s(stdout, "%s doesn't contain [%s] %s\n", filePath, section, keyWord);//エラー表示
		return 0;//終了
	}

	Recipe recipe = { 0 };// 途中まで指定しないとき残りはゼロになる
	readCSV2(keyValue, &recipe);

	calculator(&foodCompositionTable, &recipe);

	sprintf_s(keyWord, "keyword3");
	if (GetPrivateProfileString(section, keyWord, "\0", keyValue, BUFFSIZE, filePath) == 0) {//iniファイルからデータをとってくる 文字数が返り値
		fprintf_s(stdout, "%s doesn't contain [%s] %s\n", filePath, section, keyWord);//エラー表示
		return 0;//終了
	}

	writeCSV(keyValue, &recipe);

	return 0;
}
//aiueo
#include "header.h"

int main() {
	char currentDirectory[BUFFSIZE];//現在のディレクトリの位置
	char section[BUFFSIZE];//iniファイルのセクション名
	char keyWord[BUFFSIZE];//iniファイルのパラメータ名
	char keyValue[BUFFSIZE];//取り出したファイル名
	char filePath[BUFFSIZE];//iniファイルのパス

	GetCurrentDirectory(BUFFSIZE, currentDirectory);//パスとってくる
	sprintf_s(section, "section1");//変数に文字列を代入
	sprintf_s(keyWord, "keyword1");
	sprintf_s(filePath, "%s\\IOFileName.ini", currentDirectory);

	if (GetPrivateProfileString(section, keyWord, "\0", keyValue, BUFFSIZE, filePath) == 0) {//iniファイルからデータをとってくる 文字数が返り値
		fprintf_s(stdout, "%s doesn't contain [%s] %s\n", filePath, section, keyWord);//エラー表示
		return 0;//終了
	}

	FoodCompositionTable foodCompositionTable;//構造体宣言
	readTable(keyValue, &foodCompositionTable);

	sprintf_s(keyWord, "keyword2");
	if (GetPrivateProfileString(section, keyWord, "\0", keyValue, BUFFSIZE, filePath) == 0) {//iniファイルからデータをとってくる 文字数が返り値
		fprintf_s(stdout, "%s doesn't contain [%s] %s\n", filePath, section, keyWord);//エラー表示
		return 0;//終了
	}

	Recipe recipe = { 0 };// 途中まで指定しないとき残りはゼロになる
	readRecipe(keyValue, &recipe);

	calculator(&foodCompositionTable, &recipe);//

	sprintf_s(keyWord, "keyword3");
	if (GetPrivateProfileString(section, keyWord, "\0", keyValue, BUFFSIZE, filePath) == 0) {//iniファイルからデータをとってくる 文字数が返り値
		fprintf_s(stdout, "%s doesn't contain [%s] %s\n", filePath, section, keyWord);//エラー表示
		return 0;//終了
	}

	writeValue(keyValue, &recipe);

	sprintf_s(keyWord, "keyword4");
	if (GetPrivateProfileString(section, keyWord, "\0", keyValue, BUFFSIZE, filePath) == 0) {//iniファイルからデータをとってくる 文字数が返り値
		fprintf_s(stdout, "%s doesn't contain [%s] %s\n", filePath, section, keyWord);//エラー表示
		return 0;//終了
	}

	int age, sex;
	cout << "歳はいくつですか。数字のみ" << endl;
	cin >> age;
	cout << "性別を教えてください。男性:0 女性:1" << endl;//male:0 female:1
	cin >> sex;

	Standard standard = readStandard(keyValue, age, sex);

	// 初期化
	if (initscr() == NULL) {
		return 1;
	}

	showGraph(&recipe, &standard);

	return 0;
}
//aiueo
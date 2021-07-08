﻿#include "header.h"

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

	if (GetPrivateProfileString(section, keyWord, "none", keyValue, BUFFSIZE, filePath) == 0) {//iniファイルからデータをとってくる
		fprintf_s(stdout, "%s doesn't contain [%s] %s\n", filePath, section, keyWord);//エラー表示
		return 0;//終了
	}



	return 0;
}
//aiueo
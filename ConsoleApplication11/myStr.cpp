#include "header.h"

int myStrlen(const char* s) {//文字数を返す
	int cnt = 0;
	while (*(s + cnt) != '\0')
		cnt++;
	return cnt;
}

char* myStrcpy(char* s1, const char* s2) {//s1にs2の文字列を代入する
	for (int i = 0; i < myStrlen(s2); i++)
		*(s1 + i) = *(s2 + i);
	*(s1 + myStrlen(s2)) = '\0';
	return s1;
}

char* myStrcat(char* s1, const char* s2) {//s1の後ろにs2をくっつける
	int len_s1 = myStrlen(s1);
	for (int i = 0; i < myStrlen(s2); i++)
		*(s1 + len_s1 + i) = *(s2 + i);
	*(s1 + len_s1 + myStrlen(s2)) = '\0';
	return s1;
}

int myStrcmp(const char* s1, const char* s2) {//文字列を辞書的に比べる　
	//同じ ゼロ
	//s1が大きい 正
	//s2が大きい 負
	for (int i = 0; i < (signed)max(strlen(s1), strlen(s2)); i++) {
		if (*(s1 + i) > *(s2 + i))
			return 1;
		if (*(s1 + i) < *(s2 + i))
			return -1;
	}
	return 0;
}

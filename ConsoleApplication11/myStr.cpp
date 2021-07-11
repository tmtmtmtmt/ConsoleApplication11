#include "header.h"

int myStrlen(const char* s) {//•¶š”‚ğ•Ô‚·
	int cnt = 0;
	while (*(s + cnt) != '\0')
		cnt++;
	return cnt;
}

char* myStrcpy(char* s1, const char* s2) {//s1‚És2‚Ì•¶š—ñ‚ğ‘ã“ü‚·‚é
	for (int i = 0; i < myStrlen(s2); i++)
		*(s1 + i) = *(s2 + i);
	*(s1 + myStrlen(s2)) = '\0';
	return s1;
}

char* myStrcat(char* s1, const char* s2) {//s1‚ÌŒã‚ë‚És2‚ğ‚­‚Á‚Â‚¯‚é
	int len_s1 = myStrlen(s1);
	for (int i = 0; i < myStrlen(s2); i++)
		*(s1 + len_s1 + i) = *(s2 + i);
	*(s1 + len_s1 + myStrlen(s2)) = '\0';
	return s1;
}

int myStrcmp(const char* s1, const char* s2) {//•¶š—ñ‚ğ«‘“I‚É”ä‚×‚é@
	//“¯‚¶ ƒ[ƒ
	//s1‚ª‘å‚«‚¢ ³
	//s2‚ª‘å‚«‚¢ •‰
	for (int i = 0; i < (signed)max(strlen(s1), strlen(s2)); i++) {
		if (*(s1 + i) > *(s2 + i))
			return 1;
		if (*(s1 + i) < *(s2 + i))
			return -1;
	}
	return 0;
}

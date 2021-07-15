#include "header.h"

int main() {
	char currentDirectory[BUFFSIZE];//���݂̃f�B���N�g���̈ʒu
	char section[BUFFSIZE];//ini�t�@�C���̃Z�N�V������
	char keyWord[BUFFSIZE];//ini�t�@�C���̃p�����[�^��
	char keyValue[BUFFSIZE];//���o�����t�@�C����
	char filePath[BUFFSIZE];//ini�t�@�C���̃p�X

	GetCurrentDirectory(BUFFSIZE, currentDirectory);//�p�X�Ƃ��Ă���
	sprintf_s(section, "section1");//�ϐ��ɕ��������
	sprintf_s(keyWord, "keyword1");
	sprintf_s(filePath, "%s\\IOFileName.ini", currentDirectory);

	if (GetPrivateProfileString(section, keyWord, "\0", keyValue, BUFFSIZE, filePath) == 0) {//ini�t�@�C������f�[�^���Ƃ��Ă��� ���������Ԃ�l
		fprintf_s(stdout, "%s doesn't contain [%s] %s\n", filePath, section, keyWord);//�G���[�\��
		return 0;//�I��
	}

	FoodCompositionTable foodCompositionTable;//�\���̐錾
	readTable(keyValue, &foodCompositionTable);

	sprintf_s(keyWord, "keyword2");
	if (GetPrivateProfileString(section, keyWord, "\0", keyValue, BUFFSIZE, filePath) == 0) {//ini�t�@�C������f�[�^���Ƃ��Ă��� ���������Ԃ�l
		fprintf_s(stdout, "%s doesn't contain [%s] %s\n", filePath, section, keyWord);//�G���[�\��
		return 0;//�I��
	}

	Recipe recipe = { 0 };// �r���܂Ŏw�肵�Ȃ��Ƃ��c��̓[���ɂȂ�
	readRecipe(keyValue, &recipe);

	calculator(&foodCompositionTable, &recipe);//

	sprintf_s(keyWord, "keyword3");
	if (GetPrivateProfileString(section, keyWord, "\0", keyValue, BUFFSIZE, filePath) == 0) {//ini�t�@�C������f�[�^���Ƃ��Ă��� ���������Ԃ�l
		fprintf_s(stdout, "%s doesn't contain [%s] %s\n", filePath, section, keyWord);//�G���[�\��
		return 0;//�I��
	}

	writeValue(keyValue, &recipe);

	sprintf_s(keyWord, "keyword4");
	if (GetPrivateProfileString(section, keyWord, "\0", keyValue, BUFFSIZE, filePath) == 0) {//ini�t�@�C������f�[�^���Ƃ��Ă��� ���������Ԃ�l
		fprintf_s(stdout, "%s doesn't contain [%s] %s\n", filePath, section, keyWord);//�G���[�\��
		return 0;//�I��
	}

	int age, sex;
	cout << "�΂͂����ł����B�����̂�" << endl;
	cin >> age;
	cout << "���ʂ������Ă��������B�j��:0 ����:1" << endl;//male:0 female:1
	cin >> sex;

	Standard standard = readStandard(keyValue, age, sex);

	// ������
	if (initscr() == NULL) {
		return 1;
	}

	showGraph(&recipe, &standard);

	return 0;
}
//aiueo
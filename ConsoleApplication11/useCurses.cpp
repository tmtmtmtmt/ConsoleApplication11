#include "header.h"
#define SCALE(m,n) (int)(m * 24 / ((double)n * 8))

void drawGraph(Recipe* recipe, Standard* standard) {
	int a, b, scaleSize, t, s;
	int scale = 0;

	for (int i = 0; i < 5; i++) {
		switch (i) {
		case 0:
			scaleSize = 400;
			t = SCALE(recipe->totalEnergy, scaleSize);//�ړx���قȂ�̂ŕϊ�//�v���v���Z�b�T
			s = SCALE(standard->standardEnergy, scaleSize);//�ړx���قȂ�̂ŕϊ�//
			break;
		case 1:
			scaleSize = 10;
			t = SCALE(recipe->totalProtein, scaleSize);//�ړx���قȂ�̂ŕϊ�//
			s = SCALE(standard->standardProtein, scaleSize);//�ړx���قȂ�̂ŕϊ�//
			break;
		case 2:
			scaleSize = 10;
			t = SCALE(recipe->totalLipid, scaleSize);//�ړx���قȂ�̂ŕϊ�//
			s = SCALE(standard->standardLipid, scaleSize);//�ړx���قȂ�̂ŕϊ�//
			break;
		case 3:
			scaleSize = 50;
			t = SCALE(recipe->totalCarbohydrate, scaleSize);//�ړx���قȂ�̂ŕϊ�//
			s = SCALE(standard->standardCarbohydrate, scaleSize);//�ړx���قȂ�̂ŕϊ�//
			break;
		case 4:
			scaleSize = 1;
			t = SCALE(recipe->totalSalt, scaleSize);//�ړx���قȂ�̂ŕϊ�//
			s = SCALE(standard->standardSalt, scaleSize);//�ړx���قȂ�̂ŕϊ�//
			break;
		}

		scale = 0;
		attrset(COLOR_PAIR(1));//�F�P���g��
		for (a = HEIGHT - 5, b = 5 + 23 * i; b < 20 + 23 * i; b++)
			mvprintw(a, b, "_");//x��������
		for (a = HEIGHT - 5, b = 5 + 23 * i; a >= 0; a--) {
			mvprintw(a, b, "|");//y��������
			if ((a - 1) % 3 == 0) {
				mvprintw(a, b - 4, "%d", scale);//�ڐ���̒l
				scale += scaleSize;//
			}
		}
		mvprintw(a = 0, b = 1, "energy(kcal)");
		mvprintw(a, b += 23, "protein(g)");
		mvprintw(a, b += 23, "lipid(g)");
		mvprintw(a, b += 23, "carbohydrate(g)");
		mvprintw(a, b += 23, "salt(g)");

		a = HEIGHT - 5;
		b = 10 + 23 * i;
		attrset(COLOR_PAIR(2));//�F�Q���g��
		for (int j = t; j >= 0; j--)
			mvaddstr(a--, b, "   ");//�o�͂����Ƃ��͔����Ȃ�

		a = HEIGHT - 5;
		b += 3;
		attrset(COLOR_PAIR(3));//�F�R���g��
		for (int k = s; k >= 0; k--)
			mvaddstr(a--, b, "   ");//�o�͂����Ƃ��͉��F���Ȃ�
	}
	refresh();//��ʂ��X�V
}

void showGraph(Recipe* recipe, Standard* standard) {
	start_color();//�J���[�̐ݒ�
	init_pair(1, COLOR_WHITE, COLOR_BLACK);//�F�P�͍��n�ɔ�����
	init_pair(2, COLOR_WHITE, COLOR_WHITE);//�F�Q�͔��n�ɔ�����
	init_pair(3, COLOR_YELLOW, COLOR_YELLOW);//�F�R�͉��n�ɉ�����
	bkgd(COLOR_PAIR(1));//�w�i�͐F�P

	noecho();//�L�[���͂��������̔�\�����[�h
	curs_set(0); //�J�[�\���̔�\�����[�h
	int key;//getch()�̖߂�l��������ϐ�
	int h, w;//�ォ��h�s�ځ@������w���
	attrset(COLOR_PAIR(1));//�F�P���g��
	mvprintw(h = HEIGHT - 1, w = 4, "q:�I��");//����̕⏕����
	mvprintw(h, w += 47, ":���Ȃ�    :�");
	attrset(COLOR_PAIR(2));//�F�Q���g��
	mvprintw(h, w -= 2, "  ");
	attrset(COLOR_PAIR(3));//�F�R���g��
	mvprintw(h, w += 11, "  ");

	drawGraph(recipe, standard);

	while (true) {
		key = getch();//���͂܂ő҂��Ă����
		if (key == 'q') break;//q�������ꂽ��while���𔲂���
	}
}
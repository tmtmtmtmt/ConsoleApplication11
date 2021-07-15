#include "header.h"
#define SCALE(m,n) (int)(m * 24 / ((double)n * 8))

void drawGraph(Recipe* recipe, Standard* standard) {
	int a, b, scaleSize, t, s;
	int scale = 0;

	for (int i = 0; i < 5; i++) {
		switch (i) {
		case 0:
			scaleSize = 400;
			t = SCALE(recipe->totalEnergy, scaleSize);//尺度が異なるので変換//プリプロセッサ
			s = SCALE(standard->standardEnergy, scaleSize);//尺度が異なるので変換//
			break;
		case 1:
			scaleSize = 10;
			t = SCALE(recipe->totalProtein, scaleSize);//尺度が異なるので変換//
			s = SCALE(standard->standardProtein, scaleSize);//尺度が異なるので変換//
			break;
		case 2:
			scaleSize = 10;
			t = SCALE(recipe->totalLipid, scaleSize);//尺度が異なるので変換//
			s = SCALE(standard->standardLipid, scaleSize);//尺度が異なるので変換//
			break;
		case 3:
			scaleSize = 50;
			t = SCALE(recipe->totalCarbohydrate, scaleSize);//尺度が異なるので変換//
			s = SCALE(standard->standardCarbohydrate, scaleSize);//尺度が異なるので変換//
			break;
		case 4:
			scaleSize = 1;
			t = SCALE(recipe->totalSalt, scaleSize);//尺度が異なるので変換//
			s = SCALE(standard->standardSalt, scaleSize);//尺度が異なるので変換//
			break;
		}

		scale = 0;
		attrset(COLOR_PAIR(1));//色１を使う
		for (a = HEIGHT - 5, b = 5 + 23 * i; b < 20 + 23 * i; b++)
			mvprintw(a, b, "_");//x軸を書く
		for (a = HEIGHT - 5, b = 5 + 23 * i; a >= 0; a--) {
			mvprintw(a, b, "|");//y軸を書く
			if ((a - 1) % 3 == 0) {
				mvprintw(a, b - 4, "%d", scale);//目盛りの値
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
		attrset(COLOR_PAIR(2));//色２を使う
		for (int j = t; j >= 0; j--)
			mvaddstr(a--, b, "   ");//出力されるときは白くなる

		a = HEIGHT - 5;
		b += 3;
		attrset(COLOR_PAIR(3));//色３を使う
		for (int k = s; k >= 0; k--)
			mvaddstr(a--, b, "   ");//出力されるときは黄色くなる
	}
	refresh();//画面を更新
}

void showGraph(Recipe* recipe, Standard* standard) {
	start_color();//カラーの設定
	init_pair(1, COLOR_WHITE, COLOR_BLACK);//色１は黒地に白文字
	init_pair(2, COLOR_WHITE, COLOR_WHITE);//色２は白地に白文字
	init_pair(3, COLOR_YELLOW, COLOR_YELLOW);//色３は黄地に黄文字
	bkgd(COLOR_PAIR(1));//背景は色１

	noecho();//キー入力した文字の非表示モード
	curs_set(0); //カーソルの非表示モード
	int key;//getch()の戻り値を代入する変数
	int h, w;//上からh行目　左からw列目
	attrset(COLOR_PAIR(1));//色１を使う
	mvprintw(h = HEIGHT - 1, w = 4, "q:終了");//操作の補助説明
	mvprintw(h, w += 47, ":あなた    :基準");
	attrset(COLOR_PAIR(2));//色２を使う
	mvprintw(h, w -= 2, "  ");
	attrset(COLOR_PAIR(3));//色３を使う
	mvprintw(h, w += 11, "  ");

	drawGraph(recipe, standard);

	while (true) {
		key = getch();//入力まで待ってくれる
		if (key == 'q') break;//qが押されたらwhile文を抜ける
	}
}
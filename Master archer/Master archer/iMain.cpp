#define _CRT_SECURE_NO_WARNINGS

# include "iGraphics.h"
# include <math.h>
# include <stdio.h>
# include <time.h>
# include <stdlib.h>
# include <string.h>

#define PI 3.14159265
#define g 9.8/100

double button_dx, button_dy;
int play, a_button, use_button, use_mouse;
int game_over, back, mouse_back;

double arrow_dx, arrow_dy, x, y;
double arrowtail_dx, arrowtail_dy;
double velocity = 12;
double point_dx, point_dy;

double arrowpoint_dx, arrowpoint_dy;   // for arrow in projectile..........

int timeChange = 1;
int timechange2 = 1;
int maxTime;

double man_dx, man_dy, fruit_dx, fruit_dy;


int move, tail_move, arrow_throw, arrow_show, deg_show, show_thank, high, follow, fruit_change, dely, show_level, show_con;  // for flag...........

double deg_qeta;
long double dx, dy;

int score, high_score, life, level;
int index, index2, index3, index4, index5, index6, index7,index8;
char score_in[20], life_in[5], level_in[5];

int red, green, blue;

FILE *fp;

char archer[30][20] = { "char\\1.bmp", "char\\2.bmp", "char\\3.bmp", "char\\4.bmp", "char\\5.bmp", "char\\6.bmp", "char\\7.bmp", "char\\8.bmp", "char\\9.bmp", "char\\10.bmp", "char\\11.bmp", "char\\12.bmp", "char\\13.bmp", "char\\14.bmp", "char\\15.bmp", "char\\16.bmp", "char\\17.bmp", "char\\18.bmp", "char\\19.bmp", "char\\20.bmp", "char\\21.bmp", "char\\22.bmp", "char\\23.bmp", "char\\24.bmp", "char\\25.bmp", "char\\26.bmp", "char\\27.bmp", "char\\28.bmp", "char\\29.bmp", "char\\30.bmp" };
char man[4][20] = { "man\\1.bmp", "man\\2.bmp", "man\\3.bmp", "man\\4.bmp" };
char win_man[9][20] = { "win\\1.bmp", "win\\2.bmp", "win\\3.bmp", "win\\4.bmp", "win\\5.bmp", "win\\6.bmp", "win\\7.bmp", "win\\8.bmp", "win\\9.bmp" };
char thank[111][20] = { "thanks\\1.bmp", "thanks\\2.bmp", "thanks\\3.bmp", "thanks\\4.bmp", "thanks\\5.bmp", "thanks\\6.bmp", "thanks\\7.bmp", "thanks\\8.bmp", "thanks\\9.bmp", "thanks\\10.bmp", "thanks\\11.bmp", "thanks\\12.bmp", "thanks\\13.bmp", "thanks\\14.bmp", "thanks\\15.bmp", "thanks\\16.bmp", "thanks\\17.bmp", "thanks\\18.bmp", "thanks\\19.bmp", "thanks\\20.bmp", "thanks\\21.bmp", "thanks\\22.bmp", "thanks\\23.bmp", "thanks\\24.bmp", "thanks\\25.bmp", "thanks\\26.bmp", "thanks\\27.bmp", "thanks\\28.bmp", "thanks\\29.bmp", "thanks\\30.bmp", "thanks\\31.bmp", "thanks\\32.bmp", "thanks\\33.bmp", "thanks\\34.bmp", "thanks\\35.bmp", "thanks\\36.bmp", "thanks\\37.bmp", "thanks\\38.bmp", "thanks\\39.bmp", "thanks\\40.bmp", "thanks\\41.bmp", "thanks\\42.bmp", "thanks\\43.bmp", "thanks\\44.bmp", "thanks\\45.bmp", "thanks\\46.bmp", "thanks\\47.bmp", "thanks\\48.bmp", "thanks\\49.bmp", "thanks\\50.bmp", "thanks\\51.bmp", "thanks\\52.bmp", "thanks\\53.bmp", "thanks\\54.bmp", "thanks\\55.bmp", "thanks\\56.bmp", "thanks\\57.bmp", "thanks\\58.bmp", "thanks\\59.bmp", "thanks\\60.bmp", "thanks\\61.bmp", "thanks\\62.bmp", "thanks\\63.bmp", "thanks\\64.bmp", "thanks\\65.bmp", "thanks\\66.bmp", "thanks\\67.bmp", "thanks\\68.bmp", "thanks\\69.bmp", "thanks\\70.bmp", "thanks\\71.bmp", "thanks\\72.bmp", "thanks\\73.bmp", "thanks\\74.bmp", "thanks\\75.bmp", "thanks\\76.bmp", "thanks\\77.bmp", "thanks\\78.bmp", "thanks\\79.bmp", "thanks\\80.bmp", "thanks\\81.bmp", "thanks\\82.bmp", "thanks\\83.bmp", "thanks\\84.bmp", "thanks\\85.bmp", "thanks\\86.bmp", "thanks\\87.bmp", "thanks\\88.bmp", "thanks\\89.bmp", "thanks\\90.bmp", "thanks\\91.bmp", "thanks\\92.bmp", "thanks\\93.bmp", "thanks\\94.bmp", "thanks\\95.bmp", "thanks\\96.bmp", "thanks\\97.bmp", "thanks\\98.bmp", "thanks\\99.bmp", "thanks\\100.bmp", "thanks\\101.bmp", "thanks\\102.bmp", "thanks\\103.bmp", "thanks\\104.bmp", "thanks\\105.bmp", "thanks\\106.bmp", "thanks\\107.bmp", "thanks\\108.bmp", "thanks\\109.bmp", "thanks\\110.bmp", "thanks\\111.bmp" };
char congrats[50][20] = { "high\\1.bmp", "high\\2.bmp", "high\\3.bmp", "high\\4.bmp", "high\\5.bmp", "high\\6.bmp", "high\\7.bmp", "high\\8.bmp", "high\\9.bmp", "high\\10.bmp", "high\\11.bmp", "high\\12.bmp", "high\\13.bmp", "high\\14.bmp", "high\\15.bmp", "high\\16.bmp", "high\\17.bmp", "high\\18.bmp", "high\\19.bmp", "high\\20.bmp", "high\\21.bmp", "high\\22.bmp", "high\\23.bmp", "high\\24.bmp", "high\\25.bmp", "high\\26.bmp", "high\\27.bmp", "high\\28.bmp", "high\\29.bmp", "high\\30.bmp", "high\\31.bmp", "high\\32.bmp", "high\\33.bmp", "high\\34.bmp", "high\\35.bmp", "high\\36.bmp", "high\\37.bmp", "high\\38.bmp", "high\\39.bmp", "high\\40.bmp", "high\\41.bmp", "high\\42.bmp", "high\\43.bmp", "high\\44.bmp", "high\\45.bmp", "high\\46.bmp", "high\\47.bmp", "high\\48.bmp", "high\\49.bmp", "high\\50.bmp" };
char congrats1[3][20] = { "high\\hi\\1.bmp", "high\\hi\\2.bmp", "high\\hi\\3.bmp" };
char fruit[3][20] = { "fruit\\1.bmp","fruit\\4.bmp", "fruit\\5.bmp" };
char level_tree[2][20] = { "level\\2.bmp", "level\\3.bmp" };


void homePage();
void playGround();
void intruction();
void Exit();							// show thank you.......
void movement_head();                  // function i use..........
void movement_tail();
void archer_throw();
void spongebob();
void spongebob_win();
void thank_you();
void high_score_con();
void high_score_con2();
void get_hit();
void level_check();

int mposx, mposy;

/*
function iDraw() is called again and again by the system.
*/
void iDraw()
{
	iClear();
	if (play == 0){
		homePage();
	}

	if (play == 1){
		playGround();
	}

	if (play == 2){
		intruction();
	}
	if (play == 3 )
	{
		Exit();
	}
}

void homePage()
{
	iShowBMP(0, 0, "pictures\\home page.bmp");           
	iSetColor(0, 255, 255);
	iRectangle(button_dx, button_dy, 252, 89);
	iRectangle(button_dx - 1, button_dy - 1, 254, 91);

	iSetColor(8, 140, 91);
	iRectangle(button_dx - 2, button_dy - 2, 256, 93);

	back = 0;
}

void playGround()
{
	iShowBMP(0, 0, "pictures\\playGround.bmp");
	if (game_over != 1)
	{
		iShowBMP2(0, 20, archer[index], 0);


		if (deg_show == 1)
		{
			iSetColor(0, 0, 255);

			iLine(123, 213, point_dx, point_dy);     // main point....
			iLine(123, 213 + .25, point_dx, point_dy + .25);
			iLine(123, 213 - .25, point_dx, point_dy - .25);
		}
		iShowBMP2(0, 0, "pictures\\play_sc & life.bmp", 0);

		iSetColor(255, 0, 0);
		_itoa(score, score_in, 10);
		iText(170, 626, "SCORE : ", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(278, 626, score_in, GLUT_BITMAP_TIMES_ROMAN_24);

		if (score == 0)
		{
			iText(278, 626, "00", GLUT_BITMAP_TIMES_ROMAN_24);
		}

		_itoa(life, life_in, 10);
		iText(720, 626, "LIFE : ", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(795, 626, life_in, GLUT_BITMAP_TIMES_ROMAN_24);

		iSetColor(255, 232, 61);
		_itoa(level + 1, level_in, 10);
		iText(455, 626, "LEVEL : ", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(555, 626, level_in, GLUT_BITMAP_TIMES_ROMAN_24);

		if (show_level == 1)
		{
			iShowBMP2(0, 0, level_tree[index8], 0);
		}

		iShowBMP2(man_dx, man_dy, man[index2], 0);

		if (arrow_show == 1)
		{
			iSetColor(122, 102, 70);  // arrow color..........
			iLine(arrowtail_dx + 123, arrowtail_dy + 213, arrow_dx + 203, arrow_dy + 213);
			iLine(arrowtail_dx + 123, arrowtail_dy + 213 + .25, arrow_dx + 203, arrow_dy + 213 + .25);
			iLine(arrowtail_dx + 123, arrowtail_dy + 213 - .25, arrow_dx + 203, arrow_dy + 213 - .25);
			iLine(arrowtail_dx + 123, arrowtail_dy + 213 + .50, arrow_dx + 203, arrow_dy + 213 + .50);
			iLine(arrowtail_dx + 123, arrowtail_dy + 213 - .50, arrow_dx + 203, arrow_dy + 213 - .50);
			iLine(arrowtail_dx + 123, arrowtail_dy + 213 + .75, arrow_dx + 203, arrow_dy + 213 + .75);
			iLine(arrowtail_dx + 123, arrowtail_dy + 213 - .75, arrow_dx + 203, arrow_dy + 213 - .75);
		}

		iShowBMP2(fruit_dx, fruit_dy, fruit[index7], 0);

	}
	if (game_over == 1 ){
		iShowBMP2(760, 134, win_man[index3], 0);
		iShowBMP2(0, 0, "pictures\\gameover2.bmp", 0);
		if (high == 0)
		{
			iShowBMP2(0, 0, "pictures\\gameover_back.bmp", 0);
			button_dx = 820;
			button_dy = 593;
			iSetColor(red, green, blue);
			iRectangle(button_dx, button_dy, 181, 84);
			iRectangle(button_dx - 1, button_dy - 1, 183, 86);
			iRectangle(button_dx - 2, button_dy - 2, 185, 88);
		}
		iSetColor(255, 0, 0);
		_itoa(score, score_in, 10);
		iText(200, 650, "YOUR SCORE : ", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(380, 650, score_in, GLUT_BITMAP_TIMES_ROMAN_24);

		fp = fopen("high score.txt", "a+");
		fscanf(fp, "%d", &high_score);
		fclose(fp);

		if (score>high_score)
		{
			fp = fopen("high score.txt", "w");
			fprintf(fp, "%d", score);
			fclose(fp);
			high = 1;
			button_dx = 832;
			button_dy = 26;
		}


		if (high == 1)
		{
			dely++;
			if (dely >= 100)
			{
				show_con = 1;
				dely = 0;
			}
			if (show_con == 1)
			{
				iShowBMP(0, 0, "pictures\\back2.bmp");
				iShowBMP(350, 40, congrats[index5]);
				iShowBMP2(275.5, 410, congrats1[index6], 255);

				iSetColor(red, green, blue);
				iRectangle(button_dx, button_dy, 181, 84);
				iRectangle(button_dx - 1, button_dy - 1, 183, 86);
				iRectangle(button_dx - 2, button_dy - 2, 185, 88);
			}
			
		}
	}
}

void intruction()
{
	iShowBMP(0, 0, "pictures\\instruction.bmp");             // instruction....
	iSetColor(red, green, blue);
	iRectangle(button_dx, button_dy, 384, 120);
	iRectangle(button_dx - 1, button_dy - 1, 386, 122);
	iRectangle(button_dx + 1, button_dy + 1, 382, 118);
	iRectangle(button_dx - 1.25, button_dy - 1.25, 387, 123);

	back = 1;
}

void Exit()
{
	iShowBMP(0, 0, "pictures\\back.bmp");
	iShowBMP(58.5, 0, thank[index4]);
}

/*
function iMouseMove() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//place your codes here

}

/*
function iMouse() is called when the user presses/releases the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && use_mouse == 1)
	{
		if (mx > 652 && mx < 902)
		{
			if (my> 403 && my < 487)
			{
				play = 1;
				use_mouse = 0;
			}
			if (my> 308 && my < 391)
			{
				play = 2;
				use_mouse = 0;
				mouse_back = 1;
				button_dx = 617;
				button_dy = 48;
				use_button = 0;

			}
			if (my> 211 && my < 294)
			{
				play = 3;
				use_mouse = 0;
				show_thank = 1;
			}
		}
	}
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && mouse_back == 1 && play==2)
	{
		if (mx > 618 && mx < 999)
		{
			if (my> 50 && my < 167)
			{
				play = 0;
				use_mouse = 1;
				button_dx = 652;
				button_dy = 400;
				back = 0;
				use_button = 1;
			}
		}
	}

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && play == 1)
	{
		dx = mx - 123;
		dy = my - 213;
		deg_qeta = atan2(dy, dx) * 180 / PI;
		maxTime = velocity*sin(deg_qeta*PI / 180) / g;

		point_dx = 100 * cos(deg_qeta *PI / 180) + 123;
		point_dy = 100 * sin(deg_qeta*PI / 180) + 213;

	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN && play == 1)
	{
		arrow_throw = 1;
	}

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && high == 1 && play == 1)  // high exit..........
	{
		if (mx > 832 && mx < 1012)
		{
			if (my> 26 && my < 110)
			{
				play = 3;
				show_thank = 1;
			}
		}
	}
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && high == 0 && game_over == 1)
	{
		if (mx > 820 && mx < 1001)
		{
			if (my> 593 && my < 677)
			{
				play = 3;
				show_thank = 1;
			}
		}
	}

	printf("mx= %d...... my= %d\n", mx, my);
	printf("deg = %.2lf...\n", deg_qeta);
	
}

/*iPassiveMouseMove is called to detect and use
the mouse point without pressing any button */

void iPassiveMouseMove(int mx, int my)
{
	mposx = mx;
	mposy = my;
	if (mx > 652 && mx < 902 && play == 0)
	{
		if (my> 403 && my < 487)
		{
			button_dx = 652;
			button_dy = 400;
			a_button = 1;
		}
		if (my> 308 && my < 391)
		{
			button_dx = 652;
			button_dy = 304;
			a_button = 2;
		}
		if (my> 211 && my < 294)
		{
			button_dx = 652;
			button_dy = 208;
			a_button = 3;
		}
	}

	if (mx > 618 && mx < 999 && play == 2)
	{
		if (my> 50 && my < 167)
		{
			button_dx = 617;
			button_dy = 48;
			red = 48;
			green = 255;
			blue = 48;
			
		}
		else
		{
			red = 255;
			green = 0;
			blue = 0;
		}
	}
	else
	{
		red = 255;
		green = 0;
		blue = 0;
	}

	if (high == 1)
	{
		if (mx > 832 && mx < 1012)
		{
			if (my> 26 && my < 110)
			{
				button_dx = 832;
				button_dy = 26;
				red = 255;
				green = 48;
				blue = 48;
			}
			else
			{
				red = 255;
				green = 233;
				blue = 73;
			}
		}
		else
		{
			red = 255;
			green = 233;
			blue = 73;
		}
	}
	if (game_over == 1 && high == 0)
	{
		if (mx > 820 && mx < 1001)
		{
			if (my> 593 && my < 677)
			{
				button_dx = 832;
				button_dy = 26;
				red = 255;
				green = 48;
				blue = 48;
			}
			else
			{
				red = 255;
				green = 233;
				blue = 73;
			}
		}
		else
		{
			red = 255;
			green = 233;
			blue = 73;
		}
	}

	//printf("mx= %d...... my= %d\n", mx, my);

}

/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/

void iKeyboard(unsigned char key)
{
	if (key == 'z')
	{
		score += 10;
	}
	if (key == 'g')
	{
		game_over = 1;
		
	}
	if (key == 'l')
	{
		level++;
	}
	if (key == 'h')
	{
		high = 1;
		button_dx = 832;
		button_dy = 26;
		use_button = 0;
	}
	if (key == 'p')
	{
		iPauseTimer(0);
		iPauseTimer(1);
		iPauseTimer(2);
		iPauseTimer(3);
		iPauseTimer(4);
		iPauseTimer(5);
		iPauseTimer(6);
		iPauseTimer(7);
		iPauseTimer(8);

	}
	if (key == 'r')
	{
		iResumeTimer(0);
		iResumeTimer(1);
		iResumeTimer(2);
		iResumeTimer(3);
		iResumeTimer(4);
		iResumeTimer(5);
		iResumeTimer(6);
		iResumeTimer(7);
		iResumeTimer(8);
	}

	if (high == 1 && key == 13 && play ==1)    // high back..........
	{
		play = 3;
		show_thank = 1;
	}
	if (high == 0 && key == 13 && game_over == 1)   // game over back............
	{
		play = 3;
		show_thank = 1;
	}

	if (a_button == 1 && key == 13 && use_button == 1)       // button selection........
	{
		play = 1;
	}
	if (a_button == 2 && key == 13 && back == 0)
	{

		play = 2;
		button_dx = 617;
		button_dy = 48;
		back = 0;
	}
	if (a_button == 3 && key == 13 && use_button == 1)
	{
		play = 3;
		show_thank = 1;
	}                                     //.........
	if (key == 13)
	{
		use_button = 0;
	}
	if (key == 13 && back == 1 && play == 2) // instruction .........
	{
		play = 0;
		a_button = 1;
		use_button = 1;
		button_dx = 652;
		button_dy = 400;
		use_mouse = 1;
	}

	if (play == 1)
	{
		if (key == ' ')
		{
			arrow_throw = 1;
		}

	}
	/*
	printf("play;%d\n", play);
	printf("key : %d\n", key);
	printf("key : %c\n", key);
	printf("back: %d\n", back);
	*/
	
}

/*
function iSpecialKeyboard() is called whenver user hits special keys like-
function keys, home, end, pg up, pg down, arraows etc. you have to use
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{

	if (key == GLUT_KEY_END)
	{
		exit(0);
	}

	if (use_button == 1 && button_dy != 208 && key == GLUT_KEY_DOWN)                //   button move...........
	{
		button_dy -= 96;
		a_button++;
	}
	if (use_button == 1 && button_dy != 400 && key == GLUT_KEY_UP)
	{
		button_dy += 96;
		a_button--;
	}
	
	//printf("button: %d\n", a_button);
	//printf("key : %c\n", key);
	//printf("back: %d\n", back);

	///printf("deg = %.2lf...\n", deg);
	//printf("dx=%.2lf....dy=%.2lf...\n", arrow_dx, arrow_dy);

}


void movement_head()
{
	if (move == 1)
	{
		arrow_dx = velocity*cos(deg_qeta*PI / 180)*timeChange;
		arrowtail_dx = arrow_dx;
		arrow_dy = arrow_dx*tan(deg_qeta*PI / 180) - 0.5*g*arrow_dx*arrow_dx / (velocity*cos(deg_qeta*PI / 180)) / (velocity*cos(deg_qeta*PI / 180));
		if (timeChange != maxTime)
		{
			timeChange++;
		}

		if (arrow_dx >= (fruit_dx - 203) && arrow_dx <= (fruit_dx + 10 -203) && arrow_dy  >= (fruit_dy + 5 - 213) && arrow_dy <= (fruit_dy + 63-213))
		{
			score += 10;
			follow = 1;
			fruit_change = 1;
		}
		if (score>100)
		{
			level = 1;
		}
		if (score>200)
		{
			level = 2;
		}
		if (score >300)
		{
			level = 3;
		}
	
		if (arrow_dy < -212 || arrow_dy >600 || arrowtail_dx > 1100)
		{
			timeChange = 1;
			maxTime = 0;
			move = 0;
			arrow_dx = arrow_dy = 0;
			tail_move = 0;
			timechange2 = 1;
			arrowtail_dx = arrowtail_dy = 0;
			deg_qeta = 0;
			index = 0;
			arrow_throw = 0;
			arrow_show = 0;
			deg_show = 1;
			level_check();
			if (level >= 2)
			{
				show_level = 1;
			}

			if (fruit_change == 1)
			{
				srand(time(NULL));
				index7 = rand() % 3;
				fruit_change = 0;
			}
			if (follow == 0)
			{
				life--;
			}
			if (life == 0)
			{
				game_over = 1;
			}
			follow = 0;	

		}
		if (arrow_dx > 80 || (deg_qeta > 70 && arrow_dy>80 ))
		{
			tail_move = 1;
		}
	}

}

void movement_tail()
{
	if (tail_move == 1)
	{
		arrowpoint_dx = velocity*cos(deg_qeta*PI / 180)*timechange2;
		arrowtail_dy = arrowpoint_dx*tan(deg_qeta*PI / 180) - 0.5*g*arrowpoint_dx*arrowpoint_dx / (velocity*cos(deg_qeta*PI / 180)) / (velocity*cos(deg_qeta*PI / 180));

		if (timechange2 != maxTime)
		{
			timechange2++;
		}
		//printf("arrowdx: %.2lf\tarrowdy: %.2lf\n", arrow_dx + 203, arrow_dy + 213);
		//printf("fdx: %.2lf\tfdy: %.2lf\n", fruit_dx, fruit_dy);
	}
	//printf("arrowdx: %.2lf\tarrowdy: %.2lf\n", arrow_dx, arrow_dy);
	//printf("arrowdx: %.2lf\tarrowdy: %.2lf\n", arrow_dx + 203, arrow_dy + 213);
	//printf("fdx: %.2lf\fdy: %.2lf\n", fruit_dx, fruit_dy);
}

void level_check()
{
	if (level == 0)
	{
		man_dx = 580;
		man_dy = 60;
		fruit_dx = 640;
		fruit_dy = 204;

	}
	if (level == 1)
	{
		man_dx = 700;
		man_dy = 60;
		fruit_dx = 760;
		fruit_dy = 205;

	}
	if (level == 2)
	{
		index8 = 0;
		man_dx = 610;
		man_dy = 160;
		fruit_dx = 670;
		fruit_dy = 304;
		
	}
	if (level == 3)
	{
		index8 = 1;
		man_dx = 780;
		man_dy = 190;
		fruit_dx = 840;
		fruit_dy = 335;
	}
}

void get_hit()
{
	if (follow == 1)
	{
		fruit_dx = arrow_dx + 190;
		fruit_dy = arrow_dy + 190;
		life = 4;
	}
}

void archer_throw()
{
	if (arrow_throw == 1)
	{
		deg_show = 0;
		index++;
		if (index >= 29)
		{
			index = 29;
			move = 1;
			arrow_show = 1;
		}
	}

}

void spongebob()
{
	index2++;
	if (index2 >= 3)
	{
		index2 = 0;
	}
}

void spongebob_win()
{
	if (game_over == 1)
	{
		index3++;
		if (index3 >= 8)
		{
			index3 = 0;
		}
	}
}

void thank_you()
{
	if (show_thank == 1)
	{
		index4++;
		if (index4 >= 110)
		{
			index4 = 0;
		}
	}
}
void high_score_con()
{
	if (high == 1)
	{
		index5++;
		if (index5 >= 49)
		{
			index5 = 0;
		}
	}
}

void high_score_con2()
{
	if (high == 1)
	{
		index6++;
		if (index6 >= 2)
		{
			index6 = 0;
		}
	}
}

int main()
{

	iSetTimer(100, archer_throw);
	iSetTimer(80, spongebob);
	iSetTimer(80, spongebob_win);
	iSetTimer(30, thank_you);
	iSetTimer(30, high_score_con);
	iSetTimer(80, high_score_con2);
	iSetTimer(15, movement_head);
	iSetTimer(15, movement_tail);
	iSetTimer(15, get_hit);


	arrowtail_dx = 0, arrowtail_dy = 0;
	arrow_dx = 0, arrow_dy = 0;
	button_dx = 652, button_dy = 400;
	level_check();
	

	point_dx = 123;
	point_dy = 213;

	a_button = 1;
	use_button = 1;
	use_mouse = 1;
	game_over = 0;
	back = 0;
	deg_show = 1;
	life = 4;


	iInitialize(1050, 700, "Master archer");
	return 0;
}

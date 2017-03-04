#include "myHeader.h"


int i, j, k; /* N : These are for looping purpose */

int cycle = 0; // Nafee(N): I will increase it always

int isPause = 0; /*If anybody wants pause, then it will be 1*/

int work = 0; // N : To check iSpecialKeyboard

int gameOverCount = 0; /* N : This will be used in game over function, When game over function is called,
					   We will gradually increase its value.
					   When its value will be 1000, then we will blurr the screen with red colour*/

int lives = 0, level = 1, score = 0;

char str_level[10], str_score[10]; /*N : I need them to show level & score in the screen*/

int myPlanePosition_x = 700 ;  // Here the x  denotes the x positions of the plane.



int	myPlanePosition_y = 250;  /* N : Except my plane i.e. plane of myPlanePosition_y = 250
							   all other planes initially have y position of 500.
							   That means they are out of the screen! */



int enemyPlanePosition_x[7], enemyPlanePosition_y[7];

											//y  denotes the y positions of the plane.
											// We are using total 11 planes, so arrays have 11 elements
											//  0 denotes the position of myPlane
											//  1 to 5 denotes the position of 5 enemy planes
											//  1 denotes position of plane1
											//  2 denotes position of plane2 etc.


int enemyBulletPosition_x[7], enemyBulletPosition_y[7];  /* N : These are positions of enemy bullets.
										 position 1 is of the bullet thrown by enemyPlane 1,
										 position 2 is of the bullet thrown by enemyPlane 2.
										 */





int fromWhichPositionEnemyBulletWillBeThrown_x[7];

double barrelAngle = 180; /* N : Player can control the barrelAngle
						  Lower limit = 135 degree
						  Upper limit = 225 degree*/
int barrelDiff_x = - 3.536, barrelDiff_y = 3.536; /*N : barrelDiff_x = 5 * cos(barrelAngle * 3.1416 / 180)
								   barrelDiff_y = 5 * sin(barrelAngle * 3.1416 / 180)
								   Speed of the Bullet will be always 5*/

double barrel_x[4], barrel_y[4]; /*Using this array, we will draw the barrel
								 We will draw 4 sided polygon, whose 
								 vertice 1 = (barrel_x[0], barrel_y[0]),
								 vertice 2 = (barrel_x[1], barrel_y[1]),
								 vertice 3 = (barrel_x[2], barrel_y[2]),
								 vertice 4 = (barrel_x[3], barrel_y[3])*/


int myMissile_x = 0, myMissile_y = -150;

int myBullet_x = 0;
int myBullet_y = -150;

int lives_x;  /* N : These are the positions of lives.bmp images */
int lives_y = 475;

int radiusOfPower = 15;
int flag = 0;
int isProtected = 0;



int chanceOfLifePosition_x = 1000;
int chanceOfLifePosition_y = 1000;
int flagOfChanceOfLife = 0;
int radiusOfChanceOfLife = 15;
int timerOfChanceOfLife = 0;



int chanceOfScorePosition_x = 1000;
int chanceOfScorePosition_y = 1000;
int flagOfChanceOfScorePosition = 0;
int radiusOfChanceOfScore = 15;
int timerOfChanceOfScore = 0;

int numberOfPlay = 0; //to count the number of playing game at every run time
int showHelp = 0;

void welcome()
{
	iSetcolor(0, 0, 10);
	iFilledRectangle(0, 0, 900, 500);

	iSetcolor(1, 1, 1);
	iText(285, 300, "WELCOME.  ENJOY GAMING.", GLUT_BITMAP_TIMES_ROMAN_24);

	iSetcolor(100, 0, 20);
	iFilledRectangle(220, 150, 50, 26);
	iFilledCircle(220, 163, 13);
	iFilledCircle(270, 163, 13);

	iSetcolor(1, 1, 1);
	iText(225, 157, "Help", GLUT_BITMAP_HELVETICA_18);

	iSetcolor(100, 0, 20);
	iFilledRectangle(410, 150, 90, 26);
	iFilledCircle(410, 163, 13);
	iFilledCircle(500, 163, 13);

	iSetcolor(1, 1, 1);
	iText(410, 157, "Start Now", GLUT_BITMAP_HELVETICA_18);

	iSetcolor(100, 0, 20);
	iFilledRectangle(640, 150, 50, 26);
	iFilledCircle(640, 163, 13);
	iFilledCircle(690, 163, 13);

	iSetcolor(1, 1, 1);
	iText(650, 157, "Exit", GLUT_BITMAP_HELVETICA_18);
}

void instructions()
{
	iSetcolor(0, 0, 10);
	iFilledRectangle(0, 0, 900, 500);

	iSetcolor(1, 1, 1);
	iText(380, 420, "Instructions", GLUT_BITMAP_TIMES_ROMAN_24);


	iSetcolor(100, 0, 20);
	iFilledRectangle(70, 420, 50, 26);
	iFilledCircle(70, 433, 13);
	iFilledCircle(120, 433, 13);

	iSetcolor(1, 1, 1);
	iText(75, 427, "Back", GLUT_BITMAP_HELVETICA_18);

	iSetcolor(10, 100, 0);
	iFilledCircle(120, 369, 9);
	iFilledCircle(120, 329, 9);
	iFilledCircle(120, 289, 9);
	iFilledCircle(120, 249, 9);
	iFilledCircle(120, 209, 9);
	iFilledCircle(120, 169, 9);

	iSetcolor(0, 0, 0);
	iFilledCircle(120, 369, 5);
	iFilledCircle(120, 329, 5);
	iFilledCircle(120, 289, 5);
	iFilledCircle(120, 249, 5);
	iFilledCircle(120, 209, 5);
	iFilledCircle(120, 169, 5);

	iSetcolor(1, 1, 1);
	iText(150, 360, "Press w, s, a or d to move your plane up, down, left or right respectively.", GLUT_BITMAP_HELVETICA_18);
	iText(150, 320, "Press b to throw a bullet and space to throw a missile.", GLUT_BITMAP_HELVETICA_18);
	iText(150, 280, "Press y or h to change the direction of your gun.", GLUT_BITMAP_HELVETICA_18);
	iText(150, 240, "Press p to pause the game for some time.", GLUT_BITMAP_HELVETICA_18);
	iText(150, 200, "You can only throw a bullet or a missile when the previous one crosses the screen.", GLUT_BITMAP_HELVETICA_18);
	iText(150, 160, "If your plane touches the upper or lower red line, you will lose a life.", GLUT_BITMAP_HELVETICA_18);
}




void gameOver()
{
	char sScore[5];
	sprintf_s(sScore, "%d", score);
	gameOverCount++;


	if (gameOverCount > 200)
	{

		iSetcolor(0, 0, 10);
		iFilledRectangle(0, 0, 900, 500);

		iSetcolor(1, 1, 1);
		iFilledEllipse(464, 332, 84, 50, 200);

		iShowBMP(400, 300, "myDestroyedPlane.bmp");

		iSetcolor(1, 1, 1);
		iText(380, 250, "GAME OVER!!!", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(390, 200, "Your Score:" , GLUT_BITMAP_TIMES_ROMAN_24);
		iText(510, 200, sScore, GLUT_BITMAP_TIMES_ROMAN_24);

		iSetcolor(100, 0, 20);
		iFilledRectangle(220, 150, 50, 26);
		iFilledCircle(220, 163, 13);
		iFilledCircle(270, 163, 13);

		iSetcolor(1, 1, 1);
		iText(225, 157, "Help", GLUT_BITMAP_HELVETICA_18);

		iSetcolor(100, 0, 20);
		iFilledRectangle(410, 150, 90, 26);
		iFilledCircle(410, 163, 13);
		iFilledCircle(500, 163, 13);

		iSetcolor(1, 1, 1);
		iText(410, 157, "Play Again", GLUT_BITMAP_HELVETICA_18);

		iSetcolor(100, 0, 20);
		iFilledRectangle(640, 150, 50, 26);
		iFilledCircle(640, 163, 13);
		iFilledCircle(690, 163, 13);

		iSetcolor(1, 1, 1);
		iText(650, 157, "Exit", GLUT_BITMAP_HELVETICA_18);
	}
}


int playAgain(int x, int y)
{
	if((gameOverCount > 200 || numberOfPlay == 0) && showHelp == 0){
		if(x > 410 && x < 500 && y > 150 && y < 176)
			return 1;

		if( (x-410)*(x-410) + (y-163)*(y-163) < 13*13)
			return 1;

		if( (x-500)*(x-500) + (y-163)*(y-163) < 13*13)
			return 1;

	}

	return 0;
}

int Exit(int x, int y)
{
	if((gameOverCount > 200 || numberOfPlay == 0) && showHelp == 0){
		if(x > 640 && x < 690 && y > 150 && y < 176)
			return 1;

		if( (x-640)*(x-640) + (y-163)*(y-163) < 13*13)
			return 1;

		if( (x-690)*(x-690) + (y-163)*(y-163) < 13*13)
			return 1;

	}

	return 0;
}

int help(int x, int y)
{
	if ((gameOverCount > 200 || numberOfPlay == 0) && showHelp == 0){
		if(x > 220 && x < 270 && y > 150 && y < 176)
			return 1;

		if( (x-220)*(x-220) + (y-163)*(y-163) < 13*13)
			return 1;

		if( (x-270)*(x-270) + (y-163)*(y-163) < 13*13)
			return 1;

	}

	return 0;
}


int back(int x, int y)
{
	if(showHelp == 1){
		if(x > 70 && x < 120 && y > 420 && y < 446)
			return 1;

		if( (x-70)*(x-70) + (y-433)*(y-433) < 13*13)
			return 1;

		if( (x-120)*(x-120) + (y-433)*(y-433) < 13*13)
			return 1;

	}

	return 0;
}

int ifMyPlaneCrossedRedLine()  // if my plane crosses the red line then it will return 1, otherwise 0
{
	if (myPlanePosition_y <= 24 || myPlanePosition_y >= (500 - 25- 64))
	{
		return 1;
	}

	else
	{
		return 0;
	}
}

void initializeMyMissile()
{
	myMissile_x = myPlanePosition_x + 20;
	myMissile_y = myPlanePosition_y + 10;
}

void initializeMyPlane()
{
	myPlanePosition_x = 700;
	myPlanePosition_y = 200;
}

void initializePlane1()
{
	int  tempEnemyPlanePos_y, isOverlaped;

	do{
		isOverlaped = 0;
		enemyPlanePosition_x[1] = -150 + rand() % 125;				// within -150 to -25
		tempEnemyPlanePos_y = 30 + rand() % 410;					// within 30 to 440
		for (i = 1; i <= 6; i++)
		{
			if (i != 1 && abs(tempEnemyPlanePos_y - enemyPlanePosition_y[i]) < 50 && abs(enemyPlanePosition_x[1] - enemyPlanePosition_x[i]) < 100)
				isOverlaped = 1;
		}

	} while (isOverlaped == 1);
	enemyPlanePosition_y[1] = tempEnemyPlanePos_y;
}

void initializePlane2()
{
	int  tempEnemyPlanePos_y, isOverlaped;


	do{
		isOverlaped = 0;
		enemyPlanePosition_x[2] = -150 + rand() % 125;
		tempEnemyPlanePos_y = 30 + rand() % 410;   
		for (i = 1; i <= 6; i++)
		{
			if (i != 2 && abs(tempEnemyPlanePos_y - enemyPlanePosition_y[i]) < 50 && abs(enemyPlanePosition_x[2] - enemyPlanePosition_x[i]) < 100)
				isOverlaped = 1;
		}

	} while (isOverlaped == 1);
	enemyPlanePosition_y[2] = tempEnemyPlanePos_y;
}

void initializePlane3()
{
	int  tempEnemyPlanePos_y, isOverlaped;

	do{
		isOverlaped = 0;
		enemyPlanePosition_x[3] = -150 + rand() % 125;
		tempEnemyPlanePos_y = 30 + rand() % 410;   
		for (i = 1; i <= 6; i++)
		{
			if (i != 3 && abs(tempEnemyPlanePos_y - enemyPlanePosition_y[i]) < 50 && abs(enemyPlanePosition_x[3] - enemyPlanePosition_x[i]) < 100)
				isOverlaped = 1;
		}

	} while (isOverlaped == 1);
	enemyPlanePosition_y[3] = tempEnemyPlanePos_y;
}


void initializePlane4()
{
	int  tempEnemyPlanePos_y, isOverlaped;


	do{
		isOverlaped = 0;
		enemyPlanePosition_x[4] = -150 + rand() % 125;
		tempEnemyPlanePos_y = 30 + rand() % 410;   
		for (i = 1; i <= 6; i++)
		{
			if (i != 4 && abs(tempEnemyPlanePos_y - enemyPlanePosition_y[i]) < 50 && abs(enemyPlanePosition_x[4] - enemyPlanePosition_x[i]) < 100)
				isOverlaped = 1;
		}

	} while (isOverlaped == 1);
	enemyPlanePosition_y[4] = tempEnemyPlanePos_y;
}


void initializePlane5()
{
	int  tempEnemyPlanePos_y, isOverlaped;

	if (level > 2){
		do{
			isOverlaped = 0;
			enemyPlanePosition_x[5] = -150 + rand() % 125;
			tempEnemyPlanePos_y = 30 + rand() % 410;
			for (i = 1; i <= 6; i++)
			{
				if (i != 5 && abs(tempEnemyPlanePos_y - enemyPlanePosition_y[i]) < 50 && abs(enemyPlanePosition_x[5] - enemyPlanePosition_x[i]) < 100)
					isOverlaped = 1;
			}

		} while (isOverlaped == 1);
		enemyPlanePosition_y[5] = tempEnemyPlanePos_y;
	}
	else
		enemyPlanePosition_y[5] = 510;
}

void initializePlane6()
{
	int tempEnemyPlanePos_y, isOverlaped;

	if (level > 4){
		do{
			isOverlaped = 0;
			enemyPlanePosition_x[6] = -150 + rand() % 125;
			tempEnemyPlanePos_y = 30 + rand() % 410;
			for (i = 1; i <= 6; i++)
			{
				if (i != 6 && abs(tempEnemyPlanePos_y - enemyPlanePosition_y[i]) < 50 && abs(enemyPlanePosition_x[6] - enemyPlanePosition_x[i]) < 100)
					isOverlaped = 1;
			}

		} while (isOverlaped == 1);
		enemyPlanePosition_y[6] = tempEnemyPlanePos_y;
	}
	else
		enemyPlanePosition_y[6] = 510;
}



void initializeAllPlane()
{
	initializeMyPlane();
	initializePlane1();
	initializePlane2();
	initializePlane3();
	initializePlane4();
	initializePlane5();
	initializePlane6();
	
}

int ifALifeIsLost()
{
	if (ifMyPlaneCrossedRedLine() || ifEnemyBulletHitMyPlane() || ifEnemyPlaneHitMyPlane())
	{
		return 1;
	}

	else
	{
		return 0;
	}
}


void callEnemyPlaneIfItCrossesTheScreen()
{
	
	if (enemyPlanePosition_x[1] >= (900 + rand() % 100) )  // N : enemyPlanePosition_x[1] == any value from 900 to 1000
	{
		initializePlane1();
	}

	if (enemyPlanePosition_x[2] >= (900 + rand() % 100) )	
	{
		initializePlane2();
	}

	if (enemyPlanePosition_x[3] >= (900 + rand() % 100) )
	{
		initializePlane3();
	}

	if (enemyPlanePosition_x[4] >= (900 + rand() % 100) )
	{
		initializePlane4();
	}

	if (enemyPlanePosition_x[5] >= (900  + rand() % 100 ) )
	{
		initializePlane5();
	}

	if (enemyPlanePosition_x[6] >= (900 + rand() % 100 ) )
	{
		initializePlane6();
	}

}


void produceImageOfAllPlanes()
{
	if (lives > 0) /*N : When I have lives, then I will show image of myPlane*/
	{
		iShowBMP(myPlanePosition_x, myPlanePosition_y, "myPlane.bmp");

		/*N : Now I will draw the barrel*/
		drawBarrel();
	}
	else /*N : But when I don't have life, then I will show image of
		 myDestroyedPlane.
		 Then no need to show the barrel also.
		 */
	{
		iShowBMP(myPlanePosition_x, myPlanePosition_y, "myDestroyedPlane.bmp");
	}															/* I am using only 6 images.
																	One for my plane.
																	Other 5 planes are twice used.
																	plane 1 & plane 6 are same images.
																	*/
	iShowBMP(enemyPlanePosition_x[1], enemyPlanePosition_y[1], "plane1.bmp");
	iShowBMP(enemyPlanePosition_x[2], enemyPlanePosition_y[2], "plane2.bmp");
	iShowBMP(enemyPlanePosition_x[3], enemyPlanePosition_y[3], "plane3.bmp");
	iShowBMP(enemyPlanePosition_x[4], enemyPlanePosition_y[4], "plane4.bmp");
	iShowBMP(enemyPlanePosition_x[5], enemyPlanePosition_y[5], "plane5.bmp");
	iShowBMP(enemyPlanePosition_x[6], enemyPlanePosition_y[6], "plane1.bmp");

	
}




void enemyPlaneMotion()  /* This function always increases
						 the x positions of enemy planes  */
{
	for (i = 1; i <= 6; i++)
	{
		enemyPlanePosition_x[i] += level;
	}
}

void randomizeFromWhichPositionEnemyBulletWillBeThrown_x()
{
	for (i = 1; i <= 6; i++)
	{
		fromWhichPositionEnemyBulletWillBeThrown_x[i] = 50 + rand() % 500;
		/* N: Bullet will be thrown from x position between 0 and 150 */
	}
}

void allEnemyBulletOutOfScreen()
{

	for (j = 0; j <= 6; j++)
	{
		enemyBulletPosition_x[j] = 1000; /* All bullets are initially out of the screen */
		enemyBulletPosition_y[j] = 250; /* It is unimportant as x positions are already out of screen */
	}
}

void initializeEnemyBullet()
{
	for (i = 1; i <= 6; i++)
	{
		if ((enemyBulletPosition_x[i] > 910) &&  (enemyPlanePosition_x[i] == fromWhichPositionEnemyBulletWillBeThrown_x[i]))
		{
			enemyBulletPosition_x[i] = enemyPlanePosition_x[i] + 64;
			enemyBulletPosition_y[i] = enemyPlanePosition_y[i] + 16;
			fromWhichPositionEnemyBulletWillBeThrown_x[i] = 50 + rand() % 500; /*Any position between
																			   50 and 550*/
		}
	}
}


void drawEnemyBullet()
{
	iSetcolor(100, 0, 0);
	for (i = 1; i <= 6; i++)
	{
		iFilledCircle(enemyBulletPosition_x[i], enemyBulletPosition_y[i], 4);
	}
}

void drawBarrel()
{
	
	barrel_x[0] = myPlanePosition_x + 5;
	barrel_y[0] = myPlanePosition_y + 28;

	barrel_x[1] = barrel_x[0];
	barrel_y[1] = barrel_y[0] + 8;

	barrel_x[2] = barrel_x[0] + 5 * 5 * cos(barrelAngle / 180 * 3.1416);
	barrel_y[2] = barrel_y[0] + 5 * 5 * sin(barrelAngle / 180 * 3.1416);

	barrel_x[3] = barrel_x[2];
	barrel_y[3] = barrel_y[2] + 8;

	iSetcolor(120, 0, 0);
	iFilledPolygon(barrel_x, barrel_y, 4);
}

void enemyBulletMotion()  /* This function always increases
						 the x positions of enemy planes' bullets  */
{
	for (i = 1; i <= 6; i++)
	{
		enemyBulletPosition_x[i] += (2*level);
	}
}

void enemyBullet()
{
	initializeEnemyBullet();
	drawEnemyBullet();
}



void initializeMyBullet()
{
	myBullet_x = myPlanePosition_x + 5 + 5 * 5 * cos(barrelAngle / 180 * 3.1416);
	myBullet_y = myPlanePosition_y + 32 + 5 * 5 * sin(barrelAngle / 180 * 3.1416);

	barrelDiff_x = (5 + level) * cos(barrelAngle / 180 * 3.1416);
	barrelDiff_y = (5 + level) * sin(barrelAngle / 180 * 3.1416);

}

void upperAndlowerFilledRectangle()
{
	iFilledRectangle(0, 0, 900, 25);
	iFilledRectangle(0, 475, 900, 25);
		
}


void myMissile()
{
	iSetcolor(256, 0, 0);
	iFilledEllipse(myMissile_x, myMissile_y, 30, 4);
	iSetcolor(0, 0, 10);
	iFilledRectangle(myMissile_x, myMissile_y - 4, 30, 8);

	
}


void myBullet()
{
	
	iSetcolor(256, 0, 0);
	iFilledCircle(myBullet_x, myBullet_y, 4);
	
}


void showLivesScoreLevel()
{
	for (i = 1; i <= lives; i++)
	{
		lives_x = 30 + i * 20;
		iShowBMP(lives_x, lives_y, "lives.bmp");
	}


	level = score / 7 + 1;

	iSetcolor(1, 1, 1);

	iText(400, 485, "LEVEL");
	sprintf_s(str_level, "%d", level);
	iText(450, 485, str_level);



	iText(600, 485, "SCORE");
	sprintf_s(str_score, "%d", score);
	iText(650, 485, str_score);

}




void ifMyMissileHitEnemyPlane()				//R
{
	if (myMissile_x - 15 <= enemyPlanePosition_x[1] + 64 && myMissile_x + 15 >= enemyPlanePosition_x[1] && myMissile_y - enemyPlanePosition_y[1] >= 0 && myMissile_y - enemyPlanePosition_y[1] <= 32)
	{
		initializePlane1();
		score += 1;
	}

	if (myMissile_x - 15 <= enemyPlanePosition_x[2] + 64 && myMissile_x + 15 >= enemyPlanePosition_x[2] && myMissile_y - enemyPlanePosition_y[2] >= 0 && myMissile_y - enemyPlanePosition_y[2] <= 32)
	{
		initializePlane2();
		score += 1;
	}

	if (myMissile_x - 15 <= enemyPlanePosition_x[3] + 64 && myMissile_x + 15 >= enemyPlanePosition_x[3] && myMissile_y - enemyPlanePosition_y[3] >= 0 && myMissile_y - enemyPlanePosition_y[3] <= 32)
	{
		initializePlane3();
		score += 1;
	}

	if (myMissile_x - 15 <= enemyPlanePosition_x[4] + 64 && myMissile_x + 15 >= enemyPlanePosition_x[4] && myMissile_y - enemyPlanePosition_y[4] >= 0 && myMissile_y - enemyPlanePosition_y[4] <= 32)
	{
		initializePlane4();
		score += 1;
	}

	if (myMissile_x - 15 <= enemyPlanePosition_x[5] + 64 && myMissile_x + 15 >= enemyPlanePosition_x[5] && myMissile_y - enemyPlanePosition_y[5] >= 0 && myMissile_y - enemyPlanePosition_y[5] <= 32)
	{
		initializePlane5();
		score += 1;
	}

	if (myMissile_x - 15 <= enemyPlanePosition_x[6] + 64 && myMissile_x + 15 >= enemyPlanePosition_x[6] && myMissile_y - enemyPlanePosition_y[6] >= 0 && myMissile_y - enemyPlanePosition_y[6] <= 32)
	{
		initializePlane6();
		score += 1;
	}
		

}


void ifMyBulletHitEnemyPlane()			// my Bullet is a circle of 4 pixel radius
{
	if (myBullet_y - 4 <= enemyPlanePosition_y[1] + 32 && myBullet_y + 4 >= enemyPlanePosition_y[1] && enemyPlanePosition_x[1] - myBullet_x <= 4 && myBullet_x - enemyPlanePosition_x[1] <= 68)
	{
		myBullet_x = -100; /* N : my Bullet is out of screen*/
		initializePlane1();
		score += 1;

	}

	if (myBullet_y - 4 <= enemyPlanePosition_y[2] + 32 && myBullet_y + 4 >= enemyPlanePosition_y[2] && enemyPlanePosition_x[2] - myBullet_x <= 4 && myBullet_x - enemyPlanePosition_x[2] <= 68)
	{
		myBullet_x = -100; /* N : my Bullet is out of screen*/
		initializePlane2();
		score += 1;

	}

	if (myBullet_y - 4 <= enemyPlanePosition_y[3] + 32 && myBullet_y + 4 >= enemyPlanePosition_y[3] && enemyPlanePosition_x[3] - myBullet_x <= 4 && myBullet_x - enemyPlanePosition_x[3] <= 68)
	{
		myBullet_x = -100; /* N : my Bullet is out of screen*/
		initializePlane3();
		score += 1;

	}

	if (myBullet_y - 4 <= enemyPlanePosition_y[4] + 32 && myBullet_y + 4 >= enemyPlanePosition_y[4] && enemyPlanePosition_x[4] - myBullet_x <= 4 && myBullet_x - enemyPlanePosition_x[4] <= 68)
	{
		myBullet_x = -100; /* N : my Bullet is out of screen*/
		initializePlane4();
		score += 1;

	}

	if (myBullet_y - 4 <= enemyPlanePosition_y[5] + 32 && myBullet_y + 4 >= enemyPlanePosition_y[5] && enemyPlanePosition_x[5] - myBullet_x <= 4 && myBullet_x - enemyPlanePosition_x[5] <= 68)
	{
		myBullet_x = -100; /* N : my Bullet is out of screen*/
		initializePlane5();
		score += 1;

	}

	if (myBullet_y - 4 <= enemyPlanePosition_y[6] + 32 && myBullet_y + 4 >= enemyPlanePosition_y[6] && enemyPlanePosition_x[6] - myBullet_x <= 4 && myBullet_x - enemyPlanePosition_x[6] <= 68)
	{
		myBullet_x = -100; /* N : my Bullet is out of screen*/
		initializePlane6();
		score += 1;

	}
}


int ifEnemyBulletHitMyPlane()			//my plane is devided into three rectangle
										//
{
	for (i = 1; i <= 6; i++)
	{
		if ((enemyBulletPosition_x[i] + 4 >= myPlanePosition_x + 23) && (enemyBulletPosition_x[i] - 4 <= myPlanePosition_x + 128) && (enemyBulletPosition_y[i] + 4 >= myPlanePosition_y) && (enemyBulletPosition_y[i] - 4 <= myPlanePosition_y + 11))
			return 1;

		if ((enemyBulletPosition_x[i] + 4 >= myPlanePosition_x) && (enemyBulletPosition_x[i]  - 4 <= myPlanePosition_x + 128) && (enemyBulletPosition_y[i]  + 4 >= myPlanePosition_y + 11) && (enemyBulletPosition_y[i] - 4 <= myPlanePosition_y + 55))
			return 1;
		
		if ((enemyBulletPosition_x[i] + 4 >= myPlanePosition_x + 12) && (enemyBulletPosition_x[i] - 4 <= myPlanePosition_x + 128) && (enemyBulletPosition_y[i] + 4 >= myPlanePosition_y + 55) && (enemyBulletPosition_y[i] - 4 <= myPlanePosition_y + 64))
			return 1;
	}

	return 0;
}

int ifEnemyPlaneHitMyPlane()
{
	for (i = 1; i <= 6; i++)
	{
		if ((enemyPlanePosition_x[i] + 64 >= myPlanePosition_x + 23) && (enemyPlanePosition_x[i] <= myPlanePosition_x + 128) && (enemyPlanePosition_y[i] + 32 >= myPlanePosition_y) && (enemyPlanePosition_y[i] <= myPlanePosition_y + 11))
			return 1;

		if ((enemyPlanePosition_x[i] + 64 >= myPlanePosition_x) && (enemyPlanePosition_x[i] <= myPlanePosition_x + 128) && (enemyPlanePosition_y[i] + 32 >= myPlanePosition_y + 11) && (enemyPlanePosition_y[i] <= myPlanePosition_y + 55))
			return 1;

		if ((enemyPlanePosition_x[i] + 64 >= myPlanePosition_x + 12) && (enemyPlanePosition_x[i] <= myPlanePosition_x + 128) && (enemyPlanePosition_y[i] + 32 >= myPlanePosition_y + 55) && (enemyPlanePosition_y[i] <= myPlanePosition_y + 64))
			return 1;
	}

	return 0;

}


void allMotions() /*N : All types of motions (my plane, enemy plane, 
				  missile, Bullet, etc) will be conducted by this function*/
{
	myBullet_y += barrelDiff_y;
	myBullet_x += barrelDiff_x;

	myMissile_x -= 8 + level;

	enemyBulletMotion();

	enemyPlaneMotion();   /* This function always increases
						  the x positions of enemy planes   */


}


int powerPosition_x = 1100, powerPosition_y = 200, startCycle;

void initializePower()
{
	if (cycle % 1500 == 0 && isPause == 0 && cycle > 0){
		powerPosition_x = rand() % 300 + 300;
		powerPosition_y = rand() % 300 + 100;
		startCycle = cycle;

	}

	if (cycle - startCycle > 1000 || isProtected == 1) // N :When 5 seconds is over, power will be out of the screen
														// N : When I have got the shield, also then the power is
														//out of the shield
	{
		powerPosition_x = 1000; 
		powerPosition_y = 1000;
	}
}


void drawPower()
{
	
	if (cycle % 3 == 0 && isPause == 0){
		if (radiusOfPower >= 25)
			flag = 1;
			
		if (radiusOfPower <= 12)
				flag = 0;
			
	

		if (flag == 1) radiusOfPower--;
		else if (flag == 0) radiusOfPower++;
	}


	iSetcolor(0, 1, 0);
	iFilledCircle(powerPosition_x, powerPosition_y, radiusOfPower);

	iSetcolor(1, 0, 0);
	iCircle(powerPosition_x, powerPosition_y, radiusOfPower);

	iSetcolor(1, 0, 0);
	iFilledCircle(powerPosition_x, powerPosition_y, (int)radiusOfPower / 2);

	iSetcolor(1, 1, 1);
	iText(powerPosition_x - 5, powerPosition_y - 5, "S");
	
}



int Shield_x, Shield_y;

int shieldHit = 0; // N : This will count how many times the shield is hit
					// After a certain hit the shield will disappear

void drawShield()
{
	if (shieldHit >= 10)
	{
		isProtected = 0;
	}

	if (isProtected == 1){
		Shield_x = myPlanePosition_x + 64;
		Shield_y = myPlanePosition_y + 32;
	}

	if (isProtected == 0)
	{
		Shield_x = myPlanePosition_x + 1000; // Shield will be out of screen if isProtected == 0
		Shield_y = myPlanePosition_y + 1000;
	}

	iSetcolor(0, 0, 1);
	iCircle(Shield_x, Shield_y, 90, 200);
	iCircle(Shield_x, Shield_y, 91, 200);

}

void getPower()
{
	if ((powerPosition_x + radiusOfPower >= myPlanePosition_x + 23) && (powerPosition_x - radiusOfPower <= myPlanePosition_x + 128) && (powerPosition_y + radiusOfPower >= myPlanePosition_y) && (powerPosition_y - radiusOfPower <= myPlanePosition_y + 11))
	{
		isProtected = 1;
		shieldHit = 0;
	}

	if ((powerPosition_x + radiusOfPower >= myPlanePosition_x) && (powerPosition_x - radiusOfPower <= myPlanePosition_x + 128) && (powerPosition_y + radiusOfPower >= myPlanePosition_y + 11) && (powerPosition_y - radiusOfPower <= myPlanePosition_y + 55))
	{
		isProtected = 1;
		shieldHit = 0;
	}

	if ((powerPosition_x + radiusOfPower >= myPlanePosition_x + 12) && (powerPosition_x - radiusOfPower <= myPlanePosition_x + 128) && (powerPosition_y + radiusOfPower >= myPlanePosition_y + 55) && (powerPosition_y - radiusOfPower <= myPlanePosition_y + 64))
	{
		isProtected = 1;
		shieldHit = 0;
	}
}

void dealIfEnemyBulletHitMyShield()
{
	double diff_x, diff_y;
	for (i = 1; i < 7; i++){
		diff_x = enemyBulletPosition_x[i] - Shield_x;
		diff_y = enemyBulletPosition_y[i] - Shield_y;
		if (sqrt(diff_x * diff_x + diff_y * diff_y) < 95)
		{
			enemyBulletPosition_x[i] = 1000;
			shieldHit++;
		}
	}
}

void dealIfEnemyPlaneHitMyShield()
{
	if (whichEnemyPlaneHitMyShield() == 1)
	{
		initializePlane1();
		shieldHit++;
	}

	if (whichEnemyPlaneHitMyShield() == 2)
	{
		initializePlane2();
		shieldHit++;
	}

	if (whichEnemyPlaneHitMyShield() == 3)
	{
		initializePlane3();
		shieldHit++;
	}

	if (whichEnemyPlaneHitMyShield() == 4)
	{
		initializePlane4();
		shieldHit++;
	}

	if (whichEnemyPlaneHitMyShield() == 5)
	{
		initializePlane5();
		shieldHit++;
	}

	if (whichEnemyPlaneHitMyShield() == 6)
	{
		initializePlane6();
		shieldHit++;
	}
}

int whichEnemyPlaneHitMyShield()
{
	for (i = 1; i <= 6; i++)
	{
		double diff_x, diff_y;


		diff_x = abs(enemyPlanePosition_x[i] - Shield_x);
		diff_y = abs(enemyPlanePosition_y[i] - Shield_y);
		if (diff_x * diff_x + diff_y * diff_y < 91 * 91)
		{
			return i;
		}

		diff_x = abs(enemyPlanePosition_x[i] + 64 - Shield_x);
		diff_y = abs(enemyPlanePosition_y[i] + 32 - Shield_y);
		if (diff_x * diff_x + diff_y * diff_y < 91 * 91)
		{
			return i;
		}

		diff_x = abs(enemyPlanePosition_x[i] + 64 - Shield_x);
		diff_y = abs(enemyPlanePosition_y[i] - Shield_y);
		if (diff_x * diff_x + diff_y * diff_y < 91 * 91)
		{
			return i;
		}

		diff_x = abs(enemyPlanePosition_x[i] - Shield_x);
		diff_y = abs(enemyPlanePosition_y[i] + 32 - Shield_y);
		if (diff_x * diff_x + diff_y * diff_y < 91 * 91)
		{
			return i;
		}
	}
}



void chanceOfLife()
{
	if (cycle % 2500 == 0 && cycle > 0 && isPause == 0 ){
		chanceOfLifePosition_x = 50 + rand() % 200;
		chanceOfLifePosition_y = 100 + rand() % 300;
		timerOfChanceOfLife = cycle;
	}

	if (ifLifeIsGot())
	{
		lives++;
	}

	if (cycle - timerOfChanceOfLife >= 1000 || ifLifeIsGot()) // After 6 seconds chance of Life will disappear
	{
		chanceOfLifePosition_x = 1000;
		chanceOfLifePosition_y = 1000;
	}

	






	if(cycle%3 == 0 && isPause == 0){
		if (radiusOfChanceOfLife >= 25)
			flagOfChanceOfLife = 0;

		else if (radiusOfChanceOfLife <= 12)
			flagOfChanceOfLife = 1;

		if (flagOfChanceOfLife == 0)
			radiusOfChanceOfLife--;
		else if (flagOfChanceOfLife == 1)
			radiusOfChanceOfLife++;
	}
		

	iSetcolor(0, 1, 1);
	iFilledCircle(chanceOfLifePosition_x, chanceOfLifePosition_y, radiusOfChanceOfLife);

	iSetcolor(1, 1, 1);
	iFilledCircle(chanceOfLifePosition_x, chanceOfLifePosition_y, (int)(radiusOfChanceOfLife / 2)); 

	iSetcolor(1, 0, 0);
	iCircle(chanceOfLifePosition_x, chanceOfLifePosition_y, radiusOfChanceOfLife);
	iCircle(chanceOfLifePosition_x, chanceOfLifePosition_y, (int)(radiusOfChanceOfLife / 2)); 
	
	iShowBMP(chanceOfLifePosition_x-8, chanceOfLifePosition_y-8, "lives.bmp");

}


int ifLifeIsGot()
{

	if ((chanceOfLifePosition_x + radiusOfChanceOfLife >= myPlanePosition_x + 23) && (chanceOfLifePosition_x - radiusOfChanceOfLife <= myPlanePosition_x + 128) && (chanceOfLifePosition_y + radiusOfChanceOfLife >= myPlanePosition_y) && (chanceOfLifePosition_y - radiusOfChanceOfLife <= myPlanePosition_y + 11))
	{
		return 1;
	}

	else if ((chanceOfLifePosition_x + radiusOfChanceOfLife >= myPlanePosition_x) && (chanceOfLifePosition_x - radiusOfChanceOfLife <= myPlanePosition_x + 128) && (chanceOfLifePosition_y + radiusOfChanceOfLife >= myPlanePosition_y + 11) && (chanceOfLifePosition_y - radiusOfChanceOfLife <= myPlanePosition_y + 55))
	{
		return 1;
	}

	else if ((chanceOfLifePosition_x + radiusOfChanceOfLife >= myPlanePosition_x + 12) && (chanceOfLifePosition_x - radiusOfChanceOfLife <= myPlanePosition_x + 128) && (chanceOfLifePosition_y + radiusOfChanceOfLife >= myPlanePosition_y + 55) && (chanceOfLifePosition_y - radiusOfChanceOfLife <= myPlanePosition_y + 64))
	{
		return 1;
	}

	return 0;
}


void initializeEverythingForANewGame()
{

	initializeAllPlane();
	allEnemyBulletOutOfScreen();
	lives = 3;
	gameOverCount = 0;
	cycle = 0;
	score = 0;

	powerPosition_x = 1000; // N : power is out of screen
	powerPosition_y = 1000;

	chanceOfLifePosition_x = 1000; // N : chance of life is out of screen
	chanceOfLifePosition_y = 1000;

	myMissile_x = -500; // N : My Missile is out of screen
	myMissile_y = -500;

	myBullet_x = -500; // N : My Bullet is out of screen
	myBullet_y = -500;

}




void iKeyboard(unsigned char key)  /*N: to use arrow up, down, right, left we need to use 
								   iSpeciaKeyboard(). But I can't use it */
{
	key = tolower(key);
	if (lives > 0) /*When I have no life available then I will not be able to do
				   anything*/
	{
		if (isPause == 0)
		{


			if (key == 'w')
			{
				myPlanePosition_y += 5 + level;
			}

			if (key == 's')
			{
				myPlanePosition_y -= 5 + level;
			}

			if (key == 'a')
			{
				myPlanePosition_x -= 5 + level;
			}

			if (key == 'd' && myPlanePosition_x < 800) /* N : U can't go more than 800
													   in right side*/
			{
				myPlanePosition_x += 5 + level;
			}

			if (key == ' ')
			{
				if (myMissile_x + 15 <= 0) // if missile is passed the screen, only then u can fire another one
				{
					initializeMyMissile();
				}
			}

			if (key == 'b')
			{
				if (myBullet_y <= 0 || myBullet_y >= 500 || myBullet_x <= 0 || myBullet_x >= 900) /*If myBullet creosses
																						  the screen
																						  only then I will be
																						  able to fire another
																						  Bullet*/
				{
					initializeMyBullet();
				}
			}

			if (key == 'y' && barrelAngle >= 135) /* 'y' will heighten the barrel*/
			{
				barrelAngle -= 3 + level;
			}

			if (key == 'h' && barrelAngle <= 225) /* 'h' will lower the barrel*/
			{
				barrelAngle += 3 + level;
			}

		}

		if (key == 'p') /* One can pause & unpause the game pressing p*/
		{
			isPause = !isPause;
		}
		

	}

}

void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if(playAgain(mx, my) == 1){
			initializeEverythingForANewGame();
			numberOfPlay ++;
		}

		if(Exit(mx, my) == 1)
			exit(0);

		if(help(mx, my) == 1)
			showHelp = 1;

		if(back(mx, my) == 1)
			showHelp = 0;
	}

	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		
	}
}

void iMouseMove(int mx, int my)
{
	
}

void iSpecialKeyboard(unsigned char key)
{
	
}


void iDraw()
{

	iClear();

	

	iSetcolor(1, 1, 1);
	iFilledRectangle(0, 0, 900, 500);

	iSetcolor(256, 0, 0);
	upperAndlowerFilledRectangle();
	showLivesScoreLevel();								/* This function will show the heart symbols on the upper filled rectangle   */

	produceImageOfAllPlanes();  /* This function will produce the images of all planes  */


	callEnemyPlaneIfItCrossesTheScreen();  /* If any plane crosses the screen then It will
										   come back because of this function */




	myMissile();

	myBullet();

	enemyBullet();

	initializePower();

	drawPower();

	getPower();

	drawShield();

	dealIfEnemyBulletHitMyShield();
	dealIfEnemyPlaneHitMyShield();

	chanceOfLife();
	
	

	ifMyMissileHitEnemyPlane();
	ifMyBulletHitEnemyPlane();


	

	if (ifALifeIsLost())				 // N : If my my plane is damaged, then ifALifeIsLost() will
										//return 1, otherwise 0 
	{
		lives = lives - 1; 					//N :I will decrease the lives  

		if (lives > 0)
		{
			initializeAllPlane();			//N : Here all planes are again initialized
			allEnemyBulletOutOfScreen(); 
		}
	} 


	if (isPause == 0 && lives > 0) /*When game is paused, there will be no motion*/
	{
		allMotions();
		cycle++;

	}

	if (isPause == 1)
	{
		iSetcolor(100, 0, 0);
		iText(400, 250, "PAUSE", GLUT_BITMAP_TIMES_ROMAN_24);
	}

	if (lives <= 0)  /* N : If no more lives is available the then I will call the gameOver function */
	{
		
		
		gameOver();  /* N : This function draws a red Filled Rectangle,
					 draws a bmp image of my burnt plane & show "GAME OVER" 
					 */
	}

	if(numberOfPlay == 0)
		welcome();

	if(showHelp == 1)
		instructions();


}

int main()
{
	srand(time(NULL));

	initializeAllPlane(); /* All Planes are initialized */

	allEnemyBulletOutOfScreen();
	randomizeFromWhichPositionEnemyBulletWillBeThrown_x();
		

	

	iInitialize(900, 500, "SHOOTING");


	
	return 0;
}


#include "TextureBuilder.h"
#include <stdlib.h> 
#include <glut.h>
#include <stdio.h>
#include <string>
#include <mmsystem.h>
#include <Windows.h>

int random = 0;
int currY = -5;
int currX = 0;
int stepY = 3;
int scaleX = 0;
double cameraY = 0.1;
bool start = false;
const int maximumNumber = 30;
int Xblocks[maximumNumber];
int yBlocks[maximumNumber];
int lBlock[maximumNumber];
int score = 0;
double scoreY = 0;
int count = 0;
bool gameEnd = false;
bool startSad = false;

double yPerLower = -5;
double yPerUpper = 5;


bool fallingEffect = false;

void drawWall(void);
void SetupLights(void);
void generateRandomStep(int, int, int);
void randomCases(void);
void anim(void);
void generateBlocks(void);
void charKeyboard(unsigned char, int, int);
void print(int, int, char *);
void keyboard(int, int, int);
void checkCollision();
void simulateFall();
void mouse(int, int, int, int);

double ballX = 0;
double ballY = -3.5;
bool jumped = false;
int ballJump = 4;
int fall = 0;
bool idle = true;
bool gameOver = false;

void print(int x, int y, char *string)
{
	int len, i;
	glRasterPos2f(x, y);
	len = (int)strlen(string);
	for (i = 0; i < len; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[i]);
	}
}

void charKeyboard(unsigned char key, int x, int y) {

	if (key == 'f' && (gameOver == false) && (gameEnd == false)) {
		start = true;
		ballY += ballJump;
		jumped = true;
		count++;

	}
	//jump right
	if (key == 'r' && (gameOver == false) && (gameEnd == false)) {
		start = true;
		ballY += ballJump;
		ballX -= 1;
		jumped = true;
		count++;
	}

	//jump left
	if (key == 'l' && (gameOver == false) && (gameEnd == false)) {
		start = true;
		ballY += ballJump;
		ballX += 1;
		jumped = true;
		count++;
	}
	//long jump right
	if (key == 'n' && (gameOver == false) && (gameEnd == false)) {
		start = true;
		ballY += ballJump;
		ballX -= 3.5;
		jumped = true;
		count++;
	}

	//long jump left
	if (key == 'v' && (gameOver == false) && (gameEnd == false)) {
		start = true;
		ballY += ballJump;
		ballX += 3.5;
		jumped = true;
		count++;
	}

	glutPostRedisplay();
}

void keyboard(int key, int x, int y) {
	if (key == GLUT_KEY_LEFT && ballX <= 4.5 && (gameOver == false) && (gameEnd == false)) {
		ballX += 0.2;
		
	}
		if (key == GLUT_KEY_RIGHT && ballX >= -4.5 && (gameOver == false) && (gameEnd == false)) {
			ballX -= 0.2;
		}

		glutPostRedisplay();
}
void randomCases(){

	random = rand() % 8 + 1;
	switch (random) {
	case 1: currX = 3; currY += stepY; scaleX = 3; break;
	case 2: currX = 3; currY += stepY; scaleX = 2; break;
	case 3: currX = 0; currY += stepY; scaleX = 5; break;
	case 4: currX = -2; currY += stepY; scaleX = 2; break;
	case 5: currX = 1; currY += stepY; scaleX = 5; break;
	case 6: currX = -3; currY += stepY; scaleX = 2; break;
	case 7: currX = 1; currY += stepY; scaleX = 2; break;
	case 8: currX = 4; currY += stepY; scaleX = 2; break;

	}
}

void generateRandomStep(int x, int y, int s) {
	randomCases();
	glPushMatrix();
	glColor3f(1, 1, 1);
	glTranslated(x, y, -1);
	glScaled(s, 1, 1);
	if (count <= 10) {
		static GLuint eboxTextureTwo = LoadTexture("ice.ppm", 260, 194, true);
		GLUquadricObj* esphereTwo = gluNewQuadric();
		gluQuadricTexture(esphereTwo, true);
		gluQuadricNormals(esphereTwo, GLU_SMOOTH);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, eboxTextureTwo);
		glEnable(GL_CULL_FACE);
		glEnable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
		glEnable(GL_TEXTURE_GEN_T);
		glBindTexture(GL_TEXTURE_2D, eboxTextureTwo);
		glutSolidCube(1);
		glDisable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
		glDisable(GL_TEXTURE_GEN_T);
	}
	else {
		if (count > 10 && count <= 20) {
			static GLuint eboxTextureTwo = LoadTexture("grey.ppm", 300, 300, true);
			GLUquadricObj* esphereTwo = gluNewQuadric();
			gluQuadricTexture(esphereTwo, true);
			gluQuadricNormals(esphereTwo, GLU_SMOOTH);
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, eboxTextureTwo);
			glEnable(GL_CULL_FACE);
			glEnable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
			glEnable(GL_TEXTURE_GEN_T);
			glBindTexture(GL_TEXTURE_2D, eboxTextureTwo);
			glutSolidCube(1);
			glDisable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
			glDisable(GL_TEXTURE_GEN_T);
			glutSolidCube(1);
		}
		else {
			static GLuint eboxTextureTwo = LoadTexture("marble.ppm", 267, 189, true);
			GLUquadricObj* esphereTwo = gluNewQuadric();
			gluQuadricTexture(esphereTwo, true);
			gluQuadricNormals(esphereTwo, GLU_SMOOTH);
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, eboxTextureTwo);
			glEnable(GL_CULL_FACE);
			glEnable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
			glEnable(GL_TEXTURE_GEN_T);
			glBindTexture(GL_TEXTURE_2D, eboxTextureTwo);
			glutSolidCube(1);
			glDisable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
			glDisable(GL_TEXTURE_GEN_T);
			glutSolidCube(1);
		}
	}

	glPopMatrix();
}

void generateBlocks() {
	for (int i = 0; i < maximumNumber; i++) {
		randomCases();
		Xblocks[i] = currX;
		yBlocks[i] = currY;
		lBlock[i] = scaleX;
	}
}

//in order to know where to land we need to check after I jump 
//if I increment the y given my current x will I collide with a block or not

void checkCollision() {
	int i = 0;
	for (i = 0; i < maximumNumber - 1; i++) {
		if (ballX >= (Xblocks[i] - (lBlock[i] / 2) - 0.5) && (ballX <= (Xblocks[i] + (lBlock[i] / 2) + 0.5))
			&& (ballY >= yBlocks[i] + 1) && (ballY < yBlocks[i + 1])) {
			jumped = false;
			score += 10;
			ballY -= ballY - (yBlocks[i] + 1);
			break;
		}
		else {
			if ((ballX < (Xblocks[i] - (lBlock[i] / 2) - 0.5) || (ballX >(Xblocks[i] + (lBlock[i] / 2) + 0.5)))
				&& ((ballY >= yBlocks[i] + 1) && (ballY < yBlocks[i + 1]))) {
				fallingEffect = true;
				start = false; 
				startSad = true;
				break;
			}
		}
	}
	glutPostRedisplay();
}

void anim() {
	if (start == true && (fallingEffect == false)) {
		cameraY += 0.001;
		yPerLower += 0.02;
		yPerUpper += 0.02;
		scoreY += 0.02;

		if (jumped == true) {
			PlaySound(TEXT("jump.wav"), NULL, SND_ASYNC);
			checkCollision();

		}

		if (jumped == false && ((ballX < (Xblocks[count-1] - (lBlock[count-1] / 2) - 0.5)) || (ballX >(Xblocks[count-1] + (lBlock[count-1] / 2) + 0.5)))) {
			fallingEffect = true;
			start = false;
			startSad = true;
			gameOver = true;
		}

		if (count == maximumNumber) {
			gameEnd = true;
			start = false;
			ballY = ballY - ballJump;
			PlaySound(TEXT("tada.wav"), NULL, SND_ASYNC);
		}


		if (ballY < yPerLower) {
			fallingEffect = true;
			start = false;
			gameOver = true;
			startSad = true;
		}
	}

	if (fallingEffect == true && (start == false) && yPerLower > -5){

		cameraY -= 0.001;
		yPerLower -= 0.02;
		yPerUpper -= 0.02;
		scoreY -= 0.02;
		if (ballY > -3.5)
			ballY -= 0.04;

		if (startSad == true) {
			PlaySound(TEXT("sad.wav"), NULL, SND_ASYNC);
			startSad = false;
			gameOver = true;
		}

		if (yPerLower <= -5) {
			fallingEffect = false;
			
			glPushMatrix();
			glColor3d(0, 0, 0);
			glTranslated(0, scoreY, -5);
			char * stC[100];
			sprintf((char *)stC, "Score: % i", score);
			print(4, 4, (char *)stC);
			glPopMatrix();
		}
	}

	for (int i = 0; i < 1000000; i++);

	glutPostRedisplay();
}

void draw(){
	for (int i = 0; i < maximumNumber; i++) {
		generateRandomStep(Xblocks[i], yBlocks[i], lBlock[i]);
	}
}

void displayWire(void) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-5, 5, yPerLower, yPerUpper, -5, 5);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0, 0, -5, 0, 0, 0, 0.0, cameraY, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	//BackWall
	glPushMatrix();
	glColor3f(1.0f, 1.0f, 1.0f);
	//glColor3f(0.0f, 0.0f, 1.0f);
	glTranslated(0, yPerLower, 0);
	glScaled(1, 10, 0.1);

	//static GLuint eboxTextureTwo = LoadTexture("brickstexture.ppm", 640, 480, false);
	//GLUquadricObj* esphereTwo = gluNewQuadric();
	//gluQuadricTexture(esphereTwo, true);
	//gluQuadricNormals(esphereTwo, GLU_SMOOTH);
	//glEnable(GL_TEXTURE_2D);
	//glBindTexture(GL_TEXTURE_2D, eboxTextureTwo);
	//glEnable(GL_CULL_FACE);
	//gluSphere(esphereTwo, 10, 100, 100);
	//gluDeleteQuadric(esphereTwo);
	//GLUquadricObj* esphere = gluNewQuadric();

	static GLuint eboxTextureTwo = LoadTexture("brickstexture.ppm", 512, 512, true);
	GLUquadricObj* esphereTwo = gluNewQuadric();
	gluQuadricTexture(esphereTwo, true);
	gluQuadricNormals(esphereTwo, GLU_SMOOTH);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, eboxTextureTwo);
	glEnable(GL_CULL_FACE);
	glEnable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
	glEnable(GL_TEXTURE_GEN_T);
	glBindTexture(GL_TEXTURE_2D, eboxTextureTwo);
	glutSolidCube(10);
	glDisable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
	glDisable(GL_TEXTURE_GEN_T);
	glPopMatrix();

	//ground
	glPushMatrix();
	glTranslated(0, -4.5, -1);
	glScaled(1, 0.1, 0.1);
	glColor3f(1, 0, 0);
	glutSolidCube(10);
	glPopMatrix();


	//sphere
	glPushMatrix();
	glColor3f(0.0f, 1.0f, 1.0f);
	glTranslated(ballX, ballY, -1);
	static GLuint eboxTexture = LoadTexture("Earth.ppm", 720, 360, false);
	GLUquadricObj* esphere = gluNewQuadric();
	gluQuadricTexture(esphere, true);
	gluQuadricNormals(esphere, GLU_SMOOTH);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, eboxTexture);
	glEnable(GL_CULL_FACE);
	gluSphere(esphere, 0.5, 100, 100);
	gluDeleteQuadric(esphere);

	/*glColor3d(1, 0.5, .5);*/
	glutSolidSphere(0.5, 10, 10);
	glPopMatrix();

	//tiles
	glPushMatrix();
	draw();
	glPopMatrix();

	//score
	glPushMatrix();
	glColor3d(0, 0, 0);
	glTranslated(0, scoreY, -5);
	char * stC[100];
	sprintf((char *)stC, "Score: % i", score);
	print(5, 4.5, (char *)stC);
	glPopMatrix();

	//gameover
	if (gameOver == true) {
		glPushMatrix();
		glColor3d(0, 0, 0);
		glTranslated(1, scoreY, -5);
		char * stC[100];
		sprintf((char *)stC, "Game Over");
		print(0, 0, (char *)stC);
		glPopMatrix();
	}

	if (gameEnd == true) {
		
		glPushMatrix();
		glColor3d(0, 0, 0);
		glTranslated(1, scoreY, -5);
		char * stC[100];
		sprintf((char *)stC, "YOU WON!");
		print(0, 0, (char *)stC);
		glPopMatrix();
	}
	glutSwapBuffers();
}

void mouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON || button == GLUT_RIGHT_BUTTON) {
		start = true;
	}
	glutPostRedisplay();
}

void main(int argc, char** argv)
{
	random = rand() % 8 + 1;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(200, 150);
	generateBlocks();
	glutCreateWindow("Icy Tower");
	glutDisplayFunc(displayWire);
	glEnable(GL_DEPTH_TEST);
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glutIdleFunc(anim);
	glutKeyboardFunc(charKeyboard);
	glutSpecialFunc(keyboard);
	glutMouseFunc(mouse);

	glutMainLoop();
}
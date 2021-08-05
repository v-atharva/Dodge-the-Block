#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
int flag = 0;
float YY = 650,YY1=650;
int delta =5;
int rot = 0;
int speed=0;
int CarP = 1;
int Div = 1;
int side=0;
int XX=0;
int f=800;int g=1;
int coll=0;
int score=0;
int lvl=1;
int fps = 8;
int cond=0;
static int value=0;
static int w,menu_id;
// Trajectory Equation
void init2D(float r, float g, float b)
{
	glClearColor(r,g,b,0.0);
	glMatrixMode (GL_PROJECTION);
	//gluOrtho2D (-400.0, 800.0, -400.0, 800.0);
	gluOrtho2D (0.0, 1000.0, 0.0, 1000.0);
}
void coordinate()
{
	int i=0;
	for(i=-400;i<1000;i++)
	{
		glVertex2f(i,30);
		glVertex2f(30,i);
	}// xy-axis
}
void dash()
{
	int i=0;
	for(i=-400;i<1000;i=i+50)
	{
		glVertex2f(i,20);
		glVertex2f(i,40);
		glVertex2f(20,i);
		glVertex2f(40,i);
	}// xy-axis
}//dash

void tree(int x, int y)
{

	//rest1
	glColor3f(0.1,0.7,0.4);
	glBegin(GL_POLYGON);
	{
	glVertex2f(x+115,y+45 );
	glVertex2f(x+140,y+70 );
	glVertex2f(x+130,y+100 );
	glVertex2f(x+135,y+120);
	glVertex2f(x+110,y+170);
	glVertex2f(x+70,y+120 );
	glVertex2f(x+80,y+100);
	glVertex2f(x+70,y+70);
	glVertex2f(x+90,y+45 );
	glVertex2f(x+95,y+120);
	}glEnd();
	
	//stem1
	glColor3f(0.9,0.4,0.05);
	glBegin(GL_POLYGON);
	{
	glVertex2f(x+95,y+10 );
	glVertex2f(x+105,y+10);
	glVertex2f(x+105,y+25 );
	glVertex2f(x+100,y+100);
	glVertex2f(x+95,y+25);
	}glEnd();
}

void tree1(int x, int y)
{

//rest1
glColor3f(0.1,0.8,0);
	glBegin(GL_POLYGON);
	{
	glVertex2f(x+110,y+45 );
	glVertex2f(x+150,y+70 );
	glVertex2f(x+125,y+100 );
	glVertex2f(x+140,y+120);
	glVertex2f(x+105,y+170);
	glVertex2f(x+70,y+120 );
	glVertex2f(x+85,y+100);
	glVertex2f(x+60,y+70);
	glVertex2f(x+100,y+45 );
	glVertex2f(x+105,y+120);
	}glEnd();
//stem1

	glColor3f(0.9,0.4,0.05);
	glBegin(GL_POLYGON);
	{
	glVertex2f(x+100,y+5 );
	glVertex2f(x+110,y+5 );
	glVertex2f(x+110,y+25 );
	glVertex2f(x+105,y+100);
	glVertex2f(x+100,y+25);
	}glEnd();
	}

void scoredisplay (int posx, int posy, int posz, int space_char,int scorevar,int lvl)
{
	int j=0;
	int p,k,l;
	GLvoid *font_style1 = GLUT_BITMAP_TIMES_ROMAN_24;
	//int l=0;
	l=lvl;
	p = scorevar;
	//int n=scorevar;
	j = 0;
	k = 0;
	while(p > 9)
	{
		k = p % 10;
		glRasterPos3f ((posx-(j*space_char)),posy, posz);
		glutBitmapCharacter(font_style1,48+k);
		j++;
		p /= 10;
	}

	glRasterPos3f((posx-(j*space_char)), posy, posz);
	glutBitmapCharacter(font_style1,48+p);
	glRasterPos3f((posx-(j*space_char+68)),posy+40, posz);
	glutBitmapCharacter(font_style1,48+28);
	glutBitmapCharacter(font_style1,48+21);
	glutBitmapCharacter(font_style1,48+38);
	glutBitmapCharacter(font_style1,48+21);
	glutBitmapCharacter(font_style1,48+28);
	glutBitmapCharacter(font_style1,48+100);
	glutBitmapCharacter(font_style1,48+l);
}

int Colloid()
{
	if((CarP == 1) && (YY == 110) && (side==0))
		coll = 1;
	if((CarP == 2) && (YY == 110)&& (side==1))
		coll=2;
	if(coll==1 || coll==2)
	{
		printf("Bye");
		cond=1;
		return 1;
	}
printf("Colloid %d YY%f\n",coll,YY);
return 0;
}

void mountain(int x, int y, int w)
{
	glColor3f(0.5,0.35,0.05);
	glBegin(GL_POLYGON);
	{
	glVertex2f(x+120,y+0);
	glVertex2f(x+300,y+0);
	glVertex2f(x+200,y+300);
	}glEnd();
}

void CarL1(int YY) // enemy car
{
	glColor3f(0,1,1);
	glBegin(GL_POLYGON);
    {
    glVertex2f(360,YY+30);
    glVertex2f(410,YY+30);
    glVertex2f(410,YY+120);
    glVertex2f(360,YY+120);
    }glEnd();
}
void CarR1(int YY) // enemy car
{
    XX = 170;
    glColor3f(1,1,0);
    glBegin(GL_POLYGON);
    {
    glVertex2f(XX+370,YY+30);
    glVertex2f(XX+420,YY+30);
    glVertex2f(XX+420,YY+120);
    glVertex2f(XX+370,YY+120);
    }glEnd();
}
void CarL()
{
    glColor3f(0.7,0,0);
    glBegin(GL_POLYGON);
    {
    glVertex2f(350,30);
    glVertex2f(400,30);
    glVertex2f(400,120);
    glVertex2f(350,120);
    }glEnd();

    glColor3f(0,0.3,0.6);
    glBegin(GL_POLYGON);
    {
    glVertex2f(360,40);
    glVertex2f(390,40);
    glVertex2f(390,110);
    glVertex2f(360,110);
    }glEnd();

    glColor3f(0,0.5,0.6);
    glBegin(GL_QUAD_STRIP);
    {
    glVertex2f(355,120);
    glVertex2f(395,120);
    glVertex2f(360,140);
    glVertex2f(390,140);
    }glEnd();
}

void CarR()
{
    glColor3f(0.7,0,0);
    glBegin(GL_POLYGON);
    {
    glVertex2f(540,30);
    glVertex2f(590,30);
    glVertex2f(590,120);
    glVertex2f(540,120);
    }glEnd();

    glColor3f(0,0.3,0.6);
    glBegin(GL_POLYGON);
    {
    glVertex2f(550,40);
    glVertex2f(580,40);
    glVertex2f(580,110);
    glVertex2f(550,110);
    }glEnd();

    glColor3f(0,0.5,0.6);
    glBegin(GL_QUAD_STRIP);
    {
    glVertex2f(545,120);
    glVertex2f(585,120);
    glVertex2f(550,140);
    glVertex2f(580,140);
    }glEnd();
}

void bg2()
{
int i;
    glColor3f(0,0,0.4);
    glBegin(GL_QUAD_STRIP);
    {
    glVertex2f(0,700);
    glVertex2f(1000,700);
    glVertex2f(0,1000);
    glVertex2f(1000,1000);
    }glEnd();

    glColor3f(1,1,1);
    GLfloat twicepi=2.0f*3.14;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(870,920);
    for(i=0;i<=20;i++){
    glVertex2f(870+(40*cos(i*twicepi/20)), 920+(60*sin(i*twicepi/20)));
    }glEnd();
}

void bg1()
{
    int i;
    glColor3f(0,0.5,0.8);
    glBegin(GL_QUAD_STRIP);
    {
    glVertex2f(0,700);
    glVertex2f(1000,700);
    glVertex2f(0,1000);
    glVertex2f(1000,1000);
    }glEnd();

    glColor3f(0.9,0.9,0);
    GLfloat twicepi=2.0f*3.14;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(870,920);
    for(i=0;i<=20;i++){
    glVertex2f( 870+(40*cos(i*twicepi/20)), 920+(60*sin(i*twicepi/20)));
    }glEnd();
}

void bgg1(){
    glColor3f(0.1,0.5,0);
    glBegin(GL_QUAD_STRIP);
    {
    glVertex2f(0,0);
    glVertex2f(1000,0);
    glVertex2f(0,700);
    glVertex2f(1000,700);
    }glEnd();
}

void bgg2(){
    glColor3f(0.1,0.3,0);
    glBegin(GL_QUAD_STRIP);
    {
    glVertex2f(0,0);
    glVertex2f(1000,0);
    glVertex2f(0,700);
    glVertex2f(1000,700);
    }glEnd();
}

void road1()
{
glColor3f(0,0,0);
glBegin(GL_QUAD_STRIP);
glVertex2f(160,0);
glVertex2f(750,0);
glVertex2f(350,800);
glVertex2f(600,800);
//glVertex2f(600,800);
glEnd();
//mountain(150,780,50);
tree1(235,740);
tree1(210,630);
tree(189,540);
tree1(153,400);
tree1(110,230);
tree(84,100);
tree1(55,0);
tree1(500,740);
tree(522,630);
tree1(547,530);
tree1(565,400);
tree(600,234);
tree(624,100);
tree1(643,0);
}
void road2()
{
glColor3f(0,0,0);
glBegin(GL_QUAD_STRIP);
glVertex2f(160,0);
glVertex2f(750,0);
glVertex2f(350,800);
glVertex2f(600,800);
//glVertex2f(600,800);
glEnd();
//mountain(150,780,50);
tree(235,740);
tree1(210,630);
tree1(189,540);
tree(153,400);
tree1(110,230);
tree1(84,100);
tree(55,0);
tree1(500,740);
tree1(522,630);
tree(547,530);
tree1(565,400);
tree1(600,234);
tree(624,100);
tree(643,0);
}

void Divider(int y)
{
glColor3f(1,1,1);
glBegin(GL_QUAD_STRIP);
{
glVertex2f(450,0+y);
glVertex2f(475,0+y);
glVertex2f(453,50+y);
glVertex2f(475,50+y);
}
glEnd();
}
void cloud(int x,int y,int r){
int i;
glColor4f(0.3,0.4,0.5,0.9);
GLfloat twicepi=2.0f*3.14;
glBegin(GL_TRIANGLE_FAN);
glVertex2f(x,y);
for(i=0;i<=20;i++){

glVertex2f( x+(r*cos(i*twicepi/20)), y+((r-10)*sin(i*twicepi/20)));

}glEnd();
}
void backGround()
{
tree(0,0);
tree(200,50);
tree(300,10);
tree(800,20);
//cloud(100,100);
}
void SpecialKeys(int key, int x, int y)
{
if(key == GLUT_KEY_RIGHT)
{
//XX = XX + delta;
CarP = 2;
}
else if(key == GLUT_KEY_LEFT)
{
CarP = 1;
//XX = XX - delta;
}
glutPostRedisplay();
}
void speed_control()
{
if(speed >1000 && speed < 2000)
{
fps=1;
}
else if(speed >=2000 && speed < 3000)
{
fps=1;
}
else if(speed >=3000)
{
fps=1;
}
}
void Keys(unsigned char key, int x, int y)
{
if(key == 'q')
exit(1);
}
void Timer(int value)
{
if(coll!=1)
speed++;
printf("%d fps %d",speed,fps);
glutPostRedisplay();
glutTimerFunc(fps,Timer,0);
}

void Divider1()
{
Divider(40);
Divider(160);
Divider(280);
Divider(380);
Divider(480);
Divider(570);
Divider(660);
Divider(740);
//Divider(690);
//Divider(890);
}
void Divider2()
{
Divider(1);
Divider(121);
Divider(241);
Divider(341);
Divider(441);
Divider(531);
Divider(621);
Divider(701);
//Divider(71);
//Divider(850);
//Divider(950);
}
void GameOver()
{
glRasterPos2f(350,400);
char *s = "GAME OVER\n(press Q/q to exit)";
int j=0;
while(j<strlen(s))
{
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,(char)s[j]);
j++;
}
}

void mouseClick(int button, int state, int x, int y) {
if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && x>530 && x<620 && y<410 && y>370)
flag = 1;
if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && x>530 && x<620 && y<410 && y>370)
flag = 1;
if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && x>530 && x<620 && y<470 && y>370)
flag = 1;
if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && x>530 && x<620 && y<470 && y>430)
exit(1);
if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && x>530 && x<620 && y<470 && y>430)
exit(1);
if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && x>530 && x<620 && y<470 && y>430)
exit(1);
}
void textdisplay()
{
glPushMatrix();
unsigned char title[] = "D DODGE THE BLOCK !!";
//int l = glutBitmapLength(GLUT_BITMAP_8_BY_13,firstString);
int len = strlen(title);
glTranslatef(-110,780,0);
glScalef(0.6,0.6,0);
for (int i = 0; i <=len; i++){
glutStrokeCharacter(GLUT_STROKE_ROMAN,title[i]);
}
glPopMatrix();
unsigned char string3[] = "All you gotta do is dodge the enemy block and save your car ! Are you ready to play?";
glRasterPos3f (226,700,0);
len = strlen(string3);
for (int i = 0; i < len; i++) {
glutBitmapCharacter(GLUT_BITMAP_8_BY_13, string3[i]);
}

unsigned char firstString[] = "CHOOSE THE BELOW OPTIONS TO PLAY THE GAME";
//int l = glutBitmapLength(GLUT_BITMAP_8_BY_13, firstString);
len = strlen(firstString);
glRasterPos3f (337,550,0);
for (int i = 0; i < len; i++)
{
glutBitmapCharacter(GLUT_BITMAP_9_BY_15,
firstString[i]);
}
glBegin(GL_LINE_LOOP);
{
glVertex2f(440,450);
glVertex2f(520,450);
glVertex2f(520,490);
glVertex2f(440,490);
}glEnd();
unsigned char string[] = "START";
glRasterPos3f (466,465,0);
len = strlen(string);
for (int i = 0; i < len; i++)

{

glutBitmapCharacter(GLUT_BITMAP_8_BY_13,
string[i]);
}
glBegin(GL_LINE_LOOP);
{
glVertex2f(440,390);
glVertex2f(520,390);
glVertex2f(520,430);
glVertex2f(440,430);
}glEnd();
unsigned char string2[] = "QUIT";
glRasterPos3f (466,405,0);
len = strlen(string2);
for (int i = 0; i < len; i++) {
glutBitmapCharacter(GLUT_BITMAP_8_BY_13,
string2[i]);
}
}

void display(void) {
if(flag == 0) {
//scoredisplay(30,30,0,10,0,1);
int l;
//glClear(GL_COLOR_BUFFER_BIT);
//glColor3f(1.0, 1.0, 1.0);
glColor3f(1,1,1);
textdisplay();
}
else{
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1.0, 1.0, 1.0);
if((lvl%2)==0){
bg2();
bgg2();
}
else{
bg1();
bgg1();
}
glEnable(GL_DEPTH_TEST);
speed_control();
mountain(-80,730,50);
mountain(-40,700,50);
mountain(70,710,50);
mountain(50,780,50);
tree1(50,700);
mountain(30,700,50);
mountain(-150,700,50);
tree(-70,685);
tree(-20,675);
tree1(100,675);
mountain(460,700,50);
mountain(500,720,50);
mountain(550,700,50);
glEnable(GL_BLEND);
glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
cloud(740,930,30);
cloud(765,945,30);
cloud(770,920,30);
cloud(625,930,30);

cloud(650,945,30);
cloud(670,920,30);
cloud(815,900,30);
cloud(840,915,30);
cloud(855,890,30);
//-------------------
cloud(140,940,30);
cloud(165,955,30);
cloud(170,930,30);
cloud(25,940,30);
cloud(50,965,35);
cloud(70,930,30);
cloud(215,900,30);
cloud(240,915,30);
cloud(255,890,35);
cloud(325,940,35);
cloud(350,955,30);
cloud(365,930,30);
tree(570,680);
tree1(640,680);
if(coll!=1 && cond==0) //Enemy on right and no collision
YY = YY-g;
if(speed%f==0 && cond==0)
{
YY = 650;
side = rand()%2;
//int c= 0;
score++;
if((score%5)==0){
lvl++; f=f/2;g=g*2;
}
printf("%dside",side);
}

if(coll!=1 && cond==0) //Enemy on right and no collision
YY1 = YY1-g;
if(speed%(f)==0 && cond==0)
{
YY1 = 650;
side = rand()%2;
int c= 0;
//score++;
printf("%dside",side);
}
printf("Score---%d\n",score);
//road1();
if(speed%(f/2)==0)
Div = -1*Div;
if(Div==1 && cond==0 ){
road1();
Divider1();
}
else {
road2();
Divider2();
}
if(side==0)
{
CarL1(YY);
}
else if(side==1) {
CarR1(YY);
}
if(CarP==1) //control
CarL();
else
CarR();
int p=Colloid();

if(p==1)
{
GameOver();
//exit(1);
}
if((lvl%2)==0)

glColor3f(1, 1, 1);

else

glColor3f(0, 0, 0);

scoredisplay(900, 750, 0, 10, score, lvl);
}
glFlush();
}
void main(int argc, char *argv[])
{
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (1200, 800);
glutInitWindowPosition (300, 300);
w=glutCreateWindow ("Dodge the Block");
//CreateMenu();
glClearColor(0.0, 0.0, 0.0, 0.0);
init2D(1.0, 1.0, 1.0);
glutDisplayFunc(display);
glutSpecialFunc(SpecialKeys);
glutTimerFunc(0,Timer,0);
glutMouseFunc(mouseClick);
glutKeyboardFunc(Keys);
glutMainLoop();
}

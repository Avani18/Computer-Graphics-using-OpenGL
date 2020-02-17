#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<GL/glut.h>
#include<string.h>

#define ROUND(a) ((int) (a+0.5))

int point=0;	
int arr[2][2];

void line_DDA(int xa, int ya, int xb, int yb)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0,0.0,0.0,1.0);
	int steps, k,i;
	float dx= xb-xa, dy= yb-ya;
	float xIncrement, yIncrement, x= xa, y= ya;
	
	if(abs(dx)>abs(dy))
		steps= abs(dx);
	else
		steps= abs(dy);
	xIncrement= dx/ (float) steps;
	yIncrement= dy/ (float) steps;

	glColor4f(1.0,0.0,0.0,1.0);
	glBegin(GL_POINTS);
	for(k=0;k<steps;k++)
	{
		x+=xIncrement;	
		y+=yIncrement;
		glVertex2i(ROUND(x), ROUND(y));
	}
	glEnd();
	float m= dy/dx;
	char ms[10];
	gcvt(m, 5, ms);
	glColor4f(0.0,1.0,0.0,1.0);
	glRasterPos2f(10,100);
	int len4= (int)strlen(ms);	
	for(i=0; i<len4; ++i)
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, ms[i]);
	char str1[]= "Avani Jindal";
	char str2[]= "CSE CCVT B1";
	char str3[]= "500060696";
	int len1= (int) strlen(str1);
	int len2= (int) strlen(str2);
	int len3= (int) strlen(str3);
	glColor4f(0.5,1.0,0.5,1.0);
	glRasterPos2f(-220,-220);
	for(i=0; i<len1; ++i)
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, str1[i]);
	glRasterPos2f(-220,-200);
	for(i=0; i<len2; ++i)
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, str2[i]);
	glRasterPos2f(-220,-180);
	for(i=0; i<len3; ++i)
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, str3[i]);
	glutSwapBuffers();
	glFlush();
}

void mouse(int button, int state, int x, int y)
{
	if(button== GLUT_LEFT_BUTTON && state== GLUT_DOWN)
	{
		if(point==0)
		{
			arr[0][0]= x-250;
			arr[0][1]= 250-y;
			++point;
		}
		else
		{
			arr[1][0]= x-250;
			arr[1][1]= 250-y;
			--point;
			line_DDA(arr[0][0], arr[0][1], arr[1][0], arr[1][1]);
		}
	}
}

void init()
{
	//glClearColor(1.0, 1.0, 1.0, 0.0);
	gluOrtho2D(-250,250,-250,250);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	glutCreateWindow("Line from DDA");
	init();
	glutMouseFunc(mouse);
	glutMainLoop();
	return 0;
}


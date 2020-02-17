#include<stdlib.h>
#include<GL/glut.h>
#include<math.h>
#include<stdio.h>
#define PI 3.1415926535897932
int flag =0;
int count =0;
float arrx[15];
float arry[15];
float matrix[4][3]={{10, 10, 1},{110, 10, 1},{110, 110, 1}, {10, 110, 1}};
void drawAxes();
void drawText(char*);
void translate();
void reflect();
void rotate();
void scale();
void shear();
void init(void)
{
    glClearColor(0.5, 0.5, 0.5, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-500,500,-500,500);
}
void drawText(char *string)
{
	char *c;
	glRasterPos2f(250.0, 5.0);
	for(c=string; *c!='\0';c++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
	}
}
void reflect()
{
	float A[3][3] = {{1,0,0},{0,-1,0},{0,0,1}};
	float B[4][3];
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<3;j++)
		{
			B[i][j]=0;
			for(int k=0;k<3;k++)
			{
			  B[i][j]=matrix[i][k]*A[k][j]+B[i][j];
			}
		}
	}
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			matrix[i][j] = B[i][j];
		}
	}
	glColor3f(0.5 ,0.5 ,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(B[0][0], B[0][1]);
	glVertex2f(B[1][0], B[1][1]);
	glVertex2f(B[2][0], B[2][1]);
	glVertex2f(B[3][0], B[3][1]);
	glEnd();
	glFlush();
}
void drawSquare()
{
	drawText("Avani Jindal");
	glColor3f(1.0 ,1.0 ,0.5);
	glBegin(GL_POLYGON);
	glVertex2f(matrix[0][0], matrix[0][1]);
	glVertex2f(matrix[1][0], matrix[1][1]);
	glVertex2f(matrix[2][0], matrix[2][1]);
	glVertex2f(matrix[3][0], matrix[3][1]);
	glEnd();
	glFlush();
}
void mouse(int button, int state, int x, int y)
{
  	if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
   	{
   		drawSquare();
	}
	else if(button==GLUT_RIGHT_BUTTON && state==GLUT_DOWN)
	{
		count++;
		if(count%5==0)
		translate();
		else if(count%5==1)
		reflect();
		else if(count%5==2)
		rotate();
		else if(count%5==3)
		scale();
		else if(count%5==4)
		shear();
	}
}
void shear()
{
	 int shx = 2;
  int shy = 2;
  float A[3][3] = {{1,shx,0}, {shy,1,0}, {0,0,1}};
	float B[4][3];
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<3;j++)
		{
			B[i][j]=0;
			for(int k=0;k<3;k++)
			{
			  B[i][j]=matrix[i][k]*A[k][j]+B[i][j];
			}
		}
	}
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			matrix[i][j] = B[i][j];
		}
	}
	glColor3f(1.0 ,0.5 ,0.5);
  glBegin(GL_POLYGON);
	glVertex2f(B[0][0], B[0][1]);
	glVertex2f(B[1][0], B[1][1]);
	glVertex2f(B[2][0], B[2][1]);
	glVertex2f(B[3][0], B[3][1]);
	glEnd();
	glFlush();
}
void scale()
{
	int sx = 2;
  int sy = 2;
  float A[3][3] = {{sx,0,0}, {0,sy,0}, {0,0,1}};
  float B[4][3];
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<3;j++)
		{
			B[i][j]=0;
			for(int k=0;k<3;k++)
			{
			  B[i][j]=matrix[i][k]*A[k][j]+B[i][j];
			}
		}
	}
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			matrix[i][j] = B[i][j];
		}
	}
	glColor3f(0.0 ,0.5 ,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(B[0][0], B[0][1]);
	glVertex2f(B[1][0], B[1][1]);
	glVertex2f(B[2][0], B[2][1]);
	glVertex2f(B[3][0], B[3][1]);
	glEnd();
	glFlush();
}
void translate()
{
	int tx = 200;
	int ty = 100;
	float A[3][3]={{1,0,0},{0,1,0},{tx,ty,1}};
	float B[4][3];
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<3;j++)
		{
			B[i][j]=0;
			for(int k=0;k<3;k++)
			{
			  B[i][j]=matrix[i][k]*A[k][j]+B[i][j];
			}
		}
	}
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			matrix[i][j] = B[i][j];
		}
	}
	glColor3f(0.0 ,0.5 ,0.5);
	glBegin(GL_POLYGON);
	glVertex2f(B[0][0], B[0][1]);
	glVertex2f(B[1][0], B[1][1]);
	glVertex2f(B[2][0], B[2][1]);
	glVertex2f(B[3][0], B[3][1]);
	glEnd();
	glFlush();
}
void rotate()
{
	float deg = PI/3;
  float A[3][3] = {{cos(deg),sin(deg),0},{-1*sin(deg),cos(deg), 0},{0 ,0 ,1}};
	float B[4][3];
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<3;j++)
		{
			B[i][j]=0;
			for(int k=0;k<3;k++)
			{
			  B[i][j]=matrix[i][k]*A[k][j]+B[i][j];
			}
		}
	}
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			matrix[i][j] = B[i][j];
		}
	}
	glColor3f(0.5 ,0.0 ,0.5);
	glBegin(GL_POLYGON);
	glVertex2f(B[0][0], B[0][1]);
	glVertex2f(B[1][0], B[1][1]);
	glVertex2f(B[2][0], B[2][1]);
	glVertex2f(B[3][0], B[3][1]);
	glEnd();
	glFlush();
}
void drawAxes()
{
	glLineWidth(3);
  glPointSize(2);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_LINES);
	glVertex2f(0,500);
  glVertex2f(0,-500);
  glVertex2f(-500,0);
  glVertex2f(500,0);
	glEnd();
	glFlush();
}
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(200,200);
    glutCreateWindow("2D Transformations");
    glutDisplayFunc(drawAxes);
    glutMouseFunc(mouse);
    init();
    glutMainLoop();
    return 0;
}

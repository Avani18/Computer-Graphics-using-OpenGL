#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int point=0;
int arr[2][2];

void circlePlotPoints(int x1, int y1, float x2, float y2)
{
  glColor4f(0.6,0.5,0.3,1.0);
  glBegin(GL_POINTS);
  glVertex2f(x1+x2, y1+y2);
  glVertex2f(x1-x2, y1+y2);
  glVertex2f(x1+x2, y1-y2);
  glVertex2f(x1-x2, y1-y2);
  glVertex2f(x1+y2, y1+x2);
  glVertex2f(x1-y2, y1+x2);
  glVertex2f(x1+y2, y1-x2);
  glVertex2f(x1-y2, y1-x2);
  glEnd();
}

void circle(int x1, int y1, int x2, int y2)
{
  glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0,0.0,0.0,1.0);
  float r= sqrt(((y2-y1)*(y2-y1))+((x2-x1)*(x2-x1)));
  float x=0.0f;
  float y=r;
  float p= 1-r;
  int i;
  circlePlotPoints(x1, y1, x, y);
  while(x<y)
  {
    x++;
    if(p<0)
      p+=2*x+3;
    else
    {
      y--;
      p+=2*(x-y)+5;
    }
    circlePlotPoints(x1, y1, x, y);
  }
  char ms[10];
	gcvt(r, 5, ms);
	glColor4f(0.0,1.0,0.0,1.0);
	glRasterPos2f(-450,-380);
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
	glRasterPos2f(-450,-400);
	for(i=0; i<len1; ++i)
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, str1[i]);
	glRasterPos2f(-450,-420);
	for(i=0; i<len2; ++i)
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, str2[i]);
	glRasterPos2f(-450,-440);
	for(i=0; i<len3; ++i)
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, str3[i]);
	glutSwapBuffers();
  glutSwapBuffers();
	glFlush();
}

void mouse(int button, int state, int x, int y)
{
	if(button== GLUT_LEFT_BUTTON && state== GLUT_DOWN)
	{
		if(point==0)
		{
			arr[0][0]= x-500;
			arr[0][1]= 500-y;
			++point;
		}
		else
		{
			arr[1][0]= x-500;
			arr[1][1]= 500-y;
			--point;
			circle(arr[0][0], arr[0][1], arr[1][0], arr[1][1]);
		}
	}
}

void init()
{
	gluOrtho2D(-500,500,-500,500);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1000,1000);
	glutCreateWindow("Circle using midpoint");
	init();
	glutMouseFunc(mouse);
	glutMainLoop();
	return 0;
}

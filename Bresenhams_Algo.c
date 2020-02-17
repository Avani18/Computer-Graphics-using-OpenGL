#include<stdio.h>
#include<string.h>
#include<GL/glut.h>

#include<math.h>
#define PI 3.1415926535897932384626433832795
#define MAX_CLICK 2
#define INFINITE 99999999

int k=0;
int count=0;
int numbPoint=0;
double vertex[][2];
double m[99];
double c[99];
char buffer[10];
double P0, dy, dx;

void type(char *string, double X, double Y)
{
	char *c;
	glColor3f(1.0, 1.0, 1.0);
	glRasterPos2f(X+1,Y);
	for (c=string; *c != '\0'; c++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *c);
	}
}
void myName()
{
	int i;
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

}

// function to initialize
void myInit (void)
{
	// making background color black as first
	// 3 arguments all are 0.0
	gluOrtho2D(-500,500,-500,500);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	myName();
}
int max(double a, double b){
	return a>b?0:1;
}
int min(double a, double b){
	return a<b?0:1;
}

void printXY(double X, double Y)
{
	gcvt(X,5,buffer);
	char str[20]={"( "};
	strcat(str, buffer);
	strcat(str, ", ");
	gcvt(Y,5,buffer);
	strcat(str, buffer);
	strcat(str, " )");
	type(str, X, Y);
}

void printM(double M, double X, double Y)
{
	gcvt(M,5,buffer);
	char str[20]={"m (slope) = "};
	strcat(str, buffer);
	type(str, X, Y);
}

void DrawLine()
{
	glClear(GL_COLOR_BUFFER_BIT);
	double P[2][2];
	int maxPoint, minPoint;
	for(int i=0;k<numbPoint;k++,i++)
	{
		P[i][0] = vertex[k][0];
		P[i][1] = vertex[k][1];
	}

	double m = (P[1][1] - P[0][1])/(P[1][0] - P[0][0]);
	//printf("%lf\n", m);
	//printM(m,(P[1][0]+P[0][0])/2,(P[1][1]+P[0][1])/2);

	int i;
	char ms[10];
	gcvt(m, 5, ms);
	glColor4f(0.0,1.0,0.0,1.0);
	glRasterPos2f(-450, 370);
	int len4= (int)strlen(ms);
	for(i=0; i<len4; ++i)
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, ms[i]);

	myName();

	if(m >= 0 && m <= 1)
	{
		maxPoint = max(P[0][0], P[1][0]);
		minPoint = min(P[0][0], P[1][0]);
		dx = P[maxPoint][0]-P[minPoint][0];
		dy = P[maxPoint][1]-P[minPoint][1];
		P0 = 2*dy-dx;
		for(;P[minPoint][0]<P[maxPoint][0]; P[minPoint][0]+=1)
		{
			glBegin(GL_POINTS);
			glColor3f(0.0, 0.0, 1.0);
			//printf("(%lf, %lf)\n",P[minPoint][0],P[minPoint][1]);
			if(P0 >= 0)
			{
				P[minPoint][1] += 1;
				glVertex2f(P[minPoint][0],P[minPoint][1]);
				P0 += 2*(dy-dx);
			}
			else if (P0<0)
			{
				P[minPoint][1] += 0;
				glVertex2f(P[minPoint][0],P[minPoint][1]);
				P0+=2*dy;
			}
			glEnd();
			glFlush();
		}
	}

	if(m >= -1 && m < 0)
	{
		maxPoint = max(P[0][0], P[1][0]);
		minPoint = min(P[0][0], P[1][0]);
		dx = P[maxPoint][0]-P[minPoint][0];
		dy = P[maxPoint][1]-P[minPoint][1];
		P0 = 2*dy-dx;
		for(;P[minPoint][0]<P[maxPoint][0]; P[maxPoint][0]-=1)
		{
			glBegin(GL_POINTS);
			glColor3f(0.0, 0.0, 1.0);
			//printf("(%lf, %lf)\n",P[minPoint][0],P[minPoint][1]);
			if(P0 >= 0)
			{
				P[maxPoint][1]+=1;
				glVertex2f(P[maxPoint][0],P[maxPoint][1]);
				P0 -= 2*(dy+dx);
			}
			else if (P0<0)
			{
				P[minPoint][1]+=0;
				glVertex2f(P[maxPoint][0],P[maxPoint][1]);
				P0-=2*dy;
			}
			glEnd();
			glFlush();
		}
	}

	if(m >=1 && m < INFINITE)
	{
		maxPoint = max(P[0][1], P[1][1]);
		minPoint = min(P[0][1], P[1][1]);
		dx = P[maxPoint][0]-P[minPoint][0];
		dy = P[maxPoint][1]-P[minPoint][1];
		P0 = 2*dx-dy;
		for(;P[minPoint][1]<P[maxPoint][1]; P[minPoint][1]+=1)
		{
			glBegin(GL_POINTS);
			glColor3f(0.0, 0.0, 1.0);
			//printf("(%lf, %lf)\n",P[minPoint][0],P[minPoint][1]);
			if(P0 >= 0)
			{
				P[minPoint][0]+=1;
				glVertex2f(P[minPoint][0],P[minPoint][1]);
				P0 += 2*(dx-dy);
			}
			else if (P0<0)
			{
				P[minPoint][0]+=0;
				glVertex2f(P[minPoint][0],P[minPoint][1]);
				P0+=2*dx;
			}
			glEnd();
			glFlush();
		}
	}
	if(m<= -1 && m > -INFINITE)
	{
		maxPoint = max(P[0][1], P[1][1]);
		minPoint = min(P[0][1], P[1][1]);
		dx = P[maxPoint][0]-P[minPoint][0];
		dy = P[maxPoint][1]-P[minPoint][1];
		P0 = 2*dx-dy;
		for(;P[minPoint][1]<P[maxPoint][1]; P[maxPoint][1]-=1)
		{
			glBegin(GL_POINTS);
			glColor3f(0.0, 0.0, 1.0);
			//printf("(%lf, %lf)\n",P[minPoint][0],P[minPoint][1]);
			if(P0 >= 0)
			{
				P[maxPoint][0]+=1;
				glVertex2f(P[maxPoint][0],P[maxPoint][1]);
				P0 -= 2*(dx+dy);
			}
			else if (P0<0)
			{
				P[maxPoint][0]+=0;
				glVertex2f(P[maxPoint][0],P[maxPoint][1]);
				P0-=2*dx;
			}
			glEnd();
			glFlush();
		}
	}

}

void store(double X, double Y)
{
	vertex[numbPoint][0] = X;
	vertex[numbPoint][1] = Y;
	//printf("(%.2lf, %.2lf)\n", vertex[numbPoint][0], vertex[numbPoint][1]);
	++numbPoint;
	//printf("Number of Points: %d\n",numbPoint);
	printXY(X, Y);
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POINTS);
	glVertex2f(X,Y);
	glEnd();
	glFlush();
}

void mouseClick(int button, int state, int X, int Y)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if(count<=MAX_CLICK)
		{
			store((X-500),(500-Y));
			count++;
			if(count == MAX_CLICK){
				DrawLine();
				count=0;
				//printf("Number of Line(s): %d\n",numbPoint/2);
			}
		}
	}
}
static void Key(unsigned char key, int x, int y)
{
    switch (key) {
      	case 27:
			glutDestroyWindow(1);
			break;
	}
}
int main (int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	// giving window size in X- and Y- direction
	glutInitWindowSize(1000, 1000);
	// Giving name to window
	glutCreateWindow("Line using Bresenham's Algo");
	myInit();
	glutKeyboardFunc(Key);
	glutMouseFunc(mouseClick);
	glutMainLoop();
}

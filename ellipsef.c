#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
#include<string.h>

#define ROUND(a) ((int) (a+0.5))
int point=0;
int arr[3][2];

void ellipsePlotPoints(int xCenter, int yCenter, int x, int y)
{
  glBegin(GL_POINTS);
  glColor4f(0.3,0.5,0.0,1.0);
  glVertex2f(xCenter+x, yCenter+y);
  glVertex2f(xCenter+x, yCenter-y);
  glVertex2f(xCenter-x, yCenter+y);
  glVertex2f(xCenter-x, yCenter-y);
  glEnd();
}

void ellipseMidPoint(int x1, int y1, int x2, int y2, int x3, int y3)
{
  glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0,0.0,0.0,1.0);
  int rx= sqrt(((y2-y1)*(y2-y1))+((x2-x1)*(x2-x1)));
  int ry= sqrt(((y3-y1)*(y3-y1))+((x3-x1)*(x3-x1)));
  int rx2= rx*rx;
  int ry2= ry*ry;
  int tworx2= 2*rx2;
  int twory2= 2*ry2;
  int p;
  int x=0, y=ry, px=0, py= tworx2*y, i;
  ellipsePlotPoints(x1, y1, x, y);

   //Region 1
   p= ROUND(ry2-(rx2*ry)+(0.25*rx2));
   while(px<py)
   {
     x++;
     px+= twory2;
     if(p<0)
     {
       p+=ry2+px;
     }
     else
     {
       y--;
       py-=tworx2;
       p+=ry2+px-py;
     }
     ellipsePlotPoints(x1, y1, x, y);
   }

   //Region 2
   p= ROUND(ry2*(x+0.5)*(x+0.5)+ rx2*(y-1)*(y-1)- rx2*ry2);
   while(y>0)
   {
     y--;
     py-= tworx2;
     if(p>0)
     {
       p+=rx2-py;
     }
     else
     {
       x++;
       px+=twory2;
       p+=rx2-py+px;
     }
     ellipsePlotPoints(x1, y1, x, y);
   }
   char rxc[10], ryc[10];
 	gcvt(rx, 5, rxc);
  gcvt(ry, 5, ryc);
 	glColor4f(0.0,1.0,0.0,1.0);
 	glRasterPos2f(-450,-380);
  glPointSize(2);
  int len5= (int)strlen(rxc);
  for(i=0; i<len5; ++i)
 		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, rxc[i]);
  glRasterPos2f(-450,-390);
 	int len4= (int)strlen(ryc);
 	for(i=0; i<len4; ++i)
 		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, ryc[i]);
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
		else if(point==1)
		{
			arr[1][0]= x-500;
			arr[1][1]= 500-y;
			++point;
		}
    else
    {
      arr[2][0]= x-500;
      arr[2][1]= 500-y;
      point=0;
      ellipseMidPoint(arr[0][0], arr[0][1], arr[1][0], arr[1][1], arr[2][0], arr[2][1]);
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

#include<stdlib.h>
#include<GL/glut.h>
#include<math.h>
#include<stdio.h>
#include<string.h>

int count =0;
float r=0;
float arrx[5];
float arry[5];
double xmax=400, ymax=400, xmin=100, ymin=100;
double xfi,yfi, xff, yff;

void init(void)
{
    glClearColor(0.5, 0.5, 0.5, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,500,0,500);
}

int regioncode(float x,float y)
{
    int c=0;
    if(y>ymax)c=8;
    if(y<ymin)c=4;
    if(x>xmax)c=c|2;
    if(x<xmin)c=c|1;
    return c;
}

void radiusDisplay(float r)
{
  char bufr[50];
  gcvt(r, 10, bufr);
  char *c;
  glRasterPos2f(10,40);
  for(c = bufr; *c!='\0';c++)
  {
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, *c);
  }
  glFlush();
}

void cohenfunc(){
      double x1=0, x2=0, y1=0, y2=0;
      x1 = arrx[count-2];
      y1 = 500-arry[count-2];
      x2 = arrx[count-1];
      y2 = 500-arry[count-1];
      if(x1>xmin && x2<xmax && y1>ymin && y2<ymax)
      {
        printf("in\n");
        glBegin(GL_LINES);
        glColor3f(0.5, 0.0, 0.9);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
        glEnd();
      }
      glFlush();
      glColor4f(0.0,0.5,1.0,0.0);
      glBegin(GL_POLYGON);
      for(double i=0; i<2*3.14; i+=(2*3.14)/100)
      {
        glVertex2f((arrx[count-1])+cos(i)*3, (500-arry[count-1])+sin(i)*3);
      }
      glEnd();
      glFlush();
      glBegin(GL_POLYGON);
      for(double i=0; i<2*3.14; i+=(2*3.14)/100)
      {
        glVertex2f((arrx[count-2])+cos(i)*3, (500-arry[count-2])+sin(i)*3);
      }
      glEnd();
      glFlush();
      int c1=regioncode(x1,y1);
      int c2=regioncode(x2,y2);
      float m=(y2-y1)/(x2-x1);
      while((c1|c2)>0)
      {
          if((c1 & c2)>0)
          {
             exit(0);
          }
      float xi=x1;float yi=y1;
      int c=c1;
      if(c==0)
      {
           c=c2;
           xi=x2;
           yi=y2;
      }
      float x,y;
      if((c & 8)>0)
      {
         y=ymax;
         x=xi+ 1.0/m*(ymax-yi);
      }
      else
        if((c & 4)>0)
        {
            y=ymin;
            x=xi+1.0/m*(ymin-yi);
        }
        else
         if((c & 2)>0)
         {
             x=xmax;
             y=yi+m*(xmax-xi);
         }
         else
         if((c & 1)>0)
         {
             x=xmin;
             y=yi+m*(xmin-xi);
         }

         if(c==c1)
         {
             xfi=x;
             yfi=y;
             c1=regioncode(xfi,yfi);
         }
         if(c==c2)
         {
             xff=x;
             yff=y;
             c2=regioncode(xff,yff);
         }
  }
  glColor3f(1.0,0.0,0.0);
  glBegin(GL_LINES);
  glVertex2i(xfi,yfi);
  glVertex2i(xff,yff);
  glEnd();
  glFlush();
}


void coordinates(int button, int state, int x, int y)
{
  if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
  {
    arrx[count]=x;
    arry[count]=y;
    count= count+1;
    if(count%2==0)
    {
        cohenfunc();
    }
  }
}

void displayWindow(void)
{
  glClear(GL_COLOR_BUFFER_BIT);
  int i;
  char str1[]= "Avani Jindal";
  char str2[]= "CSE CCVT B1";
  char str3[]= "500060696";
  int len1= (int) strlen(str1);
  int len2= (int) strlen(str2);
  int len3= (int) strlen(str3);
  glColor4f(0.0,0.0,0.0,1.0);
  glPointSize(3.0);
  glRasterPos2f(380,80);
  for(i=0; i<len1; ++i)
    glutBitmapCharacter(GLUT_BITMAP_8_BY_13, str1[i]);
  glRasterPos2f(380,60);
  for(i=0; i<len2; ++i)
    glutBitmapCharacter(GLUT_BITMAP_8_BY_13, str2[i]);
  glRasterPos2f(380,40);
  for(i=0; i<len3; ++i)
    glutBitmapCharacter(GLUT_BITMAP_8_BY_13, str3[i]);
	glColor3f(0.0, 1.0, 1.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(xmin,ymin);
	glVertex2f(xmin,ymax);
	glVertex2f(xmax,ymax);
	glVertex2f(xmax, ymin);
	glEnd();
	glFlush();
}

int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(200,200);
    glutCreateWindow("Line Clipping using Cohen Sutherland Algorithm");
    glutDisplayFunc(displayWindow);
    glutMouseFunc(coordinates);
    init();
    glutMainLoop();
    return 0;
}

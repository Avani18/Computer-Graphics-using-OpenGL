#include<stdlib.h>
#include<GL/glut.h>
#include<math.h>
#include<stdio.h>
void displayWindow();
void drawLine();
int count =0;
float arrx[5];
float arry[5];
double p[4],q[4];
double xmin=200, ymin=200, xmax=500, ymax=400;
double xi,yi, xf, yf;

void init(void)
{
    glClearColor(0.5, 0.5, 0.5, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,640,0,480);
}
void drawText(char *string)
{
	char *c;
	glRasterPos2f(350.0, 5.0);
	for(c=string; *c!='\0';c++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
	}
}
void drawLine()
{
    float x1,x2,y1,y2;
    x1 = arrx[count-2];
    y1 = arry[count-2];
    x2 = arrx[count-1];
    y2 = arry[count-1];
    glColor4f(0.0,0.5,1.0,0.0);
    glBegin(GL_POLYGON);
    for(double i=0; i<2*3.14; i+=(2*3.14)/60)
    {
      glVertex2f((arrx[count-1])+cos(i)*3, (arry[count-1])+sin(i)*3);
    }
    glEnd();
    glFlush();

    glBegin(GL_POLYGON);
    for(double i=0; i<2*3.14; i+=(2*3.14)/60)
    {
      glVertex2f((arrx[count-2])+cos(i)*3, (arry[count-2])+sin(i)*3);
    }
    glEnd();
    glFlush();
	glColor3f(0,0,0.0);
	glBegin(GL_LINES);
	glVertex2f(x1,y1);
	glVertex2f(x2,y2);
	glEnd();
	glFlush();
    double dx = x2-x1;
    double dy = y2-y1;
    double t1=0, t2=1, t;
    p[0] = -dx;
    q[0] = x1 - xmin;
  	p[1] = dx;
  	q[1] = xmax - x1;
  	p[2] = -dy;
  	q[2] = y1 - ymin;
  	p[3] = dy;
  	q[3] = ymax - y1;
    for(int i=0; i<4; i++)
  	{
  		if(p[i]==0 && q[i]<0)
  		{
  			break;
  		}

  		if(p[i]<0)
  		{
  			t = (q[i]) / (p[i]);
  			if(t>t1 && t<t2)
  			{
  				t1 = t;
  			}
  		}
  		if(p[i]>0)
  		{
  			t = (q[i]) / (p[i]);
  			if(t>t1 && t<t2)
  			{
  				t2 = t;
  			}
  		}
  	}
  	if(t1<t2)
  	{
  		 xi = x1 + t1*dx;
  		 yi = y1 + t1*dy;
  		 xf = x1 + t2*dx;
  		 yf = y1 + t2*dy;
            if(xi>=xmin && xf<=xmax && yi>=ymin && yf<=ymax)
            {
              glBegin(GL_LINES);
              glColor3f(0.7, 0.6, 0.2);
              glVertex2f(xi, yi);
              glVertex2f(xf, yf);
            }
          glEnd();
          glFlush();

          glColor4f(0.0,1.0,0.0,0.0);
          glBegin(GL_POLYGON);
          for(double i=0; i<2*3.14; i+=(2*3.14)/100)
          {
            glVertex2f(xf+cos(i)*3, yf+sin(i)*3);
          }
          glEnd();
          glFlush();

          glColor4f(0.0,1.0,0.0,0.0);
          glBegin(GL_POLYGON);
          for(double i=0; i<2*3.14; i+=(2*3.14)/100)
          {
            glVertex2f(xi+cos(i)*3, yi+sin(i)*3);
          }
          glEnd();
          glFlush();
      }
  }

void mouse(int button, int state, int x, int y)
{
	y=480-y;
  if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
  {
    arrx[count]=x;
    arry[count]=y;
    count++;
    if(count%2==0)
    {
        drawLine();
    }
  }
}

void displayWindow()
{
  glClear(GL_COLOR_BUFFER_BIT);
	glColor4f(0.6,0.3,0.3,1);
	glLineWidth(3);
  glPointSize(2);
	glBegin(GL_LINE_LOOP);
	glVertex2f(xmin,ymin);
	glVertex2f(xmin,ymax);
	glVertex2f(xmax,ymax);
	glVertex2f(xmax, ymin);
	glEnd();
	glFlush();
	drawText("Avani Jindal \n 500060696 ");
}

int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(200,200);
    glutCreateWindow("Liang Barsky Line Clipping Algorithm");
    glutDisplayFunc(displayWindow);
    glutMouseFunc(mouse);
    init();
    glutMainLoop();
    return 0;
}

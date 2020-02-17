#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <time.h>
#include <cstring>

#define PENTAGON 1
#define HEXAGON 2
#define BARNSLEY 3

GLsizei wh = 500, ww = 500;
int option = PENTAGON;
int points=5000;
int x1,y1;
int move_init=1;
int lastX=0,lastY=0;

void myReshape(GLsizei w, GLsizei h)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, (GLdouble)w, 0.0, (GLdouble)h, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glViewport(0,0,w,h);
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
    ww = w;
    wh = h;
}

void mouseMove(int x, int y)
{
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   int dx = x1-x;
   int dy = y1-y;
   gluOrtho2D( dx, dx + ww, -dy, -dy + wh);
   glMatrixMode(GL_MODELVIEW);
   glutPostRedisplay();
}

int number(void)
{
   int x=0;
   srand ( time(NULL) );
   x = rand();
   x = x%9+1;
   return x;
}

void myinit(void)
{
  glClearColor(0.5, 0.5, 0.5, 1.0);
  glClear(GL_COLOR_BUFFER_BIT);
      switch (number())
      {
            case 1:
                glColor3f(1.0,0.0,0.0);
                break;
            case 2:
                glColor3f(0.0,1.0,0.0);
                break;
            case 3:
                glColor3f(0.0,0.0,1.0);
                break;
            case 4:
                glColor3f(1.0,1.0,0.0);
                break;
            case 5:
                glColor3f(1.0,0.0,1.0);
                break;
            case 6:
                glColor3f(0.0,1.0,1.0);
                break;
            case 7:
                glColor3f(1.0,0.5,1.0);
                break;
            case 8:
                glColor3f(0.5,1.0,0.5);
                break;
            default:
                glColor3f(0,0,0);
                break;
      }
      glMatrixMode(GL_PROJECTION);
      glLoadIdentity();
      gluOrtho2D(0.0, 500.0, 0.0, 500.0);
      glMatrixMode(GL_MODELVIEW);
}

void hexagon(void)
{
    typedef GLfloat point2[3];
    point2 vertices[6]={{250,500},{500,370},{500,120},{250,0},{0,120},{0,370}};
    int j, k;
    int rand();
    point2 p ={0.0,50.0};
    glClear(GL_COLOR_BUFFER_BIT);
    for( k=0; k<points; k++)
    {
         j=rand()%6;
         p[0] = (p[0]+vertices[j][0])*(1.0/3.0);
         p[1] = (p[1]+vertices[j][1])*(1.0/3.0);
          glBegin(GL_POINTS);
               glVertex2fv(p);
          glEnd();
    }
     glFlush();
     glutSwapBuffers();
}

void pentagon( void )
{
    typedef GLfloat point2[2];
    point2 vertices[5]={{100,0},{400,0},{495,300},{250,480},{5,300}};
    point2 vertices1[5]={{100-150,0+480},{400-150,0+480},{495-150,300+480},{250-150,480+480},{5-150,300+480}};
    point2 vertices2[5]={{100+490,0},{400+490,0},{495+490,300},{250+490,480},{5+490,300}};
    point2 vertices3[5]={{100+640,0+480},{400+640,0+480},{495+640,300+480},{250+640,480+480},{5+640,300+480}};
    point2 vertices4[5]={{100+245,0+780},{400+245,0+780},{495+245,300+780},{250+245,480+780},{5+245,300+780}};

    int j, k;
    int rand();
    point2 p ={0.0,50.0};
    glClear(GL_COLOR_BUFFER_BIT);
    for( k=0; k<points; k++)
    {
         j=rand()%5;
         p[0] = (p[0]+vertices[j][0])*(3.0/8.0);
         p[1] = (p[1]+vertices[j][1])*(3.0/8.0);
          glBegin(GL_POINTS);
               glVertex2fv(p);
          glEnd();
     }
     for( k=0; k<points; k++)
     {
          j=rand()%5;
          p[0] = (p[0]+vertices1[j][0])*(3.0/8.0);
          p[1] = (p[1]+vertices1[j][1])*(3.0/8.0);
           glBegin(GL_POINTS);
                glVertex2fv(p);
           glEnd();
      }
      for( k=0; k<points; k++)
      {
           j=rand()%5;
           p[0] = (p[0]+vertices2[j][0])*(3.0/8.0);
           p[1] = (p[1]+vertices2[j][1])*(3.0/8.0);
            glBegin(GL_POINTS);
                 glVertex2fv(p);
            glEnd();
       }
       for( k=0; k<points; k++)
       {
            j=rand()%5;
            p[0] = (p[0]+vertices3[j][0])*(3.0/8.0);
            p[1] = (p[1]+vertices3[j][1])*(3.0/8.0);
             glBegin(GL_POINTS);
                  glVertex2fv(p);
             glEnd();
        }
        for( k=0; k<points; k++)
        {
             j=rand()%5;
             p[0] = (p[0]+vertices4[j][0])*(3.0/8.0);
             p[1] = (p[1]+vertices4[j][1])*(3.0/8.0);
              glBegin(GL_POINTS);
                   glVertex2fv(p);
              glEnd();
         }
     // for(k=0; k<points; k++)
     // {
     //      j=rand()%5;
     //      p[0] = (p[0]+vertices1[j][0])*(3.0/8.0);
     //      p[1] = (p[1]+vertices1[j][1])*(3.0/8.0);
     //       glBegin(GL_POINTS);
     //            glVertex2fv(p);
     //       glEnd();
     //  }
     glFlush();
     glutSwapBuffers();
 }

void barnsleyFern(void)
{
	typedef GLfloat point2[2];
	point2 p = {0.0,50.0},newPoint;
	double probability[3] = {85, 92, 99};
	glClear ( GL_COLOR_BUFFER_BIT );
  for(int i=0; i<points; i++)
	{
	   GLfloat prevx=p[0];
	   GLfloat randnum=rand()%100 +1;
	   if (randnum<probability[0])
     {
            p[0]=p[0]*0.85+0.04*p[1];
            p[1]=prevx*(-0.04)+0.85*p[1]+1.6;
	   }
	   else if(randnum<probability[1])
	   {
            p[0]=0.2*p[0]-0.26*p[1];
            p[1]=0.23*prevx+0.22*p[1]+1.6;
	   }
	   else if(randnum<probability[2])
	   {
            p[0]=-0.15*p[0]+0.28*p[1];
            p[1]=0.26*prevx+0.24*p[1]+0.44;
	   }
	   else
	   {
            p[0]=0.0;
            p[1]=0.16*p[1];
	   }

	   newPoint[0]=p[0]*50+250;
	   newPoint[1]=p[1]*50;
	   if(i>100)
	   {
		  glBegin(GL_POINTS);
      glVertex2fv(newPoint);
      glEnd();
	   }
  }
	glFlush ( );
	glutSwapBuffers();
}

void myDisplay()
{
    switch(option)
    {
        case PENTAGON:
            pentagon();
            break;
        case HEXAGON:
            hexagon();
            break;
        case BARNSLEY:
            barnsleyFern();
            break;
    }
}

void menu (int id)
{
    switch(id)
    {
        case 1:
            points=100000;
            break;
        case 2:
            points=200000;
            break;
        case 3:
            option = PENTAGON;
            break;
        case 4:
            option = HEXAGON;
            break;
        case 5:
            option = BARNSLEY;
            break;
        case 6:
            exit(0);
            break;
    }
    glutPostRedisplay();
}

void mouseFunc(int button,int state,int x,int y){
	   if(button==GLUT_LEFT_BUTTON){
		   if(state==GLUT_DOWN&&move_init){
		      x1=x-lastX;
		      y1=y+lastY;
		      move_init = 0;
		    }
		    else
            {
                move_init = 1;
                lastX=-x1+x;
                lastY=y1-y;
            }
	   }
}

int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(ww,wh);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Fractals");
    glutDisplayFunc(myDisplay);
    glutCreateMenu(menu);
    glutAddMenuEntry("100000 points", 1);
    glutAddMenuEntry("200000 points", 2);
    glutAddMenuEntry("Pentagon", 3);
    glutAddMenuEntry("Hexagon", 4);
    glutAddMenuEntry("Barnsley Fern", 5);
    glutAddMenuEntry("Quit", 6);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutMouseFunc(mouseFunc);
    glutMotionFunc(mouseMove);
    myinit();
    glutReshapeFunc (myReshape);
    glutMainLoop();
    return 0;
}

#include <GL/glut.h>
#include<string.h>
#define MAX_CPTS  25

void keyboard(unsigned char key, int x, int y);
GLfloat cpts[MAX_CPTS][3];
int ncpts = 0;
static int width = 500, height = 500;

void drawCurves()
{
    int i;
    for(i=0; i<ncpts-3; i +=3)
    {
        glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, cpts[i]);
        glMapGrid1f(30, 0.0, 1.0);
        glEvalMesh1(GL_LINE, 0, 30);
    }
    glFlush();
}

void display()
{
    int i;
    glClearColor(0.5, 0.5, 0.5, 1.0);
		glClear(GL_COLOR_BUFFER_BIT);
		char str1[]= "Avani Jindal";
		char str2[]= "CSE CCVT B1";
		char str3[]= "500060696";
		int len1= (int) strlen(str1);
		int len2= (int) strlen(str2);
		int len3= (int) strlen(str3);
		glColor4f(0.0,0.0,0.0,1.0);
		glPointSize(3.0);
		glRasterPos2f(0,0);
		for(i=0; i<len1; ++i)
			glutBitmapCharacter(GLUT_BITMAP_8_BY_13, str1[i]);
		glRasterPos2f(10,-20);
		for(i=0; i<len2; ++i)
			glutBitmapCharacter(GLUT_BITMAP_8_BY_13, str2[i]);
		glRasterPos2f(20,-40);
		for(i=0; i<len3; ++i)
			glutBitmapCharacter(GLUT_BITMAP_8_BY_13, str3[i]);
    glBegin(GL_POINTS);
    for (i = 0; i < ncpts; i++)
        glVertex3fv(cpts[i]);
    glEnd();
    glFlush();
}

void mouse(int button, int state, int x, int y)
{
    float wx, wy;
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
       wx = (2.0 * x) / (float)(width - 1) - 1.0;
       wy = (2.0 * (height - 1 - y)) / (float)(height - 1) - 1.0;
       if (ncpts == MAX_CPTS) return;
       cpts[ncpts][0] = wx;
       cpts[ncpts][1] = wy;
       cpts[ncpts][2] = 0.0;
       ncpts++;
       glColor3f(0.0, 0.0, 0.0);
       glPointSize(5.0);
       glBegin(GL_POINTS);
       glVertex3f(wx, wy, 0.0);
       glEnd();
       glFlush();
    }
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 'q': case 'Q':
            exit(0);
            break;
        case 'c': case 'C':
            ncpts = 0;
            glutPostRedisplay();
            break;
        case 'e': case 'E':
            glutPostRedisplay();
            break;
        case 'b': case 'B':
            drawCurves();
            break;
    }
}

void reshape(int w, int h)
{
    width = w;
    height = h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glViewport(0, 0, w, h);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(width, height);
    glutCreateWindow("Bezier Curve");
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(reshape);
    glColor3f(0.0, 0.0, 0.0);
    glPointSize(5.0);
    glEnable(GL_MAP1_VERTEX_3);
    glutMainLoop();
}

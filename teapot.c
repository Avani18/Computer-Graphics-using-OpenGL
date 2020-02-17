#include <string.h>
#include <GL/glut.h>
static int window;
static int menu_id;
static int submenu_id;
static int value = 0;
GLdouble size= 100;
void menu(int num){
  if(num == 0){
    glutDestroyWindow(window);
    exit(0);
  }else{
    value = num;
  }
  glutPostRedisplay();
}
void createMenu(void){     submenu_id = glutCreateMenu(menu);
    glutAddMenuEntry("Sphere", 2);
    glutAddMenuEntry("Cone", 3);
    glutAddMenuEntry("Cube", 4);
    glutAddMenuEntry("Teapot", 5);     menu_id = glutCreateMenu(menu);
    glutAddMenuEntry("Clear", 1);
    glutAddSubMenu("Draw", submenu_id);
    glutAddMenuEntry("Quit", 0);     glutAttachMenu(GLUT_RIGHT_BUTTON);
}
void display(void){
  glClearColor(0.5, 0.5, 0.5, 1.0);
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
  glRasterPos2f(150,100);
  for(i=0; i<len1; ++i)
    glutBitmapCharacter(GLUT_BITMAP_8_BY_13, str1[i]);
  glRasterPos2f(150,80);
  for(i=0; i<len2; ++i)
    glutBitmapCharacter(GLUT_BITMAP_8_BY_13, str2[i]);
  glRasterPos2f(150,60);
  for(i=0; i<len3; ++i)
    glutBitmapCharacter(GLUT_BITMAP_8_BY_13, str3[i]);
  if(value == 1){
    return;
  }else if(value == 2){
    glPushMatrix();
    glColor3d(1.0, 0.5, 0.5);
    glutWireSphere(0.5, 50, 50);
    glPopMatrix();
  }else if(value == 3){
    glPushMatrix();
    glColor3d(1.0, 1.0, 0.0);
    glRotated(65, -1.0, 0.0, 0.0);
    glutWireCone(0.5, 1.0, 50, 50);
    glPopMatrix();
  }else if(value == 4){
    glEnable(GL_DEPTH_TEST);
    glPushMatrix();
    glColor3d(0.5, 0.0, 1.0);
    glutWireCube(1.0);
    glPopMatrix();
  }else if(value == 5){
    glPushMatrix();
    glColor3d(0.7, 0.0, 1.0);
    glutSolidTeapot(0.5);
    glPopMatrix();
  }
  glFlush();
}
int main(int argc, char **argv){     glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    window = glutCreateWindow("Cone, Cube, Sphere and Teapot");
    createMenu();     glClearColor(0.0,0.0,0.0,0.0);
    glutDisplayFunc(display);     glutMainLoop();
    return EXIT_SUCCESS;
}

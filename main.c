#include <stdio.h>
#include <stdlib.h>
#include <GL/freeglut.h>

void drawStrokeText(char *string, int x, int y, int z)
{
    glPushMatrix();
    glTranslatef(x,y+8,z);
    glScalef(0.2f,0.2f,z);
    glutStrokeString(GLUT_STROKE_ROMAN, (unsigned char*)string);
    glPopMatrix();
}

void drawBitmapText1(char *string, float x, float y)
{
    char *c;
    glRasterPos2f(x,y);
    for (c=string; *c != '\0'; c++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*c);
    }
}

void init()
{
        glClearColor(0.0,0.0,0.0,0.0);
}

void reshape(int w,int h)
{
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,500.0,0,500.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void render(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glColor3f(0.5,1.0,0.5);
    drawStrokeText("Women's Safety",160,400,0);
    drawBitmapText1("A short animation story",215,380);
    drawBitmapText1("Done by-",235,200);
    drawBitmapText1("Chehak Nayar",140,150);
    drawBitmapText1("K V Bhavana",140,120);
    drawBitmapText1("1PE15CS042",310,150);
    drawBitmapText1("1PE15CS063",310,120);
    glutSwapBuffers();
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(1000,1000);
    glutInitWindowPosition(0,0);
    glutCreateWindow("CG Project");
    glutDisplayFunc(render);
    glutIdleFunc(render);
    glutReshapeFunc(reshape);
    //glutFullScreen();
    init();
    glutMainLoop();
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <GL/freeglut.h>
int screen = 0;
void drawStrokeText(char *string, int x, int y, int z)
{
    glPushMatrix();
    glTranslatef(x,y+8,z);
    glScalef(0.33f,0.33f,z);
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

void mouse(int btn,int state,int x,int y)
{
    if(btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        screen = 1;
        glutPostRedisplay();
    }
}
void first_screen()
{
    glColor3f(1.0,0.5,0.0);
    drawStrokeText("Women's Safety",360,500,0);
    drawBitmapText1("A short animation story",430,470);
    glColor3f(1.0,1.0,1.0);
    drawBitmapText1("Done by-",480,200);
    drawBitmapText1("Chehak Nayar",300,150);
    drawBitmapText1("K V Bhavana",300,120);
    drawBitmapText1("1PE15CS042",610,150);
    drawBitmapText1("1PE15CS063",610,120);
    glColor3f(0.0,1.0,0.0);
    drawBitmapText1("Press left mouse button to move to next screen",580,20);
}

void bus_stop()
{
//ground
    glColor3ub(100,100,100);
    glBegin(GL_POLYGON);
        glVertex3i(340-200,400,-110);
        glVertex3i(680-200,400,-110);
        glVertex3i(710-200,430,-240);
        glVertex3i(370-200,430,-240);
    glEnd();
    glColor3ub(100,100,100);
    glBegin(GL_POLYGON);
        glVertex3i(340-200,400,-110);
        glVertex3i(680-200,400,-110);
        glVertex3i(680-200,380,-110);
        glVertex3i(340-200,380,-110);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex3i(680-200,400,-110);
        glVertex3i(710-200,430,-240);
        glVertex3i(710-200,410,-240);
        glVertex3i(680-200,380,-110);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex3i(710-200,430,-240);
        glVertex3i(710-200,410,-240);
        glVertex3i(370-200,410,-240);
        glVertex3i(370-200,430,-240);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex3i(370-200,410,-240);
        glVertex3i(370-200,430,-240);
        glVertex3i(340-200,400,-110);
        glVertex3i(340-200,380,-110);
    glEnd();
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_LINE_STRIP);
        glVertex3i(340-200,400,-110);
        glVertex3i(680-200,400,-110);
        glVertex3i(710-200,430,-240);
    glEnd();
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_LINE_STRIP);
        glVertex3i(680-200,400,-110);
        glVertex3i(680-200,380,-110);
    glEnd();

// left screen
    glColor3ub(10,50,80);
    glBegin(GL_POLYGON);
        glVertex3i(370-200,540,-140);
        glVertex3i(400-200,555,-200);
        glVertex3i(400-200,420,-200);
        glVertex3i(370-200,410,-140);
    glEnd();

// mid screen
    glColor3ub(100,100,100);
    glBegin(GL_POLYGON);
        glVertex3i(395-200,510,-200);
        glVertex3i(690-200,510,-200);
        glVertex3i(690-200,450,-200);
        glVertex3i(395-200,450,-200);
    glEnd();
    glColor3f(0,0,0);
    glBegin(GL_LINES);
        glVertex3i(395-200,510,-200);
        glVertex3i(690-200,510,-200);
        glVertex3i(690-200,450,-200);
        glVertex3i(395-200,450,-200);
    glEnd();

//right screen
    glColor3ub(10,50,80);
    glBegin(GL_POLYGON);
        glVertex3i(690-200,555,-200);
        glVertex3i(670-200,540,-140);
        glVertex3i(670-200,405,-140);
        glVertex3i(690-200,420,-200);
    glEnd();

//chair
    glColor3ub(80,80,80);
    glBegin(GL_POLYGON);
        glVertex3i(425-200,460,-180);
        glVertex3i(520-200,460,-180);
        glVertex3i(500-200,445,-150);
        glVertex3i(405-200,445,-150);
    glEnd();

    glColor3ub(80,80,80);
    glBegin(GL_LINES);
        glVertex3i(425-200,445,-160);
        glVertex3i(425-200,410,-160);
        glVertex3i(437-200,445,-170);
        glVertex3i(437-200,417,-170);
    glEnd();

    glColor3ub(80,80,80);
    glBegin(GL_LINES);
        glVertex3i(485-200,445,-163);
        glVertex3i(485-200,410,-163);
        glVertex3i(495-200,445,-170);
        glVertex3i(495-200,417,-170);
    glEnd();

 //2nd  chair
    glColor3ub(80,80,80);
    glBegin(GL_POLYGON);
        glVertex3i(560-200,460,-180);
        glVertex3i(655-200,460,-180);
        glVertex3i(635-200,445,-150);
        glVertex3i(540-200,445,-150);
    glEnd();

    glColor3ub(80,80,80);
    glBegin(GL_LINES);
        glVertex3i(560-200,445,-160);
        glVertex3i(560-200,410,-160);
        glVertex3i(572-200,445,-170);
        glVertex3i(572-200,417,-170);
    glEnd();

    glColor3ub(80,80,80);
    glBegin(GL_LINES);
        glVertex3i(620-200,445,-163);
        glVertex3i(620-200,410,-163);
        glVertex3i(630-200,445,-170);
        glVertex3i(630-200,417,-170);
    glEnd();

//roof
    glColor3ub(10,50,80);
    glBegin(GL_POLYGON);
        glVertex3i(350-200,550,-120);
        glVertex3i(700-200,550,-120);
        glVertex3i(700-200,530,-120);
        glVertex3i(350-200,530,-120);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3i(350-200,550,-120);
        glVertex3i(700-200,550,-120);
        glVertex3i(720-200,570,-240);
        glVertex3i(380-200,570,-240);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3i(700-200,550,-120);
        glVertex3i(720-200,570,-240);
        glVertex3i(720-200,550,-240);
        glVertex3i(700-200,530,-120);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3i(350-200,530,-120);
        glVertex3i(350-200,550,-120);
        glVertex3i(380-200,570,-240);
        glVertex3i(380-200,550,-240);
    glEnd();

    glColor3f(1.0,1.0,1.0);
    glBegin(GL_LINES);
        glVertex3i(350-200,550,-120);
        glVertex3i(700-200,550,-120);
        glVertex3i(700-200,550,-120);
        glVertex3i(720-200,570,-240);
        glVertex3i(700-200,550,-120);
        glVertex3i(700-200,530,-120);
    glEnd();
}

void lamp_post()
{
	//post
	glColor3ub(170,170,220);
	double len=180;
    double thick=10;
	glPushMatrix();
	glTranslatef(650-45,500,70.0);
    glScalef(thick,len,thick);
	glutSolidCube(1.0);
	glPopMatrix();

    //lantern  right
    glColor3ub(170,170,220);
	glPushMatrix();
	glLoadIdentity();
    glTranslatef(713-45,569,0);
    glutSolidCone(22,22,3,2);
    glPopMatrix();

    //sphere
    glColor3ub(160,160,210);
	glPushMatrix();
	glLoadIdentity();
	glTranslatef(650-45,600,70);
	glutSolidSphere(10,20,20);
	glPopMatrix();

    //bar right
    glColor3ub(155,155,205);
    double len0=60;
	double thick0=5;
	glPushMatrix();
	glLoadIdentity();
	glTranslatef(685-45,590,0);
    glScalef(len0,thick0,len0);
	glutSolidCube(1.0);
	glPopMatrix();

    //bar left
    glColor3ub(155,155,205);
    double len1=60;
    double thick1=5;
	glPushMatrix();
	glLoadIdentity();
	glTranslatef(615-45,590,70);
    glScalef(len1,thick1,len1);
	glutSolidCube(1.0);
	glPopMatrix();

    //lantern left
    glColor3ub(170,170,220);
	glPushMatrix();
	glLoadIdentity();
    glTranslatef(587-45,569,0);
    glutSolidCone(22,22,3,2);
    glPopMatrix();

    //bulb right
    glColor3f(100,100,0.0);
	glPushMatrix();
	glLoadIdentity();
	glTranslatef(713-45,555,70);
	glutSolidSphere(5,20,20);
	glPopMatrix();

    //bulb left
    glColor3f(100,100,0.0);
	glPushMatrix();
	glLoadIdentity();
	glTranslatef(587-45,555,0);
	glutSolidSphere(5,20,20);
	glPopMatrix();


}

void road2d()
{
    glColor3d(0.1,0.1,0.1);
    glBegin(GL_POLYGON);
        glVertex2d(0,200);
        glVertex2d(0,350);
        glVertex2d(1000,350);
        glVertex2d(1000,200);
    glEnd();
    int x;
    glColor3d(1,1,1);
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1,0x00FF);;
    glBegin(GL_LINES);
        glVertex2d(0,280);
        glVertex2d(1000,280);
    glEnd();
    glDisable(GL_LINE_STIPPLE);
}

void scene_1()
{
    bus_stop();
    lamp_post();
    road2d();
}

void reshape(int w,int h)
{
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if(w<=h)
		 glOrtho(-2.0,2.0,-2.0*(GLfloat)h/(GLfloat)w,2.0*(GLfloat)h/(GLfloat)w,-10.0,10.0);
	else
		 glOrtho(-2.0*(GLfloat)w/(GLfloat)h,2.0*(GLfloat)w/(GLfloat)h,-2.0,2.0,-10.0,10.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void display(void)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0,1000,10.0,650,-2000,1500);
    glMatrixMode(GL_MODELVIEW);
    glClearColor(0.0,0.0,0.0,0.0);
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    if(screen==0)
        first_screen();
    if(screen==1)
        scene_1();
    glutSwapBuffers();
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(1000,650);
    glutInitWindowPosition(0,0);
    glutCreateWindow("CG Project");
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutReshapeFunc(reshape);
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}


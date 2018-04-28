#include <stdio.h>
#include <stdlib.h>
#include <GL/freeglut.h>
#include <unistd.h>

#include<GL/glut.h>
#include<SOIL/SOIL.h>
#include<string.h>
GLuint tex_2d, tex_2d1, tex_2d2;

int screen = 0,x=-150,flag=0,x1=12,_y1=52,flag1=0,x2=-150,flag2=0,flag4=0,x4=0;
GLfloat vertices[][3] ={{160,390-50,-70},{425,390-50,-70},
					{425,510-50,-70}, {160,520-50,-70},

					{135,370-50,70}, {400,370-50,70},
					{400,490-50,70}, {135,500-50,70},

					{135,447-50,70},{400,447-50,70},
					{425,467-50,-70},{410,520-50,-70},

					{385,500-50,70}, {160,467-50,-70},
					{320,467-50,-70},{320,520-50,-70},

{380,520-50,-70},{380,390-50,-70},{320,390-50,-70}};

GLfloat colors[][3] = {{1.0,1.0,0.0},{0.0,0.6,0.7},{.3,.4,.5}};

GLfloat verticesd[][3] ={{160,390-175,-70},{425,390-175,-70},
					{425,510-175,-70}, {160,520-175,-70},

					{135,370-175,70}, {400,370-175,70},
					{400,490-175,70}, {135,500-175,70},

					{135,447-175,70},{400,447-175,70},
					{425,467-175,-70},{410,520-175,-70},

					{385,500-175,70}, {160,467-175,-70},
					{320,467-175,-70},{320,520-175,-70},

{380,520-175,-70},{380,390-175,-70},{320,390-175,-70}};

GLfloat colorsd[][3] = {{1.0,1.0,0.0},{0.0,0.6,0.7},{.3,.4,.5}};

void frontpg()
{
	glEnable(GL_TEXTURE_2D);
    /*background*/
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	tex_2d2 = SOIL_load_OGL_texture
		 (
			 "bg.png",
			 SOIL_LOAD_AUTO,
			 SOIL_CREATE_NEW_ID,
			 SOIL_FLAG_COMPRESS_TO_DXT
		 );
	glBindTexture(GL_TEXTURE_2D, tex_2d2);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glBegin(GL_POLYGON);
		glTexCoord2f(1.0, 1.0);
		glVertex2f(1000,415);
		glTexCoord2f(0.0, 1.0);
		glVertex2f(0,415);
		glTexCoord2f(0.0, 0.0);
		glVertex2f(0,650);
		glTexCoord2f(1.0, 0.0);
		glVertex2f(1000,650);
	glEnd();

    /*sidewalk*/
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	tex_2d2 = SOIL_load_OGL_texture
		 (
			 "sidewalk.png",
			 SOIL_LOAD_AUTO,
			 SOIL_CREATE_NEW_ID,
			 SOIL_FLAG_COMPRESS_TO_DXT
		 );
	glBindTexture(GL_TEXTURE_2D, tex_2d2);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glBegin(GL_POLYGON);
		glTexCoord2f(1.0, 1.0);
		glVertex2f(1000,350);
		glTexCoord2f(0.0, 1.0);
		glVertex2f(0,350);
		glTexCoord2f(0.0, 0.0);
		glVertex2f(0,415);
		glTexCoord2f(1.0, 0.0);
		glVertex2f(1000,415);
	glEnd();
    glDisable(GL_TEXTURE_2D);
}

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

void text()
{
    if(screen == 1 && flag == 0)
    {
        glColor3f(0,0,0);
        drawBitmapText1("Press x to start the scene",50,20);
    }
    if(screen == 1 && flag == 1 && x == 1000)
    {
        glColor3f(0,0,0);
        drawBitmapText1("Press left mouse button to move to next scene",50,20);
    }
    if(screen == 2 && flag1 == 0)
    {
        glColor3f(0,0,0);
        drawBitmapText1("Press x to start the scene",50,20);
    }
    if(screen == 2 && flag1 == 1 && _y1 > 310)
    {
        glColor3f(0,0,0);
        drawBitmapText1("Press left mouse button to move to next scene",50,20);
    }
    if(screen == 3 && flag2 == 0)
    {
        glColor3f(0,0,0);
        drawBitmapText1("Press x to start the scene",50,20);
    }
    if(screen == 3 && flag2 == 1 && x2 == 1000)
    {
        glColor3f(0,0,0);
        drawBitmapText1("Press left mouse button to move to next scene",50,20);
    }
    if(screen == 5 && flag4 == 0)
    {
        glColor3f(0,0,0);
        drawBitmapText1("Press x to start the scene",50,20);
    }
    if(screen == 5 && flag4 == 1 && x4 == -1000)
    {
        glColor3f(0,0,0);
        drawBitmapText1("Press left mouse button to move to next scene",50,20);
    }
}

void mouse(int btn,int state,int x,int y)
{
    if(btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        screen++;
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
    glColor3ub(180,180,180);
    glBegin(GL_POLYGON);
        glVertex3i(340-200,400,-110);
        glVertex3i(680-200,400,-110);
        glVertex3i(710-200,430,-240);
        glVertex3i(370-200,430,-240);
    glEnd();
    glColor3ub(180,180,180);
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

    //text
    drawBitmapText1("BUS STOP",280,530);
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
    //int x;
    glColor3d(1,1,1);
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1,0x00FF);
    glBegin(GL_LINES);
        glVertex2d(0,280);
        glVertex2d(1000,280);
    glEnd();
    glDisable(GL_LINE_STIPPLE);
}

void wheel1()
{
	glColor3f(0,0,0);
	glPushMatrix();
	glTranslatef(345,377-50,-70);
	glutSolidTorus(5,15,100,90);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(190,377-50,-70);
	glutSolidTorus(5,15,100,90); //front two wheels tyre
	glPopMatrix();
	glColor3ub(100,100,100);
	glPushMatrix();
	glTranslatef(345,377-50,-70);
	glutSolidTorus(5,5,10,69);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(190,377-50,-70);
	glutSolidTorus(5,5,10,69);
	glPopMatrix(); // front two wheels
}

void wheel2()
{
	glColor3f(0,0,0);
	glPushMatrix();
	glTranslatef(180,370-50,70);
	glutSolidTorus(5,15,100,90);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(335,370-50,70);
	glutSolidTorus(5,15,100,90);
	glPopMatrix();   //back two wheels tyre
	glColor3ub(100,100,100);
	glPushMatrix();
	glTranslatef(335,370-50,70);
	glutSolidTorus(5,5,10,69);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(180,370-50,70);
	glutSolidTorus(5,5,10,69);
	glPopMatrix();      //back two wheels
}

void woman()
{
	//face
	glColor3ub(0,0,0);
	glTranslatef(0, 0, -10);
	glPushMatrix();
	glTranslatef(540,495-30,0);
	glutSolidTorus(1,10,100-30,90);
	glPopMatrix();
	glColor3ub(255,191,128);
    glPushMatrix();
	glTranslatef(540,494-30,0);
	glutSolidTorus(7,7,100-30,90);
	glPopMatrix();
	glColor3ub(0,0,0);
	glBegin(GL_LINES);
 		glVertex2i(540,494-30);
 		glVertex2i(540,490-30); //nose
  		glVertex2i(531,498-30);
		glVertex2i(532,499-30);
 		glVertex2i(532,499-30);
		glVertex2i(537,498-30);//eyebrow
  	    glVertex2i(549,498-30);
		glVertex2i(548,499-30);
		glVertex2i(548,499-30);
 		glVertex2i(543,498-30);//eyebrow
 	glEnd();

    //ear right
	glBegin(GL_POLYGON);
        glColor3ub(255,191,128);
        glVertex2i(540-14,494+1-30);
        glVertex2i(540-14,490+1-30);
        glVertex2i(538-14,489+1-30);
        glVertex2i(538-14,495+1-30);
	glEnd();

	//ear left
	glBegin(GL_POLYGON);
        glColor3ub(255,191,128);
        glVertex2i(554,495-30);
        glVertex2i(556,496-30);
        glVertex2i(556,491-30);
        glVertex2i(554,490-30);
	glEnd();

	//ear ring right
	glBegin(GL_POLYGON);
        glColor3ub(255,85,90);
        glVertex2i(539-14,492-30);
        glVertex2i(542-14,485-30);
        glVertex2i(536-14,485-30);
	glEnd();

	//ear ring left
    glBegin(GL_POLYGON);
        glColor3ub(255,85,90);
        glVertex2i(551,485-30);
        glVertex2i(555,492-30);
        glVertex2i(558,485-30);
	glEnd();

    //hair
	glBegin(GL_POLYGON);
        glColor3ub(0,0,0);
        glVertex2i(525,499-30);
        glVertex2i(549,509-30);
        glVertex2i(540,512-30);
        glVertex2i(528,507-30);
	glEnd();

	glBegin(GL_POLYGON);
        glColor3ub(0,0,0);
        glVertex2i(540,507-30);
        glVertex2i(549,509-30);
        glVertex2i(552,507-30);
        glVertex2i(555,499-30);
	glEnd();

	// eyes
    glBegin(GL_POLYGON);
 		glVertex2i(533,496-30);
 		glVertex2i(535,496-30);
 		glVertex2i(535,494-30);
 		glVertex2i(533,494-30);
    glEnd();

    glBegin(GL_POLYGON);
 		glVertex2i(545,496-30);
 		glVertex2i(547,496-30);
     	glVertex2i(547,494-30);
 		glVertex2i(545,494-30);
    glEnd();

    //mouth
    glBegin(GL_POLYGON);
 		glColor3ub(150,50,50);
        glVertex2i(534,487-30);
 		glVertex2i(540,484-30);
 		glVertex2i(546,487-30);
 		glVertex2i(540,485-30);
    glEnd();

    //shirt
 	glBegin(GL_POLYGON);
 		glColor3ub(160,150,250);
        glVertex2i(529,480-30);
 		glVertex2i(551,480-30);
 		glVertex2i(566,469-30);
 		glVertex2i(561,460-30);
 		glVertex2i(556,465-30);
        glVertex2i(556,445-30);
 		glVertex2i(524,445-30);
 		glVertex2i(524,465-30);
 		glVertex2i(519,460-30);
 		glVertex2i(514,469-30);
    glEnd();

    //neck
    glBegin(GL_POLYGON);
        glColor3ub(255,190,128);
        glVertex2i(533,480-30);
        glVertex2i(547,480-30);
        glVertex2i(545,471-30);
        glVertex2i(535,471-30);
    glEnd();

    //hands
 	glBegin(GL_POLYGON);
		glColor3ub(255,191,128);
 		glVertex2i(565,468-30);
 		glVertex2i(575,453-30);
 		glVertex2i(567,454-30);
 		glVertex2i(562,462-30);
 	glEnd();
  	glBegin(GL_POLYGON);
		glVertex2i(575,453-30);
 		glVertex2i(556,438-30);
 		glVertex2i(556,445-30);
 		glVertex2i(567,454-30);
 	glEnd();
    glBegin(GL_POLYGON);
	 	glVertex2i(515,468-30);
 		glVertex2i(505,453-30);
 		glVertex2i(513,454-30);
 		glVertex2i(518,462-30);
 	glEnd();
  	glBegin(GL_POLYGON);
		glVertex2i(505,453-30);
   		glVertex2i(524,438-30);
   		glVertex2i(524,445-30);
   		glVertex2i(513,454-30);
  	glEnd();

    // belt
 	glBegin(GL_POLYGON);
		glColor3ub(10,120,130);
 		glVertex2i(556,445-30);
 		glVertex2i(524,445-30);
 		glVertex2i(524,440-30);
 		glVertex2i(556,440-30);
    glEnd();

	// leg
    glBegin(GL_POLYGON);
		glColor3ub(255,190,128);
        glVertex2i(555,440-30);
        glVertex2i(525,440-30);
        glVertex2i(520,405-30);
        glVertex2i(530,405-30);
        glVertex2i(533,438-30);
        glVertex2i(550,405-30);
        glVertex2i(560,405-30);
	glEnd();

    //skirt
    glBegin(GL_POLYGON);
	    glColor3ub(180,80,90);
		glVertex2i(524,440-30);
		glVertex2i(556,440-30);
		glVertex2i(566,410-30);
		glVertex2i(514,410-30);
    glEnd();

    //texture for skirt
    int i,k=0;
    for(i=1;i<40;i+=5)
    {
        glBegin(GL_LINES);
            glColor3f(0,0,1);
            glVertex2d(522+i,380+i/20);
            glVertex2d(522+i,410+i/20);
        glEnd();
    }

    //shoe left
	glBegin(GL_POLYGON);
        glColor3ub(180,0,0);
        glVertex2i(530,405-30);
        glVertex2i(530,396-30);
        glVertex2i(528,396-30);
        glVertex2i(528,404-30);
        glVertex2i(522,396-30);
        glVertex2i(512,396-30);
        glVertex2i(520,405-30);
	glEnd();

	//shoe right
	glBegin(GL_POLYGON);
        glColor3ub(180,0,0);
        glVertex2i(550,405-30);
        glVertex2i(550,396-30);
        glVertex2i(552,396-30);
        glVertex2i(552,404-30);
        glVertex2i(558,396-30);
        glVertex2i(568,396-30);
        glVertex2i(560,405-30);
	glEnd();

	// buttons
	glColor3ub(0,0,0);
	glPushMatrix();
	glTranslatef(540,465-30,0);
	glutSolidTorus(1,1,100-30,90);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(540,458-30,0);
	glutSolidTorus(1,1,100-30,90);
	glPopMatrix();
}

void man()
{
	glColor3ub(0,0,0);
	glPushMatrix();
	glTranslatef(540-220,495+76-30-76,0);
	glutSolidTorus(1,10,100-30-76,90);
	glPopMatrix();
	glColor3ub(255,191,128);
    glPushMatrix();
	glTranslatef(540-220,495-30+76-76,0);
	glutSolidTorus(7,7,100-76+30,90);
	glPopMatrix();
	glColor3ub(0,0,0);
	glBegin(GL_LINES);
 		glVertex2i(540-220,495+76-30-76);
 		glVertex2i(540-220,490+76-30-76); //nose
  		glVertex2i(531-220,500+76-30-76);
 		glVertex2i(537-220,500+76-30-76);//eyebrow
  		glVertex2i(543-220,500+76-30-76);
 		glVertex2i(549-220,500+76-30-76);//eyebrow
 	glEnd();

    //ear right
	glBegin(GL_POLYGON);
        glColor3ub(255,191,128);
        glVertex2i(540-14-220,494+1+76-30-76);
        glVertex2i(540-14-220,490+1+76-30-76);
        glVertex2i(538-14-220,489+1+76-30-76);
        glVertex2i(538-14-220,495+1+76-30-76);
	glEnd();

	//ear left
    glBegin(GL_POLYGON);
        glColor3ub(255,191,128);
        glVertex2i(554-220,495+76-30-76);
        glVertex2i(556-220,496+76-30-76);
        glVertex2i(556-220,491+76-30-76);
        glVertex2i(554-220,490+76-30-76);
	glEnd();

    //hair
	glBegin(GL_POLYGON);
	  glColor3ub(0,0,0);
	  glVertex2i(527-220,503+76-30-76);
	  glVertex2i(553-220,503+76-30-76);
	  glVertex2i(547-220,509+76-30-76);
	  glVertex2i(533-220,509+76-30-76);
	glEnd();

	// eyes
 	glBegin(GL_POLYGON);
 		glVertex2i(533-220,498+76-30-76);
 		glVertex2i(535-220,498+76-30-76);
 		glVertex2i(535-220,496+76-30-76);
 		glVertex2i(533-220,496+76-30-76);
    glEnd();
    glBegin(GL_POLYGON);
 		glVertex2i(545-220,498+76-30-76);
 		glVertex2i(547-220,498+76-30-76);
 		glVertex2i(547-220,496+76-30-76);
 		glVertex2i(545-220,496+76-30-76);
    glEnd();

 	// mouth
    glBegin(GL_POLYGON);
 		glVertex2i(535-220,487+76-30-76);
 		glVertex2i(540-220,485+76-30-76);
 		glVertex2i(545-220,487+76-30-76);
 		glVertex2i(540-220,487+76-30-76);
    glEnd();

    //beard
    glBegin(GL_POLYGON);
        glColor3ub(0,0,0);
        glVertex2i(538-220,480+76-30-76);
        glVertex2i(542-220,480+76-30-76);
        glVertex2i(542-220,484+76-30-76);
        glVertex2i(538-220,484+76-30-76);
    glEnd();

    //shirt
 	glBegin(GL_POLYGON);
 		glColor3ub(55,50,70);
	    glVertex2i(529-220,480+76-30-76);
 		glVertex2i(551-220,480+76-30-76);
 		glVertex2i(566-220,469+76-30-76);
 		glVertex2i(561-220,461+76-30-76);
 		glVertex2i(556-220,465+76-30-76);
        glVertex2i(556-220,445+76-30-76);
 		glVertex2i(524-220,445+76-30-76);
 		glVertex2i(524-220,465+76-30-76);
 		glVertex2i(519-220,460+76-30-76);
 		glVertex2i(514-220,469+76-30-76);
    glEnd();

    //hands
 	glBegin(GL_POLYGON);
		glColor3ub(255,191,128);
 		glVertex2i(565-220,468+76-30-76);
 		glVertex2i(575-220,453+76-30-76);
 		glVertex2i(567-220,454+76-30-76);
 		glVertex2i(562-220,462+76-30-76);
 	glEnd();
  	glBegin(GL_POLYGON);
		glVertex2i(575-220,453+76-30-76);
 		glVertex2i(556-220,438+76-30-76);
 		glVertex2i(556-220,445+76-30-76);
 		glVertex2i(567-220,454+76-30-76);
 	glEnd();
    glBegin(GL_POLYGON);
	 	glVertex2i(515-220,468+76-30-76);
 		glVertex2i(505-220,453+76-30-76);
 		glVertex2i(513-220,454+76-30-76);
 		glVertex2i(518-220,462+76-30-76);
 	glEnd();
  	glBegin(GL_POLYGON);
		glVertex2i(505-220,453+76-30-76);
   		glVertex2i(524-220,438+76-30-76);
   		glVertex2i(524-220,445+76-30-76);
   		glVertex2i(513-220,454+76-30-76);
  	glEnd();

    // belt
 	glBegin(GL_POLYGON);
		glColor3ub(150,12,30);
 		glVertex2i(556-220,445+76-30-76);
 		glVertex2i(524-220,445+76-30-76);
 		glVertex2i(524-220,440+76-30-76);
		glVertex2i(524-220,440+76-30-76);
 		glVertex2i(556-220,440+76-30-76);
    glEnd();

    // collar
 	glBegin(GL_POLYGON);
		glColor3ub(200,140,110+76-30-76);
 		glVertex2i(529-220,480+76-30-76);
 		glVertex2i(551-220,480+76-30-76);
 		glVertex2i(546-220,470+76-30-76);
 		glVertex2i(534-220,470+76-30-76);
    glEnd();
 	glBegin(GL_TRIANGLES);
		glColor3ub(20,140,110);
 		glVertex2i(540-220,477+76-30-76);
  		glVertex2i(545-220,470+76-30-76);
 		glVertex2i(535-220,470+76-30-76);
    glEnd();

    // buttons
	glColor3ub(0,0,0);
	glPushMatrix();
	glTranslatef(540-220,465-30,0);
	glutSolidTorus(1,1,100-30,90);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(540-220,458-30,0);
	glutSolidTorus(1,1,100-30,90);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(540-220,451-30,0);
	glutSolidTorus(1,1,100-30,90);
	glPopMatrix();

	// pant
    glBegin(GL_POLYGON);
		glColor3ub(80,80,230);
        glVertex2i(555-220,440+76-30-76);
        glVertex2i(525-220,440+76-30-76);
        glVertex2i(520-220,405+76-30-76);
        glVertex2i(530-220,405+76-30-76);
        glVertex2i(533-220,438+76-30-76);
        glVertex2i(550-220,405+76-30-76);
        glVertex2i(560-220,405+76-30-76);
	glEnd();

    //shoe left
	glBegin(GL_POLYGON);
        glColor3ub(100,10,10);
        glVertex2i(530-220,405+76-30-76);
        glVertex2i(530-220,396+76-30-76);
        glVertex2i(512-220,396+76-30-76);
        glVertex2i(520-220,405+76-30-76);
	glEnd();

	//shoe right
	glBegin(GL_POLYGON);
        glColor3ub(100,10,10);
        glVertex2i(550-220,405+76-30-76);
        glVertex2i(550-220,396+76-30-76);
        glVertex2i(568-220,396+76-30-76);
        glVertex2i(560-220,405+76-30-76);
	glEnd();
}


/*-------------------------------------------------------------------*/
				//	FUNCTION cube
/*-------------------------------------------------------------------*/
void polygon(int a, int b, int c , int d,int E,int f)
{
	glBegin(GL_POLYGON);
		glColor3fv(colors[E]);
		glVertex3fv(vertices[a]);
		glVertex3fv(vertices[b]);
		glVertex3fv(vertices[c]);
		glVertex3fv(vertices[d]);
		if(f!=0)
		glVertex3fv(vertices[f]);
	glEnd();
}

void colorcube()
{
	wheel1();
	polygon(0,1,5,4,0,0);
	polygon(13,14,18,0,0,0);
	polygon(15,16,17,18,2,0);
	polygon(16,11,2,1,0,17);
	polygon(0,4,8,13,0,0);
	polygon(1,10,9,5,0,0);
	polygon(9,10,2,6,1,0);
	polygon(4,5,9,8,0,0);
	polygon(8,9,6,12,1,7);
	glColor3ub(100,40,50);
	polygon(13,8,7,3,1,0);
	polygon(3,15,14,13,1,0);
	polygon(6,2,11,12,0,0);
	polygon(11,3,7,12,0,0);
	int i;
	for(i=0;i<=180;i+=45)
	{
		glBegin(GL_LINES);
		glColor3f(0.8,0.2,0);
		glVertex3f(180+i,400,70);
		glVertex3f(180+i,450,70);
		glEnd();
	}
	glColor3f(0.4,0,0);
	drawBitmapText1("BMTC",250,350);
    wheel2();
}

void bus_move()
{
    if(x>250)
        woman();
    if(x<1000)
    {
        x += 2;
        glPushMatrix();
        glTranslatef(x,0,0);
        wheel1();
        colorcube();
        wheel2();
        glPopMatrix();
    }
    if(x == 250) sleep(2);
    if(x == 1000)
        text();
}

void window()
{
    glBegin(GL_POLYGON);
	glColor3f(0.7,0.7,1);
	glVertex2d(68,65);
	glVertex2d(68,35);
	glColor3f(0.4,0.5,0.6);
	glVertex2d(98,25);
	glVertex2d(98,55);
	glEnd();
}

void gate()
{
    //compound walls
    glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	gluLookAt(230,140,210,0,25,0,0,110,0);
	glTranslatef(705,510,0);
	glScalef(180,160,20);
	glColor3f(0.2,0.2,0.2);
	glutSolidCube(1.0);
	glPopMatrix();
    glPushMatrix();
	gluLookAt(230,140,210,0,25,0,0,110,0);
	glTranslatef(998,500,0);
	glScalef(180,160,20);
	glColor3f(0.2,0.2,0.2);
	glutSolidCube(1.0);
	glPopMatrix();
    glBegin(GL_LINES);
        glColor3f(0,0,0);
        glVertex2d(407,370);
        glVertex2d(528,323);
        glVertex2d(528,323);
        glVertex2d(528,174);
        glVertex2d(528,323);
        glVertex2d(543,329);
    glEnd();
    glBegin(GL_LINES);
        glColor3f(0,0,0);
        glVertex2d(407+198,370-84);
        glVertex2d(528+198,323-84);
        glVertex2d(528+198,323-84);
        glVertex2d(528+198,174-84);
        glVertex2d(528+198,323-84);
        glVertex2d(543+198,329-84);
    glEnd();

    //lights
    glPushMatrix();
    glColor3f(1,1,0);
    glTranslatef(519,339,0);
	glutSolidTorus(4.5,4.5,200,190);
	glPopMatrix();
	glPushMatrix();
    glColor3f(1,1,0);
    glTranslatef(622,291,0);
	glutSolidTorus(4.5,4.5,200,190);
	glPopMatrix();

	//bricks
	int i;
	for(i=0;i<120;i+=10)
	{
        glBegin(GL_LINES);
            glColor3f(0,0,0);
            glVertex2d(528-i,323+i/2.5);
            glVertex2d(528-i,174+i/2.5);
        glEnd();
	}
	for(i=0;i<150;i+=10)
	{
        glBegin(GL_LINES);
            glColor3f(0,0,0);
            glVertex2d(407,370-i);
            glVertex2d(528,323-i);
        glEnd();
	}
	for(i=0;i<120;i+=10)
	{
        glBegin(GL_LINES);
            glColor3f(0,0,0);
            glVertex2d(528+198-i,323-84+i/2.5);
            glVertex2d(528+198-i,174-84+i/2.5);
        glEnd();
	}
	for(i=0;i<150;i+=10)
	{
        glBegin(GL_LINES);
            glColor3f(0,0,0);
            glVertex2d(407+198,370-84-i);
            glVertex2d(528+198,323-84-i);
        glEnd();
	}

	//gate right
	glBegin(GL_POLYGON);
        glColor3f(0.2,0.3,0.5);
        glVertex2i(750-145,300-155);
        glVertex2i(650-140,300-155);
        glVertex2i(650-140,303-155);
        glVertex2i(750-145,303-155);
	glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.2,0.3,0.5);
        glVertex2i(650-140,450-155-10);
        glVertex2i(750-145,433-155);
        glVertex2i(750-145,430-155);
        glVertex2i(650-140,447-155-10);
	glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.2,0.3,0.5);
        glVertex2i(650-140,300-155);
        glVertex2i(650-140,442-155);
        glVertex2i(653-140,442-155);
        glVertex2i(653-140,300-155);
	glEnd();

	glBegin(GL_POLYGON);
        glColor3f(0.2,0.3,0.5);
        glVertex2i(711-140,300-155);
        glVertex2i(711-140,437-155);
        glVertex2i(714-140,437-155);
        glVertex2i(714-140,300-155);
	glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.2,0.3,0.5);
        glVertex2i(650-140,350-155);
        glVertex2i(750-145,350-155);
        glVertex2i(750-145,345-155);
        glVertex2i(650-140,345-155);
	glEnd();

   //gate left
    glBegin(GL_POLYGON);
        glColor3f(0.2,0.3,0.5);
        glVertex2i(420+25,300-155+15);
        glVertex2i(500+25,340-155);
        glVertex2i(500+25,343-155);
        glVertex2i(420+25,303-155+15);
	glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.2,0.3,0.5);
        glVertex2i(420+25,433-155+15);
        glVertex2i(500+25,473-155);
        glVertex2i(500+25,476-155);
        glVertex2i(420+25,436-155+15);
	glEnd();

	glBegin(GL_POLYGON);
        glColor3f(0.2,0.3,0.5);
        glVertex2i(500-1+25,340-155);
        glVertex2i(500-1+25,473-155);
        glVertex2i(503-1+25,476-155);
        glVertex2i(503-1+25,343-155);
	glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.2,0.3,0.5);
        glVertex2i(500-41+25,340-15-155);
        glVertex2i(500-41+25,473-15-155);
        glVertex2i(503-41+25,476-15-155);
        glVertex2i(503-41+25,343-15-155);
	glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.2,0.3,0.5);
        glVertex2i(500-81+25,340-25-155);
        glVertex2i(500-81+25,473-25-155);
        glVertex2i(503-81+25,476-25-155);
        glVertex2i(503-81+25,343-25-155);
	glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.2,0.3,0.5);
        glVertex2i(420+25,433-75-155);
        glVertex2i(500+25,473-90-155);
        glVertex2i(500+25,478-90-155);
        glVertex2i(420+25,438-75-155);
	glEnd();
}

void building()
{
    //wall
    glBegin(GL_POLYGON);
        glColor3f(0.2,0.2,0.2);
        glVertex2d(409,220);
        glVertex2d(409,370);
        glVertex2d(950,550);
        glVertex2d(950,400);
    glEnd();

    //building
    glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	gluLookAt(230,140,210,0,25,0,0,110,0);
	glTranslatef(990,740,0);
	glScalef(200,330,150);
	glColor3ub(75,75,80);
	glutSolidCube(1.0);
	glPopMatrix();
	glBegin(GL_LINES);
        glColor3f(0.5,0.5,0.5);
        glVertex2d(680,220);
        glVertex2d(680,530);
        glVertex2d(545,580);
        glVertex2d(680,530);
        glVertex2d(680,530);
        glVertex2d(789,566);
	glEnd();

	//texture for building
    int i;
    for(i=1;i<110;i+=2)
    {
        glBegin(GL_LINES);
            glVertex2d(680+i,220+i/3);
            glVertex2d(680+i,530+i/3);
        glEnd();
    }
    glPushMatrix();
    for(i=1;i<150;i+=25)
    {
        glBegin(GL_LINES);
            glVertex2d(545+i,582-i/2.5);
            glVertex2d(545+i,272-i/2.5);
            glVertex2d(547+i,582-i/2.5);
            glVertex2d(547+i,272-i/2.5);
        glEnd();
    }
    glPopMatrix();
    gate();
    glPushMatrix();
	glTranslated(491,488,0);
    window();
    glPopMatrix();
    glPushMatrix();
	glTranslated(491+70,488-25,0);
    window();
    glPopMatrix();
    glPushMatrix();
	glTranslated(491,488-80,0);
    window();
    glPopMatrix();
    glPushMatrix();
	glTranslated(491+70,488-105,0);
    window();
    glPopMatrix();
    glPushMatrix();
	glTranslated(491,488-160,0);
    window();
    glPopMatrix();
    glPushMatrix();
	glTranslated(491+70,488-185,0);
    window();
    glPopMatrix();

    //wall
    glBegin(GL_POLYGON);
        glColor3f(0.2,0.2,0.2);
        glVertex2d(730,90);
        glVertex2d(730,240);
        glVertex2d(950,330);
        glVertex2d(950,180);
    glEnd();
}

void tree()
{
    glBegin(GL_TRIANGLES);
        glColor3f(0,1,0);
        glVertex2d(30,430);
        glVertex2d(140,430);
        glVertex2d(85,500);
        glVertex2d(40,480);
        glVertex2d(130,480);
        glVertex2d(85,550);
        glVertex2d(50,530);
        glVertex2d(120,530);
        glVertex2d(85,600);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3f(0.7,0,0);
        glVertex2d(80,380);
        glVertex2d(90,380);
        glVertex2d(90,430);
        glVertex2d(80,430);
    glEnd();
}

void scene2_translate()
{
    if(x1<=230)
    {
        x1 += 1;
        glPushMatrix();
        glTranslatef(x1,0,0);
        woman();
        glPopMatrix();
    }
    if(_y1<=310)
    {
        _y1 += 1.5;
        glPushMatrix();
        glTranslatef(_y1,0,0);
        man();
        glPopMatrix();
    }
    if(x1>230)
    {
        text();
        glPushMatrix();
        glTranslatef(230,0,0);
        woman();
        glPopMatrix();
    }
    if(_y1>310)
    {
        glPushMatrix();
        glTranslatef(350,0,0);
        man();
        glPopMatrix();
    }
}

void car()
{
    glPushMatrix();
    glColor3f(1,1,0);
    glTranslatef(383,344,0);
	glutSolidTorus(3,3,200,190);
	glPopMatrix();
    glPushMatrix();
    glTranslatef(-10,-10,0);
    wheel1();
    glPopMatrix();
    glBegin(GL_POLYGON);
        glColor3f(0.3,0,0);
        glVertex2d(110,310);
        glVertex2d(380,310);
        glVertex2d(380,370);
        glVertex2d(110,370);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2d(160,370);
        glVertex2d(180,420);
        glVertex2d(300,420);
        glVertex2d(320,370);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(80,80,80);
        glVertex2d(170,375);
        glVertex2d(185,415);
        glColor3ub(150,150,150);
        glVertex2d(235,415);
        glVertex2d(235,375);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(80,80,80);
        glVertex2d(245,375);
        glVertex2d(310,375);
        glColor3ub(150,150,150);
        glVertex2d(295,415);
        glVertex2d(245,415);
    glEnd();
    glPushMatrix();
    glColor3f(1,1,0);
    glTranslatef(381,340,0);
	glutSolidTorus(3,3,200,190);
	glPopMatrix();
    glPushMatrix();
    glTranslatef(-10,-10,0);
    wheel2();
    glPopMatrix();
    glBegin(GL_POLYGON);
        glVertex2d(100,320);
        glVertex2d(110,320);
        glVertex2d(110,330);
        glVertex2d(100,330);
    glEnd();
}

void car_move()
{
    if(x2<1000)
    {
        x2 += 5;
        glPushMatrix();
        glTranslatef(x2,0,0);
        car();
        glPopMatrix();
    }
    if(x2 == 400) sleep(2);
    if(x2 > 400)
    {
        glPushMatrix();
        glTranslatef(1000,0,0);
        woman();
        man();
        glPopMatrix();
    }
    if(x2 == 1000)
        text();
}

void shrubd(int xtrans)
{
    glColor3ub(0,160,0);
    double len0=57;
	double thick0=13;
	glPushMatrix();
	glLoadIdentity();
	glTranslatef(15+5 + xtrans,357+20,0);
    glScalef(len0,thick0,len0);
	glutSolidCube(1.0);
	glPopMatrix();

	//leaves1
    glColor3ub(0,160,0);
	glPushMatrix();
	glLoadIdentity();
	glTranslatef(5 + xtrans,370+20,70);
	glutSolidSphere(20,20,20);
	glPopMatrix();

	//leaves2
    glColor3ub(0,160,0);
	glPushMatrix();
	glLoadIdentity();
	glTranslatef(15+5 + xtrans,395+20,70);
	glutSolidSphere(20,20,20);
	glPopMatrix();

    //leaves3
    glColor3ub(0,160,0);
	glPushMatrix();
	glLoadIdentity();
	glTranslatef(30+5 + xtrans,370+20,70);
	glutSolidSphere(20,20,20);
	glPopMatrix();

    //flower1
    glColor3ub(140,0,0);
	glPushMatrix();
	glLoadIdentity();
	glTranslatef(30+5+xtrans,370+20,70);
	glutSolidSphere(5,20,20);
	glPopMatrix();

    //flower2
    glColor3ub(140,0,0);
	glPushMatrix();
	glLoadIdentity();
	glTranslatef(12+5+xtrans,393+20,70);
	glutSolidSphere(5,20,20);
	glPopMatrix();
}

void grass1()
{
    glColor3ub(0,160,0);
    glBegin(GL_TRIANGLES);
        glVertex2d(100,10+10);
        glVertex2d(95-5,50+10);
        glVertex2d(105,15+10);
        glVertex2d(100,10+10);
        glVertex2d(85-5,45+10);
        glVertex2d(103,15+10);
        glVertex2d(100,10+10);
        glVertex2d(108-5,60+10);
        glVertex2d(110,20);
        glVertex2d(108-3,20);
        glVertex2d(116,55+10);
        glVertex2d(114,20);
        glVertex2d(112,20);
        glVertex2d(124,45+10);
        glVertex2d(118,20);
        glVertex2d(116,20);
        glVertex2d(132,35+10);
        glVertex2d(122,20);
    glEnd();
}

void grass()
{
    glBegin(GL_POLYGON);
        glColor3f(0.6,1,0);
        glVertex2d(0,10);
        glColor3f(0.4,1,0);
        glVertex2d(1000,10);
        glColor3f(0.6,1,0);
        glVertex2d(1000,200);
        glColor3f(0.4,1,0);
        glVertex2d(0,200);
    glEnd();
    glPushMatrix();
    grass1();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-40,80,0);
    grass1();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(60+10,60,0);
    grass1();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(100+60,40+70,0);
    grass1();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(120+120,20+10,0);
    grass1();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(160+150,80+10,0);
    grass1();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(180+230,50+10,0);
    grass1();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(60+10+400,60,0);
    grass1();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(100+60+400,40+70,0);
    grass1();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(120+120+400,20+10,0);
    grass1();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(160+150+400,80+10,0);
    grass1();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(180+230+400,50+10,0);
    grass1();
    glPopMatrix();
}

void woman4()
{
	//face
	glColor3ub(0,0,0);
	glTranslatef(0, 0, -10);
	glPushMatrix();
	glTranslatef(540,495-30,0);
	glutSolidTorus(1,10,100-30,90);
	glPopMatrix();
	glColor3ub(255,191,128);
    glPushMatrix();
	glTranslatef(540,494-30,0);
	glutSolidTorus(7,7,100-30,90);
	glPopMatrix();
	glColor3ub(0,0,0);
	glBegin(GL_LINES);
 		glVertex2i(540,494-30);
 		glVertex2i(540,490-30); //nose
  		glVertex2i(531,498-30);
		glVertex2i(532,499-30);
 		glVertex2i(532,499-30);
		glVertex2i(537,498-30);//eyebrow
  	    glVertex2i(549,498-30);
		glVertex2i(548,499-30);
		glVertex2i(548,499-30);
 		glVertex2i(543,498-30);//eyebrow
 	glEnd();

    //ear right
	glBegin(GL_POLYGON);
        glColor3ub(255,191,128);
        glVertex2i(540-14,494+1-30);
        glVertex2i(540-14,490+1-30);
        glVertex2i(538-14,489+1-30);
        glVertex2i(538-14,495+1-30);
	glEnd();

	//ear left
	glBegin(GL_POLYGON);
        glColor3ub(255,191,128);
        glVertex2i(554,495-30);
        glVertex2i(556,496-30);
        glVertex2i(556,491-30);
        glVertex2i(554,490-30);
	glEnd();

	//ear ring right
	glBegin(GL_POLYGON);
        glColor3ub(255,85,90);
        glVertex2i(539-14,492-30);
        glVertex2i(542-14,485-30);
        glVertex2i(536-14,485-30);
	glEnd();

	//ear ring left
    glBegin(GL_POLYGON);
        glColor3ub(255,85,90);
        glVertex2i(551,485-30);
        glVertex2i(555,492-30);
        glVertex2i(558,485-30);
	glEnd();

    //hair
	glBegin(GL_POLYGON);
        glColor3ub(0,0,0);
        glVertex2i(525,499-30);
        glVertex2i(549,509-30);
        glVertex2i(540,512-30);
        glVertex2i(528,507-30);
	glEnd();

	glBegin(GL_POLYGON);
        glColor3ub(0,0,0);
        glVertex2i(540,507-30);
        glVertex2i(549,509-30);
        glVertex2i(552,507-30);
        glVertex2i(555,499-30);
	glEnd();

	// eyes
    glBegin(GL_POLYGON);
 		glVertex2i(533,496-30);
 		glVertex2i(535,496-30);
 		glVertex2i(535,494-30);
 		glVertex2i(533,494-30);
    glEnd();

    glBegin(GL_POLYGON);
 		glVertex2i(545,496-30);
 		glVertex2i(547,496-30);
     	glVertex2i(547,494-30);
 		glVertex2i(545,494-30);
    glEnd();

    //mouth
    glBegin(GL_POLYGON);
 		glColor3ub(150,50,50);
        glVertex2i(534,487-30);
 		glVertex2i(540,484-30);
 		glVertex2i(546,487-30);
 		glVertex2i(540,485-30);
    glEnd();

    //shirt
 	glBegin(GL_POLYGON);
 		glColor3ub(160,150,250);
        glVertex2i(529,480-30);
 		glVertex2i(551,480-30);
 		glVertex2i(566,469-30);
 		glVertex2i(561,460-30);
 		glVertex2i(556,465-30);
        glVertex2i(556,445-30);
 		glVertex2i(524,445-30);
 		glVertex2i(524,465-30);
 		glVertex2i(519,460-30);
 		glVertex2i(514,469-30);
    glEnd();

    //neck
    glBegin(GL_POLYGON);
        glColor3ub(255,190,128);
        glVertex2i(533,480-30);
        glVertex2i(547,480-30);
        glVertex2i(545,471-30);
        glVertex2i(535,471-30);
    glEnd();

    //hands
 	glBegin(GL_POLYGON);
		glColor3ub(255,191,128);
 		glVertex2i(565,468-30);
 		glVertex2i(575,453-30);
 		glVertex2i(567,454-30);
 		glVertex2i(562,462-30);
 	glEnd();
  	glBegin(GL_POLYGON);
		glVertex2i(575,453-30);
 		glVertex2i(556,438-30);
 		glVertex2i(556,445-30);
 		glVertex2i(567,454-30);
 	glEnd();
    glBegin(GL_POLYGON);
		glVertex2i(570-52,453-30+10);
 		glVertex2i(556-52,438-30+13);
 		glVertex2i(555-52,445-30+13);
 		glVertex2i(567-52,454-30+14);
 	glEnd();

    // belt
 	glBegin(GL_POLYGON);
		glColor3ub(10,120,130);
 		glVertex2i(556,445-30);
 		glVertex2i(524,445-30);
 		glVertex2i(524,440-30);
 		glVertex2i(556,440-30);
    glEnd();

	// leg
    glBegin(GL_POLYGON);
		glColor3ub(255,190,128);
        glVertex2i(555,440-30);
        glVertex2i(525,440-30);
        glVertex2i(520,405-30);
        glVertex2i(530,405-30);
        glVertex2i(533,438-30);
        glVertex2i(550,405-30);
        glVertex2i(560,405-30);
	glEnd();

    //skirt
    glBegin(GL_POLYGON);
	    glColor3ub(180,80,90);
		glVertex2i(524,440-30);
		glVertex2i(556,440-30);
		glVertex2i(566,410-30);
		glVertex2i(514,410-30);
    glEnd();

    //texture for skirt
    int i,k=0;
    for(i=1;i<40;i+=5)
    {
        glBegin(GL_LINES);
            glColor3f(0,0,1);
            glVertex2d(522+i,380+i/20);
            glVertex2d(522+i,410+i/20);
        glEnd();
    }

    //shoe left
	glBegin(GL_POLYGON);
        glColor3ub(180,0,0);
        glVertex2i(530,405-30);
        glVertex2i(530,396-30);
        glVertex2i(528,396-30);
        glVertex2i(528,404-30);
        glVertex2i(522,396-30);
        glVertex2i(512,396-30);
        glVertex2i(520,405-30);
	glEnd();

	//shoe right
	glBegin(GL_POLYGON);
        glColor3ub(180,0,0);
        glVertex2i(550,405-30);
        glVertex2i(550,396-30);
        glVertex2i(552,396-30);
        glVertex2i(552,404-30);
        glVertex2i(558,396-30);
        glVertex2i(568,396-30);
        glVertex2i(560,405-30);
	glEnd();

	// buttons
	glColor3ub(0,0,0);
	glPushMatrix();
	glTranslatef(540,465-30,0);
	glutSolidTorus(1,1,100-30,90);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(540,458-30,0);
	glutSolidTorus(1,1,100-30,90);
	glPopMatrix();
}

void pepper_spray()
{
    glPushMatrix();
    glColor3ub(80,80,80);
    glTranslatef(710,438,0);
    glutSolidTorus(3,3,200,190);
    glPopMatrix();
    glColor3f(1,0,0);
    glBegin(GL_POLYGON);
        glColor3f(0.9,0.9,0.2);
        glVertex2d(705,410);
        glVertex2d(713,410);
        glVertex2d(713,435);
        glVertex2d(705,435);
    glEnd();
}

void road()
{
    glColor3d(0.1,0.1,0.1);
    glBegin(GL_POLYGON);
        glVertex2d(0,200);
        glVertex2d(0,350);
        glVertex2d(700,350);
        glVertex2d(700,200);
    glEnd();
    //int x;
    glColor3d(1,1,1);
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1,0x00FF);
    glBegin(GL_LINES);
        glVertex2d(0,280);
        glVertex2d(700,280);
    glEnd();
    glDisable(GL_LINE_STIPPLE);
}

void press_spray()
{
    int i;
    for(i=0;i<5;i++)
    {
        glBegin(GL_LINES);
            glVertex2d(687+i,445+i);
            glVertex2d(631+i,465+i);
        glEnd();
    }
}

void scene4_translate()
{
    if(x4>-1000)
    {
        x4 -= 2;
        glPushMatrix();
        glTranslatef(300+x4,0,0);
        man();
        glPopMatrix();
    }
    if(x4 == -1000)
        text();
}

void scene_1()
{
    glPushMatrix();
	frontpg();
    glPopMatrix();

    glPushMatrix();
    bus_stop();
    lamp_post();
    road2d();
    man();
    tree();
    shrubd(0);
    grass();
    text();
    glPushMatrix();
    glTranslatef(800,0,0);
    tree();
    glPopMatrix();
    shrubd(750);
    shrubd(80);
    shrubd(820);
    shrubd(900);
    if(flag == 1)
        bus_move();
    glPopMatrix();
}

void scene_2()
{
    glPushMatrix();
	frontpg();
    glPopMatrix();

    glPushMatrix();
    bus_stop();
    lamp_post();
    road2d();
    tree();
    shrubd(0);
    grass();
    text();
    glPushMatrix();
    glTranslatef(800,0,0);
    tree();
    glPopMatrix();
    shrubd(750);
    shrubd(80);
    shrubd(820);
    shrubd(900);
    if(x1 == 12)
    {
        glPushMatrix();
        glTranslatef(8,0,0);
        woman();
        glPopMatrix();
    }
    if(_y1 == 52)
    {
        glPushMatrix();
        glTranslatef(8,0,0);
        man();
        glPopMatrix();
    }
    if(flag1 == 1)
        scene2_translate();
    glPopMatrix();
}

void scene_3()
{
    glPushMatrix();
	frontpg();
    glPopMatrix();

    glPushMatrix();
    road2d();
    grass();
    text();
    if(x2 < 390)
    {
        glPushMatrix();
        glTranslated(200,0,0);
        woman();
        glPopMatrix();
        glPushMatrix();
        glTranslated(360,0,0);
        man();
        glPopMatrix();
    }
    if(flag2 == 1)
        car_move();
    glPopMatrix();
}

void scene_4()
{
    glColor3f(1,1,1);
    drawBitmapText1("Press right mouse button to view the menu",50,20);
}

void scene_5()
{
    glPushMatrix();
	frontpg();
    glPopMatrix();

    glPushMatrix();
    road2d();
    grass();
    text();
    glPushMatrix();
    glTranslated(200,0,0);
    woman4();
    glPopMatrix();
    if(flag4 == 0)
    {
        glPushMatrix();
        glTranslated(300,0,0);
        man();
        glPopMatrix();
    }
    glPushMatrix();
    glTranslatef(696,400,0);
    glRotatef(20,0,0,1);
    glTranslatef(-696,-400,0);
    pepper_spray();
    glPopMatrix();
    if(flag4 == 1)
    {
        if(x4>-20)
            press_spray();
        scene4_translate();
    }
    glPopMatrix();
}

void scene_6()
{
    glPushMatrix();
	frontpg();
    glPopMatrix();
    road();
    grass();
    glPushMatrix();
    glTranslated(10,-100,0);
    woman();
    glPopMatrix();
    glPushMatrix();
    glTranslated(60,-100,0);
    man();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,-90,0);
    glScalef(-100,0,0);
    road2d();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(200,35,0);
    building();
    glPopMatrix();
}

void scene_7()
{
    glColor3f(1,1,0);
    glLineWidth(3.0);
    drawStrokeText("Respect",350+40,350,0);
    drawStrokeText("Women",380+60,300,0);
}

void keys(unsigned char key,int x,int y)
{
    if(key == 'x' && screen == 1)
        flag = 1;
    if(key == 'x' && screen == 2)
        flag1 = 1;
    if(key == 'x' && screen == 3)
        flag2 = 1;
    if(key == 'x' && screen == 5)
        flag4 = 1;
}

void menu(int id)
{
    if(screen == 4 || screen == 5 || screen == 6)
    {
        switch(id)
        {
            case 1: screen = 1;
                    break;
            case 2: screen = 5;
                    break;
            case 3: screen = 6;
                    break;
            default: exit(0);
        }
    }
    glutPostRedisplay();
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
    if(screen==2)
        scene_2();
    if(screen==3)
        scene_3();
    if(screen==4)
        scene_4();
    if(screen==5)
        scene_5();
    if(screen==6)
        scene_6();
    if(screen==7)
        scene_7();
    if(screen>7)
        exit(0);
    glutSwapBuffers();
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
    glutInitWindowSize(1000,650);
    glutInitWindowPosition(0,0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glutCreateWindow("CG Project");
    int submenu = glutCreateMenu(menu);
    glutAddMenuEntry("Female perspective",2);
    glutAddMenuEntry("Male perspective",3);
    glutCreateMenu(menu);
    glutAddMenuEntry("Move back to scene 1",1);
    glutAddSubMenu("What should be done?",submenu);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutReshapeFunc(reshape);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keys);
    glutMainLoop();
    return 0;
}

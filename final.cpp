#include<windows.h>
#define GLUT_DISABLE_ATEXIT_HACK
#include <gl/glut.h>
#include <math.h>//for PI value , sine and cosine function that we used to draw lines
void line_drawing(float a, float b, float c, float d)
{
    // Draw an outlined triangle
	glBegin(GL_LINES);

		glVertex2f(a, b);
		glVertex2f(c, d);


	glEnd();
}
 float angleHour= 0,angleMin  = 0,angleSec  = 0, clockR    = 80.0f,angle1min = M_PI / 30.0f,minStart= 0.9f,minEnd=1.0f,stepStart = 0.8f,stepEnd   = 1.0f; 
void init(){
  	glClearColor(0.0f, 0.5f, 1.0f, 1.0f);
	glMatrixMode(GL_PROJECTION);
	glOrtho(-150,150,-100,100,-100,100);
}
//number method is used to write the numbers found in the clock
void numbers()
{
	glRasterPos2i(58,0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'3');
	glRasterPos2i(0,-60);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'6');
	glRasterPos2i(-62,-2);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'9');
	glRasterPos2i(-2,57);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'1');
	glRasterPos2i(1,57);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'2');
}
//display function responsible to design the classic clock interface
void Display(){
	// set raster position to bottom right corner
//    glRasterPos2f(9.5, -14);
	
    
//    glutSwapBuffers();

 
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1.0f, 0.0f, 0.0f);
  glLineWidth(2);
  
  glEnable(GL_LINE_SMOOTH);//for drawing  smooth lines 
  glBegin(GL_LINES);
    for(int i=0; i<60; i++){
  float c = cos(i*angle1min), s = sin(i*angle1min);
      if(i%5){ // normal minute
        if(i%5 == 1)
          	glColor3f(1.0f, 1.0f, 1.0f);
          	//The following is to draw white lines around the circle
	        glVertex2f( clockR*minStart*c, clockR*minStart*s);
	        glVertex2f( clockR*minEnd*c, clockR*minEnd*s);
      }else{
        glColor3f(0.0f, 1.0f, 0.0f);
          //The following is to draw red long lines around the circle
          	glVertex2f( clockR*stepStart*c, clockR*stepStart*s);
        	glVertex2f( clockR*stepEnd*c, clockR*stepEnd*s);
      }
    }
  glEnd();
  
  
	numbers();
	//the following is for second hand
	glColor3f(0.0f, 1.0f, 0.0f);
	glPushMatrix();
		glTranslatef(-1,3,0);
		glPushMatrix();
		glRotatef(-angleSec,0,0,1);
			glPushMatrix();
		 	glTranslatef(1,-3,0);
			glBegin(GL_LINES);
				glVertex2i(-1,3);
				glVertex2i(9,-45);
 			glEnd();
 
		  	glBegin(GL_TRIANGLES);
			  	glVertex2i(9,-48);
			 	glVertex2i(9,-42);
			 	glVertex2i(9,-40);
 			glEnd();
 			glPopMatrix();
		glPopMatrix();
	glPopMatrix();
 //for minute hand
 glLineWidth(8);
 glColor3f(0.0, 0.0, 1.0);
 glPushMatrix();
	glTranslatef(-1,3,0);
	glPushMatrix();
	glRotatef(-angleMin,0,0,1);
	glPushMatrix();
		 glTranslatef(1,-3,0);
		 glBegin(GL_LINES);
			 glVertex2i(-1,3);
			 glVertex2i(40,2);
		 glEnd();
		 glBegin(GL_TRIANGLES);
			 glVertex2i(40,-3);
			 glVertex2i(40,7);
			 glVertex2i(45,2);
 		glEnd();
 		glPopMatrix();
  	glPopMatrix();
  glPopMatrix();
 //for hour hand
 glLineWidth(10);
 glColor3f(1.0f, 0.0f, 0.0f);
 glPushMatrix();
 glTranslatef(-1,3,0);
 glPushMatrix();
	glRotatef(-angleHour,0,0,1);
	glPushMatrix();
	 	glTranslatef(1,-3,0);
		glBegin(GL_LINES);
	 		glVertex2i(-1,3);
	 		glVertex2i(0,35);
	 	glEnd();
	 	glBegin(GL_TRIANGLES);
			 glVertex2i(-5,35);
			 glVertex2i(0,40);
			 glVertex2i(5,35);
	 	glEnd();
 		glPopMatrix();
  	glPopMatrix();
  glPopMatrix();
  //circle design
glPushMatrix();
glTranslatef(-140,-160,0);
  float Xpos = 140, Ypos = 160, radius = 90;
  glColor3f(1.0, 0.0, 0.0);
 
  glBegin(GL_LINE_STRIP);
  for (float i = 0; i < 360; i += 0.01)
    glVertex2f(Xpos + sin(i) * radius, Ypos + cos(i) * radius);
  glEnd();
   
  radius=80;
  glColor3f(0.0, 1.0, 0.0);
   glBegin(GL_LINE_STRIP);
  	for (float i = 0; i < 360; i += 0.01)
    glVertex2f(Xpos + sin(i) * radius, Ypos + cos(i) * radius);
   glEnd();
   radius=85;
   glColor3f(1.0, 1.0, 0.0);
   glBegin(GL_LINE_STRIP);
  	for (float i = 0; i < 360; i += 0.01)
    glVertex2f(Xpos + sin(i) * radius, Ypos + cos(i) * radius);
  glEnd();
  glLineWidth(15);
  glPopMatrix();
  glColor3f(1.0, 0.5, 0.5);
  glPointSize(12);
  glBegin(GL_POINTS);
	glVertex2i(-1,3);
  glEnd();
  //int a=10;
  glColor3f(0, 0, 0);
  glLineWidth(2.0);
  glBegin(GL_LINES);//1
    glVertex2i(-20, -50);
    glVertex2i(-20, -44);
    glEnd();
    glBegin(GL_LINES);//1
    glVertex2i(-17, -50);
    glVertex2i(-17, -44);
    glEnd();
    glBegin(GL_LINES);//9
    glVertex2i(-11, -50);
    glVertex2i(-11, -44);
    glVertex2i(-11, -44);
    glVertex2i(-14, -44);
    glVertex2i(-14, -44);
    glVertex2i(-14, -47);
    glVertex2i(-14, -47);
    glVertex2i(-11, -47);
    glEnd();
    glBegin(GL_LINES);//1
    glVertex2i(-8, -50);
    glVertex2i(-8, -44);
    glEnd();
    glBegin(GL_LINES);//6
    glVertex2i(-2, -44);
    glVertex2i(-5, -44);
    glVertex2i(-5, -44);
    glVertex2i(-5, -47);
    glVertex2i(-5, -47);
    glVertex2i(-2, -47);
    glVertex2i(-2, -47);
    glVertex2i(-2, -50);
    glVertex2i(-2, -50);
    glVertex2i(-5, -50);
    glVertex2i(-5, -50);
    glVertex2i(-5, -47);
    glEnd();
    glBegin(GL_LINES);//3
    glVertex2i(1, -50);
    glVertex2i(4, -50);
    glVertex2i(4, -50);
    glVertex2i(4, -47);
    glVertex2i(4, -47);
    glVertex2i(1, -47);
    glVertex2i(4, -47);
    glVertex2i(4, -44);
    glVertex2i(4, -44);
    glVertex2i(1, -44);
    glEnd();
    glBegin(GL_LINES);//9
    glVertex2i(10, -50);
    glVertex2i(10, -44);
    glVertex2i(10, -44);
    glVertex2i(7, -44);
    glVertex2i(7, -44);
    glVertex2i(7, -47);
    glVertex2i(7, -47);
    glVertex2i(10, -47);
    glEnd();
    glBegin(GL_LINES);//5
    glVertex2i(13, -50);
    glVertex2i(16, -50);
    glVertex2i(16, -50);
    glVertex2i(16, -47);
    glVertex2i(16, -47);
    glVertex2i(13, -47);
    glVertex2i(13, -47);
    glVertex2i(13, -44);
    glVertex2i(13, -44);
    glVertex2i(16, -44);
    glEnd();
glFlush();  
}
//rotate function manages how the hour,minute and second 
//hand are simulated
void rotate() 
{
	if(angleSec<360)
	{
		angleSec+=0.03;
	}
	else
	{
		angleSec=0;
	}
  if(angleMin<360)
	{
		angleMin+=0.00085;
	}
	else
	{
		angleMin=0;
	}
  if(angleHour<360)
	{
		angleHour+=0.0000146;
	}
	else
	{
		angleHour=0;
	}
	glutPostRedisplay();
}
int main(int argc, char* argv[]){
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(100,10);
  glutInitWindowSize(1080,780);
  glutCreateWindow(" Analog clock");
  init();
  glutDisplayFunc(Display);
  glutIdleFunc(rotate);
  glutMainLoop();
  return 0;
}


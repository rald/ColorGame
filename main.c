#include<GL/glut.h>
#include<GL/gl.h>

#include<math.h>
#include<time.h>


/*Matrix for the vertices of Cubes*/
static GLfloat vert[][4]={
	{ 1.0,  1.0,  1.0},
	{-1.0,  1.0,  1.0},
	{-1.0, -1.0,  1.0},
	{ 1.0, -1.0,  1.0},
	{ 1.0,  1.0, -1.0},
	{-1.0,  1.0, -1.0},
	{-1.0, -1.0, -1.0},
	{ 1.0, -1.0, -1.0},
};

/*Matrix for the color of sides of Cubes*/
static GLfloat color[][4]={
	{1.0, 0.0, 0.0, 0.0},
	{0.0, 0.5, 0.0, 0.0},
	{0.0, 0.0, 1.0, 0.0},
	{1.0, 0.0, 1.0, 0.0},
	{1.0, 1.0, 0.0, 0.0},
	{1.0, 1.0, 1.0, 0.0},
};


static GLfloat rx[3],ry[3],rz[3];
static GLfloat rxi=0,ryi=0,rzi=0;
static int c=0;

void drawCube() {
	glBegin(GL_QUADS);
		glColor3fv(color[0]);
		glVertex3fv(vert[0]);
		glVertex3fv(vert[1]);
		glVertex3fv(vert[2]);
		glVertex3fv(vert[3]);

		glColor3fv(color[1]);
		glVertex3fv(vert[4]);		
		glVertex3fv(vert[5]);		
		glVertex3fv(vert[6]);		
		glVertex3fv(vert[7]);		

		glColor3fv(color[2]);
		glVertex3fv(vert[0]);		
		glVertex3fv(vert[1]);		
		glVertex3fv(vert[5]);		
		glVertex3fv(vert[4]);

		glColor3fv(color[3]);
		glVertex3fv(vert[2]);		
		glVertex3fv(vert[3]);		
		glVertex3fv(vert[7]);		
		glVertex3fv(vert[6]);

		glColor3fv(color[4]);
		glVertex3fv(vert[3]);		
		glVertex3fv(vert[0]);		
		glVertex3fv(vert[4]);		
		glVertex3fv(vert[7]);

		glColor3fv(color[5]);
		glVertex3fv(vert[1]);		
		glVertex3fv(vert[2]);		
		glVertex3fv(vert[6]);		
		glVertex3fv(vert[5]);		

	glEnd();
}

void display_func(void) {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
  glTranslatef(-4.0f, 0.0f, 0.0f);
	glRotatef(rx[0], 1.0, 0.0, 0.0); 
	glRotatef(ry[0], 0.0, 1.0, 0.0); 
	glRotatef(rz[0], 0.0, 0.0, 1.0); 
	drawCube();
	glPopMatrix();

	glPushMatrix();
  glTranslatef(0.0f, 0.0f, 0.0f);
	glRotatef(rx[1], 1.0, 0.0, 0.0); 
	glRotatef(ry[1], 0.0, 1.0, 0.0); 
	glRotatef(rz[1], 0.0, 0.0, 1.0); 
	drawCube();
	glPopMatrix();

	glPushMatrix();
  glTranslatef(4.0f, 0.0f, 0.0f);
	glRotatef(rx[2], 1.0, 0.0, 0.0); 
	glRotatef(ry[2], 0.0, 1.0, 0.0); 
	glRotatef(rz[2], 0.0, 0.0, 1.0); 
	drawCube();
	glPopMatrix();

	glutSwapBuffers();	
}

void reshape_func(int width, int height)
{
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
//	glFrustum(-1.0, 1.0, -1.0, 1.0, 3.0, 10000.0);
	glOrtho(-7.0, 7.0, 7.0, -7.0, -7.0, 7.0);
	glMatrixMode(GL_MODELVIEW);
}

void idle_func() {
	if(c>0) {
		c--;
		for(int i=0;i<3;i++) {
			rx[i]+=rxi;
			ry[i]+=ryi;
			rz[i]+=rzi;
		}
		glutPostRedisplay();
	}
}

void keyboard_func (unsigned char key, int x, int y) {
	switch (key) {
		case ' ':
			if(c==0) { 
				c=(rand()%4+1)*90/5; 
				rxi=(rand()%2?1:-1)*5;
				ryi=(rand()%2?1:-1)*5;
				rzi=(rand()%2?1:-1)*5; 
				for(int i=0;i<3;i++) {
					rx[i]=(rand()%4)*90;
					ry[i]=(rand()%4)*90;
					rz[i]=(rand()%4)*90;
				}
			}
			break;
		case 27:
			exit(0);
		 	break;
		default:
			break;
	}
}

int main(int argc, char *argv[]) {

	srand(time(NULL));

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(320,240);
	glutCreateWindow("Color Cube");
	glutDisplayFunc(display_func);
	glutReshapeFunc(reshape_func);
	glutKeyboardFunc(keyboard_func);
	glutIdleFunc(idle_func);

	glEnable(GL_DEPTH_TEST);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-10.0, 10.0, 10.0, -10.0, -10.0, 10.0);
	glMatrixMode(GL_MODELVIEW);

	for(int i=0;i<3;i++) {
		rx[i]=(rand()%4)*90*(rand()%2?1:-1);
		ry[i]=(rand()%4)*90*(rand()%2?1:-1);
		rz[i]=(rand()%4)*90*(rand()%2?1:-1);
	}
	

	glutMainLoop();
	return 0;
}



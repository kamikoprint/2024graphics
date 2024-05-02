#include <GL/glut.h>
void myBody()
{
    glPushMatrix();
        glColor3f(1, 1, 1);
        glutWireCube( 0.6 );///myBody();
    glPopMatrix();
}
void myArm()
{
    glPushMatrix();
        glColor3f(0, 1, 1);
        glScalef(1, 0.4, 0.4);///myArm();
        glutWireCube(0.3);
    glPopMatrix();
}
float angle = 0;
void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	myBody();///我的身體
	glPushMatrix();
        glTranslatef(0.3, 0.3, 0);///(3)掛在肩上
        glRotatef(angle++, 0, 0,1);///(2)旋轉
        glTranslatef(0.15,0,0);///(1)把旋轉中心移到正中心
        myArm();///我的手臂
    glPopMatrix();

	glutSwapBuffers();
}
int main(int argc, char*argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("week11-1");
	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutMainLoop();
}

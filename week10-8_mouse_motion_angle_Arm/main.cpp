#include <GL/glut.h>
void myBody()
{
    glPushMatrix();
        glColor3f(1, 0, 1);
        glutWireCube( 0.6 );///myBody();
    glPopMatrix();
}
void myArm()
{
    glPushMatrix();
        glColor3f(1, 1, 1);
        glScalef(1, 0.4, 0.4);///myArm();
        glutWireCube(0.3);
    glPopMatrix();
}
float angle = 0;
void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	myBody();///�ڪ�����

	glPushMatrix();///�k�b��
        glTranslated(0.3, 0.3, 0);///(3)����ӤW
        glRotatef(angle, 0, 0 ,1);///(2)����
        glTranslatef(0.15, 0, 0);///(1)����त�ߩ�b�e����������
        myArm();///�ڪ����u
        glPushMatrix();
            glTranslated(0.15, 0, 0);///(3)����ӤW
            glRotatef(angle, 0, 0 ,1);///(2)����
            glTranslatef(0.15, 0, 0);///(1)����त�ߩ�b�e����������
            myArm();///�ڪ����u
        glPopMatrix();
	glPopMatrix();

	glPushMatrix();///���b��
        glTranslated(-0.3, 0.3, 0);///(3)����ӤW
        glRotatef(-angle, 0, 0 ,1);///(2)����
        glTranslatef(-0.15, 0, 0);///(1)����त�ߩ�b�e����������
        myArm();///�ڪ����u
        glPushMatrix();
            glTranslated(-0.15, 0, 0);///(3)����ӤW
            glRotatef(-angle, 0, 0 ,1);///(2)����
            glTranslatef(-0.15, 0, 0);///(1)����त�ߩ�b�e����������
            myArm();///�ڪ����u
        glPopMatrix();
	glPopMatrix();

	glutSwapBuffers();
}
void motion(int x, int y)
{
    angle = x;
    glutPostRedisplay();
}
int main(int argc, char*argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("week09-2 glutSoildTeapot");

	glutDisplayFunc(display);
	glutIdleFunc(display);///���ŴN����
	glutMotionFunc(motion);
	glutMainLoop();
}

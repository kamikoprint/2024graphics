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

	myBody();///我的身體

	glPushMatrix();///右半邊
        glTranslated(0.3, 0.3, 0);///(3)掛到肩上
        glRotatef(angle, 0, 0 ,1);///(2)旋轉
        glTranslatef(0.15, 0, 0);///(1)把旋轉中心放在畫面的正中心
        myArm();///我的手臂
        glPushMatrix();
            glTranslated(0.15, 0, 0);///(3)掛到肩上
            glRotatef(angle, 0, 0 ,1);///(2)旋轉
            glTranslatef(0.15, 0, 0);///(1)把旋轉中心放在畫面的正中心
            myArm();///我的手臂
        glPopMatrix();
	glPopMatrix();

	glPushMatrix();///左半邊
        glTranslated(-0.3, 0.3, 0);///(3)掛到肩上
        glRotatef(-angle, 0, 0 ,1);///(2)旋轉
        glTranslatef(-0.15, 0, 0);///(1)把旋轉中心放在畫面的正中心
        myArm();///我的手臂
        glPushMatrix();
            glTranslated(-0.15, 0, 0);///(3)掛到肩上
            glRotatef(-angle, 0, 0 ,1);///(2)旋轉
            glTranslatef(-0.15, 0, 0);///(1)把旋轉中心放在畫面的正中心
            myArm();///我的手臂
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
	glutIdleFunc(display);///有空就旋轉
	glutMotionFunc(motion);
	glutMainLoop();
}

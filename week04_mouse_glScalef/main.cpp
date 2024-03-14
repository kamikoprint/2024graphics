#include <GL/glut.h>
float angle = 0; ///旋轉角度
float s=1;///縮放的比例
void display()
{
    glClearColor(1.0, 0.0, 0.9, 1.0);///清背景的淡黃色
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);///清背景
    glPushMatrix();
        ///glRotatef(angle, 0, 0, 1);
        glScalef(s, s, s);///縮放
        glutSolidTeapot(0.3);
    glPopMatrix();
    glutSwapBuffers();
}
void motion(int x, int y)
{
    ///angle = x;
    s = 1+ (x-150)/150.0;
    display();
}
int main(int argc, char*argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week04 mouse glScalef");
    glutDisplayFunc(display);
    glutMotionFunc(motion);

    glutMainLoop();
}

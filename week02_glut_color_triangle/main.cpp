#include <GL/glut.h>

void display()
{
    glBegin(GL_POLYGON);///開始畫(多邊形)
        glColor3f(1,0,0); glVertex2f(0, 1);
        glColor3f(0,1,0); glVertex2f(+1, -0.6);
        glColor3f(0,0,1); glVertex2f(-1, -0.6);
    glEnd();///結束畫
    glutSwapBuffers();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("GLUT Shapes");
    glutDisplayFunc(display);

    glutMainLoop();
}

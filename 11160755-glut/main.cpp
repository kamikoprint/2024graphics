#include <GL/glut.h>

void display()
{
    glBegin(GL_POLYGON);
        glColor3f(4/255.0, 25/255.0, 46/255.0);
        glVertex2f((0-200)/200.0, -(0-200)/200.0);
        glVertex2f((225-200)/200.0, -(0-200)/200.0);
        glVertex2f((225-200)/200.0, -(225-200)/200.0);
        glVertex2f((0-200)/200.0, -(225-200)/200.0);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3f(255/255.0, 70/255.0, 84/255.0);
        glVertex2f((43-200)/200.0, -(55-200)/200.0);
        glVertex2f((43-200)/200.0, -(112-200)/200.0);
        glVertex2f((89-200)/200.0, -(169-200)/200.0);
        glVertex2f((133-200)/200.0, -(169-200)/200.0);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f((119-200)/200.0, -(131-200)/200.0);
        glVertex2f((167-200)/200.0, -(131-200)/200.0);
        glVertex2f((180-200)/200.0, -(112-200)/200.0);
        glVertex2f((180-200)/200.0, -(56-200)/200.0);
    glEnd();
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

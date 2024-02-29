#include <GL/glut.h>
#include <math.h>

void display()
{
    glBegin(GL_POLYGON);
    glColor3f(247/255.0, 180/255.0, 171/255.0);
    for(float a=0;a<3.14159*2;a+=0.1){
        glVertex2f(0.2*cos(a)+0.5, 0.2*sin(a)+0.5 );
    }
    glEnd();///µ²§ôµe
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

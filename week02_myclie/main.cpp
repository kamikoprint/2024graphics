#include <GL/glut.h>
#include <math.h>

void myCircle(float x, float y, float r){
    glBegin(GL_POLYGON);
    glColor3f(247/255.0, 180/255.0, 171/255.0);
    for(float a=0;a<3.14159*2;a+=0.1){
        glVertex2f(r*cos(a)+x, r*sin(a)+y );
    }
    glEnd();///�����e
}
void display()
{
    myCircle( 0.5, 0.5, 0.3);
    myCircle(-0.5, 0.5, 0.3);
    myCircle( 0,  -0.1, 0.6);
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


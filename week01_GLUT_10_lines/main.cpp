#include <GL/glut.h>///��18��d�U�ӡA�ϥ�GLUT�~��

void display()
{
    glutSolidTeapot( 0.3 );
    glutSwapBuffers();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);///��140��A�}��GLUT�\��
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);///143��A�]�w��ܼҦ�
    glutCreateWindow("GLUT Shapes");///145��A�}�@��GLUT����
    glutDisplayFunc(display);///148��A�n��display()�t���Ӷ}��

    glutMainLoop();///174��A�D�n���j��A�b�o�̤@���B�@�A������
}

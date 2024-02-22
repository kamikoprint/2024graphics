#include <GL/glut.h>///第18行留下來，使用GLUT外掛

void display()
{
    glutSolidTeapot( 0.3 );
    glutSwapBuffers();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);///第140行，開啟GLUT功能
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);///143行，設定顯示模式
    glutCreateWindow("GLUT Shapes");///145行，開一個GLUT視窗
    glutDisplayFunc(display);///148行，要用display()含式來開圖

    glutMainLoop();///174行，主要的迴圈，在這裡一直運作，不結束
}

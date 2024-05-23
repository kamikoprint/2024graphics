///���� week08-1_glm_gundam ���{���K�W��
///���@�U, �n�A�[�K�Ϫ� 18��{��
#include <opencv/highgui.h> ///�ϥ� OpenCV 2.1 ���²��, �u�n�� High GUI �Y�i
#include <opencv/cv.h>
#include <GL/glut.h>
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCVŪ��
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV���m (�ݭncv.h)
    glEnable(GL_TEXTURE_2D); ///1. �}�ҶK�ϥ\��
    GLuint id; ///�ǳƤ@�� unsigned int ���, �s �K��ID
    glGenTextures(1, &id); /// ����Generate �K��ID
    glBindTexture(GL_TEXTURE_2D, id); ///�j�wbind �K��ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// �K�ϰѼ�, �W�L�]�˪��d��T, �N���жK��
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// �K�ϰѼ�, �W�L�]�˪��d��S, �N���жK��
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// �K�ϰѼ�, ��j�ɪ�����, �γ̪��I
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// �K�ϰѼ�, �Y�p�ɪ�����, �γ̪��I
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}
#include <GL/glut.h>
#include "glm.h"
GLMmodel * Pmodel = NULL;
GLMmodel * handA = NULL;
GLMmodel * handB = NULL;
GLMmodel * UpperA = NULL;
GLMmodel * LowerA = NULL;
GLMmodel * body = NULL;
void drawBody(void)
{
    if (!body) {
	body = glmReadOBJ("data/body.obj");
	if (!body) exit(0);
	glmUnitize(body);
	glmFacetNormals(body);
	glmVertexNormals(body, 90.0);
    }

    glmDraw(body, GLM_SMOOTH | GLM_TEXTURE);
}
void drawUpperA(void)
{
    if (!UpperA) {
	UpperA = glmReadOBJ("data/UpperA.obj");
	if (!UpperA) exit(0);
	glmUnitize(UpperA);
	glmFacetNormals(UpperA);
	glmVertexNormals(UpperA, 90.0);
    }

    glmDraw(UpperA, GLM_SMOOTH | GLM_TEXTURE);
}
void drawLowerA(void)
{
    if (!LowerA) {
	LowerA = glmReadOBJ("data/LowerA.obj");
	if (!LowerA) exit(0);
	glmUnitize(LowerA);
	glmFacetNormals(LowerA);
	glmVertexNormals(LowerA, 90.0);
    }

    glmDraw(LowerA, GLM_SMOOTH | GLM_TEXTURE);
}
void myBody()
{
    glPushMatrix();
        glColor3f( 1, 1, 1);
        glutSolidCube( 0.6 );///myBody();
    glPopMatrix();
}
///float angle = 0, da = 1; ///�[�o��, �������
float angle[20] = {};
int angleID = 0;
int oldX = 0, oldY = 0;
#include <stdio.h>
FILE * fin = NULL;
FILE * fout = NULL;
void motion(int x, int y)
{
    angle[angleID] += y - oldY;
    oldX = x;
    oldY = y;
    glutPostRedisplay();///�n���e�e��
    ///���Ӫ��{���ű��A�K��keyboard��
}
void mouse(int button, int state, int x, int y)
{
    oldX = x;
    oldY = y;
}
float oldAngle[20] = {}, newAngle[20] = {};
void timer(int t)
{
    glutTimerFunc(50, timer, t+1);
    if(t%20==0){
        if(fin == NULL) fin = fopen("angle.txt", "r");
        for(int i=0; i<20; i++){///�w��20�����`
            oldAngle[i] = newAngle[i];
            fscanf(fin, "%f", & newAngle[i] );
        }
    }
    float alpha = (t%20) / 20.0;
    for(int i=0; i<20; i++){///�w��20�����`
        angle[i] = newAngle[i]*alpha + oldAngle[i]*(1-alpha);
    }
    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y)
{
    if(key=='p'){///play����
        glutTimerFunc(0, timer, 0);
    }
    if(key=='r'){
        if(fin == NULL) fopen("angle.txt", "r");
        for(int i=0; i<20; i++){
            fscanf(fin, "%f", & angle[i] );
        }
        glutPostRedisplay();
    }
    else if(key=='s'){
        if(fout == NULL) fout = fopen("angle.txt", "w+");
        for(int i=0; i<20; i++){
            printf("%.1f ", angle[i] );
            fprintf(fout, "%.1f ", angle[i] );
        }
        printf("\n");
        fprintf(fout, "\n");
    }
    if(key == '0') angleID = 0;
    if(key == '1') angleID = 1;
    if(key == '2') angleID = 2;
    if(key == '3') angleID = 3;

}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    ///glDisable(GL_TEXTURE_2D);

    glPushMatrix();
        glRotatef(angle[0], 0, 1, 0);
        glEnable(GL_TEXTURE_2D);
        drawBody();
        ///glutSolidSphere(0.1, 30, 30);
        glColor3f(1, 1, 1);

        glPushMatrix();
            glTranslatef(-0.1, 0, 0);
            glRotatef(angle[1], 0, 0, 1);
            glRotatef(angle[2], 1, 0, 0);
            glTranslatef(0, -0.07, 0);
            drawUpperA();
            glPushMatrix();
                glTranslatef(-0.02, -0.09, 0);
                glRotatef(angle[3], 1, 0, 0);
                glTranslatef(0, -0.21, 0);
                drawLowerA();
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();

    glutSwapBuffers();
}

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, -5.0f, 0.0f };///�[�o��, �������

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };
///void timer(int t)///�N�{���Ϊ��{���X�����ѱ�
///{
   /// glutTimerFunc(1000, timer, t+1);
   /// printf("�{�b�_��: %d\n", t);
///}
int main(int argc, char*argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week12-3 Gundam");
    glutDisplayFunc(display);
    glutIdleFunc(display); ///�[�o��, �������
    glutMouseFunc(mouse);///�j�H���B�c
    glutMotionFunc(motion);///�ƹ��ޱ�
    glutKeyboardFunc(keyboard);
    ///glutTimerFunc(0, timer ,0);

    myTexture("data/Diffuse.jpg");

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    glutMainLoop();
}
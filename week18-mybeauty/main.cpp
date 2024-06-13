///先把 week08-1_glm_gundam 的程式貼上來
///等一下, 要再加貼圖的 18行程式
#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>
#include <GL/glut.h>
float teapotX=0, teapotY=0;
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCV讀圖
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV轉色彩 (需要cv.h)
    glEnable(GL_TEXTURE_2D); ///1. 開啟貼圖功能
    GLuint id; ///準備一個 unsigned int 整數, 叫 貼圖ID
    glGenTextures(1, &id); /// 產生Generate 貼圖ID
    glBindTexture(GL_TEXTURE_2D, id); ///綁定bind 貼圖ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖T, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖S, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// 貼圖參數, 放大時的內插, 用最近點
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// 貼圖參數, 縮小時的內插, 用最近點
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}
#include <GL/glut.h>
#include "glm.h"
GLMmodel * Pmodel = NULL;
GLMmodel * handA = NULL;
GLMmodel * handB = NULL;
GLMmodel * footA = NULL;
GLMmodel * footB = NULL;
GLMmodel * UpperA = NULL;
GLMmodel * LowerA = NULL;
GLMmodel * UpperB = NULL;
GLMmodel * LowerB = NULL;
GLMmodel * upA = NULL;
GLMmodel * upB = NULL;
GLMmodel * downA = NULL;
GLMmodel * downB = NULL;
GLMmodel * body = NULL;
GLMmodel * head = NULL;
void drawhead(void)
{
    if (!head) {
	head = glmReadOBJ("data/head.obj");
	if (!head) exit(0);
	glmUnitize(head);
	glmFacetNormals(head);
	glmVertexNormals(head, 90.0);
    }

    glmDraw(head, GLM_SMOOTH | GLM_TEXTURE);
}
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
void drawUpperB(void)
{
    if (!UpperB) {
	UpperB = glmReadOBJ("data/UpperB.obj");
	if (!UpperB) exit(0);
	glmUnitize(UpperB);
	glmFacetNormals(UpperB);
	glmVertexNormals(UpperB, 90.0);
    }

    glmDraw(UpperB, GLM_SMOOTH | GLM_TEXTURE);
}
void drawLowerB(void)
{
    if (!LowerB) {
	LowerB = glmReadOBJ("data/LowerB.obj");
	if (!LowerB) exit(0);
	glmUnitize(LowerB);
	glmFacetNormals(LowerB);
	glmVertexNormals(LowerB, 90.0);
    }

    glmDraw(LowerB, GLM_SMOOTH | GLM_TEXTURE);
}
void myBody()
{
    glPushMatrix();
        glColor3f( 1, 1, 1);
        glutSolidCube( 0.6 );///myBody();
    glPopMatrix();
}
///float angle = 0, da = 1; ///加這行, 讓它轉動
///float angle[20] = {};
float angleX[10] = {}, angleY[10] = {};
int angleID = 0;
int oldX = 0, oldY = 0;
#include <stdio.h>
FILE * fin = NULL;
FILE * fout = NULL;
void motion(int x, int y)
{
    if(0){
        teapotX += (x-oldX)/150.0;
        teapotY -= (y-oldY)/150.0;
        printf("glTranslatef(%.3f, %.3f, 0);\n", teapotX, teapotY);
    }else{
        angleX[angleID] += y - oldY;
        angleY[angleID] -= x - oldX;
    }
    oldX = x;
    oldY = y;
    glutPostRedisplay();///要重畫畫面
    ///把原來的程式剪掉，貼到keyboard裡
}
void mouse(int button, int state, int x, int y)
{
    oldX = x;
    oldY = y;
}
///float oldAngle[20] = {}, newAngle[20] = {};
float oldAngleX[10] = {}, newAngleX[10] = {};
float oldAngleY[10] = {}, newAngleY[10] = {};
void timer(int t)
{
    glutTimerFunc(50, timer, t+1);
    if(t%20==0){
        if(fin == NULL) fin = fopen("angle.txt", "r");
        for(int i=0; i<10; i++){///針對20個關節
            ///oldAngle[i] = newAngle[i];
            oldAngleX[i] = newAngleX[i];
            oldAngleY[i] = newAngleY[i];
            ///fscanf(fin, "%f", & newAngle[i] );
            fscanf(fin, "%f", & newAngleX[i] );
            fscanf(fin, "%f", & newAngleY[i] );
        }
    }
    float alpha = (t%20) / 20.0;
    for(int i=0; i<10; i++){///針對20個關節
        angleX[i] = newAngleX[i]*alpha + oldAngleX[i]*(1-alpha);
        angleY[i] = newAngleY[i]*alpha + oldAngleY[i]*(1-alpha);
    }
    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y)
{
    if(key=='p'){///play播放
        glutTimerFunc(0, timer, 0);
    }
    if(key=='r'){
        if(fin == NULL) fopen("angle.txt", "r");
        for(int i=0; i<10; i++){
            fscanf(fin, "%f", & angleX[i] );
            fscanf(fin, "%f", & angleY[i] );
        }
        glutPostRedisplay();
    }
    else if(key=='s'){
        if(fout == NULL) fout = fopen("angle.txt", "w+");
        for(int i=0; i<10; i++){
            printf("%.1f ", angleX[i] );
            printf("%.1f ", angleY[i] );
            fprintf(fout, "%.1f ", angleX[i] );
            fprintf(fout, "%.1f ", angleY[i] );
        }
        printf("\n");
        fprintf(fout, "\n");
    }
    if(key == '0') angleID = 0;
    if(key == '1') angleID = 1;
    if(key == '2') angleID = 2;
    if(key == '3') angleID = 3;
    if(key == '4') angleID = 4;
    if(key == '5') angleID = 5;
    if(key == '6') angleID = 6;
    if(key == '7') angleID = 7;
    if(key == '8') angleID = 8;
    if(key == '9') angleID = 9;
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    ///glDisable(GL_TEXTURE_2D);

    glutSolidSphere(0.02, 30, 30);
    glPushMatrix();
        //glRotatef(angleX[0], 1, 0, 0);
        ///glRotatef(angleY[0], 0, 1, 0);
        ///glEnable(GL_TEXTURE_2D);
        drawBody();
        glColor3f(1, 1, 1);

        glPushMatrix();
            glTranslatef(-0.267, 0.227, 0);//glTranslatef(teapotX, teapotY, 0);
            //glTranslatef(-0.300, 0.167, 0);
            glRotatef(angleX[1], 1, 0, 0);
            glRotatef(angleY[1], 0, 1, 0);
            //glTranslatef(-0.087, -0.113, 0);
            glTranslatef(-0.047, -0.073, 0);
            drawUpperA();
            glPushMatrix();
                glTranslatef(-0.073, -0.060, 0);
                //glTranslatef(-0.133, -0.113, 0);
                glRotatef(angleX[2], 1, 0, 0);
                glRotatef(angleY[2], 0, 1, 0);
                //glTranslatef(-0.100, -0.107, 0);
                glTranslatef(-0.053, -0.040, 0);
                drawLowerA();
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();

    glutSwapBuffers();
}

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, -5.0f, 0.0f };///加這行, 讓它轉動

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };
///void timer(int t)///將程式用的程式碼先註解掉
///{
   /// glutTimerFunc(1000, timer, t+1);
   /// printf("現在起來: %d\n", t);
///}
int main(int argc, char*argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week18 h");
    glutDisplayFunc(display);
    glutIdleFunc(display); ///加這行, 讓它轉動
    glutMouseFunc(mouse);///大象放到冰箱
    glutMotionFunc(motion);///滑鼠操控
    glutKeyboardFunc(keyboard);
    ///glutTimerFunc(0, timer ,0);

    ///myTexture("data/SmolinaTex.png");

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

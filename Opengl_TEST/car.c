#include <GL/glut.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <windows.h>
#include <GL/glaux.h>

#define WIDTH 1000
#define HEIGHT 800
GLfloat  xrot;   // X ƽ��
GLfloat  yrot;   // Y ƽ��
GLfloat  zrot;   // Z ƽ��
GLfloat  vxrot2;   // X ƽ��
GLfloat  vyrot2;   // Y ƽ��
GLfloat  vzrot2;   // Z ƽ��
GLfloat set;
GLfloat rot;
GLfloat scale=1;
GLuint  texture[1];  // �洢һ������
static GLfloat angle = 0.0f;
static const float points[][3] =
	{
		0.0f, 0.0f, 0.0f,//1
		0.0f, 0.0f, 0.5f,//2
		1.5f, 0.0f, 0.5f,//3
		1.5f, 0.0f, 0.0f,//4
		0.0f, 1.0f, 0.0f,//5
		0.0f, 1.0f, 0.5f,//6
		1.5f, 1.0f, 0.5f,//7
		1.5f, 1.0f, 0.0f,//8
	};
void DrawBack(void){
	glColor3f(1.0f, 1.0f, 1.0f);
	glBindTexture(GL_TEXTURE_2D, texture[0]);      // ѡ������
	glBegin(GL_QUADS);
	// ǰ��
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-5.0f, 0.0f, 5.0f); // ������ı��ε�����
	glTexCoord2f(1.0f, 0.0f); glVertex3f(5.0f, 0.0f, 5.0f); // ������ı��ε�����
	glTexCoord2f(1.0f, 1.0f); glVertex3f(5.0f, 0.0f, -5.0f); // ������ı��ε�����
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-5.0f, 0.0f, -5.0f); // ������ı��ε�����

	glTexCoord2f(0.0f, 0.0f); glVertex3f(-5.0f, 5.0f, 5.0f); // ������ı��ε�����
	glTexCoord2f(1.0f, 0.0f); glVertex3f(5.0f, 5.0f, 5.0f); // ������ı��ε�����
	glTexCoord2f(1.0f, 1.0f); glVertex3f(5.0f, 5.0f, -5.0f); // ������ı��ε�����
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-5.0f, 5.0f, -5.0f); // ������ı��ε�����

	glTexCoord2f(0.0f, 0.0f); glVertex3f(-5.0f, 0.0f, 5.0f); // ������ı��ε�����
	glTexCoord2f(1.0f, 0.0f); glVertex3f(5.0f, 0.0f, 5.0f); // ������ı��ε�����
	glTexCoord2f(1.0f, 1.0f); glVertex3f(5.0f, 5.0f, 5.0f); // ������ı��ε�����
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-5.0f, 5.0f, 5.0f); // ������ı��ε�����

	glTexCoord2f(0.0f, 0.0f); glVertex3f(-5.0f, 0.0f, -5.0f); // ������ı��ε�����
	glTexCoord2f(1.0f, 0.0f); glVertex3f(5.0f, 0.0f, -5.0f); // ������ı��ε�����
	glTexCoord2f(1.0f, 1.0f); glVertex3f(5.0f, 5.0f, -5.0f); // ������ı��ε�����
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-5.0f, 5.0f, -5.0f); // ������ı��ε�����
	glEnd();
	//glFlush();
}
void Drawxy(){
	glLineWidth(1);
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-10.0f, 0.0f, 0.0f);//X
	glVertex3f(10.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, -10.0f, 0.0f);//Y
	glVertex3f(0.0f, 10.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, -10.0f);
	glVertex3f(0.0f, 0.0f, 10.0f);//Z
	//	glVertex3f(0.0f, 1.0f, 0.0f);
	//	glVertex3f(5.0f, 1.0f, 0.0f);


	glVertex3f(5.0f, 0.3f, 0.0f);
	glVertex3f(5.1f, 0.2f, 0.0f);
	glVertex3f(5.0f, 0.2f, 0.0f);
	glVertex3f(5.1f, 0.3f, 0.0f);
	//X
	glVertex3f(0.3f, 5.2f, 0.0f);
	glVertex3f(0.3f, 5.0f, 0.0f);
	glVertex3f(0.2f, 5.3f, 0.0f);
	glVertex3f(0.3f, 5.2f, 0.0f);
	glVertex3f(0.4f, 5.3f, 0.0f);
	glVertex3f(0.3f, 5.2f, 0.0f);
	//Y
	glVertex3f(-0.1f, 1.0f, 3.0f);
	glVertex3f(0.1f, 1.0f, 3.0f);
	glVertex3f(0.1f, 1.0f, 3.0f);
	glVertex3f(-0.1f, 0.8f, 3.0f);
	glVertex3f(-0.1f, 0.8f, 3.0f);
	glVertex3f(0.1f, 0.8f, 3.0f);
	//Z
	glEnd();
}
void DrawBody(){

	
	glPushMatrix();
	glTranslatef(0.0, 0.3, 0.0);
	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 1.0f);
	//down,1234
	glVertex3f(points[0][0]+xrot, points[0][1]+yrot, points[0][2]+zrot);
	glVertex3f(points[1][0]+xrot, points[1][1]+yrot, points[1][2]+zrot);
	glVertex3f(points[2][0]+xrot, points[2][1]+yrot, points[2][2]+zrot);
	glVertex3f(points[3][0]+xrot, points[3][1]+yrot, points[3][2]+zrot);
	//up4567
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(points[4][0]+xrot, points[4][1]+yrot, points[4][2]+zrot);
	glVertex3f(points[5][0]+xrot, points[5][1]+yrot, points[5][2]+zrot);
	glVertex3f(points[6][0]+xrot, points[6][1]+yrot, points[6][2]+zrot);
	glVertex3f(points[7][0]+xrot, points[7][1]+yrot, points[7][2]+zrot);
	//front2367
	glColor3f(1.0f, 0.0f, 1.0f);
	glVertex3f(points[1][0]+xrot, points[1][1]+yrot, points[1][2]+zrot);
	glVertex3f(points[2][0]+xrot, points[2][1]+yrot, points[2][2]+zrot);
	glVertex3f(points[6][0]+xrot, points[6][1]+yrot, points[6][2]+zrot);
	glVertex3f(points[5][0]+xrot, points[5][1]+yrot, points[5][2]+zrot);
	//back4185
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(points[3][0]+xrot, points[3][1]+yrot, points[3][2]+zrot);
	glVertex3f(points[0][0]+xrot, points[0][1]+yrot, points[0][2]+zrot);
	glVertex3f(points[4][0]+xrot, points[4][1]+yrot, points[4][2]+zrot);
	glVertex3f(points[7][0]+xrot, points[7][1]+yrot, points[7][2]+zrot);

	//left1256
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(points[0][0]+xrot, points[0][1]+yrot, points[0][2]+zrot);
	glVertex3f(points[1][0]+xrot, points[1][1]+yrot, points[1][2]+zrot);
	glVertex3f(points[5][0]+xrot, points[5][1]+yrot, points[5][2]+zrot);
	glVertex3f(points[4][0]+xrot, points[4][1]+yrot, points[4][2]+zrot);
	//right3478
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(points[2][0]+xrot, points[2][1]+yrot, points[2][2]+zrot);
	glVertex3f(points[3][0]+xrot, points[3][1]+yrot, points[3][2]+zrot);
	glVertex3f(points[7][0]+xrot, points[7][1]+yrot, points[7][2]+zrot);
	glVertex3f(points[6][0]+xrot, points[6][1]+yrot, points[6][2]+zrot);
	glEnd();
	glPopMatrix();
}

void mySolidCylinder(GLUquadric*   quad,
	GLdouble base,
	GLdouble top,
	GLdouble height,
	GLint slices,
	GLint stacks)
{	//1	glLineWidth(3);
	glLineWidth(3);
	glPushMatrix();
	glTranslatef(0.0, 0.3, 0.0);
	glTranslatef(0.0f+xrot, 0.0f+yrot, -0.2f+zrot);
	glRotatef(rot /180, 0, 1, 0);
	//glTranslatef(0.0f, 0.0f, -0.3f);
	glColor3f(1, 1, 0);
	gluCylinder(quad, base, top, height, slices, stacks);
	glPopMatrix();

	//2
	glPushMatrix();
	glTranslatef(0.0, 0.3, 0.0);
	glTranslatef(0.0f+xrot, 0.0f+yrot, 0.5f+zrot);
	glRotatef(rot / 180, 0, 1, 0);
	//glTranslatef(0.0f, 0.0f, -0.3f);
	glColor3f(1, 1, 0);
	gluCylinder(quad, base, top, height, slices, stacks);
	glPopMatrix();
	//3
	glPushMatrix();
	glTranslatef(0.0, 0.3, 0.0);
	glTranslatef(1.5f+xrot, 0.0f+yrot, 0.5f+zrot);
	glRotatef(rot / 180, 0, 1, 0);
	//glTranslatef(0.0f, 0.0f, -0.3f);
	glColor3f(1, 1, 0);
	gluCylinder(quad, base, top, height, slices, stacks);
	glPopMatrix();
	//4
	glPushMatrix();
	glTranslatef(0.0, 0.3, 0.0);
	glTranslatef(1.5f+xrot, 0.0f+yrot, -0.2f+zrot);
	glRotatef(rot / 180, 0, 1, 0);
	//glTranslatef(0.0f, 0.0f, -0.3f);
	glColor3f(1, 1, 0);
	gluCylinder(quad, base, top, height, slices, stacks);
	glPopMatrix();

	//��̥��
	//glTranslatef(0.0f, 0.0f, -0.5f);
	//1
	glPushMatrix();	
	
	glTranslatef(0.0, 0.3, 0.0);
	glTranslatef(0.0f+xrot, 0.0f+yrot, 0.7f+zrot);
	glRotatef(rot / 180, 0, 1, 0);
	glRotatef(xrot/3.14/0.3*180,0,0,1);
	glColor3f(1, 1, 0);
	gluDisk(quad, 0, 0.3, 20, 4);
	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(3);
	glBegin(GL_LINES);
	glVertex3f(-top, 0.0, 0.0);
	glVertex3f(top, 0.0, 0.0);
	glVertex3f(0.0, base, 0);
	glVertex3f(0.0, -base, 0);
	glEnd();
	
	glPopMatrix();
	glPushMatrix();
	
	glTranslatef(0.0, 0.3, 0.0);
	glTranslatef(0.0f+xrot, 0.0f+yrot, 0.5f+zrot);
	glRotatef(rot / 180, 0, 1, 0);
	glRotatef(xrot / 3.14 / 0.3 * 180, 0, 0, 1);
	glColor3f(1, 1, 0);
	gluDisk(quad, 0, 0.3, 20, 4);
	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(3);
	glBegin(GL_LINES);
	glVertex3f(-top, 0.0, 0.0);
	glVertex3f(top, 0.0, 0.0);
	glVertex3f( 0.0,base, 0);
	glVertex3f( 0.0,-base, 0);
	glEnd();
	glPopMatrix();
	//2
	glPushMatrix();	
	glTranslatef(0.0, 0.3, 0.0);
	glTranslatef(1.5f+xrot, 0.0f+yrot, 0.7f+zrot);
	glRotatef(rot / 180, 0, 1, 0);
	glRotatef(xrot / 3.14 / 0.3 * 180, 0, 0, 1);
	glColor3f(1, 1, 0);
	gluDisk(quad, 0, 0.3, 20, 4);
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex3f(-top, 0.0, 0.0);
	glVertex3f(top, 0.0, 0.0);
	glVertex3f(0.0, base, 0);
	glVertex3f(0.0, -base, 0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, 0.3, 0.0);
	glTranslatef(1.5f+xrot, 0.0f+yrot, 0.5f+zrot);	
	glRotatef(rot / 180, 0, 1, 0);
	glRotatef(xrot / 3.14 / 0.3 * 180, 0, 0, 1);
	glColor3f(1, 1, 0);
	gluDisk(quad, 0, 0.3, 20, 4);
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex3f(-top, 0.0, 0.0);
	glVertex3f(top, 0.0, 0.0);
	glVertex3f(0.0, base, 0);
	glVertex3f(0.0, -base, 0);
	glEnd();
	glPopMatrix();
	
	//3
	glPushMatrix();
	
	glTranslatef(0.0, 0.3, 0.0);
	glTranslatef(1.5f+xrot, 0.0f+yrot, 0.0f+zrot);
	glRotatef(rot / 180, 0, 1, 0);
	glRotatef(xrot / 3.14 / 0.3 * 180, 0, 0, 1);
	glColor3f(1, 1, 0);
	gluDisk(quad, 0, 0.3, 20, 4);
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex3f(-top, 0.0, 0.0);
	glVertex3f(top, 0.0, 0.0);
	glVertex3f(0.0, base, 0);
	glVertex3f(0.0, -base, 0);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	
	glTranslatef(0.0, 0.3, 0.0);
	glTranslatef(1.5f+xrot, 0.0f+yrot, -0.2f+zrot);
	glRotatef(rot / 180, 0, 1, 0);
	glRotatef(xrot / 3.14 / 0.3 * 180, 0, 0, 1);
	glColor3f(1, 1, 0);
	gluDisk(quad, 0, 0.3, 20, 4);
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex3f(-top, 0.0, 0.0);
	glVertex3f(top, 0.0, 0.0);
	glVertex3f(0.0, base, 0);
	glVertex3f(0.0, -base, 0);
	glEnd();
	glPopMatrix();
	//4
	glPushMatrix();
	
	glTranslatef(0.0, 0.3, 0.0);
	glTranslatef(0.0f+xrot, 0.0f+yrot, -0.2f+zrot);
	glRotatef(rot / 180, 0, 1, 0);
	glRotatef(xrot / 3.14 / 0.3 * 180, 0, 0, 1);
	glColor3f(1, 1, 0);
	gluDisk(quad, 0, 0.3, 20, 4);
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex3f(-top, 0.0, 0.0);
	glVertex3f(top, 0.0, 0.0);
	glVertex3f(0.0, base, 0);
	glVertex3f(0.0, -base, 0);
	glEnd();
	glPopMatrix();
	glPushMatrix();

	glTranslatef(0.0, 0.3, 0.0);
	glTranslatef(0.0f+xrot, 0.0f+yrot, 0.0f+zrot);	
	glRotatef(rot / 180, 0, 1, 0);
	glRotatef(xrot / 3.14 / 0.3 * 180, 0, 0, 1);
	glColor3f(1, 1, 0);
	gluDisk(quad, 0, 0.3, 20, 4);
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex3f(-top, 0.0, 0.0);
	glVertex3f(top, 0.0, 0.0);
	glVertex3f(0.0, base, 0);
	glVertex3f(0.0, -base, 0);
	glEnd();
	glPopMatrix();
}
void DrawTyre(){

	//glTranslatef(0.0f, 0.0f, -0.5f);
	GLUquadricObj *quadratic;
	quadratic = gluNewQuadric();
	mySolidCylinder(quadratic, 0.3f, 0.3f, 0.2f, 32, 32);
	
}
boolean check(){
	if ((points[0][2] + zrot>5) || (points[3][2]+zrot<-5))
	return FALSE;
	if ((points[4][1] + yrot<0) || (points[4][1] + yrot>5))
		return FALSE;
	return TRUE;
}
void mydis(void)
{
	const GLfloat factor = 0.1f;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// ����͸��Ч����ͼ
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90.0f, 1.0f, 1.0f, 4000.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//gluLookAt(0.0, 5.0, 0.25, 0.0, 0.0, 0.25, 1.0, 0.0, 0.0);
	
	GLfloat x, y, z;
	x = 5.0 * cos(vyrot2/180)*scale;
	y = (5.0 * cos(vxrot2/180)+set)*scale;
	z = (5.0 * sin(vyrot2/180) +  5.0 * sin(vxrot2/180) )*scale;
	
	gluLookAt(x, y, z, 0.0, 0.0, 0.0, 0, 1, 0);

	if (check()){
	DrawBack();
	Drawxy();
	DrawBody();
	DrawTyre();
	}
	DrawBack();
	Drawxy();
	
	glutSwapBuffers();
	glFlush();
}
AUX_RGBImageRec *LoadBMP(CHAR *Filename)    // ����λͼͼ��
{
	FILE *File = NULL;         // �ļ����
	if (!Filename)          // ȷ���ļ������ṩ
	{
		return NULL;         // ���û�ṩ������ NULL
	}
	File = fopen(Filename, "r");       // ���Դ��ļ�
	if (File)           // �ļ�����ô?
	{
		fclose(File);         // �رվ��
		return auxDIBImageLoadA(Filename);    // ����λͼ������ָ��
	}
	return NULL;          // �������ʧ�ܣ����� NULL
}
int LoadGLTextures()         // ����λͼ(��������Ĵ���)��ת��������
{
	int Status = FALSE;         // ״ָ̬ʾ��
	AUX_RGBImageRec *TextureImage[1];     // ��������Ĵ洢�ռ�
	memset(TextureImage, 0, sizeof(void *)* 1);   // ��ָ����Ϊ NULL
	// ����λͼ��������޴������λͼû�ҵ����˳�
	if (TextureImage[0] = LoadBMP("map.bmp"))
	{
		Status = TRUE;         // �� Status ��Ϊ TRUE
		glGenTextures(1, &texture[0]);     // ��������

		// ʹ������λͼ�������� �ĵ�������
		glBindTexture(GL_TEXTURE_2D, texture[0]);
		// ��������
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage[0]->sizeX, TextureImage[0]->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage[0]->data);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); // �����˲�
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); // �����˲�
	}

	if (TextureImage[0])        // �����Ƿ����
	{
		if (TextureImage[0]->data)      // ����ͼ���Ƿ����
		{
			free(TextureImage[0]->data);    // �ͷ�����ͼ��ռ�õ��ڴ�
		}

		free(TextureImage[0]);       // �ͷ�ͼ��ṹ
	}
	return Status;          // ���� Status
}
void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);            //������ɫ��Ϊ��ɫ����Ҳ����Ϊ�Ǳ�����ɫ��

	                      //����ü�(���治�ɼ�)
	//glEnable(GL_CULL_FACE);                        //���òü�
	glEnable(GL_TEXTURE_2D);
	//glCullFace(GL_BACK);  
	LoadGLTextures();            //����������ͼ
}
void reshape(GLsizei w, GLsizei h)
{
	//����С˵��һ�£�����ģʽ�ǲ�ͬ�ģ����Ǹ�����һ������ͶӰ���
	//ֻ����ͶӰ����(ֻ��Ŀǰ�����Ŷ������ѧ���˿��ܾ�֪��Ϊʲô�ˡ�)

	glViewport(0, 0, w, h);        //�����ӿ�
	glMatrixMode(GL_PROJECTION);    //���þ���ģʽΪͶӰ�任����
	glLoadIdentity();                //��Ϊ��λ����
	gluPerspective(60, (GLfloat)w / h, 0, 1000);    //����ͶӰ����
	glMatrixMode(GL_MODELVIEW);        //���þ���ģʽΪ��ͼ����(ģ��)
	glLoadIdentity();                //��Ϊ��λ����
}
//���������¼�����
void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'd':    //�����¼�����dʱ������X����תΪ��
		xrot += 0.1f;   //������ת����
		glutPostRedisplay();   //�ػ溯��
		break;
	case 's':
		zrot += 0.1f;
		glutPostRedisplay();
		break;
	case 'a':
		xrot -= 0.1f;
		glutPostRedisplay();
		break;
	case 'w':
		zrot -= 0.1f;
		glutPostRedisplay();
		break;
		//��Xת��
	case 'i':    //�����¼�����dʱ������X����תΪ��
		vxrot2 += 10;   //������ת����
		glutPostRedisplay();   //�ػ溯��
		break;
	case 'k':
		vxrot2 -= 10;
		glutPostRedisplay();
		break;
		//��Y��ת��
	case 'j':
		vyrot2 -= 10;
		glutPostRedisplay();
		break;
	case 'l':
		vyrot2 += 10;
		glutPostRedisplay();
		break;
	case 'g':
		rot -= 30;
		glutPostRedisplay();
		break;
	case 'h':
		rot += 30;
		glutPostRedisplay();
		break;
	case '=':
		set+=0.1;
		glutPostRedisplay();
		break;
	case '-':
		set -= 0.1;
		glutPostRedisplay();
		break;
	case '[':
		scale += 0.1;
		glutPostRedisplay();
		break;
	case ']':
		scale -= 0.1;
		glutPostRedisplay();
		break;
	default:
		break;
	}
}
int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
	//glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("OpenGL������ʾ");
	init();
	glEnable(GL_DEPTH_TEST);
	//glutDisplayFunc(&myDisplay);
	//glutDisplayFunc(&mydis);
	//glutIdleFunc(&myIdle);
	LoadGLTextures();
	DrawBack();
	glutDisplayFunc(&mydis);
	glutReshapeFunc(reshape);                //����ͼ��ʱ�Ļص�
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}
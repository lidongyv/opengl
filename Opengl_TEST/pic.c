#include <GL/glut.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <windows.h>
#include <GL/glaux.h>

#define WIDTH 1000
#define HEIGHT 800
GLfloat  xrot;   // X ��ת��
GLfloat  yrot;   // Y ��ת��
GLfloat  zrot;   // Z ��ת��
GLuint  texture[1];  // �洢һ������
static GLfloat angle = 0.0f;
void DrawBack(void){

	glBindTexture(GL_TEXTURE_2D, texture[0]);      // ѡ������
	glBegin(GL_QUADS);
	// ǰ��
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-5.0f, 0.0f, 5.0f); // ������ı��ε�����
	glTexCoord2f(1.0f, 0.0f); glVertex3f(5.0f, 0.0f, 5.0f); // ������ı��ε�����
	glTexCoord2f(1.0f, 1.0f); glVertex3f(5.0f, 0.0f, -5.0f); // ������ı��ε�����
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-5.0f, 0.0f, -5.0f); // ������ı��ε�����
	glEnd();
	glFlush();
}
void DrawCircleArea(float cx, float cy, float cz, float r, int num_segments)
{
	GLfloat vertex[4];

	const GLfloat delta_angle = 2.0*3.14 / num_segments;
	glBegin(GL_TRIANGLE_FAN);

	vertex[0] = cx;
	vertex[1] = cy;
	vertex[2] = cz;
	vertex[3] = 1.0;
	glVertex4fv(vertex);

	//draw the vertex on the contour of the circle  
	for (int i = 0; i < num_segments; i++)
	{
		vertex[0] = cos(delta_angle*i) * r + cx;
		vertex[1] = sin(delta_angle*i) * r + cy;
		vertex[2] = cz;
		vertex[3] = 1.0;
		glVertex4fv(vertex);
	}

	vertex[0] = 1.0 * r + cx;
	vertex[1] = 0.0 * r + cy;
	vertex[2] = cz;
	vertex[3] = 1.0;
	glVertex4fv(vertex);
	glEnd();
}
void mySolidCylinder(GLUquadric*   quad,
	GLdouble base,
	GLdouble top,
	GLdouble height,
	GLint slices,
	GLint stacks)
{
	glColor3f(84.0 / 255, 0.0, 125.0 / 255.0);
	gluCylinder(quad, base, top, height, slices, stacks);
	//top  
	DrawCircleArea(0.0, 0.0, height, top, slices);
	//base  
	DrawCircleArea(0.0, 0.0, 0.0, base, slices);
}

void mydis(void)
{
	const GLfloat factor = 0.1f;
	glClear(GL_COLOR_BUFFER_BIT);
	// ����͸��Ч����ͼ
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90.0f, 1.0f, 1.0f, 40.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(5.0, 5.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	//glRotatef(45, 0.0f, -1.0f, 0.0f);
	//glRotatef(45, 0.0f, 0.0f, -1.0f);
	glTranslatef(-3.0f, 0.0f, 0.0f);
	glTranslatef(0.0f, 0.0f, -3.0f);
	
	DrawBack();
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
	//DrawBack();
	GLUquadricObj *quadratic;
	quadratic = gluNewQuadric();
	gluCylinder(quadratic, 0.6f, 0.6f, 0.4f, 32, 32);//��Բ��
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

	glCullFace(GL_BACK);                        //����ü�(���治�ɼ�)
	glEnable(GL_CULL_FACE);                        //���òü�
	glEnable(GL_TEXTURE_2D);
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
}/*
void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-1, 1, -1, 1, 1.5, 20);
	gluLookAt(1, 0, 8, 1, 0, -1, 0, 1, 0);
}*/
//���������¼�����
void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'd':    //�����¼�����dʱ������X����תΪ��
		xrot += 1.0f;   //������ת����
		glutPostRedisplay();   //�ػ溯��
		break;
	case 's':
		yrot += 1.0f;
		glutPostRedisplay();
		break;
	case 'a':
		zrot += 1.0f;
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
	//glutDisplayFunc(&myDisplay);
	//glutDisplayFunc(&mydis);
	//glutIdleFunc(&myIdle);
	LoadGLTextures();
	glutDisplayFunc(&mydis);
	glutReshapeFunc(reshape);                //����ͼ��ʱ�Ļص�
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}
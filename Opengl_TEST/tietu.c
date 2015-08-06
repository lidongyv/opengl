#include <GL/glut.h>  //������ذ�
#include <windows.h>
#include <GL/glaux.h>
#include <stdio.h>

GLfloat  xrot;   // X ��ת��
GLfloat  yrot;   // Y ��ת��
GLfloat  zrot;   // Z ��ת��
GLfloat  xmot;   // X �ƶ�
GLfloat  ymot;   // Y �ƶ�
GLfloat  zmot;   // Z �ƶ�
GLfloat  scot=1;   // ����
GLuint  texture[1];  // �洢һ������
GLuint  textureb[1];
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
int LoadGLTextures2()         // ����λͼ(��������Ĵ���)��ת��������
{
	int Status = FALSE;         // ״ָ̬ʾ��
	AUX_RGBImageRec *TextureImage[1];     // ��������Ĵ洢�ռ�
	memset(TextureImage, 0, sizeof(void *)* 1);   // ��ָ����Ϊ NULL
	// ����λͼ��������޴������λͼû�ҵ����˳�
	if (TextureImage[0] = LoadBMP("wall.bmp"))
	{
		Status = TRUE;         // �� Status ��Ϊ TRUE
		glGenTextures(1, &textureb[0]);     // ��������

		// ʹ������λͼ�������� �ĵ�������
		glBindTexture(GL_TEXTURE_2D, textureb[0]);
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
int LoadGLTextures()         // ����λͼ(��������Ĵ���)��ת��������
{
	int Status = FALSE;         // ״ָ̬ʾ��
	AUX_RGBImageRec *TextureImage[1];     // ��������Ĵ洢�ռ�
	memset(TextureImage, 0, sizeof(void *)* 1);   // ��ָ����Ϊ NULL
	// ����λͼ��������޴������λͼû�ҵ����˳�
	if (TextureImage[0] = LoadBMP("mf.bmp"))
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


void DrawCube(void)         // �����￪ʼ�������еĻ���
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // �����Ļ����Ȼ���
	glLoadIdentity();         // ���õ�ǰ��ģ�͹۲����
	
	glTranslatef(0.0f, 0.0f, -5.0f);  glTranslatef(xmot, ymot, zmot);       // ������Ļ 5 ����λ
	glRotatef(xrot, 1.0f, 0.0f, 0.0f);         // ��X����ת
	glRotatef(yrot, 0.0f, 1.0f, 0.0f);         // ��Y����ת
	glRotatef(zrot, 0.0f, 0.0f, 1.0f);         // ��Z����ת
	
	glScalef(scot,scot,scot);
	glBindTexture(GL_TEXTURE_2D, texture[0]);      // ѡ������
	glBegin(GL_QUADS);
	// ǰ��
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f); // ������ı��ε�����
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f); // ������ı��ε�����
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f); // ������ı��ε�����
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f); // ������ı��ε�����
	// ����
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f); // ������ı��ε�����
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f); // ������ı��ε�����
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f); // ������ı��ε�����
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f); // ������ı��ε�����
	// ����
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f); // ������ı��ε�����
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 1.0f, 1.0f); // ������ı��ε�����
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, 1.0f, 1.0f); // ������ı��ε�����
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f); // ������ı��ε�����
	// ����
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f); // ������ı��ε�����
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, -1.0f, -1.0f); // ������ı��ε�����
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f); // ������ı��ε�����
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f); // ������ı��ε�����
	// ����
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f); // ������ı��ε�����
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f); // ������ı��ε�����
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f); // ������ı��ε�����
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f); // ������ı��ε�����
	// ����f
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f); // ������ı��ε�����
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f); // ������ı��ε�����
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f); // ������ı��ε�����
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f); // ������ı��ε�����
	glEnd();


	glBindTexture(GL_TEXTURE_2D, textureb[0]);      // ѡ������
	glBegin(GL_QUADS);
	//// ǰ��
	//glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f); // ������ı��ε�����
	//glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f); // ������ı��ε�����
	//glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f); // ������ı��ε�����
	//glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f); // ������ı��ε�����
	//// ����
	//glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f); // ������ı��ε�����
	//glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f); // ������ı��ε�����
	//glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f); // ������ı��ε�����
	//glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f); // ������ı��ε�����
	// ����
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-4.0f, 4.0f, -4.0f); // ������ı��ε�����
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-4.0f, 4.0f, 4.0f); // ������ı��ε�����
	glTexCoord2f(1.0f, 0.0f); glVertex3f(4.0f, 4.0f, 4.0f); // ������ı��ε�����
	glTexCoord2f(1.0f, 1.0f); glVertex3f(4.0f, 4.0f, -4.0f); // ������ı��ε�����
	// ����
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-4.0f, -4.0f, -4.0f); // ������ı��ε�����
	glTexCoord2f(0.0f, 1.0f); glVertex3f(4.0f, -4.0f, -4.0f); // ������ı��ε�����
	glTexCoord2f(0.0f, 0.0f); glVertex3f(4.0f, -4.0f, 4.0f); // ������ı��ε�����
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-4.0f, -4.0f, 4.0f); // ������ı��ε�����
	// ����
	glTexCoord2f(1.0f, 0.0f); glVertex3f(4.0f, -4.0f, -4.0f); // ������ı��ε�����
	glTexCoord2f(1.0f, 1.0f); glVertex3f(4.0f, 4.0f, -4.0f); // ������ı��ε�����
	glTexCoord2f(0.0f, 1.0f); glVertex3f(4.0f, 4.0f, 4.0f); // ������ı��ε�����
	glTexCoord2f(0.0f, 0.0f); glVertex3f(4.0f, -4.0f, 4.0f); // ������ı��ε�����
	// ����
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-4.0f, -4.0f, -4.0f); // ������ı��ε�����
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-4.0f, -4.0f, 4.0f); // ������ı��ε�����
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-4.0f, 4.0f, 4.0f); // ������ı��ε�����
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-4.0f, 4.0f, -4.0f); // ������ı��ε�����
	glEnd();
	glFlush();
	//xrot += 0.3f;              // X ����ת
	//yrot += 0.2f;              // Y ����ת
	//zrot += 0.4f;              // Z ����ת
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


void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);    // �����ɫ���ݺ�������ݣ�������
	glLoadIdentity();                                    // Reset The View
	GLUquadric *pObj;
	pObj = gluNewQuadric();
	glTranslatef(0.0f, 0.0f, -5.0f);
	gluCylinder(pObj, 10.0, 10.0, 10.0, 32, 5);
	DrawCube();

	glutSwapBuffers();            //��������������ʾͼ��
}

//��ʼ��
void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);            //������ɫ��Ϊ��ɫ����Ҳ����Ϊ�Ǳ�����ɫ��

	glCullFace(GL_BACK);                        //����ü�(���治�ɼ�)
	glEnable(GL_CULL_FACE);                        //���òü�
	glEnable(GL_TEXTURE_2D);
	LoadGLTextures();            //����������ͼ
	LoadGLTextures2();
}

//�����ڴ�С�ı�ʱ��������������
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
	case 'j':    //�����¼�����dʱ������X����תΪ��
		xmot +=0.3f;   //������ת����
		glutPostRedisplay();   //�ػ溯��
		break;
	case 'l':
		xmot -= 0.3f;
		glutPostRedisplay();
		break;
	case 'i':
		ymot += 0.3f;
		glutPostRedisplay();
		break;
	case 'k':
		ymot -= 0.3f;
		glutPostRedisplay();
		break;
	case 'u':
		zmot += 0.3f;
		glutPostRedisplay();
		break;
	case 'o':
		zmot -= 0.3f;
		glutPostRedisplay();
		break;
	case '=':
		scot += 0.3f;
		glutPostRedisplay();
		break;
	case '-':
		scot -= 0.3f;
		glutPostRedisplay();
		break;
	default:
		break;
	}
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);  //�̶���ʽ
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(600, 600);    //��ʾ��Ĵ�С
	glutInitWindowPosition(100, 100); //ȷ����ʾ�����Ͻǵ�λ��
	glutCreateWindow("OpenGL������ͼ");
	init();                                //��ʼ����Դ,����һ��Ҫ�ڴ��������Ժ󣬲�Ȼ����Ч��
	LoadGLTextures();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);                //����ͼ��ʱ�Ļص�
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}
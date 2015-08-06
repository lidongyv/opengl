#include <GL/glut.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <windows.h>
#include <GL/glaux.h>

#define WIDTH 1000
#define HEIGHT 800
GLfloat  xrot;   // X 旋转量
GLfloat  yrot;   // Y 旋转量
GLfloat  zrot;   // Z 旋转量
GLuint  texture[1];  // 存储一个纹理
static GLfloat angle = 0.0f;
void DrawBack(void){

	glBindTexture(GL_TEXTURE_2D, texture[0]);      // 选择纹理
	glBegin(GL_QUADS);
	// 前面
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-5.0f, 0.0f, 5.0f); // 纹理和四边形的左下
	glTexCoord2f(1.0f, 0.0f); glVertex3f(5.0f, 0.0f, 5.0f); // 纹理和四边形的右下
	glTexCoord2f(1.0f, 1.0f); glVertex3f(5.0f, 0.0f, -5.0f); // 纹理和四边形的右上
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-5.0f, 0.0f, -5.0f); // 纹理和四边形的左上
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
	// 创建透视效果视图
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
	gluCylinder(quadratic, 0.6f, 0.6f, 0.4f, 32, 32);//画圆柱
	glutSwapBuffers();
	glFlush();
}



AUX_RGBImageRec *LoadBMP(CHAR *Filename)    // 载入位图图象
{
	FILE *File = NULL;         // 文件句柄
	if (!Filename)          // 确保文件名已提供
	{
		return NULL;         // 如果没提供，返回 NULL
	}
	File = fopen(Filename, "r");       // 尝试打开文件
	if (File)           // 文件存在么?
	{
		fclose(File);         // 关闭句柄
		return auxDIBImageLoadA(Filename);    // 载入位图并返回指针
	}
	return NULL;          // 如果载入失败，返回 NULL
}
int LoadGLTextures()         // 载入位图(调用上面的代码)并转换成纹理
{
	int Status = FALSE;         // 状态指示器
	AUX_RGBImageRec *TextureImage[1];     // 创建纹理的存储空间
	memset(TextureImage, 0, sizeof(void *)* 1);   // 将指针设为 NULL
	// 载入位图，检查有无错误，如果位图没找到则退出
	if (TextureImage[0] = LoadBMP("map.bmp"))
	{
		Status = TRUE;         // 将 Status 设为 TRUE
		glGenTextures(1, &texture[0]);     // 创建纹理

		// 使用来自位图数据生成 的典型纹理
		glBindTexture(GL_TEXTURE_2D, texture[0]);
		// 生成纹理
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage[0]->sizeX, TextureImage[0]->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage[0]->data);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); // 线形滤波
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); // 线形滤波
	}

	if (TextureImage[0])        // 纹理是否存在
	{
		if (TextureImage[0]->data)      // 纹理图像是否存在
		{
			free(TextureImage[0]->data);    // 释放纹理图像占用的内存
		}

		free(TextureImage[0]);       // 释放图像结构
	}
	return Status;          // 返回 Status
}

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);            //清理颜色，为黑色，（也可认为是背景颜色）

	glCullFace(GL_BACK);                        //背面裁剪(背面不可见)
	glEnable(GL_CULL_FACE);                        //启用裁剪
	glEnable(GL_TEXTURE_2D);
	LoadGLTextures();            //载入纹理贴图
}
void reshape(GLsizei w, GLsizei h)
{
	//这里小说明一下：矩阵模式是不同的，他们各自有一个矩阵。投影相关
	//只能用投影矩阵。(只是目前情况下哦，等我学多了可能就知道为什么了。)

	glViewport(0, 0, w, h);        //设置视口
	glMatrixMode(GL_PROJECTION);    //设置矩阵模式为投影变换矩阵，
	glLoadIdentity();                //变为单位矩阵
	gluPerspective(60, (GLfloat)w / h, 0, 1000);    //设置投影矩阵
	glMatrixMode(GL_MODELVIEW);        //设置矩阵模式为视图矩阵(模型)
	glLoadIdentity();                //变为单位矩阵
}/*
void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-1, 1, -1, 1, 1.5, 20);
	gluLookAt(1, 0, 8, 1, 0, -1, 0, 1, 0);
}*/
//键盘输入事件函数
void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'd':    //当按下键盘上d时，以沿X轴旋转为主
		xrot += 1.0f;   //设置旋转增量
		glutPostRedisplay();   //重绘函数
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
	glutCreateWindow("OpenGL光照演示");
	init();
	//glutDisplayFunc(&myDisplay);
	//glutDisplayFunc(&mydis);
	//glutIdleFunc(&myIdle);
	LoadGLTextures();
	glutDisplayFunc(&mydis);
	glutReshapeFunc(reshape);                //绘制图形时的回调
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}
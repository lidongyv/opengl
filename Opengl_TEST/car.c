#include <GL/glut.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <windows.h>
#include <GL/glaux.h>

#define WIDTH 1000
#define HEIGHT 800
GLfloat  xrot;   // X 平移
GLfloat  yrot;   // Y 平移
GLfloat  zrot;   // Z 平移
GLfloat  vxrot2;   // X 平移
GLfloat  vyrot2;   // Y 平移
GLfloat  vzrot2;   // Z 平移
GLfloat set;
GLfloat rot;
GLfloat scale=1;
GLuint  texture[1];  // 存储一个纹理
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
	glBindTexture(GL_TEXTURE_2D, texture[0]);      // 选择纹理
	glBegin(GL_QUADS);
	// 前面
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-5.0f, 0.0f, 5.0f); // 纹理和四边形的左下
	glTexCoord2f(1.0f, 0.0f); glVertex3f(5.0f, 0.0f, 5.0f); // 纹理和四边形的右下
	glTexCoord2f(1.0f, 1.0f); glVertex3f(5.0f, 0.0f, -5.0f); // 纹理和四边形的右上
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-5.0f, 0.0f, -5.0f); // 纹理和四边形的左上

	glTexCoord2f(0.0f, 0.0f); glVertex3f(-5.0f, 5.0f, 5.0f); // 纹理和四边形的左下
	glTexCoord2f(1.0f, 0.0f); glVertex3f(5.0f, 5.0f, 5.0f); // 纹理和四边形的右下
	glTexCoord2f(1.0f, 1.0f); glVertex3f(5.0f, 5.0f, -5.0f); // 纹理和四边形的右上
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-5.0f, 5.0f, -5.0f); // 纹理和四边形的左上

	glTexCoord2f(0.0f, 0.0f); glVertex3f(-5.0f, 0.0f, 5.0f); // 纹理和四边形的左下
	glTexCoord2f(1.0f, 0.0f); glVertex3f(5.0f, 0.0f, 5.0f); // 纹理和四边形的右下
	glTexCoord2f(1.0f, 1.0f); glVertex3f(5.0f, 5.0f, 5.0f); // 纹理和四边形的右上
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-5.0f, 5.0f, 5.0f); // 纹理和四边形的左上

	glTexCoord2f(0.0f, 0.0f); glVertex3f(-5.0f, 0.0f, -5.0f); // 纹理和四边形的左下
	glTexCoord2f(1.0f, 0.0f); glVertex3f(5.0f, 0.0f, -5.0f); // 纹理和四边形的右下
	glTexCoord2f(1.0f, 1.0f); glVertex3f(5.0f, 5.0f, -5.0f); // 纹理和四边形的右上
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-5.0f, 5.0f, -5.0f); // 纹理和四边形的左上
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

	//轮胎面
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
	// 创建透视效果视图
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

	                      //背面裁剪(背面不可见)
	//glEnable(GL_CULL_FACE);                        //启用裁剪
	glEnable(GL_TEXTURE_2D);
	//glCullFace(GL_BACK);  
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
}
//键盘输入事件函数
void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'd':    //当按下键盘上d时，以沿X轴旋转为主
		xrot += 0.1f;   //设置旋转增量
		glutPostRedisplay();   //重绘函数
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
		//绕X转动
	case 'i':    //当按下键盘上d时，以沿X轴旋转为主
		vxrot2 += 10;   //设置旋转增量
		glutPostRedisplay();   //重绘函数
		break;
	case 'k':
		vxrot2 -= 10;
		glutPostRedisplay();
		break;
		//绕Y轴转动
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
	glutCreateWindow("OpenGL光照演示");
	init();
	glEnable(GL_DEPTH_TEST);
	//glutDisplayFunc(&myDisplay);
	//glutDisplayFunc(&mydis);
	//glutIdleFunc(&myIdle);
	LoadGLTextures();
	DrawBack();
	glutDisplayFunc(&mydis);
	glutReshapeFunc(reshape);                //绘制图形时的回调
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}
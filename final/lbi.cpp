#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<windows.h>
int k;
int flag=0;
int start=0;
int overflow=0;
int temp=0,change=0;
int res=0;
void drawBitmapText( float x, float y, float z,char *string)
{
    char *c;
    glRasterPos3f(x, y, z);

    for (c = string; *c != '\0'; c++)
    {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }
}

int compute()
{
 int c=0;
 int op,pk[30],bucketsize,n,i;
 printf("enter out rate:\n");
 scanf("%d",&op);
 printf("enter the bucket size \n");
 scanf("%d",&bucketsize);
	 printf("enter the number of packets\n");
	 scanf("%d",&n);
	 for(i=1;i<=n;i++)
	 {
		printf("Enter packet bandwidth %d :  ",i);
		scanf("%d",&pk[i]);
	 }
	 for(i=1;i<=n;i++)
	 {
		 if(pk[i]>bucketsize)
		 {
			printf("\nbucket overflow\n");
			overflow=1;
			//exit(0);
		 }
		 else
		 {
			while(pk[i]>op)
		   {
				printf("\n%d bytes outputted",op);
				pk[i]=pk[i]-op;
				c++;
		   }
			if(pk[i]>0)
				c++;
			printf("\n last %d bytes sent",pk[i]);
			printf("\n bucket output successful\n");
		}
	 }
	 printf("\n no. of packets sent=%d\n",c);
	 return c;
	
}

void setpoint(GLint x,GLint y)
{
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
}

int round1(double number)
{
	return (number>=0) ? (int)(number+0.5):(int)(number-0.5);
}
void LineWithDDA(int x0,int y0,int x1,int y1)
{
	int dy=y1-y0;
	int dx=x1-x0;
	int steps,i;
	float xinc,yinc,x=x0,y=y0;
	if(abs(dx)>abs(dy))
	{
		steps=abs(dx);
	}
	else
	{
		steps=abs(dy);
	}
	xinc=(float)dx/(float)steps;
	yinc=(float)dy/(float)steps;
	setpoint(round1(x),round1(y));
	for(i=0;i<steps;i++)
	{
		x+=xinc;
		y+=yinc;
		setpoint(round1(x),round1(y));
	}
	glPointSize(5);
	glutSwapBuffers();
}
void Circle(int r,int xCenter,int yCenter)
{ 
	
	int x=0,y=r;
	int d = 3/2 - r;   
	glColor3f( 0 ,0, 1); 
	while(x<=y)
	{
		setpoint(xCenter+x,yCenter+y);
		setpoint(xCenter+y,yCenter+x);  
		setpoint(xCenter-x,yCenter+y);
		setpoint(xCenter+y,yCenter-x);
		setpoint(xCenter-x,yCenter-y);
		setpoint(xCenter-y,yCenter-x);
		setpoint(xCenter+x,yCenter-y);
		setpoint(xCenter-y,yCenter+x);

		if (d<0)
			d+=(2*x)+3;
		else 
		{
			d+=(2*(x-y))+5;
			y-=1;
		}
		x++;
	}
	glFlush();
}
void ke(unsigned char key,int x,int y)
{
	switch(key)
	{
	case's':{ start=1;flag=1;
		
		break;
	}
			case 'c':
				{
					if(start!=0)
						start=2;
					if(change==0)
						glClearColor(1,1,1,1);
					else if(change==1)
						glClearColor(0,0,0,0);
					else if(change==2)
						glClearColor(0.5,0.5,0.5,0);
					change++;
					if(change>2)
						change=change-3;
					break;
				}
	case 27:exit(1);
		break;
	}
		glutPostRedisplay();
}
void draw()
{	
	
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	if(start==0)
	{
		
		int const w = glutGet(GLUT_WINDOW_WIDTH);
		int const h = glutGet(GLUT_WINDOW_HEIGHT);
	
		glColor3f(0,0,1);
		drawBitmapText(3*w/10,5*h/6,0.0,"SIR M.VISVESVARAYA INSTITUTE OF TECHNOLOGY");
		glColor3f(0.7,0,1);
		drawBitmapText(3*w/10-20,4*h/6+30,0.0,"DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING");
		glColor3f(1,0.5,0);
		drawBitmapText(4*w/10,7*h/12,0.0,"A MINI PROJECT ON:");
		glColor3f(1,0,0);
		drawBitmapText(4*w/10,5*h/12+30,0.0,"Leaky Bucket Algorithm");
		glColor3f(1,0.5,0);
		drawBitmapText(10,180,0.0,"BY:");
		glColor3f(0.5,0,0.5);
		drawBitmapText(20,155,0.0,"NAME: Aishwarya R George      (USN:1MV15CS006)");
		drawBitmapText(20,130,0.0,"NAME: Amrutha B                    (USN:1MV15CS007)");
		drawBitmapText(20,105,0.0,"NAME: Anupama Raj               (USN:1MV15CS012)");
		glColor3f(0.5,0.2,0.2);
		drawBitmapText(7*w/10+10,150,0.0,"GUIDE NAME: Mr.Elaiyaraja P ");
		
		glColor3f(1,0.1,1);
		drawBitmapText(8*w/10,50,0.0,"PRESS 'S' TO START");
		glMatrixMode(GL_MODELVIEW);
 
	}
	else{
	 if(start==1)
	{

		
		int const w = glutGet(GLUT_WINDOW_WIDTH);
		int const h = glutGet(GLUT_WINDOW_HEIGHT);

		glTranslatef(600,0,0);
		glRotatef(180,0,1,0);
		glScalef(2.0,2.0,0);
		
		if(flag==1)
			temp=compute();
		int x=temp;
		
		Circle(3,102,183);
		Circle(1,102,183);
		//pipe
		glColor3f( 1.0 ,0.0, 0.0);
		LineWithDDA(40,180,100,180);
		LineWithDDA(40,185,100,185); 
		//st.line
		glColor3f( 1.0 ,0.0, 0.0);
		LineWithDDA(40,60,40,250);
		//bucket
		glColor3f( 0.0 ,1.0, 0.0);
		LineWithDDA(75,60,125,60);
		LineWithDDA(125,60,125,120);
		LineWithDDA(75,120,75,60);
		
		
		int i=0;
		glColor3f( 0 ,0, 255);

		while(i<13)
		{
			k=0;
			while(k<10000)   
			{
				int j=0;
				while(j<10000)
				{
					j++;
				}
				k++;
			}
			Circle(3,102,183-(10*i));
			Circle(1,102,183-(10*i));
			
			i++;
		}
		//overflow
		if(overflow==1)
		{
			
			int i=0;
			glColor3f( 0 ,0, 255);
			LineWithDDA(76,61,124,61);
			while(i<60)
			{
				k=0;
				while(k<1000)   
				{
					int j=0;
					while(j<10000)
					{
						j++;
					}
					k++;
				}
		
				LineWithDDA(76,61+i,124,61+i);
				i++;
			}

			
			glClearColor(0,0,0,0);
			glColor3f(1,0,0);
			drawBitmapText(200,100,0.0,"BUCKET OVERFLOW");
			
		
		}


	
		if(overflow==0)
		{
		i=0;
		glColor3f( 0 ,0, 255);
		LineWithDDA(76,61,124,61);
		while(i<10)
		{
			k=0;
			while(k<1000)   
			{
				int j=0;
				while(j<10000)
				{
					j++;
				}
				k++;
			}
		
			LineWithDDA(76,61+i,124,61+i);
			i++;
		}

		glColor3f( 0 ,0, 200/255.0);
		Circle(1,102,63);
		i=0;
		while(i<(x+1))
		{
			k=0;
			while(k<10000)   
			{
				int j=0;
				while(j<10000)
				{
					j++;
				}
				k++;
			}
			Circle(1,102,63-(10*i));
			
			i++;
		}
		}
	res=1;
	flag=0;
	
	}
	else if(start==2)
	{
			glTranslatef(600,0,0);
		glRotatef(180,0,1,0);
		glScalef(2.0,2.0,0);
		int x=temp;
		Circle(3,102,183);
		Circle(1,102,183);
		//pipe
		glColor3f( 1.0 ,0.0, 0.0);
		LineWithDDA(40,180,100,180);
		LineWithDDA(40,185,100,185); 
		//st.line
		glColor3f( 1.0 ,0.0, 0.0);
		LineWithDDA(40,60,40,250);
		//bucket
		glColor3f( 0.0 ,1.0, 0.0);
		LineWithDDA(75,60,125,60);
		LineWithDDA(125,60,125,120);
		LineWithDDA(75,120,75,60);
		
		
		int i=0;
		glColor3f( 0 ,0, 255);

		while(i<13)
		{
			k=0;
			while(k<100)   
			{
				int j=0;
				while(j<100)
				{
					j++;
				}
				k++;
			}
			Circle(3,102,183-(10*i));
			Circle(1,102,183-(10*i));
			
			i++;
		}
		//overflow
		if(overflow==1)
		{
			
			int i=0;
			glColor3f( 0 ,0, 255);
			LineWithDDA(76,61,124,61);
			while(i<60)
			{
				k=0;
				while(k<10)   
				{
					int j=0;
					while(j<100)
					{
						j++;
					}
					k++;
				}
		
				LineWithDDA(76,61+i,124,61+i);
				i++;
			}

			
			glClearColor(0,0,0,0);
			glColor3f(1,0,0);
			drawBitmapText(200,100,0.0,"BUCKET OVERFLOW");
			
		
		}


	
		if(overflow==0)
		{
		i=0;
		glColor3f( 0 ,0, 255);
		LineWithDDA(76,61,124,61);
		while(i<10)
		{
			k=0;
			while(k<10)   
			{
				int j=0;
				while(j<100)
				{
					j++;
				}
				k++;
			}
		
			LineWithDDA(76,61+i,124,61+i);
			i++;
		}

		glColor3f( 0 ,0, 200/255.0);
		Circle(1,102,63);
		i=0;
		while(i<(x+1))
		{
			k=0;
			while(k<100)   
			{
				int j=0;
				while(j<100)
				{
					j++;
				}
				k++;
			}
			Circle(1,102,63-(10*i));
			
			i++;
		}
		}

	}

	}
	glFlush();
	glutSwapBuffers();

}
void reshape(int w, int h)
{
	
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,w,0,h);
	glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
	if(res==1)
		start=2;
	glutPostRedisplay();
	
	
}

int main(int argc,char **argv)
{
	
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(50,50);
	glutInitWindowSize(1000,480);
	glutCreateWindow("Leaky Bucket");
	glutKeyboardFunc(ke);
	
	glutDisplayFunc(draw);
	glutReshapeFunc(reshape);
	glutMainLoop();
	
}
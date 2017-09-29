/**
 * Program: Rotaating Cube
 * Author: Alex Thoennes
 * Compile: gcc -o cube cube.c -L/System/Library/Frameworks -framework GLUT -framework OpenGL
 * Run: ./cube
 * Description: This program is a simple OpenGL program that
 *              displays a red rotating cube.
 **/
#include <stdio.h>
#include <GLUT/glut.h>         /* glut.h includes h and glu.h*/
#include <math.h>

// these are the starting values for the viewers eye
double eyeX = 5;
double eyeY = 5;
double eyeZ = 5;

// this is the rate at which the viewer will rotate
float o = 0.0001f;

// these are the dimensions of the frame
int CANVAS_WIDTH = 500;
int CANVAS_HEIGHT = 500;

void transformEye()
{
    // use o for theta which is the amount of degrees
    eyeX = (5 * cos(o)) + (5 * sin(o));
    eyeZ = (-5 * sin(o)) + (5 * cos(o));
}

/**
 * This method draws all the triangles as the viewer rotates
 */
void drawTriangles()
{
    //        R      G     B
    glColor3f(1.0f, 0.0f, 0.0f);
    // Triangle 0
    glBegin( GL_TRIANGLES);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glEnd();
    
    // Triangle 1
    glBegin( GL_TRIANGLES);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glEnd();
    
    // Triangle 2
    glBegin( GL_TRIANGLES);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glEnd();
    
    // Triangle 3
    glBegin( GL_TRIANGLES);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glEnd();
    
    // Triangle 4
    glBegin( GL_TRIANGLES);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);
    glEnd();
    
    // Triangle 5
    glBegin( GL_TRIANGLES);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);
    glEnd();
    
    // Triangle 6
    glBegin( GL_TRIANGLES);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glEnd();
    
    // Triangle 7
    glBegin( GL_TRIANGLES);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glEnd();
    
    // Triangle 8
    glBegin( GL_TRIANGLES);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glEnd();
    
    // Triangle 9
    glBegin( GL_TRIANGLES);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glEnd();
    
    // Triangle 10
    glBegin( GL_TRIANGLES);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);
    glEnd();
    
    // Triangle 11
    glBegin( GL_TRIANGLES);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);
    glEnd();
}



void display(void)
{
    while (1)
    {
        // this method moves the viewer
        transformEye();
        
        // load identities
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(40.0, 1.0, 1.0, 10000.0);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        
        // look at the cube
        gluLookAt(eyeX, eyeY, eyeZ, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        // draw the triangles that make up the cube
        drawTriangles();
        
        glFlush();
        
        // increment the angle so that the viewer rotates
        o += 0.01f;
        
    }
}


void init()
{
    glEnable(GL_DEPTH_TEST);
    /* set clear color to black */
    
    glClearColor (0.0, 0.0, 0.0, 0.0);
    /* set fill  color to white */
    
    glColor3f(1.0, 1.0, 1.0);
    
    /* set up standard orthogonal view with clipping */
    /* box as cube of side 2 centered at origin */
    /* This is default view and these statement could be removed */
    
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv)
{
    
    /* Initialize mode and open a window in upper left corner of screen */
    /* Window title is name of program (arg[0]) */
    
    glutInit(&argc,argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Cube");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
}

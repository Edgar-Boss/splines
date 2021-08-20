#include <iostream>
#include "glut.h"
#include <math.h> 

int i, x = 1000, y = 1000;

void pintar(float x, float y, float r, float g, float b) {

    glPointSize(3);
    glBegin(GL_POINTS);
    glColor3f(r, g, b);
    glVertex2f(x, y);
    glEnd();
    glutSwapBuffers();
}

void Funcion() {
    float f;
    //  g(x)
    for (float i = -10; i < -6; i += 0.03) {
        f = (-0.75 * i) - 6.5;


        pintar(i * 50, f*50, 1, 0, 0);
    }
    //   h(x)
    for (float i = -6; i < -3; i += 0.03) {
        f =  (1.33 * i) +6;

        pintar(i * 50, f*50, 0.6, 0, 0.5);
    }
    
     //i(x)
    for (float i = -3; i < 3; i += 0.03) {
        f = (-0.16 * i) + 1.5;

        pintar(i * 50, f*50, 0.6, 0, 0.5);
    }
    
    //j(x)
    for (float i = 3; i < 9; i += 0.03) {
        f = -1 * 0.33 * i + 2;

        pintar(i * 50, f*50, 0.2, 0.2, 0.2);
    }


}





void plano() {
    for (int i = -x / 2; i < x / 2; i++) {
        pintar(i, 0, 1, 1, 1);
    }
    for (int i = -y / 2; i < y / 2; i++) {
        pintar(0, i, 1, 1, 1);
    }
    
}

void cordenadas() {
    
    plano();
    Funcion();
    
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(x, y);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Dibujar Función");
    gluOrtho2D(-x / 2, x / 2, -y / 2, y / 2);
    glutDisplayFunc(cordenadas);
    glutMainLoop();


}
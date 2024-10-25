//============================================================================
// Project     : Render 3D Cube
// Author      : JD
// Version     : 1.0
// Run         : g++ 3dCube.cpp -o 3dCube -lfreeglut -lopengl32 -lglu32

// Description : Displays a rotating 3D cube with colored faces in OpenGL.
//               Each face color is randomized on program start.
//============================================================================

#include <GL/glut.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string.h>

using namespace std;

// Global Constants and Variables
const GLsizei WIN_WIDTH = 800, WIN_HEIGHT = 800; // Initial window size
const char *WINDOW_TITLE = "Render 3D Cube";

GLfloat colorArray[6][3];  // Color array for each face of the cube

GLfloat rotationAngle = 0.0f; // Initial rotation angle

// Function Prototypes
void initializeOpenGL();
void updateColorArray(GLfloat colorArray[6][3]);
void onDisplay();
void onReshape(GLint newWidth, GLint newHeight);
void rotateCube();
void drawCube();
void drawFace(GLfloat vertex1[], GLfloat vertex2[], GLfloat vertex3[], GLfloat vertex4[], int colorIndex);

// Main Function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    initializeOpenGL();
    updateColorArray(colorArray); // Randomize colors for each cube face
    glutDisplayFunc(onDisplay);
    glutReshapeFunc(onReshape);
    glutIdleFunc(rotateCube);
    glutMainLoop();
    return 0;
}

// Function Definitions

/**
 * Initializes OpenGL settings and creates a window.
 */
void initializeOpenGL() {
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowPosition(100, 50);
    glutInitWindowSize(WIN_WIDTH, WIN_HEIGHT);
    glutCreateWindow(WINDOW_TITLE);

    glClearColor(0.90, 0.90, 0.90, 0.0); // Set background color to white
    glLineWidth(4);
    glEnable(GL_DEPTH_TEST);           // Enable depth testing for 3D rendering
}

/**
 * Generates random colors for each face of the cube and stores them in colorArray.
 * Each color component is a float between 0 and 1.
 */
void updateColorArray(GLfloat colorArray[6][3]) {

    for (int i = 0; i < 6; i++) {
        colorArray[i][0] = static_cast<float>(rand()) / RAND_MAX;
        colorArray[i][1] = static_cast<float>(rand()) / RAND_MAX;
        colorArray[i][2] = static_cast<float>(rand()) / RAND_MAX;
    }
}

/**
 * Renders the 3D scene: a rotating cube with colored faces.
 */
void onDisplay() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glRotatef(rotationAngle, 1, 1, 1); // Rotate the cube along the X, Y, Z axes
    drawCube();
    glutSwapBuffers();
}

/**
 * Reshapes the viewport based on the new window dimensions.
 * @param newWidth  New width of the window.
 * @param newHeight New height of the window.
 */
void onReshape(GLint newWidth, GLint newHeight) {
    glViewport(0, 0, newWidth, newHeight);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
}

/**
 * Increments the rotation angle of the cube and requests a display refresh.
 */
void rotateCube() {
    rotationAngle += 0.5f;
    if (rotationAngle > 360) {
        rotationAngle = 0; // Reset angle to avoid overflow
    }
    glutPostRedisplay();
}

/**
 * Draws a 3D cube with 6 faces, each with a different color from colorArray.
 */
void drawCube() {
    GLfloat vertices[8][3] = {
        { -0.5f, 0.5f, 0.5f }, { 0.5f, 0.5f, 0.5f }, { 0.5f, -0.5f, 0.5f }, { -0.5f, -0.5f, 0.5f },
        { -0.5f, 0.5f, -0.5f }, { 0.5f, 0.5f, -0.5f }, { 0.5f, -0.5f, -0.5f }, { -0.5f, -0.5f, -0.5f }
    };

    // Define cube faces using vertices and assign a color to each face
    drawFace(vertices[0], vertices[1], vertices[2], vertices[3], 0); // Front face
    drawFace(vertices[4], vertices[5], vertices[6], vertices[7], 1); // Back face
    drawFace(vertices[0], vertices[3], vertices[7], vertices[4], 2); // Left face
    drawFace(vertices[1], vertices[2], vertices[6], vertices[5], 3); // Right face
    drawFace(vertices[0], vertices[1], vertices[5], vertices[4], 4); // Top face
    drawFace(vertices[3], vertices[2], vertices[6], vertices[7], 5); // Bottom face
}

/**
 * Draws a single face of the cube with a specified color and border.
 * @param vertex1   First vertex of the face
 * @param vertex2   Second vertex of the face
 * @param vertex3   Third vertex of the face
 * @param vertex4   Fourth vertex of the face
 * @param colorIndex Index in colorArray for the color of this face
 */
void drawFace(GLfloat vertex1[], GLfloat vertex2[], GLfloat vertex3[], GLfloat vertex4[], int colorIndex) {
    // Draw the filled face with specified color
    glBegin(GL_POLYGON);
    glColor3fv(colorArray[colorIndex]);
    glVertex3fv(vertex1);
    glVertex3fv(vertex2);
    glVertex3fv(vertex3);
    glVertex3fv(vertex4);
    glEnd();

    // Draw the black border for the face
    glBegin(GL_LINE_LOOP);
    glColor3f(0, 0, 0);
    glVertex3fv(vertex1);
    glVertex3fv(vertex2);
    glVertex3fv(vertex3);
    glVertex3fv(vertex4);
    glEnd();
}

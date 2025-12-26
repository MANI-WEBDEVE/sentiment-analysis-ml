#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <iostream>

int main() {
    if (!glfwInit()) return -1;

    // Window create karna
    GLFWwindow* window = glfwCreateWindow(800, 600, "3D Setup Test", NULL, NULL);
    glfwMakeContextCurrent(window);
    glewInit();

    float y_pos = 1.0f; // Starting Height
    float velocity = 0.0f;

    while (!glfwWindowShouldClose(window)) {
        // --- SIMPLE PHYSICS ---
        velocity -= 0.001f; // Gravity constant
        y_pos += velocity;

        if (y_pos < -0.8f) { // Ground collision
            y_pos = -0.8f;
            velocity *= -0.8f; // Bounce
        }

        // --- RENDERING ---
        glClear(GL_COLOR_BUFFER_BIT);
        
        glBegin(GL_QUADS); // Drawing a 2D Square moving in 3D space
            glColor3f(0.1f, 0.6f, 0.9f);
            glVertex2f(-0.1f, y_pos + 0.1f);
            glVertex2f(0.1f, y_pos + 0.1f);
            glVertex2f(0.1f, y_pos - 0.1f);
            glVertex2f(-0.1f, y_pos - 0.1f);
        glEnd();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}
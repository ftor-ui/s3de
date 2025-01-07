#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <S3DE/s3de.h>
#include <stdio.h>
#include <stdlib.h>

#define FAILURE -1
#define SUCCESS 0

struct s3deWindow {
    GLFWwindow* pWindow;
    int height;
    int width;
};

int s3deInit()
{
    if (!glfwInit()) {
        printf("ERROR: Can't init glfw!\n");
        return FAILURE;
    }

    //glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    //glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 6);
    //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    return SUCCESS;
}

s3deWindow* s3deCreateWindow(int width, int height, const char* title)
{
    s3deWindow* p_s3deWindow = (s3deWindow*)malloc(sizeof(s3deWindow));
    GLFWwindow* pWindow = glfwCreateWindow(width, height, title, NULL, NULL);

    p_s3deWindow->pWindow = pWindow;
    p_s3deWindow->height = height;
    p_s3deWindow->width = width;

    glfwMakeContextCurrent(p_s3deWindow->pWindow);
    gladLoadGL();

    return p_s3deWindow;
}

int s3deWindowIsClosed(s3deWindow* p_s3deWindow)
{
    return glfwWindowShouldClose(p_s3deWindow->pWindow);
}

void s3deRender(s3deWindow* p_s3deWindow)
{
    /* Render here */
    //glClear(GL_COLOR_BUFFER_BIT);
    glClear(GL_COLOR_BUFFER_BIT);

    /* Swap front and back buffers */
    glfwSwapBuffers(p_s3deWindow->pWindow);

    /* Poll for and process events */
    glfwPollEvents();
}

void s3deCloseWindow()
{
    glfwTerminate();
}

#include <GLFW/glfw3.h>
#include <vector> 
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/ext/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale
#include <glm/ext/matrix_clip_space.hpp> // glm::perspective
#include <glm/ext/scalar_constants.hpp> // glm::pi
#include <math.h>

using namespace std;



double yy1 = 0, yy2 = 0, yy3 = 200, yy4 = 200;
double xx1 = 300, xx2 = 500, xx3 = 500, xx4 = 300;
using matrix = vector<vector<double>>;


vector<vector<double>> multiple(vector<vector<double>> A, vector<vector<double>> B, vector<vector<double>> res)
{

    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < 1; j++) {
            for (int k = 0; k < A.size(); k++)
                res[i][j] += A[i][k] * B[k][j];
        }
    }
    return res;
}

void rotateright(double theta, GLFWwindow* window)
{
    theta = -theta;
    int t = 10;
    while (t--)
    {
        double aroundx = xx1;
        double aroundy = yy1;
        vector<vector<double>> A = { {cos(theta),-sin(theta),0},{sin(theta),cos(theta),0},{0,0,1} };
        vector<vector<double>> B = { {0} ,{0},{1} };
        vector<vector<double>> C = { {0} ,{0},{0} };
        C = multiple(A, B, C);
        xx1 = C[0][0] + aroundx;
        yy1 = C[1][0] + aroundy;
        vector<vector<double>> A2 = { {cos(theta),-sin(theta),0},{sin(theta),cos(theta),0},{0,0,1} };
        vector<vector<double>> B2 = { {xx2 - aroundx} ,{yy2 - aroundy},{1} };
        vector<vector<double>> C2 = { {0} ,{0},{0} };
        C = multiple(A2, B2, C2);
        xx2 = C[0][0] + aroundx;
        yy2 = C[1][0] + aroundy;
        vector<vector<double>> A3 = { {cos(theta),-sin(theta),0},{sin(theta), cos(theta),0 },{0,0,1} };
        vector<vector<double>> B3 = { {xx3 - aroundx} ,{yy3 - aroundy},{1} };
        vector<vector<double>> C3 = { {0} ,{0},{0} };
        C = multiple(A3, B3, C3);
        xx3 = C[0][0] + aroundx;
        yy3 = C[1][0] + aroundy;
        vector<vector<double>> A4 = { {cos(theta),-sin(theta),0},{sin(theta),cos(theta),0},{0,0,1} };
        vector<vector<double>> B4 = { {xx4 - aroundx} ,{yy4 - aroundy},{1} };
        vector<vector<double>> C4 = { {0} ,{0},{0} };
        C = multiple(A4, B4, C4);
        xx4 = C[0][0] + aroundx;
        yy4 = C[1][0] + aroundy;

        int y1 = yy1;
        int y2 = yy2;
        int y3 = yy3;
        int y4 = yy4;
        int x1 = xx1, x2 = xx2, x3 = xx3, x4 = xx4;
        glfwSwapBuffers(window);
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_QUADS);
        glColor3f(0.52, 0.30, 0.21);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
        glVertex2f(x3, y3);
        glVertex2f(x4, y4);
        glEnd();
    }
}
void rotateleft(double theta, GLFWwindow* window)
{
    int t = 10;
    while (t--)
    {
        double aroundx = xx1;
        double aroundy = yy1;
        vector<vector<double>> A = { {cos(theta),-sin(theta),0},{sin(theta),cos(theta),0},{0,0,1} };
        vector<vector<double>> B = { {0} ,{0},{1} };
        vector<vector<double>> C = { {0} ,{0},{0} };
        C = multiple(A, B, C);
        xx1 = C[0][0] + aroundx;
        yy1 = C[1][0] + aroundy;
        vector<vector<double>> A2 = { {cos(theta),-sin(theta),0},{sin(theta),cos(theta),0},{0,0,1} };
        vector<vector<double>> B2 = { {xx2 - aroundx} ,{yy2 - aroundy},{1} };
        vector<vector<double>> C2 = { {0} ,{0},{0} };
        C = multiple(A2, B2, C2);
        xx2 = C[0][0] + aroundx;
        yy2 = C[1][0] + aroundy;
        vector<vector<double>> A3 = { {cos(theta),-sin(theta),0},{sin(theta), cos(theta),0 },{0,0,1} };
        vector<vector<double>> B3 = { {xx3 - aroundx} ,{yy3 - aroundy},{1} };
        vector<vector<double>> C3 = { {0} ,{0},{0} };
        C = multiple(A3, B3, C3);
        xx3 = C[0][0] + aroundx;
        yy3 = C[1][0] + aroundy;
        vector<vector<double>> A4 = { {cos(theta),-sin(theta),0},{sin(theta),cos(theta),0},{0,0,1} };
        vector<vector<double>> B4 = { {xx4 - aroundx} ,{yy4 - aroundy},{1} };
        vector<vector<double>> C4 = { {0} ,{0},{0} };
        C = multiple(A4, B4, C4);
        xx4 = C[0][0] + aroundx;
        yy4 = C[1][0] + aroundy;

        int y1 = yy1;
        int y2 = yy2;
        int y3 = yy3;
        int y4 = yy4;
        int x1 = xx1, x2 = xx2, x3 = xx3, x4 = xx4;
        glfwSwapBuffers(window);
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_QUADS);
        glColor3f(0.52, 0.30, 0.21);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
        glVertex2f(x3, y3);
        glVertex2f(x4, y4);
        glEnd();
    }
}

void scalebig(double big, GLFWwindow* window)
{
    int t = 10;
    while (t--)
    {
        double aroundx = xx1;
        double aroundy = yy1;
        vector<vector<double>> A = { {big,0,0},{0,big,0},{0,0,1} };
        vector<vector<double>> B = { {0} ,{0},{1} };
        vector<vector<double>> C = { {0} ,{0},{0} };
        C = multiple(A, B, C);
        xx1 = C[0][0] + aroundx;
        yy1 = C[1][0] + aroundy;
        vector<vector<double>> A2 = { {big,0,0},{0,big,0},{0,0,1} };
        vector<vector<double>> B2 = { {xx2 - aroundx} ,{yy2 - aroundy},{1} };
        vector<vector<double>> C2 = { {0} ,{0},{0} };
        C = multiple(A2, B2, C2);
        xx2 = C[0][0] + aroundx;
        yy2 = C[1][0] + aroundy;
        vector<vector<double>> A3 = { {big,0,0},{0,big,0},{0,0,1} };
        vector<vector<double>> B3 = { {xx3 - aroundx} ,{yy3 - aroundy},{1} };
        vector<vector<double>> C3 = { {0} ,{0},{0} };
        C = multiple(A3, B3, C3);
        xx3 = C[0][0] + aroundx;
        yy3 = C[1][0] + aroundy;
        vector<vector<double>> A4 = { {big,0,0},{0,big,0},{0,0,1} };
        vector<vector<double>> B4 = { {xx4 - aroundx} ,{yy4 - aroundy},{1} };
        vector<vector<double>> C4 = { {0} ,{0},{0} };
        C = multiple(A4, B4, C4);
        xx4 = C[0][0] + aroundx;
        yy4 = C[1][0] + aroundy;

        int y1 = yy1;
        int y2 = yy2;
        int y3 = yy3;
        int y4 = yy4;
        int x1 = xx1, x2 = xx2, x3 = xx3, x4 = xx4;
        glfwSwapBuffers(window);
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_QUADS);
        glColor3f(0.52, 0.30, 0.21);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
        glVertex2f(x3, y3);
        glVertex2f(x4, y4);
        glEnd();
    }
}
void scalesmall(double small, GLFWwindow* window)
{
    int t = 10;
    while (t--)
    {
        double aroundx = xx1;
        double aroundy = yy1;
        vector<vector<double>> A = { {small,0,0},{0,small,0},{0,0,1} };
        vector<vector<double>> B = { {0} ,{0},{1} };
        vector<vector<double>> C = { {0} ,{0},{0} };
        C = multiple(A, B, C);
        xx1 = C[0][0] + aroundx;
        yy1 = C[1][0] + aroundy;
        vector<vector<double>> A2 = { {small,0,0},{0,small,0},{0,0,1} };
        vector<vector<double>> B2 = { {xx2 - aroundx} ,{yy2 - aroundy},{1} };
        vector<vector<double>> C2 = { {0} ,{0},{0} };
        C = multiple(A2, B2, C2);
        xx2 = C[0][0] + aroundx;
        yy2 = C[1][0] + aroundy;
        vector<vector<double>> A3 = { {small,0,0},{0,small,0},{0,0,1} };
        vector<vector<double>> B3 = { {xx3 - aroundx} ,{yy3 - aroundy},{1} };
        vector<vector<double>> C3 = { {0} ,{0},{0} };
        C = multiple(A3, B3, C3);
        xx3 = C[0][0] + aroundx;
        yy3 = C[1][0] + aroundy;
        vector<vector<double>> A4 = { {small,0,0},{0,small,0},{0,0,1} };
        vector<vector<double>> B4 = { {xx4 - aroundx} ,{yy4 - aroundy},{1} };
        vector<vector<double>> C4 = { {0} ,{0},{0} };
        C = multiple(A4, B4, C4);
        xx4 = C[0][0] + aroundx;
        yy4 = C[1][0] + aroundy;

        int y1 = yy1;
        int y2 = yy2;
        int y3 = yy3;
        int y4 = yy4;
        int x1 = xx1, x2 = xx2, x3 = xx3, x4 = xx4;
        glfwSwapBuffers(window);
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_QUADS);
        glColor3f(0.52, 0.30, 0.21);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
        glVertex2f(x3, y3);
        glVertex2f(x4, y4);
        glEnd();
    }
}
void sheary(double small, GLFWwindow* window)
{
    int t = 10;
    while (t--)
    {
        double aroundx = xx1;
        double aroundy = yy1;
        vector<vector<double>> A = { {1,small,0},{0,1,0},{0,0,1} };
        vector<vector<double>> B = { {0} ,{0},{1} };
        vector<vector<double>> C = { {0} ,{0},{0} };
        C = multiple(A, B, C);
        xx1 = C[0][0] + aroundx;
        yy1 = C[1][0] + aroundy;
        vector<vector<double>> A2 = { {1,small,0},{0,1,0},{0,0,1} };
        vector<vector<double>> B2 = { {xx2 - aroundx} ,{yy2 - aroundy},{1} };
        vector<vector<double>> C2 = { {0} ,{0},{0} };
        C = multiple(A2, B2, C2);
        xx2 = C[0][0] + aroundx;
        yy2 = C[1][0] + aroundy;
        vector<vector<double>> A3 = { {1,small,0},{0,1,0},{0,0,1} };
        vector<vector<double>> B3 = { {xx3 - aroundx} ,{yy3 - aroundy},{1} };
        vector<vector<double>> C3 = { {0} ,{0},{0} };
        C = multiple(A3, B3, C3);
        xx3 = C[0][0] + aroundx;
        yy3 = C[1][0] + aroundy;
        vector<vector<double>> A4 = { {1,small,0},{0,1,0},{0,0,1} };
        vector<vector<double>> B4 = { {xx4 - aroundx} ,{yy4 - aroundy},{1} };
        vector<vector<double>> C4 = { {0} ,{0},{0} };
        C = multiple(A4, B4, C4);
        xx4 = C[0][0] + aroundx;
        yy4 = C[1][0] + aroundy;

        int y1 = yy1;
        int y2 = yy2;
        int y3 = yy3;
        int y4 = yy4;
        int x1 = xx1, x2 = xx2, x3 = xx3, x4 = xx4;
        glfwSwapBuffers(window);
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_QUADS);
        glColor3f(0.52, 0.30, 0.21);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
        glVertex2f(x3, y3);
        glVertex2f(x4, y4);
        glEnd();
    }
}
void shearx(double small, GLFWwindow* window)
{
    int t = 10;
    while (t--)
    {
        double aroundx = xx1;
        double aroundy = yy1;
        vector<vector<double>> A = { {1,0,0},{small,1,0},{0,0,1} };
        vector<vector<double>> B = { {0} ,{0},{1} };
        vector<vector<double>> C = { {0} ,{0},{0} };
        C = multiple(A, B, C);
        xx1 = C[0][0] + aroundx;
        yy1 = C[1][0] + aroundy;
        vector<vector<double>> A2 = { {1,0,0},{small,1,0},{0,0,1} };
        vector<vector<double>> B2 = { {xx2 - aroundx} ,{yy2 - aroundy},{1} };
        vector<vector<double>> C2 = { {0} ,{0},{0} };
        C = multiple(A2, B2, C2);
        xx2 = C[0][0] + aroundx;
        yy2 = C[1][0] + aroundy;
        vector<vector<double>> A3 = { {1,0,0},{small,1,0},{0,0,1} };
        vector<vector<double>> B3 = { {xx3 - aroundx} ,{yy3 - aroundy},{1} };
        vector<vector<double>> C3 = { {0} ,{0},{0} };
        C = multiple(A3, B3, C3);
        xx3 = C[0][0] + aroundx;
        yy3 = C[1][0] + aroundy;
        vector<vector<double>> A4 = { {1,0,0},{small,1,0},{0,0,1} };
        vector<vector<double>> B4 = { {xx4 - aroundx} ,{yy4 - aroundy},{1} };
        vector<vector<double>> C4 = { {0} ,{0},{0} };
        C = multiple(A4, B4, C4);
        xx4 = C[0][0] + aroundx;
        yy4 = C[1][0] + aroundy;

        int y1 = yy1;
        int y2 = yy2;
        int y3 = yy3;
        int y4 = yy4;
        int x1 = xx1, x2 = xx2, x3 = xx3, x4 = xx4;
        glfwSwapBuffers(window);
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_QUADS);
        glColor3f(0.52, 0.30, 0.21);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
        glVertex2f(x3, y3);
        glVertex2f(x4, y4);
        glEnd();
    }
}
void shearx2(double small, GLFWwindow* window)
{
    int t = 10;
    while (t--)
    {
        small = -small;
        double aroundx = xx1;
        double aroundy = yy1;
        vector<vector<double>> A = { {1,0,0},{small,1,0},{0,0,1} };
        vector<vector<double>> B = { {0} ,{0},{1} };
        vector<vector<double>> C = { {0} ,{0},{0} };
        C = multiple(A, B, C);
        xx1 = C[0][0] + aroundx;
        yy1 = C[1][0] + aroundy;
        vector<vector<double>> A2 = { {1,0,0},{small,1,0},{0,0,1} };
        vector<vector<double>> B2 = { {xx2 - aroundx} ,{yy2 - aroundy},{1} };
        vector<vector<double>> C2 = { {0} ,{0},{0} };
        C = multiple(A2, B2, C2);
        xx2 = C[0][0] + aroundx;
        yy2 = C[1][0] + aroundy;
        vector<vector<double>> A3 = { {1,0,0},{small,1,0},{0,0,1} };
        vector<vector<double>> B3 = { {xx3 - aroundx} ,{yy3 - aroundy},{1} };
        vector<vector<double>> C3 = { {0} ,{0},{0} };
        C = multiple(A3, B3, C3);
        xx3 = C[0][0] + aroundx;
        yy3 = C[1][0] + aroundy;
        vector<vector<double>> A4 = { {1,0,0},{small,1,0},{0,0,1} };
        vector<vector<double>> B4 = { {xx4 - aroundx} ,{yy4 - aroundy},{1} };
        vector<vector<double>> C4 = { {0} ,{0},{0} };
        C = multiple(A4, B4, C4);
        xx4 = C[0][0] + aroundx;
        yy4 = C[1][0] + aroundy;

        int y1 = yy1;
        int y2 = yy2;
        int y3 = yy3;
        int y4 = yy4;
        int x1 = xx1, x2 = xx2, x3 = xx3, x4 = xx4;
        glfwSwapBuffers(window);
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_QUADS);
        glColor3f(0.52, 0.30, 0.21);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
        glVertex2f(x3, y3);
        glVertex2f(x4, y4);
        glEnd();
    }
}
void sheary2(double small, GLFWwindow* window)
{
    int t = 10;
    while (t--)
    {
        small = -small;
        double aroundx = xx1;
        double aroundy = yy1;
        vector<vector<double>> A = { {1,small,0},{0,1,0},{0,0,1} };
        vector<vector<double>> B = { {0} ,{0},{1} };
        vector<vector<double>> C = { {0} ,{0},{0} };
        C = multiple(A, B, C);
        xx1 = C[0][0] + aroundx;
        yy1 = C[1][0] + aroundy;
        vector<vector<double>> A2 = { {1,small,0},{0,1,0},{0,0,1} };
        vector<vector<double>> B2 = { {xx2 - aroundx} ,{yy2 - aroundy},{1} };
        vector<vector<double>> C2 = { {0} ,{0},{0} };
        C = multiple(A2, B2, C2);
        xx2 = C[0][0] + aroundx;
        yy2 = C[1][0] + aroundy;
        vector<vector<double>> A3 = { {1,small,0},{0,1,0},{0,0,1} };
        vector<vector<double>> B3 = { {xx3 - aroundx} ,{yy3 - aroundy},{1} };
        vector<vector<double>> C3 = { {0} ,{0},{0} };
        C = multiple(A3, B3, C3);
        xx3 = C[0][0] + aroundx;
        yy3 = C[1][0] + aroundy;
        vector<vector<double>> A4 = { {1,small,0},{0,1,0},{0,0,1} };
        vector<vector<double>> B4 = { {xx4 - aroundx} ,{yy4 - aroundy},{1} };
        vector<vector<double>> C4 = { {0} ,{0},{0} };
        C = multiple(A4, B4, C4);
        xx4 = C[0][0] + aroundx;
        yy4 = C[1][0] + aroundy;

        int y1 = yy1;
        int y2 = yy2;
        int y3 = yy3;
        int y4 = yy4;
        int x1 = xx1, x2 = xx2, x3 = xx3, x4 = xx4;
        glfwSwapBuffers(window);
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_QUADS);
        glColor3f(0.52, 0.30, 0.21);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
        glVertex2f(x3, y3);
        glVertex2f(x4, y4);
        glEnd();
    }
}
void move_obj_up(int& y1, int& y2, int& y3, int& y4, int& x1, int& x2, int& x3, int& x4, GLFWwindow* window)
{
    int t = 10;
    while (t--) {

        yy1++, yy2++, yy3++, yy4++;
        y1 = yy1;
        y2 = yy2;
        y3 = yy3;
        y4 = yy4;
        x1 = xx1, x2 = xx2, x3 = xx3, x4 = xx4;
        glfwSwapBuffers(window);
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_QUADS);
        glColor3f(0.52, 0.30, 0.21);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
        glVertex2f(x3, y3);
        glVertex2f(x4, y4);
        glEnd();
    }
}
void move_obj_down(int& y1, int& y2, int& y3, int& y4, int& x1, int& x2, int& x3, int& x4, GLFWwindow* window)
{
    int t = 10;
    while (t--) {

        yy1--, yy2--, yy3--, yy4--;
        y1 = yy1;
        y2 = yy2;
        y3 = yy3;
        y4 = yy4;
        x1 = xx1, x2 = xx2, x3 = xx3, x4 = xx4;
        glfwSwapBuffers(window);
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_QUADS);
        glColor3f(0.52, 0.30, 0.21);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
        glVertex2f(x3, y3);
        glVertex2f(x4, y4);
        glEnd();
    }
}
void move_obj_right(int& y1, int& y2, int& y3, int& y4, int& x1, int& x2, int& x3, int& x4, GLFWwindow* window)
{
    int t = 10;
    while (t--) {

        xx1++, xx2++, xx3++, xx4++;
        y1 = yy1;
        y2 = yy2;
        y3 = yy3;
        y4 = yy4;
        x1 = xx1, x2 = xx2, x3 = xx3, x4 = xx4;

        glfwSwapBuffers(window);
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_QUADS);
        glColor3f(0.52, 0.30, 0.21);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
        glVertex2f(x3, y3);
        glVertex2f(x4, y4);
        glEnd();
    }
}
void move_obj_left(int& y1, int& y2, int& y3, int& y4, int& x1, int& x2, int& x3, int& x4, GLFWwindow* window)
{
    int t = 10;
    while (t--) {

        xx1--, xx2--, xx3--, xx4--;
        y1 = yy1;
        y2 = yy2;
        y3 = yy3;
        y4 = yy4;
        x1 = xx1, x2 = xx2, x3 = xx3, x4 = xx4;

        glfwSwapBuffers(window);
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_QUADS);
        glColor3f(0.52, 0.30, 0.21);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
        glVertex2f(x3, y3);
        glVertex2f(x4, y4);
        glEnd();
    }
}
void keycalback(GLFWwindow* window, int key, int scancode, int action, int mods)
{

    int  y1 = 0, y2 = 0, y3 = 200, y4 = 200, x1 = 300, x2 = 500, x3 = 500, x4 = 300;
    if (key == GLFW_KEY_W)
    {
        move_obj_up(y1, y2, y3, y4, x1, x2, x3, x4, window);
    }
    if (key == GLFW_KEY_S && action == GLFW_PRESS)
    {
        move_obj_down(y1, y2, y3, y4, x1, x2, x3, x4, window);
    }
    if (key == GLFW_KEY_A && action == GLFW_PRESS)
    {
        move_obj_left(y1, y2, y3, y4, x1, x2, x3, x4, window);
    }
    if (key == GLFW_KEY_D && action == GLFW_PRESS)
    {
        move_obj_right(y1, y2, y3, y4, x1, x2, x3, x4, window);
    }
    if (key == GLFW_KEY_E)
    {
        rotateright(0.01, window);
    }
    if (key == GLFW_KEY_Q)
    {
        rotateleft(0.01, window);
    }
    if (key == GLFW_KEY_F && action == GLFW_PRESS)
    {
        scalebig(1.01, window);
    }
    if (key == GLFW_KEY_G && action == GLFW_PRESS)
    {
        scalesmall(0.99, window);
    }
    if (key == GLFW_KEY_X && action == GLFW_PRESS)
    {
        shearx(0.01, window);
    }
    if (key == GLFW_KEY_Z && action == GLFW_PRESS)
    {

        sheary(0.01, window);
    }
    if (key == GLFW_KEY_C && action == GLFW_PRESS)
    {
        shearx2(0.01, window);
    }
    if (key == GLFW_KEY_V && action == GLFW_PRESS)
    {

        sheary2(0.01, window);
    }
}
int main(void)
{
    int  y1 = 0, y2 = 0, y3 = 200, y4 = 200;

    GLFWwindow* window;
    if (!glfwInit())
    {
        return -1;
    }
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, keycalback);
    glViewport(0.0f, 0.0f, 640, 480);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 640, 0, 480, 0, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();


    while (!glfwWindowShouldClose(window))
    {
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();

    return 0;
}

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#define ASSERT(x) if (!(x)) __debugbreak();
#define GLCall(x) GLClearError();\
    x;\
    ASSERT(GLLogCall(#x, __FILE__, __LINE__))

static void GLClearError()
{
    while (glGetError() != GL_NO_ERROR);
}

static bool GLLogCall(const char* function, const char* file, int line)
{
    while (GLenum error = glGetError())
    {
        std::cout << "[OpenGL Error] : (" << error << ")" << function << " : " << file << " : " << line << std::endl;
        return false;
    }
    return true;
}

struct ShaderProgramSource
{
    std::string vertexSource;
    std::string fragmentSource;
};

static ShaderProgramSource ParseShader(const std::string& filePath)
{
    enum class shaderType
    {
        None = -1,
        Vertex = 0,
        Fragment = 1
    };

    std::ifstream stream(filePath);
    std::string line;
    std::stringstream stringStream[2];
    shaderType currentType = shaderType::None;

    while (getline(stream, line))
    {
        if (line.find("#shader") != std::string::npos)
        {
            if (line.find("vertex") != std::string::npos)
            {
                currentType = shaderType::Vertex;
            }
            else if (line.find("fragment") != std::string::npos)
            {
                currentType = shaderType::Fragment;
            }
        }
        else
        {
            stringStream[(int)currentType] << line << '\n';
        }
    }

    return { stringStream[0].str(), stringStream[1].str() };
}

static unsigned int CompileShader(unsigned int type, const std::string& source)
{
    unsigned int id = glCreateShader(type);
    const char* src = source.c_str();
    glShaderSource(id, 1, &src, nullptr);
    glCompileShader(id);

    int result;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);

    if (!result)
    {
        int length;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
        char* message = (char*)alloca(length * sizeof(char));
        glGetShaderInfoLog(id, length, &length, message);
        std::cout << "Failed to compile " << (type == GL_VERTEX_SHADER ? "vertex shader!" : "fragment shader!") << std::endl;
        std::cout << message << std::endl;
        glDeleteShader(id);
        return 0;
    }

    return id;
}

static unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader)
{
    unsigned int programPointer = glCreateProgram();
    unsigned int vShader = CompileShader(GL_VERTEX_SHADER, vertexShader);
    unsigned int fShader = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

    glAttachShader(programPointer, vShader);
    glAttachShader(programPointer, fShader);
    glLinkProgram(programPointer);
    glValidateProgram(programPointer);

    glDeleteShader(vShader);
    glDeleteShader(fShader);

    return programPointer;
}

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    glfwSwapInterval(1);

    if (glewInit() != GLEW_OK)
    {
        std::cout << "ERROR: GLEW init is not okay!" << std::endl;
    }

    std::cout << glGetString(GL_VERSION) << std::endl;

    float positions[12] =
    {
        //Square with index buffers ~ 8 bytes buffer
        -0.5f, 0.5f,
        0.5f, 0.5f,
        0.5f, -0.5f,
        -0.5f, -0.5f

        /*
        //Square out of triangles without an index buffer ~ 48 bytes buffer
        -0.5f, -0.5f,
        0.5f, -0.5f,
        0.5f, 0.5f,
        0.5f, 0.5f,
        -0.5f, 0.5f,
        - 0.5f, -0.5f
        */

        /*
        //Triangle ~ 6 bytes buffer
        0, 0.5f, 
        -0.5f, -0.5f, 
        0.5f, -0.5f
        */
    };

    unsigned int indices[] =    //index buffer
    {
        0, 1, 2,
        0, 2, 3
    };

    unsigned int vao;
    GLCall(glGenVertexArrays(1, &vao));
    GLCall(glBindVertexArray(vao));

    unsigned int buffer;
    GLCall(glGenBuffers(1, &buffer));
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, buffer));
    GLCall(glBufferData(GL_ARRAY_BUFFER, 8 * sizeof(float), positions, GL_STATIC_DRAW));
    
    GLCall(glEnableVertexAttribArray(0));
    GLCall(glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0));
    
    unsigned int indexBufferObject;
    GLCall(glGenBuffers(1, &indexBufferObject));
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferObject));
    GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(unsigned int), indices, GL_STATIC_DRAW));

    ShaderProgramSource programSource = ParseShader("resources/shaders/Basic.shader");
    
    /*
    std::cout << "VERTEX" << std::endl;
    std::cout << programSource.vertexSource << std::endl;
    std::cout << "FRAGMENT" << std::endl;
    std::cout << programSource.fragmentSource << std::endl;
    */

    unsigned int shader = CreateShader(programSource.vertexSource, programSource.fragmentSource);
    GLCall(glUseProgram(shader));

    GLCall(int location = glGetUniformLocation(shader, "u_Colour"));
    ASSERT(location != -1);
    GLCall(glUniform4f(location, 0.6, 0.1, 0.9, 1.0));

    //Unbind everything so you can carry them in while loop for demenstrution purposes
    GLCall(glBindVertexArray(0));
    GLCall(glUseProgram(0));
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));


    //glBindBuffer(GL_ARRAY_BUFFER, 0);

    float red = 0.0f;
    float increment = 0.05f;

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        GLCall(glUseProgram(shader));
        GLCall(glClear(GL_COLOR_BUFFER_BIT));

        GLCall(glBindVertexArray(vao));
        GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferObject));


        //glBegin(GL_TRIANGLES);            //Legacy openGL
        //glVertex2f(0, 0.5f);
        //glVertex2f(-0.5f, -0.5f);
        //glVertex2f(0.5f, -0.5f);
        //glEnd();

        /*
        glDrawArrays(GL_TRIANGLES, 0, 6);     //When you are not using index buffer
        */

        //GLClearError();
        GLCall(glUniform4f(location, red, 0.1, 0.9, 1.0));
        GLCall(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr));      //When you use index buffer
        if (red >= 1)
        {
            increment = -0.05f;
        }
        else if (red <= 0)
        {
            increment = 0.05f;
        }
        red += increment;

        //ASSERT(GLCheckError());

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    GLCall(glDeleteProgram(shader));

    glfwTerminate();
    return 0;
}

//
// Created by khanh.pd1 on 9/7/2024.
//

#include "draw_geometry.h"
#include "GLES2/gl2.h"
#include "GLES2/gl2ext.h"
#include "GLES2/gl2platform.h"
#include "../utils/ALog.h"

#define LOG_TAG "DRAW_GEOMETRY"

const char *mVertexShaderSource = R"(
        attribute vec4 vPosition;
        void main(){
            gl_Position = vPosition;
        })";

const char *mFragmentShaderSource = R"(
       uniform vec4 vColor;
       void main() {
           gl_FragColor = vColor;
       })";

float mVertices[] = {
        0.5f,  0.5f, 0.0f,  // top right
        0.5f, -0.5f, 0.0f,  // bottom right
        -0.5f, -0.5f, 0.0f,  // bottom left
        -0.5f,  0.5f, 0.0f   // top left
};

unsigned int mIndices[] = {  // note that we start from 0!
        0, 1, 3,   // first triangle
        1, 2, 3    // second triangle
};

float mRGBAColor[] = {0.0f, 0.8f, 0.0f, 1.0f };

unsigned int mProgram;

void initTriangle(){
    ALOGD("[%s] begin",__FUNCTION__ );

    /*create vertexShader*/
    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);

    glShaderSource(vertexShader, 1, &mVertexShaderSource, NULL);
    glCompileShader(vertexShader);

    int  success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

    if(!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        ALOGE("glCreate Vertex Shader was failed error is %s", infoLog);
    }
    else {
        ALOGD("glCreate Vertex Shader is successfully");
    }
    /*create fragmentShader*/
    unsigned int fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &mFragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    if(!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        ALOGE("glCreate Fragment Shader was failed error is %s", infoLog);
    }
    else {
        ALOGD("glCreate Fragment Shader is successfully");
    }

    /*create program from vertex shader/fragment shader*/
    mProgram = glCreateProgram();
    glAttachShader(mProgram, vertexShader);
    glAttachShader(mProgram, fragmentShader);
    glLinkProgram(mProgram);

    glGetProgramiv(mProgram, GL_LINK_STATUS, &success);
    if(!success) {
        glGetProgramInfoLog(mProgram, 512, NULL, infoLog);
        ALOGE("Create program was failed with error is %s",infoLog);
    } else {
        ALOGD("Create program is successfully");
        return;
    }

    ALOGD("[%s] end",__FUNCTION__ );
}

void drawTriangle(){
    ALOGD("[%s] begin",__FUNCTION__ );
    glUseProgram(mProgram);

    // Handle vertex
    int positionHandle = glGetAttribLocation(mProgram, "vPosition");
    glEnableVertexAttribArray(positionHandle);
    glVertexAttribPointer(positionHandle,3,GL_FLOAT,GL_FALSE,3*sizeof (float),mVertices);

    // Handle Color
    int colorHandle = glGetUniformLocation(mProgram, "vColor");
    glUniform4fv(colorHandle, 1, mRGBAColor);

    /*draw triangle*/
    glDrawArrays(GL_TRIANGLE_STRIP,0,3);

   // glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_INT,mIndices);

    glDisableVertexAttribArray(positionHandle);

    ALOGD("[%s] end",__FUNCTION__ );
}

void drawRectangle(){
    ALOGD("[%s] begin",__FUNCTION__ );
    glUseProgram(mProgram);

    // Handle vertex
    int positionHandle = glGetAttribLocation(mProgram, "vPosition");
    glEnableVertexAttribArray(positionHandle);
    glVertexAttribPointer(positionHandle,3,GL_FLOAT,GL_FALSE,3*sizeof (float),mVertices);

    // Handle Color
    int colorHandle = glGetUniformLocation(mProgram, "vColor");
    glUniform4fv(colorHandle, 1, mRGBAColor);

    /*draw triangle*/

    glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_INT,mIndices);

    glDisableVertexAttribArray(positionHandle);

    ALOGD("[%s] end",__FUNCTION__ );
}




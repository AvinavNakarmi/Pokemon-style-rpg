#version 460 core
layout(location=0)in vec3 aPos;
layout(location=1)in vec2 aTexCoords;
out vec2 TexCoord;
uniform mat4 uModel;
uniform mat4 uView;
uniform mat4 uProjection;

void main()
{
    vec4 worldPos=uProjection*uView*uModel*vec4(aPos,1.);
    gl_Position=worldPos;
    TexCoord=aTexCoords;
}
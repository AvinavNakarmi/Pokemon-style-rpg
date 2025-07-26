#version 460 core
layout(location=0)in vec3 aPos;
uniform mat4 uView;
uniform mat4 uProjection;

void main()
{
    vec4 worldPos=uProjection*uView*uModel*vec4(aPos,1.);
    
    gl_Position=worldPos;
}
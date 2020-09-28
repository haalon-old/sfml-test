#version 130

uniform float scale;

out vec4 oldPos;
out vec4 newPos;

void main()
{
	vec4 Vertex = gl_Vertex;
	Vertex.x*= scale;
	Vertex.y*= scale;

    gl_Position = gl_ModelViewProjectionMatrix * Vertex;

    // transform the texture coordinates
    gl_TexCoord[0] = gl_TextureMatrix[0] * gl_MultiTexCoord0;

    // forward the vertex color
    gl_FrontColor = gl_Color;

    oldPos = gl_ModelViewProjectionMatrix * gl_Vertex;
    newPos = gl_Position;
}
#version 130

in vec4 oldPos;
in vec4 newPos;

void main()
{
    // lookup the pixel in the texture
    vec2 delta = newPos.xy - oldPos.xy;
    

    // multiply it by the color
    vec4 col = gl_Color;
    col.w = 1 - 1/sqrt(delta.x*delta.x + delta.y*delta.y);
    gl_FragColor = col;
}
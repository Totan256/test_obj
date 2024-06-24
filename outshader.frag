#version 150
in vec4 fc;

//
// shader.frag
//

uniform vec2 Res;
uniform vec3 Pos;
uniform vec2 turn;


void main(void)
{
	vec2 uv2 = gl_FragCoord.xy / Res;
	vec3 col = vec3(1,0,0);
	gl_FragColor = vec4(col , 1.0);
    
}
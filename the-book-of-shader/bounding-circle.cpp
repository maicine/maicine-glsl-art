#ifdef GL_ES
precision mediump float;
#endif

uniform vec2 u_resolution;
uniform vec2 u_mouse;
uniform float u_time;

void main() {
    vec2 st = gl_FragCoord.xy/u_resolution.xy;
    vec2 center = vec2(0.5);
    
    
    float c1_r = abs(0.3);
    float c1_d = distance(center, st);
    float c1 = step(c1_r, c1_d);
    
    float shrink_speed = (abs(sin(u_time)) / 400.0);
	float c2_r = abs(sin(u_time * shrink_speed)*0.1);
    float offset = 0.5;
    float sin = offset + sin(u_time)*0.3;
	float cos = offset + cos(u_time)*0.3;
    vec2 c2_center = vec2(sin,cos);
    float c2_d = distance(c2_center, st);
    float c2 = step(c2_r, c2_d);
    
    
    gl_FragColor = vec4(vec3(c1*c2),1.0);
}

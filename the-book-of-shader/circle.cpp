fdef GL_ES
precision mediump float;
#endif

uniform vec2 u_resolution;
uniform vec2 u_mouse;
uniform float u_time;

void main() {
    vec2 st = gl_FragCoord.xy/u_resolution.xy;
    vec2 center = vec2(0.5);
    float d = step(0.3, distance(center, st));
    
    gl_FragColor = vec4(vec3(d),1.0);
}

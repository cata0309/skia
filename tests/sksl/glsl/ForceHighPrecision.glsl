#version 400
precision mediump float;
precision mediump sampler2D;
out mediump vec4 sk_FragColor;
uniform highp float unknownInput;
void main() {
    highp float x = unknownInput;
    highp vec4 y = vec4(x);
    sk_FragColor = y;
}

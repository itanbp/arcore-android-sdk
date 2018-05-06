// Fragment shader that renders to a RGBA texture.
#extension GL_OES_EGL_image_external : require

precision mediump float;
varying vec2 v_TexCoord;
uniform samplerExternalOES sTexture;

void main() {
    gl_FragColor = texture2D(sTexture, v_TexCoord);
    //gl_FragColor = texture2D(sTexture, v_TexCoord).argb;
    /*
    options:
        1. no - looks good
        2. rgba - looks same as #1
        3. argb - red colors
        4. bgra - blue colors
    */

}

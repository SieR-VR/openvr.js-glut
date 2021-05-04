const glut = require('bindings')('glut')

export namespace electron_glut {
    export const GLUT_Init = function(imageData: Buffer): number { return glut.GLUT_Init(imageData); } 
    export const GLUT_TextureUpdate = function(): number { return glut.GLUT_TextureUpdate(); }
}
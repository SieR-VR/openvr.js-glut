const glut = require('bindings')('glut')

export namespace electron_glut {
    export const GLUT_Init = function(width: number, height: number): number { return glut.GLUT_Init(width, height); } 
    export const GLUT_TextureUpdate = function(imageData: Buffer): number { return glut.GLUT_TextureUpdate(imageData); }
}
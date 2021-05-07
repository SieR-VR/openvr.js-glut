const glut = require('bindings')('glut')

export namespace electron_glut {
<<<<<<< HEAD
    export const GLUT_Init = function(width: number, height: number): number { return glut.GLUT_Init(width, height); } 
    export const GLUT_TextureUpdate = function(imageData: Buffer): number { return glut.GLUT_TextureUpdate(imageData); }
=======
    export const GLUT_Init = function(imageData: Buffer): number { return glut.GLUT_Init(imageData); } 
    export const GLUT_TextureUpdate = function(): number { return glut.GLUT_TextureUpdate(); }
>>>>>>> 18e8e7e5117e793668ecdf24ca5bdd8c8be36a9b
}
"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.electron_glut = void 0;
var glut = require('bindings')('glut');
var electron_glut;
(function (electron_glut) {
    electron_glut.GLUT_Init = function (width, height) { return glut.GLUT_Init(width, height); };
    electron_glut.GLUT_TextureUpdate = function (imageData) { return glut.GLUT_TextureUpdate(imageData); };
})(electron_glut = exports.electron_glut || (exports.electron_glut = {}));

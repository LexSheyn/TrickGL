#pragma once

#include "TrickBase.h"

#include <glcorearb.h>

TK_HANDLE(TkGLInterface);

TkResult TK_CALL tkCreateGLInterface  (void* Allocator, TkGLInterface* p_GLInterface);
void     TK_CALL tkDestroyGLInterface (TkGLInterface GLInterface);

void TK_CALL tkglCullFace    (TkGLInterface GLInterface, GLenum Mode);
void TK_CALL tkglFronFace    (TkGLInterface GLInterface, GLenum Mode);
void TK_CALL tkglHint        (TkGLInterface GLInterface, GLenum Target, GLenum Mode);
void TK_CALL tkglLineWidth   (TkGLInterface GLInterface, GLfloat Width);
void TK_CALL tkglPointSize   (TkGLInterface GLInterface, GLfloat Size);
void TK_CALL tkglPolygonMode (TkGLInterface GLInterface, GLenum Face, GLenum Mode);
void TK_CALL tkglScissor     (TkGLInterface GLInterface, GLint X, GLint Y, GLint Width, GLint Height);

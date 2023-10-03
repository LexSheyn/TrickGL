#pragma once

#include "TrickBase.h"

#include <glcorearb.h>

TK_HANDLE(TkGLInterface);

TkResult TK_CALL tkCreateGLInterface  (void* Allocator, TkGLInterface* p_GLInterface);
void     TK_CALL tkDestroyGLInterface (TkGLInterface GLInterface);

void TK_CALL tkGLCullFace    (TkGLInterface GLInterface, GLenum Mode);
void TK_CALL tkGLFronFace    (TkGLInterface GLInterface, GLenum Mode);
void TK_CALL tkGLHint        (TkGLInterface GLInterface, GLenum Target, GLenum Mode);
void TK_CALL tkGLLineWidth   (TkGLInterface GLInterface, GLfloat Width);
void TK_CALL tkGLPointSize   (TkGLInterface GLInterface, GLfloat Size);
void TK_CALL tkGLPolygonMode (TkGLInterface GLInterface, GLenum Face, GLenum Mode);

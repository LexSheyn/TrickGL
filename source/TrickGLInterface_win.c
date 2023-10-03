#include "TrickGLInterface.h"

#include <glxext.h>
#include <wglext.h>

typedef void (TK_CALL* PFN_tkGLCullFace)    (GLenum Mode);
typedef void (TK_CALL* PFN_tkGLFronFace)    (GLenum Mode);
typedef void (TK_CALL* PFN_tkGLHint)        (GLenum Target, GLenum Mode);
typedef void (TK_CALL* PFN_tkGLLineWidth)   (GLfloat Width);
typedef void (TK_CALL* PFN_tkGLPointSize)   (GLfloat Size);
typedef void (TK_CALL* PFN_tkGLPolygonMode) (GLenum Face, GLenum Mode);

typedef struct TkGLInterface_T
{
    PFN_tkGLCullFace       pfn_glGullFace;
    PFN_tkGLFronFace       pfn_glFrontFace;
    PFN_tkGLHint           pfn_glHint;
    PFN_tkGLLineWidth      pfn_glLineWidth;
    PFN_tkGLPointSize      pfn_glPointSize;
    PFN_tkGLPolygonMode    pfn_glPolygonMode;
} TkGLInterface_T;

TkResult TK_CALL tkCreateGLInterface(void* Allocator, TkGLInterface* p_GLInterface)
{
    // TO DO

    return TK_SUCCESS;
}

void TK_CALL tkDestroyGLInterface(TkGLInterface GLInterface)
{
    // TO DO
}

void tkGLCullFace(TkGLInterface GLInterface, GLenum Mode)
{
    GLInterface->pfn_glGullFace(Mode);
}

void tkGLFronFace(TkGLInterface GLInterface, GLenum Mode)
{
    GLInterface->pfn_glFrontFace(Mode);
}

void tkGLHint(TkGLInterface GLInterface, GLenum Target, GLenum Mode)
{
    GLInterface->pfn_glHint(Target, Mode);
}

void tkGLLineWidth(TkGLInterface GLInterface, GLfloat Width)
{
    GLInterface->pfn_glLineWidth(Width);
}

void tkGLPointSize(TkGLInterface GLInterface, GLfloat Size)
{
    GLInterface->pfn_glPointSize(Size);
}

void tkGLPolygonMode(TkGLInterface GLInterface, GLenum Face, GLenum Mode)
{
    GLInterface->pfn_glPolygonMode(Face, Mode);
}

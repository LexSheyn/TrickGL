#include "TrickGLInterface.h"

#include <wglext.h>

#include <stdlib.h>

typedef struct TkGLInterface_T
{
    PFNGLCULLFACEPROC          pfn_glGullFace;
    PFNGLFRONTFACEPROC         pfn_glFrontFace;
    PFNGLHINTPROC              pfn_glHint;
    PFNGLLINEWIDTHPROC         pfn_glLineWidth;
    PFNGLPOINTSIZEPROC         pfn_glPointSize;
    PFNGLPOLYGONMODEPROC       pfn_glPolygonMode;
    PFNGLSCISSORPROC           pfn_glScissor;
    PFNGLTEXPARAMETERFPROC     pfn_glTexParameterf;
    PFNGLTEXPARAMETERFVPROC    pfn_glTexParameterfv;
    PFNGLTEXPARAMETERIPROC     pfn_glTexParameteri;
    PFNGLTEXPARAMETERIVPROC    pfn_glTexParameteriv;
    PFNGLTEXIMAGE1DPROC        pfn_glTexImage1D;
    PFNGLTEXIMAGE2DPROC        pfn_glTexImage2D;
    PFNGLDRAWBUFFERPROC        pfn_glDrawBuffer;
    PFNGLCLEARPROC             pfn_glClear;
    PFNGLCLEARCOLORPROC        pfn_glClearColor;
    PFNGLCLEARSTENCILPROC      pfn_glClearStencil;
    PFNGLCLEARDEPTHPROC        pfn_glClearDepth;
    PFNGLSTENCILMASKPROC       pfn_glStencilMask;
    PFNGLCOLORMASKPROC         pfn_glColorMask;
    PFNGLDEPTHMASKPROC         pfn_glDepthMask;
    PFNGLDISABLEPROC           pfn_glDisable;
    PFNGLENABLEPROC            pfn_glEnable;
    PFNGLFINISHPROC            pfn_glFinish;
    PFNGLFLUSHPROC             pfn_glFlush;
    PFNGLBLENDFUNCPROC         pfn_glBlendFunc;
    PFNGLLOGICOPPROC           pfn_glLogicOp;
    PFNGLSTENCILFUNCPROC       pfn_glStencilFunc;
    PFNGLSTENCILOPPROC         pfn_glStencilOp;
    PFNGLDEPTHFUNCPROC         pfn_glDepthFunc;
    PFNGLPIXELSTOREFPROC       pfn_glPixelStoref;
    PFNGLPIXELSTOREIPROC       pfn_glPixelStorei;
    PFNGLREADBUFFERPROC        pfn_glReadBuffer;
    PFNGLREADPIXELSPROC        pfn_glReadPixels;
    PFNGLGETBOOLEANVPROC       pfn_glGetBooleanv;
    PFNGLGETDOUBLEVPROC        pfn_glGetDoublev;
} TkGLInterface_T;

TkResult TK_CALL tkCreateGLInterface(void* Allocator, TkGLInterface* p_GLInterface)
{
    *p_GLInterface = malloc(sizeof(TkGLInterface_T));

    TkGLInterface GLInterface = *p_GLInterface;

    if (GLInterface)
    {
        return TK_ERROR_OUT_OF_HOST_MEMORY;
    }

    GLInterface->pfn_glGullFace    = wglGetProcAddress("glGullFace");
    GLInterface->pfn_glFrontFace   = wglGetProcAddress("glFrontFace");
    GLInterface->pfn_glHint        = wglGetProcAddress("glHint");
    GLInterface->pfn_glLineWidth   = wglGetProcAddress("glLineWidth");
    GLInterface->pfn_glPointSize   = wglGetProcAddress("glPointSize");
    GLInterface->pfn_glPolygonMode = wglGetProcAddress("glPolygonMode");

    return TK_SUCCESS;
}

void TK_CALL tkDestroyGLInterface(TkGLInterface GLInterface)
{
    free(GLInterface);
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

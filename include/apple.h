// These are basically for system macros that need to be included for this to
// work on apple devices, which is what I'm developing on.

#ifdef __APPLE__
#define glGenVertexArrays glGenVertexArraysAPPLE
#define glBindVertexArray glBindVertexArrayAPPLE
#define glDeleteVertexArrays glDeleteVertexArraysAPPLE

#define GL_GLEXT_PROTOTYPES 1
#include <OpenGL/gl3.h>
#include <OpenGL/gl3ext.h>

#endif

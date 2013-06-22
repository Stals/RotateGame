#ifndef CC_UNDER_MARMALADE
#   define CC_UNDER_MARMALADE 1
#endif
#ifndef I3D_OS_S3E
#   define I3D_OS_S3E 1
#endif
#ifndef I3D_PLATFORM_S3E
#   define I3D_PLATFORM_S3E 1
#endif
#ifndef IW_APP_NAME
#   define IW_APP_NAME "HelloCPP"
#endif
#ifndef IW_APP_VERSION
#   define IW_APP_VERSION "1.0"
#endif
#ifndef IW_MKF_BOX2D
#   define IW_MKF_BOX2D 1
#endif
#ifndef IW_MKF_COCOS2DX
#   define IW_MKF_COCOS2DX 1
#endif
#ifndef IW_MKF_FREETYPE
#   define IW_MKF_FREETYPE 1
#endif
#ifndef IW_MKF_IWGL
#   define IW_MKF_IWGL 1
#endif
#ifndef IW_MKF_IWUTIL
#   define IW_MKF_IWUTIL 1
#endif
#ifndef IW_MKF_LIBJPEG
#   define IW_MKF_LIBJPEG 1
#endif
#ifndef IW_MKF_LIBPNG
#   define IW_MKF_LIBPNG 1
#endif
#ifndef IW_MKF_LIBTIFF
#   define IW_MKF_LIBTIFF 1
#endif
#ifndef IW_MKF_LIBWEBP
#   define IW_MKF_LIBWEBP 1
#endif
#ifndef IW_MKF_ZLIB
#   define IW_MKF_ZLIB 1
#endif
#ifndef IW_PLATFORM_S3E
#   define IW_PLATFORM_S3E 1
#endif
#ifndef IW_SDK
#   define IW_SDK 1
#endif
#ifndef MARMALADE
#   define MARMALADE 1
#endif
#ifndef S3E_INCLUDE_LEGACY
#   define S3E_INCLUDE_LEGACY 1
#endif
#ifndef _CRT_SECURE_NO_DEPRECATE
#   define _CRT_SECURE_NO_DEPRECATE 1
#endif
#ifndef __S3E__
#   define __S3E__ 1
#endif

/* including "extra_body" specified by the mkb plugin */

#undef win32

#ifndef unix
    #define unix
#endif

#ifndef __unix
    #define __unix
#endif

/*
#ifndef _REENTRANT
    #define _REENTRANT
#endif
*/

#if !defined I3D_ARCH_ARM && !defined I3D_ARCH_X86 && !defined I3D_ARCH_AMD64 && !defined I3D_ARCH_MIPS && !defined I3D_ARCH_PS3 && !defined I3D_ARCH_X360 && !defined I3D_ARCH_PSP
    #if defined __ARMCC_VERSION || defined __ARMC__ || defined __arm__
        #define I3D_ARCH_ARM
    #elif defined __mipsel || defined __MIPSEL
        #define I3D_ARCH_MIPS
    #elif defined __amd64
        #define I3D_ARCH_AMD64
    #else
        #define I3D_ARCH_X86
    #endif
#endif

#if defined I3D_ARCH_X86 && !defined __i386__
    #define __i386__
#endif

#if defined I3D_ARCH_ARM && !defined __ARM__
    #define __ARM__
#endif

#if defined __cplusplus && defined _MSC_VER && _MSC_VER < 1400 && !defined IW_WCHAR_T_DEFINED && !defined __clang__
    // wchar_t is a builtin in C++ .. but not for MSVC <= 2003
    typedef unsigned short wchar_t;
    #define IW_WCHAR_T_DEFINED
#endif

#if defined _MSC_VER && !defined __clang__
    #pragma warning (disable: 4786)
#endif

#if !defined __S3E_CL_WRAPPER
    #if __COUNTER__ < 1 //Effectively '#ifndef intellisense'
        #error "Wrong compiler used.  Please run s3eConfig to configure Visual Studio"
    #endif
#endif

#undef _WIN32
#undef WIN32
#undef __linux__
#undef __linux
#undef __gnu_linux__
#undef linux

#if defined __i386__ && defined __ANDROID__
#ifndef S3E_ANDROID_X86
#   define S3E_ANDROID_X86 1
#endif
#endif

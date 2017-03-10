/*
 * CSP library
 * Copyright (C) 2017, Cosmed s.r.l. <http://www.cosmed.com/>
 * Author: Gabriele Filosofi <gabrielef@cosmed.it>
 */

#ifndef CSP_CONFIG_H
#define CSP_CONFIG_H

/* Set platform */
#if defined(__APPLE__) && defined(__MACH__) //Darwin
# include <TargetConditionals.h>
# if TARGET_IPHONE_SIMULATOR == 1
#  define PLATFORM_IPHONE_SIM //iOS in Xcode simulator
#  warning This is a iPhone Sim Platform.
# elif TARGET_OS_IPHONE == 1
#  define PLATFORM_IPHONE //iOS
//#  warning This is a iPhone Platform.
# elif TARGET_OS_MAC == 1 //OSX
#  define PLATFORM_MACOSX
#  warning This is a Darwin Platform.
# endif
#elif defined(__ANDROID__)
   #define PLATFORM_ANDROID
#elif defined(linux) || defined (__linux) //Linux
   #define PLATFORM_LINUX
#else
#  error Platform not available.
#endif

/* Set to 1 to allow CSP to operate as a Product */
# define CSP_FOR_PRODUCT	0
/* Set to 1 to allow CSP to operate as a Device */
# define CSP_FOR_DEVICE		1

/* Must be either a Product or a Device */
#if !(CSP_FOR_PRODUCT ^ CSP_FOR_DEVICE)
# error Please define and set CSP_FOR_PRODUCT or CSP_FOR_DEVICE
#else /* Check Product and Device platform restrictions */
# if CSP_FOR_PRODUCT
#  ifndef PLATFORM_LINUX
#   ifndef BUILD_FOR_HOST
#    error K5 is the only available product.
#   endif
#  endif
# endif
# if CSP_FOR_DEVICE
#  ifndef PLATFORM_IPHONE
#   ifndef BUILD_FOR_HOST
#   error Apple iPhone is the only device platform.
#   endif
#  endif
# endif
#endif

/* Set to 1 to allow CSPRunLoop to be used */
//#define CSP_USE_RUNLOOP 1

/* Set to 1 to allow CSP code use malloc to allocate buffers */
#define CSP_ALLOW_MALLOC 0

/* Set to 1 to allow CSP implementation code use large memory allocations (> 64K) for packets */
//#define CSP_ALLOW_LARGE_PACKET_MALLOC 1

/* Set to 1 to allow CSP code to keep track of stats */
//#define CSP_ALLOW_STATS 0

#define CSP_VERSION		("0.1.1")
#define CSP_VERSION_MAJOR	(0)
#define CSP_VERSION_MINOR	(1)
#define CSP_VERSION_BUILD	(1)

#define NMEA_CONVSTR_BUF	(256)
#define NMEA_TIMEPARSE_BUF	(256)

#define NMEA_POSIX(x)		x
#define NMEA_INLINE		inline

#if !defined(NDEBUG)
# include <assert.h>
# define CSP_ASSERT(x)	assert(x)
#else
# define CSP_ASSERT(x)
#endif

#endif /* #ifndef CSP_CONFIG_H */

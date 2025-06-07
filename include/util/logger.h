#ifndef __LOGGER_H__
#define __LOGGER_H__

#include <iostream>  // cout

#include "main.h"  // yrc

#define YRC(x)                               \
    do {                                     \
        yrc __rc__ = x;                      \
        if (__rc__ != YRC_OK) return __rc__; \
    } while (0)

#define YRCL(x)                                                       \
    do {                                                              \
        yrc __rc__ = x;                                               \
        if (__rc__ != YRC_OK) {                                       \
            std::cout << "Error: " << x << ", at " << __FILE__ << ":" \
                      << __LINE__ << std::endl;                       \
            return __rc__;                                            \
        }                                                             \
    } while (0)

#define YRCL_SDL(x)                                                         \
    do {                                                                    \
        yrc __rc__ = x;                                                     \
        if (__rc__ != YRC_OK) {                                             \
            std::cout << "Error: " << SDL_GetError() << ", at " << __FILE__ \
                      << ":" << __LINE__ << std::endl;                      \
            return __rc__;                                                  \
        }                                                                   \
    } while (0)

#endif  // __LOGGER_H__

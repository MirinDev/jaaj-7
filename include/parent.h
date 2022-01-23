#ifndef PARENT_H
#define PARENT_H
#include <iostream>
#include <filesystem>

#if defined(WIN32)||defined(_WIN32)||defined(__WIN32)&&!defined(__CYGWIN__)
static const std::string bar="\\";
#else
static const std::string bar="/";
#endif

#endif
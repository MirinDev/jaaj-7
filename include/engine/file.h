#ifndef FILE_H
#define FILE_H
#include <iostream>
#include <filesystem>

#if defined(WIN32)||defined(_WIN32)||defined(__WIN32)&&!defined(__CYGWIN__)
static const std::string bar="\\";
#else
static const std::string bar="/";
#endif

static std::string openFile(const char *file){
	std::ifstream in(file, std::ios::binary);
	if(in){
		std::string contents;
		in.seekg(0, std::ios::end);
		contents.resize(in.tellg());
		in.seekg(0, std::ios::beg);
		in.read(&contents[0], contents.size());
		in.close();
		return(contents);
	}
	throw(errno);
}

#endif
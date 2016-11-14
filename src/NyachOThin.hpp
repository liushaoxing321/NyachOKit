#ifndef NYACHOTHIN_H
#define NYACHOTHIN_H

#ifdef __APPLE__
#import <mach-o/fat.h>
#import <mach-o/loader.h>
#else
#error "OS X Only For Now"

#endif
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <typeinfo>
#include <stdexcept>
#include <exception>
using namespace std;
class NyachOThin {
	private:
		std::ifstream & inputStream;
		struct mach_header* Header;
	//protected:

	public:
		NyachOThin(std::ifstream & rawData);
		std::string dump();
} ;

#endif
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

#include "EndianUtils.hpp"
#include "NyachOMachHeader.hpp"

using namespace std;
class NyachOThin {
	private:
		NyachOMachHeader* Header;
	public:
		NyachOThin(char* loc,unsigned long long size);
		std::string dump();
        bool shouldSwap=false;//Swap Endian if needed
} ;

#endif

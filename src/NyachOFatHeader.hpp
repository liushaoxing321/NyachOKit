#ifndef NYACHOFATHEADER_H
#define NYACHOFATHEADER_H

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

using namespace std;
class NyachOFatHeader {
	public:
		NyachOFatHeader(char* loc);
		std::string dump();
        uint32_t	magic;		/* FAT_MAGIC or FAT_MAGIC_64 */
        uint32_t	nfat_arch;
        bool is64;
        bool shouldSwap=false;//Swap Endian if needed
    
} ;

#endif

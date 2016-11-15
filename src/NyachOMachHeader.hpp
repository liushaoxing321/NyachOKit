#ifndef NYACHOMACHHEADER_H
#define NYACHOMACHHEADER_H
#ifdef __APPLE__
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
class NyachOMachHeader {
protected:
    void* Header;
public:
    NyachOMachHeader(char* loc);
    std::string dump();
    bool is64;
    bool shouldSwap=false;//Swap Endian if needed
    uint32_t	magic;		/* mach magic number identifier */
    cpu_type_t	cputype;	/* cpu specifier */
    cpu_subtype_t	cpusubtype;	/* machine specifier */
    uint32_t	filetype;	/* type of file */
    uint32_t	ncmds;		/* number of load commands */
    uint32_t	sizeofcmds;	/* the size of all the load commands */
    uint32_t	flags;		/* flags */
    uint32_t	reserved;	/* reserved */
} ;

#endif

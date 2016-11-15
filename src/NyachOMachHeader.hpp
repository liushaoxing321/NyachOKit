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
public:
    NyachOMachHeader(char* loc);
    std::string dump();
    struct mach_header_64 Header={0};
    bool is64;
    bool shouldSwap=false;//Swap Endian if needed
} ;

#endif

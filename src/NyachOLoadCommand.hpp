//
//  NyachOLoadCommand.hpp
//  NyachO
//
//  Created by Zhang Naville on 15/11/2016.
//
//

#ifndef NyachOLoadCommand_hpp
#define NyachOLoadCommand_hpp

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
class NyachOLoadCommand {
public:
    NyachOLoadCommand(char* loc,bool shouldSwap=false);
    virtual std::string dump();
    void* commandData;//struct representing different struct load_command s. overridden by subclass
    uint32_t cmd;		/* type of load command */
    uint32_t cmdsize;	/* total size of command in bytes */
    bool shouldSwap=false;//Swap Endian if needed
} ;



#endif

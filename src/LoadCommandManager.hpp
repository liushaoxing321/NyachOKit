//
//  LoadCommandManager.hpp
//  NyachO
//
//  Created by Zhang Naville on 15/11/2016.
//
//

#ifndef LoadCommandManager_hpp
#define LoadCommandManager_hpp

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
#include "NyachOLoadCommand.hpp"
#include "LCSegment.hpp"
#include "LCEncryptionInfo.hpp"
#include "LCDylibCommand.hpp"

using namespace std;
class LoadCommandManager{
    protected:
        bool shouldSwap;
    public:
        static NyachOLoadCommand* ParseLC(char* loc,bool shouldSwap);
    
};

#endif /* LoadCommandManager_hpp */

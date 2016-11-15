//
//  LCDylibCommand.hpp
//  NyachO
//
//  Created by Zhang Naville on 15/11/2016.
//
//

#ifndef LCDylibCommand_hpp
#define LCDylibCommand_hpp
#include "NyachOLoadCommand.hpp"
class LCDylibCommand:public NyachOLoadCommand{
protected:
    void* LC;//Pointer to encryption_info_command or encryption_info_command_64
public:
    LCDylibCommand(char* LCPosition,bool shouldSwap);
    string dump();
    string pathName;
    uint32_t timestamp;			/* library's build time stamp */
    uint32_t current_version;		/* library's current version number */
    uint32_t compatibility_version;	/* library's compatibility vers number*/
    
};

#endif /* LCDylibCommand_hpp */

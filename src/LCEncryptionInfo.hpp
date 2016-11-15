//
//  LCEncryptionInfo.hpp
//  NyachO
//
//  Created by Zhang Naville on 15/11/2016.
//
//

#ifndef LCEncryptionInfo_hpp
#define LCEncryptionInfo_hpp
#include "NyachOLoadCommand.hpp"
class LCEncryptionInfo:public NyachOLoadCommand{
protected:
    void* LC;//Pointer to encryption_info_command or encryption_info_command_64
public:
    LCEncryptionInfo(char* LCPosition,bool shouldSwap);
    string dump();
    uint32_t	cryptoff;	/* file offset of encrypted range */
    uint32_t	cryptsize;	/* file size of encrypted range */
    uint32_t	cryptid;	/* which enryption system,
                             0 means not-encrypted yet */
    
    
};
#endif /* LCEncryptionInfo_hpp */

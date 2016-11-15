//
//  NyachOLoadCommand.cpp
//  NyachO
//
//  Created by Zhang Naville on 15/11/2016.
//
//

#include "NyachOLoadCommand.hpp"
NyachOLoadCommand::NyachOLoadCommand(char* loc,bool shouldSwap){
    struct load_command* LC=(struct load_command*)loc;
    memcpy(this->commandData, loc,LC->cmdsize);
    this->cmd=LC->cmd;
    this->cmdsize=LC->cmdsize;
}

string NyachOLoadCommand::dump(){
    return "NyachOLoadCommand";
}

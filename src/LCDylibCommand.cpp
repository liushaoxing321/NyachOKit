//
//  LCDylibCommand.cpp
//  NyachO
//
//  Created by Zhang Naville on 15/11/2016.
//
//

#include "LCDylibCommand.hpp"
LCDylibCommand::LCDylibCommand(char* LCPosition,bool shouldSwap):NyachOLoadCommand(LCPosition,shouldSwap){
    struct dylib_command* DC=(struct dylib_command*) LCPosition;
    this->LC=DC;
    this->compatibility_version=DC->dylib.compatibility_version;
    this->timestamp=DC->dylib.timestamp;
    this->current_version=DC->dylib.current_version;
    char* name=LCPosition+DC->dylib.name.offset;
    //size_t stringSize=DC->cmdsize-sizeof(this->cmd)-sizeof(this->cmdsize)-sizeof(struct dylib);
    //pathName=string(name, stringSize);
    pathName=name;
    //std::cout<<pathName;
    
}

std::string LCDylibCommand::dump(){
    stringstream ss;
    ss<<NyachOLoadCommand::dump();
    ss<<"Path: "<<this->pathName<<std::endl;
    time_t time=this->timestamp;
    ss<<"Timestamp: "<<ctime(&time)<<std::endl;
    ss<<"Compatibility Version: "<<this->compatibility_version<<std::endl;
    ss<<"Current Version: "<<this->current_version<<std::endl;
    return ss.str();
}

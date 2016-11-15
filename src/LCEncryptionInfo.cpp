//
//  LCEncryptionInfo.cpp
//  NyachO
//
//  Created by Zhang Naville on 15/11/2016.
//
//

#include "LCEncryptionInfo.hpp"

#define SetupThisFromLC(LC) this->cmd=LC->cmd;\
    this->cmdsize=LC->cmdsize;\
    this->cryptoff=LC->cryptoff;\
    this->cryptsize=LC->cryptsize;\
    this->cryptid=LC->cryptid;




LCEncryptionInfo::LCEncryptionInfo(char* LCPosition,bool shouldSwap):NyachOLoadCommand(LCPosition,shouldSwap){
    struct encryption_info_command* LC=(struct encryption_info_command*)LCPosition;
    SetupThisFromLC(LC);
}
string LCEncryptionInfo::dump(){
    stringstream ss;
    ss<<NyachOLoadCommand::dump();
    ss<<"cryptoff: "<<std::hex<<this->cryptoff<<endl;
    ss<<"cryptsize: "<<std::hex<<this->cryptsize<<endl;
    ss<<"cryptid: "<<std::hex<<this->cryptid<<endl;
    return ss.str();
}

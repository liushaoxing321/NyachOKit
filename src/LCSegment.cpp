//
//  LCSegment.cpp
//  NyachO
//
//  Created by Zhang Naville on 15/11/2016.
//
//

#define SetupThisFromLC(LC) this->cmd=LC->cmd;\
    this->cmdsize=LC->cmdsize;\
    memcpy(this->segname,LC->segname,16);\
    this->vmaddr=LC->vmaddr;\
    this->vmsize=LC->vmsize;\
    this->fileoff=LC->fileoff;\
    this->filesize=LC->filesize;\
    this->maxprot=LC->maxprot;\
    this->initprot=LC->initprot;\
    this->nsects=LC->nsects;\
    this->flags=LC->flags

#include "LCSegment.hpp"
LCSegment::LCSegment(char* LCPosition,bool shouldSwap):NyachOLoadCommand(LCPosition,shouldSwap){
    bool is64=false;
    struct segment_command* JudgingArchSC=(struct segment_command*)LCPosition;
    switch (JudgingArchSC->cmd){
        case LC_SEGMENT:{
            //32bit header
            struct segment_command* LC=(struct segment_command*)LCPosition;
            /*if(shouldSwap){
                SwapSegmentCommand(LC);
            }*/
            SetupThisFromLC(LC);
            break;
        }
        case LC_SEGMENT_64:{
            is64=true;
            struct segment_command_64* LC=(struct segment_command_64*)LCPosition;
            /*if(shouldSwap){
                SwapSegment64Command(LC);
            }*/
            SetupThisFromLC(LC);
            break;
        }
    default:
        throw std::invalid_argument( "This will never be executed\n" );
    }
}
string LCSegment::dump(){
    stringstream ss;
    ss<<NyachOLoadCommand::dump();
    ss<<"segname: "<<this->segname<<endl;
    ss<<"vmaddr: 0x"<<std::hex<<this->vmaddr<<endl;
    ss<<"vmsize: 0x"<<std::hex<<this->vmsize<<endl;
    ss<<"fileoff: 0x"<<std::hex<<this->fileoff<<endl;
    ss<<"filesize: 0x"<<std::hex<<this->filesize<<endl;
    ss<<"maxprot: 0x"<<std::hex<<this->maxprot<<endl;
    ss<<"initprot: 0x"<<std::hex<<this->initprot<<endl;
    ss<<"nsects: 0x"<<std::hex<<this->nsects<<endl;
    ss<<"flags: 0x"<<std::hex<<this->flags<<endl;
    return ss.str();
}

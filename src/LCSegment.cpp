//
//  LCSegment.cpp
//  NyachO
//
//  Created by Zhang Naville on 15/11/2016.
//
//

#include "LCSegment.hpp"
LCSegment::LCSegment(char* LCPosition,bool shouldSwap):NyachOLoadCommand(LCPosition,shouldSwap){
    bool is64=false;
    struct segment_command* JudgingArchSC=(struct segment_command*)LCPosition;
    switch (JudgingArchSC->cmd){
        case LC_SEGMENT:{
            //32bit header
            struct segment_command* LC=(struct segment_command*)LCPosition;
            if(shouldSwap){
                SwapSegmentCommand(LC);
            }
        }
        case LC_SEGMENT_64:{
            is64=true;
            struct segment_command_64* LC=(struct segment_command_64*)LCPosition;
            if(shouldSwap){
                SwapSegment64Command(LC);
            }
        }
    default:
        throw std::invalid_argument( "This will never be executed\n" );
    }
}

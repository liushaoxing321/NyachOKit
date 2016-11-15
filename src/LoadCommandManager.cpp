//
//  LoadCommandManager.cpp
//  NyachO
//
//  Created by Zhang Naville on 15/11/2016.
//
//

#include "LoadCommandManager.hpp"
NyachOLoadCommand* LoadCommandManager::ParseLC(char* LCPosition,bool Swap){
    
    struct load_command* LC=(struct load_command*)LCPosition;
    switch (LC->cmd) {//Register handling classes here
        case LC_SEGMENT:
            return new LCSegment(LCPosition,Swap);
            break;
        case LC_SEGMENT_64:
            return new LCSegment(LCPosition,Swap);
            break;
            
        default:
#warning Using BaseLC Class here.
            return new NyachOLoadCommand(LCPosition,Swap);
            /*stringstream ss;
            ss<<"Unknown LoadCommand: "<<LC->cmd<<endl;
            throw std::invalid_argument(ss.str());*/
            break;
    }

    
}

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
    this->shouldSwap=Swap;
    switch (LC->cmd) {
        case LC_SEGMENT:
            return new LCSegment(LCPosition,Swap);
            break;
            
        default:
            stringstream ss;
            ss<<"Unknown LoadCommand: "<<LC->cmd<<endl;
            throw std::invalid_argument(ss.str());
            break;
    }

    
}

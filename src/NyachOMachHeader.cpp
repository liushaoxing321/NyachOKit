#include "NyachOMachHeader.hpp"
NyachOMachHeader::NyachOMachHeader(char* loc){
    this->Header=*(struct mach_header_64*)loc;
    this->is64=false;
    switch(Header.magic){
        case MH_MAGIC:
            std::cout<<"MH_MAGIC\n";
            break;
        case MH_CIGAM:
            std::cout<<"MH_CIGAM\n";
            this->shouldSwap=true;
            break;
        case MH_MAGIC_64:
            std::cout<<"MH_MAGIC_64\n";
            this->is64=true;
            break;
        case MH_CIGAM_64:
            std::cout<<"MH_CIGAM_64\n";
            this->is64=true;
            this->shouldSwap=true;
            break;
        default:
            throw std::invalid_argument( "Not a Thin Mach-O Executable\n" );
    }
    if(this->shouldSwap){
        if(this->is64){
            SwapMach64Header(&Header);
        }
        else{
            SwapMachHeader((struct mach_header *)&this->Header);
        }
    }

}
string NyachOMachHeader::dump(){
    
  return "Mach-O Header";
}

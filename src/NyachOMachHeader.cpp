#include "NyachOMachHeader.hpp"


#define UpdateThisFromHeader(Header) \
    this->magic=Header->magic;\
    this->cputype=Header->cputype;\
    this->cpusubtype=Header->cpusubtype;\
    this->filetype=Header->filetype;\
    this->sizeofcmds=Header->sizeofcmds;\
    this->ncmds=Header->ncmds;\
    this->flags=Header->flags;\




NyachOMachHeader::NyachOMachHeader(char* loc){
    struct mach_header* ArchJudgingheader=(struct mach_header*)loc;
    this->is64=false;
    switch(ArchJudgingheader->magic){
        case MH_MAGIC:
            break;
        case MH_CIGAM:
            this->shouldSwap=true;
            break;
        case MH_MAGIC_64:
            this->is64=true;
            break;
        case MH_CIGAM_64:
            this->is64=true;
            this->shouldSwap=true;
            break;
        default:
            throw std::invalid_argument( "Not a Thin Mach-O Executable\n" );
    }
    if(this->shouldSwap){
        if(this->is64){
            struct mach_header_64* Header=(struct mach_header_64 *)loc;
            SwapMach64Header(Header);
            UpdateThisFromHeader(Header);
            this->reserved=Header->reserved;
        }
        else{
            struct mach_header* Header=(struct mach_header *)loc;
            SwapMachHeader(Header);
            UpdateThisFromHeader(Header);
        }
    }
    else{
        if(this->is64){
            struct mach_header_64* Header=(struct mach_header_64 *)loc;
            UpdateThisFromHeader(Header);
            this->reserved=Header->reserved;
        }
        else{
            struct mach_header* Header=(struct mach_header *)loc;
            UpdateThisFromHeader(Header);
        }
        
    }

    
    
}
string NyachOMachHeader::dump(){
    stringstream ss;
    ss<<"Thin MachO Header:\n";
    ss<<"magic:0x"<<std::hex<<this->magic<<endl;
    ss<<"cputype:0x"<<std::hex<<this->cputype<<endl;
    ss<<"cpusubtype:0x"<<std::hex<<this->cpusubtype<<endl;
    ss<<"filetype:0x"<<std::hex<<this->filetype<<endl;
    ss<<"sizeofcmds:0x"<<std::hex<<this->sizeofcmds<<endl;
    ss<<"flags:0x"<<std::hex<<this->flags<<endl;
    return ss.str();
}

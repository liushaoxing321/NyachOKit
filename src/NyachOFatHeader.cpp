#import "NyachOFatHeader.hpp"
NyachOFatHeader::NyachOFatHeader(char* loc){
    struct fat_header* Header=(struct fat_header*)loc;
    this->is64=false;
    bool isLittleEndian=false;
    switch(Header->magic){
        case FAT_MAGIC:
            break;
        case FAT_CIGAM:
            isLittleEndian=true;
            break;
        case FAT_MAGIC_64:
            this->is64=true;
            break;
        case FAT_CIGAM_64:
            this->is64=true;
            isLittleEndian=true;
            break;
        default:
            throw std::invalid_argument( "Not a Fat Mach-O Executable\n" );
    }
    this->shouldSwap=isLittleEndian;
    if(this->shouldSwap){
        SwapFatHeader(Header);
    }
    this->magic=Header->magic;
    this->nfat_arch=Header->nfat_arch;
    
}

string NyachOFatHeader::dump(){
    stringstream ss;
    ss<<"Fat MachO Header:\n";
    ss<<"magic:0x"<<std::hex<<this->magic<<endl;
    ss<<"nfat_arch:0x"<<std::hex<<this->nfat_arch<<endl;
    return ss.str();
}

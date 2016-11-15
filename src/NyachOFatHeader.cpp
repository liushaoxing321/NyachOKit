#import "NyachOFatHeader.hpp"
NyachOFatHeader::NyachOFatHeader(char* loc){
    Header=*(struct fat_header*)loc;
    this->is64=false;
    switch(Header.magic){
        case FAT_MAGIC:
            std::cout<<"FAT_MAGIC\n";
            break;
        case FAT_CIGAM:
            std::cout<<"FAT_CIGAM\n";
           this->shouldSwap=true;
            break;
        case FAT_MAGIC_64:
            std::cout<<"FAT_MAGIC_64\n";
            this->is64=true;
            break;
        case FAT_CIGAM_64:
            std::cout<<"FAT_CIGAM_64\n";
            this->is64=true;
            this->shouldSwap=true;
            break;
        default:
            throw std::invalid_argument( "Not a Fat Mach-O Executable\n" );
    }
    if(this->shouldSwap){
        SwapFatHeader(&this->Header);
    }
    
}

string NyachOFatHeader::dump(){
    stringstream ss;
    ss<<"Fat Mach-O Header nfat_arch:"<<this->Header.nfat_arch<<endl;
    return ss.str();
}

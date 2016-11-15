#include "NyachOFat.hpp"
using namespace std;
NyachOFat::NyachOFat(std::ifstream & rawData):inputStream(rawData){
    char * buffer = new char [sizeof(struct fat_header)];
    rawData.read (buffer,sizeof(struct fat_header));
    
    this->Header=new NyachOFatHeader(buffer);
    for(int i =0;i<this->Header->Header.nfat_arch;i++){
        int currentPosition=rawData.tellg();
        if(this->Header->is64){
            struct fat_arch_64* fh=(struct fat_arch_64*)new char [sizeof(struct fat_arch_64)];
            rawData.read((char*)fh, sizeof(struct fat_arch_64));
            if(this->Header->shouldSwap){
                SwapFatArch64(fh);
            }
            rawData.seekg(fh->offset);
            char* archData=new char [fh->size];
            rawData.read(archData, fh->size);
            
            NyachOThin* currentArch=new NyachOThin(archData,fh->size);
            
            delete[] fh;
            rawData.seekg(currentPosition+sizeof(fat_arch_64));
            
        }
        else{
            struct fat_arch* fh=(struct fat_arch*)new char [sizeof(struct fat_arch)];
            rawData.read((char*)fh, sizeof(struct fat_arch));
            if(this->Header->shouldSwap){
                SwapFatArch(fh);
            }
            rawData.seekg(fh->offset);
            char* archData=new char [fh->size];
            rawData.read(archData, fh->size);
            
            NyachOThin* currentArch=new NyachOThin(archData,fh->size);
            
            delete[] fh;
            rawData.seekg(currentPosition+sizeof(fat_arch));;
        }
    }
}



string NyachOFat::dump(){
	stringstream ss;
    ss<<this->Header->dump();
    return ss.str();

}

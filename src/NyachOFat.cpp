#include "NyachOFat.hpp"
using namespace std;
NyachOFat::NyachOFat(std::ifstream & rawData):inputStream(rawData){
	this->Header=(struct fat_header*)malloc(sizeof(struct fat_header));
	rawData.read ((char*)this->Header,sizeof(struct fat_header));
	bool TargetisLitteEndian;
	switch(this->Header->magic){
		case FAT_MAGIC:
			std::cout<<"FAT_MAGIC\n";
			break;
		case FAT_CIGAM:
			std::cout<<"FAT_CIGAM\n";
			TargetisLitteEndian=true;
			break;
		case MH_MAGIC_64:
			std::cout<<"FAT_MAGIC_64\n";
			break;
		case MH_CIGAM_64:
			std::cout<<"FAT_CIGAM_64\n";
			TargetisLitteEndian=true;
			break;
		default:
			throw std::invalid_argument( "Not a Fat Mach-O Executable\n" );
	}
	this->shouldSwap=((LITTLEENDIAN ==1)&& !TargetisLitteEndian)||(!(LITTLEENDIAN!=1)&& TargetisLitteEndian);
	if(this->shouldSwap){
		SwapFatHeader(this->Header);
	}


	//Reset Stream to the first fat_arch, which is right after fat_header
	this->inputStream.seekg(sizeof(struct fat_header), ios::beg);
	//Split out Thin Mach-Os
	for(int index=0;index<this->Header->nfat_arch;index++){
		struct fat_arch* currentArch=(struct fat_arch *)malloc(sizeof(struct fat_arch));
		this->inputStream.read ((char*)currentArch,sizeof(struct fat_arch));
		if(this->shouldSwap){
			SwapFatArch(currentArch);
		}


		cout<<"Found Arch at:"<<currentArch->offset<<" and size:"<<currentArch->size<<"\n";
		

	}
}



string NyachOFat::dump(){
	stringstream ss;
	ss<<"Fat Mach-O With "<<this->Header->nfat_arch<<" Thin Archs\n";
	return ss.str();

}
#include "NyachOThin.hpp"
using namespace std;
NyachOThin::NyachOThin(std::ifstream & rawData):inputStream(rawData){
	this->Header=(struct mach_header*)malloc(sizeof(struct mach_header));
	rawData.read ((char*)this->Header,sizeof(struct mach_header));
	bool TargetisLitteEndian;
	switch(this->Header->magic){
		case MH_MAGIC:
			std::cout<<"MH_MAGIC\n";
			break;
		case MH_CIGAM:
			std::cout<<"MH_CIGAM\n";
			TargetisLitteEndian=true;
			break;
		case MH_MAGIC_64:
			std::cout<<"MH_MAGIC_64\n";
			break;
		case MH_CIGAM_64:
			std::cout<<"MH_CIGAM_64\n";
			TargetisLitteEndian=true;
			break;
		default:
			throw std::invalid_argument( "Not a Thin Mach-O Executable\n" );
	}
	this->shouldSwap=((LITTLEENDIAN ==1)&& !TargetisLitteEndian)||(!(LITTLEENDIAN!=1)&& TargetisLitteEndian);
	if(this->shouldSwap){
		SwapFatHeader(this->Header);
	}
}



string NyachOThin::dump(){
	stringstream ss;
	ss<<"Thin Mach-O With "<<this->Header->ncmds<<" Load Commands";
	return ss.str();

}
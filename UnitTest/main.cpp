#include "NyachOThin.hpp"
#include "NyachOFat.hpp"
#include <iostream>
int main(int argc, char *argv[], char *envp[]) {
    std::ifstream iOSmachO;
	iOSmachO.open("/Users/Naville/Desktop/Development/qqmusiclrcexporter/QQMusicPad",ios_base::binary);
	NyachOFat iOSnya=NyachOFat::NyachOFat(iOSmachO);
	std::cout<<iOSnya.dump();
    std::cout<<"OSX Mach-O";
    
    std::ifstream FatMachO;
    FatMachO.open("/Users/Naville/NyachOTest",ios_base::binary);

	NyachOFat Fatnya=NyachOFat::NyachOFat(FatMachO);
	std::cout<<Fatnya.dump();
    
	return 0;
}

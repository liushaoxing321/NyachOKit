#include "NyachOThin.hpp"
#include "NyachOFat.hpp"
#include <iostream>
int main(int argc, char *argv[], char *envp[]) {
	/*std::ifstream OSXmachO;
	OSXmachO.open("/Applications/Launchpad.app/Contents/MacOS/Launchpad",ios_base::binary);
	NyachOThin OSXnya=NyachOThin::NyachOThin(OSXmachO);
	std::cout<<OSXnya.dump();

	std::ifstream iOSmachO;
	iOSmachO.open("/Users/Naville/iOSMachO",ios_base::binary);
	NyachOThin iOSnya=NyachOThin::NyachOThin(iOSmachO);
	std::cout<<iOSnya.dump();*/
	std::ifstream FatMachO;
	FatMachO.open("/Users/Naville/NyachOiOSTest.dylib",ios_base::binary);
    //FatMachO.open("/Users/Naville/Desktop/Development/qqmusiclrcexporter/QQMusicPad",ios_base::binary);

	NyachOFat Fatnya=NyachOFat::NyachOFat(FatMachO);
	std::cout<<Fatnya.dump();
    
	return 0;
}

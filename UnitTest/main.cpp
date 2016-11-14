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
	std::ifstream iOSFatMachO;
	iOSFatMachO.open("/Users/Naville/iOSFatMachO",ios_base::binary);
	NyachOFat iOSFatnya=NyachOFat::NyachOFat(iOSFatMachO);
	std::cout<<iOSFatnya.dump();

	return 0;
}
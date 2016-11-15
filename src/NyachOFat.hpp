#ifndef NYACHOFAT_H
#define NYACHOFAT_H

#ifdef __APPLE__
#import <mach-o/fat.h>
#import <mach-o/loader.h>
#else
#error "OS X Only For Now"
#endif

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <typeinfo>
#include <stdexcept>
#include <exception>
#include <vector>


#include "NyachOThin.hpp"
#include "NyachOFatHeader.hpp"
#include "EndianUtils.hpp"
using namespace std;
class NyachOFat {
	private:
		std::ifstream & inputStream;
		NyachOFatHeader* Header;
	protected:
		vector<NyachOThin*> sliceList;
		bool shouldSwap=false;//Swap Endian if needed

	public:
		NyachOFat(std::ifstream & rawData);
		std::string dump();
} ;

#endif

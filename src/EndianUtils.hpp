#include "endian.h"
#ifdef __APPLE__
#import <mach-o/fat.h>
#import <mach-o/loader.h>
#else
#error "OS X Only For Now"
#endif
using namespace std;
static void SwapFatHeader(struct fat_header* fh){
			fh->nfat_arch=be32toh(fh->nfat_arch);
}
static void SwapFatArch(struct fat_arch* fh){
			fh->cputype=be32toh(fh->cputype);
			fh->cpusubtype=be32toh(fh->cpusubtype);
			fh->offset=be32toh(fh->offset);
			fh->size=be32toh(fh->size);
			fh->align=be32toh(fh->align);
}


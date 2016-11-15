#ifndef ENDIANUTILS_H
#define ENDIANUTILS_H
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
static void SwapMachHeader(struct mach_header * fh){
	fh->cputype=be32toh(fh->cputype);
	fh->cpusubtype=be32toh(fh->cpusubtype);
	fh->filetype=be32toh(fh->filetype);
	fh->ncmds=be32toh(fh->ncmds);
	fh->sizeofcmds=be32toh(fh->sizeofcmds);
	fh->flags=be32toh(fh->flags);
}
static void SwapMach64Header(struct mach_header_64 * fh){
    fh->cputype=be32toh(fh->cputype);
    fh->cpusubtype=be32toh(fh->cpusubtype);
    fh->filetype=be32toh(fh->filetype);
    fh->ncmds=be32toh(fh->ncmds);
    fh->sizeofcmds=be32toh(fh->sizeofcmds);
    fh->flags=be32toh(fh->flags);
    fh->reserved=be32toh(fh->reserved);
}
static void SwapFatArch(struct fat_arch * fh){    
    fh->cputype=be32toh(fh->cputype);
    fh->cpusubtype=be32toh(fh->cpusubtype);
    fh->offset=be32toh(fh->offset);
    fh->size=be32toh(fh->size);
    fh->align=be32toh(fh->align);
}
static void SwapFatArch64(struct fat_arch_64 * fh){
    fh->cputype=be32toh(fh->cputype);
    fh->cpusubtype=be32toh(fh->cpusubtype);
    fh->offset=be32toh(fh->offset);
    fh->size=be32toh(fh->size);
    fh->align=be32toh(fh->align);
    fh->reserved=be32toh(fh->reserved);
}
static void SwapSegmentCommand(struct segment_command * sc){
//#error Unimplemented
}
static void SwapSegment64Command(struct segment_command_64 * sc){
//#error Unimplemented
}
#endif


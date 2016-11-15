//
//  LCSegment.hpp
//  NyachO
//
//  Created by Zhang Naville on 15/11/2016.
//
//

#ifndef LCSegment_hpp
#define LCSegment_hpp

#include "NyachOLoadCommand.hpp"
class LCSegment:public NyachOLoadCommand{
protected:
    void* LC;//Pointer to segment_command or segment_command_64
public:
    LCSegment(char* LCPosition,bool shouldSwap);
    string dump();
    uint32_t	cmd;		/* LC_SEGMENT_64 */
    uint32_t	cmdsize;	/* includes sizeof section_64 structs */
    char		segname[16];	/* segment name */
    uint64_t	vmaddr;		/* memory address of this segment */
    uint64_t	vmsize;		/* memory size of this segment */
    uint64_t	fileoff;	/* file offset of this segment */
    uint64_t	filesize;	/* amount to map from the file */
    vm_prot_t	maxprot;	/* maximum VM protection */
    vm_prot_t	initprot;	/* initial VM protection */
    uint32_t	nsects;		/* number of sections in segment */
    uint32_t	flags;		/* flags */
    
    
};
#endif /* LCSegment_hpp */

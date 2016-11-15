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
    char		segname[16];	/* segment name */
    uint64_t	fileoff;	/* file offset of this segment */
    uint64_t	filesize;	/* amount to map from the file */
    vm_prot_t	maxprot;	/* maximum VM protection */
    vm_prot_t	initprot;	/* initial VM protection */
    uint32_t	nsects;		/* number of sections in segment */
    uint32_t	flags;		/* flags */
    
private:
    uint64_t	vmaddr;		/* memory address of this segment */
    uint64_t	vmsize;		/* memory size of this segment */
    
    
};
#endif /* LCSegment_hpp */

#include "NyachOThin.hpp"
#include "LoadCommandManager.hpp"
using namespace std;
NyachOThin::NyachOThin(char* loc,unsigned long long size){
    this->Header= new NyachOMachHeader(loc);
    size_t offset=0;
    if(this->Header->is64){//Point offset to the first LC
        offset=offset+sizeof(struct mach_header_64);
    }
    else{
        offset=offset+sizeof(struct mach_header);
    }
    for(int i=0;i<this->Header->ncmds;i++){
        //Copy out the minimum memory to determine the size of this LC
        char* minimumData=new char[sizeof(struct load_command)];
        memcpy(minimumData, loc+offset, sizeof(struct load_command));
               
        struct load_command* minimumHeader=(struct load_command*)minimumData;
               
        //Constructor full LC
        char* currentLC=new char[minimumHeader->cmdsize];
        memcpy(currentLC, loc+offset, minimumHeader->cmdsize);
        
        NyachOLoadCommand* NYLC=LoadCommandManager::ParseLC(currentLC,this->Header->shouldSwap);
        this->LCList.push_back(NYLC);
        delete[] minimumData;
        offset=offset+NYLC->cmdsize; //Point offset to the next LC
    }
    
    
}



string NyachOThin::dump(){
	stringstream ss;
	ss<<this->Header->dump()<<endl;
    ss<<"LoadCommands:"<<endl;
    for(int i =0;i<this->LCList.size();i++){
        ss<<LCList.at(i)->dump()<<endl;
    }
	return ss.str();

}

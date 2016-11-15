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
    char* firstLCData=new char[sizeof(struct load_command)];
    memcpy (firstLCData,loc+offset,sizeof(struct load_command));
    
    struct load_command* previousLC=(struct load_command*)firstLCData;
    for(int i=0;i<this->Header->ncmds;i++){
        char* fullLC=new char[previousLC->cmdsize];
        memcpy (fullLC,loc+offset,previousLC->cmdsize);
        struct load_command* currentLC=(struct load_command*)fullLC;
        NyachOLoadCommand* NYLC=LoadCommandManager::ParseLC((char*)currentLC,this->Header->shouldSwap);
        this->LCList.push_back(NYLC);
        
        offset=offset+currentLC->cmdsize; //Point offset to the second LC
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

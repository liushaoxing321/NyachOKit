#include "NyachOThin.hpp"
using namespace std;
NyachOThin::NyachOThin(char* loc,unsigned long long size){
    this->Header= new NyachOMachHeader(loc);
    
    
}



string NyachOThin::dump(){
	stringstream ss;
	ss<<this->Header->dump()<<endl;
	return ss.str();

}

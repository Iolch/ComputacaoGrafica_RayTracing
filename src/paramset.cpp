#include "../include/paramset.h"


std::unique_ptr<void *> createObject(std::string tag_identifier, std::map<std::string, std::string> attributes){
    void * object;
    if(tag_identifier == "film") {
        Film f {attributes};
        object = &f;     
    }else
    if(tag_identifier == "background"){
    	Background b {attributes};
    	object = &b;
    }	

    std::unique_ptr<void*> result( new void *);
    *result = object;
    //std::cout << "DENTRO DA CREATEOBJECT " << *result << std::endl; 
    //std::cout << (static_cast<Film *>(*result))->getWidth() <<std::endl;	//OK RETORNA WIDTH CORRETAMENTE
    return result;
}
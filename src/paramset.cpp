#include "../include/parser.h"

std::unique_ptr<void *> createObject(std::string tag_identifier, std::map<std::string, std::string> attributes){
    void * object;
    if(tag_identifier == "film") {
        film f {attributes};
        object = &f;      
    }

    std::unique_ptr<void*> result( new void *);
    *result = object;
    std::cout << "DENTRO DA CREATEOBJECT " << *result << std::endl; 
    std::cout << (static_cast<film *>(*result))->getWidth() <<std::endl;	//OK RETORNA WIDTH CORRETAMENTE
    return result;
}
#include "../include/paramset.h"

void oi(){std::cout<<"oie"<<std::endl;}
std::unique_ptr<void *> createObject(std::string tag_identifier, std::map<std::string, std::string> attributes){
    void * object;
    if(tag_identifier == "film") {
        Film f = *new Film(attributes);
        object = &f;     
        std::cout << (static_cast<Film *>(&f))->getWidth()<<std::endl;
    }else
    if(tag_identifier == "background"){
    	Background b {attributes};
    	object = &b;
        std::cout << (static_cast<Background *>(&b))->getColor()<<std::endl;
    }	

    std::unique_ptr<void*> result( new void *);
    *result = object;
    //std::cout << "DENTRO DA CREATEOBJECT " << *result << std::endl; 
    //std::cout << (static_cast<Film *>(*result))->getWidth() <<std::endl;	//OK RETORNA WIDTH CORRETAMENTE
    return result;
}
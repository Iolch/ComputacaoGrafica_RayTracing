#include "../include/parser.h"

void * createObject(std::string tag_identifier, std::map<std::string, std::string> attributes){
    if(tag_identifier == "film") {
        film f {attributes};
	    return &f;
    }
}
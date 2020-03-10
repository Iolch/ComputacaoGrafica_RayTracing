#include "../include/parser.h"

void * createObject(std::string tag_identifier, std::map<std::string, std::string> attributes){
    void * object;
    if(tag_identifier == "film") {
        film f {attributes};
        object = &f;
    }
    return object;
}
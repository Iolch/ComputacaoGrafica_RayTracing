#include "../include/paramset.h"

std::map<std::string, std::map<std::string, std::string>> ParamSet::getObjects(){
    return objects;
}
void ParamSet::addObject(std::string tag_identifier, std::map<std::string, std::string> attributes){
    objects[tag_identifier] = attributes;
}   
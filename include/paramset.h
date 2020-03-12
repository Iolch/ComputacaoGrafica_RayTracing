#ifndef PARAMSETH
#define PARAMSETH

#include <map>
#include <fstream>
#include <string>
#include <memory>

class paramset{
    public:
    	std::unique_ptr<void *> createObject(std::string tag_identifier, std::map<std::string, std::string> attributes);
        //void * createObject(std::string tag_identifier, std::map<std::string, std::string> attributes);
};
#endif
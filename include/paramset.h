#ifndef PARAMSETH
#define PARAMSETH

#include <map>
#include <fstream>
#include <string>
#include <memory>

class ParamSet{
	std::map<std::string, std::map<std::string, std::string>> objects;
    public:
    	std::map<std::string, std::map<std::string, std::string>> getObjects(){return objects;}
    	void oi(){std::cout<<"oie"<<std::endl;}

    	void addObject(std::string tag_identifier, std::map<std::string, std::string> attributes){
    		objects[tag_identifier] = attributes;
    	}
    	std::unique_ptr<void *> createObject(std::string tag_identifier, std::map<std::string, std::string> attributes);
        //void * createObject(std::string tag_identifier, std::map<std::string, std::string> attributes);
};
#endif
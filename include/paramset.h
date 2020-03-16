#ifndef PARAMSETH
#define PARAMSETH

#include <map>
#include <fstream>
#include <string>
#include <memory>

class ParamSet{
	std::map<std::string, std::map<std::string, std::string>> objects;
    public:
    	std::map<std::string, std::map<std::string, std::string>> getObjects();
    	void addObject(std::string tag_identifier, std::map<std::string, std::string> attributes);
};
#endif
#ifndef PARSERH
#define PARSERH

#include <map>
#include <string>
#include "utils.h"
#include "../src/paramset.cpp"
struct tag_object {
  std::string tag_identifier;
  std::map<std::string, std::string> attributes;
};
class Parser{
	public:
		void readXML(std::string file_path, ParamSet * paramSet);
		tag_object readTag(std::string tag);
};



#endif
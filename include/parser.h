#ifndef PARSERH
#define PARSERH

#include <string.h>
#include <map>
#include <vector>
#include <fstream>
#include <string>
#include <memory>

struct tag_object {
  std::string tag_identifier;
  std::unique_ptr<void *> object;
};
std::map<int, std::string> split(std::string str, char comma);
std::map<std::string, std::unique_ptr<void *>> readXML(std::string file_path);
tag_object readTag(std::string tag);



#endif
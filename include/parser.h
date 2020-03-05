#ifndef PARSERH
#define PARSERH

#include <vector>
#include <fstream>

struct tag_object {
  std::string tag_identifier;
  void * attributes;
};
int readXML(std::string file_path);
tag_object readTag(std::string tag);
#endif
#ifndef PARSERH
#define PARSERH

#include <map>
#include <vector>
#include <fstream>
#include <string>
#include "../src/paramset.cpp"

// struct tag_object {
//   std::string tag_identifier;
//   void * attributes;
// };
class parser{
  private:
    std::map<std::string, void *> objects;
    std::string teste;
  public:
    int readXML(std::string file_path) const;
    void readTag(std::string tag) const;
};


#endif
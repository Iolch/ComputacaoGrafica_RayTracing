#ifndef PARSERH
#define PARSERH

#include <map>
#include <vector>
#include <fstream>
#include <string>
#include <memory>
#include "../src/paramset.cpp"

struct tag_object {
  std::string tag_identifier;
  std::unique_ptr<void *> object;
  //void * object;
};
std::map<std::string, std::unique_ptr<void *>> readXML(std::string file_path);
//std::map<std::string, void *> readXML(std::string file_path);
tag_object readTag(std::string tag);

// class parser{
//   private:
//     std::string teste;
//   public:
//     int readXML(std::string file_path) const;
//     tag_object readTag(std::string tag, std::map<std::string, void *> objs);
// };


#endif
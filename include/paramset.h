#ifndef PARAMSETH
#define PARAMSETH

#include <map>
#include <fstream>
#include <string>
#include "../src/film.cpp"

class paramset{
    public:
        void * createObject(std::string tag_identifier, std::map<std::string, std::string> attributes);
};
#endif
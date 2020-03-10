#ifndef BACKGROUNDH
#define BACKGROUNDH

#include <map>
#include <sstream>
#include <fstream>
#include <string>

class background{
    private:    
        std::string type;
        std::string color;
        std::string mapping;
        
    public:
        background(std::map<std::string, std::string> attributes);
        int getType() const;
        int getColor() const;
        std::string getMapping() const;
        
};
#endif
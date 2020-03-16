#ifndef BACKGROUNDH
#define BACKGROUNDH

#include <map>
#include <string>
#include "utils.h"

// struct rgb{
// 	int r;
// 	int g;
// 	int b;
// };
class Background{
    private:    
        std::string type;
        std::string color;
        std::string mapping;
    public:
        Background(std::map<std::string, std::string> attributes);
        rgb sample(float i, float j);
        std::string getType() const;
        std::string getColor() const;
        std::string getMapping() const;
        
};
#endif
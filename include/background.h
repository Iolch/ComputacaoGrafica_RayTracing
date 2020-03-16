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
        std::string color = "";
        std::string mapping;
        std::string bl = "";
        std::string tl = "";
        std::string tr = "";
        std::string br = "";
    public:
        Background(std::map<std::string, std::string> attributes);
        rgb sample(float i, float j);
        std::string getType() const;
        std::string getColor() const;
        std::string getMapping() const;
        std::string getBl() const;
        std::string getBr() const;
        std::string getTl() const;
        std::string getTr() const;
        
};
#endif
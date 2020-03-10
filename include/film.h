#ifndef FILMH
#define FILMH

#include <map>
#include <string>
class film{
    private:    
        int width;
        int height;
        std::string filename;
        std::string img_type;
    public:
        film(std::map<std::string, std::string> attributes);
        int getWidth() const;
        int getHeight() const;
        std::string getFilename() const;
        std::string getImgType() const;
        
};
#endif
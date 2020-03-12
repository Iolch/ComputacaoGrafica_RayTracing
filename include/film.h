#ifndef FILMH
#define FILMH

#include <map>
#include <string>
class Film{
    private:    
        int width;
        int height;
        std::string filename;
        std::string img_type;
    public:
        Film(std::map<std::string, std::string>);
        int getWidth() const;
        int getHeight() const;
        std::string getFilename() const;
        std::string getImgType() const;
        
};
#endif
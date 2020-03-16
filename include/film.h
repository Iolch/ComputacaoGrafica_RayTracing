#ifndef FILMH
#define FILMH

#include <map>
#include <string>
struct rgb{
    int r;
    int g;
    int b;
};
class Film{
    private:    
        int width;
        int height;
        std::string filename;
        std::string img_type;
        std::map<std::pair<int,int>, rgb> points;
    public:
        Film(std::map<std::string, std::string>);
        void addPoint(int i, int j, rgb color);
        int getWidth() const;
        int getHeight() const;
        std::string getFilename() const;
        std::string getImgType() const;
        std::map<std::pair<int,int>, rgb> getPoints() const;

        
};
#endif
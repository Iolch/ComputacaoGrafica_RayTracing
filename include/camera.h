#ifndef CAMERAH
#define CAMERAH

#include <string>
#include <fstream>
#include "../src/film.cpp"
class Camera{
    private:    
        std::string type;
    public:
        Camera(std::map<std::string, std::string>);
        void writeImage(Film * film);
        std::string getType() const;
        
};
#endif
#include "../include/background.h"


Background::Background(std::map<std::string, std::string> attributes){
    type = attributes["type"];
    color = attributes["color"];
    mapping = attributes["mapping"];
}   
std::string Background::getType() const {return type;}
std::string Background::getColor() const {return color;}
std::string Background::getMapping() const {return mapping;}
rgb Background::sample(float i, float j){
	std::map<int, std::string> c = split(getColor(), ' ');
	rgb rgb_color;
	rgb_color.r = int(std::stoi(c[0])*i);
	rgb_color.g = int(std::stoi(c[1])*j);
	rgb_color.g = int(std::stoi(c[2])*0.2);
	return rgb_color;
}


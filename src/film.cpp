#include "../include/film.h"

Film::Film(std::map<std::string, std::string> attributes){
	width = std::stoi(attributes["x_res"]);
	height = std::stoi(attributes["y_res"]);
	filename = attributes["filename"];
}
int Film::getWidth() const {return width;}
int Film::getHeight() const {return height;}
std::string Film::getFilename() const {return filename;}
std::string Film::getImgType() const {return filename;}

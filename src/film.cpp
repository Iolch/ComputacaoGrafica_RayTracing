#include "../include/film.h"

film::film(std::map<std::string, std::string> attributes){
	width = std::stoi(attributes["x_res"]);
	height = std::stoi(attributes["y_res"]);
	filename = attributes["filename"];
}
int film::getWidth() const {return width;}
int film::getHeight() const {return height;}
std::string film::getFilename() const {return filename;}
std::string film::getImgType() const {return filename;}

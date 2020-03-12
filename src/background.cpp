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

// void createFilm(std::map<std::string, std::string> attributes){
	
// 	std::string teste = attributes["filename"];
// 	FilmClass::setFilePath(teste);
// 	std::cout << ">> Creating Film Object" << std::endl;
// 	std::cout << "\t >> Saving at file " << attributes["filename"] << std::endl;

// 	std::ofstream img(attributes["filename"]);

// 	int width = std::stoi(attributes["x_res"]);
// 	int height = std::stoi(attributes["y_res"]);
// 	img << "P3" << std::endl << width << " " << height << std::endl << "255" << std::endl;
	
// 	for(int j =  height-1; j>=0; j--){
// 		for(int i=0; i<width; i++){
// 			vec3 col(float(i)/float(width), float(j)/float(height), 0.2);
			
// 			int ir = int(255.99*col[0]);
// 			int ig = int(255.99*col[1]);
// 			int ib = int(255.99*col[2]);
// 			img << ir << "  " << ig << " " << ib << std::endl;
// 		}
// 	}

// 	std::cout << "\t >> DONE!" << std::endl;

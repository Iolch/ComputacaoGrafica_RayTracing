#include "../include/film.h"

Film::Film(std::map<std::string, std::string> attributes){
	width = std::stoi(attributes["x_res"]);
	height = std::stoi(attributes["y_res"]);
	filename = attributes["filename"];
}
void Film::addPoint(int i, int j, rgb color){
	points[std::make_pair(i,j)] = color;
}
int Film::getWidth() const {return width;}
int Film::getHeight() const {return height;}
std::string Film::getFilename() const {return filename;}
std::string Film::getImgType() const {return filename;}
std::map<std::pair<int,int>, rgb> Film::getPoints() const {return points;}

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
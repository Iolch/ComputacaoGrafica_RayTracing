#include "../include/camera.h"

Camera::Camera(std::map<std::string, std::string> attributes){
	type = attributes["type"];
}
void Camera::writeImage(Film * film){
	std::ofstream img(film->getFilename());

	int width = film->getWidth();
	int height = film->getHeight();

	img << "P3" << std::endl << width << " " << height << std::endl << "255" << std::endl;
	
	std::map<std::pair<int,int>, rgb> elements = film->getPoints();


	for(int j =  height-1; j>=0; j--){
		for(int i=0; i<width; i++){
			rgb color = elements[std::make_pair(i,j)];
			img << color.r << "  " << color.g << " " << color.b << std::endl;
		}
	}	
			
}
std::string Camera::getType() const {return type;}

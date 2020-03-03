#include "../include/file.h"
#include <sstream>
#include <fstream>

std::ofstream createImage(int width, int height, char * filepath){
	std::ofstream img(filepath);
	img << "P3" << std::endl << width << " " << height << std::endl << "255" << std::endl;
	
	return img;
}
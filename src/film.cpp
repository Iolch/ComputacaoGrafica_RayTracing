#include "../include/film.h"
#include <sstream>
#include <fstream>

void createImage(int width, int height, std::string file_path){
	std::ofstream img(file_path);
	img << "P3" << std::endl << width << " " << height << std::endl << "255" << std::endl;
	
	for(int j =  height-1; j>=0; j--){
		for(int i=0; i<width; i++){
			vec3 col(float(i)/float(width), float(j)/float(height), 0.2);
			
			int ir = int(255.99*col[0]);
			int ig = int(255.99*col[1]);
			int ib = int(255.99*col[2]);
			img << ir << "  " << ig << " " << ib << std::endl;
		}
	}
}
#include <iostream>
#include <sstream>     
//#include <fstream>

#include "../include/vec3.h"
#include "file.cpp"

int main(int argc, char** argv){
	int w = 200;
	int h = 100;
	
	char * filepath = argv[1]; 
	std::ofstream img  = createImage(w, h, filepath);
	
	for(int j =  h-1; j>=0; j--){
		for(int i=0; i<w; i++){
			vec3 col(float(i)/float(w), float(j)/float(h), 0.2);
			
			int ir = int(255.99*col[0]);
			int ig = int(255.99*col[1]);
			int ib = int(255.99*col[2]);
			img << ir << "  " << ig << " " << ib << std::endl;
		}
	}
	return 0;
}
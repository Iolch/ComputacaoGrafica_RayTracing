#include <iostream>
#include <sstream>  

#include "../include/vec3.h"
#include "film.cpp"
#include "background.cpp"
#include "parser.cpp"
// #include "paramset.cpp"

int main(int argc, char** argv){
	int w = 200;
	int h = 100;

	char * xmlpath = argv[1];
	if(!xmlpath){ 
		std::cout << "Por favor, informe o caminho de um arquivo xml";
		return -1;
	}
	ParamSet paramSet;
	Parser parser;

	parser.readXML(xmlpath, &paramSet);
	//std::map<std::string, std::unique_ptr<void *>> objects = readXML(xmlpath, &paramSet);
	std::map<std::string, std::map<std::string, std::string>> objects = paramSet.getObjects();
	std::cout << objects["film"]["type"] << std::endl;
	//Film * f = static_cast<Film *>(*objects["film"]);
	//Background * b = static_cast<Background *>(*objects["background"]);

	
	// 	std::cout << ">> Creating Film Object" << std::endl;
	// 	std::cout << "\t >> Saving at file " << f->getFilename() << std::endl;

	// 	std::ofstream img(f->getFilename());

	// 	int width = f->getWidth();
	// 	int height = f->getHeight();
	// 	img << "P3" << std::endl << width << " " << height << std::endl << "255" << std::endl;
		
	// 	for(int j =  height-1; j>=0; j--){
	// 		for(int i=0; i<width; i++){
	// 			rgb c = b->sample(float(i)/float(width), float(j)/float(height));
	// 			img << c.r << "  " << c.g << " " << c.b << std::endl;
	// 		}
	// 	}

	// 	std::cout << "\t >> DONE!" << std::endl;

	return 0;
}
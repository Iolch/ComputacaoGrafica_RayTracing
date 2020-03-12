#include <iostream>
#include <sstream>  

#include "../include/vec3.h"
#include "film.cpp"
#include "background.cpp"
#include "parser.cpp"


int main(int argc, char** argv){
	int w = 200;
	int h = 100;

	char * xmlpath = argv[1];
	if(!xmlpath){ 
		std::cout << "Por favor, informe o caminho de um arquivo xml";
		return -1;
	}
	std::map<std::string, std::unique_ptr<void *>> objects = readXML(xmlpath);
	Film * f = static_cast<Film *>(*objects["film"]);

	
    std::cout << "DENTRO DA MAIN " << f << std::endl; 
	std::cout << f->getWidth() << std::endl;
	
	
	return 0;
}
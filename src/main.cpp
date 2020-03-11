#include <iostream>
#include <sstream>  

#include "../include/vec3.h"
#include "film.cpp"
#include "parser.cpp"

int main(int argc, char** argv){
	int w = 200;
	int h = 100;

	char * xmlpath = argv[1];
	if(!xmlpath){ 
		std::cout << "Por favor, informe o caminho de um arquivo xml";
		return -1;
	}
	if(readXML(xmlpath) == -1){
		std::cout << "Problemas na leitura do arquivo";
		return -1;
	}
	// parser p{};

	// if(p.readXML(xmlpath) == -1){
	// 	std::cout << "Problemas na leitura do arquivo";
	// 	return -1;
	// }

	
	
	return 0;
}
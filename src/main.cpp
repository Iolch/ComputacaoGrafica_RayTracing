#include <iostream>
#include <sstream>  
#include <fstream>

#include "../include/vec3.h"
// #include "film.cpp"
#include "parser.cpp"
#include "camera.cpp"
#include "background.cpp"
//PARAMSET INCLUIDA DENTRO DA PARSER!
//FILM INCLUIDA DENTRO DA CAMERA!

bool keyExists(std::string key, std::map<std::string, std::map<std::string, std::string>> map, bool mute=false){ // alterar pra receber  map<string, void *>
	if(!mute){
		if(map.find(key) == map.end()) std::cout << "Nao foi possivel encontrar o objeto "+ key << std::endl;
	}
	return !(map.find(key) == map.end());
}

int main(int argc, char** argv){
	int w = 200;
	int h = 100;

	char * xmlpath = argv[1];
	if(!xmlpath){ 
		std::cout << "Por favor, informe o caminho de um arquivo xml" << std::endl;
		return -1;
	}
	ParamSet paramSet;
	Parser parser;

	parser.readXML(xmlpath, &paramSet);	//LENDO O ARQUIVO, SALVANDO OS OBJETOS NA paramSet
	std::map<std::string, std::map<std::string, std::string>> objects = paramSet.getObjects();	// ARMAZENANDO OS OBJETOS CRIADOS
	
	//	VERIFICAÇÃO DE OBJETOS	//
	if(!keyExists("film", objects)) return -1;
	if(!keyExists("background", objects)) return -1;
	if(!keyExists("camera", objects)) return -1;

	//	INSTANCIANDO OBJETOS	//
	
	std::cout << ">> Creating Film, Camera and Background Object" << std::endl;
		Film f = {objects["film"]};	// INSTANCIANDO FILM
		Camera c = {objects["camera"]};	//INSTANCIANDO CAMERA
		Background b = {objects["background"]};	//INSTANCIANDO BACKGROUND
	std::cout << "\t >> Saving image at file " << f.getFilename() << std::endl;

		int width = f.getWidth();
		int height = f.getHeight();
		
		for(int j =  height-1; j>=0; j--){
			for(int i=0; i<width; i++){
				rgb color = b.sample(float(i)/float(width), float(j)/float(height));
				f.addPoint(i, j, color);
			}
		}
		c.writeImage(&f);
	std::cout << "\t >> DONE!" << std::endl;

	return 0;
}
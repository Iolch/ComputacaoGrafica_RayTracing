#include "../include/parser.h"

#include <fstream>


int readXML(char * filepath){
	std::ifstream file(filepath);
	if(!file)	return -1;

	std::string line;
    while (getline(file, line)) {
        printf("%s", line.c_str());
    }
    return 0;
}
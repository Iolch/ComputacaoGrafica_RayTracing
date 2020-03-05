#include "../include/parser.h"

int readXML(std::string file_path){
	std::ifstream file(file_path);
	if(!file)	return -1;

	std::string line;
    while (std::getline(file, line)) {
    	printf("%s\n", line.c_str());
        readTag(line.c_str());
    }
    return 0;
}
tag_object readTag(std::string tag){
  	
  	std::string tag_identifier;
  	// std::map<std::string, std::string> attributes;
  	bool found_tag_identifier = false;
  	bool found_tag_ending = false;
  	bool found_attribute_name = false;
  	bool found_attribute_value = false;
  	std::string temporary_attribute_name;
  	std::string temporary_attribute_value;

  	for(char& c : tag) {
  		if(!found_tag_identifier){
  			if(c == ' '){
  				found_tag_identifier = true;
  				std::cout << "tag: " << tag_identifier << std::endl;
  				continue;
  			}
  			if(c != '<' and c != '/' and c != '>'){
  				tag_identifier += c;
  			}
  		}
  		if(found_tag_identifier && !found_tag_ending){
  			
  			if(!found_attribute_name){
  				if(c == '='){
  					found_attribute_name = true;
  					std::cout << "attribute: " << temporary_attribute_name << std::endl;
  					temporary_attribute_name = "";
  					continue;
  				}
  				if(c != ' ' and c != '<' and c != '/' and c != '>'){
  					temporary_attribute_name += c;
  				}
  			}
  			if(found_attribute_name && !found_attribute_value){
  				if(c == ' '){
  					found_attribute_value = true;
  					std::cout << "attribute value: " << temporary_attribute_value << std::endl;
  					temporary_attribute_value = "";

  					continue;
  				}
  				if(c != '"' and c != '<' and c != '/' and c != '>'){
  					temporary_attribute_value += c;
  				}
  			}
  		}
	}
}



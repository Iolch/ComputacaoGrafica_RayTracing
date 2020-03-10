#include "../include/parser.h"


int parser::readXML(std::string file_path) const{
	std::ifstream file(file_path);
	if(!file)	return -1;

	std::string line;
    while (std::getline(file, line)) {
        readTag(line.c_str());
    }
    return 0;
}
void parser::readTag(std::string tag) const{
  	
  	bool found_tag_identifier = false;
  	bool found_attribute_name = false;
  	std::string tag_identifier;
  	std::string temporary_attribute_name;
  	std::string temporary_attribute_value;
  	std::map<std::string, std::string> attributes;

  	for(char& c : tag) {
		if(!found_tag_identifier){
  			if((c == ' ' || c == '>') && (tag_identifier != "")){
  				found_tag_identifier = true;				  
  			}else if(c != '<' and c != '/' and c != ' '){
  				tag_identifier += c; 
  			}
  		}else{
  			if(!found_attribute_name){
  				if(c == '='){
  					found_attribute_name = true;
  				}else if(c != ' ' and c != '<' and c != '/' and c != '>'){
  					temporary_attribute_name += c;
  				}
  			}
  			if(found_attribute_name){
  				if(c == ' ' || c == '>'){
					attributes[temporary_attribute_name] = temporary_attribute_value;
  					temporary_attribute_name = "";
  					temporary_attribute_value = "";
					found_attribute_name = false;
  				}else if(c != '"' and c != '<' and c != '>' and c != '='){
  					temporary_attribute_value += c;
  				}
  			}
  		}

		if(c == '>'){
			//AQUI CHAMAMOS A FUNÇÃO CREATE OBJECT passando tag_identifier e attributes
			void * object = createObject(tag_identifier, attributes);
			//addObject(tag_identifier, object);
			tag_identifier = "";
			attributes.clear();
			found_tag_identifier = false;
		}
	}
}



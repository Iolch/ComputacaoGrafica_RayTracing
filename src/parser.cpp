#include "../include/parser.h"


int readXML(std::string file_path){
	std::ifstream file(file_path);
	if(!file)	return -1;

  std::map<std::string, void *> objects;
  std::string line;
  while (std::getline(file, line)) {
      tag_object tag = readTag(line.c_str());
      objects[tag.tag_identifier] = tag.object;
  }
  std::cout << static_cast<film *>(objects["film"])->getWidth();
  return 0;
}
tag_object readTag(std::string tag){
  	
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
      
      // tag_object tag = {tag_identifier, createObject(tag_identifier, attributes)};
      std::cout<< "bbb"  << createObject(tag_identifier, attributes) << std::endl;
      void * obj;
			tag_object tag = {tag_identifier, obj};
      tag_identifier = "";
			attributes.clear();
			found_tag_identifier = false;
      return tag;
		}
	}
}



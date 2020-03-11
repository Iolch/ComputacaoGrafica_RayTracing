#include "../include/parser.h"


std::map<std::string, std::unique_ptr<void *>> readXML(std::string file_path){
	std::ifstream file(file_path);
  //if(!file) return;
	std::map<std::string, std::unique_ptr<void *>> objects;
  std::string line;
  while (std::getline(file, line)) {
      tag_object tag = readTag(line.c_str());
      objects[tag.tag_identifier] = std::move(tag.object);
  }
  return objects;
}
tag_object readTag(std::string tag){
  	
  	bool found_tag_identifier = false;
  	bool found_attribute_name = false;
  	std::string tag_identifier;
  	std::string temporary_attribute_name;
  	std::string temporary_attribute_value;
  	std::map<std::string, std::string> attributes;
    
    tag_object tag_obj;

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
      
      tag_obj.tag_identifier = tag_identifier;  //SALVAMOS A KEY COMO A TAGNAME
      tag_obj.object = std::move(createObject(tag_identifier, attributes)); //RECEBE OBJETO E ARMAZENA EM TAG.OBJECT
      std::cout << "DENTRO DA READTAG " << *tag_obj.object << std::endl; 
      std::cout << (static_cast<film *>(*tag_obj.object))->getWidth() <<std::endl;  //O OBJETO TÁ BUGANDO A FUNCAO, MAS A REFERENCIA ESTA CORRETA
      

      tag_identifier = "";	
      attributes.clear();
			found_tag_identifier = false;
		}
	}
  return tag_obj; 
}



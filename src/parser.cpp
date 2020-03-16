#include "../include/parser.h"

void Parser::readXML(std::string file_path, ParamSet * paramSet){
	std::ifstream file(file_path);
  //if(!file) return;
  std::string line;
  while (std::getline(file, line)) {
      tag_object tag = readTag(line.c_str());
      paramSet->addObject(tag.tag_identifier, tag.attributes); 
  }
}
tag_object Parser::readTag(std::string tag){

    std::map<int, std::string> elements = split(tag, ' ');
    
    std::string tag_identifier = elements[0];
    std::map<std::string, std::string> attributes;

    std::map<int, std::string>::iterator it;
    for ( it = elements.begin(); it != elements.end(); it++ )
    {
        if(it->first == 0) continue;
        std::map<int, std::string> attr = split(it->second, '=');
        if(attr[0] != "" && attr[1] != ""){ //CASO O ATRIBUTO TENHA UM NOME E UM VALOR
          attributes[attr[0]] = attr[1];
        }
    }

    tag_object tag_obj;
    tag_obj.tag_identifier = tag_identifier;  //SALVAMOS A KEY COMO A TAGNAME
    tag_obj.attributes = attributes;
    return tag_obj;
}



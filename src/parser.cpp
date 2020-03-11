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
std::map<int, std::string> split(std::string str, char comma){
  int index = 0;
  std::map<int, std::string> words;
  std::string temporary;

  for ( std::string::iterator it=str.begin(); it<=str.end(); ++it){
    
    if(*it == comma || it == str.end()){
      words[index] = temporary;
      temporary = "";
      index += 1;
    }else{
      if(*it != '<' and *it != '>' and *it != '"' and *it != ' ') temporary += *it;
      else continue;
    }
  } 
  return words;
}
tag_object readTag(std::string tag){

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
    tag_obj.object = std::move(createObject(tag_identifier, attributes)); //RECEBE OBJETO E ARMAZENA EM TAG.OBJECT
    
    std::cout << "DENTRO DA READTAG " << *tag_obj.object << std::endl; 
    std::cout << (static_cast<film *>(*tag_obj.object))->getWidth() <<std::endl;  //O OBJETO TÁ BUGANDO A FUNCAO, MAS A REFERENCIA ESTA CORRETA
      
    return tag_obj;
}



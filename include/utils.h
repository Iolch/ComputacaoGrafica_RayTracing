#ifndef UTILSH
#define UTILSH

#include <string.h>
#include <map>
#include <string>

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
      if(*it != '<' and *it != '>' and *it != '"') temporary += *it;
      else continue;
    }
  } 
  return words;
}

#endif
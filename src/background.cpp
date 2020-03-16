#include "../include/background.h"

bool keyExists(std::string key, std::map<std::string, std::string> map, bool mute=false){ // alterar pra receber  map<string, void *>
	if(!mute){
		if(map.find(key) == map.end()) std::cout << "Nao foi possivel encontrar o objeto "+ key << std::endl;
	}
	return !(map.find(key) == map.end());
}
int interpolate (int value_a, int value_b, int value_c, int value_d, float i, float j){
	int r1 = int(value_a + i*value_b - value_a);
	int r2 = int(value_c + i*value_d - value_c);	
	return int( r2 + j * (r1 - r2));
}
Background::Background(std::map<std::string, std::string> attributes){
    type = attributes["type"];
    color = attributes["color"];
    mapping = attributes["mapping"];
    if(keyExists("br", attributes, true)) br = attributes["br"];
	if(keyExists("bl", attributes, true)) bl = attributes["bl"];
    if(keyExists("tr", attributes, true)) tr = attributes["tr"];
    if(keyExists("tl", attributes, true)) tl = attributes["tl"];


}   
std::string Background::getType() const {return type;}
std::string Background::getColor() const {return color;}
std::string Background::getMapping() const {return mapping;}
std::string Background::getBl() const {return bl;}
std::string Background::getBr() const {return br;}
std::string Background::getTl() const {return tl;}
std::string Background::getTr() const {return tr;}

rgb Background::sample(float i, float j){
	rgb rgb_color;
	if(color != ""){
		std::map<int, std::string> c = split(getColor(), ' ');
		rgb_color.r = int(std::stoi(c[0]));
		rgb_color.g = int(std::stoi(c[1]));
		rgb_color.g = int(std::stoi(c[2]));
	}else if((bl != "") and (br != "") and (tl != "") and (tr != "")){	//Interpolaremos
		std::map<int, std::string> mbl = split(getBl(), ' ');
		std::map<int, std::string> mbr = split(getBr(), ' ');
		std::map<int, std::string> mtl = split(getTl(), ' ');
		std::map<int, std::string> mtr = split(getTr(), ' ');

		rgb_color.r = interpolate(std::stoi(mbl[0]), std::stoi(mbr[0]), std::stoi(mtl[0]), std::stoi(mtr[0]), i, j);
		rgb_color.g = int(std::stoi(mtr[0])*j - std::stoi(mtl[0]) * i);
		rgb_color.b = std::stoi(mbl[2]);
		// rgb_color.g = interpolate(std::stoi(mbl[1]), std::stoi(mbr[1]), std::stoi(mtl[1]), std::stoi(mtr[1]), i, j);
		// rgb_color.b = interpolate(std::stoi(mbl[2]), std::stoi(mbr[2]), std::stoi(mtl[2]), std::stoi(mtr[2]), i, j);

	}else{	//COR PADRÃO
		rgb_color.r = 255;
		rgb_color.g = 192;
		rgb_color.g = 203;
	}
	return rgb_color;
}


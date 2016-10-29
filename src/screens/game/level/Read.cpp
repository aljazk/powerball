#include "Read.hpp"

Read::Read(){
	theString = "";
}

Read::Read(const std::string &newString){
	setString(newString);
}

void Read::setString(const std::string &newString){
	theString = newString;
}

std::string Read::getString(){
	return theString;
}

std::vector<std::string> Read::getWords(){
	std::vector<std::string> ret;
	bool newWord = true;
	for(unsigned int i=0; i<theString.size(); i++){
		if((theString[i] >= 'a' && theString[i] <= 'z') || (theString[i] >= 'A' && theString[i] <= 'Z')){
			if(newWord){
				ret.push_back("");
				ret[ret.size()-1] = theString[i];
			} else {
				ret[ret.size()-1] += theString[i];
			}
			newWord = false;
		} else {
			newWord = true;
		}
	}
	return ret;
}

std::vector<std::string> Read::getWords(const std::string &conString){
	std::vector<std::string> ret;
	bool newWord = true;
	for(unsigned int i=0; i<conString.size(); i++){
		if((conString[i] >= 'a' && conString[i] <= 'z') || (conString[i] >= 'A' && conString[i] <= 'Z')){
			if(newWord){
				ret.push_back("");
				ret[ret.size()-1] = conString[i];
			} else {
				ret[ret.size()-1] += conString[i];
			}
			newWord = false;
		} else {
			newWord = true;
		}
	}
	return ret;
}

int Read::toInt(const std::string &conString){
	int ret = 0;
	int sign = 1;
	int start = 0;
	if (conString[0] == '-'){
		start = 1;
		sign = -1;
	} 
	for(unsigned int i=start; i<conString.size(); i++){
		if(conString[i] == '.')
			return ret * sign;
		
		ret *= 10;
		ret += conString[i]-'0';
	}
	return ret * sign;
}

float Read::toFloat(const std::string &conString){
	float ret = 0;
	bool dec = false;
	unsigned int decCount = 0;
	int sign = 1;
	int start = 0;
	if (conString[0] == '-'){
		start = 1;
		sign = -1;
	} 
	for(unsigned int i=start; i<conString.size(); i++){
		if(conString[i] == '.'){
			dec = true;
		} else {
			ret *= 10;
			ret += conString[i]-'0';
			if (dec) decCount++;
		}
	}
	if (dec){
		for(unsigned int i=0; i<decCount; i++){
			ret /= 10;
		}
	}
	return ret * sign;
}

std::string Read::fromInt(int num){
	std::string num_string;
	while (num >= 10){
		int addnum = num % 10;
		num_string += addnum + 48;
		num /= 10;
	}
	num_string += num + 48;
	std::string return_string;
	for(unsigned int i=num_string.size()-1; i>0; i--){
		return_string.push_back(num_string[i]);
	}
	return_string.push_back(num_string[0]);
	return return_string;
}

std::vector<std::string> Read::getNumbers(){
	std::vector<std::string> ret;
	bool newNumber = true;
	for(unsigned int i=0; i<theString.size(); i++){
		if((theString[i] >= '0' && theString[i] <= '9') || (theString[i] == '.' && !newNumber)){
			if(newNumber){
				ret.push_back("");
				ret[ret.size()-1] = theString[i];
			} else {
				ret[ret.size()-1] += theString[i];
			}
			newNumber = false;
		} else {
			if (theString[i] == '-'){
				ret.push_back("");
				ret[ret.size()-1] = theString[i];
				newNumber = false;
			} else {
				newNumber = true;
			}
		}
	}
	return ret;
}

std::vector<std::string> Read::getNumbers(const std::string &conString){
	std::vector<std::string> ret;
	bool newNumber = true;
	for(unsigned int i=0; i<conString.size(); i++){
		if((conString[i] >= '0' && conString[i] <= '9') || (conString[i] == '.' && !newNumber)){
			if(newNumber){
				ret.push_back("");
				ret[ret.size()-1] = conString[i];
			} else {
				ret[ret.size()-1] += conString[i];
			}
			newNumber = false;
		} else {
			if (conString[i] == '-'){
				ret.push_back("");
				ret[ret.size()-1] = conString[i];
				newNumber = false;
			} else {
				newNumber = true;
			}
		}
	}
	return ret;
}

std::vector<int> Read::getNumbersi(){
	std::vector<std::string> str = getNumbers();
	std::vector<int> ret;
	for(unsigned int i=0; i<str.size(); i++){
		ret.push_back(0);
		ret[i] = toInt(str[i]);
	}
	return ret;
}

std::vector<int> Read::getNumbersi(const std::string &conString){
	std::vector<std::string> str = getNumbers(conString);
	std::vector<int> ret;
	for(unsigned int i=0; i<str.size(); i++){
		ret.push_back(0);
		ret[i] = toInt(str[i]);
	}
	return ret;
}

std::vector<float> Read::getNumbersf(){
	std::vector<std::string> str = getNumbers();
	std::vector<float> ret;
	for(unsigned int i=0; i<str.size(); i++){
		ret.push_back(0);
		ret[i] = toFloat(str[i]);
	}
	return ret;
}

std::vector<float> Read::getNumbersf(const std::string &conString){
	std::vector<std::string> str = getNumbers(conString);
	std::vector<float> ret;
	for(unsigned int i=0; i<str.size(); i++){
		ret.push_back(0);
		ret[i] = toFloat(str[i]);
	}
	return ret;
}
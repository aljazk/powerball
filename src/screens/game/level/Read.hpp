#ifndef READ
#define READ

#include <string>
#include <vector>
#include <iostream>

class Read{
		std::string theString;
	public:
		Read();
		Read(const std::string &);
		void setString(const std::string &);
		std::string getString();
		
		//returns array of all words made of a-z || A-Z "Hello, My name is Bob." returns as [Hello] [My] [name] [is] [Bob]
		std::vector<std::string> getWords();
		static std::vector<std::string> getWords(const std::string &);
		
		//converting functions
		static int toInt(const std::string &);
		static float toFloat(const std::string &);
		static std::string fromInt(int);
		
		//returns array of all numbers in the string
		//as strings (returns decimals)
		std::vector<std::string> getNumbers();
		static std::vector<std::string> getNumbers(const std::string &);
		//as int (doesnt return decimals)
		std::vector<int> getNumbersi();
		static std::vector<int> getNumbersi(const std::string &);
		//as float (returns decimals)
		std::vector<float> getNumbersf();
		static std::vector<float> getNumbersf(const std::string &);
};

#endif
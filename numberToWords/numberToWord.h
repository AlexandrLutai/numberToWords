#ifndef NUMBERTOWORD
#define NUMBERTOWORD
#include<string>
//10 в степени 
enum orderOfDigits
{
	orderHundreds, orderTens, orderUnits, rankOrValute
};

namespace constants {
	extern const std::string valutes[1][10];
	extern const std::string ranks[][10];
	extern const std::string tensInWords[];
	extern const std::string hundredsInWords[];
	extern const std::string thousandExeption[];
	extern const std::string tensExeption[];
	extern const std::string unitsInWords[];
	extern const std::string* digitsInWordsArray[3];
}



std::string getNumberAsWords(unsigned long number);
#endif // !NUMBERTOWORD

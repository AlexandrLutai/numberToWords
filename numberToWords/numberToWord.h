#ifndef NUMBERTOWORD
#define NUMBERTOWORD
#include<string>
namespace constants {
	const std::string units[10][3]{
		{"","",""},
		{"Один", "Десять","Сто"},
		{"Два", "Двадцать", "Двести"},
		{"Три", "Тридцать", "Триста"},
		{"Четыре", "Сорок", "Четыреста"},
		{"Пять","Пятьдесят","Пятьсот"},
		{"Шесть", "Шестьдесят", "Шестьсот"},
		{"Семь", "Семьдесят", "Семьсот"},
		{"Восемь", "Восемьдесят", "Восемьсот"},
		{"Девять", "Девяносто", "Девятьсот"}
	};
	
	const std::string ranks[4]{"Тысяч", "Миллион", "Миллиард"};
}
std::string changeEnding(std::string stringBeingChenged, std::string ending);
std::string getRubles(short lastDigit, bool execution);
std::string getThousand(short lastDigit, bool execution);
std::string dozensExecution(int lastNumber, int numberDigit);
std::string getUnitsAsWord(int& fullNumber, int& numberDigit, int& fullNumberDigit);
#endif // !NUMBERTOWORD

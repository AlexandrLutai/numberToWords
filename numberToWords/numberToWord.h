#ifndef NUMBERTOWORD
#define NUMBERTOWORD
#include<string>
namespace constants {
	const std::string units[10]{ "Ноль","Один", "Два", "Три", "Четыре", "Пять", "Шесть", "Семь", "Восемь", "Девять"};
	const std::string ranks[4]{"Сто", "Тысяча", "Миллион", "Миллиард" };
}
std::string changeEnding(std::string stringBeingChenged, std::string ending);
std::string getRubles(short lastDigit, bool execution);
std::string dozensExecution(int lastNumber, int& numberDigit);
std::string getUnitsAsWord(int fullNumber, int& numberDigit);
#endif // !NUMBERTOWORD

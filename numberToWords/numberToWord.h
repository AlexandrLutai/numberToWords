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
	
	const std::string ranks[5]{"Тысяч", "Миллион", "Миллиард", "Триллион"};
}

std::string getNumberAsWords(unsigned long long number);
#endif // !NUMBERTOWORD

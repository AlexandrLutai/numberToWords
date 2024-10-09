#ifndef NUMBERTOWORD
#define NUMBERTOWORD
#include<string>
namespace constants {
	const std::string units[9]{ "Один", "Два", "Три", "Четыре", "Пять", "Шесть", "Семь", "Восемь", "Девять" };
	const std::string ranks[5]{ "Десять", "Сто", "Тысяча", "Миллион", "Миллиард" };
}
std::string changeEnding(std::string stringBeingChenged, std::string ending);

#endif // !NUMBERTOWORD

#ifndef NUMBERTOWORD
#define NUMBERTOWORD
#include<string>
namespace constants {
	const std::string units[9]{ "����", "���", "���", "������", "����", "�����", "����", "������", "������" };
	const std::string ranks[5]{ "������", "���", "������", "�������", "��������" };
}
std::string changeEnding(std::string stringBeingChenged, std::string ending);

#endif // !NUMBERTOWORD

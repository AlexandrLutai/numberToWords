#ifndef NUMBERTOWORD
#define NUMBERTOWORD
#include<string>
namespace constants {
	const std::string units[10][3]{
		{"","",""},
		{"����", "������","���"},
		{"���", "��������", "������"},
		{"���", "��������", "������"},
		{"������", "�����", "���������"},
		{"����","���������","�������"},
		{"�����", "����������", "��������"},
		{"����", "���������", "�������"},
		{"������", "�����������", "���������"},
		{"������", "���������", "���������"}
	};
	
	const std::string ranks[4]{"�����", "�������", "��������"};
}
std::string changeEnding(std::string stringBeingChenged, std::string ending);
std::string getRubles(short lastDigit, bool execution);
std::string getThousand(short lastDigit, bool execution);
std::string dozensExecution(int lastNumber, int numberDigit);
std::string getUnitsAsWord(int& fullNumber, int& numberDigit, int& fullNumberDigit);
#endif // !NUMBERTOWORD

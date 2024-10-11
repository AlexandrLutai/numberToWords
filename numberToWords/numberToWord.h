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
	
	const std::string ranks[5]{"�����", "�������", "��������", "��������"};
}

std::string getNumberAsWords(unsigned long long number);
#endif // !NUMBERTOWORD

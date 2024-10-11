#include"numberToWord.h"
#include<iostream>


// !!������ �� ������������� 
//�������� ��������� ���������� ������ - stringBeingChenged.
//ending - ���������, �� ������� ����� ���������� ��������.
std::string changeEnding(std::string stringBeingChenged, std::string ending) {
	
		short endChangedString = stringBeingChenged.size() - 1;
		short endEndingString = ending.size() - 1 ;
		short iteration{ 0 };

		do
		{
			stringBeingChenged[endChangedString--] = ending[endEndingString--];
			iteration++;
		} while (iteration <= endEndingString);
	
	return stringBeingChenged;
}

std::string getRubles(short lastDigit, bool execution) {
	if (lastDigit == 0 ||  lastDigit >= 5 || execution) {
		return " ������.";
	}
	else if (lastDigit == 1) {
		return " �����.";
	}
	else {
		return " �����.";
	}
};

std::string dozensExecution(int lastNumber, int& numberDigit) 
{
	++numberDigit;
	if (lastNumber == 0) return " ������";
	std::string numberAsWord{ constants::units[lastNumber][0] };
	if (lastNumber == 2) {
		numberAsWord = changeEnding(numberAsWord, "�");
	}
	else if (lastNumber >= 4 && lastNumber <= 9) {
		numberAsWord.erase(numberAsWord.end() - 1 );
	}
	return " " + numberAsWord + "������� ";
}

std::string getUnitsAsWord(int fullNumber,int& numberDigit) {
	int lastDigit{fullNumber % 10};
	std::string numberAsWord{};
	bool execution{ false };
	if ((fullNumber / 10) % 10 == 1)
	{
		numberAsWord =  dozensExecution(lastDigit, numberDigit);
		execution = true;
		++numberDigit;
	
	}
	else {
		numberAsWord = numberAsWord + " " + constants::units[lastDigit][numberDigit];
	}
	++numberDigit;
	return numberAsWord;
}


#include"numberToWord.h"
#include<iostream>


// !!ВОПРОС ПО ЭФФЕКТИВНОСТИ 
//Изменяет окончание переданной строки - stringBeingChenged.
//ending - окончание, на которое будет заменяться исходное.
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

std::string printRubles(short lastDigit, bool execution = false) {
	if (lastDigit >= 5 || execution) {
		return " Рублей.";
	}
	else if (lastDigit == 1) {
		return " Рубль.";
	}
	else {
		return " Рубля.";
	}
};

void printUnitsAsWord(int fullNumber, int& numberDigit) {

}


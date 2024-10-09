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

std::string dozensExecution(int lastNumber) {
	if (lastNumber == 0) return "Десять";
	std::string numberAsWord{ constants::units[lastNumber - 1] };
	if (lastNumber == 2) {
		numberAsWord = changeEnding(numberAsWord, "е");
	}
	else if (lastNumber >= 4 && lastNumber <= 9) {
		numberAsWord.erase(numberAsWord.end());
	}
	return numberAsWord + "надцать";
}

std::string printUnitsAsWord(int fullNumber, int& numberDigit) {

}


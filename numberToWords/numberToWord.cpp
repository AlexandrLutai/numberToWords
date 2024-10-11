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


std::string getRubles(short lastDigit, bool execution) {
	if (lastDigit == 0 ||  lastDigit >= 5 || execution) {
		return " Рублей.";
	}
	else if (lastDigit == 1) {
		return " Рубль.";
	}
	else {
		return " Рубля.";
	}
};

std::string getThousand(short lastDigit, bool execution) {
	std::string thousand{ constants::ranks[0] };
	if (lastDigit == 0 || lastDigit >= 5 || execution) {
		return " " + thousand;
	}
	else if (lastDigit == 1) {
		return " "+thousand + "а";
	}
	else {
		return  " " + thousand + "и";
	}
}

std::string getWordDigit(short fullNumberDigit,short lastDigit, bool exeption) {
	switch (fullNumberDigit)
	{
	case 0:
		return getRubles(lastDigit, exeption);
		break;
	case 1:
		return getThousand(lastDigit, exeption);
		break;
	default:
		break;
	}
}

std::string dozensExecution(int lastNumber, int numberDigit) 
{
	++numberDigit;
	if (lastNumber == 0) return " Десять";
	std::string numberAsWord{ constants::units[lastNumber][0] };
	if (lastNumber == 2) {
		numberAsWord = changeEnding(numberAsWord, "е");
	}
	else if (lastNumber >= 4 && lastNumber <= 9) {
		numberAsWord.erase(numberAsWord.end() - 1 );
	}
	return " " + numberAsWord + "надцать ";
}

std::string getUnitsAsWord(int fullNumber,int& numberDigit, int& fullNumberDigit) {
	int lastDigit{fullNumber % 10};
	std::string numberAsWord{};
	bool exeption{ (fullNumber / 10) % 10 == 1 && numberDigit == 0 };
	if (fullNumberDigit % 3 == 0) {
		numberAsWord = getWordDigit(fullNumberDigit / 3, lastDigit, exeption);
	}
	if (exeption)
	{
		numberAsWord =  dozensExecution(lastDigit, numberDigit) + " " + numberAsWord;
		++numberDigit;
	}
	else {
		numberAsWord =  constants::units[lastDigit][numberDigit] + " " + numberAsWord;
	}
	++fullNumberDigit;
	++numberDigit;
	return numberAsWord;
}


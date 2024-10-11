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

//Получение слова рублей.
//lastDigit - число, от которого зависит вид слова "Рубль".
//exeption - Исключение от 10 до 19
std::string getRubles(short lastDigit, bool exeption) {
	if (lastDigit == 0 ||  lastDigit >= 5 || exeption) {
		return " Рублей.";
	}
	else if (lastDigit == 1) {
		return " Рубль.";
	}
	else {
		return " Рубля.";
	}
};

std::string thousandExeption(short lastDigit,int numberDigit, int fullNumberDigit) {
	if (fullNumberDigit == 3) {
		switch (lastDigit)
		{
		case 1:
			return "Одна";
		case 2:
			return "Две";
		
		}
	}
	return constants::units[lastDigit][numberDigit];
}

std::string getThousand(short lastDigit, bool exeption) {
	std::string thousand{ constants::ranks[0] };
	if (lastDigit == 0 || lastDigit >= 5 || exeption) {
		return " " + thousand;
	}
	else if (lastDigit == 1) {
		return " " +thousand + "а";
	}
	else {
		return  " " + thousand + "и";
	}
}

std::string getAnyRanks(short fullNumberDigit, short lastDigit, bool exeption) {
	std::string word{constants::ranks[fullNumberDigit -1]};
	if (lastDigit == 0 || lastDigit >= 5 || exeption) {
		return " " + word + "ов";
	}
	else if (lastDigit == 1) {
		return " " + word;
		
	}
	else {
		return " " + word + "а";
	}
}

std::string getWordDigit(short fullNumberDigit,short lastDigit, bool exeption) {
	fullNumberDigit /= 3;
	switch (fullNumberDigit)
	{
	case 0:
		return getRubles(lastDigit, exeption);
		break;
	case 1:
		return getThousand(lastDigit, exeption);
		break;
	default:
		return getAnyRanks(fullNumberDigit,lastDigit, exeption);
		break;
	}
}

std::string dozensExeption(int lastNumber, int numberDigit)
{
	++numberDigit;
	if (lastNumber == 0) return "Десять";
	std::string numberAsWord{ constants::units[lastNumber][0] };
	if (lastNumber == 2) {
		numberAsWord = changeEnding(numberAsWord, "е");
	}
	else if (lastNumber >= 4 && lastNumber <= 9) {
		numberAsWord.erase(numberAsWord.end() - 1 );
	}
	return numberAsWord + "надцать";
}

void changeParams(unsigned long long& fullNumber, int& numberDigit, int& fullNumberDigit) {
	++numberDigit;
	++fullNumberDigit;
	fullNumber /= 10;
}

std::string getUnitsAsWord(unsigned long long& fullNumber,int& numberDigit, int& fullNumberDigit) {
	int lastDigit{fullNumber % 10};
	std::string numberAsWord{};
	bool exeption{ (fullNumber / 10) % 10 == 1 && numberDigit == 0 };
	
	if (fullNumberDigit % 3 == 0) {
		numberAsWord = getWordDigit(fullNumberDigit, lastDigit, exeption);
	}
	if (exeption)
	{
		numberAsWord =  dozensExeption(lastDigit, numberDigit) +  numberAsWord;
		changeParams(fullNumber, numberDigit, fullNumberDigit);
	}
	else {
		numberAsWord = thousandExeption(lastDigit,numberDigit,fullNumberDigit) +  numberAsWord;
	}


	changeParams(fullNumber, numberDigit, fullNumberDigit);
	if (numberDigit >= 3) numberDigit = 0;
	return numberAsWord + " ";
}


std::string getNumberAsWords(unsigned long long number) {
	int digit{ 0 };
	int fullDigit{ 0 };
	std::string word{ "" };
	do
	{
		word = getUnitsAsWord(number, digit, fullDigit) + word;
		
	} while (number > 0);

	return word;
}

//Доработать окончание числительных двЕ-одна тысячи
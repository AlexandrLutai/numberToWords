#include"numberToWord.h"
#include<iostream>



void getDigitsInArray(unsigned long , unsigned short*, int );
void changeParams(unsigned long* number, unsigned short* numberOfDigit = nullptr);
std::string getNumberName(unsigned short, unsigned short , unsigned short , unsigned short );
std::string getNumberNameWithValutes(unsigned short, unsigned short, unsigned short);




//Выводит число словом для разряда тысяч.
//Обробатывается два исключения, для 1 и 2
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

//Получение названий чисел
std::string getHundredName(unsigned short hundred)
{
	return constants::hundredsNames[hundred];
}
std::string getTenName(unsigned short ten, bool tenExeption)
{
	std::string tenName{ "" };
	if (!tenExeption) 
	{
		tenName = constants::tensNames[ten];
	}
	return tenName;
}
std::string getUnitName(unsigned short unit, bool tenExeption, short digitRank = -1)
{
	//Инвертируется значения исключения
	//В переменной isExeption хранится 0, если обрабатывается исключение десятков, в другом случае - 1
	unsigned short isExeption{ !tenExeption };
	//Обрабатывается исключение для тысяч, 0 - разряд тысяч, так как разряд с валютой обрабатывается отдельно.
	if (digitRank == 0) 
	{
		//Если обрабатывается исключение для десятков, то в переменной isExeption хранится 0, 
		//результатом данного выражения будет 0, что является индексом вложенного массива с исключением для десятков
		//в массиве unitsName.
		//если обрабатывается число, без исключения для десятков, то результатом данног выражения будет
		//индекс вложенного массива, хрпанящего исключения для тысяч


		isExeption *= constants::thousandExeptionIndex;
	}
	return constants::unitsNames[isExeption][unit];
}
std::string getRankName(unsigned short unit, bool tenExeption, unsigned short digitRank) 
{
	return constants::ranksNames[digitRank][!tenExeption * unit];
}



std::string getNumberName(unsigned short unit,  unsigned short ten, unsigned short hundred, unsigned short digitRank)
{

	int summAllDigits{ hundred + ten + unit };
	
	if (summAllDigits)
	{
		bool tensExeption{ ten == 1 };
		return getHundredName(hundred) + getTenName(ten, tensExeption) 
			+ getUnitName(unit, tensExeption, digitRank) + getRankName(unit, tensExeption, digitRank);
	}
	return "";
}


std::string getValuteName(unsigned short unit, bool tenExeption)
{
	//Если обрабатывается исключение по десяткам, то инвертированная переменная tenExeption будет возвращать 0,
	//и результатом данного выражения всегда будет первая запись в массиве, которая хранит склонение слова для десяти.
	//В ином случае результатом будет индекс для склонения числа, хранящегося в unit
	return constants::valutes[!tenExeption * unit];
}
std::string getNumberNameWithValutes(unsigned short unit, unsigned short ten, unsigned short hundred)
{
	int summAllDigits{ hundred + ten + unit };

	
		bool tensExeption{ ten == 1 };
		return getHundredName(hundred) + getTenName(ten, tensExeption)
			+ getUnitName(unit, tensExeption) + getValuteName(unit, tensExeption);
	
}





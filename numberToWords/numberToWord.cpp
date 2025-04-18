#include"numberToWord.h"
#include<iostream>

namespace constants {
	std::string valutes[1][10] 
	{
		{"Рублей.", "Рубль.","Рубля.", "Рубля.", "Рубля.", "Рублей.", "Рублей.","Рублей.","Рублей.", "Рублей."}

	};

	std::string ranks[4][10]
	{
		{"","","","","","","","","",""},
		{"Тысяч ","Тысяча ","Тысячи ","Тысячи ","Тысячи ", "Тысяч ","Тысяч ","Тысяч ","Тысяч ","Тысяч "},
		{"Миллионов ", "Миллион ", "Миллиона ","Миллиона ","Миллиона ","Миллионов ","Миллионов ","Миллионов ","Миллионов ","Миллионов "},
		{"Миллиардов ", "Миллиард ", "Миллиарда ","Миллиарда ","Миллиарда ","Миллиардов ","Миллиардов ","Миллиардов ","Миллиардов ","Миллиардов "}
	};

	std::string tensInWords[]
	{
		"","Десять ", "Двадцать ", "Тридцать ", "Сорок ", "Пятьдесят ", "Шестьдесят ", "Семьдесят ", "Восемьдесят ","Девяносто "
	};

	std::string hundredsInWords[]
	{
		"","Сто ", "Двести ","Триста ","Четыреста ","Пятьсот ","Шестьсот ","Семьсот ","Восемьсот ","Девятьсот "
	};

	std::string thousandExeption[]
	{
		"","Одна ", "Две ", "Три ", "Четыре ", "Пять ", "Шесть ", "Семь ", "Восемь ", "Девять "
	};

	std::string tensExeptionsNames[]
	{
		"Десять ", "Одиннадцать ", "Двенадцать ", "Тринадцать ", "Четырнадцать ", "Пятнадцать ", "Шестнадцать ","Семнадцать ","Восемнадцать ", "Девятнадцать "
	};
	
	
	std::string unitsInWords[]
	{
		"","Один ", "Два ", "Три ", "Четыре ", "Пять ", "Шесть ", "Семь ", "Восемь ", "Девять "
	};
	
	std::string* digitsInWordsArrays[4][3]
	{
		{unitsInWords, tensInWords,  hundredsInWords}, 
		{thousandExeption , tensInWords,hundredsInWords }, 
		{unitsInWords, tensInWords,  hundredsInWords},
		{unitsInWords, tensInWords,  hundredsInWords}

	};

	//const std::string* digitsInWordsMap[]{ digitsInWordsArrays,tensExeptionsNames, };


	

}

std::string getTripletName(int triplet, int rank);
std::string getRankName(unsigned short triplet, unsigned short rank);
int parceRightTriplet(unsigned long number);
std::string getValuteName(unsigned  long number);
int pow(int base, int power);


std::string getNumberAsWords(unsigned  long number)
{
	if (!number) return "Ноль Рублей.";
	
	std::string numberInWords{getValuteName(number)}; 
	int rank{ 0 };
	
	
	while (number > 0)
	{
		int triplet = parceRightTriplet(number);
		numberInWords = getTripletName(triplet, rank) + getRankName(triplet,rank) + numberInWords;
		
		number /= pow(10, 3);
		rank++;
	}

	return numberInWords;
}





std::string getTripletName(int triplet, int rank)
{
	
	if (triplet == 0) return "";

	std::string tripletName{};
	//bool tenExeption{ (triplet / 10) % 10 == 1};
	
	for (int position = 2; position >= 0; position--)
	{
		short digit{ static_cast<short>((triplet / pow(10,position)) % 10) };
		std::string* numberNameArrPtr{ constants::digitsInWordsArrays[rank][position] };
		if (position == 1)
		{
			
			if (digit == 1) 
			{
				digit = static_cast<short>((triplet / pow(10,0)) % 10);
				numberNameArrPtr = constants::tensExeptionsNames;
				
				break;
			}
		}
		tripletName += *(numberNameArrPtr + digit);
	}
	

	return tripletName;
}

int parceRightTriplet(unsigned long number)
{
	int triplet{};
	for (int i = 0; i < 3; i++)
	{
		triplet += (number % 10)*pow(10,i);
		number /= 10;
	}
	return triplet;
}


std::string getRankName( unsigned short triplet,unsigned short rank)
{
	unsigned short ten{ (triplet / 10) % 10 };
	unsigned short unit{};
	if (ten == 1)
		unit = 0;
	else
		unit = triplet % 10;
	return constants::ranks[rank][unit];
}

std::string getValuteName(unsigned  long number) {
	bool tenExeption{ number % 100 / 10 == 1 };
	return *(constants::valutes[0] + number % 10 * !tenExeption);
}

int pow(int base, int power)
{
	int result{ 1 };
	for (int i = 0; i < power; i++)
	{
		result *= base;
	}
	return result;
}










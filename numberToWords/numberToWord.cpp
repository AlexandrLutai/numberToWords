#include"numberToWord.h"
#include<iostream>

namespace constants {
	const std::string valutes[1][10] = {
		{"Рублей.", "Рубль.","Рубля.", "Рубля.", "Рубля.", "Рублей.", "Рублей.","Рублей.","Рублей.", "Рублей."}
	};

	const std::string ranks[][10] = {
		{"","","","","","","","","",""},
		{"Тысяч ","Тысяча ","Тысячи ","Тысячи ","Тысячи ", "Тысяч ","Тысяч ","Тысяч ","Тысяч ","Тысяч "},
		{"Миллионов ", "Миллион ", "Миллиона ","Миллиона ","Миллиона ","Миллионов ","Миллионов ","Миллионов ","Миллионов ","Миллионов "},
		{"Миллиардов ", "Миллиард ", "Миллиарда ","Миллиарда ","Миллиарда ","Миллиардов ","Миллиардов ","Миллиардов ","Миллиардов ","Миллиардов "}
	};

	const std::string tensInWords[] = {
		"","", "Двадцать ", "Тридцать ", "Сорок ", "Пятьдесят ", "Шестьдесят ", "Семьдесят ", "Восемьдесят ","Девяносто "
	};

	const std::string hundredsInWords[] = {
		"","Сто ", "Двести ","Триста ","Четыреста ","Пятьсот ","Шестьсот ","Семьсот ","Восемьсот ","Девятьсот "
	};

	const std::string thousandExeption[] = {
		"","Одна ", "Две ", "Три ", "Четыре ", "Пять ", "Шесть ", "Семь ", "Восемь ", "Девять "
	};

	const std::string tensExeptionUnitName[] = {
		"Десять ", "Одиннадцать ", "Двенадцать ", "Тринадцать ", "Четырнадцать ", "Пятнадцать ", "Шестнадцать ","Семнадцать ","Восемнадцать ", "Девятнадцать "
	};
	const std::string tensExeptionTensName[] = {
		"", "", "", "", "", "", "","","", ""
	};

	const std::string unitsInWords[] = {
		"","Один ", "Два ", "Три ", "Четыре ", "Пять ", "Шесть ", "Семь ", "Восемь ", "Девять "
	};

	const std::string* digitsInWordsArrays[8][4]
	{
		{hundredsInWords, tensInWords, unitsInWords, *ranks}, {hundredsInWords,tensExeptionTensName, tensExeptionUnitName, *ranks},
		{hundredsInWords, tensInWords, thousandExeption, *ranks}, {hundredsInWords, tensExeptionTensName, tensExeptionUnitName, *valutes},
		{hundredsInWords, tensInWords, unitsInWords, *ranks}, {hundredsInWords, tensExeptionTensName, tensExeptionUnitName, *valutes},
		{hundredsInWords, tensInWords, unitsInWords, *ranks}, {hundredsInWords, tensExeptionTensName, tensExeptionUnitName, *valutes},
	};
}

struct Triplet
{
	unsigned short triplet[3]{ 0,0,0 };
	Triplet operator=(Triplet paramTriplet) 
	{
		for (int position = 0; position < 3; position++)
		{
			triplet[position] = paramTriplet.triplet[position];
		}
		return *this;
	}
	explicit operator bool() const
	{
		return triplet[orderHundreds] + triplet[orderTens] + triplet[orderUnits] != 0;
	}
};

//Объявление функций
std::string getTripletName(Triplet triplet, int rank);
std::string getRankName(unsigned short unit, unsigned short rank, bool tenExeption);
Triplet parceRightTriplet(unsigned long number);
std::string getValuteName(unsigned  long number);



//Определение функций
std::string getNumberAsWords(unsigned  long number)
{
	if (!number) return "Ноль Рублей.";
	
	std::string numberInWords{getValuteName(number)};
	int rank{ 0 };
	Triplet parsedTriplet{};
	
	while (number > 0)
	{
		parsedTriplet = parceRightTriplet(number);
		number /= 1000;
		numberInWords = getTripletName(parsedTriplet, rank) + numberInWords;
		rank += 2;
	}

	return numberInWords;
}

std::string getTripletName(Triplet triplet, int rank)
{
	
	if (!triplet) return "";

	std::string tripletName{};
	bool tenExeption{ triplet.triplet[orderTens] == 1 };
	
	for (int position = 0; position < 3; position++)
	{
		tripletName += *(constants::digitsInWordsArrays[rank + tenExeption][position] + triplet.triplet[position]);
	}
	
	tripletName += getRankName(triplet.triplet[orderUnits], rank, tenExeption);
	return tripletName;
}

Triplet parceRightTriplet(unsigned long number)
{
	Triplet triplet;
	for (int position = 2; position >= 0; position--)
	{
		triplet.triplet[position] = number % 10;
		number /= 10;
	}
	return triplet;
}

std::string getRankName( unsigned short unit, unsigned short rank, bool tenExeption)
{
	// elementPosition - вычисляется по следующей формуле:
	// (countElementsInRank * rank) / 2 + unit * !tenExeption
	// countElementsInRank - количество элементов в массиве, хранящем разряд
	// unit - число порядка единиц
	// tenExeption - флаг исключения для чисел от 10 до 19
	// rank - порядок разряда
	// 2 - магическое число, необходимое для корректного вычисления позиции элемента в массиве Ranks
	// P.s: digitsInWordsArrays хранит массивы указателей на массивы в формате:
		// {
		// {Стандартный случай}, {Исключение}, //Первый разряд
		// {Стандартный случай}, {Исключение}, //Второй разряд
		// }
	// Следовательно, для каждого разряда выделено по 2 массива, для стандартного случая и исключения
	// Массивы valutes и ranks хранят значения в формате:
		//{
		//	{Значения}, //Первый разряд
		//  {Значения}, //Второй разряд
		//}
	//Следовательно, для каждого разряда выделено по 1 массиву.
	//Поэтому для корректного вычисления значения элемента в массиве ranks(valutes), необходимо разделить
	//исходное значение переменной rank, предназначенное для работы с массивом digitsInWordsArrays на 2
	//!!Решить данную проблему можно выделением новой переменной, которя будет зранить разряды 
	//для работы с массивами valutes и ranks
	const unsigned short countElementsInRank{ 10 };
	int elementPosition{ (countElementsInRank * rank) / 2 + unit * !tenExeption };
	return *(constants::digitsInWordsArrays[rank][rankOrValute] + elementPosition );
}

std::string getValuteName(unsigned  long number) {
	bool tenExeption{ number % 100 / 10 == 1 };
	return *(constants::valutes[0] + number % 10 * !tenExeption);
}












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
		{hundredsInWords, tensInWords, unitsInWords, *valutes}, {hundredsInWords,tensExeptionTensName, tensExeptionUnitName, *valutes},
		{hundredsInWords, tensInWords, thousandExeption, *ranks}, {hundredsInWords, tensExeptionTensName, tensExeptionUnitName, *valutes},
		{hundredsInWords, tensInWords, unitsInWords, *ranks}, {hundredsInWords, tensExeptionTensName, tensExeptionUnitName, *valutes},
		{hundredsInWords, tensInWords, unitsInWords, *ranks}, {hundredsInWords, tensExeptionTensName, tensExeptionUnitName, *valutes},
	};
}



int parseRightDigit(unsigned long number);
std::string getUnitName(unsigned short unit, unsigned short rank, bool isTenExeption);
std::string getTenName(unsigned short tens, unsigned short rank, bool isTenExeption);
std::string getHundredName(unsigned short hundreds, unsigned short rank, bool tenExeption);
std::string getRankName(unsigned short unit, unsigned short rank, bool tenExeption);
 
std::string(*funcArr[])(unsigned short unit, unsigned short rank, bool isTenExeption) {getHundredName,  getTenName, getUnitName};

std::string getNumberAsWords(unsigned  long number)
{
	if (!number) return "Ноль Рублей.";
	std::string numberInWords{};
	int rank{ 0 };
	unsigned short triplet[3]{};
	while (number > 0)
	{
		//Получение триплета
		for ( int position = 2; position >=0; position--)
		{
			triplet[position] = parseRightDigit(number);
			number /= 10;
		}
		rank += 2;

		
		if (!(triplet[orderUnits] + triplet[orderTens] + triplet[orderHundreds] + !rank)) //!!!! Убрать rank
			continue;
		

		bool tenExeption{ triplet[orderTens] == 1 };
		std::string tripletName = {};
			
		for (int i = 0; i < 3; i++)
		{
			std::string word{(*funcArr[i])(triplet[i], rank, tenExeption)};
			tripletName += word;
		}
			
		tripletName+= getRankName(triplet[orderUnits], rank, tenExeption);
			
		numberInWords = tripletName + numberInWords;
		
		

		
		 // 2 - пропускаем разряд целиком
		
	
	}

	return numberInWords;
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


std::string getHundredName(unsigned short hundreds, unsigned short rank, bool tenExeption)
{
	//Фактич. одна строка.
	return *(constants::digitsInWordsArrays[rank + tenExeption][orderHundreds] + hundreds);
}

std::string getTenName(unsigned short ten, unsigned short rank, bool tenExeption)
{
	return *(constants::digitsInWordsArrays[rank][orderTens] + ten * !tenExeption);

}

std::string getUnitName(unsigned short unit, unsigned short rank, bool tenExeption)
{
	return *(constants::digitsInWordsArrays[rank + tenExeption][orderUnits] + unit);
}

int parseRightDigit(unsigned long number)
{
	return number % 10;
}









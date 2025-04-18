#include"numberToWord.h"
#include<iostream>

namespace constants {
	std::string valutes[1][10] 
	{
		{"������.", "�����.","�����.", "�����.", "�����.", "������.", "������.","������.","������.", "������."}

	};

	std::string ranks[4][10]
	{
		{"","","","","","","","","",""},
		{"����� ","������ ","������ ","������ ","������ ", "����� ","����� ","����� ","����� ","����� "},
		{"��������� ", "������� ", "�������� ","�������� ","�������� ","��������� ","��������� ","��������� ","��������� ","��������� "},
		{"���������� ", "�������� ", "��������� ","��������� ","��������� ","���������� ","���������� ","���������� ","���������� ","���������� "}
	};

	std::string tensInWords[]
	{
		"","������ ", "�������� ", "�������� ", "����� ", "��������� ", "���������� ", "��������� ", "����������� ","��������� "
	};

	std::string hundredsInWords[]
	{
		"","��� ", "������ ","������ ","��������� ","������� ","�������� ","������� ","��������� ","��������� "
	};

	std::string thousandExeption[]
	{
		"","���� ", "��� ", "��� ", "������ ", "���� ", "����� ", "���� ", "������ ", "������ "
	};

	std::string tensExeptionsNames[]
	{
		"������ ", "����������� ", "���������� ", "���������� ", "������������ ", "���������� ", "����������� ","���������� ","������������ ", "������������ "
	};
	
	
	std::string unitsInWords[]
	{
		"","���� ", "��� ", "��� ", "������ ", "���� ", "����� ", "���� ", "������ ", "������ "
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
	if (!number) return "���� ������.";
	
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










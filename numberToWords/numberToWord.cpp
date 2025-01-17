#include"numberToWord.h"
#include<iostream>

namespace constants {
	const std::string valutes[1][10] = {
		{"������.", "�����.","�����.", "�����.", "�����.", "������.", "������.","������.","������.", "������."}
	};

	const std::string ranks[][10] = {
		{"","","","","","","","","",""},
		{"����� ","������ ","������ ","������ ","������ ", "����� ","����� ","����� ","����� ","����� "},
		{"��������� ", "������� ", "�������� ","�������� ","�������� ","��������� ","��������� ","��������� ","��������� ","��������� "},
		{"���������� ", "�������� ", "��������� ","��������� ","��������� ","���������� ","���������� ","���������� ","���������� ","���������� "}
	};

	const std::string tensInWords[] = {
		"","", "�������� ", "�������� ", "����� ", "��������� ", "���������� ", "��������� ", "����������� ","��������� "
	};

	const std::string hundredsInWords[] = {
		"","��� ", "������ ","������ ","��������� ","������� ","�������� ","������� ","��������� ","��������� "
	};

	const std::string thousandExeption[] = {
		"","���� ", "��� ", "��� ", "������ ", "���� ", "����� ", "���� ", "������ ", "������ "
	};

	const std::string tensExeptionUnitName[] = {
		"������ ", "����������� ", "���������� ", "���������� ", "������������ ", "���������� ", "����������� ","���������� ","������������ ", "������������ "
	};
	const std::string tensExeptionTensName[] = {
		"", "", "", "", "", "", "","","", ""
	};

	const std::string unitsInWords[] = {
		"","���� ", "��� ", "��� ", "������ ", "���� ", "����� ", "���� ", "������ ", "������ "
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

//���������� �������
std::string getTripletName(Triplet triplet, int rank);
std::string getRankName(unsigned short unit, unsigned short rank, bool tenExeption);
Triplet parceRightTriplet(unsigned long number);
std::string getValuteName(unsigned  long number);



//����������� �������
std::string getNumberAsWords(unsigned  long number)
{
	if (!number) return "���� ������.";
	
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
	// elementPosition - ����������� �� ��������� �������:
	// (countElementsInRank * rank) / 2 + unit * !tenExeption
	// countElementsInRank - ���������� ��������� � �������, �������� ������
	// unit - ����� ������� ������
	// tenExeption - ���� ���������� ��� ����� �� 10 �� 19
	// rank - ������� �������
	// 2 - ���������� �����, ����������� ��� ����������� ���������� ������� �������� � ������� Ranks
	// P.s: digitsInWordsArrays ������ ������� ���������� �� ������� � �������:
		// {
		// {����������� ������}, {����������}, //������ ������
		// {����������� ������}, {����������}, //������ ������
		// }
	// �������������, ��� ������� ������� �������� �� 2 �������, ��� ������������ ������ � ����������
	// ������� valutes � ranks ������ �������� � �������:
		//{
		//	{��������}, //������ ������
		//  {��������}, //������ ������
		//}
	//�������������, ��� ������� ������� �������� �� 1 �������.
	//������� ��� ����������� ���������� �������� �������� � ������� ranks(valutes), ���������� ���������
	//�������� �������� ���������� rank, ��������������� ��� ������ � �������� digitsInWordsArrays �� 2
	//!!������ ������ �������� ����� ���������� ����� ����������, ������ ����� ������� ������� 
	//��� ������ � ��������� valutes � ranks
	const unsigned short countElementsInRank{ 10 };
	int elementPosition{ (countElementsInRank * rank) / 2 + unit * !tenExeption };
	return *(constants::digitsInWordsArrays[rank][rankOrValute] + elementPosition );
}

std::string getValuteName(unsigned  long number) {
	bool tenExeption{ number % 100 / 10 == 1 };
	return *(constants::valutes[0] + number % 10 * !tenExeption);
}












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

	const std::string tensExeption[] = {
		"������ ", "����������� ", "���������� ", "���������� ", "������������ ", "���������� ", "����������� ","���������� ","������������ ", "������������ "
	};

	const std::string unitsInWords[] = {
		"","���� ", "��� ", "��� ", "������ ", "���� ", "����� ", "���� ", "������ ", "������ "
	};

	const std::string* digitsInWordsArrays[8][4]
	{
		{hundredsInWords, tensInWords, unitsInWords, *valutes}, {hundredsInWords, tensInWords, tensExeption, *valutes},
		{hundredsInWords, tensInWords, thousandExeption, *ranks}, {hundredsInWords, tensInWords, tensExeption, *valutes},
		{hundredsInWords, tensInWords, unitsInWords, *ranks}, {hundredsInWords, tensInWords, tensExeption, *valutes},
		{hundredsInWords, tensInWords, unitsInWords, *ranks}, {hundredsInWords, tensInWords, tensExeption, *valutes},
	};
}



int parseRightDigit(unsigned long* number);
std::string getUnitName(unsigned short unit, unsigned short rank, bool isTenExeption);
std::string getTenName(unsigned short tens, unsigned short rank, bool isTenExeption);
std::string getHundredName(unsigned short hundreds, unsigned short rank);
std::string getRankName(unsigned short unit, unsigned short rank, bool tenExeption);

std::string getNumberAsWords(unsigned  long number)
{
	if (!number) return "���� ������.";
	unsigned short numberOfDigit{ 0 };
	std::string numberInWords{};
	int rank{ 0 };
	unsigned short triplet[3]{};
	while (number > 0)
	{
		triplet[orderUnits] = parseRightDigit(&number) ;
		triplet[orderTens] = parseRightDigit(&number);
		triplet[orderHundreds] = parseRightDigit(&number);
		bool tenExeption{ triplet[orderTens] == 1 };
		if (triplet[orderUnits] + triplet[orderTens] + triplet[orderHundreds] + !rank)
		{
			numberInWords =
				getHundredName(triplet[orderHundreds], rank) +
				getTenName(triplet[orderTens], rank, tenExeption) +
				getUnitName(triplet[orderUnits], rank, tenExeption) +
				getRankName(triplet[orderUnits], rank, tenExeption) + numberInWords;
		}
		

		
		rank += 2; // 2 - ���������� ������ �������
		
	
	}

	return numberInWords;
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

std::string getHundredName(unsigned short hundreds, unsigned short rank) 
{
	return *(constants::digitsInWordsArrays[rank][orderHundreds] + hundreds);
}

std::string getTenName(unsigned short ten, unsigned short rank, bool tenExeption)
{
	return *(constants::digitsInWordsArrays[rank][orderTens] + ten * !tenExeption);

}

std::string getUnitName(unsigned short unit, unsigned short rank, bool tenExeption)
{
	return *(constants::digitsInWordsArrays[rank + tenExeption][orderUnits] + unit);
}

int parseRightDigit(unsigned long* number)
{
	int lastRightDigit{ *number % 10 };
	*number /= 10;
	return lastRightDigit;
}









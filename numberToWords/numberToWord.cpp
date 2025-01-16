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
	if (!number) return "���� ������.";
	std::string numberInWords{};
	int rank{ 0 };
	unsigned short triplet[3]{};
	while (number > 0)
	{
		//��������� ��������
		for ( int position = 2; position >=0; position--)
		{
			triplet[position] = parseRightDigit(number);
			number /= 10;
		}
		rank += 2;

		
		if (!(triplet[orderUnits] + triplet[orderTens] + triplet[orderHundreds] + !rank)) //!!!! ������ rank
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
		
		

		
		 // 2 - ���������� ������ �������
		
	
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


std::string getHundredName(unsigned short hundreds, unsigned short rank, bool tenExeption)
{
	//������. ���� ������.
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









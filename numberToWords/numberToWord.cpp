#include"numberToWord.h"
#include<iostream>



void getDigitsInArray(unsigned long , unsigned short*, int );
void changeParams(unsigned long* number, unsigned short* numberOfDigit = nullptr);
std::string getNumberName(unsigned short, unsigned short , unsigned short , unsigned short );
std::string getNumberNameWithValutes(unsigned short, unsigned short, unsigned short);




//������� ����� ������ ��� ������� �����.
//�������������� ��� ����������, ��� 1 � 2
std::string thousandExeption(short lastDigit,int numberDigit, int fullNumberDigit) {
	if (fullNumberDigit == 3) {
		switch (lastDigit)
		{
		case 1:
			return "����";
		case 2:
			return "���";
		
		}
	}
	return constants::units[lastDigit][numberDigit];
}

//��������� �������� �����
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
	//������������� �������� ����������
	//� ���������� isExeption �������� 0, ���� �������������� ���������� ��������, � ������ ������ - 1
	unsigned short isExeption{ !tenExeption };
	//�������������� ���������� ��� �����, 0 - ������ �����, ��� ��� ������ � ������� �������������� ��������.
	if (digitRank == 0) 
	{
		//���� �������������� ���������� ��� ��������, �� � ���������� isExeption �������� 0, 
		//����������� ������� ��������� ����� 0, ��� �������� �������� ���������� ������� � ����������� ��� ��������
		//� ������� unitsName.
		//���� �������������� �����, ��� ���������� ��� ��������, �� ����������� ������ ��������� �����
		//������ ���������� �������, ���������� ���������� ��� �����


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
	//���� �������������� ���������� �� ��������, �� ��������������� ���������� tenExeption ����� ���������� 0,
	//� ����������� ������� ��������� ������ ����� ������ ������ � �������, ������� ������ ��������� ����� ��� ������.
	//� ���� ������ ����������� ����� ������ ��� ��������� �����, ����������� � unit
	return constants::valutes[!tenExeption * unit];
}
std::string getNumberNameWithValutes(unsigned short unit, unsigned short ten, unsigned short hundred)
{
	int summAllDigits{ hundred + ten + unit };

	
		bool tensExeption{ ten == 1 };
		return getHundredName(hundred) + getTenName(ten, tensExeption)
			+ getUnitName(unit, tensExeption) + getValuteName(unit, tensExeption);
	
}





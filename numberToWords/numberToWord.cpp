#include"numberToWord.h"
#include<iostream>


// !!������ �� ������������� 
//�������� ��������� ���������� ������ - stringBeingChenged.
//ending - ���������, �� ������� ����� ���������� ��������.
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


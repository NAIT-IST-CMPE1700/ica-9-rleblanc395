#include <stdlib.h>
#include <stdio.h>
#include "LList.h"

int main(int argc, char** argv)
{
	PrintMenu();
	student* headID = NULL;
	student* headMark = NULL;
	int menu = 0;
	scanf_s("%d", &menu, sizeof(int));

	for (int i = 0; i < 10; i++)
	{
		headID = AddByID(headID, nameList[i], idList[i], markList[i]);
	}
	for (int j = 0; j < 10; j++)
	{
		headMark = AddByMark(headMark, nameList[j], idList[j], markList[j]);
	}

	if (menu == 1)
	{
		Print(headID);
		PrintMenu();
		scanf_s("%d", &menu, sizeof(int));
	}
	
	if (menu == 2)
	{
		Print(headMark);
		PrintMenu();
		scanf_s("%d", &menu, sizeof(int));
	}
	
	if (menu == 3)
	{
		printf("Enter the ID: ");
		scanf_s("%d", &menu, sizeof(int));
		PrintByID(headID, menu);
		PrintMenu();
		scanf_s("%d", &menu, sizeof(int));
	}

	if (menu == 4)
	{
		printf("Enter the grade threshold: ");
		scanf_s("%d", &menu, sizeof(int));
		PrintByGrade(headMark, menu);
		PrintMenu();
		scanf_s("%d", &menu, sizeof(int));
	}

	if (menu == 5)
		exit(EXIT_SUCCESS);

	Free(headID);
	Free(headMark);
	return 0;
}
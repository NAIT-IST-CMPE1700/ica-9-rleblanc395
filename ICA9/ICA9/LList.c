#include <stdlib.h>
#include <stdio.h>
#include "LList.h"

student* AddByID(student* head, char* name, int id, int mark)
{
	student* curr = NULL;

	student* new = (student*)malloc(sizeof(student));
	if(!new)
	{
		fprintf(stderr, "Error allocating memory for student.");
		exit(EXIT_FAILURE);
	}

	new->next = NULL;
	new->name = name;
	new->studentID = id;
	new->mark = mark;

	if (!head || head->studentID >= id)
	{
		new->next = head;
		return new;
	}

	curr = head;
	while (curr->next && curr->next->studentID < id)
		curr = curr->next;

	new->next = curr->next;
	curr->next = new;
	return head;
}

student* AddByMark(student* head, char* name, int id, int mark)
{
	student* curr = NULL;

	student* new = (student*)malloc(sizeof(student));
	if (!new)
	{
		fprintf(stderr, "Error allocating memory for student.");
		exit(EXIT_FAILURE);
	}

	new->next = NULL;
	new->name = name;
	new->studentID = id;
	new->mark = mark;

	if (!head || head->mark <= mark)
	{
		new->next = head;
		return new;
	}

	curr = head;
	while (curr->next && curr->next->mark > mark)
		curr = curr->next;
	new->next = curr->next;
	curr->next = new;
	return head;
}

void PrintMenu()
{
	printf("1.Display list in order of Id’s\n");
	printf("2.Display list in descending order of Marks\n");
	printf("3.Display the names, marks and rank of a person given the ID (ID should be input)\n");
	printf("4.Display the names and marks of all person above a thresholdmarks value(the threshold value should be input).\n");
	printf("5.Exit\n");
}

void  Print(student* head)
{
	if (head)
	{
		printf("%10s   %3d   %3d\n", head->name, head->studentID, head->mark);
		Print(head->next);
	}
}

void  PrintByID(student* head, int id)
{
	if (head)
	{
		if(head->studentID == id)
			printf("%10s   %3d   %3d\n", head->name, head->studentID, head->mark);
		PrintByID(head->next, id);
	}
}

void PrintByGrade(student* head, int mark)
{
	if (head)
	{
		if (head->mark >= mark)
			printf("%10s   %3d   %3d\n", head->name, head->studentID, head->mark);
		PrintByGrade(head->next, mark);
	}
}

void Free(student* head)
{
	if (head)
		Free(head->next);
	if (head)
		free(head);
}
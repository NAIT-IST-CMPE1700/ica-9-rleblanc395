#ifndef LLISTH
#pragma once

typedef struct student student;

struct student
{
	char* name;
	int studentID;
	int mark;
	student* next;
};

void printMenu();
student* AddByID(student* head, char* name, int id, int mark);
student* AddByMark(student* head, char* name, int id, int mark);
void  Print(student* head);
void PrintByID(student* head, int id);
void PrintByGrade(student* head, int mark);
void Free(student* head);

static const char* nameList[] = { "Croaker", "Raven", "One Eye", "Goblin", "Silent", "Lady", "Case", "Sleepy", "Darling", "Otto"};
static const int idList[] = { 2, 6, 8, 1, 5, 7, 3, 4, 9, 10 };
static const int markList[] = { 88, 62, 44, 45, 67, 100, 32, 78, 57, 60 };
#endif
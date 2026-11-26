#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
typedef struct student
{
 int rollno;
 char name[50];
 float percentage;
 struct student *next;
}SLL;
void addRecord(SLL**);
void deleteRecord(SLL**);
void showRecord(SLL*);
void modifyRecord(SLL*);
void saveFile(SLL*);
void sortList(SLL*);
void deleteAll(SLL**);
void reverseList(SLL**);

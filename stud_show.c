#include<stdio.h>
#include"student.h"
void showRecord(SLL *ptr)
{
	printf("\033[3m***************\n");
	if(ptr==0)
	{
		printf("No student records available\n");
		printf("**********\n\033[0m");
		return;
	}
	printf("Roll No  Name  Percentage\n");
	printf("-------------------------\n");
	while(ptr)
	{
		printf("%d %s %f\n",ptr->rollno,ptr->name,ptr->percentage);
		ptr=ptr->next;
	}

	printf("-------------------------\n");
	printf("**********\n\033[0m");
}




	

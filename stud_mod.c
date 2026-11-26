#include<stdio.h>
#include"student.h"

void modifyRecord(SLL *ptr)
{
    if(ptr==0)
    {
        printf("No students records available\n");
        return;
    }

    char ch;
    printf("Enter which records to search for modification\n");
    printf("R/r : Search by roll number\n");
    printf("N/n : Search by name\n");
    printf("P/p : Search by percentage\n");
    scanf(" %c",&ch);

    SLL *target=0;

    if(ch=='R' || ch=='r')
    {
        int roll;
        printf("Enter roll number : ");
        scanf("%d",&roll);
        SLL *t=ptr;
        while(t)
        {
            if(t->rollno==roll)
                target=t;
            t=t->next;
        }
    }
    else if(ch=='N' || ch=='n')
    {
        char name[50];
        printf("Enter name : ");
        scanf(" %[^\n]",name);

        SLL *t=ptr;
        while(t)
        {
            if(strcmp(t->name,name)==0)
                printf("%d %s %.2f\n",t->rollno,t->name,t->percentage);
            t=t->next;
        }

        int roll;
        printf("Enter roll number to modify : ");
        scanf("%d",&roll);
        t=ptr;
        while(t)
        {
            if(t->rollno==roll)
                target=t;
            t=t->next;
        }
    }
    else if(ch=='P' || ch=='p')
    {
        float per;
        printf("Enter percentage : ");
        scanf("%f",&per);

        SLL *t=ptr;
        while(t)
        {
            if(t->percentage==per)
                printf("%d %s %.2f\n",t->rollno,t->name,t->percentage);
            t=t->next;
        }

        int roll;
        printf("Enter roll number to modify : ");
        scanf("%d",&roll);
        t=ptr;
        while(t)
        {
            if(t->rollno==roll)
                target=t;
            t=t->next;
        }
    }

    if(target==0)
    {
        printf("Records not found\n");
        return;
    }

    printf("Current : %d %s %.2f\n",target->rollno,target->name,target->percentage);

    printf("Enter new name : ");
    scanf(" %[^\n]",target->name);

    printf("Enter new percentage : ");
    scanf("%f",&target->percentage);

    printf("Record modified\n");
}

#include<stdio.h>
#include"student.h"
void deleteRecord(SLL **ptr)
{
    printf("\033[3m**************\n");
    if(*ptr==0)
    {
        printf("NO records found\n");
        printf("**********\n\033[0m");
        return;
    }
    char ch;
    printf("R/r : Enter roll number to delete\n");
    printf("N/n : enter name to delete\n");
    printf("Enter choice :");
    scanf(" %c",&ch);
    if(ch=='R' || ch=='r')
    {
        int roll;
        printf("Enter roll number to delete : ");
        scanf("%d",&roll);
        SLL *del=*ptr;
        SLL *prev;
        while(del)
        {
            if(del->rollno==roll)
            {
                if(del==*ptr)
                    *ptr=del->next;
                else
                    prev->next=del->next;
                free(del);
                printf("Record deleted\n");
                return;
            }
            prev=del;
            del=del->next;
        }
        printf("Roll number not found\n");
    }
    else if(ch=='N' || ch=='n')
    {
        char name[50];
        printf("Enter name to delete : ");
        //scanf("%[^\n]",name);
        scanf("%s",name);
        SLL *t=*ptr;
        int found=0;
        while(t)
        {
            if(strcmp(t->name,name)==0)
            {
                printf("%d %s %.2f\n",t->rollno,t->name,t->percentage);
                found=1;
            }
            t=t->next;
        }

        if(found==0)
        {
            printf("Name not found\n");
            return;
        }
        int roll;
        printf("Enter roll number from above to delete : ");
        scanf("%d",&roll);
        SLL *del=*ptr;
        SLL *prev;
        while(del)
        {
            if(del->rollno==roll)
            {
                if(del==*ptr)
                    *ptr=del->next;
                else
                    prev->next=del->next;

                free(del);
                printf("Record deleted\n");
                return;
            }
            prev=del;
            del=del->next;
        }
        printf("Roll number not found\n");
    }
}

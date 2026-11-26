#include<stdio.h>
#include"student.h"
int getNextRollno(SLL *ptr)
{
    int r=1;
    while(1)
    {
        SLL *t=ptr;
        int found=0;
        while(t)
        {
            if(t->rollno==r)
            {
                found=1;
                break;
            }
            t=t->next;
        }
        if(found==0)
            return r;
        r++;
    }
}
void addRecord(SLL **ptr)
{
    SLL *new;
    new=malloc(sizeof(SLL));
    new->rollno=getNextRollno(*ptr);
    printf("Enter name :");
    scanf(" %[^\n]",new->name);
    printf("Enter percentage (0-100) : ");
    scanf("%f",&new->percentage);
    if(new->name[0]=='\0' || new->percentage < 0 || new->percentage > 100)
    {
        printf("Invalid name / percentage\n");
        free(new);
        return;
    }
    new->next=0;
    if(*ptr==0)
    {
        *ptr=new;
    }
    else
    {
        SLL *last=*ptr;
        while(last->next)
            last=last->next;
        last->next=new;
    }
    printf("Record added,RollNo=%d\n",new->rollno);
}












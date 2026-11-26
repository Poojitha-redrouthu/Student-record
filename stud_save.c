#include<stdio.h>
#include"student.h"
//savefile
void saveFile(SLL *ptr)
{
    FILE *fp=fopen("student.dat","w");
    if(fp==0)
    {
        printf("Cannot open file\n");
        return;
    }

    while(ptr)
    {
        fprintf(fp,"%d %s %f\n",ptr->rollno,ptr->name,ptr->percentage);
        ptr=ptr->next;
    }
    fclose(fp);
    printf("Records saved to student.dat\n");
}
//loadfile
void loadFile(SLL **ptr)
{
    FILE *fp=fopen("student.dat","r");
    if(fp==0)
        return;

    while(1)
    {
        SLL *new=malloc(sizeof(SLL));
        if(fscanf(fp,"%d %s %f",&new->rollno,new->name,&new->percentage)==-1)
        {
            free(new);
            break;
        }
        new->next=0;
        if(*ptr==0)
            *ptr=new;
        else
        {
            SLL *last=*ptr;
            while(last->next)
                last=last->next;
            last->next=new;
        }
    }
    fclose(fp);
}


int countNode(SLL *ptr)
{
    int c=0;
    while(ptr)
    {
        c++;
        ptr=ptr->next;
    }
    return c;
}
//sort
void sortList(SLL *ptr)
{
    if(ptr==0)
    {
        printf("No student records available\n");
        return;
    }

    char ch;
    printf("N/n : Sort with name\n");
    printf("P/p : Sort with percentage\n");
    scanf(" %c",&ch);

    int i,j,c=countNode(ptr);
    SLL *p1=ptr,*p2,*t;

    for(i=0;i<c-1;i++)
    {
        p2=p1->next;
        for(j=0;j<c-i-1;j++)
        {
            int swap=0;
            if(ch=='N' || ch=='n')
            {
                if(strcmp(p1->name,p2->name)>0)
                    swap=1;
            }
            else
            {
                if(p1->percentage<p2->percentage)
                    swap=1;
            }

            if(swap)
            {
                t->rollno=p1->rollno;
                strcpy(t->name,p1->name);
                t->percentage=p1->percentage;

                p1->rollno=p2->rollno;
                strcpy(p1->name,p2->name);
                p1->percentage=p2->percentage;

                p2->rollno=t->rollno;
                strcpy(p2->name,t->name);
                p2->percentage=t->percentage;
            }
            p2=p2->next;
        }
        p1=p1->next;
    }
    printf("Sorted Successfully\n");
}
//reverselist
void reverseList(SLL **ptr)
{
    if(*ptr==0)
    {
        printf("No student records available\n");
        return;
    }

    int i,c=countNode(*ptr);
    if(c>1)
    {
        SLL **a=malloc(sizeof(SLL *)*c);
        SLL *t=*ptr;

        for(i=0;i<c;i++)
        {
            a[i]=t;
            t=t->next;
        }

        for(i=c-1;i>0;i--)
            a[i]->next=a[i-1];

        a[0]->next=0;
        *ptr=a[c-1];
        free(a);
    }
    printf("List reversed\n");
}
//deleteAll
void deleteAll(SLL **ptr)
{
    if(*ptr==0)
    {
        printf("No student records available\n");
        return;
    }

    SLL *del=*ptr;
    while(del)
    {
        *ptr=del->next;
        free(del);
        del=*ptr;
    }
    printf("All records deleted\n");
}





























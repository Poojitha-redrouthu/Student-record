#include<stdio.h>
#include"student.h"
int main(){
SLL *headptr=0;
char  op;
while(1){
printf("enter your choice\n");
printf("a/A : Add new record\n"
       "d/D : Delete a record\n"
        "s/S : Show the list\n"
        "m/M : Modify a record\n"
        "v/V : Save records\n"
         "e/E : Exit\n"
         "t/T : Sort the list\n"
         "l/L : Delete all the records\n"
         "r/R : Reverse the list\n");
scanf(" %c",&op);
switch(op){
case 'a':case 'A': addRecord(&headptr);break;
case 'd':case 'D': deleteRecord(&headptr);break;
case 's':case 'S': showRecord(headptr);break;
case 'm':case 'M': modifyRecord(headptr);break;
case 'v':case 'V': saveFile(headptr);break;
case 't':case 'T': sortList(headptr);break;
case 'l':case 'L': deleteAll(&headptr);break;
case 'r':case 'R': reverseList(&headptr);break;
case 'e':case 'E': exit(0);
default: printf("unknown choice\n");
}
}
}


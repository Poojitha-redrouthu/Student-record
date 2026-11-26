CC = gcc

CFLAGS = -Wall -g

OBJ = stud_main.o stud_add.o stud_del.o stud_mod.o stud_save.o stud_show.o

student: $(OBJ)
	$(CC) $(CFLAGS) -o student $(OBJ)

stud_main.o: stud_main.c student.h
	$(CC) $(CFLAGS) -c stud_main.c

stud_add.o: stud_add.c student.h
	$(CC) $(CFLAGS) -c stud_add.c

stud_del.o: stud_del.c student.h
	$(CC) $(CFLAGS) -c stud_del.c

stud_mod.o: stud_mod.c student.h
	$(CC) $(CFLAGS) -c stud_mod.c

stud_save.o: stud_save.c student.h
	$(CC) $(CFLAGS) -c stud_save.c

stud_show.o: stud_show.c student.h
	$(CC) $(CFLAGS) -c stud_show.c

clean:
	rm -f *.o student

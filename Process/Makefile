all:clean process zombie orphan no_orphan signal child_parent_signal
	rm -f *.o

process:process.o
	gcc -o process process.o
process.o:process.c
	gcc -c process.c

zombie:process_zombie.o
	gcc -o process_zombie process_zombie.o
process_zombie.o:process_zombie.c
	gcc -c process_zombie.c

orphan:process_orphan.o
	gcc -o process_orphan process_orphan.o
process_orphan.o:process_orphan.c
	gcc -c process_orphan.c

no_orphan:process_no_orphan.o
	gcc -o process_no_orphan process_no_orphan.o
process_no_orphan.o:process_no_orphan.c
	gcc -c process_no_orphan.c

signal:process_signal.o
	gcc -o process_signal process_signal.o
process_signal.o:process_signal.c
	gcc -c process_signal.c

child_parent_signal:child_parent_signal.o
	gcc -o child_parent_signal child_parent_signal.o
child_parent_signal.o:child_parent_signal.c
	gcc -c child_parent_signal.c


clean:
	rm -f process *.o process_orphan process_zombie process_no_orphan process

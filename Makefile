CC = gcc
CFLAGS = -g -Wall -Wextra -O0 -std=gnu99

zad1-5: 
	$(CC) $(CFLAGS) ./zadania1-5/*.c -o ./zadania1-5/test
zad6-8: 
	$(CC) $(CFLAGS) ./zadania6-8/*.c -o ./zadania6-8/test
zad9: 
	$(CC) $(CFLAGS) ./zadanie9/*.c -o ./zadanie9/test
zad10-1way:
	$(CC) $(CFLAGS) ./zadania10-12/main_1way.c ./zadania10-12/circularLinkedList.c -o ./zadania10-12/1way_test
zad10-12-2way:
	$(CC) $(CFLAGS) ./zadania10-12/main_2way.c ./zadania10-12/circularDoublyLinkedList.c -o ./zadania10-12/2way_test
zad13:
	$(CC) $(CFLAGS) ./zadanie13/*.c -o ./zadanie13/test
zad14i15:
	$(CC) $(CFLAGS) ./zadanie14i15/*.c -o ./zadanie14i15/test
zad16:
	$(CC) $(CFLAGS) ./zadanie16/*.c -o ./zadanie16/test
zad17:
	$(CC) $(CFLAGS) ./zadanie17/*.c -o ./zadanie17/test
zad18:
	$(CC) $(CFLAGS) ./zadanie18/*.c -o ./zadanie18/test
zad19:
	$(CC) $(CFLAGS) ./zadanie19/*.c -o ./zadanie19/test
zad20:
	$(CC) $(CFLAGS) ./zadanie20/*.c -o ./zadanie20/test
zad21:
	$(CC) $(CFLAGS) ./zadanie21/*.c -o ./zadanie21/test
zad22:
	$(CC) $(CFLAGS) ./zadanie22/*.c -o ./zadanie22/test
zad23:
	$(CC) $(CFLAGS) ./zadanie23/*.c -o ./zadanie23/test
zad24:
	$(CC) $(CFLAGS) ./zadanie24/*.c -o ./zadanie24/test
zad25:
	$(CC) $(CFLAGS) ./zadanie25/*.c -o ./zadanie25/test
github-push:
	git add .
	git commit -m"Dodanie rozwiązań zadań do repozytorium"
	git push origin main
github-pull:
	git pull
%:
	@:
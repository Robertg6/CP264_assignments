/*
 -------------------------------------
 File:    a1q2.c
 Project: a1q1
 file description
 -------------------------------------
 Author:  your name here
 ID:      your ID here
 Email:   your Laurier email here
 Version  2020-01-13
 -------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *args[]) {

	int i, n;
	if (argc > 1) {
		printf("Invalid input you should enter a number!");
	} else {
		n = atoi(args[1]);
		if (n == 0 && argc != 0) {
			int temporary = 1;
			for (int i = 1; i <= n && i <= 13; i++) {
				if (i == 13) {
					printf("Overflow at 13!");
					break;
				}
				if (i % 3 == 0) {
					printf("%10d\n", temporary *= i);
				} else {
					printf("%10d", temporary *= i);
				}
			}

		} else
			printf("no argument");

		return 0;
	}
}


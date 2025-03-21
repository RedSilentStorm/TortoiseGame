#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>


void gameOver() {
	printf("\nGAME OVER!\n");
	exit(0);
}

void youWon() {
	printf("\nYOU WON!\n");
	exit(0);
}

void  isBerry(char b[][100], int* e, int* bCount, int tx, int ty) {

	if (b[tx][ty] == '*') {
		*e += 11;
		*bCount = *bCount - 1;
	}
}

void  isPit(char b[][100], int* e, int* pCount, int tx, int ty) {

	if (b[tx][ty] == '0') {
		b[tx][ty] = '0';
		*pCount = 0;
	}
}

void printBoard(char b[][100], int n, int energy) {
	system("cls"); //for clearing the screen
	printf("\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%c", b[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("you have %d energy\n", energy);
}


int main() {
	srand(time(NULL));
	int energy = 20;
	int n, p;
	int bCount;
	int pCount;

	printf("enter matrix size: ");
	scanf("%d", &n);
	printf("\n");

	int tx = rand() % n; //tortoise x
	int ty = rand() % n; //tortoise y
	char b[100][100]; //locations
	int bn = 0.15 * n * n; //berry number
	int pn = 0.05 * n * n; //pit number
	if (pn < 1) {
		pn = 1;
	}
	if (bn < 1) {
		bn = 1;
	}
	bCount = bn;
	pCount = 1;

	//-
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			b[i][j] = '-';
		}
	}

	//tortoise
	b[tx][ty] = '@';

	//mulberrys
	for (int k = 1; k <= bn; k++) {
		int bx = rand() % n;
		int by = rand() % n;
		if (b[bx][by] != '@' && b[bx][by] != '*') {
			b[bx][by] = '*';
		}
		else {
			k--;
		}

	}

	//pits
	for (int k = 1; k <= pn; k++) {
		int px = rand() % n;
		int py = rand() % n;
		if (b[px][py] != '*' && b[px][py] != '@' && b[px][py] != '0') {
			b[px][py] = '0';
		}
		else {
			k--;
		}
	}

	// ACTIONS
	char direction;
	printBoard(b, n, energy);

	while (energy > 0) {

		printf("enter the action: ");
		scanf("%s", &direction);

		if (direction == 'w') {
			if (tx != 0) {
				b[tx][ty] = '-';
				tx--;
				energy--;

			}
		}
		else if (direction == 'a') {
			if (ty != 0) {
				b[tx][ty] = '-';
				ty--;
				energy--;
			}
		}
		else if (direction == 's') {
			if (tx != (n - 1)) {
				b[tx][ty] = '-';
				tx++;
				energy--;
			}
		}
		else if (direction == 'd') {
			if (ty != (n - 1)) {
				b[tx][ty] = '-';
				ty++;
				energy--;
			}

		}

		isBerry(b, &energy, &bCount, tx, ty);
		isPit(b, &energy, &pCount, tx, ty);
		b[tx][ty] = '@';
		printBoard(b, n, energy);

		if (bCount == 0) {
			b[tx][ty] = '@';
			printBoard(b, n, energy);
			youWon();
		}
		if (pCount == 0) {
			b[tx][ty] = '0';
			printBoard(b, n, energy);
			gameOver();
		}
	}

	printf("\nout of energy");
	gameOver();
	return 0;
}
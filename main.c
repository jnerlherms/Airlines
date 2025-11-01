#include <stdio.h>
#include <stdlib.h>
#include "airline.c"

int main() {

  int seats[10];
  int size = 10;
  int seatType;
  int seatno;
  char redo;
  int restart = 1;

  printf("Welcome to MGM Airlines!\n");
  initSeats(seats, size);
  displaySeats(seats, size);

  while (restart) {
    do {
      printf("\n");
      printf("\nPlease type 1 for \"first class\"\nPlease type 2 for \"economy\" ");
      printf("\n");
      scanf("%d", &seatType);
    } while (seatType != 1 && seatType != 2);

    seatno = assignSeat(seats, seatType);
    if (seatno != -1) {
      	boardPass(seatno);
	displaySeats(seats, size);
    } else {
      system("cls");
      printf("Next flight leaves in 3 hours.\n");
      printf("\n");
      system("pause");
      return 0;
    }


    printf("\n\nWould you like another? [y/n] ");
    do {
      scanf("%c", &redo);
    } while (redo != 'y' && redo != 'Y' && redo != 'N' && redo != 'n');

    if (redo == 'Y' || redo == 'y') {
      	system("cls");
	restart = 1;
    } else {
      	restart = 0;
    }
  }
  return 0;
}

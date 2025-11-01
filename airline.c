#include <stdio.h>

int assignFirstClass(int *seats, int size);
int assignEconomy(int *seats, int size);


void initSeats(int*seats, int size){
	for(int i = 0; i < size; i++){
		*(seats + i)  = 0;
	}
	return;
}

void displaySeats(int *seats, int size){
	printf("\nFirst Class Section: \t");
	for (int i = 0; i < size / 2; i++){
		printf("[%d]", *(seats + i));
	}

	printf("\nEconomy Section: \t");

	for(int i = size / 2; i < size; i++){
		printf("[%d]", *(seats + i));
	}
	return;
}


int assignSeat(int *st, int seatType){
	int seatno;
	char choice;

if(seatType == 1){
	seatno = assignFirstClass(st, 10);
	if(seatno == -1){
		system("cls");
		printf("First class is full. Would you like to be placed to Economy? [Y/N]");
		printf("\n");
		do{
			scanf("%c", &choice);
		} while(choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N');

		if(choice == 'Y' || choice == 'y'){
			seatno = assignEconomy(st, 10);
		}
	}
}

else if(seatType == 2){
	seatno = assignEconomy(st, 10);
	if(seatno == 1){
		system("cls");
		printf("Economy class is full. Would you like to be placed to First Class? [Y/N] ");
		printf("\n");
		do{
			scanf(" %c", &choice);
		} while ( choice != 'Y' && choice != 'y' && choice != 'N' && choice !='n');

		if(choice == 'Y' || choice == 'y'){
			seatno = assignFirstClass(st, 10);
		}
	}
}
return seatno;
}


int assignFirstClass(int *seats, int size){
	for(int i = 0; i < size / 2; i++){
		if(*(seats +i) == 0){
			*(seats + i) = 1;
			return i + 1;
		}
	}
	return -1;
}

int assignEconomy(int *seats, int size){
	for(int i = size / 2; i < size; i++){
		if(*(seats + i) == 0){
		*(seats + i) = 1;
		return i + 1;
		}
	}
	return -1;
}

void boardPass(int seat){
	printf("\n--------------------------\n");
	printf("| Boarding Pass          |\n");
	if(seat < 5){
		printf("| First Class Section    |\n");
		printf("| Seat #%d                |\n", seat);
	}else{
		printf("| Economy Section        |\n");
		printf("| Seat #%d                |\n", seat);
	}
	printf("--------------------------\n");
}

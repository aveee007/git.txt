#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct // global variables and composite data type are declared
{
	char name[50]; // username
	int bus_num;
	int num_of_seats;
} pd;					// variable of the structure
void reservation(void); // list of function prototypes
void viewdetails(void);
void printticket(char name[], int, int, float);
void specificbus(int);
float charge(int, int);
void login();
int main()

{
	system("cls");
	system("COLOR 0A");

	printf("\v\v\v\v");

	printf("\t\t\t\t=================================================\n");
	printf("\t\t\t\t|                                               |\n");
	printf("\t\t\t\t| --------------------------------------------- |\n");
	printf("\t\t\t\t|             COE TRAVEL AND TOURISM            |\n");
	printf("\t\t\t\t|   				                |\n");
	printf("\t\t\t\t|                                               |\n");
	printf("\t\t\t\t|  Book Your Tickets At The Cheapest PRICE      |\n");
	printf("\t\t\t\t| --------------------------------------------- |\n");
	printf("\t\t\t\t|                                               |\n");
	printf("\t\t\t\t|                                               |\n");
	printf("\t\t\t\t|                                               |\n");
	printf("\t\t\t\t=================================================\n\n\n");

	system("pause");
	system("cls");
	login();
	int menu_choice, choice_return;
start:
	system("cls");

	printf("\v\v\v\v\v\v");
	printf("\t\t\t\t\t\t BUS RESERVATION SYSTEM \v\v");
	printf("\t\t\t\t\t     =================================  \v\v");
	printf("\t\t\t\t\t\t   1>> Reserve A Ticket\v\v");
	printf("\t\t\t\t\t\t  ------------------------  \v\v");
	printf("\t\t\t\t\t\t 2>> View All Available Bus\v\v");
	printf("\t\t\t\t\t\t  ------------------------  \v\v");
	printf("\t\t\t\t\t\t   3>> Exit\v\v");
	scanf("%d", &menu_choice);
	switch (menu_choice)
	{
	case 1:
		reservation();
		break;
	case 2:
		viewdetails();
		system("pause");
		;
		break;
	case 3:
		return (0);
	default:
		printf("\nInvalid choice");
	}
	goto start;
	return (0);
}

void viewdetails(void)
{
	system("cls");
	printf("\t\t---------------------------------------------------------------------------------------");
	printf("\nBus.No \t\tName \t\tDestinations  \t\t  Charges  \t\tTime\n");
	printf("/t---------------------------------------------------------------------------------------");
	printf("\n1001\tSajha Travels     \tKathmandu To Chitwan     \tRs.2500  \t9:00 PM");
	printf("\n1002\tKaskit Travels     \tKathmandu To Pokhara     \tRs.3000  \t12:00 PM");
	printf("\n1003\tNarsimha Travels    \tKathmandu To Dang   	  \tRs.3500   \t8:00 PM");
	printf("\n1004\tKasa Deluxe         \tKathmandu To Birgunj     \tRs.5000   \t11:00 PM");
}

void reservation(void)
{
	char confirm;
	int i = 0;
	float charges;
	pd passdetails;
	FILE *fp;
	fp = fopen("seats_reserved.txt", "a");
	system("cls");

	 

	printf("\v\v\v  Enter Your Name:> ");
	fflush(stdin);
	gets(passdetails.name);
	printf("\v\v Note - Max seat is 9");
	printf("\v\v\v  Enter Number of seats:> ");
	scanf("%d", &passdetails.num_of_seats);
	if (passdetails.num_of_seats >= 9)
	{
		printf("\v\v\v  Max number of seats");
		
	}
	else{
	system("pause");
	}
	system("cls");
	viewdetails();
	printf("\n\nEnter bus number:> ");
start1:
	scanf("%d", &passdetails.bus_num);
	if (passdetails.bus_num >= 1001 && passdetails.bus_num <= 1004)
	{
		charges = charge(passdetails.bus_num, passdetails.num_of_seats);
		printticket(passdetails.name, passdetails.num_of_seats, passdetails.bus_num, charges);
	}
	else
	{
		printf("\nInvalid bus Number! Enter again--> ");
		goto start1;
	}

	printf("\n\nConfirm Ticket (y/n):>");
start:
	scanf(" %c", &confirm);
	if (confirm == 'y')
	{
		fprintf(fp, "%s\t\t%d\t\t%d\t\t%.2f\n", &passdetails.name, passdetails.num_of_seats, passdetails.bus_num, charges);
		printf("==================");
		printf("\n Reservation Done\n");
		printf("==================");
		printf("\nPress any key to go back to Main menu");
	}
	else
	{
		if (confirm == 'n')
		{
			printf("\nReservation Not Done!\nPress any key to go back to  Main menu!");
		}
		else
		{
			printf("\nInvalid choice entered! Enter again-----> ");
			goto start;
		}
	}
	fclose(fp);
	system("pause");
}

float charge(int bus_num, int num_of_seats)
{

	if (bus_num == 1001)
	{
		return (2500 * num_of_seats);
	}
	if (bus_num == 1002)
	{
		return (3000 * num_of_seats);
	}
	if (bus_num == 1003)
	{
		return (3500 * num_of_seats);
	}
	if (bus_num == 1004)
	{
		return (5000 * num_of_seats);
	}
}

void printticket(char name[], int num_of_seats, int bus_num, float charges)
{

	system("cls");
	printf("-------------------\n");
	printf("\tTICKET\n");
	printf("-------------------\n\n");
	printf("\nName:%s", name);
	
	printf("\nNumber Of Seats:\t%d", num_of_seats);
	printf("\nbus Number:\t\t%d", bus_num);
	specificbus(bus_num);
	printf("\nCharges:\t\t%.2f", charges);
}

void specificbus(int bus_num)
{

	if (bus_num == 1001)
	{
		printf("\nbus:\t\t\tSajha Travels ");
		printf("\nDestination:\t\tKathmandu To Chitwan ");
		printf("\nDeparture:\t\t9pm");
	}
	if (bus_num == 1002)
	{
		printf("\nbus:\t\t\tKaskit Travels ");
		printf("\nDestination:\t\tKathmandu To Pokhara");
		printf("\nDeparture:\t\t12pm");
	}
	if (bus_num == 1003)
	{
		printf("\nbus:\t\t\tNarsimha Travels  ");
		printf("\nDestination:\t\tKathmandu To Dang");
		printf("\nDeparture:\t\t8pm");
	}
	if (bus_num == 1004)
	{
		printf("\nbus:\t\t\tKasa Deluxe   ");
		printf("\nDestination:\t\t Kathmandu To Birgunj");
		printf("\nDeparture:\t\t11pm");
	}
}

void login()
{
	int a = 0, i = 0;
	char uname[10], c = ' ';
	char pword[10], code[10];
	do
	{
		printf("\v\v\v");
		printf("\t ===============  Please enter your username and password  ===========================   ");
		printf("\v\v\v\v");
		printf("\t\t\t                     USERNAME: ");
		scanf("%s", &uname);
		printf("\v\v");
		printf("\t\t\t                     PASSWORD: ");
		scanf("%s", &pword);

		if (strcmp(uname, "admin") == 0 && strcmp(pword, "admin") == 0)
		{
			system("pause");
			break;
		}
		else
		{
			printf("\t\t    Please check your username and password before trying again");
			a++;

			system("pause");
			system("cls");
		}
	} while (a <= 2);
	if (a > 2)
	{
		printf("\v\v\v\v");
		printf("\t\t\t\t\t\t  TRY AGAIN AFTER 10 MINUTES");

		system("pause");
	}
	system("cls");
}
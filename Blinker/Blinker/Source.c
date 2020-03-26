#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#define HAVE_STRUCT_TIMESPEC
#include <pthread.h>

void* ReadInput(void* pt)
{
	char* ch = (char*)pt;
	printf("Character ch is %c\n", *ch);
	*ch = getch();
	printf("Character ch is now %c\n", *ch);

	return NULL;
}

int main()
{
	int numberOfBlinks = 0;
	char ch = 'A';

	pthread_t inputThread;

	while ('c' != ch)
	{
		pthread_create(&inputThread, NULL, ReadInput, &ch);

		printf("ON\n");
		Sleep(1000);
		system("cls");
		printf("OFF\n");
		Sleep(1000);
		system("cls");

		numberOfBlinks++;
		printf("character in main is %c\n", ch);
	}

	printf("Hit cancel.\n");
	printf("Number of blinks: %d\n", numberOfBlinks);


	return 0;
}
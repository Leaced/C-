#include<conio.h>
#include<iostream>
#include<sstream>
#include<new>
#include <stdio.h>

//In Zusammenarbeit mit Nils Werner

//Zwei verschiedene natürliche Zahlen,
//von denen wechselseitig jeweils eine Zahl gleich der Summe der echten Teiler der anderen Zahl ist,
//bilden ein Paar befreundeter Zahlen.

int divSum(int number);
void program();

int main()
{
	printf("Gib ein Limit ein: ");
	
	program();
	
	printf("\n\nProgrammende!");
	
	getch();
	return(0);
}

int divSum(int number)
{
	int sum = 0;
	for (int idx = 1; idx*2 <= number; idx++) if(number%idx==0) sum += idx;
	return (sum);	
}

void program()
{
	unsigned long long limit = 0;
	std::string input;
	
	do
	{
		getline(std::cin, input);
		std::stringstream(input)>>limit;
		if(limit>=ULLONG_MAX || limit<0) printf("Error: Dieses Limit ist nicht m\x94glich. Gib ein anderes Limit ein: ");
	}while(limit>=ULLONG_MAX || limit<0);
	
	try
	{
		unsigned long long *number = new unsigned long long[limit+1];
		
		printf("befreundete Zahlen sind:\n");
		
		for (int idx = 220; idx<= limit; idx++)
		{
			number[idx] = divSum(idx);
			if(idx > number[idx]) if (idx==number[number[idx]]) std::cout << idx << "	und	" << number[idx] << "\n";
		}
		
		delete[] number;
	}
	catch(std::bad_alloc& ba)
	{
		printf("Error: Es konnte kein Array dieser Gr\x94\xE1 \be erstellt werden. Gib ein anderes Limit ein: ");
		program();
	}
	catch(std::exception& e)
	{
		printf("Error: Beim Erstellen des Arrays ist ein unbekannter Fehler aufgetreten. Gib ein anderes Limit ein: ");
		program();
	}
}

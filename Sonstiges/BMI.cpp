#include<iostream>
#include<string>
#include<sstream>

//Der Body-Mass-Index (BMI) � auch K�rpermasseindex (KMI), K�rpermassenzahl (KMZ) oder Quetelet-Kaup-Index � ist eine Ma�zahl f�r die Bewertung des K�rpergewichts eines Menschen in Relation zu seiner K�rpergr��e.

int main()
{
	long double height, weight;
	std::string input;
	
	std::cout<<"Gib deine Gr\x94\xE1 \be in metern ein: ";
	getline(std::cin,input);
	std::stringstream(input)>>height;
	
	if(height<=0)
	{
		std::cout<<"ERROR: Die eingegebene Gr\x94\xE1 \be ist nicht m\x94glich.";
		return(1);
	}
	
	std::cout<<"...und jetzt dein Gewicht: ";
	getline(std::cin,input);
	std::stringstream(input)>>weight;
	
	if(weight<=0)
	{
		std::cout<<"ERROR: Das eingegebene Gewicht ist nicht m\x94glich.";
		return(1);
	}
	
	std::cout<<"\nDein BMI ist: "<<weight/(height*height);
	
	getchar();
	return(0);
}

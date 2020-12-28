#include <iostream>
#include "Fraction.h"
#include <conio.h>
#include <sstream>
#include "CalculateFraction.h"
#include "List.h"
#include "MixedFraction.h"
#include <queue>
#include <ctime>
#include "CreatingElements.h"
#include <map>

typedef std::vector<Fraction> TFrVector; //typegef to vector of class Fraction
typedef std::vector<CalculateFraction> CalcVector;
typedef std::vector<MixedFraction> MixedVector;


void RunLabEight()
{
	queue<int> myIntQueue;

	std::cout << "int queue " << endl;

	int start, result;

	start = clock();

	for (int i = 0; i < 10000; i++)  myIntQueue.push(i);//добавление 10000 элементов

	result = clock() - start;
	std::cout << "Creating time: " << result << endl;

	start = clock();

	for (int i = 1; i < 10000; i++) myIntQueue.pop();

	result = clock() - start;
	std::cout << "Deleting time: " << result << endl;
	
	queue<Fraction> myQueue;

	std::cout << endl << "Fraction Queue" << endl;
	
	start = clock();
	
	CreatingElements::CreateData(myQueue); //добавление 10000 элементов

	result = clock() - start;
	std::cout << "Creating time: " << result << endl;
	
	start = clock();

	for (int i = 1; i < 10000; i++) myQueue.pop();
	
	result = clock() - start;
	std::cout << "Deleting time: " << result << endl;

	std::cout << endl << "int int map" << endl;

	map<int, int> myIntMap;

	start = clock();

	for (int i = 0; i < 10000; i++) myIntMap.insert(make_pair(i, 10000 - i)); //добавление 10000 элементов

	result = clock() - start;
	std::cout << "Creating time: " << result << endl;

	map<int, int> ::iterator it;

	start = clock();

	it = myIntMap.find(10001);

	result = clock() - start;
	std::cout << "Searching time: " << result << endl;

	start = clock();
	for (int i = 1; i < 10000; i++) myIntMap.erase(i);
	result = clock() - start;
	std::cout << "Deleting time: " << result << endl;

	std::cout << endl << "int Fraction map" << endl;
		
	map<int,Fraction> myMap;

	start = clock();

	CreatingElements::CreateData(myMap); //добавление 10000 элементов

	result = clock() - start;
	std::cout << "Creating time: " << result << endl;

	map<int, Fraction> ::iterator it2;

	start = clock();
	
	it2 = myMap.find(10001);

	result = clock() - start;
	std::cout << "Searching time: " << result << endl;

	start = clock();
	for (int i = 1; i < 10000; i++) myMap.erase(i);
	result = clock() - start;
	std::cout << "Deleting time: " << result << endl;
	
}

int main()
{
	
	TFrVector v = {									//creating Fraction vector
		Fraction::Create(1, 2),
		Fraction::Create(3, 4),
		Fraction::Create(526, 736),
		Fraction::Create(0, 57),
		Fraction::Create(45, 6),
		Fraction::Create(7, 9),
		Fraction::Create(25, 4),
		Fraction::Create(2147483640, 2147483642),
		Fraction::Create(2147400640, 2147480042),
		Fraction::Create(-2147400640, 2147480042)
	};

	CalcVector calcFr(4);
	
	calcFr[0];
	calcFr[1] = CalculateFraction(v[1]);
	calcFr[2] = CalculateFraction(v[2]);
	calcFr[3] = CalculateFraction::CreateCalculate(2, 3);

	MixedVector mixFr(6);
	
	mixFr[0];
	mixFr[1] = MixedFraction(v[0]);
	mixFr[2] = MixedFraction(v[1]);
	mixFr[3] = MixedFraction::CreateMixedFraction(2, 3, 0);
	mixFr[4] = MixedFraction::CreateMixedFraction(6, 4, 4);
	mixFr[5] = MixedFraction(v[4]);

	//RunDemonstrationLabFive(v, calcFr, mixFr);

	RunLabEight();
	
	std::cout << std::endl << "Enter a symbol to finish" << std::endl;
	std::getchar();
}
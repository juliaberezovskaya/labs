#include <iostream>
#include "Fraction.h"
#include <conio.h>
#include <fstream>
#include <sstream>

typedef std::vector<Fraction> TFrVector; //typegef to vector of class Fraction

void PutInFile(const TFrVector& v, const std::string& fileName) // function puts vector of Fraction to text file
{
	std::ofstream file(fileName, std::ios_base::trunc);
	for(TFrVector::const_iterator iter = v.begin(); iter != v.end(); iter++)
	{
		file << *iter << std::endl; // operator << overloaded
	}
}

void PutInBinFile(const TFrVector& v, const std::string& fileName) // function puts vector of Fraction to bin file
{
	std::ofstream file(fileName, std::ios_base::trunc | std::ios_base::binary);
	for (TFrVector::const_iterator iter = v.begin(); iter != v.end(); iter++)
	{
		std::ostringstream ostr;
		ostr << *iter; // operator << overloaded
		size_t sz = ostr.str().size();
		file.write((char*)&sz, sizeof(sz));
		file.write(ostr.str().c_str(), sz);
	}
}

void ReadFromFile (TFrVector& v, const std::string& fileName) // function load data in vector from text file
{
	
	std::ifstream file(fileName);
	for (; !file.eof();)
	{
		Fraction f;
		file >> f; // operator >> overloaded
		v.push_back(f); 
	}
}

void ReadFromBinFile(TFrVector& v, const std::string& fileName) //function load data in vector from bin file
{
	std::ifstream file(fileName,std::ios_base::binary);
	if (!file.is_open()) return;	
		while (!file.eof())
	{
		size_t cnt;
		file.read((char*)&cnt, sizeof(cnt));
		std::vector<char> buf;
		buf.reserve(cnt);
		buf.resize(cnt, 0);

		file.read(&buf[0], cnt);
		std::string str(buf.begin(), buf.end());
		std::istringstream istr(str);
		
		Fraction f;
		istr >> f; // operator >> overloaded

		v.push_back(f);
	}

}

bool CheckResult(TFrVector vRes, TFrVector v)
{
	if (vRes.size() != v.size() && vRes.size() - 1 != v.size())
	{
		std::cout << "Numbers of elements in original and resultant vector are not match" << std::endl;
		return false;
	}
	for (int i = 0; i < v.size(); i++) 
		if (vRes[i].GetNumerator() != v[i].GetNumerator() ||
			vRes[i].GetDenominator() != v[i].GetDenominator())
		{
			std::cout << "One of original and resultund nominator or denominator are not match" << std::endl;
			return false;
		}
	std::cout << "The comparison was successful" << std::endl;
	return true;
}

void RunTests(TFrVector v, TFrVector vText, TFrVector vBin)
{
	std::cout << "Program will put preassigned vector of Fraction objects in text and binary files. " <<
		"Then they will be loaded in program from this files. Then vectors will be compared in tests." << std::endl;
	std::cout << "Test 1: comparing preassigned vector and loaded from text file vector" << std::endl;
	std::cout << "Test 1 result: ";
	if (CheckResult(vText,v)) std::cout << "SUCCESSED";
	else std::cout << "FAILED";
	std::cout << std::endl;
	std::cout << "Test 2: comparing preassigned vector and loaded from binary file vector" << std::endl;
	std::cout << "Test 2 result: ";
	if (CheckResult(vBin, v)) std::cout << "SUCCESSED";
	else std::cout << "FAILED";
	std::cout << std::endl;
	std::cin.get();
}

int main()
{
	
	TFrVector v = {									//creating Fraction vector
		Fraction::Create(1, 2),
		Fraction::Create(3, 4),
		Fraction::Create(526, 736),
		Fraction::Create(0, 57),
		Fraction::Create(214748360, 2147483642),
		Fraction::Create(21474830, 17),
		Fraction::Create(21474840, 2147483642),
	};

	const std::string fileName = "text_file";
	const std::string binFileName = "bin_file";

	PutInFile(v, fileName);
	PutInBinFile(v, binFileName);

	TFrVector vCheck;
	TFrVector vCheckBin;

	ReadFromFile(vCheck, fileName);
	ReadFromBinFile(vCheckBin, binFileName);

	RunTests(v, vCheck, vCheckBin);
	
	std::cout << "Enter a symbol to finish" << std::endl;
	std::getchar();
}
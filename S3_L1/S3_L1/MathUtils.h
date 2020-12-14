#pragma once
class MathUtils
{
public:
	static int FindNod(int d1, int d2);
	static int FindNok(int d1, int d2);
	static int FindWholePart(int num, int den);
	static int FindNewNumerator(int num, int den);
	static void PutInPlaces(int& num, int& den, int& whole);
	static int ChangeWholePartInSimpleNumerator(int num, int den, int whole);
};
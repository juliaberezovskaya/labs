#include <iostream>
#include "CppUnitTest.h"
#include "../S3_L1/Fraction.h"
#include "../S3_L1/MixedFraction.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace S3L1test
{
	TEST_CLASS(S3L1test)
	{
	public:
		
		TEST_METHOD(ConstructorsTest)
		{
			Fraction defaultValue;
			Assert::AreEqual(0, defaultValue.GetNumerator());
			Assert::AreEqual(1, defaultValue.GetDenominator());
			Fraction myObj = Fraction::Create(1, 2);
			Assert::AreEqual(1, myObj.GetNumerator());
			Assert::AreEqual(2, myObj.GetDenominator());
			Fraction secondObj(myObj);
			Assert::AreEqual(myObj.GetDenominator(), secondObj.GetDenominator());
			Assert::AreEqual(myObj.GetNumerator(), secondObj.GetNumerator());
		}
		TEST_METHOD(OperationsTest)
		{
			Fraction myObj1 = Fraction::Create(1,2);
			Fraction myObj2 = Fraction::Create(1,2);

			Fraction myObjRes = myObj1.Sum(myObj2);
			Assert::AreEqual(1, myObjRes.GetNumerator(), L"Test Numerator");
			Assert::AreEqual(1, myObjRes.GetDenominator(), L"Test Denominator");

			Fraction myObjSub = myObj1.Sub(myObj2);
			Assert::AreEqual(0, myObjSub.GetNumerator());
			Assert::AreEqual(2, myObjSub.GetDenominator());

			Fraction myObjMul = myObj1.Mul(myObj2);
			Assert::AreEqual(1, myObjMul.GetNumerator());
			Assert::AreEqual(4, myObjMul.GetDenominator());

			Fraction myObjDiv = myObj1.Div(myObj2);
			Assert::AreEqual(1, myObjDiv.GetNumerator());
			Assert::AreEqual(1, myObjDiv.GetDenominator());
		}

		TEST_METHOD(OutputTest)
		{
			auto myObj = Fraction::Create(1, 2);

			std::ostringstream ostr;
			ostr << myObj;
			Assert::AreEqual(std::string("1/2"), ostr.str());
		}
		
		TEST_METHOD(SumTest)
		{
			MixedFraction mix = MixedFraction::CreateMixedFraction(1, 4, 0);
			Fraction sim = Fraction::Create(1, 4);

			mix = mix.Fraction::Sum(sim);
			
			Assert::AreEqual(1, mix.GetNumerator());
			Assert::AreEqual(2, mix.GetDenominator());
			Assert::AreEqual(0, mix.GetWhole());
		}
	};
}

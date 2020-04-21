#include "pch.h"
#include "../Complex.h"
//#include "gtest/"
namespace Complex_arithmatic_basic_tests
{
	TEST(Complex_Arithmatics, addition) {
		Complex__arithmatic::Complex<>a(3, 4), b(5, 6), res;
		res = a + b;
		EXPECT_EQ(res.Real(), 8);
		EXPECT_EQ(res.Imaj(), 10);
	}
	TEST(Complex_Arithmatics, subtraction) {
		Complex__arithmatic::Complex<>a(3, 4), b(5, 6), res;
		res = a - b;
		EXPECT_EQ(res.Real(), -2);
		EXPECT_EQ(res.Imaj(), -2);
	}
	TEST(Complex_Arithmatics, conjugate) {
		Complex__arithmatic::Complex<>a(3, 4), b(-5,4 ), res;
		b.Conj();
		res = a + b;
		EXPECT_EQ(res.Real(), -2);
		EXPECT_EQ(res.Imaj(), 0);
	}
	TEST(Complex_Arithmatics, conjugateAs_sub) {
		Complex__arithmatic::Complex<>a(3, 4), b(3, 6), res;
		b.Conj_As(a);
		res = a - b;
		EXPECT_EQ(res.Real(), 0);
		EXPECT_EQ(res.Imaj(), 8);
	}
	TEST(Complex_Arithmatics, multiply) {
		Complex__arithmatic::Complex<>a(3, 4), b(5, 6), res;
		res = a * b;
		EXPECT_EQ(res.Real(), -9);
		EXPECT_EQ(res.Imaj(), 38);
	}
	TEST(Complex_Arithmatics, divide) {
		Complex__arithmatic::Complex<>a(3, 4), b(5, 6), res;
		res = a / b;
		EXPECT_NEAR(res.Real(), 0.639344,1E-6);
		EXPECT_NEAR(res.Imaj(), 0.032787,1E-6);
	}
}
int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
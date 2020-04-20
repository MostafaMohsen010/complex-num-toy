#pragma once
#include <type_traits>
/// <summary>
/// @description complex class implementation
/// </summary>
namespace Complex__arithmatic {
	template<typename Number = double>
		//requires regular
	class Complex
	{
		Number real, imaj;


	public:
		Complex(const Number& real, const Number& imaj) :real{ real }, imaj{ imaj } {/*static_assert(std::is_arithmetic<Number>, "Complex Must be of arithmatic type");*/}
		Complex() :real{ 0 }, imaj{ 0 }{}
		Complex(const Number& real) :real{ real } {}

		Number Real()const { return real; }
		void Real(Number re) { real = re; }
		Number Imaj()const { return imaj; }
		void Imaj(Number im) { imaj = im; }
		//------------------ Arithmatic operations -----------------------------------------------
		Complex& operator+=(Complex z) { real += z.real; imaj += z.imaj; return *this; }
		Complex& operator-=(Complex z) { real -= z.real; imaj -= z.imaj; return *this; }
		Complex& operator*=(Complex z)
		{ 
			Number old_re = real;
			real = real * z.real - imaj * z.imaj;
			imaj = old_re * z.imaj + imaj * z.real;
			return *this; 
		}
		Complex& operator/=(Complex z)
		{
			if (std::abs(z.real) - std::abs(z.imaj))
			{
				Number old_re = real;
				Number den = z.real * z.real + z.imaj * z.imaj;
				real = (real * z.real + imaj * z.imaj)/den;
				imaj = (imaj * z.real - old_re * z.imaj)/den;
				return *this;
			}
			real = imaj = INFINITY;
			return *this;
		}
	
		Complex& Conj() { imaj *= -1; return *this; }
		Complex& Conj_As(Complex z) { imaj = -z.imaj; return *this; }
	};
	template<typename Number>
	Complex<Number> operator+(Complex<Number> U, Complex<Number> V) { return U += V; }
	template<typename Number>
	Complex<Number> operator-(Complex<Number> U, Complex<Number> V) { return U -= V; }
	template<typename Number>
	Complex<Number> operator*(Complex<Number> U, Complex<Number> V) { return U *= V; }
	template<typename Number>
	Complex<Number> operator/(Complex<Number> U, Complex<Number> V) { return U /= V; }
}


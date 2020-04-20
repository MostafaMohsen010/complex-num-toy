#include <iostream>
#include "Complex.h"
//import helloworld;

using Std_Complex = typename Complex__arithmatic::Complex<>;
int main()
{
	const Std_Complex mycomp  ;
	std::cout << "real : " << mycomp.Real() << "\t imaj:" << mycomp.Imaj() << "\n";
	Std_Complex a{ mycomp },c,d,e;
	Std_Complex b(4, 3);
	c = b;			// copy constructor working 
	Std_Complex c_bar = c.Conj_As(b);
	d = c + b;
	d *= b;
	e = c / d;
	return 0;
}

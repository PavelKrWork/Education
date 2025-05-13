/////////////////////////////////////////////////////////////////

// support : valgrind --tool=callgrind ./07.03.03

// support : valgrind --leak-check=yes ./07.03.03

/////////////////////////////////////////////////////////////////

#include <cassert>
#include <cmath>
#include <cstddef>
#include <iostream>

/////////////////////////////////////////////////////////////////

auto calculate(std::size_t size)
{
	auto x = 0.0;

	for (auto i = 0uz; i < size; ++i)
	{
		x += std::pow(std::sin(i), 2) + std::pow(std::cos(i), 2);
	}

	return x;
}

/////////////////////////////////////////////////////////////////

auto equal(double x, double y, double epsilon = 1e-6)
{
	return std::abs(x - y) < epsilon;
}

/////////////////////////////////////////////////////////////////

int main() 
{
	assert(equal(calculate(1'000), 1'000));

//  ----------------------------------------------------

	auto array = new int[5]{ 1, 2, 3, 4, 5 };

//  ----------------------------------------------------

	assert(array[5] == 0);

//  ----------------------------------------------------

//  delete[] array; // error

//  ----------------------------------------------------

	std::cout << "main : enter char : "; std::cin.get();
}

/////////////////////////////////////////////////////////////////
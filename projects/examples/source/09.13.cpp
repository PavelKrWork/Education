///////////////////////////////////////////////////////////////////////////////////////////

#include <iterator>
#include <vector>

///////////////////////////////////////////////////////////////////////////////////////////

int main()
{
	std::vector < int > vector = { 1, 2, 3, 4, 5 };

//  ---------------------------------------------------------------------------------------

	for (auto iterator = std::  begin(vector); iterator != std::  end(vector); ++iterator);

	for (auto iterator = std:: cbegin(vector); iterator != std:: cend(vector); ++iterator);

	for (auto iterator = std:: rbegin(vector); iterator != std:: rend(vector); ++iterator);

	for (auto iterator = std::crbegin(vector); iterator != std::crend(vector); ++iterator);
}

///////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////

// support : Boost.NumericConversion

////////////////////////////////////////////////////////

int main()
{
    double x = 1;

//  ----------------------------------------------------

//	[[maybe_unused]] int y1 = x; // bad

//	[[maybe_unused]] int y2 { x }; // error

//	[[maybe_unused]] int y3 { int(x) }; // bad

	[[maybe_unused]] int y4 { static_cast < int > (x) };
}

////////////////////////////////////////////////////////
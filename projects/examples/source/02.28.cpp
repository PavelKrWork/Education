///////////////////////////////////////////////////////////

int main()
{
    [[maybe_unused]] int array_1[5]{};

	[[maybe_unused]] int array_2[5]{ 1, 2, 3 };

	[[maybe_unused]] int array_3[ ]{ 1, 2, 3, 4, 5 };

//	[[maybe_unused]] int array_4[0]{}; // error
	
//	[[maybe_unused]] int array_5[1'000'000'000]{}; // error
}

///////////////////////////////////////////////////////////
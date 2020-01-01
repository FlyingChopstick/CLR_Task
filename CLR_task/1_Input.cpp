#include "pch.h"
#include "Functions.h"


void Input(const Int32 user_dimension, const Int32 max_dimension)
{
	Boolean is_set = false;
	String^ input_line;
	Char selector = Convert::ToChar("a");

	Console::WriteLine(L"----INPUT MENU----");
	
	/**
	if (is_set == true)
		Console::WriteLine(L" 1. Set custom dimension (currently {0})", user_dimension);
	else
		Console::WriteLine(L" 1. Set custom dimension");
	/**/
	Console::WriteLine(L" 1. Fill the matrix from the keyboard");
	Console::WriteLine(L" 2. Fill the matrix with random values");
	Console::WriteLine(L" 5. Return to the main menu");
	Console::WriteLine(L"Your selection: ");
	input_line = Console::ReadLine();
	selector = Convert::ToChar(input_line);

	switch (selector)
	{
	case '1': matrix_input(user_dimension, max_dimension); break;

	case '2': break;

	case '5': break;

	default: break;
	}
}
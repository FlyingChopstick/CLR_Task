#include "pch.h"


//MATRIX_DIMENSION(), used to obtain the custom matrix dimension
Int32 matrix_dimension(UInt32 max_dimension)
{
	Int32 user_dimension = 0;


	while (true)
	{
		String^ input_line;


		Console::WriteLine();
		Console::Write(L"Enter the size of the array (NxN, >0, max {0}): ", max_dimension);



		while (!user_dimension)
		{
			input_line = Console::ReadLine();
			//Console::WriteLine(L"{0}", input_line);//DEBUG

			try
			{
				user_dimension = Convert::ToInt32(input_line);
				//Console::WriteLine(L"{0}", user_dimension);//DEBUG
			}
			catch (...) { Console::WriteLine(L"Error: dimension cannot be a character, try again"); }
		}


		//input check
		if ((user_dimension <= 0) || (user_dimension > max_dimension))
			Console::WriteLine(L"Error: Array size must be >0 and <={0}, please try again.", max_dimension);
		else
			break;
	}

	return user_dimension;
}
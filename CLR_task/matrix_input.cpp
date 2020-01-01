#include "pch.h"



//MATRIX_INPUT(), handles the input of the matrix
array<Double, 2>^ matrix_input(Int32 dimension, const UInt32 max_dimension)
{
	array<Double, 2>^ user_matrix = gcnew array<Double, 2>(dimension, dimension);
	UInt32 position1 = 0, position2 = 0;
	String^ input_line;
	Double element;

	Console::WriteLine(L"---INPUT---");
	Console::WriteLine(L"Enter the elements: ");


	while (position1 < dimension)
	{
		Console::Write(L"Row #{0}: ", position1);
		while (position2 < dimension)
		{
			while (!element)
			{
				input_line = Console::ReadLine();
				//Console::WriteLine(L"{0}", input_line);//DEBUG

				//element = Convert::ToDouble(input_line);

				/**/
				try
				{
					element = Convert::ToDouble(input_line);
					//Console::WriteLine(L"{0}", user_dimension);//DEBUG
				}
				catch (...)
				{
					Console::WriteLine(L"Error reading the element: enter by one; element must be a number.");
				}
				/**/
			}

			user_matrix[position1, position2] = element;
			position2++;
		}
		Console::WriteLine();
		position1++;
	}
	return user_matrix;
}
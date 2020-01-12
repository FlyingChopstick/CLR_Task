#include "pch.h"



//MATRIX_INPUT(), handles the input of the matrix
array<Double, 2>^ matrix_input(Int32 dimension, const UInt32 max_dimension)
{
	array<Double, 2>^ user_matrix = gcnew array<Double, 2>(dimension, dimension);
	UInt32 position1 = 0, position2 = 0;

	String^ input_line;

	String^ number_string;
	Double element = 0;

	Int32 number_count = 0;
	Int32 target = dimension * dimension;
	Int32 length = 0;

	Int32 i = 0, j = 0;

	Console::WriteLine(L"---INPUT---");
	Console::WriteLine(L"Enter the elements: ");


	while (number_count < target)
	{
		input_line = Console::ReadLine();

		while (input_line[i] != 0)
		{
			if (input_line[i] == ' ')
			{
				j = i - 1;
				while ((input_line[j] != 0) && (input_line[j] != ' '))
				{
					j--;
				}
				length = i - j;

				number_string = input_line->Substring(j, length);
				element = Convert::ToDouble(number_string);

				Console::WriteLine(L"{0}", element);

				number_count++;
			}
		}
	}



	/**
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

	/**
				try
				{
					element = Convert::ToDouble(input_line);
					//Console::WriteLine(L"{0}", user_dimension);//DEBUG
				}
				catch (...)
				{
					Console::WriteLine(L"Error reading the element: enter by one; element must be a number.");
				}
				/**
			}

			user_matrix[position1, position2] = element;
			position2++;
		}
		Console::WriteLine();
		position1++;
	}
	/**/

	return user_matrix;
}
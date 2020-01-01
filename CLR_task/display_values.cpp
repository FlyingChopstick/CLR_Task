#include "pch.h"



//OUTPUT(), handles the output of the values
void display_values(array<Double, 2>^ t_matrix, array<Int32, 2>^ t_greater, array<Double>^ t_array, Int32 dimension)
{
	Console::WriteLine(L"----OUTPUT----");


	UInt32 i, j;
	UInt32 counter = 0;

	for (i = 0; i < dimension; i++)
	{
		for (j = 0; j < dimension; j++)
			Console::Write(L"{0}  ", t_matrix[i, j]);

		Console::WriteLine();
	}


	for (i = 0; i < dimension; i++)
	{
		j = 0;
		counter = 0;

		Console::Write(L" Elements greater then the element in the main diagonal: ", t_array[i]);

		while (j < dimension)
		{
			if (t_greater[i, j] == 1)
			{
				Console::Write(L"{0}  ", t_matrix[i, j]);
				counter++;
			}

			j++;
		}

		Console::WriteLine();
		Console::WriteLine(L"  There are {0} such elements.", counter);
	}

	Console::WriteLine();
}

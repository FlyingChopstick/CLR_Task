#include "pch.h"

//OUTPUT(), handles the output of the values
void Output(array<int, 2>^ t_matrix, array<int, 2>^ t_greater, array<int>^ t_array, const unsigned int dimension)
{
	unsigned int i, j;
	unsigned int counter = 0;

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

int main(array<System::String ^> ^args)
{
	//Array dimension (square matrix)
	const unsigned int dimension = 6;

	//Two matrices
	array<Int32, 2>^ M_matrix = gcnew array<Int32, 2>(dimension, dimension);
	array<Int32, 2>^ N_matrix = gcnew array<Int32, 2>(dimension, dimension);

	//
	array<Int32, 2>^ M_greater = gcnew array<Int32, 2>(dimension, dimension);
	array<Int32, 2>^ N_greater = gcnew array<Int32, 2>(dimension, dimension);

	//Two arrays
	array<Int32>^ C_array = gcnew array<Int32>(dimension);
	array<Int32>^ D_array = gcnew array<Int32>(dimension);

	//Random
	Random^ rnd = gcnew Random;

	unsigned int i, j;
	String^ input_line;
	char selector = Convert::ToChar("a");


	//Initial filling of the matrices
	for (i = 0; i < dimension; i++)
	{

		for (j = 0; j < dimension; j++)
		{
			M_matrix[i, j] = rnd->Next() / 10000000 - 100;
			N_matrix[i, j] = rnd->Next() / 10000000 - 100;

			M_greater[i, j] = 0;
			N_greater[i, j] = 0;
		}

		C_array[i] = M_matrix[i, i];
		D_array[i] = N_matrix[i, i];
	}


	//Counter for greater elements
	int temp_count = 0;

	//Parsing the matrices
	for (i = 0; i < dimension; i++)
	{
		for (j = 0; j < dimension; j++)
		{
			if (M_matrix[i, j] > C_array[i])
			{
				temp_count++;
				M_greater[i, j] = 1;
			}
		}
		C_array[i] = temp_count;
		temp_count = 0;

		for (j = 0; j < dimension; j++)
		{
			if (N_matrix[i, j] > D_array[i])
			{
				temp_count++;
				N_greater[i, j] = 1;
			}
		}
		D_array[i] = temp_count;
		temp_count = 0;
	}


	//Output menu
	while (selector != '5')
	{
		Console::WriteLine(L"----MENU----");
		Console::WriteLine(L" 1. First matrix");
		Console::WriteLine(L" 2. Second matrix");
		Console::WriteLine(L" 5. Exit");
		Console::Write(L"Your selection: ");
		input_line = Console::ReadLine();
		selector = Convert::ToChar(input_line);

		
		switch (selector)
		{
			//First matrix
		case '1':
		{
			Console::WriteLine();
			Output(M_matrix, M_greater, C_array, dimension);
			Console::WriteLine();
			break;
		}

			//Second matrix
		case '2':
		{
			Console::WriteLine();
			Output(N_matrix, N_greater, D_array, dimension);
			Console::WriteLine();
			break;
		}

		case '5': break;

		default: Console::WriteLine(L"Wrong input, try again.");

		}
	}



	Console::Write(L"Press any key to exit...");
	String^ stopper=Console::ReadLine();
    return 0;
}
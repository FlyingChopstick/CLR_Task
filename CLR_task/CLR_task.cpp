#include "pch.h"
#include "Functions.h"




int main(array<System::String ^> ^args)
{
	//Max matrix dimension
	const Int32 max_dimension = 10;


	Int32 i, j;
	String^ input_line;
	Char selector = 'a';
	Int32 user_dimension = -1;
	Boolean is_set = false;


	//Counter for greater elements
	Int32 temp_count = 0;

	//Random
	Random^ rnd = gcnew Random;

	//Main matrix
	array<Double, 2>^ M_matrix = gcnew array<Double, 2>(max_dimension, max_dimension);

	//Matrix dimension (square matrix)
	Int32 dimension = matrix_dimension(max_dimension);
		//Console::WriteLine(L"|{0}|", dimension);//DEBUG

	//Subarrays
	//positions of greater elements 
	array<Int32, 2>^ M_greater = gcnew array<Int32, 2>(dimension, dimension);
	//number of greater elements
	array<Double>^ C_array = gcnew array<Double>(dimension);


	while (selector != '5')
	{
		Console::WriteLine(L"--Setting the dimensions of the matrix--");
		//====
		if (is_set == true)
			Console::WriteLine(L" 1. Set custom dimension (currently {0})", user_dimension);
		else
			Console::WriteLine(L" 1. Set custom dimension");
		Console::WriteLine(L" 2. Use default dimension ({0})", max_dimension);
		Console::WriteLine(L" 5. Cancel and exit");
		//====
		Console::WriteLine(L"Your selection: ");
		input_line = Console::ReadLine();
		selector = Convert::ToChar(input_line);


		switch (selector)
		{
		case '1':
		{
			user_dimension = matrix_dimension(max_dimension);
			is_set = true;
			break;
		}

		case '2':
		{
			user_dimension = max_dimension;
			break;
		}

		//EXIT
		case '5': return 0;

		default:
			Console::WriteLine(L"Wrong input, try again"); break;
		}
	}
	
	
	//reset the selector
	selector = 'a';
	

	while (selector != '5')
	{
		Console::WriteLine(L"----MAIN MENU----");
		//====
		Console::WriteLine(L" 1. Matrix input");
		Console::WriteLine(L" 2. Print the values");
		Console::WriteLine(L" 5. Exit");
		//====
		Console::WriteLine(L"Your selection: ");
		input_line = Console::ReadLine();
		selector = Convert::ToChar(input_line);


		switch (selector)
		{
		case '1':
		{
			M_matrix = matrix_input(user_dimension, max_dimension);
			for (i = 0; i < dimension; i++)
			{
				for (j = 0; j < dimension; j++)
				{
					M_greater[i, j] = 0;
				}

				C_array[i] = M_matrix[i, i];
			}

			break;
		}

		case '2': 
		{
			user_dimension = max_dimension;
			break;
		}

		//EXIT
		case '5': return 0;

		default:
			Console::WriteLine(L"Wrong input, try again"); break;
		}




		//PARSE
		//DO NOT REMOVE UNTIL THE REWORK IS READY
		//Parsing the matrices
		for (i = 0; i < user_dimension; i++)
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
		}





		//Output menu
		while (selector != '5')
		{
			Console::WriteLine(L"----MENU----");
			Console::WriteLine(L" 1. matrix");
			Console::WriteLine(L" 5. Exit");
			Console::WriteLine(L"Your selection: ");
			input_line = Console::ReadLine();
			selector = Convert::ToChar(input_line);


			switch (selector)
			{
				//First matrix
			case '1':
			{
				Console::WriteLine();
				display_values(M_matrix, M_greater, C_array, dimension);
				Console::WriteLine();
				break;
			}

			case '5': break;

			default: Console::WriteLine(L"Wrong input, try again.");

			}
		}

	}

	Console::Write(L"Press Enter to exit...");
	String^ stopper = Console::ReadLine();
    return 0;
}
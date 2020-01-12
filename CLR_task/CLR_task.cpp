#include "pch.h"
#include "Functions.h"
#include "Matrix.h"

/**
ref class Matrix
{
public:
	array<Double, 2>^ M_matrix;
	array<Int32, 2>^ M_greater;

	Int32 user_dimension = -1;

	void def_greater()
	{
		Int32 i, j;

		for (i = 0; i < user_dimension; i++)
		{
			for (j = 0; j < user_dimension; j++)
			{
				this->M_greater[i, j] = 0;
			}
		}
	}
};
/**/

int main(array<System::String^>^ args)
{
	//Max matrix dimension
	const Int32 max_dimension = 10;

	//Matrix^ matrix;

	Int32 i, j;
	String^ input_line;
	Char selector = 'a';
	Int32 user_dimension = -1;
	Boolean is_set = false;

	//matrix.user_dimension = matrix_dimension(max_dimension);
	//matrix.M_matrix = gcnew array<Double, 2>(max_dimension, max_dimension);

	Matrix^ matrix = gcnew Matrix;

	//Counter for greater elements
	Int32 temp_count = 0;

	//Random
	Random^ rnd = gcnew Random;

	//Main matrix
	//array<Double, 2>^ M_matrix = gcnew array<Double, 2>(max_dimension, max_dimension);

	//Matrix dimension (square matrix)
	//user_dimension = matrix_dimension(max_dimension);
		//Console::WriteLine(L"|{0}|", dimension);//DEBUG


	//Subarrays
	//positions of greater elements 
	//array<Int32, 2>^ M_greater = gcnew array<Int32, 2>(user_dimension, user_dimension);
	//number of greater elements


	//matrix->Test_1();

	//stopper
	/**
	Console::Write(L"Press Enter to continue...");
	String^ stopper = Console::ReadLine();
	/**/

	while ((selector != '1') && (selector != '2') && (selector != '5'))
	{
		Console::WriteLine(L"--Setting the dimensions of the matrix--");
		//====
		//if (is_set == true)
			//Console::WriteLine(L" 1. Set custom dimension (currently {0})", matrix->user_dimension);
		//else
		Console::WriteLine(L" 1. Set custom dimension");
		Console::WriteLine(L" 2. Use default dimension ({0})", matrix->get_dim("default"));
		Console::WriteLine(L" 5. Cancel and exit");
		//====
		Console::WriteLine(L"Your selection: ");
		input_line = Console::ReadLine();
		selector = Convert::ToChar(input_line);


		switch (selector)
		{
		case '1':
		{
			matrix->set_dimension("user");

			//Int32 user_dimension = matrix_dimension(max_dimension);
			//Console::WriteLine(L"User dimension: {0}", user_dimension);
			/**
			matrix->user_dimension = temp_dim;
			matrix->M_matrix = gcnew array<Double, 2>(matrix->user_dimension, matrix->user_dimension);
			matrix->M_greater = gcnew array<Int32, 2>(user_dimension, user_dimension);
			matrix->def_greater();
			is_set = true;
			/**/
			break;
		}

		case '2':
		{
			matrix->set_dimension("default");

			/**
			matrix->user_dimension = max_dimension;
			matrix->M_matrix = gcnew array<Double, 2>(matrix->user_dimension, matrix->user_dimension);
			matrix->M_greater = gcnew array<Int32, 2>(user_dimension, user_dimension);
			matrix->def_greater();
			/**/
			break;
		}

		//EXIT
		case '5': return 0;

		default:
			Console::WriteLine(L"Wrong input, try again"); break;
		}
	}


	user_dimension = matrix->get_dim("user");

	//array<Double>^ C_array = gcnew array<Double>(user_dimension);

	//matrix.M_greater = gcnew array<Int32, 2>(user_dimension, user_dimension);

	//reset the selector
	selector = 'a';


	while (selector != '5')
	{
		Console::WriteLine(L"----MAIN MENU----");
		//====
		Console::WriteLine(L" 1. Matrix input");
		Console::WriteLine(L" 2. Print the values");
		Console::WriteLine(L" 3. Matrix output");
		Console::WriteLine(L" 5. Exit");
		//====
		Console::WriteLine(L"Your selection: ");

		while (true)
		{
			input_line = Console::ReadLine();
			//catch conversion errors
			try
			{
				selector = Convert::ToChar(input_line);
			}
			catch (...)
			{
				Console::WriteLine(L"Wrong input, try again.");
				//repeat input if the error was caught
				continue;
			}
			//continue to the next element if successful
			break;
		}

		switch (selector)
		{
		case '1':
		{
			String^ selector;
			if (matrix->get_state() == false)
				matrix->Input();
			else
			{
				Console::WriteLine("The matrix is already created, overwrite? (yes/no): ");
				
				while (true)
				{
					//catch conversion errors
					try
					{
						selector = Console::ReadLine();
					}
					catch (...)
					{
						Console::WriteLine(L"Wrong input, try again.");
						//repeat input if the error was caught
						continue;
					}

					if ((selector != "yes") && (selector != "no"))
					{
						Console::WriteLine(L"Wrong input, try again.");
						continue;
					}

					//continue to the next element if successful
					break;
				}

				if (selector == "yes")
					matrix->Input();
				else
					break;

				break;
			}


			


			/**
		//	matrix->M_matrix = matrix_input(matrix->user_dimension, max_dimension);
			for (i = 0; i < user_dimension; i++)
			{
				for (j = 0; j < user_dimension; j++)
				{
			//		matrix->M_greater[i, j] = 0;
				}

				//C_array[i] = matrix->M_matrix[i, i];
			}
			/**/

			break;
		}

		case '2':
		{
			if (matrix->get_state() == true)
			{
				matrix->parse_positions();
				matrix->display_greater();
			}
			else
				Console::WriteLine("The matrix is not created, you need to create it first.");

			break;
		}

		case '3':
		{
			if (matrix->get_state() == true)
				matrix->display_matrix();
			else
				Console::WriteLine("The matrix is not created, you need to create it first.");

			break;
		}

		//EXIT
		case '5': return 0;

		default:
			Console::WriteLine(L"Wrong input, try again"); break;
		}
	}



	//PARSE
	//DO NOT REMOVE UNTIL THE REWORK IS READY
	/**
	//Parsing the matrices
	for (i = 0; i < user_dimension; i++)
	{
		for (j = 0; j < user_dimension; j++)
		{
		//	if (matrix->M_matrix[i, j] > C_array[i])
			{
				temp_count++;
		//		matrix->M_greater[i, j] = 1;
			}
		}
		C_array[i] = temp_count;
		temp_count = 0;
	}
	/**/




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
			//	display_values(matrix->M_matrix, matrix->M_greater, C_array, user_dimension);
			Console::WriteLine();
			break;
		}

		case '5': break;

		default: Console::WriteLine(L"Wrong input, try again.");

		}
	}




	//stopper
	/**
	Console::Write(L"Press Enter to continue...");
	String^ stopper = Console::ReadLine();
	/**/
	return 0;
}
#include "pch.h"


array<Double, 2>^ Matrix_input(Int32 dimension, const UInt32 max_dimension)
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

			
		}
		Console::WriteLine();
		position1++;
	}
	return user_matrix;
}

//OUTPUT(), handles the output of the values
void Output(array<Double, 2>^ t_matrix, array<Int32, 2>^ t_greater, array<Double>^ t_array, Int32 dimension)
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

int main(array<System::String ^> ^args)
{
	//Max matrix dimension
	const Int32 max_dimension = 10;

	UInt32 i, j;
	String^ input_line;
	SByte selector = Convert::ToChar("a");


	//Random
	Random^ rnd = gcnew Random;

	//Main matrix
	array<Double, 2>^ M_matrix = gcnew array<Double, 2>(max_dimension, max_dimension);




	//Matrix dimension (square matrix)
	Int32 dimension = matrix_dimension(max_dimension);
		//Console::WriteLine(L"{0}", dimension);//DEBUG

	M_matrix = Matrix_input(dimension, max_dimension);
		Console::WriteLine(L"End of input");//DEBUG


	//Subarrays
	array<Int32, 2>^ M_greater = gcnew array<Int32, 2>(dimension, dimension);
	array<Double>^ C_array = gcnew array<Double>(dimension);

	//Two matrices
	//array<Int32, 2>^ N_matrix = gcnew array<Int32, 2>(dimension, dimension);
	//
	//array<Int32, 2>^ N_greater = gcnew array<Int32, 2>(dimension, dimension);
	//Two arrays
	//array<Int32>^ D_array = gcnew array<Int32>(dimension);





	//Initial filling of the matrices
	for (i = 0; i < dimension; i++)
	{

		for (j = 0; j < dimension; j++)
		{
			M_matrix[i, j] = rnd->Next() / 10000000 - 100;
			//N_matrix[i, j] = rnd->Next() / 10000000 - 100;

			M_greater[i, j] = 0;
			//N_greater[i, j] = 0;
		}

		C_array[i] = M_matrix[i, i];
		//D_array[i] = N_matrix[i, i];
	}


	//Counter for greater elements
	Int32 temp_count = 0;

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

		/**
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
		/**/
	}


	//Output menu
	while (selector != '5')
	{
		Console::WriteLine(L"----MENU----");
		Console::WriteLine(L" 1. First matrix");
		//Console::WriteLine(L" 2. Second matrix");
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
			Output(M_matrix, M_greater, C_array, dimension);
			Console::WriteLine();
			break;
		}

			//Second matrix
		/**
		case '2':
		{
			Console::WriteLine();
			Output(N_matrix, N_greater, D_array, dimension);
			Console::WriteLine();
			break;
		}
		/**/

		case '5': break;

		default: Console::WriteLine(L"Wrong input, try again.");

		}
	}



	Console::Write(L"Press Enter to exit...");
	String^ stopper = Console::ReadLine();
    return 0;
}
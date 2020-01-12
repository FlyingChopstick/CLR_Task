#pragma once
#include "pch.h"

ref class Matrix
{
public:
	//CONSTRUCTOR
	Matrix()
	{
		M_matrix = gcnew array<Double, 2>(2, 2);
		M_greater = gcnew array<Boolean, 2>(2, 2);
		//positions = gcnew array<Int32>(user_dimension);


		//sets M_greater to all 0
		for (i = 0; i < user_dimension; i++)
		{
			for (j = 0; j < user_dimension; j++)
			{
				M_greater[i, j] = false;
			}
		}
	}


	//INPUT(), handles the input
	void Input()
	{
		String^ input_line;
		Double element = 0;
		Int32 number_count = 0;		
		Int32 target = user_dimension * user_dimension;		
		Boolean error = false;

		//String^ number_string;
		//Int32 length = 0;

		Console::WriteLine(L"---INPUT---");
		Console::WriteLine(L"Enter {0} elements: ", target);


		for (i = 0; i < user_dimension; i++)
		{
			
			j = 0;
			while (j < user_dimension)
			{
				Console::Write(L"Element #[{0},{1}]: ", i, j);
				while (true)
				{
	
					input_line = Console::ReadLine();
					//catch conversion errors
					try
					{
						element = Convert::ToDouble(input_line);
					}
					catch (...)
					{
						Console::WriteLine(L"Error reading the element, try again.");
						//repeat input if the error was caught
						continue;
					}

					//continue to the next element if successful
					break;

					/**
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
					/**/
				}


				//Console::WriteLine(L"|{0}|", j);//DEBUG
				M_matrix[i, j] = element;
				j++;
				
				
			}
			//j = 0;
		}

		is_created = true;
	}

	//SET_DIMENSION(), sets the dimension ("user" - custom, "default" - default);
	void set_dimension(const String^ mode)
	{
		Int32 temp_dim = 0;
		String^ input_line;

		if (mode == "user")
		{
			while (true)
			{
				Console::WriteLine();
				Console::Write(L"Enter the size of the array (NxN, >0, max {0}): ", max_dimension);

				while (!temp_dim)
				{
					input_line = Console::ReadLine();
					//Console::WriteLine(L"{0}", input_line);//DEBUG

					try
					{
						temp_dim = Convert::ToInt32(input_line);
						//Console::WriteLine(L"{0}", user_dimension);//DEBUG
					}
					catch (...) { Console::WriteLine(L"Error: dimension cannot be a character, try again"); }
				}

				//input check
				if ((temp_dim <= 0) || (temp_dim > max_dimension))
					Console::WriteLine(L"Error: Array size must be >0 and <={0}, please try again.", max_dimension);
				else
					break;
			}
			user_dimension = temp_dim;
		}
		
		if (mode == "default")
			user_dimension = max_dimension;

		M_matrix = gcnew array<Double, 2>(user_dimension, user_dimension);
		M_greater = gcnew array<Boolean, 2>(user_dimension, user_dimension);
	}

	//PARSE_POSITIONS(), looks for values in lines greater then the main diagonal
	void parse_positions()
	{
		Int32 reference;
		//Parsing the matrices
		for (i = 0; i < user_dimension; i++)
		{
			reference = M_matrix[i, i];
			for (j = 0; j < user_dimension; j++)
			{
				if (M_matrix[i, j] > reference)
					M_greater[i, j] = true;
			}
		}
	}

	//DISPLAY_GREATER(), prints element greater then the main diag
	void const display_greater()
	{
		//state - greater elements in the row
		Boolean found = false;
		//local array for greater elements in rows
		array<Double>^ greater = gcnew array<Double>(user_dimension);
		//counts the greater elements
		Int32 count = 0;
		//output iterator;
		Int32 c;

		for (i = 0; i < user_dimension; i++)
		{
			found = false;
			count = 0;
			for (j = 0; j < user_dimension; j++)
			{
				if (M_greater[i, j] == true)
				{
					greater[count] = M_matrix[i, j];
					count++;
					found = true;
				}
			}

			if (found == true)
			{
				Console::Write(L"In the row #{0} there are {1} elements greater then the main diag: ", i, count);
				for (c = 0; c < count; c++)
				{
					Console::Write(L"|{0}| ", greater[c]);
				}
				Console::WriteLine();
			}
			else
				Console::WriteLine(L"All elements in row #{0} are lesser then the main diag", i);
		}


	}

	//GET_MAX_DIM(), returns dimension ("default" - max_dimension/"user" - user_)
	const Int32 const get_dim(const String^ mode)
	{
		if (mode == "default")
			return max_dimension;
		
		if (mode == "user")
			return user_dimension;		
	}

	//DISPLAY_MATRIX(), prints the matrix
	void const display_matrix()
	{
		Console::WriteLine(L"--MATRIX--");

		for (i = 0; i < user_dimension; i++)
		{
			for (j = 0; j < user_dimension; j++)
			{
				Console::Write(L"{0} ", M_matrix[i, j]);
			}
			Console::WriteLine();
		}

		Console::WriteLine(L"----------");
	}
	
	//GET_STATE(), returns is_created
	const Boolean get_state()
	{
		return is_created;
	}

	//DEBUG
	/**
	void Test_1()
	{
		Console::WriteLine(L"{0}", this->Test_value);
		Test_2();
		Console::WriteLine(L"{0}", this->Test_value);
	}
	/**/
private:
	//matrix max dimension const
	const Int32 max_dimension = 10;

	Int32 user_dimension = -1;

	//main matrix
	array<Double, 2>^ M_matrix;
	//matrix with the positions of the greater elements
	array<Boolean, 2>^ M_greater;

	Int32 i, j;

	Boolean is_created = false;



	//array<Int32>^ positions;

	//DEBUG
	/**
	Int32 Test_value = 0;
	void Test_2()
	{
		this->Test_value = 1;
	}
	/**/
};
#include "pch.h"



array<Int32>^ matrix_parse_positions(array<Double, 2>^& M_matrix, Int32 user_dimension, Int32 position)
{

	Int32 reference = M_matrix[position, position];
	Int32 i;

	array<Int32>^ positions = gcnew array<Int32>(user_dimension);

	//Parsing the matrices
	for (i = 0; i < user_dimension; i++)
	{

		if (M_matrix[position, i] > reference)
		{

			positions[i] = 1;
		}
		else
			positions[i] = 0;
	}

	return positions;
}
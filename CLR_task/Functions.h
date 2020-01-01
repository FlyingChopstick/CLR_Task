#pragma once
#include "pch.h"


void Input(const Int32 user_dimension, const Int32 max_dimension);

//MATRIX_INPUT(), handles the input of the matrix
array<Double, 2>^ matrix_input(Int32 dimension, const UInt32 max_dimension);
//OUTPUT(), handles the output of the values
void display_values(array<Double, 2>^ t_matrix, array<Int32, 2>^ t_greater, array<Double>^ t_array, Int32 dimension);


//MATRIX_DIMENSION(), used to obtain the custom matrix dimension
Int32 matrix_dimension(UInt32 max_dimension);
#include "shark/LinAlg/eigenvalues.h"

#define BOOST_TEST_MODULE LinAlg_eigensymm
#include <boost/test/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>

using namespace shark;

BOOST_AUTO_TEST_CASE( LinAlg_eigensymm )
{
	RealMatrix A(3, 3);   // input matrix
	RealMatrix x(3, 3);   // matrix for eigenvectors
	RealVector lambda(3); // vector for eigenvalues

	// Initialization values for input matrix:
	double bottom_triangle[9] =
		{
			7.,  0.,  0.,

			-2.,  6.,  0.,

			0., -2.,  0.
		};

	// Initializing matrices and vector:
	for (size_t curr_row = 0; curr_row < 3; curr_row++)
	{
		for (size_t curr_col = 0; curr_col < 3; curr_col++)
		{
			A(curr_row, curr_col) = bottom_triangle[curr_row*3+curr_col];
			x(curr_row, curr_col) = 0.;
		}
		lambda(curr_row) = 0.;
	}

	// Calculating eigenvalues and eigenvectors:
	eigensymm(A, x, lambda);// A is unchanged after the call

	// lines below are for self-testing this example, please ignore
	BOOST_CHECK_SMALL(lambda(0)- 8.74697,1.e-5);
}

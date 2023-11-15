#include "tmatrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length)
{
	ASSERT_NO_THROW(TMatrix<int> m(5));
}


TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
	ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
	TMatrix<int> m(5);

	ASSERT_NO_THROW(TMatrix<int> m1(m));
}


TEST(TMatrix, can_get_size)
{
	TMatrix<int> m(5);

	EXPECT_EQ(5, m.GetSize());
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	TMatrix<int> m(5);
	int i = 1;

	ASSERT_ANY_THROW(m[-1][0] = i);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	TMatrix<int> m(5);

	ASSERT_ANY_THROW(m[100][0] = 1);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
	TMatrix<int> m(5);
	ASSERT_NO_THROW(m = m);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
	TMatrix<int> m(5);
	TMatrix<int> m1(5);
	ASSERT_NO_THROW(m = m1);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
	int size1 = 1, size2 = 2;
	TMatrix<int> m(size1);
	TMatrix<int> m1(size2);

	m = m1;

	EXPECT_EQ(m.GetSize(), m1.GetSize());
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
	TMatrix<int> m(1);
	TMatrix<int> m1(2);

	EXPECT_NE(m, m1);
}
/*
TEST(TMatrix, can_add_matrices_with_equal_size)
{
	TMatrix<int> m(1);
	TMatrix<int> m1(1);

	m[0][0] = 1;
	m1[0][0] = 2;

	EXPECT_NO_THROW(m + m1);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
	TMatrix<int> m(1);
	TMatrix<int> m1(5);

	ASSERT_ANY_THROW(m + m1);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
	TMatrix<int> m(1);
	TMatrix<int> m1(1);

	m[0][0] = 1;
	m1[0][0] = 2;

	EXPECT_NO_THROW(m - m1);
}
*/
TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TMatrix<int> m(1);
	TMatrix<int> m1(5);

	ASSERT_ANY_THROW(m - m1);
}
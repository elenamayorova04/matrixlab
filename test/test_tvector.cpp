#include "tvector.h"

#include <gtest.h>

TEST(TVector, can_create_vector_with_positive_length)
{
	ASSERT_NO_THROW(TVector<int> vect(10));
}

TEST(TVector, throws_when_create_vector_with_negative_length)
{
	ASSERT_ANY_THROW(TVector<int> vect(-10));
}

TEST(TVector, can_create_copied_vector)
{
	TVector<int> vect(10);

	ASSERT_NO_THROW(TVector<int> newVect(vect));
}

TEST(TVector, can_set_and_get_element)
{
	TVector<int> vect(10);
	vect[0] = 1;

	EXPECT_EQ(1, vect[0]);
}

TEST(TVector, throws_when_set_element_with_negative_index)
{
	TVector<int> vect(1);
	ASSERT_ANY_THROW(vect[-1] = 2);
}

TEST(TVector, can_assign_vector_to_itself)
{
	TVector<int> vect(10);
	ASSERT_NO_THROW(vect = vect);
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
	TVector<int> vect1(5);
	TVector<int> vect2(5);
	ASSERT_NO_THROW(vect1 = vect2);
}

TEST(TVector, assign_operator_change_vector_size)
{
	int size1 = 1;
	int size2 = 2;
	TVector<int> vect1(size1);
	TVector<int> vect2(size2);

	vect1 = vect2;

	EXPECT_EQ(vect1.GetSize(), vect2.GetSize());
}

TEST(TVector, can_assign_vectors_of_different_size)
{
	TVector<int> vect1(2);
	TVector<int> vect2(1);

	vect2[0] = 1;

	ASSERT_NO_THROW(vect1 = vect2);
}

TEST(TVector, compare_equal_vectors_return_true)
{
	TVector<int> vect1(2);
	TVector<int> vect2(2);

	vect1[0] = 1; vect2[1] = 2;
	vect2[0] = 1; vect2[1] = 2;

	EXPECT_EQ(vect1, vect2);
}

TEST(TVector, compare_vector_with_itself_return_true)
{
	TVector<int> vect(2);

	vect[0] = 1; vect[1] = 2;

	EXPECT_EQ(vect, vect);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
	TVector<int> vect1(1);
	TVector<int> vect2(2);

	EXPECT_NE(vect1, vect2);
}

TEST(TVector, can_add_scalar_to_vector)
{
	TVector<int> vect(1);
	vect[0] = 1;

	EXPECT_NO_THROW(vect + 2);
}

TEST(TVector, can_subtract_scalar_from_vector)
{
	TVector<int> vect(1);
	vect[0] = 1;

	EXPECT_NO_THROW(vect - 2);
}

TEST(TVector, can_multiply_scalar_by_vector)
{
	TVector<int> vect(1);
	vect[0] = 1;

	EXPECT_NO_THROW(vect * 2);
}

TEST(TVector, can_add_vectors_with_equal_size)
{
	TVector<int> vect1(1);
	TVector<int> vect2(1);

	vect1[0] = 1;
	vect2[0] = 2;

	EXPECT_NO_THROW(vect1 + vect2);
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
	TVector<int> vect1(1);
	TVector<int> vect2(5);

	ASSERT_ANY_THROW(vect1 + vect2);
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
	TVector<int> vect1(1);
	TVector<int> vect2(1);

	vect1[0] = 1;
	vect2[0] = 2;

	EXPECT_NO_THROW(vect1 - vect2);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
	TVector<int> vect1(1);
	TVector<int> vect2(5);

	ASSERT_ANY_THROW(vect1 - vect2);
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
	TVector<int> vect1(1);
	TVector<int> vect2(1);

	vect1[0] = 1;
	vect2[0] = 2;

	EXPECT_NO_THROW(vect1 * vect2);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
	TVector<int> vect1(1);
	TVector<int> vect2(5);

	ASSERT_ANY_THROW(vect1 * vect2);
}
#include <ctest.h>
#include <proc.h>

CTEST(quadratic_equation_suite, discriminant_less_than_zero) {
	// Given
	const float a = 7;
	const float b = 2;
	const float c = 8;

	// When
	float x1, x2, d;
	int CountRoots;
	process(a, b, c, &d, &x1, &x2, &CountRoots);

	// Then
	const int expected_CountRoots = 0;
	const float expected_d = -220;
	ASSERT_DBL_NEAR(expected_d, d);
	ASSERT_EQUAL(expected_CountRoots, CountRoots);
}

CTEST(quadratic_equation_suite, discriminant_is_equal_to_zero) {
	//Given
	const float a = 1;
	const float b = 2;
	const float c = 1;

	// When
	float x1, x2, d;
	int CountRoots;
	process(a, b, c, &d, &x1, &x2, &CountRoots);

	// Then
	const float expected_x1 = -1;
	const float expected_d = 0;
	const int expected_CountRoots = 2;

	ASSERT_DBL_NEAR(expected_x1, x1);
	ASSERT_DBL_NEAR(expected_d, d);
	ASSERT_EQUAL(expected_CountRoots, CountRoots);
}

CTEST(quadratic_equation_suite, discriminant_all_coefficient_equal_to_zero) {
	// Given
	const float a = 0;
	const float b = 0;
	const float c = 0;

	// When
	float x1, x2, d;
	int CountRoots;
	process(a, b, c, &d, &x1, &x2, &CountRoots);

	// Then
	const int expected_CountRoots = -1;
	ASSERT_EQUAL(expected_CountRoots, CountRoots);
}

CTEST(quadratic_equation_suite, discriminant_is_greater_than_zero) {
	// Given
	const float a = 2;
	const float b = 5;
	const float c = 2;

	// When
	float x1, x2, d;
	int CountRoots;
	process(a, b, c, &d, &x1, &x2, &CountRoots);

	// Then
	const float expected_x1 = -0.5;
	const float expected_x2 = -2;
	const float expected_d = 9;
	const int expected_CountRoots = 2;

	ASSERT_DBL_NEAR(expected_x1, x1);
	ASSERT_DBL_NEAR(expected_x2, x2);
	ASSERT_DBL_NEAR(expected_d, d);
	ASSERT_EQUAL(expected_CountRoots, CountRoots);
}


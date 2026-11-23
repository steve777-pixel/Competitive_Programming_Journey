#include <gtest/gtest.h>
#include "stage_0/introduction.h"

TEST(Add, Basic) { EXPECT_EQ(add(2, 3), 5); }
TEST(Add, Large) { EXPECT_EQ(add(1000000000LL, 1000000000LL), 2000000000LL); }

TEST(AbsoluteValue, Positive) { EXPECT_EQ(5, absoluteVal(5)); }
TEST(AbsoluteValue, Negative) { EXPECT_EQ(5, absoluteVal(-5)); }

// ======================================
// FACTORIAL MODULO 
// ======================================

struct FactorialData {int input_n; long long expected_modulo;};
class FactorialModuloTest : public ::testing::TestWithParam<FactorialData> {};

TEST_P(FactorialModuloTest, CheckModuloOfFactorials){
    const auto& data = GetParam();

    EXPECT_EQ(data.expected_modulo, factorialMod(data.input_n));
}

INSTANTIATE_TEST_SUITE_P(FactorialCases, FactorialModuloTest, ::testing::Values(
    FactorialData{10, 3628800},
    FactorialData{20, 146326063},
    FactorialData{-1, -1},
    FactorialData{2'000'000'007, 0},
    FactorialData{6, 720}
));

// ======================================
// SUM OF INTEGERS UPTO N 
// ======================================

struct IntegerSumData {int input_n; long long expected_sum;};
class IntegerSumTest : public ::testing::TestWithParam<IntegerSumData> {};

TEST_P(IntegerSumTest, CheckSumUptoN){
    const auto& data = GetParam();

    EXPECT_EQ(data.expected_sum, sumOfIntegersUptoN(data.input_n));
}

INSTANTIATE_TEST_SUITE_P(SumOfNCases, IntegerSumTest, ::testing::Values(
    IntegerSumData{12, 78},
    IntegerSumData{1, 1},
    IntegerSumData{10'000, 50'005'000},
    IntegerSumData{100, 5'050},
    IntegerSumData{-1, 0}
));

// ======================================
// SUM OF SQUARES UPTO N 
// ======================================

struct SquareSumData {int input_n; long long expected_sum;};
class SquareSumTest : public ::testing::TestWithParam<SquareSumData> {};

TEST_P(SquareSumTest, CheckSumUptoN){
    const auto& data = GetParam();

    EXPECT_EQ(data.expected_sum, sumOfSquaresUptoN(data.input_n));
}

INSTANTIATE_TEST_SUITE_P(SumOfSquaresCases, SquareSumTest, ::testing::Values(
    SquareSumData{12, 650},
    SquareSumData{1, 1},
    SquareSumData{10'000, 333'383'335'000},
    SquareSumData{100, 338'350},
    SquareSumData{-1, 0}
));

// ======================================
// FINITE GEOMETRIC SERIES SUM
// ======================================

struct FiniteGeometricSeriesData {int input_first_term; int input_ratio; int input_n; long long expected_sum;};
class FiniteGeometricSeriesTest : public ::testing::TestWithParam<FiniteGeometricSeriesData> {};

TEST_P(FiniteGeometricSeriesTest, CheckSumUptoN){
    const auto& data = GetParam();

    EXPECT_EQ(data.expected_sum ,sumOfFiniteGeometricSeries(data.input_first_term, data.input_ratio, data.input_n));
}

INSTANTIATE_TEST_SUITE_P(FiniteGeometricSequenceCases, FiniteGeometricSeriesTest, ::testing::Values(
    FiniteGeometricSeriesData{2, 2, 10, 2'046LL},
    FiniteGeometricSeriesData{2, 2, 0, 0LL},
    FiniteGeometricSeriesData{-2, 2, 10, -2'046LL},
    FiniteGeometricSeriesData{2, 2, 30, 2'147'483'646LL}
));

// ======================================
// INFINITE GEOMETRIC SERIES SUM
// ======================================

struct InfiniteGeometricSeriesData {int input_first_term; double input_ratio; long long expected_sum; };
class InfiniteGometricSeriesTest : public ::testing::TestWithParam<InfiniteGeometricSeriesData> {};

TEST_P(InfiniteGometricSeriesTest, CheckInfiniteSum){
    const auto& data = GetParam();

    EXPECT_EQ(data.expected_sum, sumOfInfiniteGeometricSeries(data.input_first_term, data.input_ratio));
}

INSTANTIATE_TEST_SUITE_P(InfiniteGeometricSequenceCases, InfiniteGometricSeriesTest, ::testing::Values(
    InfiniteGeometricSeriesData{2, 0.5, 4LL},
    InfiniteGeometricSeriesData{2, 1.5, 0LL},
    InfiniteGeometricSeriesData{3, 0.9, 30LL},
    InfiniteGeometricSeriesData{1'000, 0.7, 3'333LL}
));
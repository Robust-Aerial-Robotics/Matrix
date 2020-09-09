#include "test_macros.hpp"

#include <matrix/math.hpp>

using namespace matrix;

int main()
{
    float data[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Matrix3f A(data);

    Matrix<float, 9,9> A_kron_A = A.kron(A);

    float data_check[9][9] =	{
        { 1,  2,  3,  2,  4,  6,  3,  6,  9},
        { 4,  5,  6,  8, 10, 12, 12, 15, 18},
        { 7,  8,  9, 14, 16, 18, 21, 24, 27},
        { 4,  8, 12,  5, 10, 15,  6, 12, 18},
        {16, 20, 24, 20, 25, 30, 24, 30, 36},
        {28, 32, 36, 35, 40, 45, 42, 48, 54},
        { 7, 14, 21,  8, 16, 24,  9, 18, 27},
        {28, 35, 42, 32, 40, 48, 36, 45, 54},
        {49, 56, 63, 56, 64, 72, 63, 72, 81}
    };
    Matrix<float, 9,9> A_kron_A_check(data_check);

    TEST(isEqual(A_kron_A, A_kron_A_check));
    return 0;
}
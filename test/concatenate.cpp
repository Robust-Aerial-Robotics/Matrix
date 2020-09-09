#include "test_macros.hpp"

#include <matrix/math.hpp>

using namespace matrix;

int main()
{
    float data_A[2][3] =  {
        {1, 2, 3},
        {4, 5, 6}
    };
    Matrix<float, 2,3> A(data_A);

    float data_B[4][3] =  {
        { 7,  8,  9},
        {10, 11, 12},
        {13, 14, 15},
        {16, 17, 18},
    };
    Matrix<float, 4,3> B(data_B);

    Matrix<float, 6,3> AB = A.vcat(B);

    float data_AB_check[6][3] = {
        { 1,  2,  3},
        { 4,  5,  6},
        { 7,  8,  9},
        {10, 11, 12},
        {13, 14, 15},
        {16, 17, 18},
    };
    Matrix<float, 6,3> AB_check(data_AB_check);

    TEST(isEqual(AB, AB_check));
    return 0;
}
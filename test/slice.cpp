#include <stdio.h>

#include <matrix/math.hpp>
#include "test_macros.hpp"

using namespace matrix;

int main()
{
    float data[9] = {0, 2, 3,
                     4, 5, 6,
                     7, 8, 10
                    };
    float data_check[6] = {
        4, 5, 6,
        7, 8, 10
    };
    SquareMatrix<float, 3> A(data);
    Matrix<float, 2, 3> B_check(data_check);
    Matrix<float, 2, 3> B(A.slice<2, 3>(1, 0));
    TEST(isEqual(B, B_check));
    return 0;
}

/* vim: set et fenc=utf-8 ff=unix sts=0 sw=4 ts=4 : */
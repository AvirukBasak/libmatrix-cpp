// firstly, download the libmatrix.hpp file

#include <iostream>
#include "libmatrix.hpp"

int main()
{
    using namespace std;        // standard namespace
    using namespace Matrix;     // namespace for this library

    // 4x4 matrix as C++ DDA
    int m2arr[4][4] = {
        { 0, 2, 3, 4 },
        { 7, 1, 5, 6 },
        { 6, 5, 2, 7 },
        { 4, 3, 2, 3 }
    };

    // the constructor accepts address to 1st element of the C++ DDA
    matrix<int> m2 = matrix<int>(4, 4, &m2arr[0][0]);

    std::cout << "\n>> my matrix:\n";
    for (int i = 0; i < m2.rows(); i++) {
        for (int j = 0; j < m2.cols(); j++)
            std::cout << m2[i][j] << " ";
        std::cout << "\n";
    }

    // 4x4 unit matrix
    matrix<int> im = Matrix::I<int>(4);

    std::cout << "\n>> my unit matrix:\n";
    for (int i = 0; i < im.rows(); i++) {
        for (int j = 0; j < im.cols(); j++)
            std::cout << im[i][j] << " ";
        std::cout << "\n";
    }

    cout << "\nequality = ";
    if (m2 == im) cout << "equal\n";
    else cout << "unequal\n";

    try {
        std::cout << "\n>> sum:\n";
        matrix<int> sum = m2 + im;
        sum.print();
    } catch (Matrix::Exception ex) {
        if (ex == Matrix::EX_INCMP)
            cout << "incompatible matrices!\n";
    }
    try {
        matrix<int> diff = m2 - im;
        std::cout << "\n>> difference:\n";
        diff.print();
    } catch (Matrix::Exception ex) {
        if (ex == Matrix::EX_INCMP)
            cout << "incompatible matrices!\n";
    }

    cout << "\n>> inverse of my matrix:\n";
    try {
        m2.inverse().print();
    } catch (Matrix::Exception ex) {
        if (ex == Matrix::EX_DETR0)
            cout << "can't invert, determinant = 0!\n";
    }
    return 0;
}

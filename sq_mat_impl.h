#ifndef _SQ_MAT_IMPLE_H_
#define _SQ_MAT_IMPLE_H_
#include <stdbool.h>
#include "sq_mat.h"

//constructor for SqMat
template<class T>
SqMat<T>::SqMat(Mat<T> m) :Mat<T>(m)
{
    if (m.height() != m.width())
    {
        ExceptionWrongDimensions exc;
        throw exc;
    }
}


template<class T>
unsigned int SqMat<T>::size() const {
    return this->width();

}

template<class T>
T SqMat<T>::determinant() const // Auxiliary function to find the determinant of a square matrix
{
    T Res = 0; // Initialize the result for the determinant
    int sign = 1; // Initialize the sign for the determinant calculation

    if (this->size() == 1) // Base case: return the single element for a 1x1 matrix
    {
        return (*this)[0][0];
    }

    // Create a submatrix without the first row (upper row)
    Mat<T> No_upper_row_mat = (*this).get_rows(range((unsigned int)1, ((*this).size() - 1)));

    for (unsigned int i = 0; i < (*this).size(); ++i)
    {
        // Generate an index vector for selecting the columns of the submatrix
        Vec<unsigned int> index_vec = (range((unsigned int)0, i), range(i + 1, (*this).size() - 1-i));//changed this

        // Get the minor matrix by selecting columns based on the index vector
        SqMat<T> get_minor_mat(No_upper_row_mat.get_cols(index_vec));

        // Calculate the determinant recursively and accumulate it
        Res = Res + ((sign * ((*this)[0][i])) * get_minor_mat.determinant());

        // Change the sign for the next iteration to alternate signs
        sign = -sign;
    }

    return Res; // Return the final calculated determinant
}
#endif // _SQ_MAT_H_

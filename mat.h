#ifndef _MAT_H_
#define _MAT_H_

#include "vec.h" // Include the necessary header file for Vec


// Note: The actual implementation of these methods is in the "mat_impl.h" file.

template <class T>
class Mat : public Vec< Vec<T> >
{
public:
    // Constructors
    Mat(unsigned int w);
    Mat(Vec<T> vec_1d);
    Mat(Vec< Vec<T> > vec_2d);

    // Accessors
    // Get the width (number of columns) of the matrix
    unsigned int width() const;
    // Get the height (number of rows) of the matrix
    unsigned int height() const;

    // Matrix Operations
    // Matrix addition
    Mat operator+(const Mat& rhs) const;
    // Scalar multiplication
    Mat operator*(const T& rhs) const;
    // Matrix multiplication
    Mat operator*(const Mat<T>& rhs) const;
    // Combine two matrices horizontally
    Mat operator,(const Mat<T>& rhs) const;
    //Get specified rows
    Mat get_rows(const Vec<unsigned int>& ind) const;
    // Get specified columns
    Mat get_cols(const Vec<unsigned int>& ind) const;
    // Transpose the matrix (rows become columns and vice versa)
    Mat transpose() const;

protected:
    unsigned int w_; // Width of the matrix


};
// Scalar multiplication with a matrix
template <class T>
Mat<T> operator*(const T& lhs, const Mat<T>& rhs);

// Output the matrix
template <class T>
ostream& operator<<(ostream& ro, const Mat<T>& m);

//chak Mat width
template <class T>
Vec<Vec<T>> checkMatWidth(Vec<Vec<T>> Vec);


//Checks mat with is not smaller than 1
template <class T>
unsigned int checkRowWidth(unsigned int w);
#include "mat_impl.h" 


#endif // _MAT_H_


#ifndef _MAT_IMPL_H
#define _MAT_IMPL_H_

// Function prototypes for checkMatWidth and checkRowWidth
template <class T>
Vec<Vec<T>> checkMatWidth(Vec<Vec<T>> Vec);

// Function to check and ensure a row width is not smaller than 1

unsigned int checkRowWidth(unsigned int w);

// Constructor for a Mat with only its width


template<class T>
Mat<T>::Mat(unsigned int w) : w_(checkRowWidth(w))
{
}
// Constructor for a Mat from a 1D Vec

template<class T>
Mat<T>::Mat(Vec<T> vec_1d) : Vec<Vec<T>>(vec_1d), w_(checkRowWidth(vec_1d.size()))
{
}
// Constructor for a Mat from a 2D Vec

template <class T>
Mat<T>::Mat(Vec< Vec<T> > vec_2d) : Vec<Vec<T>>(checkMatWidth(vec_2d)), w_(checkRowWidth(vec_2d[0].size()))
{
}


//class functions
// Return the width of the matrix
template <class T>
unsigned int Mat<T>::width() const {
	return this->w_;
}

// Return the height of the matrix
//check this
template <class T>
unsigned int Mat<T>::height() const {
	return this->size();
}

// Matrix addition
template <class T>
Mat<T> Mat<T>:: operator+(const Mat& rhs) const {
	if (this->width() != rhs.width()) {
		throw ExceptionWrongDimensions();
	}
	Vec<Vec<T> > sum = *this;
	for (unsigned int i = 0; i < (this->height()); ++i) {
		sum[i] = (sum[i] + rhs[i]);
	}
	return sum;
}
// Scalar multiplication
template <class T>
Mat<T> Mat<T>::  operator*(const T& rhs) const {
	Vec<Vec<T> > mul = *this;
	for (unsigned int i = 0; i < (this->height()); ++i) {
		mul[i] = (mul[i] * rhs);
	}
	return  mul;
}

// matrix mul used chat GPT for corrections - check this!!
template <class T>
Mat<T> Mat<T>::operator*(const Mat<T>& rhs) const
{
	if (this->width() != rhs.height())
	{
		ExceptionWrongDimensions exc;
		throw exc;
	}
	Vec<Vec<T> > new_this = *this;
	unsigned int this_height = height();
	Vec<Vec<T> > result;
	//mat_init(result, this_height, rhs.width());
	unsigned int i = 0;
	unsigned int j = 0;
	unsigned int tmp = 0;
	for (i = 0; i < this_height; i++)
	{
		Vec<T> tmp_vec;
		for (j = 0; j < rhs.width(); j++)
		{
			T tmp_result = 0;
			for (tmp = 0; tmp < rhs.height(); tmp++)
			{
				tmp_result = tmp_result + (rhs[tmp][j] * new_this[i][tmp]);
			}
			tmp_vec.push_back(tmp_result);
		}
		result.push_back(tmp_vec);
	}
	return result;
}

// Combine two matrices horizontally
template <class T>
Mat<T> Mat<T>:: operator,(const Mat<T>& rhs) const {
	if (this->width() != rhs.width()) { //check differen width of matrix
		throw ExceptionWrongDimensions();
	}
	Vec<Vec<T> >  sum = *this;
	for (unsigned int i = 0; i < (rhs.height()); ++i) {
		sum = (sum, rhs[i]);
	}
	return sum;

}

//transpose function, used chat gpt to write this
// Transpose the matrix (rows become columns and vice versa)
template <class T>
Mat<T> Mat<T>::transpose() const
{
	
	//Vec<Vec<T> > new_this = *this;
	Vec<Vec<T> > result;
	
	for (unsigned int i = 0; i < width(); i++) {
		Vec<T> row;
		for (unsigned int j = 0; j < height(); j++) {
			row.push_back((*this)[j][i]);
		}
		result.push_back(row);
	}
	return result;
}

//// Transpose the matrix (rows become columns and vice versa)
//template <class T>
//Mat<T> Mat<T>::transpose() const {
//	unsigned int height = this->height();
//	unsigned int width = this->width();
//	Vec<Vec<T>> transMat(width);
//
//	for (unsigned int i = 0; i < width; ++i) {
//		Vec<T> row;
//		for (unsigned int j = 0; j < height; ++j) {
//			row.push_back((*this)[j][i]); // Swap rows and columns
//		}
//		transMat = (transMat + row);
//	}
//
//	return Mat<T>(transMat);
//}


// Get specified rows
template <class T>
Mat<T> Mat<T>::get_rows(const Vec<unsigned int>& ind) const {
	Vec<Vec<T> >  rowsMat;
	for (unsigned int i = 0; i < ind.size(); ++i) {
		rowsMat.push_back((*this)[ind[i]]);
	}
	return rowsMat;
}
// Get specified columns, usage of transpose
template <class T>
Mat<T> Mat<T>::get_cols(const Vec<unsigned int>& ind) const {
	//Transpose the original matrix
	Mat<T> colMat = this->transpose();

	//Get the specified rows from the transposed matrix
	return colMat.get_rows(ind).transpose();
}


//standalone matrix multiplication function
template <class T>
Mat<T> operator*(const T& lhs, const Mat<T>& rhs) {
	Vec<Vec<T> > mul = rhs;
	for (unsigned int i = 0; i < rhs.height(); ++i) {
		mul[i] = (mul[i] * lhs);
	}
	return  mul;
}


// Output the matrix to a stream
template <class T>
ostream& operator<<(ostream& ro, const Mat<T>& m)
{
	unsigned int height = m.height();
	unsigned int width = m.width();
	if (width == 0 || height == 0)
	{
		throw ExceptionEmptyOperand();
	}
	unsigned int i = 0;
	cout << "(" << "\n";
	for (; i < height - 1; i++)
	{
		cout << m[i] << "," << "\n";
	}
	cout << m[i] << "\n" << ")";
	return cout;
}

// Function to check if a row width is not smaller than 1
unsigned int checkRowWidth(unsigned int w) {
	if (w < 1) {
		throw ExceptionEmptyOperand();
	}
	return w;
}

// Function to check if all rows have the same width
template <class T>
Vec<Vec<T>> checkMatWidth(Vec<Vec<T>> Vec) {
	unsigned int w = Vec[0].size();
	unsigned int VecSize = Vec.size();
	for (unsigned int i = 1; i < VecSize; ++i) {
		if (Vec[i].size() != w) {
			throw ExceptionWrongDimensions();
		}
	}
	return Vec;

}
#endif



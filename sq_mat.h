#ifndef _SQ_MAT_H_
#define _SQ_MAT_H_

#include "mat.h"
// Note: The actual implementation of these methods is in the "sq_mat_impl.h" file.
template <class T>
class SqMat : public Mat<T>
{
public:
	SqMat(Mat<T> m);
	unsigned int size() const;
	T determinant() const;
};

#include "sq_mat_impl.h"

#endif // _SQ_MAT_H_

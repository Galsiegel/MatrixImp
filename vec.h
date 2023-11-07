#ifndef _VEC_H_
#define _VEC_H_

#include <list>
#include <exception>
#include <iostream>


// Note: The actual implementation of these methods is in the "vec_impl.h" file.


using namespace std;

// Exception class for wrong dimensions
class ExceptionWrongDimensions : public exception
{
public:
	const char* what() const throw();
};

// Exception class for empty operand
class ExceptionEmptyOperand : public exception
{
public:
	const char* what() const throw();
};

// Exception class for index exceeding operand dimensions
class ExceptionIndexExceed : public exception
{
public:
	const char* what() const throw();
};

template <class T>
class Vec {
public:
	typename list<T>::const_iterator begin() const {
		return vals_.begin();
	}
	typename list<T>::const_iterator end() const {
		return vals_.end();
	}

	Vec() {};
	// Constructor implementation
	Vec(const T& el);

	// Add an element to the end of the vector
	void push_back(T el);

	// Get the size of the vector
	unsigned int size() const;

	// Vector addition
	Vec operator+(const Vec& rhs) const;

	// Vector-scalar multiplication
	Vec operator*(const T& rhs) const;

	// Access and modify vector elements by index
	T& operator[](unsigned int ind);

	// Access vector elements by index (const version)
	const T& operator[](unsigned int ind) const;

	// Combine two vectors into a new vector
	Vec operator,(const Vec& rhs) const;

	// Return a subvector specified by indices
	Vec operator[](const Vec<unsigned int>& ind) const;


	template <class Compare>
	void sort(Compare comp) {
		vals_.sort(comp);
	}

protected:
	list<T> vals_;
};

// Standalone multiplication function for scalar-vector multiplication
template <class T>
Vec<T> operator*(const T& lhs, const Vec<T>& rhs);

// Output the vector to a stream
template <class T>
ostream& operator<<(ostream& ro, const Vec<T>& v);

// Generate a vector with 'size' elements, including values from 'start' to 'start+size-1'
template <class T>
Vec<T> range(T start, unsigned int size);

#include "vec_impl.h"

#endif // _VEC_H_

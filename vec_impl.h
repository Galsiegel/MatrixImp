#ifndef _VEC_IMPL_H
#define _VEC_IMPL_H_

// Constructor implementation
// Initialize the Vec with a single element 'el'
template <class T>
Vec<T>::Vec(const T& el) {
    vals_.push_back(el);
}

// Add an element to the end of the vector
template <class T>
void Vec<T>::push_back(T el) {

    vals_.push_back(el);
}

// Return the size of the vector
template <class T>
unsigned int Vec<T>::size() const {
    return vals_.size();
}

// Vector addition
template <class T>
Vec<T> Vec<T>:: operator+(const Vec& rhs) const {
    if (this->size() != rhs.size()) { //trying to add different sized vectors
        throw ExceptionWrongDimensions();
    }
    if (rhs.size() == 0)
    {
        throw  ExceptionEmptyOperand();
    }
    Vec<T> result;

    typename list<T>::const_iterator it1 = this->begin();
    typename list<T>::const_iterator it2 = rhs.begin();

    while (it1 != this->end() && it2 != rhs.end()) {
        result.push_back(*it1 + *it2);
        ++it1;
        ++it2;
    }
    return result;
}
// Vector-scalar multiplication
template <class T>
Vec<T> Vec<T> :: operator*(const T& rhs) const {

    if (this->size() == 0)
    {
        throw  ExceptionEmptyOperand();
    }
    Vec<T> result;

    typename list<T>::const_iterator it1 = this->begin();

    while (it1 != end()) {
        result.push_back(*it1 * rhs);
        ++it1;
    }
    return result;
}

//template <class T>
//T& Vec<T>::operator[](unsigned int ind) {
//    if (ind >= size()) {
//        throw ExceptionIndexExceed();
//    }
//
//    typename std::list<T>::const_iterator it = begin();
//    std::advance(it, ind);
//
//    return *it;
//}


// Access and modify vector elements by index
template <class T>
T& Vec<T>::operator[](unsigned int ind) {
    if (ind >= size()) {
        throw ExceptionIndexExceed();
    }

    typename std::list<T>::const_iterator it = begin();
    std::advance(it, ind);

    return const_cast<T&>(*it);
}
// Access vector elements by index (const version)
template<class T>
const T& Vec<T>::operator[](unsigned int ind) const {
    if (ind >= size()) {
        throw ExceptionIndexExceed(); // Index is out of bounds
    }
    typename list<T>::const_iterator it = begin();
    std::advance(it, ind); // Move the iterator to the desired index

    return *it;

}

// Combine two vectors into a new vector
template<class T>
Vec<T> Vec<T> :: operator,(const Vec& rhs) const {
    Vec<T> result;
    for (unsigned int i = 0; i < size(); ++i) {
        result.push_back((*this)[i]);
    }
    for (unsigned int i = 0; i < rhs.size(); ++i) {
        result.push_back(rhs[i]);
    }
    return result;
}

// Return a subvector specified by indices
template<class T>
Vec<T> Vec<T> :: operator[](const Vec<unsigned int>& ind) const {
    Vec<T> result;

    for (unsigned int i = 0; i < ind.size(); ++i) {
        if (ind[i] >= size()) {
            throw ExceptionIndexExceed(); // Index is out of bounds
        }

        result.push_back((*this)[ind[i]]);
    }

    return result;

}

// Standalone multiplication function for scalar-vector multiplication
template<class T>
Vec<T> operator*(const T& lhs, const Vec<T>& rhs) {
    if (rhs.size() == 0)
    {
        throw  ExceptionEmptyOperand();
    }
    Vec<T> result;
    for (unsigned int i = 0; i < rhs.size(); ++i) {
        result.push_back(lhs * rhs[i]);

    }
    return result;
}

// Output the vector to a stream
template <class T>
ostream& operator<<(ostream& ro, const Vec<T>& v) {
    if (v.size() == 0)
    {
        throw  ExceptionEmptyOperand();
    }
    cout << "(";
    for (unsigned int i = 0; i < v.size(); ++i) {
        cout << v[i];
        if (i < v.size() - 1) {
            cout << ",\t";
        }
    }
    cout << ")";
    return cout;
}

// Generate a vector with 'size' elements, including values from 'start' to 'start+size-1'
template <class T>
Vec<T> range(T start, unsigned int size) {
    Vec<T> new_vec;
    for (unsigned int i = 0; i < size; i++) {
        new_vec.push_back(start + i);
    }
    return new_vec;
}

// Functor for comparing vectors based on the inf norm
template <class T>
class norm_inf_comp {
public:
    bool operator()(const Vec<T>& vec1, const Vec<T>& vec2) const {
        T max_vec1 = -1, max_vec2 = -1;
        for (const T& element : vec1) { //find max element in vector 1
            T abs_element = (element < 0) ? element*(-1) : element; //abs value of element
            if (  max_vec1 < abs_element) {
                max_vec1 = abs_element;
            }
        }
        for (const T& element : vec2) { //find max element in vector 2
            T abs_element = (element < 0) ? element * (-1) : element; //abs value of element
            if (max_vec2 < abs_element) {
                max_vec2 = abs_element;
            }
        }
        return (max_vec1 < max_vec2);
    }
};

// Exception classes and their what() methods

const char* ExceptionWrongDimensions::what() const throw()
{
    return "operand dimensions must agree";
}
const char* ExceptionEmptyOperand::what() const throw()
{
    return "empty operand";
}
const char* ExceptionIndexExceed::what() const throw()
{
    return "index exeeds operand dimensions";
}
#endif


#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
    private:
        T *array;
        unsigned int _size;
    public:
        Array() : array(new T) , _size(0) {};
        Array(unsigned int n) : array(new T[n]) , _size(n) {};
        ~Array() {delete[] array;};

        Array(const Array& obj) : array(new T[obj._size]) , _size(obj._size) {
            for (size_t i = 0; i < _size; i++)
                array[i] = obj.array[i];
        };

        Array& operator=(const Array& obj) {
            if (this != &obj) {
                delete[] array;
                _size = obj._size;
                array = new T[_size];
                for (size_t i = 0; i < _size; i++)
                    array[i] = obj.array[i];
            }
            return *this;
        }

        class OutBndException : public std::exception {
            public:
                virtual const char* what() const throw() {return "index out of bounds!";}
        };

        T& operator[](unsigned int i) const {
            if (i >= _size)
                throw OutBndException();
            return array[i];
        }

        unsigned int  size() const {return _size;}
};

#endif


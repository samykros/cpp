#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <string>

template<typename T>
class Array
{
    private:
        T *_data;       // puntero a los elementos
        unsigned int _size; // tamaño del array

    public:
        Array() : _data(NULL), _size(0) {}
        Array(unsigned int n) : _data(new T[n]()), _size(n) {}
        
        // Constructor de copia
        Array(const Array& other) : _data(NULL), _size(0) {
            *this = other;
        }
        // Operador de asignación
        Array& operator=(const Array& other) {
            if (this != &other) {
                delete[] _data;
                _size = other._size;
                _data = (_size ? new T[_size] : NULL);
                for (unsigned int i = 0; i < _size; ++i)
                    _data[i] = other._data[i];
            }
            return *this;
        }
    
        // Operador subscript
        T& operator[](unsigned int index) {
            if (index >= _size)
                throw std::out_of_range("Index out of range");
            return _data[index];
        }
        const T& operator[](unsigned int index) const { // para arrays const
            if (index >= _size)
                throw std::out_of_range("Index out of range");
            return _data[index];
        }

        ~Array() {
            delete[] _data;
        }
        // Función size
        unsigned int size() const {
            return _size;
        }
};


#endif

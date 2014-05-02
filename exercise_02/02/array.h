#ifndef __ARRAY_H__
#define __ARRAY_H__

#include <stdexcept>
#include <iostream>
#include <sstream>
#include <initializer_list>

#include "exception.h"

/* Fierz ****************************
   Diese Art den Array zu implementieren ist nicht sehr flexible, da Array's nur compatible sind, falls sie dieselbe Länge haben.
   Beispiel:
   Array<int,10> ia1;
   Array<int,11> ia2;
   das folgende Statement führt zu einem Fehler:
   ia1 = ia2;
************************************/
template <class T = int, std::size_t nElements = 100>
class Array
{
    public:
        // Type definitions
        typedef T& reference;
        typedef const T& const_reference;
        typedef T* iterator;
        typedef const T* const_iterator;

        // Constructor / desctructor
        Array() {}
        Array(std::initializer_list<T> elements)
        {
            std::size_t i = 0;

	    /* Fierz *********************************
	       Was passiert, falls mehr Elemente als nElements??
	    **************************************/
            for (auto&& e : elements) {
                m_array[i] = e;
                ++i;
            }

            while (i < nElements) {
                m_array[i] = {};
                ++i;
            }

        }
        virtual ~Array() {}

        // Iterator
        iterator begin()
        {
            return m_array;
        }

        const_iterator begin() const
        {
            return m_array;
        }

        iterator end()
        {
            return m_array + nElements;
        }

        const_iterator end() const
        {
            return m_array + nElements;
        }

        // Operators
        reference operator [] (std::size_t nIndex)
        {
            this->checkIndex(nIndex);

            return m_array[nIndex];
        }

        const_reference operator [] (std::size_t nIndex) const
        {
            this->checkIndex(nIndex);

            return m_array[nIndex];
        }

        // Functions
        reference at(std::size_t nIndex)
        {
            this->checkIndex(nIndex);

            return m_array[nIndex];
        }

        const_reference at(std::size_t nIndex) const
        {
            this->checkIndex(nIndex);

            return m_array[nIndex];
        }

        reference front()
        {
            return m_array[0];
        }

        const_reference front() const
        {
            return m_array[0];
        }

        reference back()
        {
            return m_array[nElements - 1];
        }

        const_reference back() const
        {
            return m_array[nElements - 1];
        }

        static std::size_t size()
        {
            return nElements;
        }

        const bool empty()
        {
            return false;

            /*
            bool isEmpty = true;

            for (std::size_t i = 0; i < nElements; ++i) {
                if (m_array[i]) {
                    isEmpty = false;
                    break;
                }
            }

            return isEmpty;
            */
        }

        void swap(Array<T, nElements>& src)
        {
            for (std::size_t i = 0; i < nElements; ++i) {
                std::swap(m_array[i], src.m_array[i]);
            }
        }

        const T* data() const
        {
            return m_array;
        }

        T* data()
        {
            return m_array;
        }

        void fill(const T& value)
        {
            std::fill_n(begin(), size(), value);
        }

    private:
        T m_array[nElements];

        void checkIndex(std::size_t nIndex)
        {
            if (nIndex < 0 || nIndex > nElements) {
                std::cout << nIndex << std::endl;
                std::stringstream strStream;
                strStream << "Given index out of boundaries (" << nElements << ")!";
                std::out_of_range ex(strStream.str());

                throw(OutOfBoundsException(ex));
            }
        }
};

#endif

//
// Declaration of the Set class.
// 
// The Set class stores items in a dynamically allocated array. In a Set,
// the order of elements does not matter, and every element can occur at most
// once.
// 
// Set is implemented as a template class to allow for any data type to be stored.
//

#ifndef SET_H
#define SET_H

#include <string>
#include <iostream>
#include <new>
#include <cstdlib>

using namespace std;

template <class T>
class Set
{
public:
    // TODO - add your code here (modified from Lab08)

    // Default constructor
    Set()
    {
        name = "Unnamed Set";
        pElements = nullptr;
        size = 0;

    }

    // Parameterized constructor
    Set(string setName)
    {
        name = setName;
        pElements = nullptr;
        size = 0;

    }
    
    // Copy constructor:
    Set(const Set& a)
    {
        cout << "\nCopy constructer called - the new object will be a copy of Set Object " << a.name << endl;
        name = a.name;
        size = a.size;

        try {
            pElements = new T[size];
        }
        catch (bad_alloc) {
            memError();
        }

        for (int i = 0;i < size;i++) {
            *(pElements + i) = *(a.pElements + i);
        }
    }

    // Assignment operator overload
    Set& operator=(const Set& a)
    {
        cout << "\nAssignment operator overload called for Set objects ";
        cout << name << " and " << a.name << endl;
        if (this != &a)
        {
            name = a.name;
            delete[] pElements;
            size = a.size;
            try {
                pElements = new T[size];
            }
            catch (bad_alloc) {
                memError();
            }

            for (int i = 0;i < size;i++) {
                *(pElements + i) = *(a.pElements + i);
            }
        }
        else {
            cout << "\n** Self-assignment of object " << name << " not allowed. **\n";
        }
        return *this;
    }

    // Destructor
    ~Set()
    {
        //cout << "\nDestructor called for Set object: " << name << endl;

        // Free all of the dynamically allocated elements in the array to
        // avoid memory leaks:
        delete[] pElements;
    }

    //function can be added here or outside with:
    //template class<T>
    //void Set<T>::add(T n)
    /*void add(T n)
    {
        if (!contains(n))
        {
            try 
            {
                // Create a new array:
                T* pNewElements = new T[size + 1];

                // Copy old contents, if any, to the new array:
                for (int i = 0; i < size; i++)
                {
                    pNewElements[i] = pElements[i];
                }

                // Add the new integer:
                pNewElements[size] = n;
                size++;

                // Free old memory and reassign member pointer. No need to check
                // if pElements == nullptr, since calling delete on a null pointer
                // is fine.
                delete[] pElements;
                pElements = pNewElements;
            }
            catch (bad_alloc)
            {
                memError();
            }
        }
    }*/

    void print() const
    {
        cout << "\nPrinting Set object: " << name << endl;
        for (int i = 0; i < size; i++)
        {
            cout << pElements[i] << endl;
        }
    }

    // This function checks to see if a given integer is already in the set.
    bool contains(T n) const
    {
        bool found = false;

        for (int i = 0; i < size && !found; i++)
        {
            if (pElements[i] == n)
            {
                found = true;
            }
        }

        return found;
    }

    void add(T n);

private:
    // TODO - add your code here (modified from Lab08)
    string name;
    T* pElements;
    int size;


    // Handler for memory allocation errors:
    void memError();
};

//
// Implementation of the Set template class.
// 
// Note that for template classes, we put both the declaration and
// implementation in the same file (there is no Set.cpp file).
//

// TODO - add your code here (modified from Lab08)
template <class T>
void Set<T>::add(T n)
{
    if (!contains(n))
    {
        try
        {
            // Create a new array:
            T* pNewElements = new T[size + 1];

            // Copy old contents, if any, to the new array:
            for (int i = 0; i < size; i++)
            {
                pNewElements[i] = pElements[i];
            }

            // Add the new integer:
            pNewElements[size] = n;
            size++;

            // Free old memory and reassign member pointer. No need to check
            // if pElements == nullptr, since calling delete on a null pointer
            // is fine.
            delete[] pElements;
            pElements = pNewElements;
        }
        catch (bad_alloc)
        {
            memError();
        }
    }
}

//
// Handler for memory allocation errors.
// 
// Displays an error message and terminates the program when memory allocation
// fails. Can be called from exception handlers.
//
template <class T>
void Set<T>::memError()
{
    cout << "ERROR: Cannot allocate memory.\n";
    exit(EXIT_FAILURE);
}

#endif // SET_H
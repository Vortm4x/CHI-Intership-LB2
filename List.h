#ifndef LIST_H
#define LIST_H

#include <cstddef>
#include <memory>

template<class T, size_t N>
class List
{
public:
    List();
    List(const List& other);
    List(List&& other);
    ~List();

    List& operator=(const List& other);
    List& operator=(List&& other);

    const T& operator[](const size_t& index) const;
    void operator+=(const T& element);
    size_t size () const;

private:
    T* __data;
    size_t __size;

    static T __defaultValue;
};


template<class T, size_t N>
T List<T, N>::__defaultValue = T();


template<class T, size_t N>
List<T, N>::List()
    : __data(new T[N]), __size(0)
{}


template<class T, size_t N>
List<T, N>::List(const List& other)
    : __data(new T[N]), __size(other.__size)
{
    std::copy(std::begin(other.data),
              std::end(other.data),
              std::begin(this->data));
}


template<class T, size_t N>
List<T, N>::List(List<T, N>&& other)
{
    *this = static_cast<List<T, N>&&>(other);
}


template<class T, size_t N>
List<T, N>::~List()
{
    if(__data != nullptr)
    {
        delete[] __data;
    }
}


template<class T, size_t N>
List<T, N>& List<T, N>::operator=(const List& other)
{
    if(this != &other)
    {
        std::copy(std::begin(other.data),
                  std::end(other.data),
                  std::begin(this->data));
    }


    return *this;

}


template<class T, size_t N>
List<T, N>& List<T, N>::operator=(List&& other)
{
    if(this != &other)
    {
        this->~List();

        this->__data = other.__data;
        this->__size = other.__size;

        other.__data = nullptr;
        other.__size = 0;
    }

    return *this;
}


template<class T, size_t N>
const T& List<T, N>::operator[](const size_t& index) const
{
    if(0 <= index && index < N)
    {
        return __data[index];
    }
    else
    {
        return __defaultValue;
    }
}

template<class T, size_t N>
void List<T, N>::operator+=(const T& element)
{
    if(__size < N)
    {
        __data[__size] = element;
        ++__size;
    }
}

template<class T, size_t N>
size_t List<T, N>::size() const
{
    return __size;
}


#endif // LIST_H


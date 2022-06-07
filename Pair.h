#ifndef PAIR_H
#define PAIR_H


template<class A, class B>
class Pair
{
public:
    Pair() = default;
    Pair(const A& key, const B& value);
    Pair(const Pair& other) = default;
    Pair(Pair&& other) = default;
    ~Pair() = default;

    Pair& operator=(const Pair& other) = default;
    Pair& operator=(Pair&& other) = default;

    const A& getKey() const;
    const B& getValue() const;

private:
    A __key;
    B __value;
};


template<class A, class B>
Pair<A, B>::Pair(const A& key, const B& value)
    : __key(key), __value(value)
{}


template<class A, class B>
const A& Pair<A, B>::getKey() const
{
    return this->__key;
}


template<class A, class B>
const B& Pair<A, B>::getValue() const
{
    return this->__value;
}


#endif // PAIR_H

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <algorithm>
#include <list>
#include <stack>
#include <deque>

template <typename T, typename Container = std::deque<T>> 
class MutantStack : public std::stack<T, Container>
{
    public:
        MutantStack() {};
        ~MutantStack() {};
        MutantStack(const MutantStack& obj) {*this = obj;}
        MutantStack& operator=(const MutantStack& obj) {
            std::stack<T, Container>::operator=(obj);
            return *this;
        }

        typedef typename Container::iterator iterator;

        iterator begin() {return this->c.begin();}
        iterator end() {return this->c.end();}
};

#endif

#ifndef ATARGET_HPP
#define ATARGET_HPP

#include "ASpell.hpp"
#include <iostream>

class ASpell;

class ATarget 
{
    private:
        std::string type;

    public:
        ATarget(std::string);
        virtual ~ATarget();

        const std::string& getType() const;

        void getHitBySpell(const ASpell&) const;

        virtual ATarget* clone() const = 0;

};

#endif

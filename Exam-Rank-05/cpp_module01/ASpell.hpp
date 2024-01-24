#ifndef ASPELL_HPP
#define ASPELL_HPP

#include "ATarget.hpp"
#include <iostream>
#include <string>

class ATarget;

class ASpell 
{
    private:
        std::string name;
        std::string effects;
    
    public:
        ASpell(std::string, std::string);
        virtual ~ASpell();

        const std::string& getName() const;
        const std::string& getEffects() const;

        void launch(const ATarget&) const;

        virtual ASpell* clone() const = 0;

};

#endif

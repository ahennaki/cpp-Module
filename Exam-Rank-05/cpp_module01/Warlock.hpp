#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include "ASpell.hpp"
#include <iostream>
#include <map>
#include <string>

class ASpell;
class ATarget;

class Warlock
{
    private:
        std::string name;
        std::string title;

        std::map<std::string, ASpell*> map;

    public:
       Warlock(const std::string&, const std::string&);
       ~Warlock();

       const std::string& getName() const; 
       const std::string& getTitle() const;
       void setTitle(const std::string&);

       void introduce() const;

       void learnSpell(ASpell*);
       void forgetSpell(std::string);
       void launchSpell(std::string, const ATarget&);

};

#endif

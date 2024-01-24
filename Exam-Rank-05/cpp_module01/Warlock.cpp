#include "Warlock.hpp"
#include "ASpell.hpp"
#include <string>

Warlock::Warlock(const std::string& name, const std::string& title) :
name(name) , title(title) {
    std::cout << name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock() {
    std::map<std::string, ASpell*>::iterator it = map.begin();

    while (it != map.end())
    {
        delete it->second;
        it++;
    }
    std::cout << name << ": My job here is done!" << std::endl;
}

const std::string& Warlock::getName() const {return name;}

const std::string& Warlock::getTitle() const {return title;}

void Warlock::setTitle(const std::string& title) {this->title = title;}

void Warlock::introduce() const {
    std::cout << name << ": I am " << name << ", " << title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell* spell) {
    if (!spell)
        return;
    if (map.find(spell->getName()) == map.end())
        map[spell->getName()] = spell;
}

void Warlock::forgetSpell(std::string spellName) {
    if (map.find(spellName) != map.end())
        map.erase(map.find(spellName));
}

void Warlock::launchSpell(std::string spellName, const ATarget& target) {
    if (map.find(spellName) != map.end())
        (map.find(spellName)->second)->launch(target);
}

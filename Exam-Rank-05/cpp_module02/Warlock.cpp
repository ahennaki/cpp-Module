#include "Warlock.hpp"
#include "ASpell.hpp"
#include <string>

Warlock::Warlock(const std::string& name, const std::string& title) :
name(name) , title(title) {
    std::cout << name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock() {
    std::cout << name << ": My job here is done!" << std::endl;
}

const std::string& Warlock::getName() const {return name;}

const std::string& Warlock::getTitle() const {return title;}

void Warlock::setTitle(const std::string& title) {this->title = title;}

void Warlock::introduce() const {
    std::cout << name << ": I am " << name << ", " << title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell* spell) {
    book.learnSpell(spell);
}

void Warlock::forgetSpell(std::string spellName) {
    book.forgetSpell(spellName);
}

void Warlock::launchSpell(std::string spellName, const ATarget& target) {
    if (book.createSpell(spellName))
        (book.createSpell(spellName))->launch(target);
}

#include "SpellBook.hpp"
#include "ASpell.hpp"
#include <map>
#include <string>

SpellBook::SpellBook() {}

SpellBook::~SpellBook() {
    std::map<std::string, ASpell*>::iterator it = Book.begin();

    while (it != Book.end()) {
        delete it->second;
        it++;
    }
    Book.clear();
}

SpellBook::SpellBook(const SpellBook& obj) {
    *this = obj;
}

SpellBook& SpellBook::operator=(const SpellBook& obj) {
    if (this != &obj)
        Book = obj.Book;
    return *this;
}

void SpellBook::learnSpell(ASpell* spell) {
    if (!spell)
        return;
    if (Book.find(spell->getName()) == Book.end())
        Book[spell->getName()] = spell;
}

void SpellBook::forgetSpell(std::string const & spellName) {
    if (Book.find(spellName) != Book.end())
        Book.erase(Book.find(spellName));
}

ASpell* SpellBook::createSpell(std::string const & spellName) {
    if (Book.find(spellName) != Book.end())
        return Book[spellName];
    return 0;
}

#include "TargetGenerator.hpp"
#include "ATarget.hpp"

TargetGenerator::TargetGenerator() {}

TargetGenerator::~TargetGenerator() {
    // std::map<std::string, ATarget*>::iterator it = generator.begin();

    // while (it != generator.end()) {
    //     delete it->second;
    //     it++;
    // }
    // generator.clear();
}

TargetGenerator::TargetGenerator(const TargetGenerator& obj) {
    *this = obj;
}

TargetGenerator& TargetGenerator::operator=(const TargetGenerator& obj) {
    if (this != &obj)
        generator = obj.generator;
    return *this;
}

void TargetGenerator::learnTargetType(ATarget* target) {
    if (!target)
        return;
    if (generator.find(target->getType()) == generator.end())
        generator[target->getType()] = target;
}

void TargetGenerator::forgetTargetType(std::string const & type) {
    if (generator.find(type) != generator.end())
        generator.erase(generator.find(type));
}

ATarget* TargetGenerator::createTarget(std::string const & type) {
    if (generator.find(type) != generator.end())
        return generator[type];
    return 0;
}

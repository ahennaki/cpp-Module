#ifndef TARGETGENERATOR_HPP
#define TARGETGENERATOR_HPP

#include "ATarget.hpp"
#include <map>

class TargetGenerator
{
    private:
        TargetGenerator(const TargetGenerator&);
        TargetGenerator& operator=(const TargetGenerator&);

        std::map<std::string, ATarget*> generator;

    public:
        TargetGenerator();
        ~TargetGenerator();

        void learnTargetType(ATarget*);
        void forgetTargetType(std::string const &);
        ATarget* createTarget(std::string const &);
};

#endif

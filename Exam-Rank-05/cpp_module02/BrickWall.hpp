#ifndef BRICKWALL_HPP
#define BRICKWALL_HPP

#include "ASpell.hpp"

class BrickWall : public ATarget
{
    public:
        BrickWall();
        ~BrickWall();

        ATarget* clone() const;
};

#endif

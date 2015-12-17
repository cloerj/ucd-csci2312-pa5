//
// John-Marc Cloer
//

#include "Advantage.h"

namespace Gaming {

    const char Advantage::ADVANTAGE_ID = 'D';
    const double Advantage::ADVANTAGE_MULT_FACTOR = 2.0;

    Advantage::Advantage(const Game &g, const Position &p, double capacity) : Resource(g, p, capacity)
    {

    }

    Advantage::~Advantage()
    {
        //Havent quite figured out what should go here yet...
    }

    void Advantage::print(std::ostream &os) const
    {
        os << ADVANTAGE_ID << __id;
    }

    double Advantage::getCapacity() const
    {
        return getCapacity();
    }

    double Advantage::consume()
    {
        return Resource::consume();
    }
};

//
// John-Marc Cloer
//

#include "Agent.h"

namespace Gaming{

    const double Agent::AGENT_FATIGUE_RATE = 0.3;

    Agent::Agent(const Game &g, const Position &p, double energy) : Piece(g,p) // Default constructor
    {
        __energy = energy; //Assign to pass energy to __energy
    }


    Agent::~Agent()
    {
        //Havent quite figured out what should go here yet...
    }

    void Agent::age()
    {
        __energy = __energy - AGENT_FATIGUE_RATE;
    }

    Piece &Agent::operator*(Piece &other)
    {
        return other.interact(this);
    }

    Piece &Agent::interact(Agent *otherAgent)
    {

        if(otherAgent->__energy == __energy)
        {
            finish();
            otherAgent->finish();
        }
        else if(otherAgent->__energy < this->__energy)
        {
            addEnergy(this->__energy);
            otherAgent->finish();
        }
        else
        {
            otherAgent->addEnergy(__energy);
            finish();
        }
        return *this;
    }

    Piece &Agent::interact(Resource *food)
    {
        //addEnergy(food->consume()); //For whatever reason, it doesn't want to read consume
        return *this;
    }
};

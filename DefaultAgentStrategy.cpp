//
// John-Marc Cloer
//

#include "DefaultAgentStrategy.h"

namespace Gaming
{
    DefaultAgentStrategy::DefaultAgentStrategy()
    {
        //Yay for defaults!!!
    }

    DefaultAgentStrategy::~DefaultAgentStrategy()
    {
        //More defaults!
    }

    ActionType DefaultAgentStrategy::operator()(const Surroundings &s) const
    {
        int position;
        for(int i = 0; i < 9; i++)
        {
            if(s.array[i] == SIMPLE || s.array[i] == EMPTY || s.array[i] == FOOD || s.array[i] == ADVANTAGE)
            {
                position = i;
            }
            else
            {
                return STAY;
            }
        }

        switch(position)
        {
            case 0:
                return NW;
            case 1:
                return N;
            case 2:
                return NE;
            case 3:
                return W;
            case 4:
                return STAY;
            case 5:
                return E;
            case 6:
                return SW;
            case 7:
                return S;
            case 8:
                return SE;
        }
    }
};

//
// John-Marc Cloer
//

#include "Exceptions.h"

namespace Gaming{


    void GamingException::setName(std::string name)
    {
        __name = name;
    }

    std::ostream& operator<<(std::ostream &os, const GamingException &ex)
    {
        os << ex.__name;
        return os;
    }

    DimensionEx::DimensionEx(unsigned expWidth, unsigned expHeight, unsigned width, unsigned height)
    {
        __exp_width = expWidth;
        __exp_height = expHeight;
        __width = width;
        __height = height;
    }

    unsigned DimensionEx::getExpWidth() const
    {
        return __exp_width;
    }

    unsigned DimensionEx::getExpHeight() const
    {
        return __exp_height;
    }

    unsigned DimensionEx::getWidth() const
    {
        return __width;
    }

    unsigned DimensionEx::getHeight() const
    {
        return __height;
    }

    void InsufficientDimensionsEx::__print_args(std::ostream &os) const
    {
        os << "There are Insufficent Dimensions." << std::endl;
        os << "The Expected Width is " << getExpWidth() << std::endl;
        os << "The Expected Height is " << getExpHeight() << std::endl;
        os << "The Current Width is " << getWidth() << std::endl;
        os << "The Current Height is " << getHeight() << std::endl;
    }

    InsufficientDimensionsEx::InsufficientDimensionsEx(unsigned minWidth, unsigned minHeight, unsigned width,
                                                       unsigned height) : DimensionEx(minWidth, minHeight, width, height)
    {
       //static GamingException::setName("InsufficientDimensionsEx");
    }

    void OutOfBoundsEx::__print_args(std::ostream &os) const
    {
        os << "You are now out of bounds." << std::endl;
        os << "The Expected Width is " << getExpWidth() << std::endl;
        os << "The Expected Height is " << getExpHeight() << std::endl;
        os << "The Current Width is " << getWidth() << std::endl;
        os << "The Current Height is " << getHeight() << std::endl;
    }

    OutOfBoundsEx::OutOfBoundsEx(unsigned maxWidth, unsigned maxHeight, unsigned width, unsigned height): DimensionEx(maxWidth ,maxHeight, width, height)
    {
        //static GamingException::setName("OutOfBoundsEx");
    }
};

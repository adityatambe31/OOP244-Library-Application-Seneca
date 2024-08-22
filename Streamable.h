// File	Streamable.h
// Version 1.0
// Author	Aditya Mahesh Tambe
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// Aditya Mahesh Tambe     07/08              init
/////////////////////////////////////////////////////////////////

#ifndef MS3_STREAMABLE_H
#define MS3_STREAMABLE_H
#include <iostream>

// using namespace std;
namespace seneca
{
    class Streamable
    {
    public:
        virtual std::ostream &write(std::ostream &) const = 0;
        virtual std::istream &read(std::istream &) = 0;
        virtual bool conIO(std::ios &io) const = 0;
        virtual operator bool() const = 0;
        virtual ~Streamable() = default;
        virtual std::ostream &operator<<(std::ostream &os) = 0;
        virtual std::istream &operator>>(std::istream &is) = 0;
    };
}
#endif // MS3_STREAMABLE_H

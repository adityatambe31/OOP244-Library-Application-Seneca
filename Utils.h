/***********************************************************************
// OOP244 Utils Module
// File	Utils.h
// Version
// Date
// Author
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//Aditya Mahesh Tambe 07-05           add the getInt
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SENECA_UTILS_H__
#define SENECA_UTILS_H__
#include <iostream>
namespace seneca
{
    class Utils
    {
    public:
        size_t getInt(size_t, size_t);
        int getMemberNum();
        char getType(unsigned int);
    };
    extern Utils ut;
}
#endif // SENECA_UTILS_H__

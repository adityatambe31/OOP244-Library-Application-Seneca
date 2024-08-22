/***********************************************************************
// OOP244 Utils Module
// File	Utils.cpp
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

#include <iostream>
#include "Utils.h"

using namespace std;
namespace seneca
{

    size_t Utils::getInt(size_t min, size_t max)
    {
        size_t val{};
        cin >> val;
        while (cin.fail() || val < min || val > max)
        {
            cout << "Invalid Selection, try again: ";
            cin.clear();
            cin.ignore(12000, '\n');
            cin >> val;
        }
        cin.ignore(12000, '\n');
        return val;
    }

    int Utils::getMemberNum()
    {
        int val{};
        cin >> val;
        while (cin.fail() || val < 10000 || val > 99999)
        {
            cout << "Invalid membership number, try again: ";
            cin.clear();
            cin.ignore(12000, '\n');
            cin >> val;
        }
        cin.ignore(12000, '\n');
        return val;
    }

    char Utils::getType(unsigned int num)
    {
        char ch = 'X';
        switch (num)
        {
        case 1:
            ch = 'B';
            break;
        case 2:
            ch = 'P';
            break;
        default: // not B or P
            ch = 'X';
            break;
        }
        return ch;
    }
}
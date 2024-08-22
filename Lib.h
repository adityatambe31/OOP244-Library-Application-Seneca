// File	Lib.h
// Version 1.0
// Author	Aditya Mahesh Tambe
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// Aditya Mahesh Tambe     07/08              init
/////////////////////////////////////////////////////////////////

#ifndef MS3_LIB_H
#define MS3_LIB_H
namespace seneca
{
    const int SENECA_MAX_LOAN_DAYS = 15;
    // maximum number of day a publication can be borrowed with no penalty
    const int SENECA_TITLE_WIDTH = 30;
    // The width in which the title of a publication should be printed on the console
    const int SENECA_AUTHOR_WIDTH = 15;
    // The width in which the author name of a book should be printed on the console
    const int SENECA_SHELF_ID_LEN = 4;
    // The width in which the shelf id of a publication should be printed on the console
    const int SENECA_LIBRARY_CAPACITY = 333;
    // Maximum number of publications the library can hold.
}
#endif // MS3_LIB_H

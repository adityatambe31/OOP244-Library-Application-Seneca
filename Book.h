// File	Book.h
// Version 1.0
// Author	Aditya Mahesh Tambe
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// Aditya Mahesh Tambe     07/14              init
// Aditya Mahesh Tambe     07/16              done
/////////////////////////////////////////////////////////////////
#ifndef MS4_BOOK_H
#define MS4_BOOK_H
#include "Publication.h"
using namespace seneca;
namespace seneca
{
    class Book : public Publication
    {
        char *m_authorName{};

    public:
        Book();
        // rule of three
        Book &operator=(const Book &);
        Book(const Book &);
        ~Book() override;

        char type() const override;
        std::ostream &write(std::ostream &) const override;
        std::istream &read(std::istream &) override;
        void set(int member_id) override;
        operator bool() const override;

        std::ostream &operator<<(std::ostream &os) override;
        std::istream &operator>>(std::istream &is) override;
    };
    std::ostream &operator<<(std::ostream &os, const Book &right);
    std::istream &operator>>(std::istream &is, Book &right);
}
#endif // MS4_BOOK_H

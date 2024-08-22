// File	Book.cpp
// Version 1.0
// Author	Aditya Mahesh Tambe
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// Aditya Mahesh Tambe     07/14              init
// Aditya Mahesh Tambe     07/16              done
/////////////////////////////////////////////////////////////////
#include <cstring>
#include <iomanip>
#include "Book.h"

using namespace seneca;
using namespace std;
namespace seneca
{

    Book::Book() : m_authorName{nullptr}
    {
    }

    Book &Book::operator=(const Book &B)
    {
        if (this != &B && B.m_authorName != nullptr)
        {
            delete[] m_authorName;
            m_authorName = nullptr;
            m_authorName = new char[strlen(B.m_authorName) + 1];
            strcpy(m_authorName, B.m_authorName);
            Publication::operator=(B);
        }
        else
        {
            delete[] m_authorName;
            m_authorName = nullptr;
        }
        return *this;
    }

    Book::Book(const Book &B) : Publication(B), m_authorName(nullptr)
    {
        *this = B;
    }
    Book::~Book()
    {
        delete[] m_authorName;
        m_authorName = nullptr;
    }

    char Book::type() const
    {
        return 'B';
    }

    std::ostream &Book::write(std::ostream &os) const
    {
        if (!(*this) || !m_authorName)
            return os;
        Publication::write(os);
        if (Publication::conIO(os))
        {
            os << ' ';

            if (m_authorName && m_authorName[0] != '\0')
            {
                if (strlen(m_authorName) > SENECA_AUTHOR_WIDTH)
                {
                    os.write(m_authorName, SENECA_AUTHOR_WIDTH);
                }
                else
                {
                    os << setw(SENECA_AUTHOR_WIDTH) << left << setfill(' ');
                    os << m_authorName;
                }
            }
            os << right << setfill(' ') << " |";
        }
        else
        {
            os << '\t' << m_authorName;
        }
        os << setfill(' ');
        return os;
    }

    std::istream &Book::read(istream &is)
    {
        char authorName[255]{};
        Publication::read(is);

        if (m_authorName != nullptr)
        {
            delete[] m_authorName;
            m_authorName = nullptr;
        }

        if (Publication::conIO(is))
        {
            is.ignore(1, '\n');
            cout << "Author: ";
            is.get(authorName, 256, '\n');
        }
        else
        {
            is.ignore(1, '\t');
            is.get(authorName, 255, '\n');
        }

        if (!is.fail())
        {
            m_authorName = new char[strlen(authorName) + 1];
            strcpy(m_authorName, authorName);
        }
        return is;
    }

    void Book::set(int member_id)
    {
        Publication::set(member_id);
        Publication::resetDate();
    }

    Book::operator bool() const
    {
        return (m_authorName != nullptr && m_authorName[0] != '\0' && Publication::operator bool());
    }

    ostream &Book::operator<<(ostream &os)
    {
        return write(os);
    }
    istream &Book::operator>>(istream &is)
    {
        return read(is);
    }

    ostream &operator<<(ostream &os, const Book &right)
    {
        return right.write(os);
    }
    istream &operator>>(istream &is, Book &right)
    {
        return right.read(is);
    }
}
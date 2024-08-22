// File	Publication.cpp
// Version 1.0
// Author	Aditya Mahesh Tambe
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// Aditya Mahesh Tambe     07/08              init
// Aditya Mahesh Tambe     07/13              done
/////////////////////////////////////////////////////////////////
#include <cstring>
#include <iomanip>
#include "Publication.h"

using namespace std;

using namespace seneca;

namespace seneca
{

    Publication::Publication() : m_title(nullptr), m_shelfId{""}, m_membership(0), m_libRef(-1), m_date()
    {
        // m_date = Date();
    }

    Publication::Publication(const Publication &P) : Publication()
    {
        //        *this = src;
        if (m_title != nullptr)
        {
            delete[] m_title;
            m_title = nullptr;
        }
        if (P.m_title != nullptr && P.m_title[0] != '\0')
        {
            m_title = new char[strlen(P.m_title) + 1];
            strcpy(m_title, P.m_title);
        }
        strcpy(m_shelfId, P.m_shelfId);
        m_membership = P.m_membership;
        m_libRef = P.m_libRef;
        m_date = P.m_date;
    }
    Publication &Publication::operator=(const Publication &P)
    {
        if (this != &P)
        {
            if (m_title != nullptr)
            {
                delete[] m_title;
                m_title = nullptr;
            }

            if (P.m_title != nullptr && P.m_title[0] != '\0')
            {
                m_title = new char[strlen(P.m_title) + 1];
                strcpy(m_title, P.m_title);
            }
            strcpy(m_shelfId, P.m_shelfId);
            m_membership = P.m_membership;
            m_libRef = P.m_libRef;
            m_date = P.m_date;
        }
        return *this;
    }
    Publication::~Publication()
    {
        if (m_title != nullptr)
        {
            delete[] m_title;
            m_title = nullptr;
        }
    }

    void Publication::set(int member_id)
    {
        if ((member_id < 99999 && member_id > 9999) || member_id == 0)
        {
            m_membership = member_id;
        }
    }

    void Publication::setRef(int value)
    {
        m_libRef = value;
    }

    void Publication::resetDate()
    {
        m_date = Date();
    }

    char Publication::type() const
    {
        return 'P';
    }

    bool Publication::onLoan() const
    {
        return (m_membership != 0);
    }

    Date Publication::checkoutDate() const
    {
        return m_date;
    }

    bool Publication::operator==(const char *title) const
    {
        return strstr(m_title, title) != nullptr;
    }

    Publication::operator const char *() const
    {
        return m_title;
    }
    int Publication::getRef() const
    {
        return m_libRef;
    }

    bool Publication::conIO(std::ios &io) const
    {
        return (&cin == &io) || (&cout == &io);
    }

    std::ostream &Publication::write(std::ostream &os) const
    {
        if (!(*this) || !m_date)
            return os;
        if (conIO(os))
        {
            os << "| " << setw(SENECA_SHELF_ID_LEN)
               << m_shelfId
               << " | ";

            if (strlen(m_title) > SENECA_TITLE_WIDTH)
            {
                os.write(m_title, SENECA_TITLE_WIDTH);
            }
            else
            {
                os << setw(SENECA_TITLE_WIDTH) << left << setfill('.');
                os << m_title;
            }
            os << right << setfill(' ');

            os << " | ";

            onLoan() ? os << m_membership : os << " N/A ";
            os << " | "
               << m_date
               << " |";
        }
        else
        {
            os << type() << '\t' << m_libRef << '\t' << m_shelfId << '\t' << m_title << '\t' << m_membership << '\t' << m_date;
        }
        return os;
    }
    std::istream &Publication::read(std::istream &istr)
    {
        // First, clear all the attributes by freeing the memory and setting everything to their default values.
        // constructor and de constructor instead
        delete[] m_title;
        m_title = nullptr;
        m_shelfId[0] = '\0';
        m_membership = 0;
        m_libRef = -1;
        m_date = Date();

        char titleTmp[256]{};

        char shelfTmp[SENECA_SHELF_ID_LEN + 1]{};
        int membershipTmp = 0;
        int libRefTmp = -1;
        Date dateTmp;

        if (conIO(istr))
        {
            cout << "Shelf No: ";
            istr >> shelfTmp;
            if (strlen(shelfTmp) != SENECA_SHELF_ID_LEN)
            {
                istr.setstate(std::ios::failbit);
            }
            else
            {
                istr.ignore();
            }
            cout << "Title: ";
            if (!istr.fail())
            {
                istr.getline(titleTmp, 256, '\n');
            }
            cout << "Date: ";
            if (!istr.fail())
            {
                istr >> dateTmp;
                if (!dateTmp)
                {
                    istr.setstate(std::ios::failbit);
                }
            }
        }
        else
        {
            istr >> libRefTmp;
            istr.ignore();
            istr.getline(shelfTmp, SENECA_SHELF_ID_LEN + 1, '\t');
            istr.getline(titleTmp, 256, '\t');
            istr >> membershipTmp;
            istr.ignore();

            istr >> dateTmp;
            if (!dateTmp)
                istr.setstate(std::ios::failbit);
        }
        // After the process of reading is done if istr is in a valid state:
        if (!istr.fail())
        {
            if (titleTmp[0] != '\0')
            {
                delete m_title;
                m_title = nullptr;
                m_title = new char[strlen(titleTmp) + 1];
                strcpy(m_title, titleTmp);
            }
            if (shelfTmp[0] != '\0')
            {
                strcpy(m_shelfId, shelfTmp);
            }
            m_membership = membershipTmp;
            m_libRef = libRefTmp;
            m_date = dateTmp;
        }
        return istr;
    }

    Publication::operator bool() const
    {
        return m_title != nullptr && m_shelfId[0] != '\0';
    }

    ostream &Publication::operator<<(ostream &os)
    {
        return write(os);
    }

    istream &Publication::operator>>(istream &is)
    {
        return read(is);
    }

    ostream &operator<<(ostream &os, const Publication &right)
    {
        return right.write(os);
    }
    istream &operator>>(istream &is, Publication &right)
    {
        return right.read(is);
    }
}

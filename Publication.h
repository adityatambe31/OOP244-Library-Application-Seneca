// File	Publication.h
// Version 1.0
// Author	Aditya Mahesh Tambe
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// Aditya Mahesh Tambe     07/08              init
/////////////////////////////////////////////////////////////////

#ifndef MS3_PUBLICATION_H
#define MS3_PUBLICATION_H
#define MAX_TITLE_LEN 255
#define MAX_SHELF_LEN 4

#include <iostream>
#include <ctime>
#include "Date.h"
#include "Lib.h"
#include "Streamable.h"

using namespace seneca;
namespace seneca
{
    class Publication : public Streamable
    {
        char *m_title{};
        char m_shelfId[MAX_SHELF_LEN + 1]{};
        int m_membership{};
        int m_libRef = -1;
        Date m_date;

    public:
        Publication();

        Publication(const Publication &);
        Publication &operator=(const Publication &);
        ~Publication() override;

        // Modifiers
        virtual void set(int member_id);
        // Sets the membership attribute to either zero or a five-digit integer.
        void setRef(int value);
        // Sets the **libRef** attribute value
        void resetDate();
        // Sets the date to the current date of the system.

        // Queries
        virtual char type() const;
        // Returns the character 'P' to identify this object as a "Publication object"
        bool onLoan() const;
        // Returns true is the publication is checkout (membership is non-zero)
        Date checkoutDate() const;
        // Returns the date attribute
        bool operator==(const char *title) const;
        // Returns true if the argument title appears anywhere in the title of the
        // publication. Otherwise, it returns false; (use strstr() function in <cstring>)
        operator const char *() const;
        // Returns the title attribute
        int getRef() const;
        // Returns the libRef attirbute.

        // implement Streamable
        bool conIO(std::ios &io) const override;
        std::ostream &write(std::ostream &) const override;
        std::istream &read(std::istream &) override;
        operator bool() const override;
        std::ostream &operator<<(std::ostream &os) override;
        std::istream &operator>>(std::istream &is) override;
    };
    std::ostream &operator<<(std::ostream &os, const Publication &right);
    std::istream &operator>>(std::istream &is, Publication &right);

}
#endif // MS3_PUBLICATION_H

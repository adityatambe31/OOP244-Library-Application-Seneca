// Name:Aditya Mahesh Tambe
// Seneca email:amtambe@myseneca.ca
// Seneca Student ID:171969223
// 2024-07-04 Creat this file
// 2024-07-05 done
#include "Menu.h"
#include "Utils.h"
using namespace seneca;
using namespace std;
namespace seneca
{
    Utils ut;
    MenuItem::MenuItem()
    {
        m_itemName = {};
    }
    // TODO: check the const is necessary or not
    MenuItem::MenuItem(const char *str)
    {
        if (str != nullptr && str[0] != '\0')
        {
            m_itemName = new char[strlen(str) + 1];
            strcpy(m_itemName, str);
        }
    }

    MenuItem::~MenuItem()
    {
        delete[] m_itemName;
    }

    MenuItem::operator bool() const
    {
        return m_itemName != nullptr && m_itemName[0] != '\0';
    }
    // return the address of m_itemName
    MenuItem::operator const char *() const
    {
        return m_itemName;
    }

    void MenuItem::display() const
    {
        if (m_itemName != nullptr && m_itemName[0] != '\0')
        {
            cout << m_itemName;
        }
    }

    Menu::Menu()
    {
        // no need just in case
        m_menuTitle = nullptr;
        noOfItems = 0;
    }
    Menu::Menu(const string str)
    {
        m_menuTitle = new char[str.length() + 1];
        strcpy(m_menuTitle, str.c_str());
        // no need just in case
        noOfItems = 0;
    }

    Menu::~Menu()
    {
        for (size_t i = 0; i < noOfItems; ++i)
        {
            if (m_menuItem[i] != nullptr)
                delete m_menuItem[i];
            m_menuItem[i] = nullptr;
        }
        delete[] m_menuTitle;
        m_menuTitle = nullptr;
    }

    void Menu::display() const
    {
        if (m_menuTitle != nullptr && m_menuTitle[0] != '\0')
        {
            //            cout << m_menuTitle << ":" << endl;
            cout << m_menuTitle << endl;
        }
        for (size_t i = 0; i < noOfItems; ++i)
        {
            cout.width(2);
            cout.fill(' ');
            cout.setf(ios::right);
            cout << i + 1;
            cout << "- " << m_menuItem[i]->m_itemName << endl;
            cout.unsetf(ios::right);
        }
        cout << " 0- Exit" << endl
             << "> ";
    }

    unsigned int Menu::run() const
    {
        unsigned int ret{};
        display();
        ret = (unsigned int)ut.getInt(0, noOfItems);
        return ret;
    }

    unsigned int Menu::operator~() const
    {
        return run();
    }
    /*get the menuItemContent
     * if the menuItemContent less max_items and not negative
     * set it's name as menuItemContent
     */
    Menu &Menu::operator<<(const char *menuItemContent)
    {
        if (noOfItems < MAX_MENU_ITEMS && noOfItems >= 0)
        {
            m_menuItem[noOfItems] = new MenuItem(menuItemContent);
            noOfItems++;
        }
        return *this;
    }
    Menu::operator int() const
    {
        return (int)noOfItems;
    }
    Menu::operator unsigned int() const
    {
        return (unsigned int)noOfItems;
    }

    Menu::operator bool() const
    {
        return noOfItems > 0;
    }
    // Overload the indexing operator to return the const char* cast of the corresponding MenuItem in the array of MenuItem pointers.
    // If the index passes the number of MenuItems in the Menu, loop back to the beginning.
    const char *Menu::operator[](unsigned int index) const
    {
        return (const char *)*m_menuItem[index % MAX_MENU_ITEMS];
    }

    std::ostream &operator<<(std::ostream &ostr, const Menu &menu)
    {
        return (menu.m_menuTitle != nullptr && menu.m_menuTitle[0] != '\0') ? ostr << menu.m_menuTitle : ostr;
    }

}

// Name:Aditya Mahesh Tambe
// Seneca email:amtambe@myseneca.ca
// Seneca Student ID:171969223
// 2024-07-04 Creat this file
// 2024-07-05 done
#ifndef SENECA_MENU_H
#define SENECA_MENU_H

#include <iostream>
#include <cstring>
#define MAX_MENU_ITEMS 20
namespace seneca
{

    class MenuItem
    {
        char *m_itemName{};
        MenuItem();
        MenuItem(const char *);
        ~MenuItem();
        // A MenuItem object cannot be copied from or assigned to another MenuItem object.
        MenuItem(const MenuItem &) = delete;
        MenuItem &operator=(const MenuItem &) = delete;

        operator bool() const;
        operator const char *() const;

        void display() const;
        friend class Menu;
    };
    class Menu
    {
        char *m_menuTitle{};
        MenuItem *m_menuItem[MAX_MENU_ITEMS]{};
        unsigned int noOfItems{};

    public:
        Menu();
        Menu(const std::string);
        ~Menu();

        Menu(const Menu &) = delete;
        Menu &operator=(const Menu &) = delete;
        // TODO:check this constructor
        Menu(MenuItem *) = delete;

        void display() const;
        unsigned int run() const;
        unsigned int operator~() const;
        Menu &operator<<(const char *);
        operator int() const;
        operator unsigned int() const;
        operator bool() const;
        const char *operator[](unsigned index) const;
        friend std::ostream &operator<<(std::ostream &, const Menu &);
    };
}

#endif // SENECA_MENU_H
#ifndef MENU_H
#define MENU_H

#include <string>

class UserInterface {

    public:
        void printWelcome();
        void printMainMenu(int&);
        void printCatalogMenu(int&);
        void printBookmarkMenu(int&);
        void printMyCoursesMenu(int&);
            
};

#endif
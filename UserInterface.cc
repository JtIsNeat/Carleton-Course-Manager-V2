#include <iostream>
#include <iomanip>
#include "UserInterface.h"

void UserInterface::printWelcome(){
    std::cout << "=========================================" << std::endl;
    std::cout << "         CARLETON COURSE MANAGER         " << std::endl;
    std::cout << "                                         " << std::endl;
    std::cout << "Developper: Jeremy Tran-Perez            " << std::endl;
    std::cout << "Version: 2.0.0                           " << std::endl;
    std::cout << "=========================================" << std::endl;
}


void UserInterface::printMainMenu(int& input){
    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "MAIN MENU"                                 << std::endl; 
    std::cout << "[1] View all Carleton Courses"             << std::endl;
    std::cout << "[2] Manage Bookmark"                       << std::endl;
    std::cout << "[3] Manage My Courses"                     << std::endl;
    std::cout << "[0] Quit"                                  << std::endl;
    std::cout << "\nInput: "                                             ;
    std::cin >> input;
    std::cout << "-----------------------------------------" << std::endl;
}


void UserInterface::printCatalogMenu(int& input){
    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "CARLETON COURSES"                          << std::endl; 
    std::cout << "[1] Sort by: Department/Year"              << std::endl;
    std::cout << "[2] Add course to Bookmark"                << std::endl;
    std::cout << "[3] Get course info"                       << std::endl;
    std::cout << "[0] Main Menu"                             << std::endl;
    std::cout << "\nInput: "                                             ;
    std::cin >> input;
    std::cout << "-----------------------------------------" << std::endl;
}

void UserInterface::printBookmarkMenu(int& input){
    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "BOOKMARKS"                                 << std::endl; 
    std::cout << "[1] Get course info"                       << std::endl;
    std::cout << "[2] Remove course from Bookmark"           << std::endl;
    std::cout << "[3] Import bookmark"                       << std::endl;
    std::cout << "[4] Export bookmark"                       << std::endl;
    std::cout << "[5] Clear bookmark"                        << std::endl;
    std::cout << "[0] Main Menu"                             << std::endl;
    std::cout << "\nInput: "                                             ;
    std::cin >> input;
    std::cout << "-----------------------------------------" << std::endl;
}

void UserInterface::printMyCoursesMenu(int& input){
    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "MY COURSES"                                << std::endl;
    std::cout << "[1] Print my courses"                      << std::endl; 
    std::cout << "[2] Get course info"                       << std::endl;
    std::cout << "[3] Import"                                << std::endl;
    std::cout << "[4] Clear"                                 << std::endl;
    std::cout << "[5] Print GPA"                             << std::endl;
    std::cout << "[0] Main Menu"                             << std::endl;
    std::cout << "\nInput: "                                             ;
    std::cin >> input;
    std::cout << "-----------------------------------------" << std::endl;

}







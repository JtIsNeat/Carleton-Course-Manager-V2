#include "MainControl.h"
#include <iostream>
#include <fstream>
#include <sstream>

MainControl::MainControl(){
    userInput = 0;
    courses = new CourseList();
    bookmark = new CourseList();
}

MainControl::~MainControl(){
    delete courses;
    delete bookmark;
}


void MainControl::runCarletonCourseCatalog(){
    bool flag = true;
    while(flag){
        UI.printCatalogMenu(userInput);
        switch(userInput){
            case 1: break;
            case 2: break;
            case 3: break;
            default: return;
        }
    }
}

void MainControl::runBookmarkManager(){
    bool flag = true;
    while(flag){
        UI.printBookmarkMenu(userInput);
        switch(userInput){
            case 1: break;
            case 2: break;
            case 3: break;
            case 4: break;
            case 5: break;
            default: return;
        }
    }
}

void MainControl::runMyCoursesManager(){

    std::string choice;
    
    bool flag = true;
    while(flag){
        UI.printMyCoursesMenu(userInput);
        switch(userInput){
            case 1:
                std::cout << std::endl << "Displaying all courses:\n" << std::endl;
                if(courses->isEmpty()){std::cout << "No courses to display." << std::endl;}
                courses->printAllCourses();
                std::cout << std::endl;                
                break;
            
            case 2:
                break;

            case 3: 
                importCourseData();
                break;
            
            case 4:
                std::cout << "\nAre you sure you want to clear your courses?(Y/N): ";
                std::cin >> choice;
                if(choice == "Y"){courses->clear();}
                std::cout << std::endl;
                break;

            case 5:
                std::cout << "\nGPA: " << courses->calculateGPA() << "\n" << std::endl;
                break;

            default: return;
        }    
    } 
}

void MainControl::importCourseData(){
    
    std::string filename;
    std::cout << "\nInput filename: ";
    std::cin >> filename;
    std::ifstream file(filename);
    
    if(!file.is_open()){
        std::cout << "\n[!] The file you specified could not be found. [!]\n" << std::endl;
        return;
    } 

    std::cout << "\nImporting data from '" << filename << "'\n" << std::endl;
    courses->clear();

    std::string line;

    std::cout << "Scraping web for data" << std::endl;

    while(std::getline(file, line)){
        std::istringstream iss(line);
        
        std::string department;
        int number;
        std::string credit;
        std::string grade;
        std::string title;
        iss >> department;
        iss >> number;
        iss >> credit;
        iss >> grade;
        title = WebScraper::getCourseTitle(department, number);

        courses->add(new Course(department, number, Credit::parseCredit(credit), Grade::parseGrade(grade), title));
    }

    file.close();
}




void MainControl::importCourseData1(){

    std::string filename;
    std::cout << "\nInput filename: ";
    std::cin >> filename;
    std::ifstream file(filename);
    
    if(!file.is_open()){
        std::cout << "\n[!] The file you specified could not be found. [!]\n" << std::endl;
        return;
    } 


    std::cout << "\nImporting data from '" << filename << "'\n" << std::endl;
    courses->clear();

    std::ofstream outfile;
    outfile.open("data.txt");

    std::string line;
    while(std::getline(file, line)){
        std::istringstream iss(line);
        
        std::string department;
        std::string     number;
        std::string     credit;
        std::string      grade;
        
        iss >> department;
        iss >> number;
        iss >> credit;
        iss >> grade;

        outfile << department + " " + number + " " + credit + " " + grade + "\n";

    }

    outfile.close();
    file.close();
}



void MainControl::run(){

    UI.printWelcome();

    bool flag = true;
    while(flag){
        UI.printMainMenu(userInput);
        switch(userInput){
            case 1: runCarletonCourseCatalog(); break;
            case 2: runBookmarkManager();       break;
            case 3: runMyCoursesManager();      break;
            default: flag = false;              break;
        }
    }
}
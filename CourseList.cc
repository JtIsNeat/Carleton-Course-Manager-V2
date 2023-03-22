#include <iostream>
#include <sstream>
#include "CourseList.h"

CourseList::CourseList() : size(0), courses(new Course*[MAX_ARR_SIZE]){
}

CourseList::~CourseList(){
    for(int i = 0; i < size; i++){
        delete courses[i];
    }
    delete[] courses;
}

void CourseList::printAllCourses(){
    for(int i = 0; i < size; i++){
        std::cout << courses[i]->toString() << std::endl;
    }
}

float CourseList::calculateGPA(){

    float totalCredits = 0;
    float totalGradePoints = 0;

    for(int i = 0; i < size; i++){
        if(courses[i]->matchGrade(Grade::WDN)){continue;}
        totalCredits += courses[i]->getNumericCredit();
        totalGradePoints += courses[i]->getNumericGrade();
    }

    return totalGradePoints / totalCredits;
}

void CourseList::add(Course* course){
    courses[size++] = course;
}

void CourseList::clear(){
    for(int i = 0; i < size; i++){
        delete courses[i];
    }
    size = 0;
}

bool CourseList::isEmpty(){
    return(size == 0);
}
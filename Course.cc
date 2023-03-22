#include <sstream>
#include <iostream>
#include <iomanip>
#include "Course.h"

Course::Course(std::string dept, int num, Credit cred, Grade grade, std::string t, std::string desc)
    :department(dept), number(num), credit(cred), grade(grade), title(t), description(desc){
}

Course::~Course(){
}

std::string Course::toString(){
    std::stringstream ss;
    ss << getCourseCode() << " [" << std::fixed << std::setprecision(1) << credit.getNumeric() << "] " << std::left << std::setw(MAX_TITLE_LENGTH) << title << " | " << std::left << std::setw(3) << grade.getLetterGrade();
    return ss.str();
}

std::string Course::getCourseCode(){
    std::stringstream ss;
    ss << department << " " << std::setw(4) << std::setfill('0') << number;
    return ss.str();
}

float Course::getNumericCredit(){
    return credit.getNumeric();
}

float Course::getNumericGrade(){
    switch(credit){
        case Credit::QUARTER: return grade.getQuarterGradePoint();
        case Credit::HALF:    return grade.getHalfGradePoint();
        case Credit::FULL:    return grade.getFullGradePoint();
        default:              return -1;
    }
}

bool Course::matchCredit(Credit credit){
    return(this->credit == credit);
}

bool Course::matchGrade(Grade grade){
    return(this->grade == grade);
}

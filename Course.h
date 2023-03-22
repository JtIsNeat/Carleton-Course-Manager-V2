#ifndef COURSE_H
#define COURSE_H

#include "Grade.h"
#include "Credit.h"
#include <vector>
#include "definitions.h"

class Course {
    public:
        Course(std::string = "NONE", int = 0, Credit = Credit::HALF, Grade = Grade::WDN, std::string = "UNDEFINED", std::string = "UNDEFINED");
        ~Course();
        std::string getCourseCode();
        std::string toString();
        float getNumericGrade();
        float getNumericCredit();
        bool matchGrade(Grade);
        bool matchCredit(Credit);


    private:
        int number;
        Credit credit;
        Grade grade;
        std::string department;
        std::string title;
        std::string description;
};
#endif

#ifndef COURSELIST_H
#define COURSELIST_H

#include <string>
#include "definitions.h"
#include "Course.h"


class CourseList {

    public:
        CourseList();
        ~CourseList();
        float calculateGPA();
        void printAllCourses();
        void add(Course*);
        void remove(Course*);
        void clear();
        bool isEmpty();
        

    private:
        Course** courses = new Course*[MAX_ARR_SIZE];
        int size;

};
#endif
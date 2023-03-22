#ifndef WEBSCRAPER_H
#define WEBSCRAPER_H

#include <string>
#include "CourseList.h"

class WebScraper {

    public:
        static std::string getCourseTitle(std::string, int);
        static void populateMyCourses(CourseList*, std::string[], int[], std::string[], std::string[]);
        static void getCourseInfo(std::string);

    private:
        
};

#endif
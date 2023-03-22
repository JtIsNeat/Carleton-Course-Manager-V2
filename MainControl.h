#ifndef MAINCONTROL_H
#define MAINCONTROL_H

#include "UserInterface.h"
#include "WebScraper.h"
#include "CourseList.h"
#include <vector>

class MainControl {

    public:
        MainControl();
        ~MainControl();
        void run();

    private:
        UserInterface UI;
        WebScraper WS;
        CourseList* bookmark;
        CourseList* courses;
        int userInput;
        void runCarletonCourseCatalog();
        void runBookmarkManager();
        void runMyCoursesManager();
        void importCourseData1();
        void importCourseData();


};
#endif
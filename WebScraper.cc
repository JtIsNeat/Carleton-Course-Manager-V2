#include "WebScraper.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

std::string WebScraper::getCourseTitle(std::string department, int number){

    std::string args = "python script.py " + department + " " + std::to_string(number);

    FILE* pipe = popen(args.c_str(), "r");
    if(!pipe) {
        perror("popen failed");
        return "";
    }

    std::vector<std::string> lines;
    char buffer[128];
    while (fgets(buffer, sizeof(buffer), pipe)) {
        lines.push_back(buffer);
    }

    pclose(pipe);
    if(lines.size() > 0){
        std::string str = lines[0];

        str.erase(str.begin(), std::find_if(str.begin(), str.end(), [](int ch) {
            return !std::isspace(ch);
        }));

        str.erase(std::find_if(str.rbegin(), str.rend(), [](int ch) {
            return !std::isspace(ch);
        }).base(), str.end());

        return str;
    }

    return "";
}

void WebScraper::populateMyCourses(CourseList* courses, std::string courseDepartments[], int courseNumbers[], std::string courseCredits[], std::string courseGrades[]){
    


}



void WebScraper::getCourseInfo(std::string course_code){

}
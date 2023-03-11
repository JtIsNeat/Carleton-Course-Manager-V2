#ifndef DEFS_H
#define DEFS_H

#include <string>

enum class GradePointScale {
    APLUS = 0,
    A,
    AMINUS,
    BPLUS,
    B,
    BMINUS,
    CPLUS,
    C,
    CMINUS,
    DPLUS,
    D,
    DMINUS,
    F,
    WDN
};

struct GradePointScaleProperties {
    std::string letterGrade;
    double quarterGradePoint;
    double halfGradePoint;
    double fullGradePoint;
};

const std::array<GradePointScaleProperties, 14> GRADE_POINT_SCALE_PROPERTIES {
    { 
        {"A+", 3.0, 6.0, 12.0},
        {"A", 2.75, 5.5, 11.0},
        {"A-", 2.5, 5.0, 10.0},
        {"B+", 2.25, 4.5, 9.0},
        {"B", 2.0, 4.0, 8.0},
        {"B-", 1.75, 3.5, 7.0},
        {"C+", 1.5, 3.0, 6.0},
        {"C", 1.25, 2.5, 5.0},
        {"C-", 1.0, 2.0, 4.0},
        {"D+", 0.75, 1.5, 3.0},
        {"D", 0.5, 1.0, 2.0},
        {"D-", 0.25, 0.5, 1.0},
        {"F", 0.0, 0.0, 0.0},
        {"WDN", 0.0, 0.0, 0.0}
    }
};

const GradePointScaleProperties& getGradePointScaleProperties(GradePointScale gradePointScale) {
    return GRADE_POINT_SCALE_PROPERTIES[static_cast<int>(gradePointScale)];
}

#endif 
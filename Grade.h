#ifndef GRADE_H
#define GRADE_H

#include <string>
#include <stdexcept>

class Grade{

    public:
        enum Enum {
            APLUS =  0, A     =  1, AMINUS = 2,
            BPLUS =  3, B     =  4, BMINUS = 5,
            CPLUS =  6, C     =  7, CMINUS = 8,
            DPLUS =  9, D     = 10, DMINUS = 11,
            F     = 12, WDN   = 13
        };

        Grade(Enum e) : e(e){
            switch(e){
                case  APLUS: letterGrade =  "A+"; quarterGradePoint =  3.0; halfGradePoint = 6.0; fullGradePoint = 12.0; break;
                case      A: letterGrade =   "A"; quarterGradePoint = 2.75; halfGradePoint = 5.5; fullGradePoint = 11.0; break;
                case AMINUS: letterGrade =  "A-"; quarterGradePoint =  2.5; halfGradePoint = 5.0; fullGradePoint = 10.0; break;
                case  BPLUS: letterGrade =  "B+"; quarterGradePoint = 2.25; halfGradePoint = 4.5; fullGradePoint =  9.0; break;
                case      B: letterGrade =   "B"; quarterGradePoint =  2.0; halfGradePoint = 4.0; fullGradePoint =  8.0; break;
                case BMINUS: letterGrade =  "B-"; quarterGradePoint = 1.75; halfGradePoint = 3.5; fullGradePoint =  7.0; break;
                case  CPLUS: letterGrade =  "C+"; quarterGradePoint =  1.5; halfGradePoint = 3.0; fullGradePoint =  6.0; break;
                case      C: letterGrade =   "C"; quarterGradePoint = 1.25; halfGradePoint = 2.5; fullGradePoint =  5.0; break;
                case CMINUS: letterGrade =  "C-"; quarterGradePoint =  1.0; halfGradePoint = 2.0; fullGradePoint =  4.0; break;
                case  DPLUS: letterGrade =  "D+"; quarterGradePoint = 0.75; halfGradePoint = 1.5; fullGradePoint =  3.0; break;
                case      D: letterGrade =   "D"; quarterGradePoint =  0.5; halfGradePoint = 1.0; fullGradePoint =  2.0; break;
                case DMINUS: letterGrade =  "D-"; quarterGradePoint = 0.25; halfGradePoint = 0.5; fullGradePoint =  1.0; break;
                case      F: letterGrade =   "F"; quarterGradePoint =  0.0; halfGradePoint = 0.0; fullGradePoint =  0.0; break;
                case    WDN: letterGrade = "WDN"; quarterGradePoint =  0.0; halfGradePoint = 0.0; fullGradePoint =  0.0; break;
            }
        }

        // Allows comparisons with Enum constants
        operator Enum() const {return e;} 

        // Needed to prevent if(c)
        explicit operator bool() const = delete;

  
        std::string getLetterGrade() const {return letterGrade;}
        double getQuarterGradePoint() const {return quarterGradePoint;}
        double getHalfGradePoint() const {return halfGradePoint;}
        double getFullGradePoint() const {return fullGradePoint;}

        static Grade::Enum parseGrade(std::string& str){
            if (str == "APLUS")  return Grade::APLUS;
            if (str == "A")      return Grade::A;
            if (str == "AMINUS") return Grade::AMINUS;
            if (str == "BPLUS")  return Grade::BPLUS;
            if (str == "B")      return Grade::B;
            if (str == "BMINUS") return Grade::BMINUS;
            if (str == "CPLUS")  return Grade::CPLUS;
            if (str == "C")      return Grade::C;
            if (str == "CMINUS") return Grade::CMINUS;
            if (str == "DPLUS")  return Grade::DPLUS;
            if (str == "D")      return Grade::D;
            if (str == "DMINUS") return Grade::DMINUS;
            if (str == "F")      return Grade::F;
            if (str == "WDN")    return Grade::WDN;
            throw std::invalid_argument("Invalid grade value: " + str);
        }


    private:
        Enum e;
        std:: string letterGrade;
        double quarterGradePoint;
        double    halfGradePoint;
        double    fullGradePoint;
};

#endif
#ifndef CREDIT_H
#define CREDIT_H

#include <stdexcept>

class Credit {

    public:

        enum Enum {
            QUARTER = 1,
            HALF    = 2,
            FULL    = 4    
        };

        constexpr Credit(Enum e) : e(e){}

        // Allows comparisons with Enum constants
        constexpr operator Enum() const {return e;} 

        // Needed to prevent if(c)
        explicit operator bool() const = delete;


        double getNumeric() const{
            switch(e){
                case QUARTER: return 0.25;
                case    HALF: return 0.5;
                case    FULL: return 1.0;
                default:      return -1;
            }
        }    
        
        static Credit parseCredit(std::string& str){
            if(str == "QUARTER"){return Credit::QUARTER;}
            if(str == "HALF"){return Credit::HALF;}
            if(str == "FULL"){return Credit::FULL;}
            throw std::invalid_argument("Invalid credit value: " + str);
        }

    private:
        Enum e;
};

#endif
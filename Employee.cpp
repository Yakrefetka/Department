#include <iostream>
#include "Employee.h"
namespace Empl{

    std::istream& Employee::get(std::istream& is){
        std::cout<<std::endl<<"Surname:";
        is >> Surname;
        std::cout<<std::endl<<"Year of birth:";
        is >> Year;
        std::cout<<std::endl<<"Education:";
        is >> Education;
        std::cout<<std::endl<<"Salary:";
        is >> Salary;
        std::cout<<std::endl<<"Position:";
        is >> Position;
        Type = "regular";
        return is;
    }
    std::istream& Boss::get(std::istream& is){
        std::cout<<std::endl<<"Surname:";
        is >> Surname;
        std::cout<<std::endl<<"Year of birth:";
        is >> Year;
        std::cout<<std::endl<<"Education:";
        is >> Education;
        std::cout<<std::endl<<"Salary:";
        is >> Salary;
        std::cout<<std::endl<<"Position:";
        is >> Position;
        std::cout<<std::endl<<"Unitname:";
        is >> UnitName;
        Type = "boss";
    }
    std::ostream& Employee::show(std::ostream& os)const{
         os<<"Our Employee is "<<Surname<<std::endl<<"Year of birth is "<<Year<<std::endl;
         os<<"His salary is "<<Salary<<std::endl<<"His education is "<<Education<<std::endl;
         os<<"His position is "<<Position<<std::endl<<"Type of worker is "<<Type<<std::endl;
         return os;
    }
    std::ostream& Boss::show(std::ostream& os)const{
         os<<"Our Employee is "<<Surname<<std::endl<<"Year of birth is "<<Year<<std::endl;
         os<<"His salary is "<<Salary<<std::endl<<"His education is "<<Education<<std::endl;
         os<<"His position is "<<Position<<std::endl<<"Type of worker is "<<Type<<std::endl;
         os<<"Name of his Unit:"<<UnitName<<std::endl;
         return os;
    }
    std::ostream& operator <<(std::ostream& os,const Employee &p)
    {
        p.show(os);
    }
    std::istream& operator >>(std::istream& is,Employee &p){
        p.get(is);
    }


}

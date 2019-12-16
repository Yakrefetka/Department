#ifndef _Company_h_
#define _Company_h_
#include <iostream>
#include <map>
#include <string>
#include "Employee.h"
//std::ostream & operator<<(std::ostream &,const std::pair<const int,Empl::Employee *> & );
namespace Prog4{
    class Unit{
    private:
        std::string UnitName;
        std::map <const int, Empl::Employee *> MpU;
    public:
        Unit(std::string U):UnitName(U){};
        Unit(const Unit&);
        ~Unit();
        Unit& operator = (const Unit&);
        bool insert(const int&,const Empl::Employee *);
        Empl::Employee& find(const int&);
        bool remove(const int&);
        std::string GetName(){return UnitName;}
        std::ostream& show(std::ostream&)const;
        virtual Unit* clone()const{return new Unit(*this);}
        //std::ostream & operator<<(std::ostream &,const std::pair<const int,Empl::Employee *> & )
    };
    class Company{
    private:
        std::string CompanyName;
        std::map <const std::string, Prog4::Unit *> MpC;
    public:
        Company(std::string C):CompanyName(C){};
        ~Company();
        Company& operator = (const Company&);
        virtual Company* clone() const{return new Company(*this);}
        bool insert(const std::string& ,const Prog4::Unit *);
        std::ostream& show(std::ostream&)const;
        Prog4::Unit& find(const std::string&);
        bool remove(const std::string&);
        //std::ostream & operator<<(std::ostream &,const std::pair<const std::string, Prog4::Unit *> & )
        std::string GetName(){return CompanyName;}

    };

};
#endif

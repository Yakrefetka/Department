#ifndef _Employee_h_
#define _Employee_h_
#include <iostream>
#include <string>

namespace Empl{
    class Employee{
    protected:
        int Year;
        int Salary;
        std::string Surname;
        std::string Education;
        std::string Position;
        std::string Type;
    public:
        Employee(){};
        Employee(int Y,int S,std::string Sur, std::string E,std::string P,std::string T){
            Year = Y;
            Salary = S;
            Surname = Sur;
            Education = E;
            Position = P;
            Type = T;
         }
        Employee& setYear(int a){Year = a;return *this;}
        Employee& setSalary(int a){Salary = a;return *this;}
        Employee& setSurname(std::string b){Surname = b;return *this;}
        Employee& setEducation(std::string b){Education = b;return *this;}
        Employee& setPosition(std::string b){Position = b;return *this;}
        Employee& setType(std::string c){Type = c;return *this;}
        Employee& ChangePosition(std::string p){Position = p;}
        Employee& ChangeSalary(int s){Salary = s;}
        int GetSalary(){return Salary;}
        std::string GetPosition(){return Position;}
        std::string GetType(){return Type;}
        friend std::ostream & operator << (std::ostream &, const Employee&);
        friend std::istream & operator >> (std::istream &, Employee&);
        virtual std::istream& get(std::istream&);
        virtual std::ostream& show(std::ostream&)const;
        virtual ~Employee(){}
        virtual Employee* clone()const{return new Employee(*this);}
    };

    class Boss: public Employee{
    protected:
    std::string UnitName;
    public:
    Boss(){}
    Boss(int Y1,int S1,std::string Sur1, std::string E1,std::string P1,std::string T1,std::string U1):Employee(Y1,S1,Sur1,E1,P1,T1),UnitName(U1){}
    Boss(Employee &E,std::string U):Employee(E),UnitName(U){};
    virtual std::istream& get(std::istream&);
    virtual std::ostream& show(std::ostream&)const;
    virtual ~Boss(){}
    virtual Boss* clone()const{return new Boss(*this);}

    };
};
#endif


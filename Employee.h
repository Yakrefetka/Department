#ifndef _Employee_h_
#define _Employee_h_
#include <iostream>
#include <string>


namespace EM{
enum e_type
{
   regular,
   executive
};

class Employee{
private:
    e_type _Type;
    int Id;
    int Yearofbirth;
    int Salary;
    std::string Surname;
    std::string Education;
    std::string Position;
protected:
    virtual std::ostream& show(std::ostream&)const = 0;
public:
    std::string GetPosition(){return Position;}
    int GetSalary(){return Salary;}
    void ChangePosition(std::string p){Position = p;}
    void ChangeSalary(int s){Salary = s;}
    e_type GetType(){return _Type;}
    friend std::ostream & operator<<(std::ostream &, const Employee&)
    virtual ~Employee(){}
};

class Regular: public Employee{
public:
    e_type Promote(){}//лекции

};
class Executive: public Employee{
private:
   Unit *info;
};

#endif

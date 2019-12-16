#include <string>
#include <iostream>
#include "Companies.h"
#include "Employee.h"

using namespace Empl;
using namespace Prog4;

const std::string Names[] = {"Unknown","Regular","Boss"};
const std::string Menu[] = {"1. Hire a worker", "2. Change worker's position",
"3.Fire a worker", "4. Show this unit's workers"},
                Choice = "Make your choice",
                Msg = "You are wrong;repeat please";

int Answer(const std::string alt[], int n);
int Hire(Unit &), Change(Unit &), Fire(Unit &), Show(Unit &)/*, ShowAll(Company &)*/;
int(*Funcs[])(Unit &) = { nullptr, Hire, Change, Fire, Show, /*ShowAll*/};
const int Num = sizeof(Menu)/sizeof(Menu[0]);

int main(){
    std::string CName;
    int n;
    std::cout<<"What is Company's name?"<<std::endl;
    std::cin>>CName;
    Company c("CName");
    std::string fName;
    std::cout<<"1 unit name?"<<std::endl;
    std::cin>>fName;
    Unit ar("fName");
    std::string sName;
    std::cout<<"2 unit name?"<<std::endl;
    std::cin>>sName;
    Unit br("sName");
    std::string tName;
    std::cout<<"3 unit name?"<<std::endl;
    Unit cr("tName");
    std::cin>>tName;
    c.insert(fName,&ar);
    c.insert(sName,&br);
    c.insert(tName,&cr);

    int ind;
    try{
    std::cout<<"working with 1 unit:"<<std::endl;
    while (ind = Answer(Menu, Num)){
    Funcs[ind](ar);
    }
    std::cout<<"working with 2 unit:"<<std::endl;
    while (ind = Answer(Menu, Num)){
    Funcs[ind](br);
    }
    std::cout<<"working with 3 unit:"<<std::endl;
    while (ind = Answer(Menu, Num)){
    Funcs[ind](cr);
    }
    c.show(std::cout);
    std::cout << "That's all. Bye!" << std::endl;
    }
    catch (const std::exception &er)
    {
    std::cout << er.what() << std::endl;
    }
    return 0;
    }
    int Answer(const std::string alt[], int n)
    {
    int answer;
    std::string prompt = Choice;
    std::cout << "\nWhat do you want to do:" << std::endl;
    for(int i = 0; i < n; i++)
    std::cout << alt[i].c_str() << std::endl;
    do{
    std::cout << prompt.c_str() << ": -> ";
    prompt = Msg;
    std::cin >> answer;
    if (!std::cin.good()){
    std::cout << "Error when number of choice was entered; \nRepeat, please." << std::endl;
    std::cin.ignore(80, '\n');
    std::cin.clear();
    }
    } while (answer < 0 || answer >= n);
    std::cin.ignore(80, '\n');
    return answer;
    }

    const std::string Sh[] = {"1. Employee", "2. Boss", "0. Quit"};
    const int NumSh = sizeof(Sh) / sizeof(Sh[0]);


    int Hire(Unit &a)
    {
    Employee *ptr = nullptr;
    Employee c;
    Boss p;
    int id;
    int ans;
    while(ans = Answer(Sh, NumSh)){
    std::cout << "Enter worker's ID: --> ";
    std::cin >> id;
    if (!std::cin.good())  throw std::logic_error("Error when a ID was entered");
    switch (ans){
    case 1:
    std::cout << "Enter information for an employee: --> ";
    ptr = &c;
    break;
    case 2:
    std::cout << "Enter information for a boss: --> ";
    ptr = &p;
    break;
    }
    std::cin >> (*ptr);
    if (!std::cin.good())
    throw std::logic_error("Error when values were entered");
    std::cin.ignore(80, '\n');
    if (a.insert(id, ptr))
    std::cout << "Ok" << std::endl;
    else
    std::cout << "Duplicate ID" << std::endl;
    }
    return 0;
    }
    int Change(Unit &a){
    int id;
    std::string new_pos;
    const Employee *ptr = nullptr;
    std::cout << "Enter a worker's ID: --> ";
    std::cin >> id;
    if (!std::cin.good())
    throw std::logic_error("Error when ID was entered");
    std::cout << "Enter new position: --> ";
    std::cin >> new_pos;
    if (!std::cin.good())
    throw std::logic_error("Error when postion was entered");
    a.find(1).ChangePosition(new_pos);
    std::cout<<"Ok"<<std::endl;
    return 0;
    }
    int Fire(Unit &a)
    {
    int id;
    const Employee *ptr = nullptr;
    std::cout << "Enter worker's ID: --> ";
    std::cin >> id;
    if (!std::cin.good())
    throw std::logic_error("Error when ID was entered");
    if (a.remove(id))
    std::cout << "Ok" << std::endl;
    else
    std::cout<<"Employee with ID \""<< id<<"\is absent in container"<<std::endl;
    return 0;
    }

    int Show(Unit &a){
    a.show(std::cout);
    return 0;
    }
    int ShowAll(Company &b){
    b.show(std::cout);
    return 0;
    }

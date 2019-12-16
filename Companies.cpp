#include <iostream>
#include "Companies.h"

namespace Prog4{
    Empl::Employee& Unit::find(const int&s){
        return *(MpU.find(s))->second;
    }
    std::ostream& Unit::show(std::ostream& os)const{
    for (std::map<const int, Empl::Employee *>::const_iterator i = MpU.begin(), end = MpU.end(); i != end; ++i)
            {
        os << "Worker Id: " << i->first <<std::endl;
        Empl::Employee *e = i->second;
        e->show(os);

        //либо сначала сделать переменную с указателем,оттуда бы выводилась
    }
         return os;
    }

    Unit::Unit(const Unit &a)
    {
        std::map<const int,Empl::Employee *>::const_iterator p;
        for (p = a.MpU.begin(); p != a.MpU.end(); ++p)
        MpU.insert(std::make_pair(p->first, p->second->clone()));
    }
    Unit::~Unit()
    {
        std::map<const int, Empl::Employee *>::iterator p;
        for (p = MpU.begin(); p != MpU.end(); ++p){
        delete p->second;
        p->second = nullptr;
        }
    }
    Unit& Unit::operator=( const Unit &a)
    {
        std::map<const int, Empl::Employee*>::iterator p;
        if (this != &a){
        for (p = MpU.begin(); p != MpU.end(); ++p)
        delete p->second;
        MpU.clear();
        std::map<const int, Empl::Employee *>::const_iterator pp;
        for (pp = a.MpU.begin(); pp != a.MpU.end(); ++pp)
        MpU.insert(std::make_pair(pp->first, pp->second->clone()));
        }
        return *this;
    }
    bool Unit::insert(const int &s, const Empl::Employee *f){
        bool res = false;
        std::map<const int, Empl::Employee *>::iterator p = MpU.find(s);
        if (p == MpU.end()){
        std::pair<std::map<const int, Empl::Employee *>::iterator, bool> pp =
            MpU.insert(std::make_pair(s, f->clone()));
        if (!pp.second)
        throw ("can't insert new item into map");
        res = true;
        }
        return res;
    }

    bool Unit::remove(const int &s)
    {
        bool res = false;
        std::map<const int, Empl::Employee *>::iterator p = MpU.find(s); //arr.erase(s);
        if (p != MpU.end()){
        delete p->second;
        p->second = nullptr;
        MpU.erase(p);
        res = true;
        }
        return res;
    }
    Company::~Company()
    {
        std::map<const std::string, Prog4::Unit *>::iterator p;
        for (p = MpC.begin(); p != MpC.end(); ++p){
        delete p->second;
        p->second = nullptr;
        }

    }
    Company& Company::operator=(const Company &a)
    {
        std::map<const std::string, Prog4::Unit*>::iterator p;
        if (this != &a){
        for (p = MpC.begin(); p != MpC.end(); ++p)
        delete p->second;
        MpC.clear();
        std::map<const std::string, Prog4::Unit *>::const_iterator pp;
        for (pp = a.MpC.begin(); pp != a.MpC.end(); ++pp)
        MpC.insert(std::make_pair(pp->first, pp->second->clone()));
        }
        return *this;
    }
    bool Company::insert(const std::string&s, const Prog4::Unit *f){
        bool res = false;
        std::map<const std::string, Prog4::Unit *>::iterator p = MpC.find(s);
        if (p == MpC.end()){
        std::pair<std::map<const std::string, Prog4::Unit *>::iterator, bool> pp =
            MpC.insert(std::make_pair(s, f->clone()));
        if (!pp.second)
        throw ("can't insert new item into map");
        res = true;
        }
        return res;
    }
    Prog4::Unit& Company::find(const std::string &s){
        return *(MpC.find(s))->second;
    }

    bool Company::remove(const std::string &s)
    {
        bool res = false;
        std::map<const std::string, Prog4::Unit *>::iterator p = MpC.find(s); //arr.erase(s);
        if (p != MpC.end()){
        delete p->second;
        p->second = nullptr;
        MpC.erase(p);
        res = true;
        }
        return res;
    }
    std::ostream& Company::show(std::ostream& os)const{
    for (std::map<const std::string, Prog4::Unit *>::const_iterator i = MpC.begin(), end = MpC.end(); i != end; ++i)
            {
        os << "Unit Name: " << i->first <<std::endl;
        Prog4::Unit *e = i->second;
        e->show(os);

        //либо сначала сделать переменную с указателем,оттуда бы выводилась
    }
         return os;
    }
}

#pragma once

#include <iostream>

using namespace std;

class Person
{
protected:
    string name;
    string email;
    string password;

public:

    Person() {}

    Person(string name, string email, string password)
    {
        this->name = name;
        this->email = email;
        this->password = password;
    }

    // ================= GETTERS =================

    string getName() const
    {
        return name;
    }

    string getEmail() const
    {
        return email;
    }

    string getPassword() const
    {
        return password;
    }

    // ================= SETTERS =================

    void setPassword(string password)
    {
        this->password = password;
    }

    // ================= PURE VIRTUAL FUNCTION =================

    virtual void getPerson() = 0;
};
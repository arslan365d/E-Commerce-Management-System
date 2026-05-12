#pragma once

#include <iostream>
#include "person.h"

using namespace std;

class User : public Person
{
private:
    double balance;

public:

    User() {}

   User(string name, string email, string password, double balance)
    : Person(name, email, password)
{
    this->balance = balance;
}

    // ================= GETTERS =================

    double getBalance() const
    {
        return balance;
    }

    // ================= SETTERS =================

    void setBalance(double balance)
    {
        this->balance = balance;
    }

    // ================= PROFILE =================

    void getPerson() override
    {
        cout << "\n\033[1;36m";
        cout << "=====================================================\n";
        cout << "                    USER PROFILE                     \n";
        cout << "=====================================================\n";
        cout << "\033[0m";

        cout << "Name     : " << name << endl;
        cout << "Email    : " << email << endl;
        cout << "Password : " << password << endl;
        cout << "Balance  : Rs. " << balance << endl;

        cout << "=====================================================\n";
    }
    void setData(string name, string email, string password, double balance)
{
    this->name = name;
    this->email = email;
    this->password = password;
    this->balance = balance;
}
};
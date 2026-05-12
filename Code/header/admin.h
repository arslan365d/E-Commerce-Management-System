#pragma once

#include <iostream>
#include <vector>

#include "person.h"
#include "user.h"

using namespace std;

class Admin : public Person
{
public:
  Admin() {}

  Admin(string name,
        string email,
        string password)
      : Person(name, email, password)
  {
  }

  // ================= ADMIN PROFILE =================

  void getPerson() override
  {
    cout << "\nName     : " << name << endl;
    cout << "Email    : " << email << endl;
    cout << "Password : " << password << endl;
  }

  // ================= VIEW USERS =================

  static void viewUsers(vector<User> &users)
  {
    if (users.empty())
    {
      cout << "\033[31mNo Users Found!\033[0m\n";
      return;
    }

    cout << "\n\033[1;35m";
    cout << "=====================================================\n";
    cout << "                     ALL USERS                       \n";
    cout << "=====================================================\n";
    cout << "\033[0m";

    for (int i = 0; i < users.size(); i++)
    {
      cout << "\nUser #" << i + 1 << endl;
      cout << "-------------------------------------\n";
      cout << "Name  : " << users[i].getName() << endl;
      cout << "Email : " << users[i].getEmail() << endl;
    }

    cout << "\n=====================================================\n";
  }
};

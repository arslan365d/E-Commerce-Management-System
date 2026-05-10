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

  Admin(string name, string email, string password)
      : Person(name, email, password)
  {
  }

  void getPerson() override
  {
    cout << "\nName: " << name << endl
         << "Email: " << email << endl
         << "Password: " << password << endl;
  }

  static void viewUsers(vector<User> &users)
  {
    for (int i = 0; i < users.size(); i++)
    {
      cout << users[i].getName()
           << " " << users[i].getEmail() << endl;
    }
  }

  

};
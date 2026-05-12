#pragma once

#include <iostream>
#include <limits>
#include <windows.h>
#include <mmsystem.h>

using namespace std;

class Utility
{
public:

    // ================= GENERIC INPUT =================

    template <typename T>
    static T input(string message)
    {
        T value;

        cout << "\033[33m" << message << " \033[0m";

        while (!(cin >> value))
        {
            cin.clear();

            cin.ignore(
                numeric_limits<streamsize>::max(),
                '\n');

            PlaySound(TEXT("./sounds/fahh.wav"),
                      NULL,
                      SND_ASYNC);

            cout << "\033[31mInvalid Input! Try Again.\033[0m\n";

            cout << "\033[33m" << message << " \033[0m";
        }

        cin.ignore(
            numeric_limits<streamsize>::max(),
            '\n');

        return value;
    }

    // ================= BALANCE INPUT =================

    static double inputBalance(string message)
    {
        double value;

        cout << message;

        while (!(cin >> value) || value < 0)
        {
            cin.clear();

            cin.ignore(
                numeric_limits<streamsize>::max(),
                '\n');

            PlaySound(TEXT("./sounds/fahh.wav"),
                      NULL,
                      SND_ASYNC);

            cout << "\033[31mInvalid Balance! \033[0m";
        }

        cin.ignore(
            numeric_limits<streamsize>::max(),
            '\n');

        return value;
    }

   static bool isValidName(const string& name)
{
    if (name.empty()) return false;

    for (char c : name)
    {
        if (isdigit(c))
            return false;
    }
    return true;
}
};
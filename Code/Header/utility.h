#pragma once

#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <mmsystem.h>
#include <limits>

using namespace std;

class Utility
{
  public:
 template <typename T>
static T input(string message)
{
    T value;
    cout << "\033[33m" <<message<<"\033[33m ";
    cout <<"\033[0m";
    while (!(cin >> value))
    {
        cin.clear();

        cin.ignore(
            numeric_limits<streamsize>::max(),
            '\n'
        );

         PlaySound(TEXT("./sounds/fahh.wav"), NULL, SND_ASYNC);
        cout << "\n\033[31mInvalid Input!\n\n\033[0m";
        cout << "\033[33m" <<message<<"\033[0m ";
    }


    return value;
}

static double inputBalance(string message)
{
    double value;

    cout << message;

    while (!(cin >> value) || value < 0)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        PlaySound(TEXT("./sounds/fahh.wav"), NULL, SND_ASYNC);
        cout << "\033[31mInvalid Balance! Must be >= 0: \033[0m";
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return value;
}

static double inputPrice(string message)
{
    double value;

    cout << message;

    while (!(cin >> value) || value <= 0)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "\033[31mInvalid Price! Must be > 0: \033[0m";
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return value;
}

};

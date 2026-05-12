#pragma once

#include <iostream>
#include <cstdlib>

using namespace std;

class Voice{
  public:
   static void speak(string text)
{
    string command =
        "start /B PowerShell -Command \"Add-Type -AssemblyName System.Speech; "
        "$speak = New-Object System.Speech.Synthesis.SpeechSynthesizer; "
        "$speak.SelectVoice('Microsoft Zira Desktop'); "
        "$speak.Speak('" + text + "');\"";

    system(command.c_str());
}
};